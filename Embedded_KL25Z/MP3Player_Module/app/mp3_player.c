/*
 * mp3_player.c
 *
 *  Created on: 14/11/2017
 *      Author: Aldo Vargas
 */
#include "mp3_player.h"

static unsigned int bouncer = 0;
static unsigned int bouncerBuff = 0;

void APP_ToggleLed() {
	MAL_Toggle();

}

int APP_ButtonPressed() {

	if (MAL_Read()) {
		bouncer ++;
		return 1;
	} else {
		bouncerBuff = bouncer;
		bouncer = 0;
		return 0;
	}

}

void APP_Check() {

	if (bouncerBuff > 150 && bouncerBuff < 1000){
		APP_ToggleLed();
	}

	if(bouncer > 1000 && bouncer<10000){
		if(bouncer%500 == 0){
			APP_ToggleLed();
		}
	}
	if (bouncer >= 10000) {
		while (APP_ButtonPressed()) {
			MAL_Off();
		}
	}
}
