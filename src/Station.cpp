// Modo estación: transmisión, autenticación abierta, asociación, saludo
// WPA2-PSK de 4 vías, claves CCMP en la CAM del chip y una prueba DHCP.
// Basado en rtw88 (tx.c, pci.c, sec.c) y en IEEE 802.11-2016 (12.7.6).
#include "RTL8723DE.hpp"
#include "wpa_crypto.h"
#include <sys/random.h>

static const UInt8 kBroadcast[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
static const UInt8 kOuiIeee[3] = {0x00, 0x0f, 0xac};

static UInt16 be16(const UInt8 *p) { return (UInt16)((p[0] << 8) | p[1]); }
static UInt16 le16(const UInt8 *p) { return (UInt16)(p[0] | (p[1] << 8)); }

// ------------------------------------------------------------ potencia y claves

// Fórmula base de rtw_phy_get_2g_tx_power_index(): CCK = cck_base[grupo],
// OFDM = bw40_base + diff.ofdm, HT20 = bw40_base + diff.bw20 (sin by-rate).
void RTL8723DE::setTxPower(UInt8 ch)
{
    static const UInt8 groupOf[15] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    UInt8 g = ch <= 14 ? groupOf[ch] : 0;
    SInt8 ofdmDiff = (SInt8)(pwrHtDiff << 4) >> 4;
    SInt8 bw20Diff = (SInt8)(pwrHtDiff & 0xf0) >> 4;

    UInt8 cck = pwrCck[g] == 0xff ? 0x20 : pwrCck[g];
    UInt8 bw40 = pwrBw40[g > 4 ? 4 : g];
    bw40 = bw40 == 0xff ? 0x20 : bw40;
    UInt8 ofdm = (UInt8)(bw40 + ofdmDiff), ht20 = (UInt8)(bw40 + bw20Diff);

    // rtw8723x_txagc[]
    w32mask(0xe08, 0x0000ff00, cck);                         // 1M
    w32mask(0x86c, 0xffffff00, cck | (cck << 8) | (cck << 16)); // 2M, 5.5M, 11M
    UInt32 o = ofdm * 0x01010101U, h = ht20 * 0x01010101U;
    w32(0xe00, o);  // 6M-18M
    w32(0xe04, o);  // 24M-54M
    w32(0xe10, h);  // MCS0-3
    w32(0xe14, h);  // MCS4-7

    setProperty("TxPowerIndex", cck | (ofdm << 8) | (ht20 << 16), 32);
}

// rtw_sec_enable_sec_engine()
void RTL8723DE::enableSecEngine()
{
    w16(REG_CR, r16(REG_CR) | RTW_SEC_ENGINE_EN);
    w16(RTW_SEC_CONFIG, r16(RTW_SEC_CONFIG) | RTW_SEC_TX_DEC_EN | RTW_SEC_RX_DEC_EN |
        RTW_SEC_TX_UNI_USE_DK | RTW_SEC_RX_UNI_USE_DK |
        RTW_SEC_TX_BC_USE_DK | RTW_SEC_RX_BC_USE_DK);
}

// rtw_sec_write_cam() para una clave AES-CCMP.
void RTL8723DE::writeCam(UInt8 entry, UInt8 keyIdx, const UInt8 addr[6], const UInt8 key[16], bool group)
{
    for (int i = 7; i >= 0; i--) {
        UInt32 content;
        if (i == 0) {
            content = (keyIdx & 0x3) | ((RTW_CAM_AES & 0x7) << 2) | ((group ? 1U : 0U) << 6) |
                      BIT(15) | ((UInt32)addr[0] << 16) | ((UInt32)addr[1] << 24);
        } else if (i == 1) {
            content = addr[2] | (addr[3] << 8) | (addr[4] << 16) | ((UInt32)addr[5] << 24);
        } else if (i >= 6) {
            content = 0;
        } else {
            int j = (i - 2) * 4;
            content = key[j] | (key[j + 1] << 8) | (key[j + 2] << 16) | ((UInt32)key[j + 3] << 24);
        }
        w32(RTW_SEC_WRITE_REG, content);
        w32(RTW_SEC_CMD_REG, RTW_SEC_CMD_WRITE_ENABLE | RTW_SEC_CMD_POLLING |
                             ((entry << RTW_SEC_CAM_ENTRY_SHIFT) + i));
    }
}

// ------------------------------------------------------------------ transmisión

// rtw_tx_fill_tx_desc() + __rtw8723x_fill_txdesc_checksum() + rtw_pci_tx_write_data().
// Tasa fija sin fallback, secuencia por hardware. Con wait, espera a que el
// chip consuma la cola; sin wait, solo exige un hueco libre en el anillo.
bool RTL8723DE::txFrame(int q, const UInt8 *frame, UInt32 len, UInt8 qsel, UInt8 secType,
                        UInt8 rate, bool wait)
{
    if (!txBuf[q].virt || len + TX_PKT_DESC_SZ > TX_BUF_SIZE)
        return false;

    UInt32 slot = txWp[q];
    if (!wait && !txRingHasSpace(q)) {
        txTimeout++;
        return false;
    }
    UInt8 *buf = txBuf[q].virt + slot * TX_BUF_SIZE;
    UInt32 phys = txBuf[q].phys + slot * TX_BUF_SIZE;
    bool bmc = frame[4] & 0x01;

    UInt32 w[10] = {};
    w[0] = (len & 0xffff) | (TX_PKT_DESC_SZ << 16) | (bmc ? RTW_TX_DESC_W0_BMC : 0) |
           RTW_TX_DESC_W0_LS | RTW_TX_DESC_W0_DISQSELSEQ;
    UInt8 rateId = rate >= DESC_RATE6M ? RTW_RATEID_BG : RTW_RATEID_B_20M;
    w[1] = ((qsel & 0x1f) << 8) | ((rateId & 0x1f) << 16) | ((secType & 0x3) << 22);
    w[3] = RTW_TX_DESC_W3_USE_RATE | RTW_TX_DESC_W3_DISDATAFB;
    w[4] = (rate & 0x7f) | (0x1f << 8);  // old_datarate_fb_limit
    w[8] = RTW_TX_DESC_W8_EN_HWSEQ;
    for (int i = 0; i < 10; i++)
        OSWriteLittleInt32(buf, i * 4, w[i]);

    UInt16 sum = 0;
    for (int i = 0; i < 16; i++)
        sum ^= OSReadLittleInt16(buf, i * 2);
    OSWriteLittleInt16(buf, 28, (UInt16)~sum);  // w7[15:0]

    memcpy(buf + TX_PKT_DESC_SZ, frame, len);

    UInt8 *bd = txRing.virt + q * TX_RING_STRIDE + slot * CHIP_TX_BUF_DESC_SZ;
    OSWriteLittleInt16(bd, 0, TX_PKT_DESC_SZ);
    OSWriteLittleInt16(bd, 2, (UInt16)((len + TX_PKT_DESC_SZ - 1) / 128 + 1));
    OSWriteLittleInt32(bd, 4, phys);
    OSWriteLittleInt16(bd, 8, (UInt16)len);
    OSWriteLittleInt16(bd, 10, 0);
    OSWriteLittleInt32(bd, 12, phys + TX_PKT_DESC_SZ);
    OSSynchronizeIO();

    txWp[q] = (slot + 1) % TX_RING_LEN;
    w16(kTxIdx[q], (UInt16)txWp[q]);

    if (!wait) {
        txOk++;
        return true;
    }
    for (int i = 0; i < 500; i++) {
        if (((r32(kTxIdx[q]) >> 16) & TRX_BD_IDX_MASK) == txWp[q]) {
            txOk++;
            return true;
        }
        IODelay(100);
    }
    txTimeout++;
    return false;
}

// Hay hueco si avanzar el índice de escritura no alcanza al de lectura del HW.
bool RTL8723DE::txRingHasSpace(int q)
{
    UInt32 rp = (r32(kTxIdx[q]) >> 16) & TRX_BD_IDX_MASK;
    return (txWp[q] + 1) % TX_RING_LEN != rp;
}

// Cabecera 802.11 de 24 bytes con addr2 = nuestra MAC.
UInt32 RTL8723DE::buildHdr(UInt8 *f, UInt8 fc0, UInt8 fc1, const UInt8 *a1, const UInt8 *a3)
{
    f[0] = fc0;
    f[1] = fc1;
    f[2] = f[3] = 0;
    memcpy(f + 4, a1, 6);
    memcpy(f + 10, macAddr, 6);
    memcpy(f + 16, a3, 6);
    f[22] = f[23] = 0;
    return 24;
}

// Trama de datos ToDS con LLC/SNAP. Si va protegida, se agrega la cabecera
// CCMP con el PN (rtw88 pide IV generado por software) y el HW cifra el resto.
bool RTL8723DE::sendData(const UInt8 *da, UInt16 ethertype, const UInt8 *payload, UInt32 len,
                         bool protect, UInt8 rate, bool wait)
{
    UInt8 f[TX_BUF_SIZE];
    if (24 + 8 + 8 + len > sizeof(f) - TX_PKT_DESC_SZ)
        return false;

    UInt32 n = buildHdr(f, 0x08, (UInt8)(0x01 | (protect ? 0x40 : 0)), bssid, da);
    if (protect) {
        UInt64 pn = ++txPn;
        f[n++] = (UInt8)pn;
        f[n++] = (UInt8)(pn >> 8);
        f[n++] = 0;
        f[n++] = 0x20;  // Ext IV, key id 0
        f[n++] = (UInt8)(pn >> 16);
        f[n++] = (UInt8)(pn >> 24);
        f[n++] = (UInt8)(pn >> 32);
        f[n++] = (UInt8)(pn >> 40);
    }
    static const UInt8 llc[6] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00};
    memcpy(f + n, llc, 6);
    n += 6;
    f[n++] = (UInt8)(ethertype >> 8);
    f[n++] = (UInt8)ethertype;
    memcpy(f + n, payload, len);
    n += len;
    return txFrame(TXQ_BE, f, n, TX_DESC_QSEL_TID0, protect ? TX_SEC_TYPE_CCMP : 0, rate, wait);
}

