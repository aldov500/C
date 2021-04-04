/*
 * P3_Lights.h
 *
 *  Created on: 01/11/2017
 *      Author: Aldo Vargas
 */

#ifndef P3_LIGHTS_H_
#define P3_LIGHTS_H_

#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"

#include "kl25z_pin.h"
#include "kl25z_pwm.h"

static const gpio_pin_config_t pin_configOutput = { kGPIO_DigitalOutput, 0 };
static const gpio_pin_config_t pin_configInput = { kGPIO_DigitalInput, 0 };


typedef struct Practica3_Conf{
	/* Salidas */
	PIN lightFog;
	PWM lightMain;

	PIN lightDirL;
	PIN lightDirR;

	PWM lightBrake;
	PIN lightReverse;

	/* Entradas */
	PIN buttonFog;

	PIN buttonMain;
	PIN switchModePosicion;
	PIN switchModeCruce;

	PIN switchDirL;
	PIN switchDirR;
	PIN buttonPreventive;

	PIN buttonBrake;
	PIN buttonReverse;

	/* Banderas */

} P3;



void P3_Init(P3* p3);

void P3_Light_On(PIN* light);
void P3_Light_Off(PIN* light);

void P3_Light_PWM_Off(PWM* main);
void P3_Light_PWM_On(PWM* main);
void P3_Light_Main_ChangeMode(PWM* main, char mode);
void P3_Light_Brake_ChangeMode(PWM* main, char mode);

void P3_Light_Dir_On(PIN* dir, uint32_t count);
void P3_Light_Dir_Preventive(PIN* left, PIN* right, uint32_t count);


#endif /* P3_LIGHTS_H_ */
