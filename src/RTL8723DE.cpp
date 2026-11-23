// Driver de macOS para el Realtek RTL8723DE (pci10ec,d723), portado de rtw88.
// Parte de hardware: energía, efuse, firmware, DMA, MAC/BB/RF, coexistencia,
// canal, recepción y escaneo pasivo. La estación (TX, WPA2) está en Station.cpp.
// IOLog no llega al log en la HP, así que los resultados se publican en ioreg.
#include "RTL8723DE.hpp"
#include "rtw8723d_pwrseq.h"
#include "rtw8723d_fw.h"
#include "rtw8723d_tables.h"

OSDefineMetaClassAndStructors(RTL8723DE, IOEthernetController)

// ---------------------------------------------------------------- registros

void RTL8723DE::w32mask(UInt32 a, UInt32 mask, UInt32 v)
{
    UInt32 shift = __builtin_ctz(mask);
    w32(a, (r32(a) & ~mask) | ((v << shift) & mask));
}

void RTL8723DE::w8mask(UInt32 a, UInt8 mask, UInt8 v)
{
    UInt32 shift = __builtin_ctz(mask);
    w8(a, (r8(a) & ~mask) | ((v << shift) & mask));
}

UInt32 RTL8723DE::r32mask(UInt32 a, UInt32 mask)
{
    return (r32(a) & mask) >> __builtin_ctz(mask);
}

// check_hw_ready() de util.c: compara el campo de la máscara ya desplazado.
bool RTL8723DE::checkHwReady(UInt32 a, UInt32 mask, UInt32 target)
{
    for (int i = 0; i < 1000; i++) {
        if (r32mask(a, mask) == target)
            return true;
        IODelay(10);
    }
    return false;
}

// ------------------------------------------------------------------ energía

// do_pwr_poll_cmd(): cada 50 us, hasta RTW_PWR_POLLING_CNT veces.
bool RTL8723DE::pollMask(UInt32 addr, UInt8 mask, UInt8 target)
{
    target &= mask;
    for (int i = 0; i < RTW_PWR_POLLING_CNT; i++) {
        if ((r8(addr) & mask) == target)
            return true;
        IODelay(50);
    }
    return false;
}

// rtw_pwr_cmd_polling(): en PCIe, si falla, alterna BIT_PFM_WOWL y reintenta.
bool RTL8723DE::pwrCmdPolling(const struct rtw_pwr_seq_cmd *cmd)
{
    if (pollMask(cmd->offset, cmd->mask, cmd->value))
        return true;

    UInt8 value = r8(REG_SYS_PW_CTRL);
    w8(REG_SYS_PW_CTRL, value & ~BIT_PFM_WOWL);
    w8(REG_SYS_PW_CTRL, value | BIT_PFM_WOWL);
    w8(REG_SYS_PW_CTRL, value & ~BIT_PFM_WOWL);
    w8(REG_SYS_PW_CTRL, value | BIT_PFM_WOWL);

    if (pollMask(cmd->offset, cmd->mask, cmd->value))
        return true;

    failedPollAddr = cmd->offset;
    return false;
}

// rtw_sub_pwr_seq_parser()
IOReturn RTL8723DE::subPwrSeq(const struct rtw_pwr_seq_cmd *cmd)
{
    UInt8 cutMask = cut_version_to_mask(cut);

    for (; cmd->cmd != RTW_PWR_CMD_END; cmd++) {
        if (!(cmd->intf_mask & RTW_PWR_INTF_PCI_MSK) || !(cmd->cut_mask & cutMask))
            continue;

        switch (cmd->cmd) {
        case RTW_PWR_CMD_WRITE: {
            UInt8 value = r8(cmd->offset);
            value &= ~cmd->mask;
            value |= (cmd->value & cmd->mask);
            w8(cmd->offset, value);
            break;
        }
        case RTW_PWR_CMD_POLLING:
            if (!pwrCmdPolling(cmd))
                return kIOReturnTimeout;
            break;
        case RTW_PWR_CMD_DELAY:
            if (cmd->value == RTW_PWR_DELAY_US)
                IODelay(cmd->offset);
            else
                IOSleep(cmd->offset);
            break;
        case RTW_PWR_CMD_READ:
            break;
        default:
            return kIOReturnBadArgument;
        }
    }
    return kIOReturnSuccess;
}

// rtw_pwr_seq_parser()
IOReturn RTL8723DE::pwrSeq(const struct rtw_pwr_seq_cmd * const *seq)
{
    for (; *seq; seq++) {
        IOReturn ret = subPwrSeq(*seq);
        if (ret != kIOReturnSuccess)
            return ret;
    }
    return kIOReturnSuccess;
}

// rtw_mac_pre_system_cfg(), rama de los chips con CPU 8051 (el 8723D lo es).
void RTL8723DE::preSystemCfg()
{
    w8(REG_RSV_CTRL, 0);
    if (r32(REG_SYS_CFG1) & BIT_LDO)
        w8(REG_LDO_SWR_CTRL, LDO_SEL);
    else
        w8(REG_LDO_SWR_CTRL, SPS_SEL);
}

// rtw_mac_power_switch(): REG_CR lee 0xEA mientras el MAC está apagado.
IOReturn RTL8723DE::powerSwitch(bool on)
{
    bool curOn = r8(REG_CR) != 0xea;
    if (on == curOn)
        return kIOReturnStillOpen;  // el -EALREADY de Linux

    return pwrSeq(on ? card_enable_flow_8723d : card_disable_flow_8723d);
}

// rtw_mac_power_on() + __rtw_mac_init_system_cfg_legacy()
IOReturn RTL8723DE::powerOn()
{
    preSystemCfg();

    IOReturn ret = powerSwitch(true);
    if (ret == kIOReturnStillOpen) {
        powerSwitch(false);
        preSystemCfg();
        ret = powerSwitch(true);
    }
    if (ret != kIOReturnSuccess)
        return ret;

    w8(REG_CR, 0xff);
    IOSleep(2);
    w8(REG_HWSEQ_CTRL, 0x7f);
    IOSleep(2);
    w8set(REG_SYS_CLKR, BIT_WAKEPAD_EN);
    w16clr(REG_GPIO_MUXCFG, BIT_EN_SIC);
    w16(REG_CR, 0x2ff);
    return kIOReturnSuccess;
}

// -------------------------------------------------------------------- efuse

