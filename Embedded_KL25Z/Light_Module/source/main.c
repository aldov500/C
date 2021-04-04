/*
 * main.c
 *
 *  Created on: 01/11/2017
 *      Author: Aldo Vargas
 */

#include "P3_Lights.h"

void TimerConfiguration(void);
void PIT_IRQHandler(void);

P3 simulatedCar;
uint32_t countMain, countButton;
uint32_t debMain, debFog, debBrake, debReverse, debPreventive;
bool bMain, bFog, bBrake, bReverse, bPreventive;

void readHandler(PIN* button, uint32_t* bouncer, bool* flag, uint32_t* count);

int main(void) {

	countMain = 0;
	bPreventive = false;
	bFog = false;
	bMain = false;

	TimerConfiguration();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	P3_Init(&simulatedCar);

	while (1) {

		if (bMain) {
			P3_Light_PWM_On(&simulatedCar.lightMain);
		} else {
			P3_Light_PWM_Off(&simulatedCar.lightMain);
		}

	}
}

void TimerConfiguration(void) {
	/* Activa el Reloj para PIT */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	/* Enciende el PIT */
	PIT->MCR = 0;
	/* Interrupcion cada  0.01s */
	PIT->CHANNEL[0].LDVAL = 24000;
	/* Activa las interrupciones */
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
	NVIC_EnableIRQ(PIT_IRQn);

}

void PIT_IRQHandler(void) {
	countMain = countMain + 1;

	if(countMain % 5 == 0){
		readHandler(&simulatedCar.buttonFog, &debFog, &bFog, &countButton);
	}
	else if(countMain % 10 == 0){
		readHandler(&simulatedCar.buttonMain, &debMain, &bMain, &countButton);
	}

	if (countMain > 1600)
		countMain = 0;

	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
}

void readHandler(PIN* button, uint32_t* bouncer, bool* flag, uint32_t* count) {
	if (P3_ReadSignal(button)) {
		*count = *count + 1;
	} else {
		*bouncer = *count;
		*count = 0;
	}

	if (*bouncer > 80 && *bouncer < 300) {
		*flag = !*flag;
	}
}
