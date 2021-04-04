/*
 * kl25z_pin.c
 *
 *  Created on: 24/10/2017
 *      Author: Aldo Vargas
 */

#include "kl25z_pin.h"

void PIN_New(PIN* new_pin, clock_ip_name_t new_clk, port_mux_t new_mux,
		PORT_Type* new_port, GPIO_Type* new_gpio, gpio_pin_config_t new_conf, int new_pinNumber) {

	new_pin->clk = new_clk;
	new_pin->mux = new_mux;
	new_pin->port = new_port;
	new_pin->gpio = new_gpio;
	new_pin->conf = new_conf;
	new_pin->pinNumber = new_pinNumber;
}

void PIN_Init(PIN* pin) {
	CLOCK_EnableClock(pin->clk);
	PORT_SetPinMux(pin->port, pin->pinNumber, pin->mux);
	GPIO_PinInit(pin->gpio, pin->pinNumber, &pin->conf);
	// PIN_SetLow(pin);

}

void PIN_SetHigh(PIN* pin){
	GPIO_SetPinsOutput(pin->gpio, (1 << pin->pinNumber));
}

void PIN_SetLow(PIN* pin){
	GPIO_ClearPinsOutput(pin->gpio, (1 << pin->pinNumber));
}

int PIN_Read(PIN* pin){
	return GPIO_ReadPinInput(pin->gpio, pin->pinNumber);
}