// rtw_dump_physical_efuse_map() + rtw_dump_logical_efuse_map()
IOReturn RTL8723DE::readEfuse(UInt8 *logMap)
{
    UInt8 *phy = (UInt8 *)IOMalloc(EFUSE_PHY_SIZE);
    if (!phy)
        return kIOReturnNoMemory;

    // __rtw8723x_efuse_grant(on)
    w8(REG_EFUSE_ACCESS, EFUSE_ACCESS_ON);
    w16set(REG_SYS_FUNC_EN, BIT_FEN_ELDR);
    w16set(REG_SYS_CLKR, BIT_LOADER_CLK_EN | BIT_ANA8M);

    w32mask(REG_LDO_EFUSE_CTRL, BIT_MASK_EFUSE_BANK_SEL, 0);  // banco Wi-Fi
    w8(REG_LDO_EFUSE_CTRL + 3, r8(REG_LDO_EFUSE_CTRL + 3) & ~BIT_LDO25_EN);

    IOReturn ret = kIOReturnSuccess;
    UInt32 ctl = r32(REG_EFUSE_CTRL);
    for (UInt32 addr = 0; addr < EFUSE_PHY_SIZE; addr++) {
        ctl &= ~(BIT_MASK_EF_DATA | BITS_EF_ADDR);
        ctl |= (addr & BIT_MASK_EF_ADDR) << BIT_SHIFT_EF_ADDR;
        w32(REG_EFUSE_CTRL, ctl & ~BIT_EF_FLAG);

        UInt32 cnt = 1000000;
        do {
            IODelay(1);
            ctl = r32(REG_EFUSE_CTRL);
            if (--cnt == 0) {
                ret = kIOReturnTimeout;
                break;
            }
        } while (!(ctl & BIT_EF_FLAG));
        if (ret != kIOReturnSuccess)
            break;
        phy[addr] = ctl & BIT_MASK_EF_DATA;
    }

    w8(REG_EFUSE_ACCESS, EFUSE_ACCESS_OFF);

    if (ret == kIOReturnSuccess) {
        memset(logMap, 0xff, EFUSE_LOG_SIZE);
        for (UInt32 p = 0; p < EFUSE_PHY_SIZE - EFUSE_PROTECT_SIZE;) {
            UInt8 hdr1 = phy[p], hdr2 = phy[p + 1];
            if (hdr1 == 0xff || ((hdr1 & 0x1f) == 0xf && hdr2 == 0xff))
                break;

            UInt8 blk, wordEn;
            if ((hdr1 & 0x1f) == 0xf) {
                blk = ((hdr2 & 0xf0) >> 1) | ((hdr1 >> 5) & 0x07);
                wordEn = hdr2 & 0xf;
                p += 2;
            } else {
                blk = (hdr1 & 0xf0) >> 4;
                wordEn = hdr1 & 0xf;
                p += 1;
            }

            for (int i = 0; i < 4; i++) {
                if (wordEn & BIT(i))
                    continue;
                UInt32 l = (blk << 3) + (i << 1);
                if (p + 1 > EFUSE_PHY_SIZE - EFUSE_PROTECT_SIZE || l + 1 > EFUSE_LOG_SIZE) {
                    ret = kIOReturnBadArgument;
                    break;
                }
                logMap[l] = phy[p];
                logMap[l + 1] = phy[p + 1];
                p += 2;
            }
            if (ret != kIOReturnSuccess)
                break;
        }
    }

    IOFree(phy, EFUSE_PHY_SIZE);
    return ret;
}

// ----------------------------------------------------------------- firmware

// wlan_cpu_enable()
void RTL8723DE::wlanCpuEnable(bool enable)
{
    if (enable) {
        w8set(REG_RSV_CTRL + 1, BIT_WLMCU_IOIF);
        w8set(REG_SYS_FUNC_EN + 1, BIT_FEN_CPUEN);
    } else {
        w8clr(REG_SYS_FUNC_EN + 1, BIT_FEN_CPUEN);
        w8clr(REG_RSV_CTRL + 1, BIT_WLMCU_IOIF);
    }
}

// en_download_firmware_legacy()
void RTL8723DE::enDownloadFirmware(bool en)
{
    if (!en) {
        w8clr(REG_MCUFW_CTRL, BIT_MCUFWDL_EN);
        return;
    }

    wlanCpuEnable(false);
    wlanCpuEnable(true);

    w8set(REG_MCUFW_CTRL, BIT_MCUFWDL_EN);
    for (int i = 0; i < 10; i++) {
        if (r8(REG_MCUFW_CTRL) & BIT_MCUFWDL_EN)
            break;
        w8set(REG_MCUFW_CTRL, BIT_MCUFWDL_EN);
        IOSleep(20);
    }
    w32clr(REG_MCUFW_CTRL, BIT_ROM_DLEN);
}

// rtw_write_firmware_page(): cada página de 4 KB se escribe en la ventana 0x1000.
void RTL8723DE::writeFirmwarePage(UInt32 page, const UInt8 *data, UInt32 size)
{
    UInt32 blocks = size >> DLFW_BLK_SIZE_SHIFT_LEGACY;
    UInt32 remain = size & (DLFW_BLK_SIZE_LEGACY - 1);
    UInt32 addr = FW_START_ADDR_LEGACY;

    UInt32 v = r32(REG_MCUFW_CTRL);
    v &= ~BIT_ROM_PGE;
    v |= (page << BIT_SHIFT_ROM_PGE) & BIT_ROM_PGE;
    w32(REG_MCUFW_CTRL, v);

    for (UInt32 b = 0; b < blocks; b++) {
        w32(addr, OSReadLittleInt32(data, 0));
        addr += DLFW_BLK_SIZE_LEGACY;
        data += DLFW_BLK_SIZE_LEGACY;
    }
    if (remain) {
        UInt8 last[4] = {};
        memcpy(last, data, remain);
        w32(addr, OSReadLittleInt32(last, 0));
    }
}

// __rtw_download_firmware_legacy(): descarga + validación.
IOReturn RTL8723DE::downloadFirmware(const UInt8 *fw, UInt32 size)
{
    if (size <= FW_HDR_LEGACY_SIZE || OSReadLittleInt16(fw, 0) != FW_SIGNATURE_8723D)
        return kIOReturnBadArgument;

    const UInt8 *data = fw + FW_HDR_LEGACY_SIZE;
    size -= FW_HDR_LEGACY_SIZE;
    UInt32 totalPages = size >> DLFW_PAGE_SIZE_SHIFT_LEGACY;
    UInt32 lastPageSize = size & (DLFW_PAGE_SIZE_LEGACY - 1);

    enDownloadFirmware(true);

    bool written = false;
    for (int attempt = 0; attempt < 5 && !written; attempt++) {
        w8set(REG_MCUFW_CTRL, BIT_FWDL_CHK_RPT);
        UInt32 page;
        for (page = 0; page < totalPages; page++)
            writeFirmwarePage(page, data + page * DLFW_PAGE_SIZE_LEGACY, DLFW_PAGE_SIZE_LEGACY);
        if (lastPageSize)
            writeFirmwarePage(page, data + page * DLFW_PAGE_SIZE_LEGACY, lastPageSize);
        written = checkHwReady(REG_MCUFW_CTRL, BIT_FWDL_CHK_RPT, 1);
        setProperty("FirmwareAttempts", attempt + 1, 8);
    }

    enDownloadFirmware(false);
    if (!written)
        return kIOReturnIOError;

    // download_firmware_validate_legacy()
    UInt32 v = r32(REG_MCUFW_CTRL);
    v |= BIT_MCUFWDL_RDY;
    v &= ~BIT_WINTINI_RDY;
    w32(REG_MCUFW_CTRL, v);

    wlanCpuEnable(false);
    wlanCpuEnable(true);

    for (int i = 0; i < 10; i++) {
        if ((r32(REG_MCUFW_CTRL) & FW_READY_LEGACY) == FW_READY_LEGACY)
            return kIOReturnSuccess;
        IOSleep(20);
    }
    return kIOReturnTimeout;
}

// ---------------------------------------------------------------- DMA / PCIe

