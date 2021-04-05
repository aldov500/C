/*
 * kl25z_pin.h
 *
 *  Created on: 23/10/2017
 *      Author: Aldo Vargas
 */

/*
 PIN_New(&red, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB, pin_configOutput, 18);
 PIN_Init(&red);

 PIN_New(&blue, kCLOCK_PortD, kPORT_MuxAsGpio, PORTD, GPIOD, pin_configOutput, 1);
 PIN_Init(&blue);

 PIN_New(&boton, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB,
 pin_configInput, 0);
 PIN_Init(&boton);

 */

#ifndef KL25Z_PIN_H_
#define KL25Z_PIN_H_

#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "fsl_port.h"
#include "clock_config.h"
#include "MKL25Z4.h"

static const gpio_pin_config_t pin_configOutput = { kGPIO_DigitalOutput, 1 };
static const gpio_pin_config_t pin_configInput = { kGPIO_DigitalInput, 0 };


typedef struct pinStruct {
	clock_ip_name_t clk;
	port_mux_t mux;
	PORT_Type* port;
	GPIO_Type* gpio;
	gpio_pin_config_t conf;

	int pinNumber;

} PIN;

void PIN_New(PIN* new_pin, clock_ip_name_t new_clk, port_mux_t new_mux,
		PORT_Type* new_port, GPIO_Type* new_gpio, gpio_pin_config_t new_conf,
		int new_pinNumber);

void PIN_Init(PIN* pin);

void PIN_SetHigh(PIN* pin);

void PIN_SetLow(PIN* pin);

int PIN_Read(PIN* pin);

#endif /* KL25Z_PIN_H_ */