// ------------------------------------------------------------------- recepción

void RTL8723DE::handleStaFrame(const UInt8 *f, UInt32 len, bool decrypted)
{
    if (len < 24 + 4 || memcmp(f + 10, bssid, 6))
        return;
    bool group = f[4] & 0x01;
    if (!group && memcmp(f + 4, macAddr, 6))
        return;
    UInt8 type = (f[0] >> 2) & 0x3, sub = (f[0] >> 4) & 0xf;
    const UInt8 *b = f + 24;
    UInt32 blen = len - 24 - 4;  // sin la FCS

    if (type == 0) {
        if (group && sub != 12 && sub != 10)  // de grupo solo interesan deauth/disassoc
            return;
        if (sub == 11 && blen >= 6 && le16(b + 2) == 2)
            authStatus = le16(b + 4);
        else if (sub == 1 && blen >= 6) {
            assocStatus = le16(b + 2);
            aid = le16(b + 4) & 0x3fff;
        } else if ((sub == 12 || sub == 10) && blen >= 2)
            deauthReason = le16(b);
        return;
    }
    if (type != 2 || (f[1] & 0x03) != 0x02)  // solo datos FromDS
        return;
    if (sub & 0x4)  // null data: sin contenido
        return;
    if (group && !memcmp(f + 16, macAddr, 6))  // nuestro propio broadcast devuelto por el AP
        return;

    UInt32 hdr = (sub & 0x8) ? 26 : 24;      // QoS data
    if (len < hdr + 8 + 4)
        return;
    UInt32 trailer = 4;
    if (f[1] & 0x40) {
        rxProtected++;
        if (!decrypted) {
            rxUndecrypted++;
            return;
        }
        hdr += 8;       // cabecera CCMP
        trailer += 8;   // MIC
    }
    if (len < hdr + 8 + trailer)
        return;
    const UInt8 *llc = f + hdr;
    UInt32 plen = len - hdr - trailer;
    if (llc[0] != 0xaa || llc[1] != 0xaa || llc[2] != 0x03)
        return;
    UInt16 etype = be16(llc + 6);
    const UInt8 *p = llc + 8;
    plen -= 8;

    if (etype == 0x888e && plen >= 4) {
        UInt32 elen = 4 + be16(p + 2);
        if (elen <= plen && elen <= EAPOL_MAX) {
            UInt32 slot = eapolCount % EAPOL_SLOTS;
            memcpy(eapol[slot], p, elen);
            eapolLen[slot] = (UInt16)elen;
            eapolCount++;
        }
    } else if (staConnected) {
        deliverToStack(f + 4, f + 16, etype, p, plen);  // DA = addr1, SA = addr3
    } else if (etype == 0x0800) {
        handleDhcp(p, plen);
    }
}

