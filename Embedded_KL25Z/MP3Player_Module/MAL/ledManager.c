/*
 * ledManager.c
 *
 *  Created on: 12/11/2017
 *      Author: Aldo Vargas
 */

#include "ledManager.h"


void MAL_Off(){
	GPIO_RedOFF();
	GPIO_BlueOFF();
	GPIO_GreenOFF();
}
void MAL_Toggle() {
	static unsigned char tog = 0;

	switch (tog) {
	case 0:
		GPIO_RedON();
		GPIO_GreenOFF();
		GPIO_BlueOFF();
		tog = 1;
		break;

	case 1:
		GPIO_RedOFF();
		GPIO_GreenON();
		GPIO_BlueOFF();
		tog = 2;
		break;

	case 2:
		GPIO_RedOFF();
		GPIO_GreenOFF();
		GPIO_BlueON();
		tog = 3;
	case 3:
		GPIO_RedON();
		GPIO_GreenON();
		GPIO_BlueOFF();
		tog = 4;
		break;

	case 4:
		GPIO_RedOFF();
		GPIO_GreenON();
		GPIO_BlueON();
		tog = 5;
		break;

	case 5:
		GPIO_RedON();
		GPIO_GreenOFF();
		GPIO_BlueON();
		tog = 0;
		break;

	}
}

int MAL_Read(){
	if(GPIO_ButtonRead() == 1){
		return 1;
	}
	else{
		return 0;
	}
}
