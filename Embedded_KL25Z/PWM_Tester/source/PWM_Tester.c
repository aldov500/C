#include "kl25z_pwm.h"

PWM rojo;


int main(void) {

	/* Board pin, clock, debug console init */
	//BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	PWM_Init(&rojo, TPM2, PORTB, kCLOCK_PortB, kPORT_MuxAlt3,  0, 18);


	PWM_Start(&rojo);


	while (1) {
		PWM_Update(&rojo, 60);

	}
}
