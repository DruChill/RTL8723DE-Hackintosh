// Declaración del driver RTL8723DE; ver RTL8723DE.cpp (hardware) y Station.cpp
// (transmisión, asociación, WPA2 y DHCP).
#pragma once
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOBufferMemoryDescriptor.h>
#include <IOKit/IOCommandGate.h>
#include <IOKit/IODMACommand.h>
#include <IOKit/IOInterruptEventSource.h>
#include <IOKit/IOLocks.h>
#include <IOKit/IOTimerEventSource.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/network/IOEthernetController.h>
#include <IOKit/network/IOEthernetInterface.h>
#include <IOKit/network/IOGatedOutputQueue.h>
#include <IOKit/network/IONetworkMedium.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <libkern/OSByteOrder.h>
#include <libkern/c++/OSArray.h>
#include <libkern/c++/OSString.h>
#include <pexpert/pexpert.h>

#include "rtw_reg.h"

#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

enum { RF_PATH_A = 0, RF_PATH_B = 1 };

// Colas TX en el orden de rtw_pci_reset_buf_desc().
enum { TXQ_BK, TXQ_BE, TXQ_VI, TXQ_VO, TXQ_MGMT, TXQ_HI0, TXQ_BCN, TXQ_NUM };
static const UInt32 kTxDesa[TXQ_NUM] = {
    RTK_PCI_TXBD_DESA_BKQ, RTK_PCI_TXBD_DESA_BEQ, RTK_PCI_TXBD_DESA_VIQ,
    RTK_PCI_TXBD_DESA_VOQ, RTK_PCI_TXBD_DESA_MGMTQ, RTK_PCI_TXBD_DESA_HI0Q,
    RTK_PCI_TXBD_DESA_BCNQ,
};
static const UInt32 kTxNum[TXQ_NUM] = {
    RTK_PCI_TXBD_NUM_BKQ, RTK_PCI_TXBD_NUM_BEQ, RTK_PCI_TXBD_NUM_VIQ,
    RTK_PCI_TXBD_NUM_VOQ, RTK_PCI_TXBD_NUM_MGMTQ, RTK_PCI_TXBD_NUM_HI0Q, 0,
};
static const UInt32 kTxIdx[TXQ_NUM] = {
    RTK_PCI_TXBD_IDX_BKQ, RTK_PCI_TXBD_IDX_BEQ, RTK_PCI_TXBD_IDX_VIQ,
    RTK_PCI_TXBD_IDX_VOQ, RTK_PCI_TXBD_IDX_MGMTQ, RTK_PCI_TXBD_IDX_HI0Q, 0,
};

#define TX_RING_LEN    64
#define TX_RING_STRIDE (TX_RING_LEN * CHIP_TX_BUF_DESC_SZ)
#define TX_BUF_SIZE    2048  // descriptor de paquete (40) + trama
#define RX_RING_LEN    64
#define RX_BUF_ALLOC   12288 // >= RTK_PCI_RX_BUF_SIZE, múltiplo de página
#define MAX_BSS        48
#define MAX_RSN_IE     64
#define EAPOL_SLOTS    4
#define EAPOL_MAX      512

// Región de memoria contigua accesible por DMA de 32 bits.
struct DmaRegion {
    IOBufferMemoryDescriptor *md;
    IODMACommand *cmd;
    UInt8 *virt;
    UInt32 phys;
};

struct BssEntry {
    UInt8 bssid[6];
    char ssid[33];
    UInt8 channel;
    SInt8 rssi;
    UInt16 beacons;
    UInt8 rsn[MAX_RSN_IE];  // IE RSN completo (id + len + cuerpo)
    UInt8 rsnLen;
};

class RTL8723DE : public IOEthernetController {
    OSDeclareDefaultStructors(RTL8723DE)
    typedef IOEthernetController super;
public:
    bool start(IOService *provider) override;
    void stop(IOService *provider) override;
    IOReturn setProperties(OSObject *properties) override;
    void systemWillShutdown(IOOptionBits specifier) override;

    // IOEthernetController (NetIf.cpp)
    IOReturn enable(IONetworkInterface *interface) override;
    IOReturn disable(IONetworkInterface *interface) override;
    IOReturn getHardwareAddress(IOEthernetAddress *addr) override;
    UInt32 outputPacket(mbuf_t m, void *param) override;
    bool createWorkLoop() override;
    IOWorkLoop *getWorkLoop() const override;
    IOReturn setPromiscuousMode(bool active) override;
    IOReturn setMulticastMode(bool active) override;
    IOReturn setMulticastList(IOEthernetAddress *addrs, UInt32 count) override;
private:
    IOWorkLoop *workLoop = nullptr;
    IOCommandGate *gate = nullptr;
    IOTimerEventSource *rxTimer = nullptr;
    IOEthernetInterface *netif = nullptr;
    IOPCIDevice *pci = nullptr;
    IOMemoryMap *bar = nullptr;
    volatile UInt8 *base = nullptr;
    UInt8 cut = 0;
    UInt16 failedPollAddr = 0;

