/*
 * kl25z_pin.c
 *
 *  Created on: 24/10/2017
 *      Author: Aldo Vargas
 */

#include <HAL/gpio_mp3.h>

void GPIO_Init(){
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);

	PORT_SetPinMux(PORTB, 18u, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 19u, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD,  1u, kPORT_MuxAsGpio);

	PORT_SetPinMux(PORTB, 0u,  kPORT_MuxAsGpio);

	GPIO_PinInit(GPIOB, 18, (kGPIO_DigitalOutput, 1));
	GPIO_PinInit(GPIOB, 19, (kGPIO_DigitalOutput, 1));
	GPIO_PinInit(GPIOD,  1, (kGPIO_DigitalOutput, 1));

	GPIO_RedOFF();
	GPIO_BlueOFF();
	GPIO_GreenOFF();

	GPIO_PinInit(GPIOB, 0u, (kGPIO_DigitalInput, 1));
}


void GPIO_RedON(){
	GPIO_ClearPinsOutput(GPIOB, (1 << 18u));
}

void GPIO_RedOFF(){
	GPIO_SetPinsOutput(GPIOB, (1 << 18u));
}


void GPIO_GreenON(){
	GPIO_ClearPinsOutput(GPIOB, (1 << 19u));
}

void GPIO_GreenOFF(){
	GPIO_SetPinsOutput(GPIOB, (1 << 19u));
}


void GPIO_BlueON(){
	GPIO_ClearPinsOutput(GPIOD, (1 << 1u));
}

void GPIO_BlueOFF(){
	GPIO_SetPinsOutput(GPIOD, (1 << 1u));
}

int GPIO_ButtonRead(){
	return GPIO_ReadPinInput(GPIOB, 0);
}