void RTL8723DE::handleDhcp(const UInt8 *ip, UInt32 len)
{
    if (len < 20 || (ip[0] >> 4) != 4 || ip[9] != 17)
        return;
    UInt32 ihl = (ip[0] & 0xf) * 4;
    if (len < ihl + 8 + 240)
        return;
    const UInt8 *udp = ip + ihl;
    if (be16(udp + 2) != 68)
        return;
    const UInt8 *d = udp + 8;
    UInt32 dlen = len - ihl - 8;
    UInt32 xid = ((UInt32)d[4] << 24) | (d[5] << 16) | (d[6] << 8) | d[7];
    if (d[0] != 2 || xid != dhcpXid)
        return;

    UInt8 msgType = 0;
    const UInt8 *server = nullptr;
    for (UInt32 i = 240; i + 2 <= dlen && d[i] != 255;) {
        if (d[i] == 0) { i++; continue; }
        UInt8 opt = d[i], olen = d[i + 1];
        if (i + 2 + olen > dlen)
            break;
        if (opt == 53 && olen == 1)
            msgType = d[i + 2];
        else if (opt == 54 && olen == 4)
            server = d + i + 2;
        i += 2 + olen;
    }
    if (msgType != 2)  // DHCPOFFER
        return;
    const UInt8 *y = d + 16;
    snprintf(dhcpResult, sizeof(dhcpResult), "OFFER %u.%u.%u.%u del servidor %u.%u.%u.%u",
             y[0], y[1], y[2], y[3],
             server ? server[0] : 0, server ? server[1] : 0,
             server ? server[2] : 0, server ? server[3] : 0);
}

