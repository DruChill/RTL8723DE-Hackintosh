// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
// Constantes extraídas automáticamente de rtw88 (Copyright(c) 2018-2019 Realtek Corporation).
// Solo líneas #define, cada una protegida con #ifndef. Regenerar con tools/gen_defs.sh.
#pragma once
#ifndef BIT
#define BIT(n) (1U << (n))
#endif
#ifndef GENMASK
#define GENMASK(h, l) (((~0U) << (l)) & (~0U >> (31 - (h))))
#endif

// ---- reg.h ----
#ifndef REG_SYS_FUNC_EN
#define REG_SYS_FUNC_EN		0x0002
#endif
#ifndef BIT_FEN_EN_25_1
#define BIT_FEN_EN_25_1		BIT(13)
#endif
#ifndef BIT_FEN_ELDR
#define BIT_FEN_ELDR		BIT(12)
#endif
#ifndef BIT_FEN_PPLL
#define BIT_FEN_PPLL		BIT(7)
#endif
#ifndef BIT_FEN_PCIEA
#define BIT_FEN_PCIEA		BIT(6)
#endif
#ifndef BIT_FEN_DIO_PCIE
#define BIT_FEN_DIO_PCIE	BIT(5)
#endif
#ifndef BIT_FEN_PCIED
#define BIT_FEN_PCIED		BIT(8)
#endif
#ifndef BIT_FEN_CPUEN
#define BIT_FEN_CPUEN		BIT(2)
#endif
#ifndef BIT_FEN_USBA
#define BIT_FEN_USBA		BIT(2)
#endif
#ifndef BIT_FEN_BB_GLB_RST
#define BIT_FEN_BB_GLB_RST	BIT(1)
#endif
#ifndef BIT_FEN_BB_RSTB
#define BIT_FEN_BB_RSTB		BIT(0)
#endif
#ifndef BIT_R_DIS_PRST
#define BIT_R_DIS_PRST		BIT(6)
#endif
#ifndef BIT_WLOCK_1C_B6
#define BIT_WLOCK_1C_B6		BIT(5)
#endif
#ifndef REG_SYS_PW_CTRL
#define REG_SYS_PW_CTRL		0x0004
#endif
#ifndef BIT_PFM_WOWL
#define BIT_PFM_WOWL		BIT(3)
#endif
#ifndef BIT_APFM_OFFMAC
#define BIT_APFM_OFFMAC		BIT(9)
#endif
#ifndef REG_APS_FSMCO
#define REG_APS_FSMCO		0x0004
#endif
#ifndef BIT_EN_PDN
#define BIT_EN_PDN		BIT(4)
#endif
#ifndef APS_FSMCO_MAC_ENABLE
#define APS_FSMCO_MAC_ENABLE	BIT(8)
#endif
#ifndef APS_FSMCO_MAC_OFF
#define APS_FSMCO_MAC_OFF	BIT(9)
#endif
#ifndef APS_FSMCO_HW_POWERDOWN
#define APS_FSMCO_HW_POWERDOWN	BIT(15)
#endif
#ifndef REG_SYS_CLK_CTRL
#define REG_SYS_CLK_CTRL	0x0008
#endif
#ifndef BIT_CPU_CLK_EN
#define BIT_CPU_CLK_EN		BIT(14)
#endif
#ifndef REG_SYS_CLKR
#define REG_SYS_CLKR		0x0008
#endif
#ifndef BIT_ANA8M
#define BIT_ANA8M		BIT(1)
#endif
#ifndef BIT_WAKEPAD_EN
#define BIT_WAKEPAD_EN		BIT(3)
#endif
#ifndef BIT_LOADER_CLK_EN
#define BIT_LOADER_CLK_EN	BIT(5)
#endif
#ifndef REG_RSV_CTRL
#define REG_RSV_CTRL		0x001C
#endif
#ifndef DISABLE_PI
#define DISABLE_PI		0x3
#endif
#ifndef ENABLE_PI
#define ENABLE_PI		0x2
#endif
#ifndef BITS_RFC_DIRECT
#define BITS_RFC_DIRECT		(BIT(31) | BIT(30))
#endif
#ifndef BIT_WLMCU_IOIF
#define BIT_WLMCU_IOIF		BIT(0)
#endif
#ifndef REG_RF_CTRL
#define REG_RF_CTRL		0x001F
#endif
#ifndef BIT_RF_SDM_RSTB
#define BIT_RF_SDM_RSTB		BIT(2)
#endif
#ifndef BIT_RF_RSTB
#define BIT_RF_RSTB		BIT(1)
#endif
#ifndef BIT_RF_EN
#define BIT_RF_EN		BIT(0)
#endif
#ifndef REG_RF_CTRL1
#define REG_RF_CTRL1		0x0020
#endif
#ifndef REG_RF_CTRL2
#define REG_RF_CTRL2		0x0021
#endif
#ifndef REG_AFE_CTRL1
#define REG_AFE_CTRL1		0x0024
#endif
#ifndef BIT_MAC_CLK_SEL
#define BIT_MAC_CLK_SEL		(BIT(20) | BIT(21))
#endif
#ifndef REG_EFUSE_CTRL
#define REG_EFUSE_CTRL		0x0030
#endif
#ifndef BIT_EF_FLAG
#define BIT_EF_FLAG		BIT(31)
#endif
#ifndef BIT_SHIFT_EF_ADDR
#define BIT_SHIFT_EF_ADDR	8
#endif
#ifndef BIT_MASK_EF_ADDR
#define BIT_MASK_EF_ADDR	0x3ff
#endif
#ifndef BIT_MASK_EF_DATA
#define BIT_MASK_EF_DATA	0xff
#endif
#ifndef BITS_EF_ADDR
#define BITS_EF_ADDR		(BIT_MASK_EF_ADDR << BIT_SHIFT_EF_ADDR)
#endif
#ifndef BITS_PLL
#define BITS_PLL		0xf0
#endif
#ifndef REG_AFE_XTAL_CTRL
#define REG_AFE_XTAL_CTRL	0x24
#endif
#ifndef REG_AFE_PLL_CTRL
#define REG_AFE_PLL_CTRL	0x28
#endif
#ifndef REG_AFE_CTRL3
#define REG_AFE_CTRL3		0x2c
#endif
#ifndef BIT_MASK_XTAL
#define BIT_MASK_XTAL		0x00FFF000
#endif
#ifndef BIT_XTAL_GMP_BIT4
#define BIT_XTAL_GMP_BIT4	BIT(28)
#endif
#ifndef REG_LDO_EFUSE_CTRL
#define REG_LDO_EFUSE_CTRL	0x0034
#endif
#ifndef BIT_MASK_EFUSE_BANK_SEL
#define BIT_MASK_EFUSE_BANK_SEL	(BIT(8) | BIT(9))
#endif
#ifndef BIT_LDO25_VOLTAGE_V25
#define BIT_LDO25_VOLTAGE_V25	0x03
#endif
#ifndef BIT_MASK_LDO25_VOLTAGE
#define BIT_MASK_LDO25_VOLTAGE	GENMASK(6, 4)
#endif
#ifndef BIT_SHIFT_LDO25_VOLTAGE
#define BIT_SHIFT_LDO25_VOLTAGE	4
#endif
#ifndef BIT_LDO25_EN
#define BIT_LDO25_EN		BIT(7)
#endif
#ifndef REG_PWR_DATA
#define REG_PWR_DATA		0x0038
#endif
#ifndef BIT_EEPRPAD_RFE_CTRL_EN
#define BIT_EEPRPAD_RFE_CTRL_EN	BIT(11)
#endif
#ifndef REG_ACLK_MON
#define REG_ACLK_MON		0x3e
#endif
#ifndef REG_GPIO_MUXCFG
#define REG_GPIO_MUXCFG		0x0040
#endif
#ifndef BIT_FSPI_EN
#define BIT_FSPI_EN		BIT(19)
#endif
#ifndef BIT_EN_SIC
#define BIT_EN_SIC		BIT(12)
#endif
#ifndef BIT_PO_BT_PTA_PINS
#define BIT_PO_BT_PTA_PINS	BIT(9)
#endif
#ifndef BIT_BT_PTA_EN
#define BIT_BT_PTA_EN		BIT(5)
#endif
#ifndef BIT_WLRFE_4_5_EN
#define BIT_WLRFE_4_5_EN	BIT(2)
#endif
#ifndef REG_GPIO_PIN_CTRL
#define REG_GPIO_PIN_CTRL	0x0044
#endif
#ifndef REG_LED_CFG
#define REG_LED_CFG		0x004C
#endif
#ifndef BIT_LNAON_SEL_EN
#define BIT_LNAON_SEL_EN	BIT(26)
#endif
#ifndef BIT_PAPE_SEL_EN
#define BIT_PAPE_SEL_EN		BIT(25)
#endif
#ifndef BIT_DPDT_WL_SEL
#define BIT_DPDT_WL_SEL		BIT(24)
#endif
#ifndef BIT_DPDT_SEL_EN
#define BIT_DPDT_SEL_EN		BIT(23)
#endif
#ifndef BIT_GPIO13_14_WL_CTRL_EN
#define BIT_GPIO13_14_WL_CTRL_EN	BIT(22)
#endif
#ifndef BIT_LED2_SV
#define BIT_LED2_SV		BIT(19)
#endif
#ifndef BIT_LED2_CM
#define BIT_LED2_CM		GENMASK(18, 16)
#endif
#ifndef BIT_LED1_SV
#define BIT_LED1_SV		BIT(11)
#endif
#ifndef BIT_LED1_CM
#define BIT_LED1_CM		GENMASK(10, 8)
#endif
#ifndef BIT_LED0_SV
#define BIT_LED0_SV		BIT(3)
#endif
#ifndef BIT_LED0_CM
#define BIT_LED0_CM		GENMASK(2, 0)
#endif
#ifndef BIT_LED_MODE_SW_CTRL
#define BIT_LED_MODE_SW_CTRL	0
#endif
#ifndef BIT_LED_MODE_RX
#define BIT_LED_MODE_RX		6
#endif
#ifndef BIT_LED_MODE_TX
#define BIT_LED_MODE_TX		4
#endif
#ifndef BIT_LED_MODE_TRX
#define BIT_LED_MODE_TRX	2
#endif
#ifndef REG_LEDCFG2
#define REG_LEDCFG2		0x004E
#endif
#ifndef REG_GPIO_PIN_CTRL_2
#define REG_GPIO_PIN_CTRL_2	0x0060
#endif
#ifndef REG_PAD_CTRL1
#define REG_PAD_CTRL1		0x0064
#endif
#ifndef BIT_BT_BTG_SEL
#define BIT_BT_BTG_SEL		BIT(31)
#endif
#ifndef BIT_PAPE_WLBT_SEL
#define BIT_PAPE_WLBT_SEL	BIT(29)
#endif
#ifndef BIT_LNAON_WLBT_SEL
#define BIT_LNAON_WLBT_SEL	BIT(28)
#endif
#ifndef BIT_BTGP_JTAG_EN
#define BIT_BTGP_JTAG_EN	BIT(24)
#endif
#ifndef BIT_BTGP_SPI_EN
#define BIT_BTGP_SPI_EN		BIT(20)
#endif
#ifndef BIT_LED1DIS
#define BIT_LED1DIS		BIT(15)
#endif
#ifndef BIT_SW_DPDT_SEL_DATA
#define BIT_SW_DPDT_SEL_DATA	BIT(0)
#endif
#ifndef REG_BT_ANT_SEL
#define REG_BT_ANT_SEL		0x0067
#endif
#ifndef BIT_BT_SEL_BY_WIFI
#define BIT_BT_SEL_BY_WIFI	BIT(5)
#endif
#ifndef REG_BT_EFUSE_CTRL
#define REG_BT_EFUSE_CTRL	0x006b
#endif
#ifndef BIT_BT_PWR_CUT
#define BIT_BT_PWR_CUT		BIT(6)
#endif
#ifndef BIT_BT_OUT_ISO
#define BIT_BT_OUT_ISO		BIT(7)
#endif
#ifndef REG_WL_BT_PWR_CTRL
#define REG_WL_BT_PWR_CTRL	0x0068
#endif
#ifndef BIT_BT_FUNC_EN
#define BIT_BT_FUNC_EN		BIT(18)
#endif
#ifndef BIT_BT_DIG_CLK_EN
#define BIT_BT_DIG_CLK_EN	BIT(8)
#endif
#ifndef REG_SYS_SDIO_CTRL
#define REG_SYS_SDIO_CTRL	0x0070
#endif
#ifndef BIT_DBG_GNT_WL_BT
#define BIT_DBG_GNT_WL_BT	BIT(27)
#endif
#ifndef BIT_LTE_MUX_CTRL_PATH
#define BIT_LTE_MUX_CTRL_PATH	BIT(26)
#endif
#ifndef REG_HCI_OPT_CTRL
#define REG_HCI_OPT_CTRL	0x0074
#endif
#ifndef BIT_USB_SUS_DIS
#define BIT_USB_SUS_DIS		BIT(8)
#endif
#ifndef BIT_SDIO_PAD_E5
#define BIT_SDIO_PAD_E5		BIT(18)
#endif
#ifndef REG_RF_B_CTRL
#define REG_RF_B_CTRL		0x76
#endif
#ifndef REG_RF_CTRL3
#define REG_RF_CTRL3		0x0076
#endif
#ifndef REG_AFE_CTRL_4
#define REG_AFE_CTRL_4		0x0078
#endif
#ifndef BIT_CK320M_AFE_EN
#define BIT_CK320M_AFE_EN	BIT(4)
#endif
#ifndef BIT_EN_SYN
#define BIT_EN_SYN		BIT(15)
#endif
#ifndef REG_LDO_SWR_CTRL
#define REG_LDO_SWR_CTRL	0x007C
#endif
#ifndef LDO_SEL
#define LDO_SEL			0xC3
#endif
#ifndef SPS_SEL
#define SPS_SEL			0x83
#endif
#ifndef BIT_XTA1
#define BIT_XTA1		BIT(29)
#endif
#ifndef BIT_XTA0
#define BIT_XTA0		BIT(28)
#endif
#ifndef REG_MCUFW_CTRL
#define REG_MCUFW_CTRL		0x0080
#endif
#ifndef BIT_ANA_PORT_EN
#define BIT_ANA_PORT_EN		BIT(22)
#endif
#ifndef BIT_MAC_PORT_EN
#define BIT_MAC_PORT_EN		BIT(21)
#endif
#ifndef BIT_BOOT_FSPI_EN
#define BIT_BOOT_FSPI_EN	BIT(20)
#endif
#ifndef BIT_ROM_DLEN
#define BIT_ROM_DLEN		BIT(19)
#endif
#ifndef BIT_ROM_PGE
#define BIT_ROM_PGE		GENMASK(18, 16)	/* legacy only */
#endif
#ifndef BIT_SHIFT_ROM_PGE
#define BIT_SHIFT_ROM_PGE	16
#endif
#ifndef BIT_FW_INIT_RDY
#define BIT_FW_INIT_RDY		BIT(15)
#endif
#ifndef BIT_FW_DW_RDY
#define BIT_FW_DW_RDY		BIT(14)
#endif
#ifndef BIT_CPU_CLK_SEL
#define BIT_CPU_CLK_SEL		(BIT(12) | BIT(13))
#endif
#ifndef BIT_RPWM_TOGGLE
#define BIT_RPWM_TOGGLE		BIT(7)
#endif
#ifndef BIT_RAM_DL_SEL
#define BIT_RAM_DL_SEL		BIT(7)	/* legacy only */
#endif
#ifndef BIT_DMEM_CHKSUM_OK
#define BIT_DMEM_CHKSUM_OK	BIT(6)
#endif
#ifndef BIT_WINTINI_RDY
#define BIT_WINTINI_RDY		BIT(6)	/* legacy only */
#endif
#ifndef BIT_DMEM_DW_OK
#define BIT_DMEM_DW_OK		BIT(5)
#endif
#ifndef BIT_IMEM_CHKSUM_OK
#define BIT_IMEM_CHKSUM_OK	BIT(4)
#endif
#ifndef BIT_IMEM_DW_OK
#define BIT_IMEM_DW_OK		BIT(3)
#endif
#ifndef BIT_IMEM_BOOT_LOAD_CHECKSUM_OK
#define BIT_IMEM_BOOT_LOAD_CHECKSUM_OK BIT(2)
#endif
#ifndef BIT_FWDL_CHK_RPT
#define BIT_FWDL_CHK_RPT	BIT(2)	/* legacy only */
#endif
#ifndef BIT_MCUFWDL_RDY
#define BIT_MCUFWDL_RDY		BIT(1)	/* legacy only */
#endif
#ifndef BIT_MCUFWDL_EN
#define BIT_MCUFWDL_EN		BIT(0)
#endif
#ifndef BIT_CHECK_SUM_OK
#define BIT_CHECK_SUM_OK	(BIT(4) | BIT(6))
#endif
#ifndef FW_READY
#define FW_READY		(BIT_FW_INIT_RDY | BIT_FW_DW_RDY |             \
				 BIT_IMEM_DW_OK | BIT_DMEM_DW_OK |             \
				 BIT_CHECK_SUM_OK)
#endif
#ifndef FW_READY_LEGACY
#define FW_READY_LEGACY		(BIT_MCUFWDL_RDY | BIT_FWDL_CHK_RPT |	       \
				 BIT_WINTINI_RDY | BIT_RAM_DL_SEL)
#endif
#ifndef FW_READY_MASK
#define FW_READY_MASK		(0xffff & ~BIT_CPU_CLK_SEL)
#endif
#ifndef REG_MCU_TST_CFG
#define REG_MCU_TST_CFG		0x84
#endif
#ifndef VAL_FW_TRIGGER
#define VAL_FW_TRIGGER		0x1
#endif
#ifndef REG_PMC_DBG_CTRL1
#define REG_PMC_DBG_CTRL1	0xa8
#endif
#ifndef BITS_PMC_BT_IQK_STS
#define BITS_PMC_BT_IQK_STS	GENMASK(22, 21)
#endif
#ifndef REG_HIMR0
#define REG_HIMR0		0xb0
#endif
#ifndef REG_HISR0
#define REG_HISR0		0xb4
#endif
#ifndef REG_HIMR1
#define REG_HIMR1		0xb8
#endif
#ifndef REG_HISR1
#define REG_HISR1		0xbc
#endif
#ifndef REG_PAD_CTRL2
#define REG_PAD_CTRL2		0x00C4
#endif
#ifndef BIT_RSM_EN_V1
#define BIT_RSM_EN_V1		BIT(16)
#endif
#ifndef BIT_NO_PDN_CHIPOFF_V1
#define BIT_NO_PDN_CHIPOFF_V1	BIT(17)
#endif
#ifndef BIT_MASK_USB23_SW_MODE_V1
#define BIT_MASK_USB23_SW_MODE_V1	GENMASK(19, 18)
#endif
#ifndef BIT_USB3_USB2_TRANSITION
#define BIT_USB3_USB2_TRANSITION	BIT(20)
#endif
#ifndef BIT_USB_MODE_U2
#define BIT_USB_MODE_U2		1
#endif
#ifndef BIT_USB_MODE_U3
#define BIT_USB_MODE_U3		2
#endif
#ifndef REG_PMC_DBG_CTRL2
#define REG_PMC_DBG_CTRL2	0x00CC
#endif
#ifndef REG_EFUSE_ACCESS
#define REG_EFUSE_ACCESS	0x00CF
#endif
#ifndef EFUSE_ACCESS_ON
#define EFUSE_ACCESS_ON		0x69
#endif
#ifndef EFUSE_ACCESS_OFF
#define EFUSE_ACCESS_OFF	0x00
#endif
#ifndef REG_WLRF1
#define REG_WLRF1		0x00EC
#endif
#ifndef REG_WIFI_BT_INFO
#define REG_WIFI_BT_INFO	0x00AA
#endif
#ifndef BIT_BT_INT_EN
#define BIT_BT_INT_EN		BIT(15)
#endif
#ifndef REG_SYS_CFG1
#define REG_SYS_CFG1		0x00F0
#endif
#ifndef BIT_RTL_ID
#define	BIT_RTL_ID		BIT(23)
#endif
#ifndef BIT_LDO
#define BIT_LDO			BIT(24)
#endif
#ifndef BIT_RF_TYPE_ID
#define BIT_RF_TYPE_ID		BIT(27)
#endif
#ifndef BIT_SHIFT_VENDOR_ID
#define BIT_SHIFT_VENDOR_ID	16
#endif
#ifndef BIT_MASK_VENDOR_ID
#define BIT_MASK_VENDOR_ID	0xf
#endif
#ifndef BIT_VENDOR_ID
#define BIT_VENDOR_ID(x) (((x) & BIT_MASK_VENDOR_ID) << BIT_SHIFT_VENDOR_ID)
#endif
#ifndef BITS_VENDOR_ID
#define BITS_VENDOR_ID		(BIT_MASK_VENDOR_ID << BIT_SHIFT_VENDOR_ID)
#endif
#ifndef BIT_CLEAR_VENDOR_ID
#define BIT_CLEAR_VENDOR_ID(x)	((x) & (~BITS_VENDOR_ID))
#endif
#ifndef BIT_GET_VENDOR_ID
#define BIT_GET_VENDOR_ID(x) (((x) >> BIT_SHIFT_VENDOR_ID) & BIT_MASK_VENDOR_ID)
#endif
#ifndef BIT_SHIFT_CHIP_VER
#define BIT_SHIFT_CHIP_VER	12
#endif
#ifndef BIT_MASK_CHIP_VER
#define BIT_MASK_CHIP_VER	0xf
#endif
#ifndef BIT_CHIP_VER
#define BIT_CHIP_VER(x)	 (((x) & BIT_MASK_CHIP_VER) << BIT_SHIFT_CHIP_VER)
#endif
#ifndef BITS_CHIP_VER
#define BITS_CHIP_VER		(BIT_MASK_CHIP_VER << BIT_SHIFT_CHIP_VER)
#endif
#ifndef BIT_CLEAR_CHIP_VER
#define BIT_CLEAR_CHIP_VER(x)	((x) & (~BITS_CHIP_VER))
#endif
#ifndef BIT_GET_CHIP_VER
#define BIT_GET_CHIP_VER(x) (((x) >> BIT_SHIFT_CHIP_VER) & BIT_MASK_CHIP_VER)
#endif
#ifndef REG_SYS_STATUS1
#define REG_SYS_STATUS1		0x00F4
#endif
#ifndef REG_SYS_STATUS2
#define REG_SYS_STATUS2		0x00F8
#endif
#ifndef REG_SYS_CFG2
#define REG_SYS_CFG2		0x00FC
#endif
#ifndef REG_WLRF1
#define REG_WLRF1		0x00EC
#endif
#ifndef BIT_WLRF1_BBRF_EN
#define BIT_WLRF1_BBRF_EN	(BIT(24) | BIT(25) | BIT(26))
#endif
#ifndef REG_CR
#define REG_CR			0x0100
#endif
#ifndef BIT_32K_CAL_TMR_EN
#define BIT_32K_CAL_TMR_EN	BIT(10)
#endif
#ifndef BIT_MAC_SEC_EN
#define BIT_MAC_SEC_EN		BIT(9)
#endif
#ifndef BIT_ENSWBCN
#define BIT_ENSWBCN		BIT(8)
#endif
#ifndef BIT_MACRXEN
#define BIT_MACRXEN		BIT(7)
#endif
#ifndef BIT_MACTXEN
#define BIT_MACTXEN		BIT(6)
#endif
#ifndef BIT_SCHEDULE_EN
#define BIT_SCHEDULE_EN		BIT(5)
#endif
#ifndef BIT_PROTOCOL_EN
#define BIT_PROTOCOL_EN		BIT(4)
#endif
#ifndef BIT_RXDMA_EN
#define BIT_RXDMA_EN		BIT(3)
#endif
#ifndef BIT_TXDMA_EN
#define BIT_TXDMA_EN		BIT(2)
#endif
#ifndef BIT_HCI_RXDMA_EN
#define BIT_HCI_RXDMA_EN	BIT(1)
#endif
#ifndef BIT_HCI_TXDMA_EN
#define BIT_HCI_TXDMA_EN	BIT(0)
#endif
#ifndef MAC_TRX_ENABLE
#define MAC_TRX_ENABLE	(BIT_HCI_TXDMA_EN | BIT_HCI_RXDMA_EN | BIT_TXDMA_EN | \
			BIT_RXDMA_EN | BIT_PROTOCOL_EN | BIT_SCHEDULE_EN | \
			BIT_MACTXEN | BIT_MACRXEN)
