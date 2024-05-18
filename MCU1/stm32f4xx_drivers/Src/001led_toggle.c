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

	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);


	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_13);
		delay();
	}

	return 0;
}
