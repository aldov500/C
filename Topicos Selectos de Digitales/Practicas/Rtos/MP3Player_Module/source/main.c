#include "kl25z_pin.h"

void TimerConfiguration(void);
void PIT_IRQHandler(void);

unsigned long ulCount, ulCountBuff;

PIN pRed, pGreen, pBlue;
PIN pButton;

void LED_Toggle(int led);

int main(void) {
	TimerConfiguration();

	PIN_New(&pRed, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB,
			pin_configOutput, 18);
	PIN_Init(&pRed);

	PIN_New(&pGreen, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB,
			pin_configOutput, 19);
	PIN_Init(&pGreen);

	PIN_New(&pBlue, kCLOCK_PortD, kPORT_MuxAsGpio, PORTD, GPIOD,
			pin_configOutput, 1);
	PIN_Init(&pBlue);

	PIN_New(&pButton, kCLOCK_PortB, kPORT_MuxAsGpio, PORTB, GPIOB,
			pin_configInput, 0);
	PIN_Init(&pButton);

	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	char cSecuence = 0;

	while (1) {

		if (ulCountBuff > 100 && ulCountBuff < 800) {
			LED_Toggle(cSecuence);
			cSecuence++;
			if (cSecuence > 2)
				cSecuence = 0;
		}

		while (ulCount > 1000 && ulCount < 10000) {
			if ((ulCount % 500) == 0) {
				LED_Toggle(cSecuence);
				ulCount++;
				cSecuence++;
				if (cSecuence > 2)
					cSecuence = 0;
			}
		}

		if (ulCount > 10000) {
			PIN_SetLow(&pRed);
			PIN_SetLow(&pGreen);
			PIN_SetLow(&pBlue);
		}

	}

	return 0;

}

void LED_Toggle(int led) {
	switch (led) {
	case 0: {
		PIN_SetHigh(&pGreen);
		PIN_SetLow(&pRed);
		PIN_SetHigh(&pBlue);
	}
		break;
	case 1: {
		PIN_SetLow(&pGreen);
		PIN_SetHigh(&pRed);
		PIN_SetHigh(&pBlue);
	}
		break;
	case 2: {
		PIN_SetHigh(&pGreen);
		PIN_SetHigh(&pRed);
		PIN_SetLow(&pBlue);
	}
		break;

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

	if (PIN_Read(&pButton) == 1) {
		ulCount++;

	} else if (PIN_Read(&pButton) == 0) {
		ulCountBuff = ulCount;
		ulCount = 0;
	}

	/* Limpia bandera de interrupciones */
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
}