#endif
#ifndef REG_PBP
#define REG_PBP			0x104
#endif
#ifndef PBP_RX_MASK
#define PBP_RX_MASK		0x0f
#endif
#ifndef PBP_TX_MASK
#define PBP_TX_MASK		0xf0
#endif
#ifndef PBP_64
#define PBP_64			0x0
#endif
#ifndef PBP_128
#define PBP_128			0x1
#endif
#ifndef PBP_256
#define PBP_256			0x2
#endif
#ifndef PBP_512
#define PBP_512			0x3
#endif
#ifndef PBP_1024
#define PBP_1024		0x4
#endif
#ifndef BIT_SHIFT_TXDMA_VOQ_MAP
#define BIT_SHIFT_TXDMA_VOQ_MAP	4
#endif
#ifndef BIT_MASK_TXDMA_VOQ_MAP
#define BIT_MASK_TXDMA_VOQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_VOQ_MAP
#define BIT_TXDMA_VOQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_VOQ_MAP) << BIT_SHIFT_TXDMA_VOQ_MAP)
#endif
#ifndef BIT_SHIFT_TXDMA_VIQ_MAP
#define BIT_SHIFT_TXDMA_VIQ_MAP	6
#endif
#ifndef BIT_MASK_TXDMA_VIQ_MAP
#define BIT_MASK_TXDMA_VIQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_VIQ_MAP
#define BIT_TXDMA_VIQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_VIQ_MAP) << BIT_SHIFT_TXDMA_VIQ_MAP)
#endif
#ifndef REG_TXDMA_PQ_MAP
#define REG_TXDMA_PQ_MAP	0x010C
#endif
#ifndef BIT_RXDMA_ARBBW_EN
#define BIT_RXDMA_ARBBW_EN	BIT(0)
#endif
#ifndef BIT_RXSHFT_EN
#define BIT_RXSHFT_EN		BIT(1)
#endif
#ifndef BIT_RXDMA_AGG_EN
#define BIT_RXDMA_AGG_EN	BIT(2)
#endif
#ifndef BIT_TXDMA_BW_EN
#define BIT_TXDMA_BW_EN		BIT(3)
#endif
#ifndef BIT_SHIFT_TXDMA_BEQ_MAP
#define BIT_SHIFT_TXDMA_BEQ_MAP	8
#endif
#ifndef BIT_MASK_TXDMA_BEQ_MAP
#define BIT_MASK_TXDMA_BEQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_BEQ_MAP
#define BIT_TXDMA_BEQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_BEQ_MAP) << BIT_SHIFT_TXDMA_BEQ_MAP)
#endif
#ifndef BIT_SHIFT_TXDMA_BKQ_MAP
#define BIT_SHIFT_TXDMA_BKQ_MAP	10
#endif
#ifndef BIT_MASK_TXDMA_BKQ_MAP
#define BIT_MASK_TXDMA_BKQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_BKQ_MAP
#define BIT_TXDMA_BKQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_BKQ_MAP) << BIT_SHIFT_TXDMA_BKQ_MAP)
#endif
#ifndef BIT_SHIFT_TXDMA_MGQ_MAP
#define BIT_SHIFT_TXDMA_MGQ_MAP	12
#endif
#ifndef BIT_MASK_TXDMA_MGQ_MAP
#define BIT_MASK_TXDMA_MGQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_MGQ_MAP
#define BIT_TXDMA_MGQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_MGQ_MAP) << BIT_SHIFT_TXDMA_MGQ_MAP)
#endif
#ifndef BIT_SHIFT_TXDMA_HIQ_MAP
#define BIT_SHIFT_TXDMA_HIQ_MAP	14
#endif
#ifndef BIT_MASK_TXDMA_HIQ_MAP
#define BIT_MASK_TXDMA_HIQ_MAP	0x3
#endif
#ifndef BIT_TXDMA_HIQ_MAP
#define BIT_TXDMA_HIQ_MAP(x)                                                   \
	(((x) & BIT_MASK_TXDMA_HIQ_MAP) << BIT_SHIFT_TXDMA_HIQ_MAP)
#endif
#ifndef BIT_SHIFT_TXSC_40M
#define BIT_SHIFT_TXSC_40M	4
#endif
#ifndef BIT_MASK_TXSC_40M
#define BIT_MASK_TXSC_40M	0xf
#endif
#ifndef BIT_TXSC_40M
#define BIT_TXSC_40M(x)							       \
	(((x) & BIT_MASK_TXSC_40M) << BIT_SHIFT_TXSC_40M)
#endif
#ifndef BIT_SHIFT_TXSC_20M
#define BIT_SHIFT_TXSC_20M	0
#endif
#ifndef BIT_MASK_TXSC_20M
#define BIT_MASK_TXSC_20M	0xf
#endif
#ifndef BIT_TXSC_20M
#define BIT_TXSC_20M(x)							       \
	(((x) & BIT_MASK_TXSC_20M) << BIT_SHIFT_TXSC_20M)
#endif
#ifndef BIT_SHIFT_MAC_CLK_SEL
#define BIT_SHIFT_MAC_CLK_SEL	20
#endif
#ifndef MAC_CLK_HW_DEF_80M
#define MAC_CLK_HW_DEF_80M	0
#endif
#ifndef MAC_CLK_HW_DEF_40M
#define MAC_CLK_HW_DEF_40M	1
#endif
#ifndef MAC_CLK_HW_DEF_20M
#define MAC_CLK_HW_DEF_20M	2
#endif
#ifndef MAC_CLK_SPEED
#define MAC_CLK_SPEED		80
#endif
#ifndef REG_CR
#define REG_CR			0x0100
#endif
#ifndef REG_TRXFF_BNDY
#define REG_TRXFF_BNDY		0x0114
#endif
#ifndef REG_RXFF_BNDY
#define REG_RXFF_BNDY		0x011C
#endif
#ifndef REG_FE1IMR
#define REG_FE1IMR		0x0120
#endif
#ifndef BIT_FS_RXDONE
#define BIT_FS_RXDONE		BIT(16)
#endif
#ifndef REG_CPWM
#define REG_CPWM		0x012C
#endif
#ifndef REG_FWIMR
#define REG_FWIMR		0x0130
#endif
#ifndef BIT_FS_H2CCMD_INT_EN
#define BIT_FS_H2CCMD_INT_EN	BIT(4)
#endif
#ifndef BIT_FS_HRCV_INT_EN
#define BIT_FS_HRCV_INT_EN	BIT(5)
#endif
#ifndef REG_FWISR
#define REG_FWISR		0x0134
#endif
#ifndef BIT_FS_H2CCMD_INT
#define BIT_FS_H2CCMD_INT	BIT(4)
#endif
#ifndef BIT_FS_HRCV_INT
#define BIT_FS_HRCV_INT		BIT(5)
#endif
#ifndef REG_PKTBUF_DBG_CTRL
#define REG_PKTBUF_DBG_CTRL	0x0140
#endif
#ifndef REG_C2HEVT
#define REG_C2HEVT		0x01A0
#endif
#ifndef REG_MCUTST_1
#define REG_MCUTST_1		0x01C0
#endif
#ifndef REG_MCUTST_II
#define REG_MCUTST_II		0x01C4
#endif
#ifndef REG_WOWLAN_WAKE_REASON
#define REG_WOWLAN_WAKE_REASON	0x01C7
#endif
#ifndef REG_HMETFR
#define REG_HMETFR		0x01CC
#endif
#ifndef BIT_INT_BOX0
#define BIT_INT_BOX0		BIT(0)
#endif
#ifndef BIT_INT_BOX1
#define BIT_INT_BOX1		BIT(1)
#endif
#ifndef BIT_INT_BOX2
#define BIT_INT_BOX2		BIT(2)
#endif
#ifndef BIT_INT_BOX3
#define BIT_INT_BOX3		BIT(3)
#endif
#ifndef BIT_INT_BOX_ALL
#define BIT_INT_BOX_ALL		(BIT_INT_BOX0 | BIT_INT_BOX1 | BIT_INT_BOX2 | \
				 BIT_INT_BOX3)
#endif
#ifndef REG_HMEBOX0
#define REG_HMEBOX0		0x01D0
#endif
#ifndef REG_HMEBOX1
#define REG_HMEBOX1		0x01D4
#endif
#ifndef REG_HMEBOX2
#define REG_HMEBOX2		0x01D8
#endif
#ifndef REG_HMEBOX3
#define REG_HMEBOX3		0x01DC
#endif
#ifndef REG_LLT_INIT
#define REG_LLT_INIT		0x01E0
#endif
#ifndef BIT_LLT_WRITE_ACCESS
#define BIT_LLT_WRITE_ACCESS	BIT(30)
#endif
#ifndef REG_RFK_FW_ACK
#define REG_RFK_FW_ACK		0x01E7
#endif
#ifndef BIT_RFK_FW_ACK
#define BIT_RFK_FW_ACK		BIT(0)
#endif
#ifndef REG_HMEBOX0_EX
#define REG_HMEBOX0_EX		0x01F0
#endif
#ifndef REG_HMEBOX1_EX
#define REG_HMEBOX1_EX		0x01F4
#endif
#ifndef REG_HMEBOX2_EX
#define REG_HMEBOX2_EX		0x01F8
#endif
#ifndef REG_HMEBOX3_EX
#define REG_HMEBOX3_EX		0x01FC
#endif
#ifndef REG_RQPN
#define REG_RQPN		0x0200
#endif
#ifndef BIT_MASK_HPQ
#define BIT_MASK_HPQ		0xff
#endif
#ifndef BIT_SHIFT_HPQ
#define BIT_SHIFT_HPQ		0
#endif
#ifndef BIT_RQPN_HPQ
#define BIT_RQPN_HPQ(x)		(((x) & BIT_MASK_HPQ) << BIT_SHIFT_HPQ)
#endif
#ifndef BIT_MASK_LPQ
#define BIT_MASK_LPQ		0xff
#endif
#ifndef BIT_SHIFT_LPQ
#define BIT_SHIFT_LPQ		8
#endif
#ifndef BIT_RQPN_LPQ
#define BIT_RQPN_LPQ(x)		(((x) & BIT_MASK_LPQ) << BIT_SHIFT_LPQ)
#endif
#ifndef BIT_MASK_PUBQ
#define BIT_MASK_PUBQ		0xff
#endif
#ifndef BIT_SHIFT_PUBQ
#define BIT_SHIFT_PUBQ		16
#endif
#ifndef BIT_RQPN_PUBQ
#define BIT_RQPN_PUBQ(x)	(((x) & BIT_MASK_PUBQ) << BIT_SHIFT_PUBQ)
#endif
#ifndef BIT_RQPN_HLP
#define BIT_RQPN_HLP(h, l, p)	(BIT_LD_RQPN | BIT_RQPN_HPQ(h) |	       \
				 BIT_RQPN_LPQ(l) | BIT_RQPN_PUBQ(p))
#endif
#ifndef REG_FIFOPAGE_CTRL_2
#define REG_FIFOPAGE_CTRL_2	0x0204
#endif
#ifndef BIT_BCN_VALID_V1
#define BIT_BCN_VALID_V1	BIT(15)
#endif
#ifndef BIT_MASK_BCN_HEAD_1_V1
#define BIT_MASK_BCN_HEAD_1_V1	0xfff
#endif
#ifndef REG_AUTO_LLT_V1
#define REG_AUTO_LLT_V1		0x0208
#endif
#ifndef BIT_AUTO_INIT_LLT_V1
#define BIT_AUTO_INIT_LLT_V1	BIT(0)
#endif
#ifndef BIT_MASK_BLK_DESC_NUM
#define BIT_MASK_BLK_DESC_NUM	GENMASK(7, 4)
#endif
#ifndef REG_DWBCN0_CTRL
#define REG_DWBCN0_CTRL		0x0208
#endif
#ifndef BIT_BCN_VALID
#define BIT_BCN_VALID		BIT(16)
#endif
#ifndef REG_TXDMA_OFFSET_CHK
#define REG_TXDMA_OFFSET_CHK	0x020C
#endif
#ifndef BIT_DROP_DATA_EN
#define BIT_DROP_DATA_EN	BIT(9)
#endif
#ifndef REG_TXDMA_STATUS
#define REG_TXDMA_STATUS	0x0210
#endif
#ifndef BTI_PAGE_OVF
#define BTI_PAGE_OVF		BIT(2)
#endif
#ifndef REG_RQPN_NPQ
#define REG_RQPN_NPQ		0x0214
#endif
#ifndef BIT_MASK_NPQ
#define BIT_MASK_NPQ		0xff
#endif
#ifndef BIT_SHIFT_NPQ
#define BIT_SHIFT_NPQ		0
#endif
#ifndef BIT_MASK_EPQ
#define BIT_MASK_EPQ		0xff
#endif
#ifndef BIT_SHIFT_EPQ
#define BIT_SHIFT_EPQ		16
#endif
#ifndef BIT_RQPN_NPQ
#define BIT_RQPN_NPQ(x)		(((x) & BIT_MASK_NPQ) << BIT_SHIFT_NPQ)
#endif
#ifndef BIT_RQPN_EPQ
#define BIT_RQPN_EPQ(x)		(((x) & BIT_MASK_EPQ) << BIT_SHIFT_EPQ)
#endif
#ifndef BIT_RQPN_NE
#define BIT_RQPN_NE(n, e)	(BIT_RQPN_NPQ(n) | BIT_RQPN_EPQ(e))
#endif
#ifndef REG_AUTO_LLT
#define REG_AUTO_LLT		0x0224
#endif
#ifndef BIT_AUTO_INIT_LLT
#define BIT_AUTO_INIT_LLT	BIT(16)
#endif
#ifndef REG_DWBCN1_CTRL
#define REG_DWBCN1_CTRL		0x0228
#endif
#ifndef REG_RQPN_CTRL_1
#define REG_RQPN_CTRL_1		0x0228
#endif
#ifndef REG_RQPN_CTRL_2
#define REG_RQPN_CTRL_2		0x022C
#endif
#ifndef BIT_LD_RQPN
#define BIT_LD_RQPN		BIT(31)
#endif
#ifndef REG_FIFOPAGE_INFO_1
#define REG_FIFOPAGE_INFO_1	0x0230
#endif
#ifndef REG_FIFOPAGE_INFO_2
#define REG_FIFOPAGE_INFO_2	0x0234
#endif
#ifndef REG_FIFOPAGE_INFO_3
#define REG_FIFOPAGE_INFO_3	0x0238
#endif
#ifndef REG_FIFOPAGE_INFO_4
#define REG_FIFOPAGE_INFO_4	0x023C
#endif
#ifndef REG_FIFOPAGE_INFO_5
#define REG_FIFOPAGE_INFO_5	0x0240
#endif
#ifndef REG_H2C_HEAD
#define REG_H2C_HEAD		0x0244
#endif
#ifndef REG_H2C_TAIL
#define REG_H2C_TAIL		0x0248
#endif
#ifndef REG_H2C_READ_ADDR
#define REG_H2C_READ_ADDR	0x024C
#endif
#ifndef REG_H2C_INFO
#define REG_H2C_INFO		0x0254
#endif
#ifndef REG_RXDMA_AGG_PG_TH
#define REG_RXDMA_AGG_PG_TH	0x0280
#endif
#ifndef BIT_RXDMA_AGG_PG_TH
#define BIT_RXDMA_AGG_PG_TH	GENMASK(7, 0)
#endif
#ifndef BIT_DMA_AGG_TO_V1
#define BIT_DMA_AGG_TO_V1	GENMASK(15, 8)
#endif
#ifndef BIT_EN_PRE_CALC
#define BIT_EN_PRE_CALC		BIT(29)
#endif
#ifndef REG_RXPKT_NUM
#define REG_RXPKT_NUM		0x0284
#endif
#ifndef BIT_RXDMA_REQ
#define BIT_RXDMA_REQ		BIT(19)
#endif
#ifndef BIT_RW_RELEASE
#define BIT_RW_RELEASE		BIT(18)
#endif
#ifndef BIT_RXDMA_IDLE
#define BIT_RXDMA_IDLE		BIT(17)
#endif
#ifndef REG_RXDMA_STATUS
#define REG_RXDMA_STATUS	0x0288
#endif
#ifndef REG_RXDMA_DPR
#define REG_RXDMA_DPR		0x028C
#endif
#ifndef REG_RXDMA_MODE
#define REG_RXDMA_MODE		0x0290
#endif
#ifndef BIT_DMA_MODE
#define BIT_DMA_MODE		BIT(1)
#endif
#ifndef BIT_DMA_BURST_CNT
#define BIT_DMA_BURST_CNT	GENMASK(3, 2)
#endif
#ifndef BIT_DMA_BURST_SIZE
#define BIT_DMA_BURST_SIZE	GENMASK(5, 4)
#endif
#ifndef BIT_DMA_BURST_SIZE_64
#define BIT_DMA_BURST_SIZE_64	2
#endif
#ifndef BIT_DMA_BURST_SIZE_512
#define BIT_DMA_BURST_SIZE_512	1
#endif
#ifndef BIT_DMA_BURST_SIZE_1024
#define BIT_DMA_BURST_SIZE_1024	0
#endif
#ifndef REG_RXPKTNUM
#define REG_RXPKTNUM		0x02B0
#endif
#ifndef REG_EARLY_MODE_CONTROL
#define REG_EARLY_MODE_CONTROL	0x02BC
#endif
#ifndef REG_INT_MIG
#define REG_INT_MIG		0x0304
#endif
#ifndef REG_HCI_MIX_CFG
#define REG_HCI_MIX_CFG		0x03FC
#endif
#ifndef BIT_PCIE_EMAC_PDN_AUX_TO_FAST_CLK
#define BIT_PCIE_EMAC_PDN_AUX_TO_FAST_CLK BIT(26)
#endif
#ifndef REG_BCNQ_INFO
#define REG_BCNQ_INFO		0x0418
#endif
#ifndef BIT_MGQ_CPU_EMPTY
#define BIT_MGQ_CPU_EMPTY	BIT(24)
#endif
#ifndef REG_TXPKT_EMPTY
#define REG_TXPKT_EMPTY		0x041A
#endif
#ifndef REG_FWHW_TXQ_CTRL
#define REG_FWHW_TXQ_CTRL	0x0420
#endif
#ifndef BIT_EN_BCNQ_DL
#define BIT_EN_BCNQ_DL		BIT(22)
#endif
#ifndef BIT_EN_WR_FREE_TAIL
#define BIT_EN_WR_FREE_TAIL	BIT(20)
#endif
#ifndef REG_HWSEQ_CTRL
#define REG_HWSEQ_CTRL		0x0423
#endif
#ifndef REG_BCNQ_BDNY_V1
#define REG_BCNQ_BDNY_V1	0x0424
#endif
#ifndef REG_BCNQ_BDNY
#define REG_BCNQ_BDNY		0x0424
#endif
#ifndef REG_MGQ_BDNY
#define REG_MGQ_BDNY		0x0425
#endif
#ifndef REG_LIFETIME_EN
#define REG_LIFETIME_EN		0x0426
#endif
#ifndef BIT_BA_PARSER_EN
#define BIT_BA_PARSER_EN	BIT(5)
#endif
#ifndef REG_SPEC_SIFS
#define REG_SPEC_SIFS		0x0428
#endif
#ifndef REG_RETRY_LIMIT
#define REG_RETRY_LIMIT		0x042a
#endif
#ifndef REG_DARFRC
#define REG_DARFRC		0x0430
#endif
#ifndef REG_DARFRCH
#define REG_DARFRCH		0x0434
#endif
#ifndef REG_RARFRCH
#define REG_RARFRCH		0x043C
#endif
#ifndef REG_RRSR
#define REG_RRSR		0x0440
#endif
#ifndef BITS_RRSR_RSC
#define BITS_RRSR_RSC		GENMASK(22, 21)
#endif
#ifndef REG_ARFR0
#define REG_ARFR0		0x0444
#endif
#ifndef REG_ARFRH0
#define REG_ARFRH0		0x0448
#endif
#ifndef REG_ARFR1_V1
#define REG_ARFR1_V1		0x044C
#endif
#ifndef REG_ARFRH1_V1
#define REG_ARFRH1_V1		0x0450
#endif
#ifndef REG_CCK_CHECK
#define REG_CCK_CHECK		0x0454
#endif
#ifndef BIT_CHECK_CCK_EN
#define BIT_CHECK_CCK_EN	BIT(7)
#endif
#ifndef REG_AMPDU_MAX_TIME_V1
#define REG_AMPDU_MAX_TIME_V1	0x0455
#endif
#ifndef REG_BCNQ1_BDNY_V1
#define REG_BCNQ1_BDNY_V1	0x0456
#endif
#ifndef REG_AMPDU_MAX_TIME
#define REG_AMPDU_MAX_TIME	0x0456
#endif
#ifndef REG_AMPDU_MAX_LENGTH
#define REG_AMPDU_MAX_LENGTH	0x0458
#endif
#ifndef REG_WMAC_LBK_BF_HD
#define REG_WMAC_LBK_BF_HD	0x045D
#endif
#ifndef REG_TX_HANG_CTRL
#define REG_TX_HANG_CTRL	0x045E
#endif
#ifndef BIT_EN_GNT_BT_AWAKE
#define BIT_EN_GNT_BT_AWAKE	BIT(3)
#endif
#ifndef BIT_EN_EOF_V1
#define BIT_EN_EOF_V1		BIT(2)
#endif
#ifndef REG_FAST_EDCA_CTRL
#define REG_FAST_EDCA_CTRL	0x0460
#endif
#ifndef REG_DATA_SC
#define REG_DATA_SC		0x0483
#endif
#ifndef REG_ARFR2_V1
#define REG_ARFR2_V1		0x048C
#endif
#ifndef REG_ARFRH2_V1
#define REG_ARFRH2_V1		0x0490
#endif
#ifndef REG_ARFR3_V1
#define REG_ARFR3_V1		0x0494
#endif
#ifndef BIT_EXC_CODE
#define BIT_EXC_CODE		GENMASK(6, 2)
#endif
#ifndef REG_ARFRH3_V1
#define REG_ARFRH3_V1		0x0498
#endif
#ifndef REG_ARFR4
#define REG_ARFR4		0x049C
#endif
#ifndef BIT_WL_RFK
#define BIT_WL_RFK		BIT(0)
#endif
#ifndef REG_ARFRH4
#define REG_ARFRH4		0x04A0
#endif
#ifndef REG_ARFR5
#define REG_ARFR5		0x04A4
#endif
#ifndef REG_ARFRH5
#define REG_ARFRH5		0x04A8
#endif
#ifndef REG_SW_AMPDU_BURST_MODE_CTRL
#define REG_SW_AMPDU_BURST_MODE_CTRL 0x04BC
#endif
#ifndef BIT_PRE_TX_CMD
#define BIT_PRE_TX_CMD		BIT(6)
#endif
#ifndef REG_PKT_VO_VI_LIFE_TIME
#define REG_PKT_VO_VI_LIFE_TIME	0x04C0
#endif
#ifndef REG_PKT_BE_BK_LIFE_TIME
#define REG_PKT_BE_BK_LIFE_TIME	0x04C2
#endif
#ifndef REG_QUEUE_CTRL
#define REG_QUEUE_CTRL		0x04C6
#endif
#ifndef BIT_PTA_WL_TX_EN
#define BIT_PTA_WL_TX_EN	BIT(4)
#endif
#ifndef BIT_PTA_EDCCA_EN
#define BIT_PTA_EDCCA_EN	BIT(5)
#endif
#ifndef REG_SINGLE_AMPDU_CTRL
#define REG_SINGLE_AMPDU_CTRL	0x04C7
#endif
#ifndef BIT_EN_SINGLE_APMDU
#define BIT_EN_SINGLE_APMDU	BIT(7)
#endif
#ifndef REG_PROT_MODE_CTRL
#define REG_PROT_MODE_CTRL	0x04C8
#endif
#ifndef REG_MAX_AGGR_NUM
#define REG_MAX_AGGR_NUM	0x04CA
#endif
#ifndef REG_BAR_MODE_CTRL
#define REG_BAR_MODE_CTRL	0x04CC
#endif
#ifndef REG_MACID_PKT_DROP0
#define REG_MACID_PKT_DROP0	0x04D0
#endif
#ifndef REG_MACID_PKT_SLEEP
#define REG_MACID_PKT_SLEEP	0x04D4
#endif
#ifndef REG_PRECNT_CTRL
#define REG_PRECNT_CTRL		0x04E5
#endif
#ifndef BIT_BTCCA_CTRL
#define BIT_BTCCA_CTRL		(BIT(0) | BIT(1))
#endif
#ifndef BIT_EN_PRECNT
#define BIT_EN_PRECNT		BIT(11)
#endif
#ifndef REG_TX_RPT_CTRL
#define REG_TX_RPT_CTRL		0x04EC
#endif
#ifndef REG_TX_RPT_TIME
#define REG_TX_RPT_TIME		0x04F0
#endif
#ifndef REG_DUMMY_PAGE4_V1
#define REG_DUMMY_PAGE4_V1	0x04FC
#endif
#ifndef REG_EDCA_VO_PARAM
#define REG_EDCA_VO_PARAM	0x0500
#endif
#ifndef REG_EDCA_VI_PARAM
#define REG_EDCA_VI_PARAM	0x0504
#endif
#ifndef REG_EDCA_BE_PARAM
#define REG_EDCA_BE_PARAM	0x0508
#endif
#ifndef REG_EDCA_BK_PARAM
#define REG_EDCA_BK_PARAM	0x050C
#endif
#ifndef BIT_MASK_TXOP_LMT
#define BIT_MASK_TXOP_LMT	GENMASK(26, 16)
#endif
#ifndef BIT_MASK_CWMAX
#define BIT_MASK_CWMAX		GENMASK(15, 12)
#endif
#ifndef BIT_MASK_CWMIN
#define BIT_MASK_CWMIN		GENMASK(11, 8)
#endif
#ifndef BIT_MASK_AIFS
#define BIT_MASK_AIFS		GENMASK(7, 0)
#endif
#ifndef REG_BCNTCFG
#define REG_BCNTCFG		0x0510
#endif
#ifndef REG_PIFS
#define REG_PIFS		0x0512
#endif
#ifndef REG_SIFS
#define REG_SIFS		0x0514
#endif
#ifndef BIT_SHIFT_SIFS_OFDM_CTX
#define BIT_SHIFT_SIFS_OFDM_CTX	8
#endif
#ifndef BIT_SHIFT_SIFS_CCK_TRX
#define BIT_SHIFT_SIFS_CCK_TRX	16
#endif
#ifndef BIT_SHIFT_SIFS_OFDM_TRX
#define BIT_SHIFT_SIFS_OFDM_TRX	24
#endif
#ifndef REG_AGGR_BREAK_TIME
#define REG_AGGR_BREAK_TIME	0x051A
#endif
#ifndef REG_SLOT
#define REG_SLOT		0x051B
#endif
#ifndef REG_TX_PTCL_CTRL
#define REG_TX_PTCL_CTRL	0x0520
#endif
#ifndef BIT_DIS_EDCCA
#define BIT_DIS_EDCCA		BIT(15)
#endif
#ifndef BIT_SIFS_BK_EN
#define BIT_SIFS_BK_EN		BIT(12)
#endif
#ifndef REG_TXPAUSE
#define REG_TXPAUSE		0x0522
#endif
#ifndef BIT_AC_QUEUE
#define BIT_AC_QUEUE		GENMASK(7, 0)
#endif
#ifndef BIT_HIGH_QUEUE
#define BIT_HIGH_QUEUE		BIT(5)
#endif
#ifndef REG_RD_CTRL
#define REG_RD_CTRL		0x0524
#endif
#ifndef BIT_EDCCA_MSK_CNTDOWN_EN
#define BIT_EDCCA_MSK_CNTDOWN_EN BIT(11)
#endif
#ifndef BIT_DIS_TXOP_CFE
#define BIT_DIS_TXOP_CFE	BIT(10)
#endif
#ifndef BIT_DIS_LSIG_CFE
#define BIT_DIS_LSIG_CFE	BIT(9)
#endif
#ifndef BIT_DIS_STBC_CFE
#define BIT_DIS_STBC_CFE	BIT(8)
#endif
#ifndef REG_TBTT_PROHIBIT
#define REG_TBTT_PROHIBIT	0x0540
#endif
#ifndef BIT_SHIFT_TBTT_HOLD_TIME_AP
#define BIT_SHIFT_TBTT_HOLD_TIME_AP 8
#endif
#ifndef REG_RD_NAV_NXT
#define REG_RD_NAV_NXT		0x0544
#endif
#ifndef REG_NAV_PROT_LEN
#define REG_NAV_PROT_LEN	0x0546
#endif
#ifndef REG_BCN_CTRL
#define REG_BCN_CTRL		0x0550
#endif
#ifndef BIT_DIS_TSF_UDT
#define BIT_DIS_TSF_UDT		BIT(4)
#endif
#ifndef BIT_EN_BCN_FUNCTION
#define BIT_EN_BCN_FUNCTION	BIT(3)
#endif
#ifndef BIT_EN_TXBCN_RPT
#define BIT_EN_TXBCN_RPT	BIT(2)
#endif
#ifndef REG_BCN_CTRL_CLINT0
#define REG_BCN_CTRL_CLINT0	0x0551
#endif
#ifndef REG_DRVERLYINT
#define REG_DRVERLYINT		0x0558
#endif
#ifndef REG_BCNDMATIM
#define REG_BCNDMATIM		0x0559
#endif
#ifndef REG_ATIMWND
#define REG_ATIMWND		0x055A
#endif
#ifndef ATIMWND_DEFAULT
#define ATIMWND_DEFAULT		0x2
#endif
#ifndef ATIMWND_AP
#define ATIMWND_AP		0xa
#endif
#ifndef REG_USTIME_TSF
#define REG_USTIME_TSF		0x055C
#endif
#ifndef REG_BCN_MAX_ERR
#define REG_BCN_MAX_ERR		0x055D
#endif
#ifndef REG_RXTSF_OFFSET_CCK
#define REG_RXTSF_OFFSET_CCK	0x055E
#endif
#ifndef REG_MISC_CTRL
#define REG_MISC_CTRL		0x0577
#endif
#ifndef BIT_EN_FREE_CNT
#define BIT_EN_FREE_CNT		BIT(3)
#endif
#ifndef BIT_DIS_SECOND_CCA
#define BIT_DIS_SECOND_CCA	(BIT(0) | BIT(1))
#endif
#ifndef REG_HIQ_NO_LMT_EN
#define REG_HIQ_NO_LMT_EN	0x5A7
#endif
#ifndef REG_DTIM_COUNTER_ROOT
#define REG_DTIM_COUNTER_ROOT	0x5A8
#endif
#ifndef BIT_HIQ_NO_LMT_EN_ROOT
#define BIT_HIQ_NO_LMT_EN_ROOT	BIT(0)
#endif
#ifndef REG_TIMER0_SRC_SEL
#define REG_TIMER0_SRC_SEL	0x05B4
#endif
#ifndef BIT_TSFT_SEL_TIMER0
#define BIT_TSFT_SEL_TIMER0	(BIT(4) | BIT(5) | BIT(6))
#endif
#ifndef REG_TCR
#define REG_TCR			0x0604
#endif
#ifndef BIT_PWRMGT_HWDATA_EN
#define BIT_PWRMGT_HWDATA_EN	BIT(7)
#endif
#ifndef BIT_TCR_UPDATE_TIMIE
#define BIT_TCR_UPDATE_TIMIE	BIT(5)
#endif
#ifndef BIT_TCR_UPDATE_HGQMD
#define BIT_TCR_UPDATE_HGQMD	BIT(4)
#endif
#ifndef REG_RCR
#define REG_RCR			0x0608
#endif
#ifndef BIT_APP_FCS
#define BIT_APP_FCS		BIT(31)
#endif
#ifndef BIT_APP_MIC
#define BIT_APP_MIC		BIT(30)
#endif
#ifndef BIT_APP_ICV
#define BIT_APP_ICV		BIT(29)
#endif
#ifndef BIT_APP_PHYSTS
#define BIT_APP_PHYSTS		BIT(28)
#endif
#ifndef BIT_APP_BASSN
#define BIT_APP_BASSN		BIT(27)
#endif
#ifndef BIT_VHT_DACK
#define BIT_VHT_DACK		BIT(26)
#endif
#ifndef BIT_TCPOFLD_EN
#define BIT_TCPOFLD_EN		BIT(25)
#endif
#ifndef BIT_ENMBID
#define BIT_ENMBID		BIT(24)
#endif
#ifndef BIT_LSIGEN
#define BIT_LSIGEN		BIT(23)
#endif
#ifndef BIT_MFBEN
#define BIT_MFBEN		BIT(22)
#endif
#ifndef BIT_DISCHKPPDLLEN
#define BIT_DISCHKPPDLLEN	BIT(21)
#endif
#ifndef BIT_PKTCTL_DLEN
#define BIT_PKTCTL_DLEN		BIT(20)
#endif
#ifndef BIT_DISGCLK
#define BIT_DISGCLK		BIT(19)
#endif
#ifndef BIT_TIM_PARSER_EN
#define BIT_TIM_PARSER_EN	BIT(18)
#endif
#ifndef BIT_BC_MD_EN
#define BIT_BC_MD_EN		BIT(17)
#endif
#ifndef BIT_UC_MD_EN
#define BIT_UC_MD_EN		BIT(16)
#endif
#ifndef BIT_RXSK_PERPKT
#define BIT_RXSK_PERPKT		BIT(15)
#endif
#ifndef BIT_HTC_LOC_CTRL
#define BIT_HTC_LOC_CTRL	BIT(14)
#endif
#ifndef BIT_AMF
#define BIT_AMF			BIT(13)
#endif
#ifndef BIT_RPFM_CAM_ENABLE
#define BIT_RPFM_CAM_ENABLE	BIT(12)
#endif
#ifndef BIT_TA_BCN
#define BIT_TA_BCN		BIT(11)
#endif
#ifndef BIT_RCR_ADF
#define BIT_RCR_ADF		BIT(11)
#endif
#ifndef BIT_DISDECMYPKT
#define BIT_DISDECMYPKT		BIT(10)
#endif
#ifndef BIT_AICV
#define BIT_AICV		BIT(9)
#endif
#ifndef BIT_ACRC32
#define BIT_ACRC32		BIT(8)
#endif
#ifndef BIT_CBSSID_BCN
#define BIT_CBSSID_BCN		BIT(7)
#endif
#ifndef BIT_CBSSID_DATA
#define BIT_CBSSID_DATA		BIT(6)
#endif
#ifndef BIT_APWRMGT
#define BIT_APWRMGT		BIT(5)
#endif
#ifndef BIT_ADD3
#define BIT_ADD3		BIT(4)
#endif
#ifndef BIT_AB
#define BIT_AB			BIT(3)
#endif
#ifndef BIT_AM
#define BIT_AM			BIT(2)
#endif
#ifndef BIT_APM
#define BIT_APM			BIT(1)
#endif
#ifndef BIT_AAP
#define BIT_AAP			BIT(0)
#endif
#ifndef REG_RX_PKT_LIMIT
#define REG_RX_PKT_LIMIT	0x060C
#endif
#ifndef REG_RX_DRVINFO_SZ
#define REG_RX_DRVINFO_SZ	0x060F
#endif
#ifndef BIT_APP_PHYSTS
#define BIT_APP_PHYSTS		BIT(28)
#endif
#ifndef REG_MAR
#define REG_MAR			0x0620
#endif
#ifndef REG_USTIME_EDCA
#define REG_USTIME_EDCA		0x0638
#endif
#ifndef REG_ACKTO_CCK
#define REG_ACKTO_CCK		0x0639
#endif
#ifndef REG_MAC_SPEC_SIFS
#define REG_MAC_SPEC_SIFS	0x063A
#endif
#ifndef REG_RESP_SIFS_CCK
#define REG_RESP_SIFS_CCK	0x063C
#endif
#ifndef REG_RESP_SIFS_OFDM
#define REG_RESP_SIFS_OFDM	0x063E
#endif
#ifndef REG_ACKTO
#define REG_ACKTO		0x0640
#endif
#ifndef REG_EIFS
#define REG_EIFS		0x0642
#endif
#ifndef REG_NAV_CTRL
#define REG_NAV_CTRL		0x0650
#endif
#ifndef REG_NAV_UPPER
#define REG_NAV_UPPER		0x0652
#endif
#ifndef REG_WMAC_TRXPTCL_CTL
#define REG_WMAC_TRXPTCL_CTL	0x0668
#endif
#ifndef BIT_RFMOD
#define BIT_RFMOD		(BIT(7) | BIT(8))
#endif
#ifndef BIT_RFMOD_80M
#define BIT_RFMOD_80M		BIT(8)
#endif
#ifndef BIT_RFMOD_40M
#define BIT_RFMOD_40M		BIT(7)
#endif
#ifndef REG_WMAC_TRXPTCL_CTL_H
#define REG_WMAC_TRXPTCL_CTL_H	0x066C
#endif
#ifndef REG_WKFMCAM_CMD
#define REG_WKFMCAM_CMD		0x0698
#endif
#ifndef BIT_WKFCAM_POLLING_V1
#define BIT_WKFCAM_POLLING_V1	BIT(31)
#endif
#ifndef BIT_WKFCAM_CLR_V1
#define BIT_WKFCAM_CLR_V1	BIT(30)
#endif
#ifndef BIT_WKFCAM_WE
#define BIT_WKFCAM_WE		BIT(16)
#endif
#ifndef BIT_SHIFT_WKFCAM_ADDR_V2
#define BIT_SHIFT_WKFCAM_ADDR_V2	8
#endif
#ifndef BIT_MASK_WKFCAM_ADDR_V2
#define BIT_MASK_WKFCAM_ADDR_V2		0xff
#endif
#ifndef BIT_WKFCAM_ADDR_V2
#define BIT_WKFCAM_ADDR_V2(x)						       \
	(((x) & BIT_MASK_WKFCAM_ADDR_V2) << BIT_SHIFT_WKFCAM_ADDR_V2)
