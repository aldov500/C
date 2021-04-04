/*
 * mp3_player.c
 *
 *  Created on: 14/11/2017
 *      Author: Aldo Vargas
 */
#include "mp3_player.h"

static unsigned int uibuncer = 0;
static unsigned int uibouncerBuff = 0;


void APP_Init(){
	ledManager_Init();
}

void APP_Execute(){
	APP_Check();
	APP_ReadButton();
}
void APP_ToggleLed() {
	ledManager_Toggle();

}

int APP_ReadButton() {

	if (ledManager_Read()) {
		uibuncer +=5;
		return 1;
	} else {
		uibouncerBuff = uibuncer;
		uibuncer = 0;
		return 0;
	}

}

void APP_Check() {

	if (uibouncerBuff > 100 && uibouncerBuff < 1000){
		APP_ToggleLed();
	}

	if(uibuncer > 1000 && uibuncer<10000){
		if(uibuncer%500 == 0){
			APP_ToggleLed();
		}
	}
	if (uibuncer >= 10000) {
		while (APP_ReadButton()) {
			ledManager_Off();
		}
	}
}
