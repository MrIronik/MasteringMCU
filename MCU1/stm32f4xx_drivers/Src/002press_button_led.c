/*
 * 001led_toggle.c
 *
 *  Created on: 14 kwi 2024
 *      Author: MrIro
 */


#include "stm32f411xx.h"
#include<stdio.h>


void delay(void)
{
	for(uint32_t i = 0 ; i < 500000 ; i++);
}

int main()
{
	GPIO_Handle_t GpioLed;
	GPIO_Handle_t GpioBtn;


	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;


	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioBtn);



	while(1)
	{
		//uint8_t value = GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_2);

		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_2) == SET)
		{
			delay();
			GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_13, DISABLE);
		}else
		{
			delay();
			GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_13, ENABLE);
		}
	}

	return 0;
}
