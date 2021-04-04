#include "P3_Lights.h"

void delay(int ms);

int main(void) {
	P3 car;
	P3_Init(&car);


	while (1) {

		if (P3_ReadSignal(car.buttonFog)) {
			P3_Light_On(&car.lightFog);
			delay(1000);
		} else {
			P3_Light_Off(&car.lightFog);
			delay(1000);
		}

//		if(P3_ReadSignal(car.buttonMain)){
//			P3_Light_PWM_On(&car.lightMain);
//		} else {
//			P3_Light_PWM_Off(&car.lightMain);
//		}

	}

	return 0;
}

void delay(int ms){
	ms = 1000 * ms;
	for(int i=0; i<=ms; i++){}
}
