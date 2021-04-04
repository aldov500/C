/*
 * mp3_player.h
 *
 *  Created on: 14/11/2017
 *      Author: Aldo Vargas
 */

#ifndef MP3_PLAYER_H_
#define MP3_PLAYER_H_

#include <MAL/ledManager.h>

void APP_Init();

void APP_Execute();

void APP_ToggleLed();

void APP_Check();

int APP_ReadButton();

#endif /* MP3_PLAYER_H_ */
