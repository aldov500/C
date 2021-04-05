#include "Practice_01_Extra.h"

/* Delay Function */
static void delay(volatile uint32_t nof) {
	nof = (nof * 1940);
	while (nof != 0) {
		__asm("NOP");
		nof--;
	}
}

/* Pin Configuration Function */
void P1_InitPins() {
	/* CLK Configuration */
	CLOCK_EnableClock(kCLOCK_PortB); 
	CLOCK_EnableClock(kCLOCK_PortD);

	/* Mux to a Pin */
	PORT_SetPinMux(PORTB, 18u, 	kPORT_MuxAsGpio); /* red led, PTB18 */
	PORT_SetPinMux(PORTB, 19u, 	kPORT_MuxAsGpio); /* green led, PTB19 */
	PORT_SetPinMux(PORTD, 1u,	kPORT_MuxAsGpio);

	/* Pin initialization */
	GPIO_PinInit(GPIOB, 18u, 	&LED_configOutput); 
	GPIO_PinInit(GPIOB, 19u, 	&LED_configOutput); 
	GPIO_PinInit(GPIOD, 1u, 	&LED_configOutput);

}

/* Manager RGB Function */
void P1_RGB_Manager(char led, int state){
	switch(led){
		case 'R':
			GPIO_ClearPinsOutput(GPIOB, 18u);
		break;

		case 'G':
			GPIO_ClearPinsOutput(GPIOB, 19u);
		break;

		case 'B':
			GPIO_ClearPinsOutput(GPIOD, 1u);
		break;

		case 'Y':
			GPIO_ClearPinsOutput(GPIOB, 19u);
			GPIO_ClearPinsOutput(GPIOD, 1u);
		break;

		case 'M':
			GPIO_ClearPinsOutput(GPIOB, 18u);
			GPIO_ClearPinsOutput(GPIOD, 1u);
		break;

		case 'A':
			GPIO_ClearPinsOutput(GPIOB, 19u);
			GPIO_ClearPinsOutput(GPIOD, 1u);
		break;

		case 'W':
			GPIO_ClearPinsOutput(GPIOB, 19u);
			GPIO_ClearPinsOutput(GPIOB, 18u);
			GPIO_ClearPinsOutput(GPIOD, 1u);
		break;

		case 'N':
			RGB_Clear();
			
		break;
	}
}
/* Function to Clean RGB Pins */
void RGB_Clear() {
	GPIO_SetPinsOutput(GPIOB, 1 << 18u); /* red led off */
	GPIO_SetPinsOutput(GPIOD, 1 << 1u); /* blue led off */
	GPIO_SetPinsOutput(GPIOB, 1 << 19u); /* green led off */
}