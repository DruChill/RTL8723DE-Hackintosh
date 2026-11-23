// Definiciones de rtw88 que no están en rtw88_defs.h (vienen de main.h, de
// archivos .c o de structs) y las propias de este driver.
#pragma once
#include <libkern/OSTypes.h>
#include "rtw88_defs.h"

// --- main.h ---
#define TX_PAGE_SIZE_SHIFT   7
#define TX_PAGE_SIZE         (1 << TX_PAGE_SIZE_SHIFT)
#define RTW_PWR_POLLING_CNT  20000

#define RTW_PWR_CMD_READ     0x00
#define RTW_PWR_CMD_WRITE    0x01
#define RTW_PWR_CMD_POLLING  0x02
#define RTW_PWR_CMD_DELAY    0x03
#define RTW_PWR_CMD_END      0x04

#define RTW_PWR_ADDR_MAC     0x00
#define RTW_PWR_ADDR_USB     0x01
#define RTW_PWR_ADDR_PCIE    0x02
#define RTW_PWR_ADDR_SDIO    0x03

#define RTW_PWR_INTF_SDIO_MSK BIT(0)
#define RTW_PWR_INTF_USB_MSK  BIT(1)
#define RTW_PWR_INTF_PCI_MSK  BIT(2)
#define RTW_PWR_INTF_ALL_MSK  (BIT(0) | BIT(1) | BIT(2) | BIT(3))

#define RTW_PWR_CUT_TEST_MSK BIT(0)
#define RTW_PWR_CUT_A_MSK    BIT(1)
#define RTW_PWR_CUT_B_MSK    BIT(2)
#define RTW_PWR_CUT_C_MSK    BIT(3)
#define RTW_PWR_CUT_D_MSK    BIT(4)
#define RTW_PWR_CUT_E_MSK    BIT(5)
#define RTW_PWR_CUT_F_MSK    BIT(6)
#define RTW_PWR_CUT_G_MSK    BIT(7)
#define RTW_PWR_CUT_ALL_MSK  0xFF

enum rtw_pwr_seq_cmd_delay_unit {
    RTW_PWR_DELAY_US,
    RTW_PWR_DELAY_MS,
};

struct rtw_pwr_seq_cmd {
    UInt16 offset;
    UInt8 cut_mask;
    UInt8 intf_mask;
    UInt8 base:4;
    UInt8 cmd:4;
    UInt8 mask;
    UInt8 value;
};

enum rtw_dma_mapping {
    RTW_DMA_MAPPING_EXTRA  = 0,
    RTW_DMA_MAPPING_LOW    = 1,
    RTW_DMA_MAPPING_NORMAL = 2,
    RTW_DMA_MAPPING_HIGH   = 3,
};

// struct rtw_phy_cond (main.h), empaquetado en la palabra "addr" de cada par.
#define PHY_COND_POS(a)      (((a) >> 31) & 0x1)
#define PHY_COND_NEG(a)      (((a) >> 30) & 0x1)
#define PHY_COND_BRANCH(a)   (((a) >> 28) & 0x3)
#define PHY_COND_CUT(a)      (((a) >> 24) & 0xf)
#define PHY_COND_PKG(a)      (((a) >> 12) & 0xf)
#define PHY_COND_INTF(a)     (((a) >> 8) & 0xf)
#define PHY_COND_RFE(a)      ((a) & 0xff)
#define BRANCH_IF            0
#define BRANCH_ELIF          1
#define BRANCH_ELSE          2
#define BRANCH_ENDIF         3
#define INTF_PCIE            BIT(0)

// main.h: enum rtw_rate_id, rtw_net_type, rtw_cam_type; tx.h: TX_DESC_QSEL_*
#define RTW_RATEID_B_20M     8
#define RTW_NET_MGD_LINKED   2
#define RTW_CAM_AES          4
#define TX_DESC_QSEL_TID0    0
#define TX_DESC_QSEL_MGMT    18
#define RTW_RATEID_BG        6
#define DESC_RATE1M          0x00
#define DESC_RATE6M          0x04
#define DESC_RATE54M         0x0b
#define TX_PKT_DESC_SZ       40
#define TX_SEC_TYPE_CCMP     0x03

// Puerto 0 (rtw_vif_port[0] de mac80211.c)
#define REG_PORT0_MACID      0x0610
#define REG_PORT0_BSSID      0x0618
#define PORT0_NET_TYPE_MASK  0x30000   // en REG_CR
#define REG_PORT0_AID        0x06a8

