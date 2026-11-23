// Interfaz de red: el driver se presenta a macOS como un controlador Ethernet
// (como itlwm). Las tramas Ethernet se convierten a 802.11 con LLC/SNAP y
// viceversa; el cifrado CCMP lo hace el chip con las claves de la CAM.
#include "RTL8723DE.hpp"

#define LINK_SPEED   54000000ULL
#define TIMER_MS     5
#define BEACON_LOSS  (5000 / TIMER_MS)  // 5 s sin beacons de nuestro AP

bool RTL8723DE::createWorkLoop()
{
    workLoop = IOWorkLoop::workLoop();
    return workLoop != nullptr;
}

IOWorkLoop *RTL8723DE::getWorkLoop() const
{
    return workLoop;
}

IOReturn RTL8723DE::getHardwareAddress(IOEthernetAddress *addr)
{
    memcpy(addr->bytes, macAddr, 6);
    return kIOReturnSuccess;
}

// La implementación base devuelve kIOReturnUnsupported, y entonces la interfaz
// queda sin IFF_RUNNING y la pila no transmite. El hardware se enciende al
// conectar (rtlctl), no aquí.
IOReturn RTL8723DE::enable(IONetworkInterface *)
{
    return kIOReturnSuccess;
}

IOReturn RTL8723DE::disable(IONetworkInterface *)
{
    return kIOReturnSuccess;
}

// RCR ya acepta broadcast y multicast (BIT_AB | BIT_AM); no hay filtro que ajustar.
IOReturn RTL8723DE::setPromiscuousMode(bool) { return kIOReturnSuccess; }
IOReturn RTL8723DE::setMulticastMode(bool) { return kIOReturnSuccess; }
IOReturn RTL8723DE::setMulticastList(IOEthernetAddress *, UInt32) { return kIOReturnSuccess; }

void RTL8723DE::setLink(bool up)
{
    static IONetworkMedium *medium;
    if (!medium) {
        OSDictionary *dict = OSDictionary::withCapacity(1);
        medium = IONetworkMedium::medium(kIOMediumEthernetAuto, LINK_SPEED);
        if (dict && medium) {
            IONetworkMedium::addMedium(dict, medium);
            publishMediumDictionary(dict);
            setSelectedMedium(medium);
        }
        if (dict)
            dict->release();
    }
    if (up)
        setLinkStatus(kIONetworkLinkValid | kIONetworkLinkActive, medium, LINK_SPEED);
    else
        setLinkStatus(kIONetworkLinkValid, nullptr);
    setProperty("Link", up ? "up" : "down");
}

#define TXQ_MAX 256

// Ethernet -> 802.11. La pila llama aquí desde sus hilos (sin cola de salida
// propia, como itlwm). Nunca se espera al work loop: si este hilo se bloqueara
// en la compuerta mientras el work loop entrega paquetes a la pila, ambos
// podrían esperarse mutuamente y congelar toda la red de la máquina.
UInt32 RTL8723DE::outputPacket(mbuf_t m, void *)
{
    outCalls++;
    if (!staConnected || !txqLock || !txSource) {
        freePacket(m);
        netTxDrop++;
        return kIOReturnOutputDropped;
    }

    IOLockLock(txqLock);
    bool full = txqLen >= TXQ_MAX;
    if (!full) {
        mbuf_setnextpkt(m, nullptr);
        if (txqTail)
            mbuf_setnextpkt(txqTail, m);
        else
            txqHead = m;
        txqTail = m;
        txqLen++;
    }
    IOLockUnlock(txqLock);

    if (full) {
        freePacket(m);
        netTxDrop++;
        return kIOReturnOutputDropped;
    }
    txSource->interruptOccurred(nullptr, nullptr, 0);  // drenar en el work loop
    return kIOReturnOutputSuccess;
}

// Dentro del work loop: transmitir lo encolado mientras haya hueco en el anillo.
// Si se llena, lo pendiente espera al siguiente ciclo del temporizador
// (contrapresión) en vez de descartarse o esperar activamente.
void RTL8723DE::txSourceFired(IOInterruptEventSource *, int)
{
    while (staConnected && txBuf[TXQ_BE].virt && txRingHasSpace(TXQ_BE)) {
        IOLockLock(txqLock);
        mbuf_t m = txqHead;
        if (m) {
            txqHead = mbuf_nextpkt(m);
            if (!txqHead)
                txqTail = nullptr;
            txqLen--;
            mbuf_setnextpkt(m, nullptr);
        }
        IOLockUnlock(txqLock);
        if (!m)
            break;
        transmitOne(m);
    }
}

void RTL8723DE::transmitOne(mbuf_t m)
{
    UInt32 len = (UInt32)mbuf_pkthdr_len(m);
    if (!staConnected || len < 14 || len > sizeof(scratch)) {
        freePacket(m);
        netTxDrop++;
        return;
    }
    mbuf_copydata(m, 0, len, scratch);
    freePacket(m);

    UInt16 etype = (UInt16)((scratch[12] << 8) | scratch[13]);
    if (sendData(scratch, etype, scratch + 14, len - 14, true, dataRate, false))
        netTx++;
    else
        netTxDrop++;
}

