/*
 * 004led_drain_internal_pullup.c
 *
 *  Created on: 20-Feb-2021
 *      Author: training
 */


#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"

void delay(){

	for(uint32_t i =0; i<1000000u; i++){


	}
}



int main(void){

	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOD;

	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControlr = GPIO_NO_PU;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1){

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
		// (GPIOD, GPIO_PIN_NO_12, 1)
	//GPIO_WriteFromInputPin(GpioLed.pGPIOx, GpioLed.GPIO_PinConfig.GPIO_PinNumber, ENABLE);
	}




	return 0;
}