bool authDone(RTL8723DE *d) { return d->authStatus >= 0 || d->deauthReason >= 0; }
bool assocDone(RTL8723DE *d) { return d->assocStatus >= 0 || d->deauthReason >= 0; }
bool dhcpDone(RTL8723DE *d) { return d->dhcpResult[0] != 0; }

bool RTL8723DE::waitRx(UInt32 ms, bool (*done)(RTL8723DE *))
{
    for (UInt32 t = 0; t < ms; t += 2) {
        processRx(staChannel);
        if (done(this))
            return true;
        IOSleep(2);
    }
    processRx(staChannel);
    return done(this);
}

// ------------------------------------------------------------- asociación

bool RTL8723DE::findTarget()
{
    int best = -1;
    for (UInt32 i = 0; i < bssCount; i++) {
        if (strncmp(bss[i].ssid, staSsid, sizeof(staSsid)))
            continue;
        if (best < 0 || bss[i].rssi > bss[best].rssi)
            best = (int)i;
    }
    if (best < 0)
        return false;
    memcpy(bssid, bss[best].bssid, 6);
    staChannel = bss[best].channel;
    setHexProperty("TargetBSSID", bssid, 6, ':');
    setProperty("TargetChannel", staChannel, 8);
    if (bss[best].rsnLen)
        setProperty("TargetRSN", bss[best].rsn, bss[best].rsnLen);
    return true;
}

// Revisa el IE RSN del AP y arma el nuestro: WPA2-PSK con CCMP.
bool RTL8723DE::buildOurRsn()
{
    const BssEntry *e = nullptr;
    for (UInt32 i = 0; i < bssCount; i++)
        if (!memcmp(bss[i].bssid, bssid, 6))
            e = &bss[i];
    if (!e || e->rsnLen < 2 + 2 + 4 + 2 + 4 + 2 + 4)
        return false;

    const UInt8 *p = e->rsn + 2, *end = e->rsn + e->rsnLen;
    const UInt8 *group = p + 2;
    p += 6;
    UInt16 n = le16(p);
    p += 2;
    bool ccmp = false, psk = false;
    for (UInt16 i = 0; i < n && p + 4 <= end; i++, p += 4)
        if (!memcmp(p, kOuiIeee, 3) && p[3] == 4)
            ccmp = true;
    if (p + 2 > end)
        return false;
    n = le16(p);
    p += 2;
    for (UInt16 i = 0; i < n && p + 4 <= end; i++, p += 4)
        if (!memcmp(p, kOuiIeee, 3) && p[3] == 2)
            psk = true;
    UInt16 caps = p + 2 <= end ? le16(p) : 0;

    setProperty("TargetGroupCipher", group[3], 8);
    if (!ccmp || !psk) {
        setProperty("RsnProblem", !ccmp ? "el AP no ofrece CCMP" : "el AP no usa WPA2-PSK");
        return false;
    }
    if (caps & BIT(6)) {
        setProperty("RsnProblem", "el AP exige PMF (802.11w)");
        return false;
    }

    const UInt8 ours[] = {
        48, 20, 1, 0,
        group[0], group[1], group[2], group[3],
        1, 0, 0x00, 0x0f, 0xac, 4,
        1, 0, 0x00, 0x0f, 0xac, 2,
        0, 0,
    };
    memcpy(ourRsn, ours, sizeof(ours));
    ourRsnLen = sizeof(ours);
    return true;
}