bool RTL8723DE::dmaAlloc(DmaRegion &r, size_t size)
{
    // El chip solo acepta direcciones de 32 bits en los descriptores.
    r.md = IOBufferMemoryDescriptor::inTaskWithPhysicalMask(
        kernel_task, kIODirectionInOut | kIOMemoryPhysicallyContiguous,
        size, 0x00000000FFFFF000ULL);
    if (!r.md)
        return false;
    if (r.md->prepare() != kIOReturnSuccess) {
        r.md->release();
        r.md = nullptr;
        return false;
    }

    r.cmd = IODMACommand::withSpecification(kIODMACommandOutputHost64, 32, 0,
                                            IODMACommand::kMapped, 0, 1);
    if (!r.cmd || r.cmd->setMemoryDescriptor(r.md) != kIOReturnSuccess) {
        dmaFree(r);
        return false;
    }

    UInt64 offset = 0;
    IODMACommand::Segment64 seg;
    UInt32 nseg = 1;
    if (r.cmd->gen64IOVMSegments(&offset, &seg, &nseg) != kIOReturnSuccess ||
        nseg != 1 || seg.fLength < size || seg.fIOVMAddr > 0xFFFFFFFFULL) {
        dmaFree(r);
        return false;
    }

    r.virt = (UInt8 *)r.md->getBytesNoCopy();
    r.phys = (UInt32)seg.fIOVMAddr;
    memset(r.virt, 0, size);
    return true;
}

void RTL8723DE::dmaFree(DmaRegion &r)
{
    if (r.cmd) {
        r.cmd->clearMemoryDescriptor();
        r.cmd->release();
    }
    if (r.md) {
        r.md->complete();
        r.md->release();
    }
    r = {};
}

bool RTL8723DE::allocRings()
{
    if (!dmaAlloc(txRing, TXQ_NUM * TX_RING_STRIDE))
        return false;
    if (!dmaAlloc(rxRing, RX_RING_LEN * CHIP_RX_BUF_DESC_SZ))
        return false;
    for (UInt32 i = 0; i < RX_RING_LEN; i++) {
        if (!dmaAlloc(rxBuf[i], RX_BUF_ALLOC))
            return false;
        resetRxDesc(i);
    }
    // Solo se usan las colas de gestión y BE.
    if (!dmaAlloc(txBuf[TXQ_MGMT], TX_RING_LEN * TX_BUF_SIZE) ||
        !dmaAlloc(txBuf[TXQ_BE], TX_RING_LEN * TX_BUF_SIZE))
        return false;
    return true;
}

// Solo se llama con el MAC apagado y el bus master desactivado.
void RTL8723DE::freeRings()
{
    for (int q = 0; q < TXQ_NUM; q++)
        dmaFree(txBuf[q]);
    for (UInt32 i = 0; i < RX_RING_LEN; i++)
        dmaFree(rxBuf[i]);
    dmaFree(rxRing);
    dmaFree(txRing);
}

// rtw_pci_reset_rx_desc() / rtw_pci_sync_rx_desc_device()
void RTL8723DE::resetRxDesc(UInt32 idx)
{
    UInt8 *d = rxRing.virt + idx * CHIP_RX_BUF_DESC_SZ;
    OSWriteLittleInt16(d, 0, RTK_PCI_RX_BUF_SIZE);  // buf_size
    OSWriteLittleInt16(d, 2, 0);                    // total_pkt_size
    OSWriteLittleInt32(d, 4, rxBuf[idx].phys);      // dma
}

// rtw_pci_reset_buf_desc() + rtw_pci_dma_reset()
void RTL8723DE::hciSetup()
{
    w8(RTK_PCI_CTRL + 3, r8(RTK_PCI_CTRL + 3) | 0xf7);

    for (int q = 0; q < TXQ_NUM; q++) {
        w32(kTxDesa[q], txRing.phys + q * TX_RING_STRIDE);
        if (kTxNum[q])
            w16(kTxNum[q], TX_RING_LEN & TRX_BD_IDX_MASK);
        txWp[q] = 0;
    }

    rxRp = 0;
    w16(RTK_PCI_RXBD_NUM_MPDUQ, RX_RING_LEN & TRX_BD_IDX_MASK);
    w32(RTK_PCI_RXBD_DESA_MPDUQ, rxRing.phys);

    w32(RTK_PCI_TXBD_RWPTR_CLR, 0xffffffff);

    w32set(RTK_PCI_CTRL, BIT_RST_TRXDMA_INTF | BIT_RX_TAG_EN);
}

// ------------------------------------------------------------------ MAC init

// rtw_mac_init(): txdma_queue_mapping + priority_queue_cfg (legacy) +
// __rtw8723x_mac_init + rtw_drv_info_cfg.
IOReturn RTL8723DE::macInit()
{
    // rqpn_table_8723d[1] (PCIe)
    UInt16 pqMap = BIT_TXDMA_HIQ_MAP(RTW_DMA_MAPPING_HIGH) |
                   BIT_TXDMA_MGQ_MAP(RTW_DMA_MAPPING_EXTRA) |
                   BIT_TXDMA_BKQ_MAP(RTW_DMA_MAPPING_LOW) |
                   BIT_TXDMA_BEQ_MAP(RTW_DMA_MAPPING_LOW) |
                   BIT_TXDMA_VIQ_MAP(RTW_DMA_MAPPING_NORMAL) |
                   BIT_TXDMA_VOQ_MAP(RTW_DMA_MAPPING_NORMAL);
    w16(REG_TXDMA_PQ_MAP, pqMap);
    w8(REG_CR, 0);
    w8(REG_CR, MAC_TRX_ENABLE);

    // rtw_set_trx_fifo_info() + page_table_8723d[1] = {hq 12, nq 2, lq 2, exq 0, gap 1}
    UInt16 txffPg = CHIP_TXFF_SIZE / TX_PAGE_SIZE;
    UInt16 rsvdBoundary = txffPg - CHIP_RSVD_DRV_PG_NUM;
    UInt16 pubq = rsvdBoundary - 12 - 2 - 2 - 0 - 1;

    w32(REG_RQPN_NPQ, BIT_RQPN_NE(2, 0));
    w32(REG_RQPN, BIT_RQPN_HLP(12, 2, pubq));
    w8(REG_TRXFF_BNDY, rsvdBoundary);
    w16(REG_TRXFF_BNDY + 2, CHIP_RXFF_SIZE - REPORT_BUF - 1);
    w8(REG_DWBCN0_CTRL + 1, rsvdBoundary);
    w8(REG_BCNQ_BDNY, rsvdBoundary);
    w8(REG_MGQ_BDNY, rsvdBoundary);
    w8(REG_WMAC_LBK_BF_HD, rsvdBoundary);
    w32set(REG_AUTO_LLT, BIT_AUTO_INIT_LLT);
    if (!checkHwReady(REG_AUTO_LLT, BIT_AUTO_INIT_LLT, 0))
        return kIOReturnTimeout;

    // __rtw8723x_mac_init()
    w32(REG_TCR, BIT_TCR_CFG);
    w16(REG_RXFLTMAP0, WLAN_RX_FILTER0);
    w16(REG_RXFLTMAP1, WLAN_RX_FILTER1);
    w16(REG_RXFLTMAP2, WLAN_RX_FILTER2);
    w32(REG_RCR, WLAN_RCR_CFG);
    w32(REG_INT_MIG, 0);
    w32(REG_MCUTST_1, 0x0);
    w8(REG_MISC_CTRL, BIT_DIS_SECOND_CCA);
    w8(REG_2ND_CCA_CTRL, 0);

    // rtw_drv_info_cfg()
    w8(REG_RX_DRVINFO_SZ, PHY_STATUS_SIZE);
    w32set(REG_RCR, BIT_APP_PHYSTS);
    w32clr(REG_WMAC_OPTION_FUNCTION + 4, BIT(8) | BIT(9));
    return kIOReturnSuccess;
}

// ------------------------------------------------------------------- RF/BB

