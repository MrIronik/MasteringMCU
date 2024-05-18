/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>


#define RCC_BASE_ADDR				0x40023800UL
#define GPIOA_BASE_ADDR				0x40020000UL


#define RCC_AHB1_OFFSET				0x30UL
#define RCC_CFGR_OFFSET				0x08UL




int main(void)
{
	uint32_t *pRccAhb1Reg = (uint32_t*) (RCC_BASE_ADDR + RCC_AHB1_OFFSET);
	uint32_t *pRccCfgrReg = (uint32_t*) (RCC_BASE_ADDR + RCC_CFGR_OFFSET);
	uint32_t *pGpioaReg	  = (uint32_t*) (GPIOA_BASE_ADDR);
	uint32_t *pGpioaaReg  = (uint32_t*) (GPIOA_BASE_ADDR + 0x24);


	//Dla pewności czyści bity i ustawia HSI
	*pRccCfgrReg &= (~(0x03) << 21);

	*pRccCfgrReg |= ( 1 << 25);
	*pRccCfgrReg |= ( 1 << 26);

	//Odpalamy AHB1
	*pRccAhb1Reg |= (1 << 0);


	//Ustawiamy modera gpioa na alternative functions
	*pGpioaReg &= ~(0x03 << 16);
	*pGpioaReg |= (0x02 << 16);



	//Odpalamy zegar na PA8
	*pGpioaaReg &= ~(0xF << 0);


	for(;;);
}
