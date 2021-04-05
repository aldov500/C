/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_port.h"

#define OUT_PIN 1U

void BOARD_InitPins(void);
static const gpio_pin_config_t LED_configOutput = { kGPIO_DigitalOutput, 0 };
static const gpio_pin_config_t LED_configInput = { kGPIO_DigitalInput, 0 };

int main(void) {
	/* Init board hardware. */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	BOARD_InitPins();
	uint32_t value;

	while (1) {
		value = GPIO_ReadPinInput(GPIOB, 1);

		if (value) {
			GPIO_ClearPinsOutput(GPIOB, 1 << 18u);
			GPIO_SetPinsOutput(GPIOB, 1 << 18u);   // Apaga
			GPIO_SetPinsOutput(GPIOD, 1 << 1u);
			GPIO_SetPinsOutput(GPIOB, 1 << 19u);

		} else {

			GPIO_ClearPinsOutput(GPIOB, 1 << 19u);
			GPIO_SetPinsOutput(GPIOB, 1 << 18u);   // Apaga
			GPIO_SetPinsOutput(GPIOD, 1 << 1u);
			GPIO_SetPinsOutput(GPIOB, 1 << 19u);
		}

	}

	for (;;) { /* Infinite loop to avoid leaving the main function */
		__asm("NOP");
		/* something to use as a breakpoint stop while looping */
	}
}

void BOARD_InitPins(void) {

	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);

	/* additional clock and configuration for RGB LEDs (PTA13, PTB18 and PTB19) */
	PORT_SetPinMux(PORTB, 18u, kPORT_MuxAsGpio); /* red led, PTB18 */
	PORT_SetPinMux(PORTB, 19u, kPORT_MuxAsGpio); /* green led, PTB19 */
	PORT_SetPinMux(PORTB, 1u, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 1u, kPORT_MuxAsGpio);

	GPIO_PinInit(GPIOB, 18u, &LED_configOutput); /* mux PTB18 as output */
	GPIO_PinInit(GPIOB, 19u, &LED_configOutput); /* mux PTB19 as output */
	GPIO_PinInit(GPIOD, 1u, &LED_configOutput);
	GPIO_PinInit(GPIOB, 1u, &LED_configInput);

}