// rtw_phy_read_rf_sipi() con rtw8723x_common.rf_sipi_addr.
UInt32 RTL8723DE::readRf(UInt32 path, UInt32 addr, UInt32 mask)
{
    static const UInt32 hssi1[2] = {0x820, 0x828};
    static const UInt32 hssi2[2] = {0x824, 0x82c};
    static const UInt32 lssiRead[2] = {0x8a0, 0x8a4};
    static const UInt32 lssiReadPi[2] = {0x8b8, 0x8bc};

    addr &= 0xff;
    UInt32 v = r32(hssi2[path]);
    v = (v & ~LSSI_READ_ADDR_MASK) | (addr << 23);
    w32(hssi2[path], v);

    v = r32(hssi2[RF_PATH_A]);
    w32(hssi2[RF_PATH_A], v & ~LSSI_READ_EDGE_MASK);
    w32(hssi2[RF_PATH_A], v | LSSI_READ_EDGE_MASK);

    IODelay(120);

    UInt32 enPi = r32mask(hssi1[path], BIT(8));
    UInt32 val = r32mask(enPi ? lssiReadPi[path] : lssiRead[path], LSSI_READ_DATA_MASK);
    return (val & mask) >> __builtin_ctz(mask);
}

// rtw_phy_write_rf_reg_sipi()
void RTL8723DE::writeRf(UInt32 path, UInt32 addr, UInt32 mask, UInt32 data)
{
    static const UInt32 sipi[2] = {RF_SIPI_ADDR_A, RF_SIPI_ADDR_B};

    addr &= 0xff;
    mask &= RFREG_MASK;
    if (mask != RFREG_MASK) {
        UInt32 old = readRf(path, addr, RFREG_MASK);
        data = (old & ~mask) | (data << __builtin_ctz(mask));
    }
    w32(sipi[path], ((addr << 20) | (data & 0x000fffff)) & 0x0fffffff);
    IODelay(13);
}

// rtw_parse_tbl_phy_cond() + rtw_phy_cfg_{mac,agc,bb,rf}. Condiciones del
// driver: cut del chip, pkg 15, interfaz PCIe, rfe 0 (rtw8723x fija rfe_option = 0).
enum { TBL_MAC, TBL_AGC, TBL_BB, TBL_RF_A };

void RTL8723DE::loadPhyTable(const UInt32 *tbl, size_t words, int kind)
{
    UInt8 drvCut = cut ? cut : 15;
    bool matched = true, skipped = false;
    UInt32 posCond = 0;

    for (size_t i = 0; i + 1 < words; i += 2) {
        UInt32 addr = tbl[i], data = tbl[i + 1];

        if (PHY_COND_POS(addr)) {
            switch (PHY_COND_BRANCH(addr)) {
            case BRANCH_ENDIF:
                matched = true;
                skipped = false;
                break;
            case BRANCH_ELSE:
                matched = !skipped;
                break;
            default:
                posCond = addr;
                break;
            }
            continue;
        }
        if (PHY_COND_NEG(addr)) {
            if (!skipped) {
                bool positive =
                    !(PHY_COND_CUT(posCond) && PHY_COND_CUT(posCond) != drvCut) &&
                    !(PHY_COND_PKG(posCond) && PHY_COND_PKG(posCond) != 15) &&
                    !(PHY_COND_INTF(posCond) && PHY_COND_INTF(posCond) != INTF_PCIE) &&
                    PHY_COND_RFE(posCond) == 0;
                matched = positive;
                skipped = positive;
            } else {
                matched = false;
            }
            continue;
        }
        if (!matched)
            continue;

        switch (kind) {
        case TBL_MAC:
            w8(addr, data);
            break;
        case TBL_AGC:
            w32(addr, data);
            break;
        case TBL_BB:
            if (addr == 0xfe) IOSleep(50);
            else if (addr == 0xfd) IODelay(5000);
            else if (addr == 0xfc) IODelay(1000);
            else if (addr == 0xfb) IODelay(50);
            else if (addr == 0xfa) IODelay(5);
            else if (addr == 0xf9) IODelay(1);
            else w32(addr, data);
            break;
        case TBL_RF_A:
            if (addr == 0xffe) IOSleep(50);
            else if (addr == 0xfe) IODelay(100);
            else {
                writeRf(RF_PATH_A, addr, RFREG_MASK, data);
                IODelay(1);
            }
            break;
        }
    }
}

// __rtw8723x_lck(): calibración del LC del sintetizador.
void RTL8723DE::lck()
{
    UInt8 ctx = r8(REG_CTX);
    if (ctx & BIT_MASK_CTX_TYPE)
        w8(REG_CTX, ctx & ~BIT_MASK_CTX_TYPE);
    else
        w8(REG_TXPAUSE, 0xFF);

    UInt32 lc = readRf(RF_PATH_A, RF_CFGCH, RFREG_MASK);
    writeRf(RF_PATH_A, RF_CFGCH, RFREG_MASK, lc | BIT_LCK);

    bool done = false;
    for (int i = 0; i < 100 && !done; i++) {
        IOSleep(10);
        done = readRf(RF_PATH_A, RF_CFGCH, BIT_LCK) != 0x1;
    }
    setProperty("LCK", done ? "ok" : "timeout");

    writeRf(RF_PATH_A, RF_CFGCH, RFREG_MASK, lc);
    if (ctx & BIT_MASK_CTX_TYPE)
        w8(REG_CTX, ctx);
    else
        w8(REG_TXPAUSE, 0x00);
}

// rtw8723d_phy_set_param()
void RTL8723DE::phySetParam()
{
    w16set(REG_SYS_FUNC_EN, BIT_FEN_EN_25_1 | BIT_FEN_BB_GLB_RST | BIT_FEN_BB_RSTB);
    w8set(REG_RF_CTRL, BIT_RF_EN | BIT_RF_RSTB | BIT_RF_SDM_RSTB);
    w8(REG_AFE_CTRL1 + 1, 0x80);

    // rtw_phy_load_tables(): mac, bb, agc y rf (un solo camino RF).
    loadPhyTable(rtw8723d_mac, ARRAY_LEN(rtw8723d_mac), TBL_MAC);
    loadPhyTable(rtw8723d_bb, ARRAY_LEN(rtw8723d_bb), TBL_BB);
    loadPhyTable(rtw8723d_agc, ARRAY_LEN(rtw8723d_agc), TBL_AGC);
    loadPhyTable(rtw8723d_rf_a, ARRAY_LEN(rtw8723d_rf_a), TBL_RF_A);

    w32clr(REG_RCR, BIT_RCR_ADF);
    w8set(REG_HIQ_NO_LMT_EN, BIT_HIQ_NO_LMT_EN_ROOT);
    w16set(REG_AFE_CTRL_4, BIT_CK320M_AFE_EN | BIT_EN_SYN);

    UInt8 xtal = crystalCap & 0x3F;
    w32mask(REG_AFE_CTRL3, BIT_MASK_XTAL, xtal | (xtal << 6));
    w32set(REG_FPGA0_RFMOD, BIT_CCKEN | BIT_OFDMEN);
    if ((afe >> 4) == 14) {
        w32set(REG_AFE_CTRL3, BIT_XTAL_GMP_BIT4);
        w32clr(REG_AFE_CTRL1, BITS_PLL);
        w32set(REG_LDO_SWR_CTRL, BIT_XTA1);
        w32clr(REG_LDO_SWR_CTRL, BIT_XTA0);
    }

    w8(REG_SLOT, WLAN_SLOT_TIME);
    w8(REG_FWHW_TXQ_CTRL + 1, WLAN_TXQ_RPT_EN);
    w16(REG_RETRY_LIMIT, WLAN_RL_VAL);
    w32(REG_BAR_MODE_CTRL, WLAN_BAR_VAL);
    w8(REG_ATIMWND, 0x2);
    w8(REG_BCN_CTRL, BIT_DIS_TSF_UDT | BIT_EN_BCN_FUNCTION | BIT_EN_TXBCN_RPT);
    UInt32 v = r32(REG_TBTT_PROHIBIT);
    v &= ~BIT_MASK_TBTT_MASK;
    v |= WLAN_TBTT_TIME_STOP_BCN;
    w8(REG_TBTT_PROHIBIT, v);
    w8(REG_PIFS, WLAN_PIFS_VAL);
    w8(REG_AGGR_BREAK_TIME, WLAN_AGG_BRK_TIME);
    w16(REG_NAV_PROT_LEN, WLAN_NAV_PROT_LEN);
    w16(REG_MAC_SPEC_SIFS, WLAN_SPEC_SIFS);
    w16(REG_SIFS, WLAN_SPEC_SIFS);
    w16(REG_SIFS + 2, WLAN_SPEC_SIFS);
    w8(REG_SINGLE_AMPDU_CTRL, BIT_EN_SINGLE_APMDU);
    w8(REG_RX_PKT_LIMIT, WLAN_RX_PKT_LIMIT);
    w8(REG_MAX_AGGR_NUM, WLAN_MAX_AGG_NR);
    w8(REG_AMPDU_MAX_TIME, WLAN_AMPDU_MAX_TIME);
    w8(REG_LEDCFG2, WLAN_ANT_SEL);

    w32(REG_LTR_IDLE_LATENCY, WLAN_LTR_IDLE_LAT);
    w32(REG_LTR_ACTIVE_LATENCY, WLAN_LTR_ACT_LAT);
    w32(REG_LTR_CTRL_BASIC, WLAN_LTR_CTRL1);
    w32(REG_LTR_CTRL_BASIC + 4, WLAN_LTR_CTRL2);

    w16set(REG_TXDMA_OFFSET_CHK, BIT_DROP_DATA_EN);

    lck();

    // Fija la ganancia inicial (IGI) en 0x20, igual que rtw88.
    w32mask(REG_OFDM0_XAAGC1, MASKBYTE0, 0x50);
    w32mask(REG_OFDM0_XAAGC1, MASKBYTE0, 0x20);
}

