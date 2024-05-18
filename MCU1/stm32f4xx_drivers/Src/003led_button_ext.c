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
	GPIO_Handle_t GpioLed;			//PB6
	GPIO_Handle_t GpioBtn;			//PA2


	GpioLed.pGPIOx = GPIOB;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;


	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioBtn);



	while(1)
	{
		//uint8_t value = GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_2);

		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_2) == RESET)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_6);
		}
	}

	return 0;
}