#endif
#ifndef REG_WKFMCAM_RWD
#define REG_WKFMCAM_RWD         0x069C
#endif
#ifndef BIT_WKFMCAM_VALID
#define BIT_WKFMCAM_VALID	BIT(31)
#endif
#ifndef BIT_WKFMCAM_BC
#define BIT_WKFMCAM_BC		BIT(26)
#endif
#ifndef BIT_WKFMCAM_MC
#define BIT_WKFMCAM_MC		BIT(25)
#endif
#ifndef BIT_WKFMCAM_UC
#define BIT_WKFMCAM_UC		BIT(24)
#endif
#ifndef REG_RXFLTMAP0
#define REG_RXFLTMAP0		0x06A0
#endif
#ifndef REG_RXFLTMAP1
#define REG_RXFLTMAP1		0x06A2
#endif
#ifndef REG_RXFLTMAP2
#define REG_RXFLTMAP2		0x06A4
#endif
#ifndef REG_RXFLTMAP4
#define REG_RXFLTMAP4		0x068A
#endif
#ifndef REG_BT_COEX_TABLE0
#define REG_BT_COEX_TABLE0	0x06C0
#endif
#ifndef REG_BT_COEX_TABLE1
#define REG_BT_COEX_TABLE1	0x06C4
#endif
#ifndef REG_BT_COEX_BRK_TABLE
#define REG_BT_COEX_BRK_TABLE	0x06C8
#endif
#ifndef REG_BT_COEX_TABLE_H
#define REG_BT_COEX_TABLE_H	0x06CC
#endif
#ifndef REG_BT_COEX_TABLE_H1
#define REG_BT_COEX_TABLE_H1	0x06CD
#endif
#ifndef REG_BT_COEX_TABLE_H2
#define REG_BT_COEX_TABLE_H2	0x06CE
#endif
#ifndef REG_BT_COEX_TABLE_H3
#define REG_BT_COEX_TABLE_H3	0x06CF
#endif
#ifndef REG_BBPSF_CTRL
#define REG_BBPSF_CTRL		0x06DC
#endif
#ifndef REG_BT_COEX_V2
#define REG_BT_COEX_V2		0x0762
#endif
#ifndef BIT_GNT_BT_POLARITY
#define BIT_GNT_BT_POLARITY	BIT(12)
#endif
#ifndef BIT_LTE_COEX_EN
#define BIT_LTE_COEX_EN		BIT(7)
#endif
#ifndef REG_BT_CONTROL
#define REG_BT_CONTROL		0x0764
#endif
#ifndef REG_GNT_BT
#define REG_GNT_BT		0x0765
#endif
#ifndef BIT_PTA_SW_CTL
#define BIT_PTA_SW_CTL		GENMASK(4, 3)
#endif
#ifndef REG_BT_COEX_ENH_INTR_CTRL
#define REG_BT_COEX_ENH_INTR_CTRL	0x76E
#endif
#ifndef BIT_R_GRANTALL_WLMASK
#define BIT_R_GRANTALL_WLMASK	BIT(3)
#endif
#ifndef BIT_STATIS_BT_EN
#define BIT_STATIS_BT_EN	BIT(2)
#endif
#ifndef REG_BT_ACT_STATISTICS
#define REG_BT_ACT_STATISTICS	0x0770
#endif
#ifndef REG_BT_ACT_STATISTICS_1
#define REG_BT_ACT_STATISTICS_1	0x0774
#endif
#ifndef REG_BT_STAT_CTRL
#define REG_BT_STAT_CTRL	0x0778
#endif
#ifndef REG_BT_TDMA_TIME
#define REG_BT_TDMA_TIME	0x0790
#endif
#ifndef BIT_MASK_SAMPLE_RATE
#define BIT_MASK_SAMPLE_RATE	GENMASK(5, 0)
#endif
#ifndef REG_LTR_IDLE_LATENCY
#define REG_LTR_IDLE_LATENCY	0x0798
#endif
#ifndef REG_LTR_ACTIVE_LATENCY
#define REG_LTR_ACTIVE_LATENCY	0x079C
#endif
#ifndef REG_LTR_CTRL_BASIC
#define REG_LTR_CTRL_BASIC	0x07A4
#endif
#ifndef REG_WMAC_OPTION_FUNCTION
#define REG_WMAC_OPTION_FUNCTION 0x07D0
#endif
#ifndef REG_WMAC_OPTION_FUNCTION_1
#define REG_WMAC_OPTION_FUNCTION_1 0x07D4
#endif
#ifndef REG_FPGA0_RFMOD
#define REG_FPGA0_RFMOD		0x0800
#endif
#ifndef BIT_CCKEN
#define BIT_CCKEN		BIT(24)
#endif
#ifndef BIT_OFDMEN
#define BIT_OFDMEN		BIT(25)
#endif
#ifndef REG_CCK_RPT_FORMAT
#define REG_CCK_RPT_FORMAT	0x0804
#endif
#ifndef BIT_CCK_RPT_FORMAT
#define BIT_CCK_RPT_FORMAT	BIT(16)
#endif
#ifndef REG_RXPSEL
#define REG_RXPSEL		0x0808
#endif
#ifndef BIT_RX_PSEL_RST
#define BIT_RX_PSEL_RST		(BIT(28) | BIT(29))
#endif
#ifndef REG_TXPSEL
#define REG_TXPSEL		0x080C
#endif
#ifndef REG_RX_GAIN_EN
#define REG_RX_GAIN_EN		0x081c
#endif
#ifndef REG_FPGA0_XA_HSSI_PARM2
#define REG_FPGA0_XA_HSSI_PARM2	0x0824
#endif
#ifndef HSSI_3WIRE_ADDR_LEN
#define HSSI_3WIRE_ADDR_LEN	0x400
#endif
#ifndef HSSI_3WIRE_DATA_LEN
#define HSSI_3WIRE_DATA_LEN	0x800
#endif
#ifndef REG_CCASEL
#define REG_CCASEL		0x082C
#endif
#ifndef REG_FPGA0_XB_HSSI_PARM2
#define REG_FPGA0_XB_HSSI_PARM2	0x082C
#endif
#ifndef REG_PDMFTH
#define REG_PDMFTH		0x0830
#endif
#ifndef REG_BWINDICATION
#define REG_BWINDICATION	0x0834
#endif
#ifndef REG_CCA2ND
#define REG_CCA2ND		0x0838
#endif
#ifndef REG_L1PKTH
#define REG_L1PKTH		0x0848
#endif
#ifndef REG_CLKTRK
#define REG_CLKTRK		0x0860
#endif
#ifndef REG_FPGA0_XA_RF_INT_OE
#define REG_FPGA0_XA_RF_INT_OE	0x0860
#endif
#ifndef REG_FPGA0_XB_RF_INT_OE
#define REG_FPGA0_XB_RF_INT_OE	0x0864
#endif
#ifndef REG_FPGA0_XA_RF_SW_CTRL
#define REG_FPGA0_XA_RF_SW_CTRL	0x0870
#endif
#ifndef RFSI_RFENV
#define RFSI_RFENV		0x10
#endif
#ifndef REG_CSI_MASK_SETTING1
#define REG_CSI_MASK_SETTING1	0x0874
#endif
#ifndef REG_NBI_SETTING
#define REG_NBI_SETTING		0x087c
#endif
#ifndef BIT_NBI_ENABLE
#define BIT_NBI_ENABLE		BIT(13)
#endif
#ifndef REG_CSI_FIX_MASK0
#define REG_CSI_FIX_MASK0	0x0880
#endif
#ifndef REG_CSI_FIX_MASK1
#define REG_CSI_FIX_MASK1	0x0884
#endif
#ifndef REG_CSI_FIX_MASK6
#define REG_CSI_FIX_MASK6	0x0898
#endif
#ifndef REG_CSI_FIX_MASK7
#define REG_CSI_FIX_MASK7	0x089c
#endif
#ifndef REG_ADCCLK
#define REG_ADCCLK		0x08AC
#endif
#ifndef REG_HSSI_READ
#define REG_HSSI_READ		0x08B0
#endif
#ifndef REG_FPGA0_XCD_RF_PARA
#define REG_FPGA0_XCD_RF_PARA	0x08B4
#endif
#ifndef REG_RX_MCS_LIMIT
#define REG_RX_MCS_LIMIT	0x08BC
#endif
#ifndef REG_ADC160
#define REG_ADC160		0x08C4
#endif
#ifndef REG_DBGSEL
#define REG_DBGSEL		0x08fc
#endif
#ifndef REG_ANTSEL_SW
#define REG_ANTSEL_SW		0x0900
#endif
#ifndef REG_DAC_RSTB
#define REG_DAC_RSTB		0x090c
#endif
#ifndef REG_PSD
#define REG_PSD			0x0910
#endif
#ifndef BIT_PSD_INI
#define BIT_PSD_INI		GENMASK(23, 22)
#endif
#ifndef REG_SINGLE_TONE_CONT_TX
#define REG_SINGLE_TONE_CONT_TX	0x0914
#endif
#ifndef REG_RFE_CTRL_ANTA_SRC
#define REG_RFE_CTRL_ANTA_SRC	0x0930
#endif
#ifndef REG_RFE_CTRL_ANT_SW
#define REG_RFE_CTRL_ANT_SW	0x0944
#endif
#ifndef BIT_RFE_CTRL_ANT_SW_SEL
#define BIT_RFE_CTRL_ANT_SW_SEL	GENMASK(1, 0)
#endif
#ifndef REG_AGC_TABLE
#define REG_AGC_TABLE		0x0958
#endif
#ifndef REG_RFE_CTRL_E
#define REG_RFE_CTRL_E		0x0974
#endif
#ifndef REG_2ND_CCA_CTRL
#define REG_2ND_CCA_CTRL	0x0976
#endif
#ifndef REG_IQK_COM00
#define REG_IQK_COM00		0x0978
#endif
#ifndef REG_IQK_COM32
#define REG_IQK_COM32		0x097c
#endif
#ifndef REG_IQK_COM64
#define REG_IQK_COM64		0x0980
#endif
#ifndef REG_IQK_COM96
#define REG_IQK_COM96		0x0984
#endif
#ifndef REG_FAS
#define REG_FAS			0x09a4
#endif
#ifndef REG_RXSB
#define REG_RXSB		0x0a00
#endif
#ifndef BIT_RXSB_ANA_DIV
#define BIT_RXSB_ANA_DIV	BIT(15)
#endif
#ifndef REG_CCK_RX
#define REG_CCK_RX		0x0a04
#endif
#ifndef REG_CCK_PD_TH
#define REG_CCK_PD_TH		0x0a0a
#endif
#ifndef REG_PRECTRL
#define REG_PRECTRL		0x0a14
#endif
#ifndef BIT_DIS_CO_PATHSEL
#define BIT_DIS_CO_PATHSEL	BIT(7)
#endif
#ifndef BIT_IQ_WGT
#define BIT_IQ_WGT		GENMASK(9, 8)
#endif
#ifndef REG_CCA_MF
#define REG_CCA_MF		0x0a20
#endif
#ifndef BIT_MBC_WIN
#define BIT_MBC_WIN		GENMASK(5, 4)
#endif
#ifndef REG_CCK0_TX_FILTER1
#define REG_CCK0_TX_FILTER1	0x0a20
#endif
#ifndef REG_CCK_SWING
#define REG_CCK_SWING		0x0a22
#endif
#ifndef REG_CCK0_TX_FILTER2
#define REG_CCK0_TX_FILTER2	0x0a24
#endif
#ifndef REG_CCK0_DEBUG_PORT
#define REG_CCK0_DEBUG_PORT	0x0a28
#endif
#ifndef REG_CCK0_FAREPORT
#define REG_CCK0_FAREPORT	0x0a2c
#endif
#ifndef BIT_CCK0_2RX
#define BIT_CCK0_2RX		BIT(18)
#endif
#ifndef BIT_CCK0_MRC
#define BIT_CCK0_MRC		BIT(22)
#endif
#ifndef REG_FA_CCK
#define REG_FA_CCK		0x0a5c
#endif
#ifndef REG_DIS_DPD
#define REG_DIS_DPD		0x0a70
#endif
#ifndef DIS_DPD_MASK
#define DIS_DPD_MASK		GENMASK(9, 0)
#endif
#ifndef DIS_DPD_RATE6M
#define DIS_DPD_RATE6M		BIT(0)
#endif
#ifndef DIS_DPD_RATE9M
#define DIS_DPD_RATE9M		BIT(1)
#endif
#ifndef DIS_DPD_RATEMCS0
#define DIS_DPD_RATEMCS0	BIT(2)
#endif
#ifndef DIS_DPD_RATEMCS1
#define DIS_DPD_RATEMCS1	BIT(3)
#endif
#ifndef DIS_DPD_RATEMCS8
#define DIS_DPD_RATEMCS8	BIT(4)
#endif
#ifndef DIS_DPD_RATEMCS9
#define DIS_DPD_RATEMCS9	BIT(5)
#endif
#ifndef DIS_DPD_RATEVHT1SS_MCS0
#define DIS_DPD_RATEVHT1SS_MCS0	BIT(6)
#endif
#ifndef DIS_DPD_RATEVHT1SS_MCS1
#define DIS_DPD_RATEVHT1SS_MCS1	BIT(7)
#endif
#ifndef DIS_DPD_RATEVHT2SS_MCS0
#define DIS_DPD_RATEVHT2SS_MCS0	BIT(8)
#endif
#ifndef DIS_DPD_RATEVHT2SS_MCS1
#define DIS_DPD_RATEVHT2SS_MCS1	BIT(9)
#endif
#ifndef DIS_DPD_RATEALL
#define DIS_DPD_RATEALL		GENMASK(9, 0)
#endif
#ifndef REG_CCA
#define REG_CCA			0x0a70
#endif
#ifndef BIT_CCA_CO
#define BIT_CCA_CO		BIT(7)
#endif
#ifndef REG_ANTSEL
#define REG_ANTSEL		0x0a74
#endif
#ifndef BIT_ANT_BYCO
#define BIT_ANT_BYCO		BIT(8)
#endif
#ifndef REG_CCKTX
#define REG_CCKTX		0x0a84
#endif
#ifndef BIT_CMB_CCA_2R
#define BIT_CMB_CCA_2R		BIT(28)
#endif
#ifndef REG_CNTRST
#define REG_CNTRST		0x0b58
#endif
#ifndef REG_3WIRE_SWA
#define REG_3WIRE_SWA		0x0c00
#endif
#ifndef REG_RX_IQC_AB_A
#define REG_RX_IQC_AB_A		0x0c10
#endif
#ifndef REG_RX_IQC_CD_A
#define REG_RX_IQC_CD_A		0x0c14
#endif
#ifndef REG_TXSCALE_A
#define REG_TXSCALE_A		0x0c1c
#endif
#ifndef REG_B_RXIQI
#define REG_B_RXIQI		0x0c1c
#endif
#ifndef BB_SWING_MASK
#define BB_SWING_MASK		GENMASK(31, 21)
#endif
#ifndef REG_TX_AGC_A_CCK_11_CCK_1
#define REG_TX_AGC_A_CCK_11_CCK_1		0xc20
#endif
#ifndef REG_TX_AGC_A_OFDM18_OFDM6
#define REG_TX_AGC_A_OFDM18_OFDM6		0xc24
#endif
#ifndef REG_TX_AGC_A_OFDM54_OFDM24
#define REG_TX_AGC_A_OFDM54_OFDM24		0xc28
#endif
#ifndef REG_TX_AGC_A_MCS3_MCS0
#define REG_TX_AGC_A_MCS3_MCS0			0xc2c
#endif
#ifndef REG_TX_AGC_A_MCS7_MCS4
#define REG_TX_AGC_A_MCS7_MCS4			0xc30
#endif
#ifndef REG_TX_AGC_A_MCS11_MCS8
#define REG_TX_AGC_A_MCS11_MCS8			0xc34
#endif
#ifndef REG_TX_AGC_A_MCS15_MCS12
#define REG_TX_AGC_A_MCS15_MCS12		0xc38
#endif
#ifndef REG_TX_AGC_A_NSS1_INDEX3_NSS1_INDEX0
#define REG_TX_AGC_A_NSS1_INDEX3_NSS1_INDEX0	0xc3c
#endif
#ifndef REG_TX_AGC_A_NSS1_INDEX7_NSS1_INDEX4
#define REG_TX_AGC_A_NSS1_INDEX7_NSS1_INDEX4	0xc40
#endif
#ifndef REG_TX_AGC_A_NSS2_INDEX1_NSS1_INDEX8
#define REG_TX_AGC_A_NSS2_INDEX1_NSS1_INDEX8	0xc44
#endif
#ifndef REG_TX_AGC_A_NSS2_INDEX5_NSS2_INDEX2
#define REG_TX_AGC_A_NSS2_INDEX5_NSS2_INDEX2	0xc48
#endif
#ifndef REG_TX_AGC_A_NSS2_INDEX9_NSS2_INDEX6
#define REG_TX_AGC_A_NSS2_INDEX9_NSS2_INDEX6	0xc4c
#endif
#ifndef REG_RXIGI_A
#define REG_RXIGI_A		0x0c50
#endif
#ifndef REG_TX_PWR_TRAINING_A
#define REG_TX_PWR_TRAINING_A	0x0c54
#endif
#ifndef REG_CK_MONHA
#define REG_CK_MONHA		0x0c5c
#endif
#ifndef REG_AFE_PWR1_A
#define REG_AFE_PWR1_A		0x0c60
#endif
#ifndef REG_AFE_PWR2_A
#define REG_AFE_PWR2_A		0x0c64
#endif
#ifndef REG_RX_WAIT_CCA_TX_CCK_RFON_A
#define REG_RX_WAIT_CCA_TX_CCK_RFON_A	0x0c68
#endif
#ifndef REG_OFDM0_XA_TX_IQ_IMBALANCE
#define REG_OFDM0_XA_TX_IQ_IMBALANCE	0x0c80
#endif
#ifndef REG_OFDM0_A_TX_AFE
#define REG_OFDM0_A_TX_AFE	0x0c84
#endif
#ifndef REG_OFDM0_XB_TX_IQ_IMBALANCE
#define REG_OFDM0_XB_TX_IQ_IMBALANCE	0x0c88
#endif
#ifndef REG_TSSI_TRK_SW
#define REG_TSSI_TRK_SW		0x0c8c
#endif
#ifndef REG_LSSI_WRITE_A
#define REG_LSSI_WRITE_A	0x0c90
#endif
#ifndef REG_PREDISTA
#define REG_PREDISTA		0x0c90
#endif
#ifndef REG_TXAGCIDX
#define REG_TXAGCIDX		0x0c94
#endif
#ifndef REG_TX_AGC_A
#define REG_TX_AGC_A		0x0c94
#endif
#ifndef REG_RFE_PINMUX_A
#define REG_RFE_PINMUX_A	0x0cb0
#endif
#ifndef REG_RFE_INV_A
#define REG_RFE_INV_A		0x0cb4
#endif
#ifndef REG_RFE_CTRL8
#define REG_RFE_CTRL8		0x0cb4
#endif
#ifndef BIT_MASK_RFE_SEL89
#define BIT_MASK_RFE_SEL89	GENMASK(7, 0)
#endif
#ifndef PTA_CTRL_PIN
#define PTA_CTRL_PIN		0x66
#endif
#ifndef DPDT_CTRL_PIN
#define DPDT_CTRL_PIN		0x77
#endif
#ifndef RFE_INV_MASK
#define RFE_INV_MASK		0x3ff00000
#endif
#ifndef REG_RFECTL_A
#define REG_RFECTL_A		0x0cb8
#endif
#ifndef REG_RFE_INV0
#define REG_RFE_INV0		0x0cbc
#endif
#ifndef REG_RFE_INV8
#define REG_RFE_INV8		0x0cbd
#endif
#ifndef BIT_MASK_RFE_INV89
#define BIT_MASK_RFE_INV89	GENMASK(1, 0)
#endif
#ifndef REG_RFE_INV16
#define REG_RFE_INV16		0x0cbe
#endif
#ifndef BIT_RFE_BUF_EN
#define BIT_RFE_BUF_EN		BIT(3)
#endif
#ifndef REG_IQK_DPD_CFG
#define REG_IQK_DPD_CFG		0x0cc4
#endif
#ifndef REG_CFG_PMPD
#define REG_CFG_PMPD		0x0cc8
#endif
#ifndef REG_IQC_Y
#define REG_IQC_Y		0x0ccc
#endif
#ifndef REG_IQC_X
#define REG_IQC_X		0x0cd4
#endif
#ifndef REG_INTPO_SETA
#define REG_INTPO_SETA		0x0ce8
#endif
#ifndef REG_IQKA_END
#define REG_IQKA_END		0x0d00
#endif
#ifndef REG_PI_READ_A
#define REG_PI_READ_A		0x0d04
#endif
#ifndef REG_SI_READ_A
#define REG_SI_READ_A		0x0d08
#endif
#ifndef REG_IQKB_END
#define REG_IQKB_END		0x0d40
#endif
#ifndef REG_PI_READ_B
#define REG_PI_READ_B		0x0d44
#endif
#ifndef REG_SI_READ_B
#define REG_SI_READ_B		0x0d48
#endif
#ifndef REG_3WIRE_SWB
#define REG_3WIRE_SWB		0x0e00
#endif
#ifndef REG_RX_IQC_AB_B
#define REG_RX_IQC_AB_B		0x0e10
#endif
#ifndef REG_RX_IQC_CD_B
#define REG_RX_IQC_CD_B		0x0e14
#endif
#ifndef REG_TXSCALE_B
#define REG_TXSCALE_B		0x0e1c
#endif
#ifndef REG_TX_AGC_B_CCK_11_CCK_1
#define REG_TX_AGC_B_CCK_11_CCK_1		0xe20
#endif
#ifndef REG_TX_AGC_B_OFDM18_OFDM6
#define REG_TX_AGC_B_OFDM18_OFDM6		0xe24
#endif
#ifndef REG_TX_AGC_B_OFDM54_OFDM24
#define REG_TX_AGC_B_OFDM54_OFDM24		0xe28
#endif
#ifndef REG_TX_AGC_B_MCS3_MCS0
#define REG_TX_AGC_B_MCS3_MCS0			0xe2c
#endif
#ifndef REG_TX_AGC_B_MCS7_MCS4
#define REG_TX_AGC_B_MCS7_MCS4			0xe30
#endif
#ifndef REG_TX_AGC_B_MCS11_MCS8
#define REG_TX_AGC_B_MCS11_MCS8			0xe34
#endif
#ifndef REG_TX_AGC_B_MCS15_MCS12
#define REG_TX_AGC_B_MCS15_MCS12		0xe38
#endif
#ifndef REG_TX_AGC_B_NSS1_INDEX3_NSS1_INDEX0
#define REG_TX_AGC_B_NSS1_INDEX3_NSS1_INDEX0	0xe3c
#endif
#ifndef REG_TX_AGC_B_NSS1_INDEX7_NSS1_INDEX4
#define REG_TX_AGC_B_NSS1_INDEX7_NSS1_INDEX4	0xe40
#endif
#ifndef REG_TX_AGC_B_NSS2_INDEX1_NSS1_INDEX8
#define REG_TX_AGC_B_NSS2_INDEX1_NSS1_INDEX8	0xe44
#endif
#ifndef REG_TX_AGC_B_NSS2_INDEX5_NSS2_INDEX2
#define REG_TX_AGC_B_NSS2_INDEX5_NSS2_INDEX2	0xe48
#endif
#ifndef REG_TX_AGC_B_NSS2_INDEX9_NSS2_INDEX6
#define REG_TX_AGC_B_NSS2_INDEX9_NSS2_INDEX6	0xe4c
#endif
#ifndef REG_RXIGI_B
#define REG_RXIGI_B		0x0e50
#endif
#ifndef REG_TX_PWR_TRAINING_B
#define REG_TX_PWR_TRAINING_B	0x0e54
#endif
#ifndef REG_CK_MONHB
#define REG_CK_MONHB		0x0e5c
#endif
#ifndef REG_AFE_PWR1_B
#define REG_AFE_PWR1_B		0x0e60
#endif
#ifndef REG_AFE_PWR2_B
#define REG_AFE_PWR2_B		0x0e64
#endif
#ifndef REG_RX_WAIT_CCA_TX_CCK_RFON_B
#define REG_RX_WAIT_CCA_TX_CCK_RFON_B	0x0e68
#endif
#ifndef REG_TXTONEB
#define REG_TXTONEB		0x0e80
#endif
#ifndef REG_RXTONEB
#define REG_RXTONEB		0x0e84
#endif
#ifndef REG_TXPITMB
#define REG_TXPITMB		0x0e88
#endif
#ifndef REG_RXPITMB
#define REG_RXPITMB		0x0e8c
#endif
#ifndef REG_LSSI_WRITE_B
#define REG_LSSI_WRITE_B	0x0e90
#endif
#ifndef REG_PREDISTB
#define REG_PREDISTB		0x0e90
#endif
#ifndef REG_INIDLYB
#define REG_INIDLYB		0x0e94
#endif
#ifndef REG_TX_AGC_B
#define REG_TX_AGC_B		0x0e94
#endif
#ifndef REG_RFE_PINMUX_B
#define REG_RFE_PINMUX_B	0x0eb0
#endif
#ifndef REG_RFE_INV_B
#define REG_RFE_INV_B		0x0eb4
#endif
#ifndef REG_RFECTL_B
#define REG_RFECTL_B		0x0eb8
#endif
#ifndef REG_BPBDB
#define REG_BPBDB		0x0ec4
#endif
#ifndef REG_PHYTXONB
#define REG_PHYTXONB		0x0ec8
#endif
#ifndef REG_IQKYB
#define REG_IQKYB		0x0ecc
#endif
#ifndef REG_IQKXB
#define REG_IQKXB		0x0ed4
#endif
#ifndef REG_INTPO_SETB
#define REG_INTPO_SETB		0x0ee8
#endif
#ifndef REG_CRC_CCK
#define REG_CRC_CCK		0x0f04
#endif
#ifndef REG_CCA_OFDM
#define REG_CCA_OFDM		0x0f08
#endif
#ifndef REG_CRC_VHT
#define REG_CRC_VHT		0x0f0c
#endif
#ifndef REG_CRC_HT
#define REG_CRC_HT		0x0f10
#endif
#ifndef REG_CRC_OFDM
#define REG_CRC_OFDM		0x0f14
#endif
#ifndef REG_FA_OFDM
#define REG_FA_OFDM		0x0f48
#endif
#ifndef REG_DBGRPT
#define REG_DBGRPT		0x0fa0
#endif
#ifndef REG_CCA_CCK
#define REG_CCA_CCK		0x0fcc
#endif
#ifndef REG_SYS_CFG3_8814A
#define REG_SYS_CFG3_8814A	0x1000
#endif
#ifndef REG_ANAPARSW_MAC_0
#define REG_ANAPARSW_MAC_0	0x1010
#endif
#ifndef BIT_CF_L_V2
#define BIT_CF_L_V2		GENMASK(29, 28)
#endif
#ifndef REG_ANAPAR_XTAL_0
#define REG_ANAPAR_XTAL_0	0x1040
#endif
#ifndef BIT_XCAP_0
#define BIT_XCAP_0		GENMASK(23, 10)
#endif
#ifndef REG_CPU_DMEM_CON
#define REG_CPU_DMEM_CON	0x1080
#endif
#ifndef BIT_WL_PLATFORM_RST
#define BIT_WL_PLATFORM_RST	BIT(16)
#endif
#ifndef BIT_WL_SECURITY_CLK
#define BIT_WL_SECURITY_CLK	BIT(15)
#endif
#ifndef BIT_DDMA_EN
#define BIT_DDMA_EN		BIT(8)
#endif
#ifndef REG_SW_MDIO
#define REG_SW_MDIO		0x10C0
#endif
#ifndef REG_H2C_PKT_READADDR
#define REG_H2C_PKT_READADDR	0x10D0
#endif
#ifndef REG_H2C_PKT_WRITEADDR
#define REG_H2C_PKT_WRITEADDR	0x10D4
#endif
#ifndef REG_FW_DBG6
#define REG_FW_DBG6		0x10F8
#endif
#ifndef REG_FW_DBG7
#define REG_FW_DBG7		0x10FC
#endif
#ifndef FW_KEY_MASK
#define FW_KEY_MASK		0xffffff00
#endif
#ifndef REG_CR_EXT
#define REG_CR_EXT		0x1100
#endif
#ifndef REG_FT1IMR
#define REG_FT1IMR		0x1138
#endif
#ifndef BIT_FS_H2C_CMD_OK_INT_EN
#define BIT_FS_H2C_CMD_OK_INT_EN BIT(25)
#endif
#ifndef REG_FT1ISR
#define REG_FT1ISR		0x113c
#endif
#ifndef BIT_FS_H2C_CMD_OK_INT
#define BIT_FS_H2C_CMD_OK_INT	BIT(25)
#endif
#ifndef REG_DDMA_CH0SA
#define REG_DDMA_CH0SA		0x1200
#endif
#ifndef REG_DDMA_CH0DA
#define REG_DDMA_CH0DA		0x1204
#endif
#ifndef REG_DDMA_CH0CTRL
#define REG_DDMA_CH0CTRL	0x1208
#endif
#ifndef BIT_DDMACH0_OWN
#define BIT_DDMACH0_OWN		BIT(31)
#endif
#ifndef BIT_DDMACH0_CHKSUM_EN
#define BIT_DDMACH0_CHKSUM_EN	BIT(29)
#endif
#ifndef BIT_DDMACH0_CHKSUM_STS
#define BIT_DDMACH0_CHKSUM_STS	BIT(27)
#endif
#ifndef BIT_DDMACH0_DDMA_MODE
#define BIT_DDMACH0_DDMA_MODE	BIT(26)
#endif
#ifndef BIT_DDMACH0_RESET_CHKSUM_STS
#define BIT_DDMACH0_RESET_CHKSUM_STS BIT(25)
#endif
#ifndef BIT_DDMACH0_CHKSUM_CONT
#define BIT_DDMACH0_CHKSUM_CONT	BIT(24)
#endif
#ifndef BIT_MASK_DDMACH0_DLEN
#define BIT_MASK_DDMACH0_DLEN	0x3ffff
#endif
#ifndef REG_H2CQ_CSR
#define REG_H2CQ_CSR		0x1330
#endif
#ifndef BIT_H2CQ_FULL
#define BIT_H2CQ_FULL		BIT(31)
#endif
#ifndef REG_FAST_EDCA_VOVI_SETTING
#define REG_FAST_EDCA_VOVI_SETTING 0x1448
#endif
#ifndef REG_FAST_EDCA_BEBK_SETTING
#define REG_FAST_EDCA_BEBK_SETTING 0x144C
#endif
#ifndef REG_RXPSF_CTRL
#define REG_RXPSF_CTRL		0x1610
#endif
#ifndef BIT_RXGCK_FIFOTHR_EN
#define BIT_RXGCK_FIFOTHR_EN	BIT(28)
#endif
#ifndef BIT_SHIFT_RXGCK_VHT_FIFOTHR
#define BIT_SHIFT_RXGCK_VHT_FIFOTHR 26
#endif
#ifndef BIT_MASK_RXGCK_VHT_FIFOTHR
#define BIT_MASK_RXGCK_VHT_FIFOTHR 0x3
#endif
#ifndef BIT_RXGCK_VHT_FIFOTHR
#define BIT_RXGCK_VHT_FIFOTHR(x)                                               \
	(((x) & BIT_MASK_RXGCK_VHT_FIFOTHR) << BIT_SHIFT_RXGCK_VHT_FIFOTHR)
