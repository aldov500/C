#include <app/mp3_player.h>

void TimerConfiguration(void);
void PIT_IRQHandler(void);

unsigned static long count;

int main(void) {
	TimerConfiguration();

	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	GPIO_Init();

	count = 0;

	while (1) {

	}
	return 0;
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
	count++;

	APP_ButtonPressed();
	APP_Check();

	/* Limpia bandera de interrupciones */
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
}
