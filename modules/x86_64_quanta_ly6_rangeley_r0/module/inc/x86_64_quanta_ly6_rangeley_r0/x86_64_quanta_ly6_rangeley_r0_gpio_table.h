#ifndef __X86_64_QUANTA_LY6_RANGELEY_R0_GPIO_TABLE_H__
#define __X86_64_QUANTA_LY6_RANGELEY_R0_GPIO_TABLE_H__

/*
 * defined within platform/quanta_switch.c
 * Quanta Switch Platform driver
 */
#define PCA953x_GPIO(P1, P2)	(P1*8+P2)

#define PCA9554_GPIO_SIZE	0x08
#define PCA9555_GPIO_SIZE	0x10
#define PCA9698_GPIO_SIZE	0x28

#define I2C_GPIO_BASE	0x80

#define LY6_CPLD_QSFP_GPIO_BASE			(I2C_GPIO_BASE)
#define LY6_CPLD_QSFP_GPIO_SIZE			0x40
#define LY6_CPLD_QSFP_PRSNT(port)		(LY6_CPLD_QSFP_GPIO_BASE + ((port%2) ? (port) : (port-2)) * 4 + 1)

/* 2 cpld for 32 ports */
#define FAN_GPIO_BASE					(LY6_CPLD_QSFP_GPIO_BASE + LY6_CPLD_QSFP_GPIO_SIZE * 2)
#define FAN_GPIO_SIZE					PCA9555_GPIO_SIZE
#define FAN_PRSNT_N_1					(FAN_GPIO_BASE + PCA953x_GPIO(0,4))
#define FAN_PRSNT_N_2					(FAN_GPIO_BASE + PCA953x_GPIO(0,5))
#define FAN_PRSNT_N_3					(FAN_GPIO_BASE + PCA953x_GPIO(0,6))
#define FAN_BF_DET1						(FAN_GPIO_BASE + PCA953x_GPIO(1,0))
#define FAN_BF_DET2						(FAN_GPIO_BASE + PCA953x_GPIO(1,1))
#define FAN_BF_DET3						(FAN_GPIO_BASE + PCA953x_GPIO(1,2))
#define FAN_FAIL_LED_1					(FAN_GPIO_BASE + PCA953x_GPIO(1,4))
#define FAN_FAIL_LED_2					(FAN_GPIO_BASE + PCA953x_GPIO(1,5))
#define FAN_FAIL_LED_3					(FAN_GPIO_BASE + PCA953x_GPIO(1,6))

#define QSFP_EN_GPIO_BASE				(FAN_GPIO_BASE + FAN_GPIO_SIZE)
#define QSFP_EN_GPIO_SIZE				PCA9555_GPIO_SIZE
#define QSFP_EN_GPIO_P3V3_PW_GD			(QSFP_EN_GPIO_BASE + PCA953x_GPIO(0,4))
#define QSFP_EN_GPIO_P3V3_PW_EN			(QSFP_EN_GPIO_BASE + PCA953x_GPIO(1,0))

#define PSU_GPIO_BASE					(QSFP_EN_GPIO_BASE + QSFP_EN_GPIO_SIZE)
#define PSU_GPIO_SIZE					PCA9555_GPIO_SIZE
#define PSU_GPIO_PSU1_PRSNT_N			(PSU_GPIO_BASE + PCA953x_GPIO(0,0))
#define PSU_GPIO_PSU1_PWRGD				(PSU_GPIO_BASE + PCA953x_GPIO(0,1))
#define PSU_GPIO_PSU2_PRSNT_N			(PSU_GPIO_BASE + PCA953x_GPIO(0,3))
#define PSU_GPIO_PSU2_PWRGD				(PSU_GPIO_BASE + PCA953x_GPIO(0,4))
#define PSU_GPIO_PSU1_AC_OK				(PSU_GPIO_BASE + PCA953x_GPIO(0,6))
#define PSU_GPIO_PSU2_AC_OK				(PSU_GPIO_BASE + PCA953x_GPIO(0,7))
#define PSU_GPIO_PSU1_GREEN_R			(PSU_GPIO_BASE + PCA953x_GPIO(1,2))
#define PSU_GPIO_PSU1_RED_R				(PSU_GPIO_BASE + PCA953x_GPIO(1,3))
#define PSU_GPIO_PSU2_GREEN_R			(PSU_GPIO_BASE + PCA953x_GPIO(1,4))
#define PSU_GPIO_PSU2_RED_R				(PSU_GPIO_BASE + PCA953x_GPIO(1,5))
#define PSU_GPIO_FAN_GREEN_R			(PSU_GPIO_BASE + PCA953x_GPIO(1,6))
#define PSU_GPIO_FAN_RED_R				(PSU_GPIO_BASE + PCA953x_GPIO(1,7))

#endif /* __X86_64_QUANTA_LY6_RANGELEY_R0_GPIO_TABLE_H__ */