bool RTL8723DE::authenticate()
{
    for (int attempt = 0; attempt < 3; attempt++) {
        UInt8 f[64];
        UInt32 n = buildHdr(f, 0xb0, 0x00, bssid, bssid);
        const UInt8 body[6] = {0, 0, 1, 0, 0, 0};  // open system, seq 1, status 0
        memcpy(f + n, body, 6);
        n += 6;
        authStatus = -1;
        txFrame(TXQ_MGMT, f, n, TX_DESC_QSEL_MGMT, 0);
        if (waitRx(300, authDone) && authStatus >= 0)
            break;
    }
    setProperty("AuthStatus", (UInt64)(SInt64)authStatus, 32);
    return authStatus == 0;
}

bool RTL8723DE::associate()
{
    for (int attempt = 0; attempt < 3; attempt++) {
        UInt8 f[256];
        UInt32 n = buildHdr(f, 0x00, 0x00, bssid, bssid);
        // ESS | Privacy | Short Preamble | Short Slot; listen interval 10.
        const UInt8 fixed[4] = {0x31, 0x04, 10, 0};
        memcpy(f + n, fixed, 4);
        n += 4;
        size_t ssidLen = strnlen(staSsid, 32);
        f[n++] = 0;
        f[n++] = (UInt8)ssidLen;
        memcpy(f + n, staSsid, ssidLen);
        n += ssidLen;
        const UInt8 rates[] = {1, 8, 0x82, 0x84, 0x8b, 0x96, 0x0c, 0x12, 0x18, 0x24,
                               50, 4, 0x30, 0x48, 0x60, 0x6c};
        memcpy(f + n, rates, sizeof(rates));
        n += sizeof(rates);
        memcpy(f + n, ourRsn, ourRsnLen);
        n += ourRsnLen;

        assocStatus = -1;
        txFrame(TXQ_MGMT, f, n, TX_DESC_QSEL_MGMT, 0);
        if (waitRx(400, assocDone) && assocStatus >= 0)
            break;
    }
    setProperty("AssocStatus", (UInt64)(SInt64)assocStatus, 32);
    setProperty("AID", aid, 16);
    return assocStatus == 0;
}

// --------------------------------------------------------- saludo de 4 vías

// Offsets dentro de la trama EAPOL (desde el byte de versión).
enum {
    EK_DESC = 4, EK_INFO = 5, EK_KEYLEN = 7, EK_REPLAY = 9, EK_NONCE = 17,
    EK_MIC = 81, EK_DATALEN = 97, EK_DATA = 99,
};
#define KI_PAIRWISE 0x0008
#define KI_INSTALL  0x0040
#define KI_ACK      0x0080
#define KI_MIC      0x0100
#define KI_SECURE   0x0200
#define KI_ENCDATA  0x1000

bool eapolReady(RTL8723DE *d) { return d->eapolCount > 0; }

