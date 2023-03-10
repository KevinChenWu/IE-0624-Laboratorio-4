/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx Reset and Clock
 * Control</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Uwe Hermann <uwe@hermann-uwe.de>
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Stephen Caudle <scaudle@doceme.com>
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Fernando Cortes <fernando.corcam@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Guillermo Rivera <memogrg@gmail.com>
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com> (stm32f3)
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com> (stm32f3)
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <stdbool.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x04)
#define RCC_CIR					MMIO32(RCC_BASE + 0x08)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x0C)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x14)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x18)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x1C)
#define RCC_BDCR				MMIO32(RCC_BASE + 0x20)
#define RCC_CSR					MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x28)
#define RCC_CFGR2				MMIO32(RCC_BASE + 0x2C)
#define RCC_CFGR3				MMIO32(RCC_BASE + 0x30)

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_CSSON				(1 << 19)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
/* HSICAL: [15:8] */
/* HSITRIM: [7:3] */
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

/* --- RCC_CFGR values ----------------------------------------------------- */
#define RCC_CFGR_MCOF				(1 << 28)
#define RCC_CFGR_I2SSRC				(1 << 23)
#define RCC_CFGR_USBPRES			(1 << 22)
#define RCC_CFGR_PLLXTPRE			(1 << 17)
#define RCC_CFGR_PLLSRC				(1 << 16)

/* MCO: Microcontroller clock output */
#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0x7
#define RCC_CFGR_MCO_NOCLK			0x0
/*Reserve RCC_CFGR_MCO				0x1*/
#define RCC_CFGR_MCO_LSI			0x2
#define RCC_CFGR_MCO_LSE			0x3
#define RCC_CFGR_MCO_SYSCLK			0x4
#define RCC_CFGR_MCO_HSI			0x5
#define RCC_CFGR_MCO_HSE			0x6
#define RCC_CFGR_MCO_PLL			0x7

/* PLLSRC: PLL source values */
#define RCC_CFGR_PLLSRC_HSI_DIV2 0
#define RCC_CFGR_PLLSRC_HSE_PREDIV 1

/* PLLMUL: PLL multiplication factor */
#define RCC_CFGR_PLLMUL_SHIFT			18
#define RCC_CFGR_PLLMUL_MASK			0xF
#define RCC_CFGR_PLLMUL_MUL2		0x0
#define RCC_CFGR_PLLMUL_MUL3		0x1
#define RCC_CFGR_PLLMUL_MUL4		0x2
#define RCC_CFGR_PLLMUL_MUL5		0x3
#define RCC_CFGR_PLLMUL_MUL6		0x4
#define RCC_CFGR_PLLMUL_MUL7		0x5
#define RCC_CFGR_PLLMUL_MUL8		0x6
#define RCC_CFGR_PLLMUL_MUL9		0x7
#define RCC_CFGR_PLLMUL_MUL10		0x8
#define RCC_CFGR_PLLMUL_MUL11		0x9
#define RCC_CFGR_PLLMUL_MUL12		0xA
#define RCC_CFGR_PLLMUL_MUL13		0xB
#define RCC_CFGR_PLLMUL_MUL14		0xC
#define RCC_CFGR_PLLMUL_MUL15		0xD
#define RCC_CFGR_PLLMUL_MUL16		0xE

#define RCC_CFGR_PPRE2_SHIFT			11
#define RCC_CFGR_PPRE2_MASK			0x7
#define RCC_CFGR_PPRE1_SHIFT			8
#define RCC_CFGR_PPRE1_MASK			0x7
/** @defgroup rcc_cfgr_apbxpre RCC_CFGR APBx prescale factors
 * These can be used for both APB1 and APB2 prescaling
 * @{
 */
#define RCC_CFGR_PPRE_NODIV			0x0
#define RCC_CFGR_PPRE_DIV2			0x4
#define RCC_CFGR_PPRE_DIV4			0x5
#define RCC_CFGR_PPRE_DIV8			0x6
#define RCC_CFGR_PPRE_DIV16			0x7
/**@}*/

