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

#ifndef GPIO_MP3_H_
#define GPIO_MP3_H_

#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "fsl_port.h"
#include "clock_config.h"
#include "MKL25Z4.h"

void GPIO_Init();

void GPIO_RedON();

void GPIO_RedOFF();

void GPIO_GreenON();

void GPIO_GreenOFF();

void GPIO_BluedON();

void GPIO_BlueOFF();

int GPIO_ButtonRead();

#endif /* GPIO_MP3_H_ */