// ----------------------------------------------------------- coexistencia BT

// rtw_coex_read_indirect_reg() / ltecoex_read_reg()
UInt32 RTL8723DE::readIndirect(UInt16 addr)
{
    if (!checkHwReady(REG_LTECOEX_CTRL, LTECOEX_READY, 1))
        return 0;
    w32(REG_LTECOEX_CTRL, 0x800F0000 | addr);
    return r32(REG_LTECOEX_READ_DATA);
}

// rtw_coex_write_indirect_reg() / ltecoex_reg_write()
void RTL8723DE::writeIndirect(UInt16 addr, UInt32 mask, UInt32 val)
{
    UInt32 shift = __builtin_ctz(mask);
    UInt32 tmp = readIndirect(addr);
    tmp = (tmp & ~mask) | ((val << shift) & mask);
    if (!checkHwReady(REG_LTECOEX_CTRL, LTECOEX_READY, 1))
        return;
    w32(REG_LTECOEX_WRITE_DATA, tmp);
    w32(REG_LTECOEX_CTRL, 0xC00F0000 | addr);
}

// rtw8723d_coex_cfg_rfe_type(): antena principal o auxiliar, compartida o no.
void RTL8723DE::coexSetRfeType()
{
    bool shareAnt = btSetting & BIT(0);
    bool aux = btSetting & BIT(6);

    if (shareAnt)
        w16(REG_BB_SEL_BTG, aux ? 0x80 : 0x200);
    else
        w16(REG_BB_SEL_BTG, aux ? 0x280 : 0x0);

    writeIndirect(LTE_COEX_CTRL, BIT_LTE_COEX_EN, 0x0);
    writeIndirect(LTE_WL_TRX_CTRL, MASKLWORD, 0xffff);
    writeIndirect(LTE_BT_TRX_CTRL, MASKLWORD, 0xffff);
}

// rtw_coex_coex_ctrl_owner(), con btg_reg_8723d = {REG_BTG_SEL, BIT_MASK_BTG_WL}.
void RTL8723DE::coexCtrlOwner(bool wifi)
{
    if (wifi) {
        w8set(REG_SYS_SDIO_CTRL + 3, BIT_LTE_MUX_CTRL_PATH >> 24);
        w8set(REG_BTG_SEL, BIT_MASK_BTG_WL);
    } else {
        w8clr(REG_SYS_SDIO_CTRL + 3, BIT_LTE_MUX_CTRL_PATH >> 24);
        w8clr(REG_BTG_SEL, BIT_MASK_BTG_WL);
    }
}

// Subconjunto de rtw_coex_power_on_setting() + rtw_coex_init_hw_config() con
// la antena en modo "solo Wi-Fi" (COEX_SET_ANT_WONLY): el Wi-Fi toma la antena
// por software. La coexistencia real con BT (PTA, TDMA por H2C) llega después.
void RTL8723DE::coexWifiOnly()
{
    w8set(REG_SYS_FUNC_EN, BIT_FEN_BB_GLB_RST | BIT_FEN_BB_RSTB);
    coexSetRfeType();
    w8(0xff1a, 0x0);

    // rtw8723d_coex_cfg_gnt_debug()
    w8mask(REG_LEDCFG2, BIT(6), 0);
    w8mask(REG_PAD_CTRL1 + 3, BIT(0), 0);
    w8mask(REG_GPIO_INTM + 2, BIT(4), 0);
    w8mask(REG_GPIO_MUXCFG + 2, BIT(1), 0);
    w8mask(REG_PAD_CTRL1 + 3, BIT(1), 0);
    w8mask(REG_PAD_CTRL1 + 2, BIT(7), 0);
    w8mask(REG_SYS_CLKR + 1, BIT(1), 0);
    w8mask(REG_SYS_SDIO_CTRL + 3, BIT(3), 0);

    w8set(REG_BCN_CTRL, BIT_EN_BCN_FUNCTION);

    // __rtw8723x_coex_cfg_init()
    w8mask(REG_BT_TDMA_TIME, BIT_MASK_SAMPLE_RATE, 0x5);
    w8(REG_BT_STAT_CTRL, 0x1);
    w32set(REG_GPIO_MUXCFG, BIT_BT_PTA_EN);
    w32set(REG_GPIO_MUXCFG, BIT_PO_BT_PTA_PINS);
    w8set(REG_QUEUE_CTRL, BIT_PTA_WL_TX_EN);

    // COEX_SET_ANT_WONLY: GNT_BT = SW low, GNT_WL = SW high, control para Wi-Fi.
    writeIndirect(LTE_COEX_CTRL, 0xc000, COEX_GNT_SET_SW_LOW);
    writeIndirect(LTE_COEX_CTRL, 0x0c00, COEX_GNT_SET_SW_LOW);
    writeIndirect(LTE_COEX_CTRL, 0x3000, COEX_GNT_SET_SW_HIGH);
    writeIndirect(LTE_COEX_CTRL, 0x0300, COEX_GNT_SET_SW_HIGH);
    coexCtrlOwner(true);

    setProperty("LTE_COEX_CTRL", readIndirect(LTE_COEX_CTRL), 32);
}

// --------------------------------------------------------------------- canal

