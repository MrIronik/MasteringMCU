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
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;


	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioBtn);

	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI2, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI2, ENABLE);



	while(1)
	{

	}

}


void EXTI2_IRQHandler(void)
{
	for(uint32_t i; i < 700000; i++);
	GPIO_IRQHandling(GPIO_PIN_NO_2);
	GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_6);



}
