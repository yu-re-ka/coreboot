/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef CFG_PCH_GPIO_H
#define CFG_PCH_GPIO_H

#include <soc/gpio.h>

/* Pad configuration table for C621 Lewisburg PCH */
static const struct pad_config gpio_table[] = {
	/* ------- GPIO Community 0 ------- */
	/* ------- GPIO Group GPP_A ------- */
	/* GPP_A0 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A0, NONE, DEEP, OFF, DRIVER),
	/* GPP_A1 - LAD0 */
	PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1),
	/* GPP_A2 - LAD1 */
	PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1),
	/* GPP_A3 - LAD2 */
	PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1),
	/* GPP_A4 - LAD3 */
	PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1),
	/* GPP_A5 - LFRAME# */
	PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
	/* GPP_A6 - SERIRQ */
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
	/* GPP_A7 - PIRQA# */
	PAD_CFG_NF(GPP_A7, NONE, DEEP, NF1),
	/* GPP_A8 - CLKRUN# */
	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
	/* GPP_A9 - CLKOUT_LPC0 */
	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
	/* GPP_A10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A10, NONE, DEEP, OFF, DRIVER),
	/* GPP_A11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A11, NONE, DEEP, OFF, DRIVER),
	/* GPP_A12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A12, NONE, PLTRST, OFF, DRIVER),
	/* GPP_A13 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A13, NONE, DEEP, OFF, DRIVER),
	/* GPP_A14 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A14, NONE, DEEP, OFF, DRIVER),
	/* GPP_A15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A15, NONE, DEEP, OFF, DRIVER),
	/* GPP_A16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A16, NONE, DEEP, OFF, DRIVER),
	/* GPP_A17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A17, NONE, DEEP, OFF, DRIVER),
	/* GPP_A18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A18, NONE, DEEP, OFF, DRIVER),
	/* GPP_A19 - RESERVED */
	/* GPP_A20 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A20, NONE, DEEP, OFF, DRIVER),
	/* GPP_A21 - GPIO */
	PAD_CFG_GPO(GPP_A21, 1, DEEP),
	/* GPP_A22 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A22, NONE, DEEP, OFF, DRIVER),
	/* GPP_A23 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_A23, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Group GPP_B ------- */
	/* GPP_B0 - CORE_VID0 */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
	/* GPP_B1 - CORE_VID1 */
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
	/* GPP_B2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B2, NONE, DEEP, OFF, DRIVER),
	/* GPP_B3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B3, NONE, DEEP, OFF, DRIVER),
	/* GPP_B4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B4, NONE, DEEP, OFF, DRIVER),
	/* GPP_B5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B5, NONE, DEEP, OFF, DRIVER),
	/* GPP_B6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B6, NONE, PLTRST, OFF, DRIVER),
	/* GPP_B7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B7, NONE, PLTRST, OFF, DRIVER),
	/* GPP_B8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B8, NONE, DEEP, OFF, DRIVER),
	/* GPP_B9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B9, NONE, DEEP, OFF, DRIVER),
	/* GPP_B10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B10, NONE, DEEP, OFF, DRIVER),
	/* GPP_B11 - GPIO */
	PAD_CFG_GPO(GPP_B11, 1, DEEP),
	/* GPP_B12 - GLB_RST_WARN_N# */
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	/* GPP_B13 - PLTRST# */
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	/* GPP_B14 - SPKR */
	PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1),
	/* GPP_B15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B15, NONE, DEEP, OFF, DRIVER),
	/* GPP_B16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B16, NONE, DEEP, OFF, DRIVER),
	/* GPP_B17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B17, NONE, DEEP, OFF, DRIVER),
	/* GPP_B18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B18, NONE, DEEP, OFF, DRIVER),
	/* GPP_B19 - GPIO */
	PAD_CFG_GPO(GPP_B19, 1, DEEP),
	/* GPP_B20 - GPIO */
	PAD_CFG_GPO(GPP_B20, 0, DEEP),
	/* GPP_B21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_B21, NONE, DEEP, OFF, DRIVER),
	/* GPP_B22 - GPIO */
	PAD_CFG_GPO(GPP_B22, 0, DEEP),
	/* GPP_B23 - PCHHOT# */
	PAD_CFG_NF(GPP_B23, NONE, RSMRST, NF2),

	/* ------- GPIO Group GPP_F ------- */
	/* GPP_F0 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F0, NONE, DEEP, OFF, DRIVER),
	/* GPP_F1 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F1, NONE, DEEP, OFF, DRIVER),
	/* GPP_F2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F2, NONE, DEEP, OFF, DRIVER),
	/* GPP_F3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F3, NONE, DEEP, OFF, DRIVER),
	/* GPP_F4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F4, NONE, DEEP, OFF, DRIVER),
	/* GPP_F5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F5, NONE, DEEP, OFF, DRIVER),
	/* GPP_F6 - GPIO */
	PAD_CFG_GPO(GPP_F6, 0, PLTRST),
	/* GPP_F7 - GPIO */
	PAD_CFG_GPO(GPP_F7, 0, PLTRST),
	/* GPP_F8 - GPIO */
	PAD_CFG_GPO(GPP_F8, 0, PLTRST),
	/* GPP_F9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F9, NONE, PLTRST, OFF, DRIVER),
	/* GPP_F10 - SATA_SCLOCK */
	PAD_CFG_NF(GPP_F10, NONE, DEEP, NF1),
	/* GPP_F11 - SATA_SLOAD */
	PAD_CFG_NF(GPP_F11, NONE, DEEP, NF1),
	/* GPP_F12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F12, NONE, DEEP, OFF, DRIVER),
	/* GPP_F13 - SATA_SDATAOUT2 */
	PAD_CFG_NF(GPP_F13, NONE, DEEP, NF1),
	/* GPP_F14 - SSATA_LED# */
	PAD_CFG_NF(GPP_F14, NONE, DEEP, NF3),
	/* GPP_F15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F15, NONE, DEEP, OFF, DRIVER),
	/* GPP_F16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F16, NONE, DEEP, OFF, DRIVER),
	/* GPP_F17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F17, NONE, DEEP, OFF, DRIVER),
	/* GPP_F18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_F18, NONE, DEEP, OFF, DRIVER),
	/* GPP_F19 - LAN_SMBCLK */
	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
	/* GPP_F20 - LAN_SMBDATA */
	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
	/* GPP_F21 - LAN_SMBALRT# */
	PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
	/* GPP_F22 - SSATA_SCLOCK */
	PAD_CFG_NF(GPP_F22, NONE, DEEP, NF3),
	/* GPP_F23 - SSATA_SLOAD */
	PAD_CFG_NF(GPP_F23, NONE, DEEP, NF3),

	/* ------- GPIO Community 1 ------- */
	/* ------- GPIO Group GPP_C ------- */
	/* GPP_C0 - RESERVED */
	/* GPP_C1 - RESERVED */
	/* GPP_C2 - SMBALERT# */
	PAD_CFG_NF(GPP_C2, NONE, DEEP, NF1),
	/* GPP_C3 - RESERVED */
	/* GPP_C4 - RESERVED */
	/* GPP_C5 - GPIO */
	PAD_CFG_GPO(GPP_C5, 0, DEEP),
	/* GPP_C6 - RESERVED */
	/* GPP_C7 - RESERVED */
	/* GPP_C8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C8, NONE, DEEP, OFF, DRIVER),
	/* GPP_C9 - GPIO */
	PAD_CFG_GPO(GPP_C9, 1, DEEP),
	/* GPP_C10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C8, NONE, PLTRST, EDGE_BOTH, ACPI),
	/* GPP_C11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C11, NONE, DEEP, OFF, DRIVER),
	/* GPP_C12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C12, NONE, DEEP, OFF, DRIVER),
	/* GPP_C13 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C13, NONE, DEEP, OFF, DRIVER),
	/* GPP_C14 - GPIO */
	PAD_CFG_GPI_SCI(GPP_C14, NONE, PLTRST, LEVEL, NONE),
	/* GPP_C15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C15, NONE, DEEP, OFF, DRIVER),
	/* GPP_C16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C16, NONE, DEEP, OFF, DRIVER),
	/* GPP_C17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C17, NONE, DEEP, OFF, DRIVER),
	/* GPP_C18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C18, NONE, DEEP, OFF, DRIVER),
	/* GPP_C19 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C19, NONE, DEEP, OFF, DRIVER),
	/* GPP_C20 - RESERVED */
	/* GPP_C21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_C21, NONE, DEEP, OFF, DRIVER),
	/* GPP_C22 - GPIO */
	PAD_CFG_GPI_SMI(GPP_C22, NONE, PLTRST, LEVEL, NONE),
	/* GPP_C23 - GPIO */
	PAD_CFG_GPI_SMI(GPP_C23, NONE, DEEP, LEVEL, INVERT),

	/* ------- GPIO Group GPP_D ------- */
	/* GPP_D0 - GPIO */
	PAD_CFG_GPI_SMI(GPP_D0, NONE, PLTRST, LEVEL, INVERT),
	/* GPP_D1 - GPIO */
	PAD_CFG_GPO(GPP_D1, 0, DEEP),
	/* GPP_D2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D2, NONE, PLTRST, OFF, DRIVER),
	/* GPP_D3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D3, NONE, PLTRST, OFF, DRIVER),
	/* GPP_D4 - GPIO */
	PAD_CFG_GPO(GPP_D4, 1, DEEP),
	/* GPP_D5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D5, NONE, DEEP, OFF, DRIVER),
	/* GPP_D6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D6, NONE, DEEP, OFF, DRIVER),
	/* GPP_D7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D7, NONE, DEEP, OFF, DRIVER),
	/* GPP_D8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D8, NONE, DEEP, OFF, DRIVER),
	/* GPP_D9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D9, NONE, DEEP, OFF, DRIVER),
	/* GPP_D10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D10, NONE, DEEP, OFF, DRIVER),
	/* GPP_D11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D11, NONE, DEEP, OFF, DRIVER),
	/* GPP_D12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D12, NONE, DEEP, OFF, DRIVER),
	/* GPP_D13 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D13, NONE, DEEP, OFF, DRIVER),
	/* GPP_D14 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D14, NONE, DEEP, OFF, DRIVER),
	/* GPP_D15 - SSATA_SDATAOUT0 */
	PAD_CFG_NF(GPP_D15, NONE, DEEP, NF3),
	/* GPP_D16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D16, NONE, DEEP, OFF, DRIVER),
	/* GPP_D17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D17, NONE, DEEP, OFF, DRIVER),
	/* GPP_D18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D18, NONE, DEEP, OFF, DRIVER),
	/* GPP_D19 - GPIO */
	PAD_CFG_GPO(GPP_D19, 1, DEEP),
	/* GPP_D20 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D20, NONE, DEEP, OFF, DRIVER),
	/* GPP_D21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D21, NONE, DEEP, OFF, DRIVER),
	/* GPP_D22 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D22, NONE, DEEP, OFF, DRIVER),
	/* GPP_D23 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_D23, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Group GPP_E ------- */
	/* GPP_E0 - GPIO */
	PAD_CFG_GPI_SMI(GPP_E0, NONE, DEEP, LEVEL, NONE),
	/* GPP_E1 - GPIO */
	PAD_CFG_GPI_SMI(GPP_E1, NONE, DEEP, LEVEL, NONE),
	/* GPP_E2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E2, NONE, DEEP, OFF, DRIVER),
	/* GPP_E3 - CPU_GP0 */
	PAD_CFG_NF(GPP_E3, NONE, DEEP, NF1),
	/* GPP_E4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E4, NONE, DEEP, OFF, DRIVER),
	/* GPP_E5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E5, NONE, DEEP, OFF, DRIVER),
	/* GPP_E6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E6, NONE, DEEP, OFF, DRIVER),
	/* GPP_E7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E7, NONE, DEEP, OFF, DRIVER),
	/* GPP_E8 - SATA_LED# */
	PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
	/* GPP_E9 - USB_OC0# */
	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
	/* GPP_E10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E10, NONE, DEEP, OFF, DRIVER),
	/* GPP_E11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E11, NONE, DEEP, OFF, DRIVER),
	/* GPP_E12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_E12, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Community 2 ------- */
	/* -------- GPIO Group GPD -------- */
	/* GPD0 - RESERVED */
	/* GPD1 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD1, NONE, RSMRST, OFF, ACPI),
	/* GPD2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD2, NONE, RSMRST, OFF, ACPI),
	/* GPD3 - PWRBTN# */
	PAD_CFG_NF(GPD3, NONE, RSMRST, NF1),
	/* GPD4 - SLP_S3# */
	PAD_CFG_NF(GPD4, NONE, RSMRST, NF1),
	/* GPD5 - SLP_S4# */
	PAD_CFG_NF(GPD5, NONE, RSMRST, NF1),
	/* GPD6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD6, NONE, RSMRST, OFF, ACPI),
	/* GPD7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD7, NONE, RSMRST, OFF, ACPI),
	/* GPD8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD8, NONE, RSMRST, OFF, ACPI),
	/* GPD9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD9, NONE, RSMRST, OFF, ACPI),
	/* GPD10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPD10, NONE, RSMRST, OFF, ACPI),
	/* GPD11 - GBEPHY */
	PAD_CFG_NF(GPD11, NONE, RSMRST, NF1),

	/* ------- GPIO Community 3 ------- */
	/* ------- GPIO Group GPP_I ------- */
	/* GPP_I0 - LAN_TDO */
	PAD_CFG_NF(GPP_I0, NONE, DEEP, NF2),
	/* GPP_I1 - LAN_TCK */
	PAD_CFG_NF(GPP_I1, NONE, DEEP, NF2),
	/* GPP_I2 - LAN_TMS */
	PAD_CFG_NF(GPP_I2, NONE, DEEP, NF2),
	/* GPP_I3 - LAN_TDI */
	PAD_CFG_NF(GPP_I3, NONE, DEEP, NF2),
	/* GPP_I4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I4, NONE, DEEP, OFF, DRIVER),
	/* GPP_I5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I5, NONE, DEEP, OFF, DRIVER),
	/* GPP_I6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I6, NONE, DEEP, OFF, DRIVER),
	/* GPP_I7 - LAN_TRST_IN */
	PAD_CFG_NF(GPP_I7, NONE, DEEP, NF2),
	/* GPP_I8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I8, NONE, DEEP, OFF, DRIVER),
	/* GPP_I9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I9, NONE, DEEP, OFF, DRIVER),
	/* GPP_I10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_I10, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Community 4 ------- */
	/* ------- GPIO Group GPP_J ------- */
	/* GPP_J0 - LAN_LED_P0_0 */
	PAD_CFG_NF(GPP_J0, NONE, DEEP, NF1),
	/* GPP_J1 - LAN_LED_P0_1 */
	PAD_CFG_NF(GPP_J1, NONE, DEEP, NF1),
	/* GPP_J2 - LAN_LED_P1_0 */
	PAD_CFG_NF(GPP_J2, NONE, DEEP, NF1),
	/* GPP_J3 - LAN_LED_P1_1 */
	PAD_CFG_NF(GPP_J3, NONE, DEEP, NF1),
	/* GPP_J4 - LAN_LED_P2_0 */
	PAD_CFG_NF(GPP_J4, NONE, DEEP, NF1),
	/* GPP_J5 - LAN_LED_P2_1 */
	PAD_CFG_NF(GPP_J5, NONE, DEEP, NF1),
	/* GPP_J6 - LAN_LED_P3_0 */
	PAD_CFG_NF(GPP_J6, NONE, DEEP, NF1),
	/* GPP_J7 - LAN_LED_P3_1 */
	PAD_CFG_NF(GPP_J7, NONE, DEEP, NF1),
	/* GPP_J8 - LAN_I2C_SCL_MDC_P0 */
	PAD_CFG_NF(GPP_J8, NONE, DEEP, NF1),
	/* GPP_J9 - LAN_I2C_SDA_MDIO_P0 */
	PAD_CFG_NF(GPP_J9, NONE, DEEP, NF1),
	/* GPP_J10 - LAN_I2C_SCL_MDC_P1 */
	PAD_CFG_NF(GPP_J10, NONE, DEEP, NF1),
	/* GPP_J11 - LAN_I2C_SDA_MDIO_P1 */
	PAD_CFG_NF(GPP_J11, NONE, DEEP, NF1),
	/* GPP_J12 - LAN_I2C_SCL_MDC_P2 */
	PAD_CFG_NF(GPP_J12, NONE, DEEP, NF1),
	/* GPP_J13 - LAN_I2C_SDA_MDIO_P2 */
	PAD_CFG_NF(GPP_J13, NONE, DEEP, NF1),
	/* GPP_J14 - LAN_I2C_SCL_MDC_P3 */
	PAD_CFG_NF(GPP_J14, NONE, DEEP, NF1),
	/* GPP_J15 - LAN_I2C_SDA_MDIO_P3 */
	PAD_CFG_NF(GPP_J15, NONE, DEEP, NF1),
	/* GPP_J16 - LAN_SDP_P0_0 */
	PAD_CFG_NF(GPP_J16, NONE, DEEP, NF1),
	/* GPP_J17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_J17, NONE, DEEP, OFF, DRIVER),
	/* GPP_J18 - LAN_SDP_P1_0 */
	PAD_CFG_NF(GPP_J18, NONE, DEEP, NF1),
	/* GPP_J19 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_J19, NONE, DEEP, OFF, DRIVER),
	/* GPP_J20 - LAN_SDP_P2_0 */
	PAD_CFG_NF(GPP_J20, NONE, DEEP, NF1),
	/* GPP_J21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_J21, NONE, DEEP, OFF, DRIVER),
	/* GPP_J22 - LAN_SDP_P3_0 */
	PAD_CFG_NF(GPP_J22, NONE, DEEP, NF1),
	/* GPP_J23 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_J23, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Group GPP_K ------- */
	/* GPP_K0 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K0, NONE, DEEP, OFF, DRIVER),
	/* GPP_K1 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K1, NONE, DEEP, OFF, DRIVER),
	/* GPP_K2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K2, NONE, DEEP, OFF, DRIVER),
	/* GPP_K3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K3, NONE, DEEP, OFF, DRIVER),
	/* GPP_K4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K4, NONE, DEEP, OFF, DRIVER),
	/* GPP_K5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K5, NONE, DEEP, OFF, DRIVER),
	/* GPP_K6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_K6, NONE, DEEP, OFF, DRIVER),
	/* GPP_K7 - RESERVED */
	PAD_CFG_NF(GPP_K7, NONE, DEEP, NF1),
	/* GPP_K8 - LAN_NCSI_ARB_IN */
	PAD_CFG_NF(GPP_K8, NONE, DEEP, NF1),
	/* GPP_K9 - LAN_NCSI_ARB_OUT */
	PAD_CFG_NF(GPP_K9, NONE, DEEP, NF1),
	/* GPP_K10 - PE_RST# */
	PAD_CFG_NF(GPP_K10, NONE, DEEP, NF1),

	/* ------- GPIO Community 5 ------- */
	/* ------- GPIO Group GPP_G ------- */
	/* GPP_G0 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G0, NONE, DEEP, OFF, DRIVER),
	/* GPP_G1 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G1, NONE, DEEP, OFF, DRIVER),
	/* GPP_G2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G2, NONE, DEEP, OFF, DRIVER),
	/* GPP_G3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G3, NONE, DEEP, OFF, DRIVER),
	/* GPP_G4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G4, NONE, DEEP, OFF, DRIVER),
	/* GPP_G5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G5, NONE, DEEP, OFF, DRIVER),
	/* GPP_G6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G6, NONE, DEEP, OFF, DRIVER),
	/* GPP_G7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G7, NONE, DEEP, OFF, DRIVER),
	/* GPP_G8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G8, NONE, DEEP, OFF, DRIVER),
	/* GPP_G9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G9, NONE, DEEP, OFF, DRIVER),
	/* GPP_G10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G10, NONE, DEEP, OFF, DRIVER),
	/* GPP_G11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G11, NONE, DEEP, OFF, DRIVER),
	/* GPP_G12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G12, NONE, DEEP, OFF, DRIVER),
	/* GPP_G13 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G13, NONE, DEEP, OFF, DRIVER),
	/* GPP_G14 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G14, NONE, DEEP, OFF, DRIVER),
	/* GPP_G15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G15, NONE, DEEP, OFF, DRIVER),
	/* GPP_G16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G16, NONE, DEEP, OFF, DRIVER),
	/* GPP_G17 - ADR_COMPLETE */
	PAD_CFG_NF(GPP_G17, NONE, DEEP, NF1),
	/* GPP_G18 - NMI# */
	PAD_CFG_NF(GPP_G18, NONE, DEEP, NF1),
	/* GPP_G19 - SMI# */
	PAD_CFG_NF(GPP_G19, NONE, DEEP, NF1),
	/* GPP_G20 - RESERVED */
	/* GPP_G21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G21, NONE, DEEP, OFF, DRIVER),
	/* GPP_G22 - GPIO */
	PAD_CFG_GPO(GPP_G22, 1, DEEP),
	/* GPP_G23 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_G23, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Group GPP_H ------- */
	/* GPP_H0 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H0, NONE, DEEP, OFF, DRIVER),
	/* GPP_H1 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H1, NONE, DEEP, OFF, DRIVER),
	/* GPP_H2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H2, NONE, DEEP, OFF, DRIVER),
	/* GPP_H3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H3, NONE, DEEP, OFF, DRIVER),
	/* GPP_H4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H4, NONE, DEEP, OFF, DRIVER),
	/* GPP_H5 - RESERVED */
	/* GPP_H6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H6, NONE, DEEP, OFF, DRIVER),
	/* GPP_H7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H7, NONE, DEEP, OFF, DRIVER),
	/* GPP_H8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H8, NONE, DEEP, OFF, DRIVER),
	/* GPP_H9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H9, NONE, DEEP, OFF, DRIVER),
	/* GPP_H10 - RESERVED */
	/* GPP_H11 - RESERVED */
	/* GPP_H12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H12, NONE, DEEP, OFF, DRIVER),
	/* GPP_H13 - RESERVED */
	/* GPP_H14 - RESERVED */
	/* GPP_H15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H15, NONE, PLTRST, OFF, DRIVER),
	/* GPP_H16 - RESERVED */
	/* GPP_H17 - RESERVED */
	/* GPP_H18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H18, NONE, DEEP, OFF, DRIVER),
	/* GPP_H19 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H19, NONE, PLTRST, OFF, DRIVER),
	/* GPP_H20 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H20, NONE, DEEP, OFF, DRIVER),
	/* GPP_H21 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H21, NONE, DEEP, OFF, DRIVER),
	/* GPP_H22 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H22, NONE, DEEP, OFF, DRIVER),
	/* GPP_H23 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_H23, NONE, DEEP, OFF, DRIVER),

	/* ------- GPIO Group GPP_L ------- */
	/* GPP_L0 - RESERVED */
	/* GPP_L1 - CSME_INTR_OUT */
	PAD_CFG_NF(GPP_L1, NONE, DEEP, NF1),
	/* GPP_L2 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L2, NONE, DEEP, OFF, DRIVER),
	/* GPP_L3 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L3, NONE, DEEP, OFF, DRIVER),
	/* GPP_L4 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L4, NONE, DEEP, OFF, DRIVER),
	/* GPP_L5 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L5, NONE, DEEP, OFF, DRIVER),
	/* GPP_L6 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L6, NONE, DEEP, OFF, DRIVER),
	/* GPP_L7 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L7, NONE, DEEP, OFF, DRIVER),
	/* GPP_L8 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L8, NONE, DEEP, OFF, DRIVER),
	/* GPP_L9 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L9, NONE, DEEP, OFF, DRIVER),
	/* GPP_L10 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L10, NONE, DEEP, OFF, DRIVER),
	/* GPP_L11 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L11, NONE, DEEP, OFF, DRIVER),
	/* GPP_L12 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L12, NONE, DEEP, OFF, DRIVER),
	/* GPP_L13 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L13, NONE, DEEP, OFF, DRIVER),
	/* GPP_L14 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L14, NONE, DEEP, OFF, DRIVER),
	/* GPP_L15 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L15, NONE, DEEP, OFF, DRIVER),
	/* GPP_L16 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L16, NONE, DEEP, OFF, DRIVER),
	/* GPP_L17 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L17, NONE, DEEP, OFF, DRIVER),
	/* GPP_L18 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L18, NONE, DEEP, OFF, DRIVER),
	/* GPP_L19 - GPIO */
	PAD_CFG_GPI_TRIG_OWN(GPP_L19, NONE, DEEP, OFF, DRIVER),
};

#endif /* CFG_PCH_GPIO_H */