bool RTL8723DE::fourWayHandshake()
{
    UInt8 snonce[32], anonce[32] = {}, replay[8] = {};
    bool havePtk = false;
    read_random(snonce, sizeof(snonce));
    UInt32 next = 0;
    int msg1Seen = 0;

    for (UInt32 elapsed = 0; elapsed < 5000; elapsed += 2) {
        processRx(staChannel);
        if (deauthReason >= 0)
            break;
        if (next == eapolCount) {
            IOSleep(2);
            continue;
        }

        UInt8 *e = eapol[next % EAPOL_SLOTS];
        UInt32 elen = eapolLen[next % EAPOL_SLOTS];
        next++;
        if (elen < EK_DATA || e[1] != 3)
            continue;
        UInt16 info = be16(e + EK_INFO);

        if ((info & KI_ACK) && !(info & KI_MIC)) {
            // Mensaje 1: ANonce -> PTK, responder con el mensaje 2.
            msg1Seen++;
            memcpy(anonce, e + EK_NONCE, 32);
            memcpy(replay, e + EK_REPLAY, 8);
            wpa_derive_ptk(pmk, bssid, macAddr, anonce, snonce, ptk);
            havePtk = true;

            UInt8 m[EK_DATA + MAX_RSN_IE] = {};
            UInt16 body = (UInt16)(EK_DATA - 4 + ourRsnLen);
            m[0] = e[0];
            m[1] = 3;
            m[2] = (UInt8)(body >> 8);
            m[3] = (UInt8)body;
            m[EK_DESC] = e[EK_DESC];
            m[EK_INFO] = 0x01;      // 0x010A: MIC | pairwise | versión 2
            m[EK_INFO + 1] = 0x0a;
            memcpy(m + EK_REPLAY, replay, 8);
            memcpy(m + EK_NONCE, snonce, 32);
            m[EK_DATALEN] = 0;
            m[EK_DATALEN + 1] = ourRsnLen;
            memcpy(m + EK_DATA, ourRsn, ourRsnLen);
            wpa_eapol_mic(ptk, m, 4 + body, m + EK_MIC);
            sendData(bssid, 0x888e, m, 4 + body, false);
            continue;
        }

        if (!havePtk || (info & (KI_ACK | KI_MIC | KI_INSTALL)) != (KI_ACK | KI_MIC | KI_INSTALL))
            continue;

        // Mensaje 3: verificar MIC y ANonce, desenvolver la GTK.
        UInt8 mic[16], saved[16];
        memcpy(saved, e + EK_MIC, 16);
        memset(e + EK_MIC, 0, 16);
        wpa_eapol_mic(ptk, e, elen, mic);
        if (memcmp(mic, saved, 16)) {
            setProperty("HandshakeProblem", "MIC del mensaje 3 inválido (¿contraseña incorrecta?)");
            return false;
        }
        if (memcmp(anonce, e + EK_NONCE, 32)) {
            setProperty("HandshakeProblem", "ANonce distinto en el mensaje 3");
            return false;
        }

        UInt16 dlen = be16(e + EK_DATALEN);
        UInt8 plain[EAPOL_MAX];
        const UInt8 *gtk = nullptr;
        UInt8 gtkIdx = 0, gtkLen = 0;
        if ((info & KI_ENCDATA) && dlen >= 24 && EK_DATA + dlen <= elen &&
            aes_unwrap(ptk + 16, e + EK_DATA, dlen, plain) == 0) {
            UInt32 plen = dlen - 8;
            for (UInt32 i = 0; i + 2 <= plen;) {
                UInt8 id = plain[i], l = plain[i + 1];
                if (id == 0xdd && l == 0)
                    break;  // relleno
                if (id == 0xdd && l >= 6 + 16 && i + 2 + l <= plen &&
                    !memcmp(plain + i + 2, kOuiIeee, 3) && plain[i + 5] == 1) {
                    gtkIdx = plain[i + 6] & 0x3;
                    gtk = plain + i + 8;
                    gtkLen = l - 6;
                }
                i += 2 + l;
            }
        }
        if (!gtk) {
            setProperty("HandshakeProblem", "no se pudo extraer la GTK del mensaje 3");
            return false;
        }

        // Mensaje 4 (sin cifrar), luego instalar las claves.
        UInt8 m[EK_DATA] = {};
        m[0] = e[0];
        m[1] = 3;
        m[2] = 0;
        m[3] = EK_DATA - 4;
        m[EK_DESC] = e[EK_DESC];
        m[EK_INFO] = 0x03;      // 0x030A: Secure | MIC | pairwise | versión 2
        m[EK_INFO + 1] = 0x0a;
        memcpy(m + EK_REPLAY, e + EK_REPLAY, 8);
        wpa_eapol_mic(ptk, m, EK_DATA, m + EK_MIC);
        sendData(bssid, 0x888e, m, EK_DATA, false);
        IOSleep(10);

        writeCam(4, 0, bssid, ptk + 32, false);
        writeCam(gtkIdx, gtkIdx, kBroadcast, gtk, true);
        setProperty("GTKIndex", gtkIdx, 8);
        setProperty("GTKLength", gtkLen, 8);
        setProperty("Msg1Seen", msg1Seen, 8);
        return true;
    }

    setProperty("Msg1Seen", msg1Seen, 8);
    setProperty("HandshakeProblem", msg1Seen ? "no llegó el mensaje 3" : "no llegó el mensaje 1");
    return false;
}

// ------------------------------------------------------------------- DHCP