// rtw8723d_cfg_notch()
void RTL8723DE::cfgNotch(UInt8 ch, bool notch)
{
    if (!notch) {
        w32mask(REG_OFDM0_RXDSP, BIT_MASK_RXDSP, 0x1f);
        w32mask(REG_OFDM0_RXDSP, BIT_EN_RXDSP, 0x0);
        w32(REG_OFDM1_CSI1, 0);
        w32(REG_OFDM1_CSI2, 0);
        w32(REG_OFDM1_CSI3, 0);
        w32(REG_OFDM1_CSI4, 0);
        w32mask(REG_OFDM1_CFOTRK, BIT_EN_CFOTRK, 0x0);
        return;
    }
    if (ch == 13) {
        w32mask(REG_OFDM0_RXDSP, BIT_MASK_RXDSP, 0xb);
        w32mask(REG_OFDM0_RXDSP, BIT_EN_RXDSP, 0x1);
        w32(REG_OFDM1_CSI1, 0x04000000);
        w32(REG_OFDM1_CSI2, 0);
        w32(REG_OFDM1_CSI3, 0);
        w32(REG_OFDM1_CSI4, 0);
        w32mask(REG_OFDM1_CFOTRK, BIT_EN_CFOTRK, 0x1);
    }
}

// rtw8723d_set_channel(): RF + MAC + BB, siempre a 20 MHz.
void RTL8723DE::setChannel(UInt8 ch)
{
    // rtw8723d_set_channel_rf()
    UInt32 a = readRf(RF_PATH_A, RF_CFGCH, RFREG_MASK);
    UInt32 b = readRf(RF_PATH_B, RF_CFGCH, RFREG_MASK);
    a = (a & ~RFCFGCH_CHANNEL_MASK) | (ch & RFCFGCH_CHANNEL_MASK);
    b = (b & ~RFCFGCH_CHANNEL_MASK) | (ch & RFCFGCH_CHANNEL_MASK);
    a = (a & ~RFCFGCH_BW_MASK) | RFCFGCH_BW_20M;
    writeRf(RF_PATH_A, RF_CFGCH, RFREG_MASK, a);
    writeRf(RF_PATH_B, RF_CFGCH, RFREG_MASK, b);

    // rtw8723d_spur_cal(): el canal 13 mide la PSD para decidir el notch.
    if (ch < 13) {
        cfgNotch(ch, false);
    } else {
        w32(REG_ANALOG_P4, DIS_3WIRE);
        w32(REG_PSDFN, FREQ_CH13);
        w32(REG_PSDFN, START_PSD | FREQ_CH13);
        IOSleep(30);
        bool notch = r32(REG_PSDRPT) >= SPUR_THRES;
        w32(REG_PSDFN, FREQ_CH13);
        w32(REG_ANALOG_P4, EN_3WIRE);
        cfgNotch(ch, notch);
    }

    // rtw_set_channel_mac(), rama 8051
    w8(REG_DATA_SC, BIT_TXSC_20M(0) | BIT_TXSC_40M(0));
    w32clr(REG_WMAC_TRXPTCL_CTL, BIT_RFMOD);

    // rtw8723d_set_channel_bb(), cck_dfir_cfg[0] para canales <= 13
    w32(0xA24, 0x64B80C1C);
    w32(0xA28, 0x00008810);
    w32(0xAAC, 0x01235667);
    w32mask(REG_FPGA0_RFMOD, BIT_MASK_RFMOD, 0x0);
    w32mask(REG_FPGA1_RFMOD, BIT_MASK_RFMOD, 0x0);
    w32mask(REG_BBRX_DFIR, BIT_RXBB_DFIR_EN, 1);
    w32mask(REG_BBRX_DFIR, BIT_MASK_RXBB_DFIR, 0xa);
}

// ---------------------------------------------------------------- recepción

// Extrae SSID, BSSID y canal de beacons y probe responses.
void RTL8723DE::parseFrame(const UInt8 *f, UInt32 len, SInt8 rssi, UInt8 ch)
{
    if (len < 24 + 12 + 4)
        return;
    UInt8 type = (f[0] >> 2) & 0x3, subtype = (f[0] >> 4) & 0xf;
    if (type == 2)
        rxData++;
    if (type != 0)
        return;
    rxMgmt++;
    if (subtype != 8 && subtype != 5)  // beacon / probe response
        return;
    rxBeacon++;
    if (staConnected && !memcmp(f + 16, bssid, 6))
        lastBeaconTick = ticks;

    const UInt8 *frameBssid = f + 16;
    const UInt8 *ie = f + 24 + 12;
    const UInt8 *end = f + len - 4;  // sin la FCS
    char ssid[33] = {};
    UInt8 dsChannel = ch;
    const UInt8 *rsn = nullptr;

    while (ie + 2 <= end && ie + 2 + ie[1] <= end) {
        if (ie[0] == 0 && ie[1] <= 32) {
            memcpy(ssid, ie + 2, ie[1]);
            for (int i = 0; i < ie[1]; i++)
                if (ssid[i] < 0x20 || ssid[i] > 0x7e)
                    ssid[i] = '?';
        } else if (ie[0] == 3 && ie[1] == 1) {
            dsChannel = ie[2];
        } else if (ie[0] == 48 && ie[1] + 2 <= MAX_RSN_IE) {
            rsn = ie;
        }
        ie += 2 + ie[1];
    }

    for (UInt32 i = 0; i < bssCount; i++) {
        if (!memcmp(bss[i].bssid, frameBssid, 6)) {
            bss[i].beacons++;
            if (rssi > bss[i].rssi)
                bss[i].rssi = rssi;
            return;
        }
    }
    if (bssCount >= MAX_BSS)
        return;
    BssEntry &e = bss[bssCount++];
    memcpy(e.bssid, frameBssid, 6);
    memcpy(e.ssid, ssid, sizeof(ssid));
    e.channel = dsChannel;
    e.rssi = rssi;
    e.beacons = 1;
    if (rsn) {
        e.rsnLen = rsn[1] + 2;
        memcpy(e.rsn, rsn, e.rsnLen);
    }
}

// rtw_pci_rx_napi() simplificado: sondeo del índice de hardware, sin IRQ.
void RTL8723DE::processRx(UInt8 ch)
{
    UInt32 hw = (r32(RTK_PCI_RXBD_IDX_MPDUQ) & TRX_BD_HW_IDX_MASK) >> 16;
    if (hw >= RX_RING_LEN)
        return;

    while (rxRp != hw) {
        const UInt8 *buf = rxBuf[rxRp].virt;
        UInt32 w0 = OSReadLittleInt32(buf, 0);
        UInt32 w2 = OSReadLittleInt32(buf, 8);
        UInt32 pktLen = w0 & RTW_RX_DESC_W0_PKT_LEN;
        UInt32 drvInfo = ((w0 & RTW_RX_DESC_W0_DRV_INFO_SIZE) >> 16) * 8;
        UInt32 shift = (w0 & RTW_RX_DESC_W0_SHIFT) >> 24;
        UInt32 off = CHIP_RX_PKT_DESC_SZ + drvInfo + shift;

        rxTotal++;
        if (ch >= 1 && ch <= 14)
            rxPerChannel[ch - 1]++;

        if (w2 & RTW_RX_DESC_W2_C2H) {
            rxC2h++;
        } else if (w0 & RTW_RX_DESC_W0_CRC32) {
            rxCrc++;
        } else if (off + pktLen <= RTK_PCI_RX_BUF_SIZE) {
            SInt8 rssi = -100;
            if ((w0 & RTW_RX_DESC_W0_PHYST) && drvInfo >= 4) {
                const UInt8 *phy = buf + CHIP_RX_PKT_DESC_SZ;
                UInt8 page = phy[0] & 0xf, pwdb = phy[1];
                rssi = (SInt8)(page == 0 ? (int)pwdb - 97 : (int)pwdb - 110);
            }
            parseFrame(buf + off, pktLen, rssi, ch);
            if (staActive) {
                // rtw_rx_query_rx_desc(): descifrada si el HW lo hizo (sin SWDEC).
                bool decrypted = !(w0 & RTW_RX_DESC_W0_SWDEC) &&
                                 (w0 & RTW_RX_DESC_W0_ENC_TYPE) != 0;
                handleStaFrame(buf + off, pktLen, decrypted);
            }
        }

        resetRxDesc(rxRp);
        rxRp = (rxRp + 1) % RX_RING_LEN;
    }
    w16(RTK_PCI_RXBD_IDX_MPDUQ, rxRp);
}