#endif
#ifndef BITS_RXGCK_VHT_FIFOTHR
#define BITS_RXGCK_VHT_FIFOTHR                                                 \
	(BIT_MASK_RXGCK_VHT_FIFOTHR << BIT_SHIFT_RXGCK_VHT_FIFOTHR)
#endif
#ifndef BIT_SHIFT_RXGCK_HT_FIFOTHR
#define BIT_SHIFT_RXGCK_HT_FIFOTHR 24
#endif
#ifndef BIT_MASK_RXGCK_HT_FIFOTHR
#define BIT_MASK_RXGCK_HT_FIFOTHR 0x3
#endif
#ifndef BIT_RXGCK_HT_FIFOTHR
#define BIT_RXGCK_HT_FIFOTHR(x)                                                \
	(((x) & BIT_MASK_RXGCK_HT_FIFOTHR) << BIT_SHIFT_RXGCK_HT_FIFOTHR)
#endif
#ifndef BITS_RXGCK_HT_FIFOTHR
#define BITS_RXGCK_HT_FIFOTHR                                                  \
	(BIT_MASK_RXGCK_HT_FIFOTHR << BIT_SHIFT_RXGCK_HT_FIFOTHR)
#endif
#ifndef BIT_SHIFT_RXGCK_OFDM_FIFOTHR
#define BIT_SHIFT_RXGCK_OFDM_FIFOTHR 22
#endif
#ifndef BIT_MASK_RXGCK_OFDM_FIFOTHR
#define BIT_MASK_RXGCK_OFDM_FIFOTHR 0x3
#endif
#ifndef BIT_RXGCK_OFDM_FIFOTHR
#define BIT_RXGCK_OFDM_FIFOTHR(x)                                              \
	(((x) & BIT_MASK_RXGCK_OFDM_FIFOTHR) << BIT_SHIFT_RXGCK_OFDM_FIFOTHR)
#endif
#ifndef BITS_RXGCK_OFDM_FIFOTHR
#define BITS_RXGCK_OFDM_FIFOTHR                                                \
	(BIT_MASK_RXGCK_OFDM_FIFOTHR << BIT_SHIFT_RXGCK_OFDM_FIFOTHR)
#endif
#ifndef BIT_SHIFT_RXGCK_CCK_FIFOTHR
#define BIT_SHIFT_RXGCK_CCK_FIFOTHR 20
#endif
#ifndef BIT_MASK_RXGCK_CCK_FIFOTHR
#define BIT_MASK_RXGCK_CCK_FIFOTHR 0x3
#endif
#ifndef BIT_RXGCK_CCK_FIFOTHR
#define BIT_RXGCK_CCK_FIFOTHR(x)                                               \
	(((x) & BIT_MASK_RXGCK_CCK_FIFOTHR) << BIT_SHIFT_RXGCK_CCK_FIFOTHR)
#endif
#ifndef BITS_RXGCK_CCK_FIFOTHR
#define BITS_RXGCK_CCK_FIFOTHR                                                 \
	(BIT_MASK_RXGCK_CCK_FIFOTHR << BIT_SHIFT_RXGCK_CCK_FIFOTHR)
#endif
#ifndef BIT_RXGCK_OFDMCCA_EN
#define BIT_RXGCK_OFDMCCA_EN BIT(16)
#endif
#ifndef BIT_SHIFT_RXPSF_PKTLENTHR
#define BIT_SHIFT_RXPSF_PKTLENTHR 13
#endif
#ifndef BIT_MASK_RXPSF_PKTLENTHR
#define BIT_MASK_RXPSF_PKTLENTHR 0x7
#endif
#ifndef BIT_RXPSF_PKTLENTHR
#define BIT_RXPSF_PKTLENTHR(x)                                                 \
	(((x) & BIT_MASK_RXPSF_PKTLENTHR) << BIT_SHIFT_RXPSF_PKTLENTHR)
#endif
#ifndef BITS_RXPSF_PKTLENTHR
#define BITS_RXPSF_PKTLENTHR                                                   \
	(BIT_MASK_RXPSF_PKTLENTHR << BIT_SHIFT_RXPSF_PKTLENTHR)
#endif
#ifndef BIT_CLEAR_RXPSF_PKTLENTHR
#define BIT_CLEAR_RXPSF_PKTLENTHR(x) ((x) & (~BITS_RXPSF_PKTLENTHR))
#endif
#ifndef BIT_SET_RXPSF_PKTLENTHR
#define BIT_SET_RXPSF_PKTLENTHR(x, v)                                          \
	(BIT_CLEAR_RXPSF_PKTLENTHR(x) | BIT_RXPSF_PKTLENTHR(v))
#endif
#ifndef BIT_RXPSF_CTRLEN
#define BIT_RXPSF_CTRLEN	BIT(12)
#endif
#ifndef BIT_RXPSF_VHTCHKEN
#define BIT_RXPSF_VHTCHKEN	BIT(11)
#endif
#ifndef BIT_RXPSF_HTCHKEN
#define BIT_RXPSF_HTCHKEN	BIT(10)
#endif
#ifndef BIT_RXPSF_OFDMCHKEN
#define BIT_RXPSF_OFDMCHKEN	BIT(9)
#endif
#ifndef BIT_RXPSF_CCKCHKEN
#define BIT_RXPSF_CCKCHKEN	BIT(8)
#endif
#ifndef BIT_RXPSF_OFDMRST
#define BIT_RXPSF_OFDMRST	BIT(7)
#endif
#ifndef BIT_RXPSF_CCKRST
#define BIT_RXPSF_CCKRST	BIT(6)
#endif
#ifndef BIT_RXPSF_MHCHKEN
#define BIT_RXPSF_MHCHKEN	BIT(5)
#endif
#ifndef BIT_RXPSF_CONT_ERRCHKEN
#define BIT_RXPSF_CONT_ERRCHKEN	BIT(4)
#endif
#ifndef BIT_RXPSF_ALL_ERRCHKEN
#define BIT_RXPSF_ALL_ERRCHKEN	BIT(3)
#endif
#ifndef BIT_SHIFT_RXPSF_ERRTHR
#define BIT_SHIFT_RXPSF_ERRTHR 0
#endif
#ifndef BIT_MASK_RXPSF_ERRTHR
#define BIT_MASK_RXPSF_ERRTHR 0x7
#endif
#ifndef BIT_RXPSF_ERRTHR
#define BIT_RXPSF_ERRTHR(x)                                                    \
	(((x) & BIT_MASK_RXPSF_ERRTHR) << BIT_SHIFT_RXPSF_ERRTHR)
#endif
#ifndef BITS_RXPSF_ERRTHR
#define BITS_RXPSF_ERRTHR (BIT_MASK_RXPSF_ERRTHR << BIT_SHIFT_RXPSF_ERRTHR)
#endif
#ifndef BIT_CLEAR_RXPSF_ERRTHR
#define BIT_CLEAR_RXPSF_ERRTHR(x) ((x) & (~BITS_RXPSF_ERRTHR))
#endif
#ifndef BIT_GET_RXPSF_ERRTHR
#define BIT_GET_RXPSF_ERRTHR(x)                                                \
	(((x) >> BIT_SHIFT_RXPSF_ERRTHR) & BIT_MASK_RXPSF_ERRTHR)
#endif
#ifndef BIT_SET_RXPSF_ERRTHR
#define BIT_SET_RXPSF_ERRTHR(x, v)                                             \
	(BIT_CLEAR_RXPSF_ERRTHR(x) | BIT_RXPSF_ERRTHR(v))