    // Valores de la efuse que usa la inicialización.
    UInt8 macAddr[6] = {};
    UInt8 crystalCap = 0;
    UInt8 afe = 0;
    UInt8 btSetting = 0;

    DmaRegion txRing = {};
    DmaRegion rxRing = {};
    DmaRegion rxBuf[RX_RING_LEN] = {};
    UInt32 rxRp = 0;

    BssEntry bss[MAX_BSS] = {};
    UInt32 bssCount = 0;
    UInt32 rxTotal = 0, rxCrc = 0, rxC2h = 0, rxMgmt = 0, rxData = 0, rxBeacon = 0;
    UInt32 rxPerChannel[14] = {};

    UInt8  r8(UInt32 a)  { return base[a]; }
    UInt16 r16(UInt32 a) { return OSReadLittleInt16(base, a); }
    UInt32 r32(UInt32 a) { return OSReadLittleInt32(base, a); }
    void w8(UInt32 a, UInt8 v)   { base[a] = v; }
    void w16(UInt32 a, UInt16 v) { OSWriteLittleInt16(base, a, v); }
    void w32(UInt32 a, UInt32 v) { OSWriteLittleInt32(base, a, v); }
    void w8set(UInt32 a, UInt8 b)   { w8(a, r8(a) | b); }
    void w8clr(UInt32 a, UInt8 b)   { w8(a, r8(a) & ~b); }
    void w16set(UInt32 a, UInt16 b) { w16(a, r16(a) | b); }
    void w16clr(UInt32 a, UInt16 b) { w16(a, r16(a) & ~b); }
    void w32set(UInt32 a, UInt32 b) { w32(a, r32(a) | b); }
    void w32clr(UInt32 a, UInt32 b) { w32(a, r32(a) & ~b); }
    void w32mask(UInt32 a, UInt32 mask, UInt32 v);
    void w8mask(UInt32 a, UInt8 mask, UInt8 v);
    UInt32 r32mask(UInt32 a, UInt32 mask);
    bool checkHwReady(UInt32 a, UInt32 mask, UInt32 target);

    // Energía, efuse y firmware (hitos 2 y 3)
    bool pollMask(UInt32 addr, UInt8 mask, UInt8 target);
    bool pwrCmdPolling(const struct rtw_pwr_seq_cmd *cmd);
    IOReturn subPwrSeq(const struct rtw_pwr_seq_cmd *cmd);
    IOReturn pwrSeq(const struct rtw_pwr_seq_cmd * const *seq);
    void preSystemCfg();
    IOReturn powerSwitch(bool on);
    IOReturn powerOn();
    IOReturn readEfuse(UInt8 *logMap);
    void wlanCpuEnable(bool enable);
    void enDownloadFirmware(bool en);
    void writeFirmwarePage(UInt32 page, const UInt8 *data, UInt32 size);
    IOReturn downloadFirmware(const UInt8 *fw, UInt32 size);

    // DMA y PCIe (pci.c)
    bool dmaAlloc(DmaRegion &r, size_t size);
    void dmaFree(DmaRegion &r);
    bool allocRings();
    void freeRings();
    void resetRxDesc(UInt32 idx);
    void hciSetup();

    // Inicialización MAC/BB/RF (mac.c, phy.c, rtw8723x.c, rtw8723d.c)
    IOReturn macInit();
    UInt32 readRf(UInt32 path, UInt32 addr, UInt32 mask);
    void writeRf(UInt32 path, UInt32 addr, UInt32 mask, UInt32 data);
    void loadPhyTable(const UInt32 *tbl, size_t words, int kind);
    void phySetParam();
    void lck();

    // Coexistencia con BT (coex.c, rtw8723d.c)
    UInt32 readIndirect(UInt16 addr);
    void writeIndirect(UInt16 addr, UInt32 mask, UInt32 val);
    void coexSetRfeType();
    void coexCtrlOwner(bool wifi);
    void coexWifiOnly();

    // Canal y recepción
    void setChannel(UInt8 ch);
    void cfgNotch(UInt8 ch, bool notch);
    void processRx(UInt8 ch);
    void parseFrame(const UInt8 *frame, UInt32 len, SInt8 rssi, UInt8 ch);
    void passiveScan();
    void publishScan();
    void runScan();
    const char *bringUp();
    void shutDown();

