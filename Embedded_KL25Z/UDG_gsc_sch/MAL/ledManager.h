/*
 * ledManager.h
 *
 *  Created on: 12/11/2017
 *      Author: Aldo Vargas
 */

#ifndef LEDMANAGER_H_
#define LEDMANAGER_H_

#include <HAL/gpio_mp3.h>

void ledManager_Init();
void ledManager_Off();
void ledManager_Toggle();
int ledManager_Read();




#endif /* LEDMANAGER_H_ */