#define RCC_CFGR_HPRE_SHIFT			4
#define RCC_CFGR_HPRE_MASK			0xf
/** @defgroup rcc_cfgr_ahbpre RCC_CFGR AHB prescale factors
@{*/
#define RCC_CFGR_HPRE_NODIV			0x0
#define RCC_CFGR_HPRE_DIV2			0x8
#define RCC_CFGR_HPRE_DIV4			0x9
#define RCC_CFGR_HPRE_DIV8			0xA
#define RCC_CFGR_HPRE_DIV16			0xB
#define RCC_CFGR_HPRE_DIV64			0xC
#define RCC_CFGR_HPRE_DIV128			0xD
#define RCC_CFGR_HPRE_DIV256			0xE
#define RCC_CFGR_HPRE_DIV512			0xF
/**@}*/

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SHIFT			2
#define RCC_CFGR_SWS_MASK			0x3
#define RCC_CFGR_SWS_HSI			0x0
#define RCC_CFGR_SWS_HSE			0x1
#define RCC_CFGR_SWS_PLL			0x2

/* SW: System clock switch */
#define RCC_CFGR_SW_SHIFT			0
#define RCC_CFGR_SW_HSI				0x0
#define RCC_CFGR_SW_HSE				0x1
#define RCC_CFGR_SW_PLL				0x2

/** Older compatible definitions to ease migration
 * @defgroup rcc_cfgr_deprecated RCC_CFGR Deprecated dividers
 * @deprecated Use _CFGR_xPRE_DIVn form instead, across all families
 * @{
 */
#define RCC_CFGR_PPRE2_DIV_NONE			0x0
#define RCC_CFGR_PPRE2_DIV_2			0x4
#define RCC_CFGR_PPRE2_DIV_4			0x5
#define RCC_CFGR_PPRE2_DIV_8			0x6
#define RCC_CFGR_PPRE2_DIV_16			0x7

#define RCC_CFGR_PPRE1_DIV_NONE			0x0
#define RCC_CFGR_PPRE1_DIV_2			0x4
#define RCC_CFGR_PPRE1_DIV_4			0x5
#define RCC_CFGR_PPRE1_DIV_8			0x6
#define RCC_CFGR_PPRE1_DIV_16			0x7