#endif
#ifndef REG_RXPSF_TYPE_CTRL
#define REG_RXPSF_TYPE_CTRL	0x1614
#endif
#ifndef REG_GENERAL_OPTION
#define REG_GENERAL_OPTION	0x1664
#endif
#ifndef BIT_DUMMY_FCS_READY_MASK_EN
#define BIT_DUMMY_FCS_READY_MASK_EN BIT(9)
#endif
#ifndef REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1
#define REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1		0x1700
#endif
#ifndef REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1
#define REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1	0x1704
#endif
#ifndef REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1
#define REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1	0x1708
#endif
#ifndef LTECOEX_READY
#define LTECOEX_READY		BIT(29)
#endif
#ifndef LTECOEX_ACCESS_CTRL
#define LTECOEX_ACCESS_CTRL REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1
#endif
#ifndef LTECOEX_WRITE_DATA
#define LTECOEX_WRITE_DATA REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1
#endif
#ifndef LTECOEX_READ_DATA
#define LTECOEX_READ_DATA REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1
#endif
#ifndef REG_RX_IQC_AB_C
#define REG_RX_IQC_AB_C		0x1810
#endif
#ifndef REG_RX_IQC_CD_C
#define REG_RX_IQC_CD_C		0x1814
#endif
#ifndef REG_TXSCALE_C
#define REG_TXSCALE_C		0x181c
#endif
#ifndef REG_CK_MONHC
#define REG_CK_MONHC		0x185c
#endif
#ifndef REG_AFE_PWR1_C
#define REG_AFE_PWR1_C		0x1860
#endif
#ifndef REG_IGN_GNT_BT1
#define REG_IGN_GNT_BT1	0x1860
#endif
#ifndef REG_TX_AGC_C
#define REG_TX_AGC_C		0x1894
#endif
#ifndef REG_RFE_PINMUX_C
#define REG_RFE_PINMUX_C	0x18b4
#endif
#ifndef REG_RFESEL_CTRL
#define REG_RFESEL_CTRL	0x1990
#endif
#ifndef REG_AGC_TBL
#define REG_AGC_TBL		0x1998
#endif
#ifndef REG_RX_IQC_AB_D
#define REG_RX_IQC_AB_D		0x1a10
#endif
#ifndef REG_RX_IQC_CD_D
#define REG_RX_IQC_CD_D		0x1a14
#endif
#ifndef REG_TXSCALE_D
#define REG_TXSCALE_D		0x1a1c
#endif
#ifndef REG_CK_MONHD
#define REG_CK_MONHD		0x1a5c
#endif
#ifndef REG_AFE_PWR1_D
#define REG_AFE_PWR1_D		0x1a60
#endif
#ifndef REG_TX_AGC_D
#define REG_TX_AGC_D		0x1a94
#endif
#ifndef REG_RFE_PINMUX_D
#define REG_RFE_PINMUX_D	0x1ab4
#endif
#ifndef REG_RFE_INVSEL_D
#define REG_RFE_INVSEL_D	0x1abc
#endif
#ifndef BIT_RFE_SELSW0_D
#define BIT_RFE_SELSW0_D	GENMASK(27, 20)
#endif
#ifndef REG_NOMASK_TXBT
#define REG_NOMASK_TXBT	0x1ca7
#endif
#ifndef REG_ANAPAR
#define REG_ANAPAR	0x1c30
#endif
#ifndef BIT_ANAPAR_BTPS
#define BIT_ANAPAR_BTPS	BIT(22)
#endif
#ifndef REG_RSTB_SEL
#define REG_RSTB_SEL	0x1c38
#endif
#ifndef BIT_DAC_OFF_ENABLE
#define BIT_DAC_OFF_ENABLE	BIT(4)
#endif
#ifndef BIT_PI_IGNORE_GNT_BT
#define BIT_PI_IGNORE_GNT_BT	BIT(3)
#endif
#ifndef BIT_NOMASK_TXBT_ENABLE
#define BIT_NOMASK_TXBT_ENABLE	BIT(3)
#endif
#ifndef REG_HRCV_MSG
#define REG_HRCV_MSG	0x1cf
#endif
#ifndef REG_EDCCA_REPORT
#define REG_EDCCA_REPORT	0x2d38
#endif
#ifndef BIT_EDCCA_FLAG
#define BIT_EDCCA_FLAG		BIT(24)
#endif
#ifndef REG_IGN_GNTBT4
#define REG_IGN_GNTBT4	0x4160
#endif
#ifndef REG_USB_MOD
#define REG_USB_MOD	0xf008
#endif
#ifndef REG_USB3_RXITV
#define REG_USB3_RXITV	0xf050
#endif
#ifndef REG_USB2_PHY_ADR
#define REG_USB2_PHY_ADR	0xfe40
#endif
#ifndef REG_USB2_PHY_DAT
#define REG_USB2_PHY_DAT	0xfe41
#endif
#ifndef REG_USB2_PHY_CMD
#define REG_USB2_PHY_CMD	0xfe42
#endif
#ifndef BIT_USB2_PHY_CMD_TRG
#define BIT_USB2_PHY_CMD_TRG	0x81
#endif
#ifndef REG_USB_HRPWM
#define REG_USB_HRPWM	0xfe58
#endif
#ifndef REG_USB3_PHY_ADR
#define REG_USB3_PHY_ADR	0xff0c
#endif
#ifndef REG_USB3_PHY_DAT_L
#define REG_USB3_PHY_DAT_L	0xff0d
#endif
#ifndef REG_USB3_PHY_DAT_H
#define REG_USB3_PHY_DAT_H	0xff0e
#endif
#ifndef BIT_USB3_PHY_ADR_WR
#define BIT_USB3_PHY_ADR_WR	BIT(7)
#endif
#ifndef BIT_USB3_PHY_ADR_RD
#define BIT_USB3_PHY_ADR_RD	BIT(6)
#endif
#ifndef BIT_USB3_PHY_ADR_MASK
#define BIT_USB3_PHY_ADR_MASK	GENMASK(5, 0)
#endif
#ifndef RF_MODE
#define RF_MODE		0x00
#endif
#ifndef RF_MODOPT
#define RF_MODOPT	0x01
#endif
#ifndef RF_WLINT
#define RF_WLINT	0x01
#endif
#ifndef RF_WLSEL
#define RF_WLSEL	0x02
#endif
#ifndef RF_DTXLOK
#define RF_DTXLOK	0x08
#endif
#ifndef RF_CFGCH
#define RF_CFGCH	0x18
#endif
#ifndef BIT_BAND
#define BIT_BAND	GENMASK(18, 16)
#endif
#ifndef RF18_BAND_MASK
#define RF18_BAND_MASK	(BIT(16) | BIT(9) | BIT(8))
#endif
#ifndef RF18_CHANNEL_MASK
#define RF18_CHANNEL_MASK	(MASKBYTE0)
#endif
#ifndef RF18_RFSI_MASK
#define RF18_RFSI_MASK	(BIT(18) | BIT(17))
#endif
#ifndef RF_RCK1_V1
#define RF_RCK1_V1	0x1c
#endif
#ifndef RF_RCK
#define RF_RCK		0x1d
#endif
#ifndef RF_MODE_TABLE_ADDR
#define RF_MODE_TABLE_ADDR	0x30
#endif
#ifndef RF_MODE_TABLE_DATA0
#define RF_MODE_TABLE_DATA0	0x31
#endif
#ifndef RF_MODE_TABLE_DATA1
#define RF_MODE_TABLE_DATA1	0x32
#endif
#ifndef RF_LUTWA
#define RF_LUTWA	0x33
#endif
#ifndef RF_LUTWD1
#define RF_LUTWD1	0x3e
#endif
#ifndef RF_LUTWD0
#define RF_LUTWD0	0x3f
#endif
#ifndef BIT_GAIN_EXT
#define BIT_GAIN_EXT	BIT(12)
#endif
#ifndef BIT_DATA_L
#define BIT_DATA_L	GENMASK(11, 0)
#endif
#ifndef RF_T_METER
#define RF_T_METER	0x42
#endif
#ifndef RF_BSPAD
#define RF_BSPAD	0x54
#endif
#ifndef RF_GAINTX
#define RF_GAINTX	0x56
#endif
#ifndef RF_TXMOD
#define RF_TXMOD	0x58
#endif
#ifndef RF_TXATANK
#define RF_TXATANK	0x64
#endif
#ifndef RF_TXA_PREPAD
#define RF_TXA_PREPAD	0x65
#endif
#ifndef RF_TRXIQ
#define RF_TRXIQ	0x66
#endif
#ifndef RF_RXIQGEN
#define RF_RXIQGEN	0x8d
#endif
#ifndef RF_RXBB2
#define RF_RXBB2	0x8f
#endif
#ifndef RF_SYN_PFD
#define RF_SYN_PFD	0xb0
#endif
#ifndef RF_LCK
#define RF_LCK		0xb4
#endif
#ifndef RF_XTALX2
#define RF_XTALX2	0xb8
#endif
#ifndef RF_SYN_CTRL
#define RF_SYN_CTRL	0xbb
#endif
#ifndef RF_MALSEL
#define RF_MALSEL	0xbe
#endif
#ifndef RF_SYN_AAC
#define RF_SYN_AAC	0xc9
#endif
#ifndef RF_AAC_CTRL
#define RF_AAC_CTRL	0xca
#endif
#ifndef RF_FAST_LCK
#define RF_FAST_LCK	0xcc
#endif
#ifndef RF_RCKD
#define RF_RCKD		0xde
#endif
#ifndef RF_TXADBG
#define RF_TXADBG	0xde
#endif
#ifndef RF_LUTDBG
#define RF_LUTDBG	0xdf
#endif
#ifndef BIT_TXA_TANK
#define BIT_TXA_TANK	BIT(4)
#endif
#ifndef RF_LUTWE2
#define RF_LUTWE2	0xee
#endif
#ifndef RF_LUTWE
#define RF_LUTWE	0xef
#endif
#ifndef LTE_COEX_CTRL
#define LTE_COEX_CTRL	0x38
#endif
#ifndef LTE_WL_TRX_CTRL
#define LTE_WL_TRX_CTRL	0xa0
#endif
#ifndef LTE_BT_TRX_CTRL
#define LTE_BT_TRX_CTRL	0xa4
#endif

// ---- pci.h ----
#ifndef __RTK_PCI_H_
#define __RTK_PCI_H_
#endif
#ifndef RTK_DEFAULT_TX_DESC_NUM
#define RTK_DEFAULT_TX_DESC_NUM 128
#endif
#ifndef RTK_BEQ_TX_DESC_NUM
#define RTK_BEQ_TX_DESC_NUM	256
#endif
#ifndef RTK_MAX_RX_DESC_NUM
#define RTK_MAX_RX_DESC_NUM	512
#endif
#ifndef RTK_PCI_RX_BUF_SIZE
#define RTK_PCI_RX_BUF_SIZE	(11454 + 24)
#endif
#ifndef RTK_PCI_CTRL
#define RTK_PCI_CTRL		0x300
#endif
#ifndef BIT_RST_TRXDMA_INTF
#define BIT_RST_TRXDMA_INTF	BIT(20)
#endif
#ifndef BIT_RX_TAG_EN
#define BIT_RX_TAG_EN		BIT(15)
#endif
#ifndef REG_DBI_WDATA_V1
#define REG_DBI_WDATA_V1	0x03E8
#endif
#ifndef REG_DBI_RDATA_V1
#define REG_DBI_RDATA_V1	0x03EC
#endif
#ifndef REG_DBI_FLAG_V1
#define REG_DBI_FLAG_V1		0x03F0
#endif
#ifndef BIT_DBI_RFLAG
#define BIT_DBI_RFLAG		BIT(17)
#endif
#ifndef BIT_DBI_WFLAG
#define BIT_DBI_WFLAG		BIT(16)
#endif
#ifndef BITS_DBI_WREN
#define BITS_DBI_WREN		GENMASK(15, 12)
#endif
#ifndef BITS_DBI_ADDR_MASK
#define BITS_DBI_ADDR_MASK	GENMASK(11, 2)
#endif
#ifndef REG_MDIO_V1
#define REG_MDIO_V1		0x03F4
#endif
#ifndef REG_PCIE_MIX_CFG
#define REG_PCIE_MIX_CFG	0x03F8
#endif
#ifndef BITS_MDIO_ADDR_MASK
#define BITS_MDIO_ADDR_MASK	GENMASK(4, 0)
#endif
#ifndef BIT_MDIO_WFLAG_V1
#define BIT_MDIO_WFLAG_V1	BIT(5)
#endif
#ifndef RTW_PCI_MDIO_PG_SZ
#define RTW_PCI_MDIO_PG_SZ	BIT(5)
#endif
#ifndef RTW_PCI_MDIO_PG_OFFS_G1
#define RTW_PCI_MDIO_PG_OFFS_G1	0
#endif
#ifndef RTW_PCI_MDIO_PG_OFFS_G2
#define RTW_PCI_MDIO_PG_OFFS_G2	2
#endif
#ifndef RTW_PCI_WR_RETRY_CNT
#define RTW_PCI_WR_RETRY_CNT	20
#endif
#ifndef RTK_PCIE_LINK_CFG
#define RTK_PCIE_LINK_CFG	0x0719
#endif
#ifndef BIT_CLKREQ_SW_EN
#define BIT_CLKREQ_SW_EN	BIT(4)
#endif
#ifndef BIT_L1_SW_EN
#define BIT_L1_SW_EN		BIT(3)
#endif
#ifndef BIT_CLKREQ_N_PAD
#define BIT_CLKREQ_N_PAD	BIT(0)
#endif
#ifndef RTK_PCIE_CLKDLY_CTRL
#define RTK_PCIE_CLKDLY_CTRL	0x0725
#endif
#ifndef BIT_PCI_BCNQ_FLAG
#define BIT_PCI_BCNQ_FLAG	BIT(4)
#endif
#ifndef RTK_PCI_TXBD_DESA_BCNQ
#define RTK_PCI_TXBD_DESA_BCNQ	0x308
#endif
#ifndef RTK_PCI_TXBD_DESA_H2CQ
#define RTK_PCI_TXBD_DESA_H2CQ	0x1320
#endif
#ifndef RTK_PCI_TXBD_DESA_MGMTQ
#define RTK_PCI_TXBD_DESA_MGMTQ	0x310
#endif
#ifndef RTK_PCI_TXBD_DESA_BKQ
#define RTK_PCI_TXBD_DESA_BKQ	0x330
#endif
#ifndef RTK_PCI_TXBD_DESA_BEQ
#define RTK_PCI_TXBD_DESA_BEQ	0x328
#endif
#ifndef RTK_PCI_TXBD_DESA_VIQ
#define RTK_PCI_TXBD_DESA_VIQ	0x320
#endif
#ifndef RTK_PCI_TXBD_DESA_VOQ
#define RTK_PCI_TXBD_DESA_VOQ	0x318
#endif
#ifndef RTK_PCI_TXBD_DESA_HI0Q
#define RTK_PCI_TXBD_DESA_HI0Q	0x340
#endif
#ifndef RTK_PCI_RXBD_DESA_MPDUQ
#define RTK_PCI_RXBD_DESA_MPDUQ	0x338
#endif
#ifndef TRX_BD_IDX_MASK
#define TRX_BD_IDX_MASK		GENMASK(11, 0)
#endif
#ifndef TRX_BD_HW_IDX_MASK
#define TRX_BD_HW_IDX_MASK	GENMASK(27, 16)
#endif
#ifndef RTK_PCI_TXBD_NUM_H2CQ
#define RTK_PCI_TXBD_NUM_H2CQ	0x1328
#endif
#ifndef RTK_PCI_TXBD_NUM_MGMTQ
#define RTK_PCI_TXBD_NUM_MGMTQ	0x380
#endif
#ifndef RTK_PCI_TXBD_NUM_BKQ
#define RTK_PCI_TXBD_NUM_BKQ	0x38A
#endif
#ifndef RTK_PCI_TXBD_NUM_BEQ
#define RTK_PCI_TXBD_NUM_BEQ	0x388
#endif
#ifndef RTK_PCI_TXBD_NUM_VIQ
#define RTK_PCI_TXBD_NUM_VIQ	0x386
#endif
#ifndef RTK_PCI_TXBD_NUM_VOQ
#define RTK_PCI_TXBD_NUM_VOQ	0x384
#endif
#ifndef RTK_PCI_TXBD_NUM_HI0Q
#define RTK_PCI_TXBD_NUM_HI0Q	0x38C
#endif
#ifndef RTK_PCI_RXBD_NUM_MPDUQ
#define RTK_PCI_RXBD_NUM_MPDUQ	0x382
#endif
#ifndef RTK_PCI_TXBD_IDX_H2CQ
#define RTK_PCI_TXBD_IDX_H2CQ	0x132C
#endif
#ifndef RTK_PCI_TXBD_IDX_MGMTQ
#define RTK_PCI_TXBD_IDX_MGMTQ	0x3B0
#endif
#ifndef RTK_PCI_TXBD_IDX_BKQ
#define RTK_PCI_TXBD_IDX_BKQ	0x3AC
#endif
#ifndef RTK_PCI_TXBD_IDX_BEQ
#define RTK_PCI_TXBD_IDX_BEQ	0x3A8
#endif
#ifndef RTK_PCI_TXBD_IDX_VIQ
#define RTK_PCI_TXBD_IDX_VIQ	0x3A4
#endif
#ifndef RTK_PCI_TXBD_IDX_VOQ
#define RTK_PCI_TXBD_IDX_VOQ	0x3A0
#endif
#ifndef RTK_PCI_TXBD_IDX_HI0Q
#define RTK_PCI_TXBD_IDX_HI0Q	0x3B8
#endif
#ifndef RTK_PCI_RXBD_IDX_MPDUQ
#define RTK_PCI_RXBD_IDX_MPDUQ	0x3B4
#endif
#ifndef RTK_PCI_TXBD_RWPTR_CLR
#define RTK_PCI_TXBD_RWPTR_CLR	0x39C
#endif
#ifndef RTK_PCI_TXBD_H2CQ_CSR
#define RTK_PCI_TXBD_H2CQ_CSR	0x1330
#endif
#ifndef BIT_CLR_H2CQ_HOST_IDX
#define BIT_CLR_H2CQ_HOST_IDX	BIT(16)
#endif
#ifndef BIT_CLR_H2CQ_HW_IDX
#define BIT_CLR_H2CQ_HW_IDX	BIT(8)
#endif
#ifndef RTK_PCI_HIMR0
#define RTK_PCI_HIMR0		0x0B0
#endif
#ifndef RTK_PCI_HISR0
#define RTK_PCI_HISR0		0x0B4
#endif
#ifndef RTK_PCI_HIMR1
#define RTK_PCI_HIMR1		0x0B8
#endif
#ifndef RTK_PCI_HISR1
#define RTK_PCI_HISR1		0x0BC
#endif
#ifndef RTK_PCI_HIMR2
#define RTK_PCI_HIMR2		0x10B0
#endif
#ifndef RTK_PCI_HISR2
#define RTK_PCI_HISR2		0x10B4
#endif
#ifndef RTK_PCI_HIMR3
#define RTK_PCI_HIMR3		0x10B8
#endif
#ifndef RTK_PCI_HISR3
#define RTK_PCI_HISR3		0x10BC
#endif
#ifndef IMR_TIMER2
#define IMR_TIMER2		BIT(31)
#endif
#ifndef IMR_TIMER1
#define IMR_TIMER1		BIT(30)
#endif
#ifndef IMR_PSTIMEOUT
#define IMR_PSTIMEOUT		BIT(29)
#endif
#ifndef IMR_GTINT4
#define IMR_GTINT4		BIT(28)
#endif
#ifndef IMR_GTINT3
#define IMR_GTINT3		BIT(27)
#endif
#ifndef IMR_TBDER
#define IMR_TBDER		BIT(26)
#endif
#ifndef IMR_TBDOK
#define IMR_TBDOK		BIT(25)
#endif
#ifndef IMR_TSF_BIT32_TOGGLE
#define IMR_TSF_BIT32_TOGGLE	BIT(24)
#endif
#ifndef IMR_BCNDMAINT0
#define IMR_BCNDMAINT0		BIT(20)
#endif
#ifndef IMR_BCNDOK0
#define IMR_BCNDOK0		BIT(16)
#endif
#ifndef IMR_HSISR_IND_ON_INT
#define IMR_HSISR_IND_ON_INT	BIT(15)
#endif
#ifndef IMR_BCNDMAINT_E
#define IMR_BCNDMAINT_E		BIT(14)
#endif
#ifndef IMR_ATIMEND
#define IMR_ATIMEND		BIT(12)
#endif
#ifndef IMR_HISR1_IND_INT
#define IMR_HISR1_IND_INT	BIT(11)
#endif
#ifndef IMR_C2HCMD
#define IMR_C2HCMD		BIT(10)
#endif
#ifndef IMR_CPWM2
#define IMR_CPWM2		BIT(9)
#endif
#ifndef IMR_CPWM
#define IMR_CPWM		BIT(8)
#endif
#ifndef IMR_HIGHDOK
#define IMR_HIGHDOK		BIT(7)
#endif
#ifndef IMR_MGNTDOK
#define IMR_MGNTDOK		BIT(6)
#endif
#ifndef IMR_BKDOK
#define IMR_BKDOK		BIT(5)
#endif
#ifndef IMR_BEDOK
#define IMR_BEDOK		BIT(4)
#endif
#ifndef IMR_VIDOK
#define IMR_VIDOK		BIT(3)
#endif
#ifndef IMR_VODOK
#define IMR_VODOK		BIT(2)
#endif
#ifndef IMR_RDU
#define IMR_RDU			BIT(1)
#endif
#ifndef IMR_ROK
#define IMR_ROK			BIT(0)
#endif
#ifndef IMR_TXFIFO_TH_INT
#define IMR_TXFIFO_TH_INT	BIT(30)
#endif
#ifndef IMR_BTON_STS_UPDATE
#define IMR_BTON_STS_UPDATE	BIT(29)
#endif
#ifndef IMR_MCUERR
#define IMR_MCUERR		BIT(28)
#endif
#ifndef IMR_BCNDMAINT7
#define IMR_BCNDMAINT7		BIT(27)
#endif
#ifndef IMR_BCNDMAINT6
#define IMR_BCNDMAINT6		BIT(26)
#endif
#ifndef IMR_BCNDMAINT5
#define IMR_BCNDMAINT5		BIT(25)
#endif
#ifndef IMR_BCNDMAINT4
#define IMR_BCNDMAINT4		BIT(24)
#endif
#ifndef IMR_BCNDMAINT3
#define IMR_BCNDMAINT3		BIT(23)
#endif
#ifndef IMR_BCNDMAINT2
#define IMR_BCNDMAINT2		BIT(22)
#endif
#ifndef IMR_BCNDMAINT1
#define IMR_BCNDMAINT1		BIT(21)
#endif
#ifndef IMR_BCNDOK7
#define IMR_BCNDOK7		BIT(20)
#endif
#ifndef IMR_BCNDOK6
#define IMR_BCNDOK6		BIT(19)
#endif
#ifndef IMR_BCNDOK5
#define IMR_BCNDOK5		BIT(18)
#endif
#ifndef IMR_BCNDOK4
#define IMR_BCNDOK4		BIT(17)
#endif
#ifndef IMR_BCNDOK3
#define IMR_BCNDOK3		BIT(16)
#endif
#ifndef IMR_BCNDOK2
#define IMR_BCNDOK2		BIT(15)
#endif
#ifndef IMR_BCNDOK1
#define IMR_BCNDOK1		BIT(14)
#endif
#ifndef IMR_ATIMEND_E
#define IMR_ATIMEND_E		BIT(13)
#endif
#ifndef IMR_ATIMEND
#define IMR_ATIMEND		BIT(12)
#endif
#ifndef IMR_TXERR
#define IMR_TXERR		BIT(11)
#endif
#ifndef IMR_RXERR
#define IMR_RXERR		BIT(10)
#endif
#ifndef IMR_TXFOVW
#define IMR_TXFOVW		BIT(9)
#endif
#ifndef IMR_RXFOVW
#define IMR_RXFOVW		BIT(8)
#endif
#ifndef IMR_CPU_MGQ_TXDONE
#define IMR_CPU_MGQ_TXDONE	BIT(5)
#endif
#ifndef IMR_PS_TIMER_C
#define IMR_PS_TIMER_C		BIT(4)
#endif
#ifndef IMR_PS_TIMER_B
#define IMR_PS_TIMER_B		BIT(3)
#endif
#ifndef IMR_PS_TIMER_A
#define IMR_PS_TIMER_A		BIT(2)
#endif
#ifndef IMR_CPUMGQ_TX_TIMER
#define IMR_CPUMGQ_TX_TIMER	BIT(1)
#endif
#ifndef IMR_H2CDOK
#define IMR_H2CDOK		BIT(16)
#endif
#ifndef RTK_PCI_TXBD_OWN_OFFSET
#define RTK_PCI_TXBD_OWN_OFFSET 15
#endif
#ifndef RTK_PCI_TXBD_BCN_WORK
#define RTK_PCI_TXBD_BCN_WORK	0x383
#endif
#ifndef RX_TAG_MAX
#define RX_TAG_MAX	8192
#endif

// ---- phy.h ----
#ifndef RTW_DECL_TABLE_PHY_COND_CORE
#define RTW_DECL_TABLE_PHY_COND_CORE(name, cfg, path)	\
const struct rtw_table name ## _tbl = {			\
	.data = name,					\
	.size = ARRAY_SIZE(name),			\
	.parse = rtw_parse_tbl_phy_cond,		\
	.do_cfg = cfg,					\
	.rf_path = path,				\
}
#endif
#ifndef RTW_DECL_TABLE_PHY_COND
#define RTW_DECL_TABLE_PHY_COND(name, cfg)		\
	RTW_DECL_TABLE_PHY_COND_CORE(name, cfg, 0)
#endif
#ifndef RTW_DECL_TABLE_RF_RADIO
#define RTW_DECL_TABLE_RF_RADIO(name, path)		\
	RTW_DECL_TABLE_PHY_COND_CORE(name, rtw_phy_cfg_rf, RF_PATH_ ## path)
#endif
#ifndef RTW_DECL_TABLE_BB_PG
#define RTW_DECL_TABLE_BB_PG(name)			\
const struct rtw_table name ## _tbl = {			\
	.data = name,					\
	.size = ARRAY_SIZE(name),			\
	.parse = rtw_parse_tbl_bb_pg,			\
}
#endif
#ifndef RTW_DECL_TABLE_TXPWR_LMT
#define RTW_DECL_TABLE_TXPWR_LMT(name)			\
const struct rtw_table name ## _tbl = {			\
	.data = name,					\
	.size = ARRAY_SIZE(name),			\
	.parse = rtw_parse_tbl_txpwr_lmt,		\
}
#endif
#ifndef MASKBYTE0
#define	MASKBYTE0		0xff
#endif
#ifndef MASKBYTE1
#define	MASKBYTE1		0xff00
#endif
#ifndef MASKBYTE2
#define	MASKBYTE2		0xff0000
#endif
#ifndef MASKBYTE3
#define	MASKBYTE3		0xff000000
#endif
#ifndef MASKHWORD
#define	MASKHWORD		0xffff0000
#endif
#ifndef MASKLWORD
#define	MASKLWORD		0x0000ffff
#endif
#ifndef MASKDWORD
#define	MASKDWORD		0xffffffff
#endif
#ifndef RFREG_MASK
#define RFREG_MASK		0xfffff
#endif
#ifndef MASK7BITS
#define	MASK7BITS		0x7f
#endif
#ifndef MASK12BITS
#define	MASK12BITS		0xfff
#endif
#ifndef MASKH4BITS
#define	MASKH4BITS		0xf0000000
#endif
#ifndef MASK20BITS
#define	MASK20BITS		0xfffff
#endif
#ifndef MASK24BITS
#define	MASK24BITS		0xffffff
#endif
#ifndef MASKH3BYTES
#define MASKH3BYTES		0xffffff00
#endif
#ifndef MASKL3BYTES
#define MASKL3BYTES		0x00ffffff
#endif
#ifndef MASKBYTE2HIGHNIBBLE
#define MASKBYTE2HIGHNIBBLE	0x00f00000
#endif
#ifndef MASKBYTE3LOWNIBBLE
#define MASKBYTE3LOWNIBBLE	0x0f000000
#endif
#ifndef MASKL3BYTES
#define	MASKL3BYTES		0x00ffffff
#endif
#ifndef CCK_FA_AVG_RESET
#define CCK_FA_AVG_RESET 0xffffffff
#endif
#ifndef LSSI_READ_ADDR_MASK
#define LSSI_READ_ADDR_MASK	0x7f800000
#endif
#ifndef LSSI_READ_EDGE_MASK
#define LSSI_READ_EDGE_MASK	0x80000000
#endif
#ifndef LSSI_READ_DATA_MASK
#define LSSI_READ_DATA_MASK	0xfffff
#endif
#ifndef RRSR_RATE_ORDER_MAX
#define RRSR_RATE_ORDER_MAX	0xfffff
#endif
#ifndef RRSR_RATE_ORDER_CCK_LEN
#define RRSR_RATE_ORDER_CCK_LEN	4
#endif