// Escaneo pasivo: 150 ms por canal escuchando beacons, canales 1 a 13.
void RTL8723DE::passiveScan()
{
    // hal.rcr por defecto de rtw88 + aceptar beacons de cualquier BSS.
    UInt32 rcr = BIT_APP_FCS | BIT_APP_MIC | BIT_APP_ICV | BIT_PKTCTL_DLEN |
                 BIT_HTC_LOC_CTRL | BIT_APP_PHYSTS | BIT_AB | BIT_AM | BIT_APM;
    rcr &= ~(BIT_CBSSID_BCN | BIT_CBSSID_DATA);
    w32(REG_RCR, rcr);

    for (UInt8 ch = 1; ch <= 13; ch++) {
        setChannel(ch);
        for (int t = 0; t < 30; t++) {
            IOSleep(5);
            processRx(ch);
        }
    }
    w32(REG_RCR, 0);
}

void RTL8723DE::publishScan()
{
    setProperty("RxTotal", rxTotal, 32);
    setProperty("RxCrcErrors", rxCrc, 32);
    setProperty("RxC2H", rxC2h, 32);
    setProperty("RxMgmt", rxMgmt, 32);
    setProperty("RxData", rxData, 32);
    setProperty("RxBeacons", rxBeacon, 32);
    setProperty("RxPerChannel", rxPerChannel, sizeof(rxPerChannel));

    OSArray *list = OSArray::withCapacity(bssCount);
    if (!list)
        return;
    for (UInt32 i = 0; i < bssCount; i++) {
        char line[96];
        const BssEntry &e = bss[i];
        snprintf(line, sizeof(line), "ch%-2u %4d dBm  %02x:%02x:%02x:%02x:%02x:%02x  %s",
                 e.channel, e.rssi, e.bssid[0], e.bssid[1], e.bssid[2],
                 e.bssid[3], e.bssid[4], e.bssid[5], e.ssid[0] ? e.ssid : "<oculto>");
        OSString *s = OSString::withCString(line);
        if (s) {
            list->setObject(s);
            s->release();
        }
    }
    setProperty("ScanResults", list);
    list->release();
}

void RTL8723DE::setHexProperty(const char *key, const UInt8 *bytes, int len, char sep)
{
    char buf[64] = {};
    int pos = 0;
    for (int i = 0; i < len && pos + 4 < (int)sizeof(buf); i++) {
        if (i && sep)
            buf[pos++] = sep;
        pos += snprintf(buf + pos, sizeof(buf) - pos, "%02x", bytes[i]);
    }
    setProperty(key, buf);
}

// -------------------------------------------------------------- arranque

bool RTL8723DE::start(IOService *provider)
{
    if (!super::start(provider))
        return false;

    // Interruptor de emergencia: arrancar con este boot-arg desactiva el driver.
    UInt32 off = 0;
    if (PE_parse_boot_argn("rtl8723de_off", &off, sizeof(off)))
        return false;

    pci = OSDynamicCast(IOPCIDevice, provider);
    if (!pci)
        return false;
    pci->retain();
    pci->open(this);

    // Sin bus master hasta que haga falta DMA (bringUp): la efuse se lee por MMIO.
    // Si el chip quedó encendido de un arranque en caliente, así no puede
    // seguir escribiendo en la RAM mientras lo apagamos.
    pci->enablePCIPowerManagement(kPCIPMCSPowerStateD0);
    pci->setMemoryEnable(true);
    pci->setBusLeadEnable(false);

    bar = pci->mapDeviceMemoryWithRegister(kIOPCIConfigBaseAddress2);
    if (!bar) {
        setProperty("Stage", "bar2-map-failed");
        return false;
    }
    base = (volatile UInt8 *)bar->getVirtualAddress();
    if (r8(REG_CR) != 0xea) {
        setProperty("WarmBootChipOn", true);
        powerSwitch(false);
    }

    UInt32 cfg1 = r32(REG_SYS_CFG1);
    cut = (cfg1 >> BIT_SHIFT_CHIP_VER) & BIT_MASK_CHIP_VER;
    setProperty("CutVersion", cut, 8);

    // 1. Como en el probe de rtw88: encender, leer la efuse y apagar.
    IOReturn ret = powerOn();
    setProperty("PowerOn", ret == kIOReturnSuccess ? "ok" : "failed");
    if (ret != kIOReturnSuccess) {
        if (ret == kIOReturnTimeout)
            setProperty("PowerOnPollFailedAt", failedPollAddr, 16);
        registerService();
        return true;
    }

    UInt8 *logMap = (UInt8 *)IOMalloc(EFUSE_LOG_SIZE);
    if (logMap && readEfuse(logMap) == kIOReturnSuccess) {
        memcpy(macAddr, logMap + EFUSE_LOG_MAC_ADDR, 6);
        crystalCap = logMap[EFUSE_LOG_XTAL_K] == 0xff ? 0 : logMap[EFUSE_LOG_XTAL_K];
        afe = logMap[EFUSE_LOG_AFE];
        btSetting = logMap[EFUSE_LOG_BT_SETTING];
        memcpy(pwrCck, logMap + EFUSE_LOG_TXPWR_CCK, sizeof(pwrCck));
        memcpy(pwrBw40, logMap + EFUSE_LOG_TXPWR_BW40, sizeof(pwrBw40));
        pwrHtDiff = logMap[EFUSE_LOG_TXPWR_HT1S_DIFF];
        setProperty("Efuse", "ok");
        setProperty("EfuseLogical", logMap, EFUSE_LOG_SIZE);
        setHexProperty("MACAddress", macAddr, 6, ':');
        setProperty("CrystalCap", crystalCap, 8);
        setProperty("BtSetting", btSetting, 8);
        setProperty("BtCoex", (logMap[EFUSE_LOG_RF_BOARD] & 0xe0) == 0x20 ? "yes" : "no");
    } else {
        setProperty("Efuse", "failed");
    }
    if (logMap)
        IOFree(logMap, EFUSE_LOG_SIZE);
    powerSwitch(false);

    // Todo el acceso al hardware se serializa en el work loop: comandos de
    // rtlctl (por la compuerta), el temporizador de recepción y la salida.
    if (!workLoop)
        createWorkLoop();
    IOWorkLoop *wl = getWorkLoop();
    gate = IOCommandGate::commandGate(this);
    rxTimer = IOTimerEventSource::timerEventSource(
        this, OSMemberFunctionCast(IOTimerEventSource::Action, this, &RTL8723DE::rxTimerFired));
    // Fuente sin hardware detrás: outputPacket la dispara para drenar la cola.
    txSource = IOInterruptEventSource::interruptEventSource(
        this, OSMemberFunctionCast(IOInterruptEventSource::Action, this, &RTL8723DE::txSourceFired));
    txqLock = IOLockAlloc();
    if (!wl || !gate || !rxTimer || !txSource || !txqLock ||
        wl->addEventSource(gate) != kIOReturnSuccess ||
        wl->addEventSource(rxTimer) != kIOReturnSuccess ||
        wl->addEventSource(txSource) != kIOReturnSuccess) {
        setProperty("Stage", "workloop-failed");
        return false;
    }

    // Lo arriesgado (DMA, radio) no corre al arrancar: se pide con rtlctl.
    // Así un fallo no deja a la HP en un bucle de kernel panics.
    if (!attachInterface((IONetworkInterface **)&netif, false)) {
        setProperty("Stage", "interface-failed");
        return false;
    }
    setLink(false);
    netif->registerService();
    setProperty("Stage", "idle");
    registerService();
    return true;
}