#define RCC_CFGR_HPRE_DIV_NONE			0x0
#define RCC_CFGR_HPRE_DIV_2			0x8
#define RCC_CFGR_HPRE_DIV_4			0x9
#define RCC_CFGR_HPRE_DIV_8			0xA
#define RCC_CFGR_HPRE_DIV_16			0xB
#define RCC_CFGR_HPRE_DIV_64			0xC
#define RCC_CFGR_HPRE_DIV_128			0xD
#define RCC_CFGR_HPRE_DIV_256			0xE
#define RCC_CFGR_HPRE_DIV_512			0xF
/**@}*/

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@{*/
#define RCC_APB2RSTR_TIM20RST			(1 << 20)
#define RCC_APB2RSTR_TIM17RST			(1 << 18)
#define RCC_APB2RSTR_TIM16RST			(1 << 17)
#define RCC_APB2RSTR_TIM15RST			(1 << 16)
#define RCC_APB2RSTR_SPI4RST			(1 << 15)
#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_TIM8RST			(1 << 13)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_TIM1RST			(1 << 11)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@{*/
#define RCC_APB1RSTR_I2C3RST			(1 << 30)
#define RCC_APB1RSTR_DAC1RST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_DAC2RST			(1 << 26)
#define RCC_APB1RSTR_CAN1RST			(1 << 25)
#define RCC_APB1RSTR_USBRST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_UART5RST			(1 << 20)
#define RCC_APB1RSTR_UART4RST			(1 << 19)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM4RST			(1 << 2)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
 *@{*/
#define RCC_AHBENR_ADC34EN			(1 << 29)
#define RCC_AHBENR_ADC12EN			(1 << 28)
#define RCC_AHBENR_TSCEN			(1 << 24)
#define RCC_AHBENR_IOPGEN			(1 << 23)
#define RCC_AHBENR_IOPFEN			(1 << 22)
#define RCC_AHBENR_IOPEEN			(1 << 21)
#define RCC_AHBENR_IOPDEN			(1 << 20)
#define RCC_AHBENR_IOPCEN			(1 << 19)
#define RCC_AHBENR_IOPBEN			(1 << 18)
#define RCC_AHBENR_IOPAEN			(1 << 17)
#define RCC_AHBENR_IOPHEN			(1 << 16)
#define RCC_AHBENR_CRCEN			(1 << 6)
#define RCC_AHBENR_FMCEN			(1 << 5)
#define RCC_AHBENR_FLITFEN			(1 << 4)
#define RCC_AHBENR_SRAMEN			(1 << 2)
#define RCC_AHBENR_DMA2EN			(1 << 1)
#define RCC_AHBENR_DMA1EN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@{*/
#define RCC_APB2ENR_TIM20EN			(1 << 20)
#define RCC_APB2ENR_TIM17EN			(1 << 18)
#define RCC_APB2ENR_TIM16EN			(1 << 17)
#define RCC_APB2ENR_TIM15EN			(1 << 16)
#define RCC_APB2ENR_SPI4EN			(1 << 15)
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_TIM8EN			(1 << 13)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_TIM1EN			(1 << 11)
#define RCC_APB2ENR_SYSCFGEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_I2C3EN			(1 << 30)
#define RCC_APB1ENR_DAC1EN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_DAC2EN			(1 << 26)
#define RCC_APB1ENR_CANEN			(1 << 25)
#define RCC_APB1ENR_USBEN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_USART5EN			(1 << 20)
#define RCC_APB1ENR_USART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM4EN			(1 << 2)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/**@}*/

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)
/* RCC_BDCR[9:8]: RTCSEL */
/* RCC_BDCR[4:3]: LSEDRV */
#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)

/* --- RCC_CSR values ------------------------------------------------------ */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_OBLRSTF				(1 << 25)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/** @defgroup rcc_ahbrstr_rst RCC_AHBxRSTR reset values (full set)
@{*/
#define RCC_AHBRSTR_ADC34RST			(1 << 29)
#define RCC_AHBRSTR_ADC12RST			(1 << 28)
#define RCC_AHBRSTR_TSCRST			(1 << 24)
#define RCC_AHBRSTR_IOPGRST			(1 << 23)
#define RCC_AHBRSTR_IOPFRST			(1 << 22)
#define RCC_AHBRSTR_IOPERST			(1 << 21)
#define RCC_AHBRSTR_IOPDRST			(1 << 20)
#define RCC_AHBRSTR_IOPCRST			(1 << 19)
#define RCC_AHBRSTR_IOPBRST			(1 << 18)
#define RCC_AHBRSTR_IOPARST			(1 << 17)
#define RCC_AHBRSTR_IOPHRST			(1 << 16)
#define RCC_AHBRSTR_FMCRST			(1 << 5)
/**@}*/

/* --- RCC_CFGR2 values ---------------------------------------------------- */
/* ADCxxPRES: ADCxx prescaler */
#define RCC_CFGR2_ADC34PRES_SHIFT		9
#define RCC_CFGR2_ADC12PRES_SHIFT		4
#define RCC_CFGR2_ADCxPRES_MASK			0x1f
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_1	0x10
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_2	0x11
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_4	0x12
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_6	0x13
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_8	0x14
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_10	0x15
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_12	0x16
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_16	0x17
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_32	0x18
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_64	0x19
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_128	0x1A
#define RCC_CFGR2_ADCxPRES_PLL_CLK_DIV_256	0x1B

#define RCC_CFGR2_PREDIV			0xf
/** @defgroup rcc_cfgr2_prediv PLL source predividers
@ingroup rcc_defines
@{*/
#define RCC_CFGR2_PREDIV_NODIV			0x0
#define RCC_CFGR2_PREDIV_DIV2			0x1
#define RCC_CFGR2_PREDIV_DIV3			0x2
#define RCC_CFGR2_PREDIV_DIV4			0x3
#define RCC_CFGR2_PREDIV_DIV5			0x4
#define RCC_CFGR2_PREDIV_DIV6			0x5
#define RCC_CFGR2_PREDIV_DIV7			0x6
#define RCC_CFGR2_PREDIV_DIV8			0x7
#define RCC_CFGR2_PREDIV_DIV9			0x8
#define RCC_CFGR2_PREDIV_DIV10			0x9
#define RCC_CFGR2_PREDIV_DIV11			0xa
#define RCC_CFGR2_PREDIV_DIV12			0xb
#define RCC_CFGR2_PREDIV_DIV13			0xc
#define RCC_CFGR2_PREDIV_DIV14			0xd
#define RCC_CFGR2_PREDIV_DIV15			0xe
#define RCC_CFGR2_PREDIV_DIV16			0xf
/**@}*/

/* --- RCC_CFGR3 values ---------------------------------------------------- */
#define RCC_CFGR3_TIM8SW			(1 << 9)
#define RCC_CFGR3_TIM1SW			(1 << 8)
#define RCC_CFGR3_I2C2SW			(1 << 5)
#define RCC_CFGR3_I2C1SW			(1 << 4)
/** @defgroup rcc_cfgr3_uart_choices UART for clock sour selecting
 * @{
 */
#define RCC_CFGR3_UART5SW_SHIFT			22
#define RCC_CFGR3_UART4SW_SHIFT			20
#define RCC_CFGR3_UART3SW_SHIFT			18
#define RCC_CFGR3_UART2SW_SHIFT			16
#define RCC_CFGR3_UART1SW_SHIFT			0
/**@}*/

/** @defgroup rcc_cfgr3_uart_clksel UART Clock source selections
 * @note This is only used internally.
 * @{
 */
#define RCC_CFGR3_UARTxSW_PCLK			0x0
#define RCC_CFGR3_UARTxSW_SYSCLK		0x1
#define RCC_CFGR3_UARTxSW_LSE			0x2
#define RCC_CFGR3_UARTxSW_HSI			0x3
/**@}*/

/* Shared mask for UART clock source. */
#define RCC_CFGR3_UARTxSW_MASK			0x3


/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_48MHZ,
	RCC_CLOCK_HSI_64MHZ, /* Max from HSI */
	RCC_CLOCK_HSI_END
};
enum rcc_clock_hse8 {
	RCC_CLOCK_HSE8_72MHZ,
	RCC_CLOCK_HSE8_END
};


