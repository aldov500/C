
#ifndef PRACTICE_2_H_
#define PRACTICE_2_H_


/* Headers */
#include "fsl_device_registers.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "MKL25Z4.h"

/* Configuration Structure for output pin*/
static const gpio_pin_config_t LED_configOutput = { kGPIO_DigitalOutput, 1 };
/* Delay Function */
static void delay(volatile uint32_t nof);
/* Pin Initialization */
void P1_InitPins();
/* Function for RGB led */
void P1_RGB_Manager(char led, int state);

#endif