// coex.h
#define COEX_GNT_SET_HW_PTA  0x0
#define COEX_GNT_SET_SW_LOW  0x1
#define COEX_GNT_SET_SW_HIGH 0x3

// --- rtw8723x.c ---
#define BIT_CFENDFORM        BIT(9)
#define BIT_WMAC_TCR_ERR0    BIT(12)
#define BIT_WMAC_TCR_ERR1    BIT(13)
#define BIT_TCR_CFG          (BIT_CFENDFORM | BIT_WMAC_TCR_ERR0 | BIT_WMAC_TCR_ERR1)
#define WLAN_RX_FILTER0      0xFFFF
#define WLAN_RX_FILTER1      0x400
#define WLAN_RX_FILTER2      0xFFFF
#define WLAN_RCR_CFG         0x700060CE

// --- rtw8723d.c ---
#define WLAN_SLOT_TIME       0x09
#define WLAN_RL_VAL          0x3030
#define WLAN_BAR_VAL         0x0201ffff
#define BIT_MASK_TBTT_HOLD   0x00000fff
#define BIT_SHIFT_TBTT_HOLD  8
#define BIT_MASK_TBTT_SETUP  0x000000ff
#define BIT_SHIFT_TBTT_SETUP 0
#define BIT_MASK_TBTT_MASK   ((BIT_MASK_TBTT_HOLD << BIT_SHIFT_TBTT_HOLD) | \
                              (BIT_MASK_TBTT_SETUP << BIT_SHIFT_TBTT_SETUP))
#define TBTT_TIME(s, h)      ((((s) & BIT_MASK_TBTT_SETUP) << BIT_SHIFT_TBTT_SETUP) | \
                              (((h) & BIT_MASK_TBTT_HOLD) << BIT_SHIFT_TBTT_HOLD))
#define WLAN_TBTT_TIME_STOP_BCN TBTT_TIME(0x04, 0x64)
#define WLAN_PIFS_VAL        0
#define WLAN_AGG_BRK_TIME    0x16
#define WLAN_NAV_PROT_LEN    0x0040
#define WLAN_SPEC_SIFS       0x100a
#define WLAN_RX_PKT_LIMIT    0x17
#define WLAN_MAX_AGG_NR      0x0A
#define WLAN_AMPDU_MAX_TIME  0x1C
#define WLAN_ANT_SEL         0x82
#define WLAN_LTR_IDLE_LAT    0x90039003
#define WLAN_LTR_ACT_LAT     0x883c883c
#define WLAN_LTR_CTRL1       0xCB004010
#define WLAN_LTR_CTRL2       0x01233425

// --- Parámetros del chip (struct rtw_chip_info rtw8723d_hw_spec) ---
#define CHIP_TXFF_SIZE       32768
#define CHIP_RXFF_SIZE       16384
#define CHIP_RSVD_DRV_PG_NUM 8
#define CHIP_TX_BUF_DESC_SZ  16
#define CHIP_RX_BUF_DESC_SZ  8
#define CHIP_RX_PKT_DESC_SZ  24
#define RF_SIPI_ADDR_A       0x840
#define RF_SIPI_ADDR_B       0x844

// --- Efuse del 8723D (struct rtw8723x_efuse) ---
#define EFUSE_PHY_SIZE       512
#define EFUSE_LOG_SIZE       512
#define EFUSE_PROTECT_SIZE   (96 + 1)
#define EFUSE_LOG_AFE        0x04
#define EFUSE_LOG_TXPWR_CCK  0x10   // txpwr_idx_table[0].pwr_idx_2g.cck_base[6]
#define EFUSE_LOG_TXPWR_BW40 0x16   // .bw40_base[5]
#define EFUSE_LOG_TXPWR_HT1S_DIFF 0x1B  // .ht_1s_diff: ofdm (bits 3:0), bw20 (7:4)
#define EFUSE_LOG_XTAL_K     0xB9
#define EFUSE_LOG_RF_BOARD   0xC1
#define EFUSE_LOG_BT_SETTING 0xC3
#define EFUSE_LOG_MAC_ADDR   0xD0   // rtw8723xe_efuse.mac_addr (PCIe)
#define EFUSE_LOG_VID        0xD6
#define EFUSE_LOG_DID        0xD8

// --- Firmware de chips con CPU 8051 (struct rtw_fw_hdr_legacy) ---
#define FW_HDR_LEGACY_SIZE   32
#define FW_SIGNATURE_8723D   0x23D1