struct rcc_clock_scale {
	uint8_t pllsrc;
	uint8_t pllmul;
	uint8_t plldiv;
	bool usbdiv1;
	uint32_t flash_waitstates;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint8_t power_save;
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse8mhz_configs[RCC_CLOCK_HSE8_END];

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI, RCC_LSE, RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

/* Availability in comment:
 * 0: F30x
 * 1: F31x
 * 7: F37x
 * 8: F38x
 */
enum rcc_periph_clken {
	/* AHB peripherals*/
	RCC_DMA1	= _REG_BIT(0x14, 0),/*0178*/
	RCC_DMA2	= _REG_BIT(0x14, 1),/*0178*/
	RCC_SRAM	= _REG_BIT(0x14, 2),/*0178*/
	RCC_FLTIF	= _REG_BIT(0x14, 4),/*0178*/
	RCC_FMC		= _REG_BIT(0x14, 5),/*0178*/
	RCC_CRC		= _REG_BIT(0x14, 6),/*0178*/
	RCC_GPIOH	= _REG_BIT(0x14, 16),/*0178*/
	RCC_GPIOA	= _REG_BIT(0x14, 17),/*0178*/
	RCC_GPIOB	= _REG_BIT(0x14, 18),/*0178*/
	RCC_GPIOC	= _REG_BIT(0x14, 19),/*0178*/
	RCC_GPIOD	= _REG_BIT(0x14, 20),/*0178*/
	RCC_GPIOE	= _REG_BIT(0x14, 21),/*0178*/
	RCC_GPIOF	= _REG_BIT(0x14, 22),/*0178*/
	RCC_GPIOG	= _REG_BIT(0x14, 23),/*0178*/
	RCC_TSC		= _REG_BIT(0x14, 24),/*0178*/
	RCC_ADC12	= _REG_BIT(0x14, 28),/*01--*/
	RCC_ADC34	= _REG_BIT(0x14, 29),/*01--*/

