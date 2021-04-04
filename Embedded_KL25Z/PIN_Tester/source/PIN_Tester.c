#include "kl25z_pin.h"

static const gpio_pin_config_t pin_configOutput = { kGPIO_DigitalOutput, 0 };
static const gpio_pin_config_t pin_configInput = { kGPIO_DigitalInput, 0 };

PIN red, blue, boton, green;

int main(void) {

	PIN_New(&red, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB, pin_configOutput, 18);
	PIN_Init(&red);
	PIN_SetLow(&red);

	PIN_New(&blue, kCLOCK_PortD, kPORT_MuxAsGpio, PORTD, GPIOD, pin_configOutput, 1);
	PIN_Init(&blue);

	PIN_New(&green, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB, pin_configOutput, 19);
	PIN_Init(&green);

	PIN_New(&boton, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB, pin_configInput, 0);
	PIN_Init(&boton);

	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	while (1) {
		if (PIN_Read(&boton)) {
			PIN_SetHigh(&green);
			PIN_SetLow(&blue);
		} else {
			PIN_SetHigh(&blue);
			PIN_SetLow(&green);
		}

	}
	return 0;
}