// ---- mac.h ----
#ifndef RTW_HW_PORT_NUM
#define RTW_HW_PORT_NUM		5
#endif
#ifndef cut_version_to_mask
#define cut_version_to_mask(cut) (0x1 << ((cut) + 1))
#endif
#ifndef DDMA_POLLING_COUNT
#define DDMA_POLLING_COUNT	1000
#endif
#ifndef C2H_PKT_BUF
#define C2H_PKT_BUF		256
#endif
#ifndef REPORT_BUF
#define REPORT_BUF		128
#endif
#ifndef PHY_STATUS_SIZE
#define PHY_STATUS_SIZE		4
#endif
#ifndef ILLEGAL_KEY_GROUP
#define ILLEGAL_KEY_GROUP	0xFAAAAA00
#endif
#ifndef OCPBASE_RXBUF_FW_88XX
#define OCPBASE_RXBUF_FW_88XX		0x18680000
#endif
#ifndef OCPBASE_TXBUF_88XX
#define OCPBASE_TXBUF_88XX		0x18780000
#endif
#ifndef OCPBASE_ROM_88XX
#define OCPBASE_ROM_88XX		0x00000000
#endif
#ifndef OCPBASE_IMEM_88XX
#define OCPBASE_IMEM_88XX		0x00030000
#endif
#ifndef OCPBASE_DMEM_88XX
#define OCPBASE_DMEM_88XX		0x00200000
#endif
#ifndef OCPBASE_EMEM_88XX
#define OCPBASE_EMEM_88XX		0x00100000
#endif
#ifndef RSVD_PG_DRV_NUM
#define RSVD_PG_DRV_NUM			16
#endif
#ifndef RSVD_PG_H2C_EXTRAINFO_NUM
#define RSVD_PG_H2C_EXTRAINFO_NUM	24
#endif
#ifndef RSVD_PG_H2C_STATICINFO_NUM
#define RSVD_PG_H2C_STATICINFO_NUM	8
#endif
#ifndef RSVD_PG_H2CQ_NUM
#define RSVD_PG_H2CQ_NUM		8
#endif
#ifndef RSVD_PG_CPU_INSTRUCTION_NUM
#define RSVD_PG_CPU_INSTRUCTION_NUM	0
#endif
#ifndef RSVD_PG_FW_TXBUF_NUM
#define RSVD_PG_FW_TXBUF_NUM		4
#endif

// ---- rx.h ----
#ifndef RTW_RX_DESC_W0_PKT_LEN
#define RTW_RX_DESC_W0_PKT_LEN		GENMASK(13, 0)
#endif
#ifndef RTW_RX_DESC_W0_CRC32
#define RTW_RX_DESC_W0_CRC32		BIT(14)
#endif
#ifndef RTW_RX_DESC_W0_ICV_ERR
#define RTW_RX_DESC_W0_ICV_ERR		BIT(15)
#endif
#ifndef RTW_RX_DESC_W0_DRV_INFO_SIZE
#define RTW_RX_DESC_W0_DRV_INFO_SIZE	GENMASK(19, 16)
#endif
#ifndef RTW_RX_DESC_W0_ENC_TYPE
#define RTW_RX_DESC_W0_ENC_TYPE		GENMASK(22, 20)
#endif
#ifndef RTW_RX_DESC_W0_SHIFT
#define RTW_RX_DESC_W0_SHIFT		GENMASK(25, 24)
#endif
#ifndef RTW_RX_DESC_W0_PHYST
#define RTW_RX_DESC_W0_PHYST		BIT(26)
#endif
#ifndef RTW_RX_DESC_W0_SWDEC
#define RTW_RX_DESC_W0_SWDEC		BIT(27)
#endif
#ifndef RTW_RX_DESC_W0_EOR
#define RTW_RX_DESC_W0_EOR		BIT(30)
#endif
#ifndef RTW_RX_DESC_W0_OWN
#define RTW_RX_DESC_W0_OWN		BIT(31)
#endif
#ifndef RTW_RX_DESC_W1_MACID
#define RTW_RX_DESC_W1_MACID		GENMASK(6, 0)
#endif
#ifndef RTW_RX_DESC_W2_C2H
#define RTW_RX_DESC_W2_C2H		BIT(28)
#endif
#ifndef RTW_RX_DESC_W2_PPDU_CNT
#define RTW_RX_DESC_W2_PPDU_CNT		GENMASK(30, 29)
#endif
#ifndef RTW_RX_DESC_W3_RX_RATE
#define RTW_RX_DESC_W3_RX_RATE		GENMASK(6, 0)
#endif
#ifndef RTW_RX_DESC_W4_BW
#define RTW_RX_DESC_W4_BW		GENMASK(5, 4)
#endif
#ifndef RTW_RX_DESC_W5_TSFL
#define RTW_RX_DESC_W5_TSFL		GENMASK(31, 0)
#endif
#ifndef RTW_RX_DESC_W6_BUF_ADDR
#define RTW_RX_DESC_W6_BUF_ADDR		GENMASK(31, 0)
#endif

// ---- tx.h ----
#ifndef RTK_TX_MAX_AGG_NUM_MASK
#define RTK_TX_MAX_AGG_NUM_MASK		0x1f
#endif
#ifndef RTW_TX_PROBE_TIMEOUT_SHORT
#define RTW_TX_PROBE_TIMEOUT_SHORT	msecs_to_jiffies(500)
#endif
#ifndef RTW_TX_PROBE_TIMEOUT_LONG
#define RTW_TX_PROBE_TIMEOUT_LONG	msecs_to_jiffies(2500)
#endif
#ifndef RTW_TX_DESC_W0_TXPKTSIZE
#define RTW_TX_DESC_W0_TXPKTSIZE GENMASK(15, 0)
#endif
#ifndef RTW_TX_DESC_W0_OFFSET
#define RTW_TX_DESC_W0_OFFSET GENMASK(23, 16)
#endif
#ifndef RTW_TX_DESC_W0_BMC
#define RTW_TX_DESC_W0_BMC BIT(24)
#endif
#ifndef RTW_TX_DESC_W0_LS
#define RTW_TX_DESC_W0_LS BIT(26)
#endif
#ifndef RTW_TX_DESC_W0_FS
#define RTW_TX_DESC_W0_FS BIT(27)
#endif
#ifndef RTW_TX_DESC_W0_DISQSELSEQ
#define RTW_TX_DESC_W0_DISQSELSEQ BIT(31)
#endif
#ifndef RTW_TX_DESC_W0_OWN
#define RTW_TX_DESC_W0_OWN BIT(31)
#endif
#ifndef RTW_TX_DESC_W1_MACID
#define RTW_TX_DESC_W1_MACID GENMASK(7, 0)
#endif
#ifndef RTW_TX_DESC_W1_QSEL
#define RTW_TX_DESC_W1_QSEL GENMASK(12, 8)
#endif
#ifndef RTW_TX_DESC_W1_RATE_ID
#define RTW_TX_DESC_W1_RATE_ID GENMASK(20, 16)
#endif
#ifndef RTW_TX_DESC_W1_SEC_TYPE
#define RTW_TX_DESC_W1_SEC_TYPE GENMASK(23, 22)
#endif
#ifndef RTW_TX_DESC_W1_PKT_OFFSET
#define RTW_TX_DESC_W1_PKT_OFFSET GENMASK(28, 24)
#endif
#ifndef RTW_TX_DESC_W1_MORE_DATA
#define RTW_TX_DESC_W1_MORE_DATA BIT(29)
#endif
#ifndef RTW_TX_DESC_W2_AGG_EN
#define RTW_TX_DESC_W2_AGG_EN BIT(12)
#endif
#ifndef RTW_TX_DESC_W2_SPE_RPT
#define RTW_TX_DESC_W2_SPE_RPT BIT(19)
#endif
#ifndef RTW_TX_DESC_W2_AMPDU_DEN
#define RTW_TX_DESC_W2_AMPDU_DEN GENMASK(22, 20)
#endif
#ifndef RTW_TX_DESC_W2_BT_NULL
#define RTW_TX_DESC_W2_BT_NULL BIT(23)
#endif
#ifndef RTW_TX_DESC_W3_HW_SSN_SEL
#define RTW_TX_DESC_W3_HW_SSN_SEL GENMASK(7, 6)
#endif
#ifndef RTW_TX_DESC_W3_USE_RATE
#define RTW_TX_DESC_W3_USE_RATE BIT(8)
#endif
#ifndef RTW_TX_DESC_W3_DISDATAFB
#define RTW_TX_DESC_W3_DISDATAFB BIT(10)
#endif
#ifndef RTW_TX_DESC_W3_USE_RTS
#define RTW_TX_DESC_W3_USE_RTS BIT(12)
#endif
#ifndef RTW_TX_DESC_W3_NAVUSEHDR
#define RTW_TX_DESC_W3_NAVUSEHDR BIT(15)
#endif
#ifndef RTW_TX_DESC_W3_MAX_AGG_NUM
#define RTW_TX_DESC_W3_MAX_AGG_NUM GENMASK(21, 17)
#endif
#ifndef RTW_TX_DESC_W4_DATARATE
#define RTW_TX_DESC_W4_DATARATE GENMASK(6, 0)
#endif
#ifndef RTW_TX_DESC_W4_DATARATE_FB_LIMIT
#define RTW_TX_DESC_W4_DATARATE_FB_LIMIT GENMASK(12, 8)
#endif
#ifndef RTW_TX_DESC_W4_RTSRATE
#define RTW_TX_DESC_W4_RTSRATE GENMASK(28, 24)
#endif
#ifndef RTW_TX_DESC_W5_DATA_SHORT
#define RTW_TX_DESC_W5_DATA_SHORT BIT(4)
#endif
#ifndef RTW_TX_DESC_W5_DATA_BW
#define RTW_TX_DESC_W5_DATA_BW GENMASK(6, 5)
#endif
#ifndef RTW_TX_DESC_W5_DATA_LDPC
#define RTW_TX_DESC_W5_DATA_LDPC BIT(7)
#endif
#ifndef RTW_TX_DESC_W5_DATA_STBC
#define RTW_TX_DESC_W5_DATA_STBC GENMASK(9, 8)
#endif
#ifndef RTW_TX_DESC_W5_DATA_RTS_SHORT
#define RTW_TX_DESC_W5_DATA_RTS_SHORT BIT(12)
#endif
#ifndef RTW_TX_DESC_W6_SW_DEFINE
#define RTW_TX_DESC_W6_SW_DEFINE GENMASK(11, 0)
#endif
#ifndef RTW_TX_DESC_W7_TXDESC_CHECKSUM
#define RTW_TX_DESC_W7_TXDESC_CHECKSUM GENMASK(15, 0)
#endif
#ifndef RTW_TX_DESC_W7_TX_BUFFER_SIZE
#define RTW_TX_DESC_W7_TX_BUFFER_SIZE GENMASK(15, 0)
#endif
#ifndef RTW_TX_DESC_W7_DMA_TXAGG_NUM
#define RTW_TX_DESC_W7_DMA_TXAGG_NUM GENMASK(31, 24)
#endif
#ifndef RTW_TX_DESC_W8_EN_HWSEQ
#define RTW_TX_DESC_W8_EN_HWSEQ BIT(15)
#endif
#ifndef RTW_TX_DESC_W9_SW_SEQ
#define RTW_TX_DESC_W9_SW_SEQ GENMASK(23, 12)
#endif
#ifndef RTW_TX_DESC_W9_TIM_EN
#define RTW_TX_DESC_W9_TIM_EN BIT(7)
#endif
#ifndef RTW_TX_DESC_W9_TIM_OFFSET
#define RTW_TX_DESC_W9_TIM_OFFSET GENMASK(6, 0)
#endif
#ifndef RTW_TX_DESC_W10_TX_BUFFER_ADDRESS
#define RTW_TX_DESC_W10_TX_BUFFER_ADDRESS GENMASK(31, 0)
#endif
#ifndef RTW_TX_DESC_W12_NEXT_DESC_ADDRESS
#define RTW_TX_DESC_W12_NEXT_DESC_ADDRESS GENMASK(31, 0)
#endif

// ---- sec.h ----
#ifndef RTW_SEC_CMD_REG
#define RTW_SEC_CMD_REG			0x670
#endif
#ifndef RTW_SEC_WRITE_REG
#define RTW_SEC_WRITE_REG		0x674
#endif
#ifndef RTW_SEC_READ_REG
#define RTW_SEC_READ_REG		0x678
#endif
#ifndef RTW_SEC_CONFIG
#define RTW_SEC_CONFIG			0x680
#endif
#ifndef RTW_SEC_CAM_ENTRY_SHIFT
#define RTW_SEC_CAM_ENTRY_SHIFT		3
#endif
#ifndef RTW_SEC_DEFAULT_KEY_NUM
#define RTW_SEC_DEFAULT_KEY_NUM		4
#endif
#ifndef RTW_SEC_CMD_WRITE_ENABLE
#define RTW_SEC_CMD_WRITE_ENABLE	BIT(16)
#endif
#ifndef RTW_SEC_CMD_CLEAR
#define RTW_SEC_CMD_CLEAR		BIT(30)
#endif
#ifndef RTW_SEC_CMD_POLLING
#define RTW_SEC_CMD_POLLING		BIT(31)
#endif
#ifndef RTW_SEC_TX_UNI_USE_DK
#define RTW_SEC_TX_UNI_USE_DK		BIT(0)
#endif
#ifndef RTW_SEC_RX_UNI_USE_DK
#define RTW_SEC_RX_UNI_USE_DK		BIT(1)
#endif
#ifndef RTW_SEC_TX_DEC_EN
#define RTW_SEC_TX_DEC_EN		BIT(2)
#endif
#ifndef RTW_SEC_RX_DEC_EN
#define RTW_SEC_RX_DEC_EN		BIT(3)
#endif
#ifndef RTW_SEC_TX_BC_USE_DK
#define RTW_SEC_TX_BC_USE_DK		BIT(6)
#endif
#ifndef RTW_SEC_RX_BC_USE_DK
#define RTW_SEC_RX_BC_USE_DK		BIT(7)
#endif
#ifndef RTW_SEC_ENGINE_EN
#define RTW_SEC_ENGINE_EN		BIT(9)
#endif

// ---- fw.h ----
#ifndef H2C_PKT_SIZE
#define H2C_PKT_SIZE		32
#endif
#ifndef H2C_PKT_HDR_SIZE
#define H2C_PKT_HDR_SIZE	8
#endif
#ifndef FW_HDR_SIZE
#define FW_HDR_SIZE			64
#endif
#ifndef FW_HDR_CHKSUM_SIZE
#define FW_HDR_CHKSUM_SIZE		8
#endif
#ifndef FW_NLO_INFO_CHECK_SIZE
#define FW_NLO_INFO_CHECK_SIZE		4
#endif
#ifndef FIFO_PAGE_SIZE_SHIFT
#define FIFO_PAGE_SIZE_SHIFT		12
#endif
#ifndef FIFO_PAGE_SIZE
#define FIFO_PAGE_SIZE			4096
#endif
#ifndef FIFO_DUMP_ADDR
#define FIFO_DUMP_ADDR			0x8000
#endif
#ifndef DLFW_PAGE_SIZE_SHIFT_LEGACY
#define DLFW_PAGE_SIZE_SHIFT_LEGACY	12
#endif
#ifndef DLFW_PAGE_SIZE_LEGACY
#define DLFW_PAGE_SIZE_LEGACY		0x1000
#endif
#ifndef DLFW_BLK_SIZE_SHIFT_LEGACY
#define DLFW_BLK_SIZE_SHIFT_LEGACY	2
#endif
#ifndef DLFW_BLK_SIZE_LEGACY
#define DLFW_BLK_SIZE_LEGACY		4
#endif
#ifndef FW_START_ADDR_LEGACY
#define FW_START_ADDR_LEGACY		0x1000
#endif
#ifndef BCN_LOSS_CNT
#define BCN_LOSS_CNT			10
#endif
#ifndef BCN_FILTER_NOTIFY_SIGNAL_CHANGE
#define BCN_FILTER_NOTIFY_SIGNAL_CHANGE	0
#endif
#ifndef BCN_FILTER_CONNECTION_LOSS
#define BCN_FILTER_CONNECTION_LOSS	1
#endif
#ifndef BCN_FILTER_CONNECTED
#define BCN_FILTER_CONNECTED		2
#endif
#ifndef BCN_FILTER_NOTIFY_BEACON_LOSS
#define BCN_FILTER_NOTIFY_BEACON_LOSS	3
#endif
#ifndef RTW_DEFAULT_CQM_THOLD
#define RTW_DEFAULT_CQM_THOLD		-70
#endif
#ifndef RTW_DEFAULT_CQM_HYST
#define RTW_DEFAULT_CQM_HYST		4
#endif
#ifndef SCAN_NOTIFY_TIMEOUT
#define SCAN_NOTIFY_TIMEOUT  msecs_to_jiffies(10)
#endif
#ifndef RTW_CHANNEL_TIME
#define RTW_CHANNEL_TIME		45
#endif
#ifndef RTW_OFF_CHAN_TIME
#define RTW_OFF_CHAN_TIME		100
#endif
#ifndef RTW_PASS_CHAN_TIME
#define RTW_PASS_CHAN_TIME		105
#endif
#ifndef RTW_DFS_CHAN_TIME
#define RTW_DFS_CHAN_TIME		20
#endif
#ifndef RTW_CH_INFO_SIZE
#define RTW_CH_INFO_SIZE		4
#endif
#ifndef RTW_EX_CH_INFO_SIZE
#define RTW_EX_CH_INFO_SIZE		3
#endif
#ifndef RTW_EX_CH_INFO_HDR_SIZE
#define RTW_EX_CH_INFO_HDR_SIZE		2
#endif
#ifndef RTW_SCAN_WIDTH
#define RTW_SCAN_WIDTH			0
#endif
#ifndef RTW_PRI_CH_IDX
#define RTW_PRI_CH_IDX			1
#endif
#ifndef RTW_OLD_PROBE_PG_CNT
#define RTW_OLD_PROBE_PG_CNT		2
#endif
#ifndef RTW_PROBE_PG_CNT
#define RTW_PROBE_PG_CNT		4
#endif
#ifndef RTW_DEBUG_DUMP_TIMES
#define RTW_DEBUG_DUMP_TIMES		10
#endif
#ifndef RTW_C2H_RA_RPT_RATE
#define RTW_C2H_RA_RPT_RATE	GENMASK(6, 0)
#endif
#ifndef RTW_C2H_RA_RPT_SGI
#define RTW_C2H_RA_RPT_SGI	BIT(7)
#endif
#ifndef RTW_H2C_W0_CMDID
#define RTW_H2C_W0_CMDID		GENMASK(7, 0)
#endif
#ifndef RTW_H2C_DEFAULT_PORT_W0_PORTID
#define RTW_H2C_DEFAULT_PORT_W0_PORTID	GENMASK(15, 8)
#endif
#ifndef RTW_H2C_DEFAULT_PORT_W0_MACID
#define RTW_H2C_DEFAULT_PORT_W0_MACID	GENMASK(23, 16)
#endif
#ifndef RTW_FW_VER_CODE
#define RTW_FW_VER_CODE(ver, sub_ver, idx)	\
	(((ver) << 16) | ((sub_ver) << 8) | (idx))
#endif
#ifndef RTW_FW_SUIT_VER_CODE
#define RTW_FW_SUIT_VER_CODE(s)	\
	RTW_FW_VER_CODE((s).version, (s).sub_version, (s).sub_index)
#endif
#ifndef GET_CCX_REPORT_SEQNUM_V0
#define GET_CCX_REPORT_SEQNUM_V0(c2h_payload)	(c2h_payload[6] & 0xfc)
#endif
#ifndef GET_CCX_REPORT_STATUS_V0
#define GET_CCX_REPORT_STATUS_V0(c2h_payload)	(c2h_payload[0] & 0xc0)
#endif
#ifndef GET_CCX_REPORT_SEQNUM_V1
#define GET_CCX_REPORT_SEQNUM_V1(c2h_payload)	(c2h_payload[8] & 0xfc)
#endif
#ifndef GET_CCX_REPORT_STATUS_V1
#define GET_CCX_REPORT_STATUS_V1(c2h_payload)	(c2h_payload[9] & 0xc0)
#endif
#ifndef GET_SCAN_REPORT_RETURN_CODE
#define GET_SCAN_REPORT_RETURN_CODE(c2h_payload)	(c2h_payload[2] & 0xff)
#endif
#ifndef GET_CHAN_SWITCH_CENTRAL_CH
#define GET_CHAN_SWITCH_CENTRAL_CH(c2h_payload)	(c2h_payload[2])
#endif
#ifndef GET_CHAN_SWITCH_ID
#define GET_CHAN_SWITCH_ID(c2h_payload)		(c2h_payload[3])
#endif
#ifndef GET_CHAN_SWITCH_STATUS
#define GET_CHAN_SWITCH_STATUS(c2h_payload)	(c2h_payload[4])
#endif
#ifndef GET_BCN_FILTER_NOTIFY_TYPE
#define GET_BCN_FILTER_NOTIFY_TYPE(c2h_payload)	(c2h_payload[1] & 0xf)
#endif
#ifndef GET_BCN_FILTER_NOTIFY_EVENT
#define GET_BCN_FILTER_NOTIFY_EVENT(c2h_payload)	(c2h_payload[1] & 0x10)
#endif
#ifndef GET_BCN_FILTER_NOTIFY_RSSI
#define GET_BCN_FILTER_NOTIFY_RSSI(c2h_payload)	(c2h_payload[2] - 100)
#endif
#ifndef H2C_PKT_CMD_ID
#define H2C_PKT_CMD_ID 0xFF
#endif
#ifndef H2C_PKT_CATEGORY
#define H2C_PKT_CATEGORY 0x01
#endif
#ifndef H2C_PKT_GENERAL_INFO
#define H2C_PKT_GENERAL_INFO 0x0D
#endif
#ifndef H2C_PKT_PHYDM_INFO
#define H2C_PKT_PHYDM_INFO 0x11
#endif
#ifndef H2C_PKT_IQK
#define H2C_PKT_IQK 0x0E
#endif
#ifndef H2C_PKT_CH_SWITCH
#define H2C_PKT_CH_SWITCH 0x02
#endif
#ifndef H2C_PKT_UPDATE_PKT
#define H2C_PKT_UPDATE_PKT 0x0C
#endif
#ifndef H2C_PKT_SCAN_OFFLOAD
#define H2C_PKT_SCAN_OFFLOAD 0x19
#endif
#ifndef H2C_PKT_CH_SWITCH_LEN
#define H2C_PKT_CH_SWITCH_LEN 0x20
#endif
#ifndef H2C_PKT_UPDATE_PKT_LEN
#define H2C_PKT_UPDATE_PKT_LEN 0x4
#endif
#ifndef SET_PKT_H2C_CATEGORY
#define SET_PKT_H2C_CATEGORY(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(6, 0))
#endif
#ifndef SET_PKT_H2C_CMD_ID
#define SET_PKT_H2C_CMD_ID(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_PKT_H2C_SUB_CMD_ID
#define SET_PKT_H2C_SUB_CMD_ID(h2c_pkt, value)                                 \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 16))
#endif
#ifndef SET_PKT_H2C_TOTAL_LEN
#define SET_PKT_H2C_TOTAL_LEN(h2c_pkt, value)                                  \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 0))
#endif
#ifndef FW_OFFLOAD_H2C_SET_SEQ_NUM
#define FW_OFFLOAD_H2C_SET_SEQ_NUM(h2c_pkt, value)                             \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(31, 16))
#endif
#ifndef GENERAL_INFO_SET_FW_TX_BOUNDARY
#define GENERAL_INFO_SET_FW_TX_BOUNDARY(h2c_pkt, value)                        \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(23, 16))
#endif
#ifndef PHYDM_INFO_SET_REF_TYPE
#define PHYDM_INFO_SET_REF_TYPE(h2c_pkt, value)                                \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(7, 0))
#endif
#ifndef PHYDM_INFO_SET_RF_TYPE
#define PHYDM_INFO_SET_RF_TYPE(h2c_pkt, value)                                 \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(15, 8))
#endif
#ifndef PHYDM_INFO_SET_CUT_VER
#define PHYDM_INFO_SET_CUT_VER(h2c_pkt, value)                                 \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(23, 16))
#endif
#ifndef PHYDM_INFO_SET_RX_ANT_STATUS
#define PHYDM_INFO_SET_RX_ANT_STATUS(h2c_pkt, value)                           \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(27, 24))
#endif
#ifndef PHYDM_INFO_SET_TX_ANT_STATUS
#define PHYDM_INFO_SET_TX_ANT_STATUS(h2c_pkt, value)                           \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(31, 28))
#endif
#ifndef IQK_SET_CLEAR
#define IQK_SET_CLEAR(h2c_pkt, value)                                          \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(0))
#endif
#ifndef IQK_SET_SEGMENT_IQK
#define IQK_SET_SEGMENT_IQK(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(1))
#endif
#ifndef CHSW_INFO_SET_CH
#define CHSW_INFO_SET_CH(pkt, value)					       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, GENMASK(7, 0))
#endif
#ifndef CHSW_INFO_SET_PRI_CH_IDX
#define CHSW_INFO_SET_PRI_CH_IDX(pkt, value)				       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, GENMASK(11, 8))
#endif
#ifndef CHSW_INFO_SET_BW
#define CHSW_INFO_SET_BW(pkt, value)					       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, GENMASK(15, 12))
#endif
#ifndef CHSW_INFO_SET_TIMEOUT
#define CHSW_INFO_SET_TIMEOUT(pkt, value)				       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef CHSW_INFO_SET_ACTION_ID
#define CHSW_INFO_SET_ACTION_ID(pkt, value)				       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, GENMASK(30, 24))
#endif
#ifndef CHSW_INFO_SET_EXTRA_INFO
#define CHSW_INFO_SET_EXTRA_INFO(pkt, value)				       \
	le32p_replace_bits((__le32 *)(pkt) + 0x00, value, BIT(31))