	/* APB2 peripherals */
	RCC_SYSCFG	= _REG_BIT(0x18, 0),/*0178*/
	RCC_ADC		= _REG_BIT(0x18, 9),/*--78*/
	RCC_TIM1	= _REG_BIT(0x18, 11),/*01--*/
	RCC_SPI1	= _REG_BIT(0x18, 12),/*0178*/
	RCC_TIM8	= _REG_BIT(0x18, 13),/*01--*/
	RCC_USART1	= _REG_BIT(0x18, 14),/*0178*/
	RCC_SPI4	= _REG_BIT(0x18, 15),
	RCC_TIM15	= _REG_BIT(0x18, 16),/*0178*/
	RCC_TIM16	= _REG_BIT(0x18, 17),/*0178*/
	RCC_TIM17	= _REG_BIT(0x18, 18),/*0178*/
	RCC_TIM19	= _REG_BIT(0x18, 19),/*--78*/
	RCC_TIM20	= _REG_BIT(0x18, 20),
	RCC_DBGMCU	= _REG_BIT(0x18, 22),/*--78*/
	RCC_SDADC1	= _REG_BIT(0x18, 24),/*--78*/
	RCC_SDADC2	= _REG_BIT(0x18, 25),/*--78*/
	RCC_SDADC3	= _REG_BIT(0x18, 26),/*--78*/
	RCC_HRTIM	= _REG_BIT(0x18, 29),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 0),/*0178*/
	RCC_TIM3	= _REG_BIT(0x1C, 1),/*0178*/
	RCC_TIM4	= _REG_BIT(0x1C, 2),/*0178*/
	RCC_TIM5	= _REG_BIT(0x1C, 3),/*--78*/
	RCC_TIM6	= _REG_BIT(0x1C, 4),/*0178*/
	RCC_TIM7	= _REG_BIT(0x1C, 5),/*0178*/
	RCC_TIM12	= _REG_BIT(0x1C, 6),/*--78*/
	RCC_TIM13	= _REG_BIT(0x1C, 7),/*--78*/
	RCC_TIM14	= _REG_BIT(0x1C, 8),/*--78*/
	RCC_TIM18	= _REG_BIT(0x1C, 9),/*--78*/
	RCC_WWDG	= _REG_BIT(0x1C, 11),/*0178*/
	RCC_SPI2	= _REG_BIT(0x1C, 14),/*0178*/
	RCC_SPI3	= _REG_BIT(0x1C, 15),/*0178*/
	RCC_USART2	= _REG_BIT(0x1C, 17),/*0178*/
	RCC_USART3	= _REG_BIT(0x1C, 18),/*0178*/
	RCC_UART4	= _REG_BIT(0x1C, 19),/*01--*/
	RCC_UART5	= _REG_BIT(0x1C, 20),/*01--*/
	RCC_I2C1	= _REG_BIT(0x1C, 21),/*0178*/
	RCC_I2C2	= _REG_BIT(0x1C, 22),/*0178*/
	RCC_USB		= _REG_BIT(0x1C, 23),/*0178*/
	RCC_CAN		= _REG_BIT(0x1C, 25),/*0178*/
	RCC_CAN1	= _REG_BIT(0x1C, 25),/*0178*/
	RCC_DAC2	= _REG_BIT(0x1C, 26),
	RCC_PWR		= _REG_BIT(0x1C, 28),/*0178*/
	RCC_DAC1	= _REG_BIT(0x1C, 29),
	RCC_CEC		= _REG_BIT(0x1C, 30),/*--78*/
	RCC_I2C3	= _REG_BIT(0x1C, 30),
};