// Descarta lo pendiente (al desconectar).
void RTL8723DE::flushTxQueue()
{
    if (!txqLock)
        return;
    IOLockLock(txqLock);
    mbuf_t m = txqHead;
    txqHead = txqTail = nullptr;
    txqLen = 0;
    IOLockUnlock(txqLock);
    while (m) {
        mbuf_t next = mbuf_nextpkt(m);
        mbuf_setnextpkt(m, nullptr);
        freePacket(m);
        m = next;
    }
}

// 802.11 -> Ethernet hacia la pila de red.
void RTL8723DE::deliverToStack(const UInt8 *da, const UInt8 *sa, UInt16 etype,
                               const UInt8 *p, UInt32 len)
{
    UInt32 total = 14 + len;
    if (!netif || total > 1514)
        return;
    mbuf_t m = allocatePacket(total);
    if (!m)
        return;
    UInt8 *d = (UInt8 *)mbuf_data(m);
    memcpy(d, da, 6);
    memcpy(d + 6, sa, 6);
    d[12] = (UInt8)(etype >> 8);
    d[13] = (UInt8)etype;
    memcpy(d + 14, p, len);
    netif->inputPacket(m, total, IONetworkInterface::kInputOptionQueuePacket);
    netRx++;
}

// Cada 5 ms: recepción, renovación de claves, vigilancia del enlace y reconexión.
void RTL8723DE::rxTimerFired(IOTimerEventSource *)
{
    ticks++;

    // Algo ajeno (probablemente la parte Bluetooth del chip al iniciarse) puede
    // apagar el MAC: todos sus registros leen 0xEA. Reconectar de inmediato.
    if (staConnected && r8(REG_CR) == 0xea) {
        chipOffEvents++;
        char why[64];
        snprintf(why, sizeof(why), "chip apagado por fuera; t=%us", ticks * TIMER_MS / 1000);
        setProperty("LastDisconnect", why);
        setProperty("ChipOffEvents", chipOffEvents, 32);
        disconnect(false);
        reconnects++;
        reconnectAt = ticks + 1;
    }

    if (staConnected) {
        processRx(staChannel);
        while (eapolHandled != eapolCount) {
            UInt32 slot = eapolHandled % EAPOL_SLOTS;
            handleGroupRekey(eapol[slot], eapolLen[slot]);
            eapolHandled++;
        }
        if (netif)
            netif->flushInputQueue();
        txSourceFired(nullptr, 0);  // lo que esperaba hueco en el anillo

        if (deauthReason >= 0 || ticks - lastBeaconTick > BEACON_LOSS) {
            // Diagnóstico: ¿quién tenía la antena y seguía llegando algo?
            char why[128];
            snprintf(why, sizeof(why), "%s; t=%us coex=0x%08x rxTotal=%u rcr=0x%08x",
                     deauthReason >= 0 ? "deauth del AP" : "sin beacons",
                     ticks * TIMER_MS / 1000, readIndirect(LTE_COEX_CTRL), rxTotal, r32(REG_RCR));
            setProperty("LastDisconnect", why);
            if (deauthReason >= 0)
                setProperty("DeauthReason", (UInt64)deauthReason, 16);
            disconnect(false);
            reconnects++;
            reconnectAt = ticks + 2000 / TIMER_MS;
        }

        if ((ticks % (1000 / TIMER_MS)) == 0) {
            setProperty("NetRx", netRx, 32);
            setProperty("NetTx", netTx, 32);
            setProperty("NetTxDrop", netTxDrop, 32);
            setProperty("OutCalls", outCalls, 32);
            setProperty("BeaconAgeMs", (ticks - lastBeaconTick) * TIMER_MS, 32);
            setProperty("UptimeS", ticks * TIMER_MS / 1000, 32);
            setProperty("RxTotal", rxTotal, 32);
            setProperty("RxCrcErrors", rxCrc, 32);
            setProperty("RxUndecrypted", rxUndecrypted, 32);
            setProperty("TxRingFull", txTimeout, 32);
            setProperty("Rekeys", rekeys, 32);
            setProperty("Reconnects", reconnects, 32);
        }
    }

    if (!staConnected && havePmk && reconnectAt && ticks >= reconnectAt) {
        reconnectAt = 0;
        setProperty("Stage", "reconectando");
        // Primer intento directo al AP conocido (sin escanear); luego completo.
        const char *stage = connectSequence(reconnectTries == 0);
        setProperty("Stage", stage ? stage : "conectado");
        if (stage) {
            // Reintentar con espera creciente, hasta 30 s.
            reconnectTries++;
            UInt32 delay = reconnectTries * 5000;
            reconnectAt = ticks + (delay > 30000 ? 30000 : delay) / TIMER_MS;
        } else {
            reconnectTries = 0;
        }
    }

    if (staConnected || (havePmk && reconnectAt))
        rxTimer->setTimeoutMS(TIMER_MS);
}