// DHCPDISCOVER cifrado: si llega un OFFER, la ruta de datos completa funciona.
bool RTL8723DE::sendDhcpDiscover()
{
    for (int attempt = 0; attempt < 3; attempt++) {
        UInt8 pkt[328] = {};
        UInt8 *ip = pkt, *udp = pkt + 20, *d = pkt + 28;
        read_random(&dhcpXid, sizeof(dhcpXid));

        d[0] = 1; d[1] = 1; d[2] = 6;
        d[4] = (UInt8)(dhcpXid >> 24); d[5] = (UInt8)(dhcpXid >> 16);
        d[6] = (UInt8)(dhcpXid >> 8);  d[7] = (UInt8)dhcpXid;
        memcpy(d + 28, macAddr, 6);
        const UInt8 magic[4] = {0x63, 0x82, 0x53, 0x63};
        memcpy(d + 236, magic, 4);
        UInt32 o = 240;
        d[o++] = 53; d[o++] = 1; d[o++] = 1;               // DHCPDISCOVER
        d[o++] = 61; d[o++] = 7; d[o++] = 1;               // client id
        memcpy(d + o, macAddr, 6); o += 6;
        d[o++] = 55; d[o++] = 4; d[o++] = 1; d[o++] = 3; d[o++] = 6; d[o++] = 15;
        d[o++] = 255;

        udp[0] = 0; udp[1] = 68; udp[2] = 0; udp[3] = 67;
        udp[4] = (UInt8)((sizeof(pkt) - 20) >> 8); udp[5] = (UInt8)(sizeof(pkt) - 20);

        ip[0] = 0x45; ip[2] = (UInt8)(sizeof(pkt) >> 8); ip[3] = (UInt8)sizeof(pkt);
        ip[8] = 64; ip[9] = 17;
        memset(ip + 16, 0xff, 4);
        UInt32 sum = 0;
        for (int i = 0; i < 20; i += 2)
            sum += be16(ip + i);
        while (sum >> 16)
            sum = (sum & 0xffff) + (sum >> 16);
        ip[10] = (UInt8)(~sum >> 8); ip[11] = (UInt8)~sum;

        sendData(kBroadcast, 0x0800, pkt, sizeof(pkt), true);
        if (waitRx(2000, dhcpDone))
            break;
    }
    setProperty("DHCP", dhcpResult[0] ? dhcpResult : "sin respuesta");
    return dhcpResult[0] != 0;
}

// --------------------------------------------------------------- conexión

// Encender, escanear, autenticar, asociar y hacer el saludo WPA2. Devuelve
// nullptr si quedó conectado (chip encendido) o la etapa que falló (chip apagado).
// Con fast se reutilizan BSSID, canal e IE RSN de la conexión anterior.
const char *RTL8723DE::connectSequence(bool fast)
{
    authStatus = assocStatus = deauthReason = -1;
    aid = 0;
    eapolCount = eapolHandled = 0;
    txPn = 0;
    fast = fast && ourRsnLen && staChannel;
    const char *stage = bringUp();

    if (!stage) {
        if (!fast) {
            passiveScan();
            publishScan();
        }
        if (!fast && !findTarget()) {
            stage = "red-no-encontrada";
        } else if (!fast && !buildOurRsn()) {
            stage = "seguridad-no-soportada";
        } else {
            for (int i = 0; i < 6; i++) {
                w8(REG_PORT0_MACID + i, macAddr[i]);
                w8(REG_PORT0_BSSID + i, bssid[i]);
            }
            w32(REG_RCR, BIT_APP_FCS | BIT_APP_MIC | BIT_APP_ICV | BIT_PKTCTL_DLEN |
                         BIT_HTC_LOC_CTRL | BIT_APP_PHYSTS | BIT_AB | BIT_AM | BIT_APM);
            setChannel(staChannel);
            setTxPower(staChannel);
            staActive = true;

            if (!authenticate()) {
                stage = "autenticacion";
            } else if (!associate()) {
                stage = "asociacion";
            } else {
                w32mask(REG_CR, PORT0_NET_TYPE_MASK, RTW_NET_MGD_LINKED);
                w32mask(REG_PORT0_AID, 0x7ff, aid);
                if (!fourWayHandshake())
                    stage = "wpa2";
            }
        }
    }

    setProperty("TxOk", txOk, 32);
    setProperty("TxTimeout", txTimeout, 32);
    setProperty("EapolFrames", eapolCount, 32);
    if (deauthReason >= 0)
        setProperty("DeauthReason", (UInt64)deauthReason, 16);

    if (stage) {
        if (assocStatus == 0)
            disconnect(true);
        else
            shutDown();
        return stage;
    }

    eapolHandled = eapolCount;
    deauthReason = -1;
    lastBeaconTick = ticks;
    staConnected = true;
    setLink(true);
    rxTimer->setTimeoutMS(5);
    return nullptr;
}

