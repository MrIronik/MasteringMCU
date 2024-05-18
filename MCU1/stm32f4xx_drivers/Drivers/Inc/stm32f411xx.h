/*
 * stm32f411.h
 *
 *  Created on: Apr 10, 2024
 *      Author: MrIro
 */


#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_


#include <stdio.h>
#include <stdint.h>



/**********************************************************************************************
 * 								Processor Specific Details
 **********************************************************************************************/


/*
 * NVIC ISERx register Addresses
 */

#define NVIC_ISER0			 ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1			 ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2			 ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3			 ((volatile uint32_t*)0xE000E10C)
#define NVIC_ISER4			 ((volatile uint32_t*)0xE000E110)
#define NVIC_ISER5			 ((volatile uint32_t*)0xE000E114)
#define NVIC_ISER6			 ((volatile uint32_t*)0xE000E118)
#define NVIC_ISER7			 ((volatile uint32_t*)0xE000E11C)

/*
 * NVIC ICERx register Addresses
 */

#define NVIC_ICER0			((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1			((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2			((volatile uint32_t*)0xE000E188)
#define NVIC_ICER3			((volatile uint32_t*)0xE000E18C)
#define NVIC_ICER4			((volatile uint32_t*)0xE000E190)
#define NVIC_ICER5			((volatile uint32_t*)0xE000E194)
#define NVIC_ICER6			((volatile uint32_t*)0xE000E198)
#define NVIC_ICER7			((volatile uint32_t*)0xE000E19C)

/*
 * NVIC priority register calculation
 */

#define	NVIC_PR_BASE_ADDR	((volatile uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED			4

/*
 * Base addresses of Flash, ROM and SRAM memories
 */

#define FLASH_BASEADDR					0x08000000U
#define SRAM_BASEADDR					0x20000000U
#define ROM_BASEADDR	 				0x1FFF0000U

/*
 * Base addresses of AxBx Bus Peripheral
 */

#define PERIPH_BASE						0x40000000U
#define APB1PERIPH_BASEADDR				PERIPH_BASE
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U

/*
 * AHB1 peripheral base addresses
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * APB1 peripheral base addresses
 */

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0X5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0X5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0X5C00)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0X3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0X3C00)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0X4400)


/*
 * APB2 peripheral base addresses
 */

#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0X3000)
#define SPI4_BASEADDR				(APB2PERIPH_BASEADDR + 0X3400)

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0X1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0X1400)



/********************************Structures********************************/


typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDER;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	uint32_t RES0[2];
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t RES1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	uint32_t RES2[2];
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t RES3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	uint32_t RES4[2];
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t RES5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t RES6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	uint32_t RES7;
	volatile uint32_t DCKCFGR;
}RCC_RegDef_t;

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;


/*
 * Peripheral definitions
 */

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC					((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


/*
 * Clock Enable MAcros for GPIOx peripheral
 */

#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |= (1 << 7))


/*
 * Clock Enable MAcros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()			(RCC->APB1ENR |= (1 << 23))


/*
 * Clock Enable MAcros for SPIx peripherals
 */

#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()			(RCC->APB2ENR |= (1 << 13))
#define SPI5_PCLK_EN()			(RCC->APB2ENR |= (1 << 20))


/*
 * Clock Enable MAcros for USARTx peripherals
 */

#define USART1_PCLK_EN()		(RCC->APB2ENR |= (1 << 4))
#define USART2_PLCK_EN()		(RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()		(RCC->APB2ENR |= (1 << 5))


/*
 * Clock Enable MAcros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()		(RCC->APB2ENR |= (1 << 14))


/*
 * Clock Disable MAcros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= (0 << 0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= (0 << 1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= (0 << 2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= (0 << 3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= (0 << 4))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= (0 << 7))


/*
 * Clock Disable MAcros for I2Cx peripherals
 */




/*
 * Clock Disable MAcros for SPIx peripherals
 */




/*
 * Clock Disable MAcros for USARTx peripherals
 */




/*
 * Clock Disable MAcros for SYSCFG peripherals
 */




/*
 * Macros to reset GPIOx peripheral
 */

#define GPIOA_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOH_REG_RESET()			do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)


#define GPIO_BASEADDR_TO_CODE(x)	((x == GPIOA)?0:\
									 (x == GPIOB)?1:\
									 (x == GPIOC)?2:\
									 (x == GPIOD)?3:\
									 (x == GPIOE)?4:\
									 (x == GPIOH)?7:0)


/*
 * IRQ(Interrupt Request) position on NVIC
 */

#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		47


/*
 * IRQ Priority Macros
 */

#define NVIC_IRQ_PRI0			0
#define NVIC_IRQ_PRI1			1
#define NVIC_IRQ_PRI2			2
#define NVIC_IRQ_PRI3			3
#define NVIC_IRQ_PRI4			4
#define NVIC_IRQ_PRI5			5
#define NVIC_IRQ_PRI6			6
#define NVIC_IRQ_PRI7			7
#define NVIC_IRQ_PRI8			8
#define NVIC_IRQ_PRI9			9
#define NVIC_IRQ_PRI10			10
#define NVIC_IRQ_PRI11			11
#define NVIC_IRQ_PRI12			12
#define NVIC_IRQ_PRI13			13
#define NVIC_IRQ_PRI14			14
#define NVIC_IRQ_PRI15			15



/*
 * Generic Macros
 */

#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET 		SET
#define GPIO_PIN_RESET 		RESET




#include "stm32f411xx_gpio_driver.h"

#endif /* INC_STM32F411XX_H_ */