enum rcc_periph_rst {
	/* APB2 peripherals*/
	RST_SYSCFG	= _REG_BIT(0x0C, 0),/*0178*/
	RST_ADC		= _REG_BIT(0x0C, 9),/*--78*/
	RST_TIM1	= _REG_BIT(0x0C, 11),/*01--*/
	RST_SPI1	= _REG_BIT(0x0C, 12),/*0178*/
	RST_TIM8	= _REG_BIT(0x0C, 13),/*01--*/
	RST_USART1	= _REG_BIT(0x0C, 14),/*0178*/
	RST_SPI4	= _REG_BIT(0x0C, 15),
	RST_TIM15	= _REG_BIT(0x0C, 16),/*0178*/
	RST_TIM16	= _REG_BIT(0x0C, 17),/*0178*/
	RST_TIM17	= _REG_BIT(0x0C, 18),/*0178*/
	RST_TIM19	= _REG_BIT(0x0C, 19),/*--78*/
	RST_TIM20	= _REG_BIT(0x0C, 20),
	RST_SDADC1	= _REG_BIT(0x0C, 24),/*--78*/
	RST_SDADC2	= _REG_BIT(0x0C, 25),/*--78*/
	RST_SDADC3	= _REG_BIT(0x0C, 26),/*--78*/
	RST_HRTIM	= _REG_BIT(0x0C, 29),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 0),/*0178*/
	RST_TIM3	= _REG_BIT(0x10, 1),/*0178*/
	RST_TIM4	= _REG_BIT(0x10, 2),/*0178*/
	RST_TIM5	= _REG_BIT(0x10, 3),/*--78*/
	RST_TIM6	= _REG_BIT(0x10, 4),/*0178*/
	RST_TIM7	= _REG_BIT(0x10, 5),/*0178*/
	RST_TIM12	= _REG_BIT(0x10, 6),/*--78*/
	RST_TIM13	= _REG_BIT(0x10, 7),/*--78*/
	RST_TIM14	= _REG_BIT(0x10, 8),/*--78*/
	RST_TIM18	= _REG_BIT(0x10, 9),/*--78*/
	RST_WWDG	= _REG_BIT(0x10, 11),/*0178*/
	RST_SPI2	= _REG_BIT(0x10, 14),/*0178*/
	RST_SPI3	= _REG_BIT(0x10, 15),/*0178*/
	RST_USART2	= _REG_BIT(0x10, 17),/*0178*/
	RST_USART3	= _REG_BIT(0x10, 18),/*0178*/
	RST_UART4	= _REG_BIT(0x10, 19),/*01--*/
	RST_UART5	= _REG_BIT(0x10, 20),/*01--*/
	RST_I2C1	= _REG_BIT(0x10, 21),/*0178*/
	RST_I2C2	= _REG_BIT(0x10, 22),/*0178*/
	RST_USB		= _REG_BIT(0x10, 23),/*0178*/
	RST_CAN		= _REG_BIT(0x10, 25),/*0178*/
	RST_CAN1	= _REG_BIT(0x10, 25),/*0178*/
	RST_DAC2	= _REG_BIT(0x10, 26),
	RST_PWR		= _REG_BIT(0x10, 28),/*0178*/
	RST_DAC1	= _REG_BIT(0x10, 29),
	RST_CEC		= _REG_BIT(0x10, 30),/*--78*/
	RST_I2C3	= _REG_BIT(0x10, 30),

	/* AHB peripherals */
	RST_FMC		= _REG_BIT(0x28, 5),
	RST_GPIOH	= _REG_BIT(0x28, 16),
	RST_GPIOA	= _REG_BIT(0x28, 17),/*0178*/
	RST_GPIOB	= _REG_BIT(0x28, 18),/*0178*/
	RST_GPIOC	= _REG_BIT(0x28, 19),/*0178*/
	RST_GPIOD	= _REG_BIT(0x28, 20),/*0178*/
	RST_GPIOE	= _REG_BIT(0x28, 21),/*0178*/
	RST_GPIOF	= _REG_BIT(0x28, 22),/*0178*/
	RST_GPIOG	= _REG_BIT(0x28, 23),
	RST_TSC		= _REG_BIT(0x28, 24),/*0178*/
	RST_ADC12	= _REG_BIT(0x28, 28),/*01--*/
	RST_ADC34	= _REG_BIT(0x28, 29),/*01--*/

	/* BDCR[16] */
	RST_BD		= _REG_BIT(0x20, 16),
};

#undef _REG_BIT

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_osc_not_ready(enum rcc_osc osc);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_prediv(uint32_t prediv);
void rcc_set_pll_multiplier(uint32_t pll);
uint32_t rcc_get_system_clock_source(void);
void rcc_backupdomain_reset(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock);
void rcc_set_i2c_clock_hsi(uint32_t i2c);
void rcc_set_i2c_clock_sysclk(uint32_t i2c);
uint32_t rcc_get_i2c_clocks(void);
void rcc_usb_prescale_1_5(void);
void rcc_usb_prescale_1(void);
void rcc_adc_prescale(uint32_t prescale1, uint32_t prescale2);
uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);

END_DECLS

#endif