void RTL8723DE::runConnect(OSString *ssid, OSData *pmkData)
{
    memcpy(pmk, pmkData->getBytesNoCopy(), 32);
    strlcpy(staSsid, ssid->getCStringNoCopy(), sizeof(staSsid));
    havePmk = true;
    reconnectAt = 0;
    reconnectTries = 0;
    txOk = txTimeout = 0;
    rxProtected = rxUndecrypted = 0;

    const char *stage = connectSequence();
    setProperty("Stage", stage ? stage : "conectado");
    if (stage) {
        // Sin conexión no tiene sentido guardar la clave.
        havePmk = false;
        memset(pmk, 0, sizeof(pmk));
    }
}

// Desautenticarse (razón 3: la estación se va), bajar el enlace y apagar el chip.
void RTL8723DE::disconnect(bool sendDeauth)
{
    if (sendDeauth && base && txBuf[TXQ_MGMT].virt) {
        UInt8 f[32];
        UInt32 n = buildHdr(f, 0xc0, 0x00, bssid, bssid);
        f[n++] = 3;
        f[n++] = 0;
        txFrame(TXQ_MGMT, f, n, TX_DESC_QSEL_MGMT, 0);
    }
    bool wasConnected = staConnected;
    staConnected = false;
    flushTxQueue();
    if (rxTimer && !havePmk)
        rxTimer->cancelTimeout();
    if (wasConnected)
        setLink(false);
    memset(ptk, 0, sizeof(ptk));
    shutDown();
}

// Renovación de la GTK (saludo de grupo, 12.7.7): el AP manda la nueva clave
// cifrada con la KEK; respondemos con el mensaje 2 de grupo protegido por la PTK.
void RTL8723DE::handleGroupRekey(UInt8 *e, UInt32 elen)
{
    if (elen < EK_DATA || e[1] != 3)
        return;
    UInt16 info = be16(e + EK_INFO);
    if (info & KI_PAIRWISE) {
        // Renovación de la PTK: más simple reconectar desde cero.
        deauthReason = 0;
        return;
    }
    if ((info & (KI_ACK | KI_MIC)) != (KI_ACK | KI_MIC))
        return;

    UInt8 mic[16], saved[16];
    memcpy(saved, e + EK_MIC, 16);
    memset(e + EK_MIC, 0, 16);
    wpa_eapol_mic(ptk, e, elen, mic);
    if (memcmp(mic, saved, 16))
        return;

    UInt16 dlen = be16(e + EK_DATALEN);
    UInt8 plain[EAPOL_MAX];
    if (!(info & KI_ENCDATA) || dlen < 24 || EK_DATA + dlen > elen ||
        aes_unwrap(ptk + 16, e + EK_DATA, dlen, plain))
        return;

    UInt32 plen = dlen - 8;
    for (UInt32 i = 0; i + 2 <= plen;) {
        UInt8 id = plain[i], l = plain[i + 1];
        if (id == 0xdd && l == 0)
            break;
        if (id == 0xdd && l >= 6 + 16 && i + 2 + l <= plen &&
            !memcmp(plain + i + 2, kOuiIeee, 3) && plain[i + 5] == 1) {
            UInt8 idx = plain[i + 6] & 0x3;
            writeCam(idx, idx, kBroadcast, plain + i + 8, true);
            setProperty("GTKIndex", idx, 8);
            rekeys++;
            break;
        }
        i += 2 + l;
    }

    UInt8 m[EK_DATA] = {};
    m[0] = e[0];
    m[1] = 3;
    m[3] = EK_DATA - 4;
    m[EK_DESC] = e[EK_DESC];
    m[EK_INFO] = 0x03;      // 0x0302: Secure | MIC | versión 2
    m[EK_INFO + 1] = 0x02;
    memcpy(m + EK_REPLAY, e + EK_REPLAY, 8);
    wpa_eapol_mic(ptk, m, EK_DATA, m + EK_MIC);
    sendData(bssid, 0x888e, m, EK_DATA, true);
}