#endif
#ifndef CH_INFO_SET_CH
#define CH_INFO_SET_CH(pkt, value)					       \
	u8p_replace_bits((u8 *)(pkt) + 0x00, value, GENMASK(7, 0))
#endif
#ifndef CH_INFO_SET_PRI_CH_IDX
#define CH_INFO_SET_PRI_CH_IDX(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x01, value, GENMASK(3, 0))
#endif
#ifndef CH_INFO_SET_BW
#define CH_INFO_SET_BW(pkt, value)					       \
	u8p_replace_bits((u8 *)(pkt) + 0x01, value, GENMASK(7, 4))
#endif
#ifndef CH_INFO_SET_TIMEOUT
#define CH_INFO_SET_TIMEOUT(pkt, value)					       \
	u8p_replace_bits((u8 *)(pkt) + 0x02, value, GENMASK(7, 0))
#endif
#ifndef CH_INFO_SET_ACTION_ID
#define CH_INFO_SET_ACTION_ID(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x03, value, GENMASK(6, 0))
#endif
#ifndef CH_INFO_SET_EXTRA_INFO
#define CH_INFO_SET_EXTRA_INFO(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x03, value, BIT(7))
#endif
#ifndef EXTRA_CH_INFO_SET_ID
#define EXTRA_CH_INFO_SET_ID(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x04, value, GENMASK(6, 0))
#endif
#ifndef EXTRA_CH_INFO_SET_INFO
#define EXTRA_CH_INFO_SET_INFO(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x04, value, BIT(7))
#endif
#ifndef EXTRA_CH_INFO_SET_SIZE
#define EXTRA_CH_INFO_SET_SIZE(pkt, value)				       \
	u8p_replace_bits((u8 *)(pkt) + 0x05, value, GENMASK(7, 0))
#endif
#ifndef EXTRA_CH_INFO_SET_DFS_EXT_TIME
#define EXTRA_CH_INFO_SET_DFS_EXT_TIME(pkt, value)			       \
	u8p_replace_bits((u8 *)(pkt) + 0x06, value, GENMASK(7, 0))
#endif
#ifndef UPDATE_PKT_SET_SIZE
#define UPDATE_PKT_SET_SIZE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(15, 0))
#endif
#ifndef UPDATE_PKT_SET_PKT_ID
#define UPDATE_PKT_SET_PKT_ID(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(23, 16))
#endif
#ifndef UPDATE_PKT_SET_LOCATION
#define UPDATE_PKT_SET_LOCATION(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(31, 24))
#endif
#ifndef CH_SWITCH_SET_START
#define CH_SWITCH_SET_START(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(0))
#endif
#ifndef CH_SWITCH_SET_DEST_CH_EN
#define CH_SWITCH_SET_DEST_CH_EN(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(1))
#endif
#ifndef CH_SWITCH_SET_ABSOLUTE_TIME
#define CH_SWITCH_SET_ABSOLUTE_TIME(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(2))
#endif
#ifndef CH_SWITCH_SET_PERIODIC_OPT
#define CH_SWITCH_SET_PERIODIC_OPT(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(4, 3))
#endif
#ifndef CH_SWITCH_SET_SCAN_MODE
#define CH_SWITCH_SET_SCAN_MODE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(5))
#endif
#ifndef CH_SWITCH_SET_BACK_OP_EN
#define CH_SWITCH_SET_BACK_OP_EN(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(6))
#endif
#ifndef CH_SWITCH_SET_INFO_LOC
#define CH_SWITCH_SET_INFO_LOC(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(15, 8))
#endif
#ifndef CH_SWITCH_SET_CH_NUM
#define CH_SWITCH_SET_CH_NUM(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(23, 16))
#endif
#ifndef CH_SWITCH_SET_PRI_CH_IDX
#define CH_SWITCH_SET_PRI_CH_IDX(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(27, 24))
#endif
#ifndef CH_SWITCH_SET_DEST_BW
#define CH_SWITCH_SET_DEST_BW(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(31, 28))
#endif
#ifndef CH_SWITCH_SET_DEST_CH
#define CH_SWITCH_SET_DEST_CH(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(7, 0))
#endif
#ifndef CH_SWITCH_SET_NORMAL_PERIOD
#define CH_SWITCH_SET_NORMAL_PERIOD(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(13, 8))
#endif
#ifndef CH_SWITCH_SET_NORMAL_PERIOD_SEL
#define CH_SWITCH_SET_NORMAL_PERIOD_SEL(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(15, 14))
#endif
#ifndef CH_SWITCH_SET_SLOW_PERIOD
#define CH_SWITCH_SET_SLOW_PERIOD(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(21, 16))
#endif
#ifndef CH_SWITCH_SET_SLOW_PERIOD_SEL
#define CH_SWITCH_SET_SLOW_PERIOD_SEL(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(23, 22))
#endif
#ifndef CH_SWITCH_SET_NORMAL_CYCLE
#define CH_SWITCH_SET_NORMAL_CYCLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(31, 24))
#endif
#ifndef CH_SWITCH_SET_TSF_HIGH
#define CH_SWITCH_SET_TSF_HIGH(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x04, value, GENMASK(31, 0))
#endif
#ifndef CH_SWITCH_SET_TSF_LOW
#define CH_SWITCH_SET_TSF_LOW(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x05, value, GENMASK(31, 0))
#endif
#ifndef CH_SWITCH_SET_INFO_SIZE
#define CH_SWITCH_SET_INFO_SIZE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x06, value, GENMASK(15, 0))
#endif
#ifndef SCAN_OFFLOAD_SET_START
#define SCAN_OFFLOAD_SET_START(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(0))
#endif
#ifndef SCAN_OFFLOAD_SET_BACK_OP_EN
#define SCAN_OFFLOAD_SET_BACK_OP_EN(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(1))
#endif
#ifndef SCAN_OFFLOAD_SET_RANDOM_SEQ_EN
#define SCAN_OFFLOAD_SET_RANDOM_SEQ_EN(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(2))
#endif
#ifndef SCAN_OFFLOAD_SET_NO_CCK_EN
#define SCAN_OFFLOAD_SET_NO_CCK_EN(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(3))
#endif
#ifndef SCAN_OFFLOAD_SET_VERBOSE
#define SCAN_OFFLOAD_SET_VERBOSE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, BIT(4))
#endif
#ifndef SCAN_OFFLOAD_SET_CH_NUM
#define SCAN_OFFLOAD_SET_CH_NUM(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(15, 8))
#endif
#ifndef SCAN_OFFLOAD_SET_CH_INFO_SIZE
#define SCAN_OFFLOAD_SET_CH_INFO_SIZE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x02, value, GENMASK(31, 16))
#endif
#ifndef SCAN_OFFLOAD_SET_CH_INFO_LOC
#define SCAN_OFFLOAD_SET_CH_INFO_LOC(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(7, 0))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_CH
#define SCAN_OFFLOAD_SET_OP_CH(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(15, 8))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_PRI_CH_IDX
#define SCAN_OFFLOAD_SET_OP_PRI_CH_IDX(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(19, 16))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_BW
#define SCAN_OFFLOAD_SET_OP_BW(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(23, 20))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_PORT_ID
#define SCAN_OFFLOAD_SET_OP_PORT_ID(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x03, value, GENMASK(26, 24))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_DWELL_TIME
#define SCAN_OFFLOAD_SET_OP_DWELL_TIME(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x04, value, GENMASK(15, 0))
#endif
#ifndef SCAN_OFFLOAD_SET_OP_GAP_TIME
#define SCAN_OFFLOAD_SET_OP_GAP_TIME(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x04, value, GENMASK(31, 16))
#endif
#ifndef SCAN_OFFLOAD_SET_MODE
#define SCAN_OFFLOAD_SET_MODE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x05, value, GENMASK(3, 0))
#endif
#ifndef SCAN_OFFLOAD_SET_SSID_NUM
#define SCAN_OFFLOAD_SET_SSID_NUM(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x05, value, GENMASK(7, 4))
#endif
#ifndef SCAN_OFFLOAD_SET_PKT_LOC
#define SCAN_OFFLOAD_SET_PKT_LOC(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x05, value, GENMASK(15, 8))
#endif
#ifndef H2C_CMD_RSVD_PAGE
#define H2C_CMD_RSVD_PAGE		0x0
#endif
#ifndef H2C_CMD_MEDIA_STATUS_RPT
#define H2C_CMD_MEDIA_STATUS_RPT	0x01
#endif
#ifndef H2C_CMD_SET_PWR_MODE
#define H2C_CMD_SET_PWR_MODE		0x20
#endif
#ifndef H2C_CMD_LPS_PG_INFO
#define H2C_CMD_LPS_PG_INFO		0x2b
#endif
#ifndef H2C_CMD_DEFAULT_PORT
#define H2C_CMD_DEFAULT_PORT		0x2c
#endif
#ifndef H2C_CMD_RA_INFO
#define H2C_CMD_RA_INFO			0x40
#endif
#ifndef H2C_CMD_RSSI_MONITOR
#define H2C_CMD_RSSI_MONITOR		0x42
#endif
#ifndef H2C_CMD_RA_INFO_HI
#define H2C_CMD_RA_INFO_HI		0x46
#endif
#ifndef H2C_CMD_BCN_FILTER_OFFLOAD_P0
#define H2C_CMD_BCN_FILTER_OFFLOAD_P0	0x56
#endif
#ifndef H2C_CMD_BCN_FILTER_OFFLOAD_P1
#define H2C_CMD_BCN_FILTER_OFFLOAD_P1	0x57
#endif
#ifndef H2C_CMD_WL_PHY_INFO
#define H2C_CMD_WL_PHY_INFO		0x58
#endif
#ifndef H2C_CMD_SCAN
#define H2C_CMD_SCAN			0x59
#endif
#ifndef H2C_CMD_ADAPTIVITY
#define H2C_CMD_ADAPTIVITY		0x5A
#endif
#ifndef H2C_CMD_COEX_TDMA_TYPE
#define H2C_CMD_COEX_TDMA_TYPE		0x60
#endif
#ifndef H2C_CMD_QUERY_BT_INFO
#define H2C_CMD_QUERY_BT_INFO		0x61
#endif
#ifndef H2C_CMD_FORCE_BT_TX_POWER
#define H2C_CMD_FORCE_BT_TX_POWER	0x62
#endif
#ifndef H2C_CMD_IGNORE_WLAN_ACTION
#define H2C_CMD_IGNORE_WLAN_ACTION	0x63
#endif
#ifndef H2C_CMD_WL_CH_INFO
#define H2C_CMD_WL_CH_INFO		0x66
#endif
#ifndef H2C_CMD_QUERY_BT_MP_INFO
#define H2C_CMD_QUERY_BT_MP_INFO	0x67
#endif
#ifndef H2C_CMD_BT_WIFI_CONTROL
#define H2C_CMD_BT_WIFI_CONTROL		0x69
#endif
#ifndef H2C_CMD_WIFI_CALIBRATION
#define H2C_CMD_WIFI_CALIBRATION	0x6d
#endif
#ifndef H2C_CMD_QUERY_BT_HID_INFO
#define H2C_CMD_QUERY_BT_HID_INFO	0x73
#endif
#ifndef H2C_CMD_KEEP_ALIVE
#define H2C_CMD_KEEP_ALIVE		0x03
#endif
#ifndef H2C_CMD_DISCONNECT_DECISION
#define H2C_CMD_DISCONNECT_DECISION	0x04
#endif
#ifndef H2C_CMD_WOWLAN
#define H2C_CMD_WOWLAN			0x80
#endif
#ifndef H2C_CMD_REMOTE_WAKE_CTRL
#define H2C_CMD_REMOTE_WAKE_CTRL	0x81
#endif
#ifndef H2C_CMD_AOAC_GLOBAL_INFO
#define H2C_CMD_AOAC_GLOBAL_INFO	0x82
#endif
#ifndef H2C_CMD_NLO_INFO
#define H2C_CMD_NLO_INFO		0x8C
#endif
#ifndef H2C_CMD_RECOVER_BT_DEV
#define H2C_CMD_RECOVER_BT_DEV		0xD1
#endif
#ifndef SET_H2C_CMD_ID_CLASS
#define SET_H2C_CMD_ID_CLASS(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(7, 0))
#endif
#ifndef MEDIA_STATUS_RPT_SET_OP_MODE
#define MEDIA_STATUS_RPT_SET_OP_MODE(h2c_pkt, value)                           \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef MEDIA_STATUS_RPT_SET_MACID
#define MEDIA_STATUS_RPT_SET_MACID(h2c_pkt, value)                             \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_WL_PHY_INFO_TX_TP
#define SET_WL_PHY_INFO_TX_TP(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(17, 8))
#endif
#ifndef SET_WL_PHY_INFO_RX_TP
#define SET_WL_PHY_INFO_RX_TP(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(27, 18))
#endif
#ifndef SET_WL_PHY_INFO_TX_RATE_DESC
#define SET_WL_PHY_INFO_TX_RATE_DESC(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_WL_PHY_INFO_RX_RATE_DESC
#define SET_WL_PHY_INFO_RX_RATE_DESC(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef SET_WL_PHY_INFO_RX_EVM
#define SET_WL_PHY_INFO_RX_EVM(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(23, 16))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_MACID
#define SET_BCN_FILTER_OFFLOAD_P1_MACID(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_ENABLE
#define SET_BCN_FILTER_OFFLOAD_P1_ENABLE(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(16))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_HYST
#define SET_BCN_FILTER_OFFLOAD_P1_HYST(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(20, 17))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_OFFLOAD_MODE
#define SET_BCN_FILTER_OFFLOAD_P1_OFFLOAD_MODE(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 21))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_THRESHOLD
#define SET_BCN_FILTER_OFFLOAD_P1_THRESHOLD(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_BCN_LOSS_CNT
#define SET_BCN_FILTER_OFFLOAD_P1_BCN_LOSS_CNT(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(3, 0))
#endif
#ifndef SET_BCN_FILTER_OFFLOAD_P1_BCN_INTERVAL
#define SET_BCN_FILTER_OFFLOAD_P1_BCN_INTERVAL(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(13, 4))
#endif
#ifndef SET_SCAN_START
#define SET_SCAN_START(h2c_pkt, value)					       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_ADAPTIVITY_MODE
#define SET_ADAPTIVITY_MODE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(11, 8))
#endif
#ifndef SET_ADAPTIVITY_OPTION
#define SET_ADAPTIVITY_OPTION(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 12))
#endif
#ifndef SET_ADAPTIVITY_IGI
#define SET_ADAPTIVITY_IGI(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_ADAPTIVITY_L2H
#define SET_ADAPTIVITY_L2H(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_ADAPTIVITY_DENSITY
#define SET_ADAPTIVITY_DENSITY(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_PWR_MODE_SET_MODE
#define SET_PWR_MODE_SET_MODE(h2c_pkt, value)                                  \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(14, 8))
#endif
#ifndef SET_PWR_MODE_SET_RLBM
#define SET_PWR_MODE_SET_RLBM(h2c_pkt, value)                                  \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(19, 16))
#endif
#ifndef SET_PWR_MODE_SET_SMART_PS
#define SET_PWR_MODE_SET_SMART_PS(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 20))
#endif
#ifndef SET_PWR_MODE_SET_AWAKE_INTERVAL
#define SET_PWR_MODE_SET_AWAKE_INTERVAL(h2c_pkt, value)                        \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_PWR_MODE_SET_PORT_ID
#define SET_PWR_MODE_SET_PORT_ID(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 5))
#endif
#ifndef SET_PWR_MODE_SET_PWR_STATE
#define SET_PWR_MODE_SET_PWR_STATE(h2c_pkt, value)                             \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef LPS_PG_INFO_LOC
#define LPS_PG_INFO_LOC(h2c_pkt, value)                                        \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef LPS_PG_DPK_LOC
#define LPS_PG_DPK_LOC(h2c_pkt, value)                                         \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef LPS_PG_SEC_CAM_EN
#define LPS_PG_SEC_CAM_EN(h2c_pkt, value)                                      \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef LPS_PG_PATTERN_CAM_EN
#define LPS_PG_PATTERN_CAM_EN(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(10))
#endif
#ifndef SET_RSSI_INFO_MACID
#define SET_RSSI_INFO_MACID(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_RSSI_INFO_RSSI
#define SET_RSSI_INFO_RSSI(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_RSSI_INFO_STBC
#define SET_RSSI_INFO_STBC(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, BIT(1))
#endif
#ifndef SET_RA_INFO_MACID
#define SET_RA_INFO_MACID(h2c_pkt, value)                                      \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_RA_INFO_RATE_ID
#define SET_RA_INFO_RATE_ID(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(20, 16))
#endif
#ifndef SET_RA_INFO_INIT_RA_LVL
#define SET_RA_INFO_INIT_RA_LVL(h2c_pkt, value)                                \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(22, 21))
#endif
#ifndef SET_RA_INFO_SGI_EN
#define SET_RA_INFO_SGI_EN(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(23))
#endif
#ifndef SET_RA_INFO_BW_MODE
#define SET_RA_INFO_BW_MODE(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(25, 24))
#endif
#ifndef SET_RA_INFO_LDPC
#define SET_RA_INFO_LDPC(h2c_pkt, value)                                       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(26))
#endif
#ifndef SET_RA_INFO_NO_UPDATE
#define SET_RA_INFO_NO_UPDATE(h2c_pkt, value)                                  \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(27))
#endif
#ifndef SET_RA_INFO_VHT_EN
#define SET_RA_INFO_VHT_EN(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(29, 28))
#endif
#ifndef SET_RA_INFO_DIS_PT
#define SET_RA_INFO_DIS_PT(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(30))
#endif
#ifndef SET_RA_INFO_RA_MASK0
#define SET_RA_INFO_RA_MASK0(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_RA_INFO_RA_MASK1
#define SET_RA_INFO_RA_MASK1(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef SET_RA_INFO_RA_MASK2
#define SET_RA_INFO_RA_MASK2(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(23, 16))
#endif
#ifndef SET_RA_INFO_RA_MASK3
#define SET_RA_INFO_RA_MASK3(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(31, 24))
#endif
#ifndef SET_QUERY_BT_INFO
#define SET_QUERY_BT_INFO(h2c_pkt, value)                                      \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_WL_CH_INFO_LINK
#define SET_WL_CH_INFO_LINK(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_WL_CH_INFO_CHNL
#define SET_WL_CH_INFO_CHNL(h2c_pkt, value)                                    \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_WL_CH_INFO_BW
#define SET_WL_CH_INFO_BW(h2c_pkt, value)                                      \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_BT_MP_INFO_SEQ
#define SET_BT_MP_INFO_SEQ(h2c_pkt, value)                                     \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 12))
#endif
#ifndef SET_BT_MP_INFO_OP_CODE
#define SET_BT_MP_INFO_OP_CODE(h2c_pkt, value)                                 \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_BT_MP_INFO_PARA1
#define SET_BT_MP_INFO_PARA1(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_BT_MP_INFO_PARA2
#define SET_BT_MP_INFO_PARA2(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_BT_MP_INFO_PARA3
#define SET_BT_MP_INFO_PARA3(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef SET_BT_TX_POWER_INDEX
#define SET_BT_TX_POWER_INDEX(h2c_pkt, value)                                  \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_IGNORE_WLAN_ACTION_EN
#define SET_IGNORE_WLAN_ACTION_EN(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_COEX_TDMA_TYPE_PARA1
#define SET_COEX_TDMA_TYPE_PARA1(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_COEX_TDMA_TYPE_PARA2
#define SET_COEX_TDMA_TYPE_PARA2(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_COEX_TDMA_TYPE_PARA3
#define SET_COEX_TDMA_TYPE_PARA3(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_COEX_TDMA_TYPE_PARA4
#define SET_COEX_TDMA_TYPE_PARA4(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_COEX_TDMA_TYPE_PARA5
#define SET_COEX_TDMA_TYPE_PARA5(h2c_pkt, value)                               \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef SET_BT_WIFI_CONTROL_OP_CODE
#define SET_BT_WIFI_CONTROL_OP_CODE(h2c_pkt, value)                            \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_BT_WIFI_CONTROL_DATA1
#define SET_BT_WIFI_CONTROL_DATA1(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_BT_WIFI_CONTROL_DATA2
#define SET_BT_WIFI_CONTROL_DATA2(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_BT_WIFI_CONTROL_DATA3
#define SET_BT_WIFI_CONTROL_DATA3(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(7, 0))
#endif
#ifndef SET_BT_WIFI_CONTROL_DATA4
#define SET_BT_WIFI_CONTROL_DATA4(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(15, 8))
#endif
#ifndef SET_BT_WIFI_CONTROL_DATA5
#define SET_BT_WIFI_CONTROL_DATA5(h2c_pkt, value)                              \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x01, value, GENMASK(23, 16))
#endif
#ifndef SET_COEX_QUERY_HID_INFO_SUBID
#define SET_COEX_QUERY_HID_INFO_SUBID(h2c_pkt, value)                          \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_COEX_QUERY_HID_INFO_DATA1
#define SET_COEX_QUERY_HID_INFO_DATA1(h2c_pkt, value)                          \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_KEEP_ALIVE_ENABLE
#define SET_KEEP_ALIVE_ENABLE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_KEEP_ALIVE_ADOPT
#define SET_KEEP_ALIVE_ADOPT(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(9))
#endif
#ifndef SET_KEEP_ALIVE_PKT_TYPE
#define SET_KEEP_ALIVE_PKT_TYPE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(10))
#endif
#ifndef SET_KEEP_ALIVE_CHECK_PERIOD
#define SET_KEEP_ALIVE_CHECK_PERIOD(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_DISCONNECT_DECISION_ENABLE
#define SET_DISCONNECT_DECISION_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_DISCONNECT_DECISION_ADOPT
#define SET_DISCONNECT_DECISION_ADOPT(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(9))
#endif
#ifndef SET_DISCONNECT_DECISION_CHECK_PERIOD
#define SET_DISCONNECT_DECISION_CHECK_PERIOD(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_DISCONNECT_DECISION_TRY_PKT_NUM
#define SET_DISCONNECT_DECISION_TRY_PKT_NUM(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(31, 24))
#endif
#ifndef SET_WOWLAN_FUNC_ENABLE
#define SET_WOWLAN_FUNC_ENABLE(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_WOWLAN_PATTERN_MATCH_ENABLE
#define SET_WOWLAN_PATTERN_MATCH_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(9))
#endif
#ifndef SET_WOWLAN_MAGIC_PKT_ENABLE
#define SET_WOWLAN_MAGIC_PKT_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(10))
#endif
#ifndef SET_WOWLAN_UNICAST_PKT_ENABLE
#define SET_WOWLAN_UNICAST_PKT_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(11))
#endif
#ifndef SET_WOWLAN_REKEY_WAKEUP_ENABLE
#define SET_WOWLAN_REKEY_WAKEUP_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(14))
#endif
#ifndef SET_WOWLAN_DEAUTH_WAKEUP_ENABLE
#define SET_WOWLAN_DEAUTH_WAKEUP_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(15))
#endif
#ifndef SET_REMOTE_WAKECTRL_ENABLE
#define SET_REMOTE_WAKECTRL_ENABLE(h2c_pkt, value)			       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_REMOTE_WAKE_CTRL_NLO_OFFLOAD_EN
#define SET_REMOTE_WAKE_CTRL_NLO_OFFLOAD_EN(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(12))
#endif
#ifndef SET_AOAC_GLOBAL_INFO_PAIRWISE_ENC_ALG
#define SET_AOAC_GLOBAL_INFO_PAIRWISE_ENC_ALG(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(15, 8))
#endif
#ifndef SET_AOAC_GLOBAL_INFO_GROUP_ENC_ALG
#define SET_AOAC_GLOBAL_INFO_GROUP_ENC_ALG(h2c_pkt, value)		       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_NLO_FUN_EN
#define SET_NLO_FUN_EN(h2c_pkt, value)                                         \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef SET_NLO_PS_32K
#define SET_NLO_PS_32K(h2c_pkt, value)                                         \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(9))
#endif
#ifndef SET_NLO_IGNORE_SECURITY
#define SET_NLO_IGNORE_SECURITY(h2c_pkt, value)                                \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(10))
#endif
#ifndef SET_NLO_LOC_NLO_INFO
#define SET_NLO_LOC_NLO_INFO(h2c_pkt, value)                                   \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, GENMASK(23, 16))
#endif
#ifndef SET_RECOVER_BT_DEV_EN
#define SET_RECOVER_BT_DEV_EN(h2c_pkt, value)				       \
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif
#ifndef GET_FW_DUMP_LEN
#define GET_FW_DUMP_LEN(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x00), GENMASK(15, 0))
#endif
#ifndef GET_FW_DUMP_SEQ
#define GET_FW_DUMP_SEQ(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x00), GENMASK(22, 16))
#endif
#ifndef GET_FW_DUMP_MORE
#define GET_FW_DUMP_MORE(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x00), BIT(23))
#endif
#ifndef GET_FW_DUMP_VERSION
#define GET_FW_DUMP_VERSION(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x00), GENMASK(31, 24))
#endif
#ifndef GET_FW_DUMP_TLV_TYPE
#define GET_FW_DUMP_TLV_TYPE(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x01), GENMASK(15, 0))
#endif
#ifndef GET_FW_DUMP_TLV_LEN
#define GET_FW_DUMP_TLV_LEN(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x01), GENMASK(31, 16))
#endif
#ifndef GET_FW_DUMP_TLV_VAL
#define GET_FW_DUMP_TLV_VAL(_header)					\
	le32_get_bits(*((__le32 *)(_header) + 0x02), GENMASK(31, 0))
#endif
#ifndef RFK_SET_INFORM_START
#define RFK_SET_INFORM_START(h2c_pkt, value)				\
	le32p_replace_bits((__le32 *)(h2c_pkt) + 0x00, value, BIT(8))
#endif