// rtw_power_on() + rtw_core_start(). Devuelve nullptr si todo salió bien o el
// nombre de la etapa que falló.
const char *RTL8723DE::bringUp()
{
    memset(bss, 0, sizeof(bss));
    bssCount = rxTotal = rxCrc = rxC2h = rxMgmt = rxData = rxBeacon = 0;
    memset(rxPerChannel, 0, sizeof(rxPerChannel));

    pci->setBusLeadEnable(true);

    if (!allocRings())
        return "alloc-rings";

    hciSetup();
    if (powerOn() != kIOReturnSuccess)
        return "power-on";

    IOReturn ret = downloadFirmware(firmware_rtw8723d_fw_bin, firmware_rtw8723d_fw_bin_len);
    setProperty("FirmwareReturn", ret, 32);
    if (ret != kIOReturnSuccess)
        return "firmware";
    hciSetup();  // __rtw_download_firmware_legacy(): "reset desc and index"

    if (macInit() != kIOReturnSuccess)
        return "mac-init";

    phySetParam();
    w8(REG_FWHW_TXQ_CTRL + 1, WLAN_TXQ_RPT_EN);  // __rtw8723x_mac_postinit()

    // rtw_hci_start() sin interrupciones: la recepción se sondea.
    w32(RTK_PCI_HIMR0, 0);
    w32(RTK_PCI_HIMR1, 0);

    coexWifiOnly();
    setTxPower(1);
    enableSecEngine();  // rtw_core_start(): rtw_sec_enable_sec_engine()
    return nullptr;
}

// Apagar el MAC (detiene el DMA) y cortar el bus master antes de liberar la
// memoria a la que el chip podría escribir.
void RTL8723DE::shutDown()
{
    staActive = false;
    setProperty("REG_CR", r16(REG_CR), 16);
    powerSwitch(false);
    pci->setBusLeadEnable(false);
    freeRings();
}

// Escaneo pasivo; deja el chip apagado al terminar.
void RTL8723DE::runScan()
{
    const char *failed = bringUp();
    if (!failed) {
        passiveScan();
        publishScan();
    }
    setProperty("Stage", failed ? failed : "done");
    shutDown();
}

// Comandos desde espacio de usuario (rtlctl), ejecutados dentro del work loop:
//   {"Command" = "scan"}
//   {"Command" = "connect", "SSID" = <texto>, "PMK" = <32 bytes>}
//   {"Command" = "disconnect"}
IOReturn RTL8723DE::setProperties(OSObject *properties)
{
    OSDictionary *dict = OSDynamicCast(OSDictionary, properties);
    if (!dict || !gate || !base)
        return kIOReturnBadArgument;
    return gate->runAction(OSMemberFunctionCast(IOCommandGate::Action, this,
                                                &RTL8723DE::gatedCommand), dict);
}

IOReturn RTL8723DE::gatedCommand(void *arg, void *, void *, void *)
{
    OSDictionary *dict = (OSDictionary *)arg;
    OSString *cmd = OSDynamicCast(OSString, dict->getObject("Command"));
    if (!cmd)
        return kIOReturnBadArgument;

    if (cmd->isEqualTo("scan")) {
        if (staConnected)
            return kIOReturnBusy;
        setProperty("Stage", "running");
        runScan();
        return kIOReturnSuccess;
    }
    if (cmd->isEqualTo("connect")) {
        OSString *ssid = OSDynamicCast(OSString, dict->getObject("SSID"));
        OSData *key = OSDynamicCast(OSData, dict->getObject("PMK"));
        if (!ssid || !key || key->getLength() != 32 || ssid->getLength() > 32)
            return kIOReturnBadArgument;
        if (staConnected)
            disconnect(true);
        setProperty("Stage", "connecting");
        runConnect(ssid, key);
        return kIOReturnSuccess;
    }
    if (cmd->isEqualTo("rate")) {
        // Tasa de datos fija (DESC_RATE*): 0x00-0x03 CCK, 0x04-0x0b OFDM.
        OSNumber *rate = OSDynamicCast(OSNumber, dict->getObject("Rate"));
        if (!rate || rate->unsigned32BitValue() > 0x0b)
            return kIOReturnBadArgument;
        dataRate = (UInt8)rate->unsigned32BitValue();
        setProperty("DataRate", dataRate, 8);
        return kIOReturnSuccess;
    }
    if (cmd->isEqualTo("disconnect")) {
        havePmk = false;
        memset(pmk, 0, sizeof(pmk));
        if (staConnected)
            disconnect(true);
        setProperty("Stage", "idle");
        return kIOReturnSuccess;
    }
    return kIOReturnUnsupported;
}

// Apagado o reinicio: detener el DMA antes de que la RAM cambie de dueño. Un
// reinicio en caliente puede no cortarle la corriente al chip.
void RTL8723DE::systemWillShutdown(IOOptionBits specifier)
{
    if (gate) {
        OSDictionary *d = OSDictionary::withCapacity(1);
        OSString *s = OSString::withCString("disconnect");
        if (d && s) {
            d->setObject("Command", s);
            gate->runAction(OSMemberFunctionCast(IOCommandGate::Action, this,
                                                 &RTL8723DE::gatedCommand), d);
        }
        if (s) s->release();
        if (d) d->release();
    }
    if (rxTimer)
        rxTimer->cancelTimeout();
    if (base && r8(REG_CR) != 0xea)
        powerSwitch(false);
    if (pci)
        pci->setBusLeadEnable(false);
    super::systemWillShutdown(specifier);
}

void RTL8723DE::stop(IOService *provider)
{
    // Desconectar dentro del work loop para no competir con la salida ni el temporizador.
    if (gate && staConnected) {
        OSDictionary *d = OSDictionary::withCapacity(1);
        OSString *s = OSString::withCString("disconnect");
        if (d && s) {
            d->setObject("Command", s);
            gate->runAction(OSMemberFunctionCast(IOCommandGate::Action, this,
                                                 &RTL8723DE::gatedCommand), d);
        }
        if (s) s->release();
        if (d) d->release();
    }
    if (rxTimer) {
        rxTimer->cancelTimeout();
        if (workLoop)
            workLoop->removeEventSource(rxTimer);
        rxTimer->release();
        rxTimer = nullptr;
    }
    if (txSource) {
        if (workLoop)
            workLoop->removeEventSource(txSource);
        txSource->release();
        txSource = nullptr;
    }
    flushTxQueue();
    if (txqLock) {
        IOLockFree(txqLock);
        txqLock = nullptr;
    }
    if (gate) {
        if (workLoop)
            workLoop->removeEventSource(gate);
        gate->release();
        gate = nullptr;
    }
    if (netif) {
        detachInterface(netif);
        netif->release();
        netif = nullptr;
    }
    if (bar) { bar->release(); bar = nullptr; }
    if (pci) { pci->close(this); pci->release(); pci = nullptr; }
    super::stop(provider);
    if (workLoop) {
        workLoop->release();
        workLoop = nullptr;
    }
}