    void setHexProperty(const char *key, const UInt8 *bytes, int len, char sep);

    // ---- Estación (Station.cpp) ----
    DmaRegion txBuf[TXQ_NUM] = {};
    UInt32 txWp[TXQ_NUM] = {};
    UInt32 txOk = 0, txTimeout = 0;

    bool staActive = false;
    UInt8 bssid[6] = {};
    UInt8 staChannel = 0;
    char staSsid[33] = {};
    UInt8 pmk[32] = {};
    UInt8 ourRsn[MAX_RSN_IE] = {};
    UInt8 ourRsnLen = 0;
    UInt8 ptk[48] = {};
    UInt64 txPn = 0;

    // Buzón que llena la recepción mientras la estación está activa.
    int authStatus = -1, assocStatus = -1, deauthReason = -1;
    UInt16 aid = 0;
    UInt8 eapol[EAPOL_SLOTS][EAPOL_MAX] = {};
    UInt16 eapolLen[EAPOL_SLOTS] = {};
    UInt32 eapolCount = 0;
    UInt32 rxProtected = 0, rxUndecrypted = 0;
    UInt32 dhcpXid = 0;
    char dhcpResult[96] = {};

    // Potencia de TX de fábrica (rtw_2g_txpwr_idx del camino A en la efuse).
    UInt8 pwrCck[6] = {};
    UInt8 pwrBw40[5] = {};
    UInt8 pwrHtDiff = 0;

    void setTxPower(UInt8 ch);
    void enableSecEngine();
    void writeCam(UInt8 entry, UInt8 keyIdx, const UInt8 addr[6], const UInt8 key[16], bool group);
    bool txFrame(int q, const UInt8 *frame, UInt32 len, UInt8 qsel, UInt8 secType,
                 UInt8 rate = DESC_RATE1M, bool wait = true);
    bool txRingHasSpace(int q);
    UInt32 buildHdr(UInt8 *f, UInt8 fc0, UInt8 fc1, const UInt8 *a1, const UInt8 *a3);
    bool sendData(const UInt8 *da, UInt16 ethertype, const UInt8 *payload, UInt32 len,
                  bool protect, UInt8 rate = DESC_RATE1M, bool wait = true);
    void handleStaFrame(const UInt8 *f, UInt32 len, bool decrypted);
    void handleDhcp(const UInt8 *ip, UInt32 len);
    bool waitRx(UInt32 ms, bool (*done)(RTL8723DE *));
    bool findTarget();
    bool buildOurRsn();
    bool authenticate();
    bool associate();
    bool fourWayHandshake();
    bool sendDhcpDiscover();
    void runConnect(OSString *ssid, OSData *pmkData);
    const char *connectSequence(bool fast = false);
    void disconnect(bool sendDeauth);
    void handleGroupRekey(UInt8 *e, UInt32 elen);

    // ---- Interfaz de red (NetIf.cpp) ----
    bool staConnected = false;
    bool havePmk = false;
    UInt32 ticks = 0, lastBeaconTick = 0, reconnectAt = 0, reconnectTries = 0;
    UInt32 eapolHandled = 0;
    // Sin calibración IQK, 54M no pasa; 36M dio la mejor descarga (hasta 2,5 MB/s).
    UInt8 dataRate = 0x09;  // DESC_RATE36M
    UInt8 scratch[TX_BUF_SIZE] = {};
    UInt32 netRx = 0, netTx = 0, netTxDrop = 0, rekeys = 0, reconnects = 0;
    UInt32 outCalls = 0, lastGateError = 0, chipOffEvents = 0;

    // Cola de salida: outputPacket solo encola (nunca espera al work loop, para
    // no interbloquearse con la entrega de paquetes a la pila) y txSource drena.
    IOInterruptEventSource *txSource = nullptr;
    IOLock *txqLock = nullptr;
    mbuf_t txqHead = nullptr, txqTail = nullptr;
    UInt32 txqLen = 0;

    IOReturn gatedCommand(void *dict, void *, void *, void *);
    void txSourceFired(IOInterruptEventSource *sender, int count);
    void transmitOne(mbuf_t m);
    void flushTxQueue();
    void rxTimerFired(IOTimerEventSource *sender);
    void deliverToStack(const UInt8 *da, const UInt8 *sa, UInt16 etype, const UInt8 *p, UInt32 len);
    void setLink(bool up);
    friend bool authDone(RTL8723DE *);
    friend bool assocDone(RTL8723DE *);
    friend bool eapolReady(RTL8723DE *);
    friend bool dhcpDone(RTL8723DE *);
};