// ---- rtw8723x.h ----
#ifndef RTW8723X_IQK_ADDA_REG_NUM
#define RTW8723X_IQK_ADDA_REG_NUM	16
#endif
#ifndef RTW8723X_IQK_MAC8_REG_NUM
#define RTW8723X_IQK_MAC8_REG_NUM	3
#endif
#ifndef RTW8723X_IQK_MAC32_REG_NUM
#define RTW8723X_IQK_MAC32_REG_NUM	1
#endif
#ifndef RTW8723X_IQK_BB_REG_NUM
#define RTW8723X_IQK_BB_REG_NUM		9
#endif
#ifndef PATH_IQK_RETRY
#define PATH_IQK_RETRY	2
#endif
#ifndef MAX_TOLERANCE
#define MAX_TOLERANCE	5
#endif
#ifndef IQK_TX_X_ERR
#define IQK_TX_X_ERR	0x142
#endif
#ifndef IQK_TX_Y_ERR
#define IQK_TX_Y_ERR	0x42
#endif
#ifndef IQK_RX_X_ERR
#define IQK_RX_X_ERR	0x132
#endif
#ifndef IQK_RX_Y_ERR
#define IQK_RX_Y_ERR	0x36
#endif
#ifndef IQK_RX_X_UPPER
#define IQK_RX_X_UPPER	0x11a
#endif
#ifndef IQK_RX_X_LOWER
#define IQK_RX_X_LOWER	0xe6
#endif
#ifndef IQK_RX_Y_LMT
#define IQK_RX_Y_LMT	0x1a
#endif
#ifndef IQK_TX_OK
#define IQK_TX_OK	BIT(0)
#endif
#ifndef IQK_RX_OK
#define IQK_RX_OK	BIT(1)
#endif
#ifndef WLAN_TXQ_RPT_EN
#define WLAN_TXQ_RPT_EN		0x1F
#endif
#ifndef AGG_BURST_NUM
#define AGG_BURST_NUM		3
#endif
#ifndef AGG_BURST_SIZE
#define AGG_BURST_SIZE		0 /* 1K */
#endif
#ifndef BIT_MASK_AGG_BURST_NUM
#define BIT_MASK_AGG_BURST_NUM	(GENMASK(3, 2))
#endif
#ifndef BIT_MASK_AGG_BURST_SIZE
#define BIT_MASK_AGG_BURST_SIZE	(GENMASK(5, 4))
#endif
#ifndef SPUR_THRES
#define SPUR_THRES		0x16
#endif
#ifndef DIS_3WIRE
#define DIS_3WIRE		0xccf000c0
#endif
#ifndef EN_3WIRE
#define EN_3WIRE		0xccc000c0
#endif
#ifndef START_PSD
#define START_PSD		0x400000
#endif
#ifndef FREQ_CH5
#define FREQ_CH5		0xfccd
#endif
#ifndef FREQ_CH6
#define FREQ_CH6		0xfc4d
#endif
#ifndef FREQ_CH7
#define FREQ_CH7		0xffcd
#endif
#ifndef FREQ_CH8
#define FREQ_CH8		0xff4d
#endif
#ifndef FREQ_CH13
#define FREQ_CH13		0xfccd
#endif
#ifndef FREQ_CH14
#define FREQ_CH14		0xff9a
#endif
#ifndef RFCFGCH_CHANNEL_MASK
#define RFCFGCH_CHANNEL_MASK	GENMASK(7, 0)
#endif
#ifndef RFCFGCH_BW_MASK
#define RFCFGCH_BW_MASK		(BIT(11) | BIT(10))
#endif
#ifndef RFCFGCH_BW_20M
#define RFCFGCH_BW_20M		(BIT(11) | BIT(10))
#endif
#ifndef RFCFGCH_BW_40M
#define RFCFGCH_BW_40M		BIT(10)
#endif
#ifndef BIT_MASK_RFMOD
#define BIT_MASK_RFMOD		BIT(0)
#endif
#ifndef BIT_LCK
#define BIT_LCK			BIT(15)
#endif
#ifndef REG_GPIO_INTM
#define REG_GPIO_INTM		0x0048
#endif
#ifndef REG_BTG_SEL
#define REG_BTG_SEL		0x0067
#endif
#ifndef BIT_MASK_BTG_WL
#define BIT_MASK_BTG_WL		BIT(7)
#endif
#ifndef REG_LTECOEX_PATH_CONTROL
#define REG_LTECOEX_PATH_CONTROL	0x0070
#endif
#ifndef REG_LTECOEX_CTRL
#define REG_LTECOEX_CTRL	0x07c0
#endif
#ifndef REG_LTECOEX_WRITE_DATA
#define REG_LTECOEX_WRITE_DATA	0x07c4
#endif
#ifndef REG_LTECOEX_READ_DATA
#define REG_LTECOEX_READ_DATA	0x07c8
#endif
#ifndef REG_PSDFN
#define REG_PSDFN		0x0808
#endif
#ifndef REG_BB_PWR_SAV5_11N
#define REG_BB_PWR_SAV5_11N	0x0818
#endif
#ifndef REG_BB_PWR_SAV1_11N
#define REG_BB_PWR_SAV1_11N	0x0874
#endif
#ifndef REG_ANA_PARAM1
#define REG_ANA_PARAM1		0x0880
#endif
#ifndef REG_ANALOG_P4
#define REG_ANALOG_P4		0x088c
#endif
#ifndef REG_PSDRPT
#define REG_PSDRPT		0x08b4
#endif
#ifndef REG_FPGA1_RFMOD
#define REG_FPGA1_RFMOD		0x0900
#endif
#ifndef REG_BB_SEL_BTG
#define REG_BB_SEL_BTG		0x0948
#endif
#ifndef REG_BBRX_DFIR
#define REG_BBRX_DFIR		0x0954
#endif
#ifndef BIT_MASK_RXBB_DFIR
#define BIT_MASK_RXBB_DFIR	GENMASK(27, 24)
#endif
#ifndef BIT_RXBB_DFIR_EN
#define BIT_RXBB_DFIR_EN	BIT(19)
#endif
#ifndef REG_CCK0_SYS
#define REG_CCK0_SYS		0x0a00
#endif
#ifndef BIT_CCK_SIDE_BAND
#define BIT_CCK_SIDE_BAND	BIT(4)
#endif
#ifndef REG_CCK_ANT_SEL_11N
#define REG_CCK_ANT_SEL_11N	0x0a04
#endif
#ifndef REG_PWRTH
#define REG_PWRTH		0x0a08
#endif
#ifndef REG_CCK_FA_RST_11N
#define REG_CCK_FA_RST_11N	0x0a2c
#endif
#ifndef BIT_MASK_CCK_CNT_KEEP
#define BIT_MASK_CCK_CNT_KEEP	BIT(12)
#endif
#ifndef BIT_MASK_CCK_CNT_EN
#define BIT_MASK_CCK_CNT_EN	BIT(13)
#endif
#ifndef BIT_MASK_CCK_CNT_KPEN
#define BIT_MASK_CCK_CNT_KPEN	(BIT_MASK_CCK_CNT_KEEP | BIT_MASK_CCK_CNT_EN)
#endif
#ifndef BIT_MASK_CCK_FA_KEEP
#define BIT_MASK_CCK_FA_KEEP	BIT(14)
#endif
#ifndef BIT_MASK_CCK_FA_EN
#define BIT_MASK_CCK_FA_EN	BIT(15)
#endif
#ifndef BIT_MASK_CCK_FA_KPEN
#define BIT_MASK_CCK_FA_KPEN	(BIT_MASK_CCK_FA_KEEP | BIT_MASK_CCK_FA_EN)
#endif
#ifndef REG_CCK_FA_LSB_11N
#define REG_CCK_FA_LSB_11N	0x0a5c
#endif
#ifndef REG_CCK_FA_MSB_11N
#define REG_CCK_FA_MSB_11N	0x0a58
#endif
#ifndef REG_CCK_CCA_CNT_11N
#define REG_CCK_CCA_CNT_11N	0x0a60
#endif
#ifndef BIT_MASK_CCK_FA_MSB
#define BIT_MASK_CCK_FA_MSB	GENMASK(7, 0)
#endif
#ifndef BIT_MASK_CCK_FA_LSB
#define BIT_MASK_CCK_FA_LSB	GENMASK(15, 8)
#endif
#ifndef REG_PWRTH2
#define REG_PWRTH2		0x0aa8
#endif
#ifndef REG_CSRATIO
#define REG_CSRATIO		0x0aaa
#endif
#ifndef REG_OFDM_FA_HOLDC_11N
#define REG_OFDM_FA_HOLDC_11N	0x0c00
#endif
#ifndef BIT_MASK_OFDM_FA_KEEP
#define BIT_MASK_OFDM_FA_KEEP	BIT(31)
#endif
#ifndef REG_BB_RX_PATH_11N
#define REG_BB_RX_PATH_11N	0x0c04
#endif
#ifndef REG_TRMUX_11N
#define REG_TRMUX_11N		0x0c08
#endif
#ifndef REG_OFDM_FA_RSTC_11N
#define REG_OFDM_FA_RSTC_11N	0x0c0c
#endif
#ifndef BIT_MASK_OFDM_FA_RST
#define BIT_MASK_OFDM_FA_RST	BIT(31)
#endif
#ifndef REG_A_RXIQI
#define REG_A_RXIQI		0x0c14
#endif
#ifndef BIT_MASK_RXIQ_S1_X
#define BIT_MASK_RXIQ_S1_X	0x000003FF
#endif
#ifndef BIT_MASK_RXIQ_S1_Y1
#define BIT_MASK_RXIQ_S1_Y1	0x0000FC00
#endif
#ifndef BIT_SET_RXIQ_S1_Y1
#define BIT_SET_RXIQ_S1_Y1(y)	((y) & 0x3F)
#endif
#ifndef REG_OFDM0_RXDSP
#define REG_OFDM0_RXDSP		0x0c40
#endif
#ifndef BIT_MASK_RXDSP
#define BIT_MASK_RXDSP		GENMASK(28, 24)
#endif
#ifndef BIT_EN_RXDSP
#define BIT_EN_RXDSP		BIT(9)
#endif
#ifndef REG_OFDM_0_ECCA_THRESHOLD
#define REG_OFDM_0_ECCA_THRESHOLD	0x0c4c
#endif
#ifndef BIT_MASK_OFDM0_EXT_A
#define BIT_MASK_OFDM0_EXT_A	BIT(31)
#endif
#ifndef BIT_MASK_OFDM0_EXT_C
#define BIT_MASK_OFDM0_EXT_C	BIT(29)
#endif
#ifndef BIT_MASK_OFDM0_EXTS
#define BIT_MASK_OFDM0_EXTS	(BIT(31) | BIT(29) | BIT(28))
#endif
#ifndef BIT_SET_OFDM0_EXTS
#define BIT_SET_OFDM0_EXTS(a, c, d) (((a) << 31) | ((c) << 29) | ((d) << 28))
#endif
#ifndef BIT_MASK_OFDM0_EXTS_B
#define BIT_MASK_OFDM0_EXTS_B	(BIT(27) | BIT(25) | BIT(24))
#endif
#ifndef BIT_SET_OFDM0_EXTS_B
#define BIT_SET_OFDM0_EXTS_B(a, c, d) (((a) << 27) | ((c) << 25) | ((d) << 24))
#endif
#ifndef REG_OFDM0_XAAGC1
#define REG_OFDM0_XAAGC1	0x0c50
#endif
#ifndef REG_OFDM0_XBAGC1
#define REG_OFDM0_XBAGC1	0x0c58
#endif
#ifndef REG_AGCRSSI
#define REG_AGCRSSI		0x0c78
#endif
#ifndef REG_OFDM_0_XA_TX_IQ_IMBALANCE
#define REG_OFDM_0_XA_TX_IQ_IMBALANCE	0x0c80
#endif
#ifndef REG_OFDM_0_XB_TX_IQ_IMBALANCE
#define REG_OFDM_0_XB_TX_IQ_IMBALANCE	0x0c88
#endif
#ifndef BIT_MASK_TXIQ_ELM_A
#define BIT_MASK_TXIQ_ELM_A	0x03ff
#endif
#ifndef BIT_SET_TXIQ_ELM_ACD
#define BIT_SET_TXIQ_ELM_ACD(a, c, d) (((d) << 22) | (((c) & 0x3F) << 16) |    \
				       ((a) & 0x03ff))
#endif
#ifndef BIT_MASK_TXIQ_ELM_C
#define BIT_MASK_TXIQ_ELM_C	GENMASK(21, 16)
#endif
#ifndef BIT_SET_TXIQ_ELM_C2
#define BIT_SET_TXIQ_ELM_C2(c)	((c) & 0x3F)
#endif
#ifndef BIT_MASK_TXIQ_ELM_D
#define BIT_MASK_TXIQ_ELM_D	GENMASK(31, 22)
#endif
#ifndef REG_TXIQK_MATRIXA_LSB2_11N
#define REG_TXIQK_MATRIXA_LSB2_11N	0x0c94
#endif
#ifndef BIT_SET_TXIQ_ELM_C1
#define BIT_SET_TXIQ_ELM_C1(c)	(((c) & 0x000003C0) >> 6)
#endif
#ifndef REG_TXIQK_MATRIXB_LSB2_11N
#define REG_TXIQK_MATRIXB_LSB2_11N	0x0c9c
#endif
#ifndef REG_RXIQK_MATRIX_LSB_11N
#define REG_RXIQK_MATRIX_LSB_11N	0x0ca0
#endif
#ifndef BIT_MASK_RXIQ_S1_Y2
#define BIT_MASK_RXIQ_S1_Y2	0xF0000000
#endif
#ifndef BIT_SET_RXIQ_S1_Y2
#define BIT_SET_RXIQ_S1_Y2(y)	(((y) >> 6) & 0xF)
#endif
#ifndef REG_TXIQ_AB_S0
#define REG_TXIQ_AB_S0		0x0cd0
#endif
#ifndef BIT_MASK_TXIQ_A_S0
#define BIT_MASK_TXIQ_A_S0	0x000007FE
#endif
#ifndef BIT_MASK_TXIQ_A_EXT_S0
#define BIT_MASK_TXIQ_A_EXT_S0	BIT(0)
#endif
#ifndef BIT_MASK_TXIQ_B_S0
#define BIT_MASK_TXIQ_B_S0	0x0007E000
#endif
#ifndef REG_TXIQ_CD_S0
#define REG_TXIQ_CD_S0		0x0cd4
#endif
#ifndef BIT_MASK_TXIQ_C_S0
#define BIT_MASK_TXIQ_C_S0	0x000007FE
#endif
#ifndef BIT_MASK_TXIQ_C_EXT_S0
#define BIT_MASK_TXIQ_C_EXT_S0	BIT(0)
#endif
#ifndef BIT_MASK_TXIQ_D_S0
#define BIT_MASK_TXIQ_D_S0	GENMASK(22, 13)
#endif
#ifndef BIT_MASK_TXIQ_D_EXT_S0
#define BIT_MASK_TXIQ_D_EXT_S0	BIT(12)
#endif
#ifndef REG_RXIQ_AB_S0
#define REG_RXIQ_AB_S0		0x0cd8
#endif
#ifndef BIT_MASK_RXIQ_X_S0
#define BIT_MASK_RXIQ_X_S0	0x000003FF
#endif
#ifndef BIT_MASK_RXIQ_Y_S0
#define BIT_MASK_RXIQ_Y_S0	0x003FF000
#endif
#ifndef REG_OFDM0_TX_PSD_NOISE
#define REG_OFDM0_TX_PSD_NOISE	0x0ce4	/* TX pseudo noise weighting */
#endif
#ifndef REG_OFDM_FA_TYPE1_11N
#define REG_OFDM_FA_TYPE1_11N	0x0cf0
#endif
#ifndef BIT_MASK_OFDM_FF_CNT
#define BIT_MASK_OFDM_FF_CNT	GENMASK(15, 0)
#endif
#ifndef BIT_MASK_OFDM_SF_CNT
#define BIT_MASK_OFDM_SF_CNT	GENMASK(31, 16)
#endif
#ifndef REG_OFDM_FA_RSTD_11N
#define REG_OFDM_FA_RSTD_11N	0x0d00
#endif
#ifndef BIT_MASK_OFDM_FA_RST1
#define BIT_MASK_OFDM_FA_RST1	BIT(27)
#endif
#ifndef BIT_MASK_OFDM_FA_KEEP1
#define BIT_MASK_OFDM_FA_KEEP1	BIT(31)
#endif
#ifndef REG_CTX
#define REG_CTX			0x0d03
#endif
#ifndef BIT_MASK_CTX_TYPE
#define BIT_MASK_CTX_TYPE	GENMASK(6, 4)
#endif
#ifndef REG_OFDM1_CFOTRK
#define REG_OFDM1_CFOTRK	0x0d2c
#endif
#ifndef BIT_EN_CFOTRK
#define BIT_EN_CFOTRK		BIT(28)
#endif
#ifndef REG_OFDM1_CSI1
#define REG_OFDM1_CSI1		0x0d40
#endif
#ifndef REG_OFDM1_CSI2
#define REG_OFDM1_CSI2		0x0d44
#endif
#ifndef REG_OFDM1_CSI3
#define REG_OFDM1_CSI3		0x0d48
#endif
#ifndef REG_OFDM1_CSI4
#define REG_OFDM1_CSI4		0x0d4c
#endif
#ifndef REG_OFDM_FA_TYPE2_11N
#define REG_OFDM_FA_TYPE2_11N	0x0da0
#endif
#ifndef BIT_MASK_OFDM_CCA_CNT
#define BIT_MASK_OFDM_CCA_CNT	GENMASK(15, 0)
#endif
#ifndef BIT_MASK_OFDM_PF_CNT
#define BIT_MASK_OFDM_PF_CNT	GENMASK(31, 16)
#endif
#ifndef REG_OFDM_FA_TYPE3_11N
#define REG_OFDM_FA_TYPE3_11N	0x0da4
#endif
#ifndef BIT_MASK_OFDM_RI_CNT
#define BIT_MASK_OFDM_RI_CNT	GENMASK(15, 0)
#endif
#ifndef BIT_MASK_OFDM_CRC_CNT
#define BIT_MASK_OFDM_CRC_CNT	GENMASK(31, 16)
#endif
#ifndef REG_OFDM_FA_TYPE4_11N
#define REG_OFDM_FA_TYPE4_11N	0x0da8
#endif
#ifndef BIT_MASK_OFDM_MNS_CNT
#define BIT_MASK_OFDM_MNS_CNT	GENMASK(15, 0)
#endif
#ifndef REG_FPGA0_IQK_11N
#define REG_FPGA0_IQK_11N	0x0e28
#endif
#ifndef BIT_MASK_IQK_MOD
#define BIT_MASK_IQK_MOD	0xffffff00
#endif
#ifndef EN_IQK
#define EN_IQK			0x808000
#endif
#ifndef RST_IQK
#define RST_IQK			0x000000
#endif
#ifndef REG_TXIQK_TONE_A_11N
#define REG_TXIQK_TONE_A_11N	0x0e30
#endif
#ifndef REG_RXIQK_TONE_A_11N
#define REG_RXIQK_TONE_A_11N	0x0e34
#endif
#ifndef REG_TXIQK_PI_A_11N
#define REG_TXIQK_PI_A_11N	0x0e38
#endif
#ifndef REG_RXIQK_PI_A_11N
#define REG_RXIQK_PI_A_11N	0x0e3c
#endif
#ifndef REG_TXIQK_11N
#define REG_TXIQK_11N		0x0e40
#endif
#ifndef BIT_SET_TXIQK_11N
#define BIT_SET_TXIQK_11N(x, y)	(0x80007C00 | ((x) << 16) | (y))
#endif
#ifndef REG_RXIQK_11N
#define REG_RXIQK_11N		0x0e44
#endif
#ifndef REG_IQK_AGC_PTS_11N
#define REG_IQK_AGC_PTS_11N	0x0e48
#endif
#ifndef REG_IQK_AGC_RSP_11N
#define REG_IQK_AGC_RSP_11N	0x0e4c
#endif
#ifndef REG_TX_IQK_TONE_B
#define REG_TX_IQK_TONE_B	0x0e50
#endif
#ifndef REG_RX_IQK_TONE_B
#define REG_RX_IQK_TONE_B	0x0e54
#endif
#ifndef REG_TXIQK_PI_B
#define REG_TXIQK_PI_B		0x0e58
#endif
#ifndef REG_RXIQK_PI_B
#define REG_RXIQK_PI_B		0x0e5c
#endif
#ifndef REG_IQK_RDY
#define REG_IQK_RDY		0x0e90	/* is != 0 when IQK is done */
#endif
#ifndef REG_IQK_RES_TX
#define REG_IQK_RES_TX		0x0e94
#endif
#ifndef BIT_MASK_RES_TX
#define BIT_MASK_RES_TX		GENMASK(25, 16)
#endif
#ifndef REG_IQK_RES_TY
#define REG_IQK_RES_TY		0x0e9c
#endif
#ifndef BIT_MASK_RES_TY
#define BIT_MASK_RES_TY		GENMASK(25, 16)
#endif
#ifndef REG_IQK_RES_RX
#define REG_IQK_RES_RX		0x0ea4
#endif
#ifndef BIT_MASK_RES_RX
#define BIT_MASK_RES_RX		GENMASK(25, 16)
#endif
#ifndef REG_IQK_RES_RY
#define REG_IQK_RES_RY		0x0eac
#endif
#ifndef BIT_IQK_TX_FAIL
#define BIT_IQK_TX_FAIL		BIT(28)
#endif
#ifndef BIT_IQK_RX_FAIL
#define BIT_IQK_RX_FAIL		BIT(27)
#endif
#ifndef BIT_IQK_DONE
#define BIT_IQK_DONE		BIT(26)
#endif
#ifndef BIT_MASK_RES_RY
#define BIT_MASK_RES_RY		GENMASK(25, 16)
#endif
#ifndef REG_PAGE_F_RST_11N
#define REG_PAGE_F_RST_11N		0x0f14
#endif
#ifndef BIT_MASK_F_RST_ALL
#define BIT_MASK_F_RST_ALL		BIT(16)
#endif
#ifndef REG_IGI_C_11N
#define REG_IGI_C_11N			0x0f84
#endif
#ifndef REG_IGI_D_11N
#define REG_IGI_D_11N			0x0f88
#endif
#ifndef REG_HT_CRC32_CNT_11N
#define REG_HT_CRC32_CNT_11N		0x0f90
#endif
#ifndef BIT_MASK_HT_CRC_OK
#define BIT_MASK_HT_CRC_OK		GENMASK(15, 0)
#endif
#ifndef BIT_MASK_HT_CRC_ERR
#define BIT_MASK_HT_CRC_ERR		GENMASK(31, 16)
#endif
#ifndef REG_OFDM_CRC32_CNT_11N
#define REG_OFDM_CRC32_CNT_11N		0x0f94
#endif
#ifndef BIT_MASK_OFDM_LCRC_OK
#define BIT_MASK_OFDM_LCRC_OK		GENMASK(15, 0)
#endif
#ifndef BIT_MASK_OFDM_LCRC_ERR
#define BIT_MASK_OFDM_LCRC_ERR		GENMASK(31, 16)
#endif
#ifndef REG_HT_CRC32_CNT_11N_AGG
#define REG_HT_CRC32_CNT_11N_AGG	0x0fb8
#endif
#ifndef OFDM_SWING_A
#define OFDM_SWING_A(swing)		FIELD_GET(GENMASK(9, 0), swing)
#endif
#ifndef OFDM_SWING_B
#define OFDM_SWING_B(swing)		FIELD_GET(GENMASK(15, 10), swing)
#endif
#ifndef OFDM_SWING_C
#define OFDM_SWING_C(swing)		FIELD_GET(GENMASK(21, 16), swing)
#endif
#ifndef OFDM_SWING_D
#define OFDM_SWING_D(swing)		FIELD_GET(GENMASK(31, 22), swing)
#endif

// ---- rtw8723d.h ----
#ifndef GET_PHY_STAT_P0_PWDB
#define GET_PHY_STAT_P0_PWDB(phy_stat)                                         \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x00), GENMASK(15, 8))
#endif
#ifndef GET_PHY_STAT_P1_PWDB_A
#define GET_PHY_STAT_P1_PWDB_A(phy_stat)                                       \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x00), GENMASK(15, 8))
#endif
#ifndef GET_PHY_STAT_P1_PWDB_B
#define GET_PHY_STAT_P1_PWDB_B(phy_stat)                                       \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x00), GENMASK(23, 16))
#endif
#ifndef GET_PHY_STAT_P1_RF_MODE
#define GET_PHY_STAT_P1_RF_MODE(phy_stat)                                      \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x03), GENMASK(29, 28))
#endif
#ifndef GET_PHY_STAT_P1_L_RXSC
#define GET_PHY_STAT_P1_L_RXSC(phy_stat)                                       \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x01), GENMASK(11, 8))
#endif
#ifndef GET_PHY_STAT_P1_HT_RXSC
#define GET_PHY_STAT_P1_HT_RXSC(phy_stat)                                      \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x01), GENMASK(15, 12))
#endif
#ifndef GET_PHY_STAT_P1_RXEVM_A
#define GET_PHY_STAT_P1_RXEVM_A(phy_stat)                                      \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x04), GENMASK(7, 0))
#endif
#ifndef GET_PHY_STAT_P1_CFO_TAIL_A
#define GET_PHY_STAT_P1_CFO_TAIL_A(phy_stat)                                   \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x05), GENMASK(7, 0))
#endif
#ifndef GET_PHY_STAT_P1_RXSNR_A
#define GET_PHY_STAT_P1_RXSNR_A(phy_stat)                                      \
	le32_get_bits(*((__le32 *)(phy_stat) + 0x06), GENMASK(7, 0))
#endif
#ifndef RTW_DEF_OFDM_SWING_INDEX
#define RTW_DEF_OFDM_SWING_INDEX	28
#endif
#ifndef RTW_DEF_CCK_SWING_INDEX
#define RTW_DEF_CCK_SWING_INDEX		28
#endif
#ifndef CCK_DFIR_NR
#define CCK_DFIR_NR		3
#endif
