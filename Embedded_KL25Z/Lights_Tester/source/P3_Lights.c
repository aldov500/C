#include "P3_Lights.h"

/* Salidas */

/* Niebla */
#define FOGCLK		kCLOCK_PortB
#define FOGMUX		kPORT_MuxAsGpio
#define FOGPORT		PORTB
#define FOGGPIO		GPIOB
#define FOGPIN		0u
/* Principales */
#define MAINTPM		TPM1
#define MAINPORT	PORTB
#define MAINCLK		kCLOCK_PortB
#define MAINMUX		kPORT_MuxAlt3
#define MAINCNHL	1
#define MAINPIN		1u
/* Direccionales */
#define DIRLCLK		kCLOCK_PortB
#define DIRLMUX		kPORT_MuxAsGpio
#define DIRLPORT	PORTB
#define DIRLGPIO	GPIOB
#define DIRLPIN		2u
#define DIRRCLK		kCLOCK_PortB
#define DIRRMUX		kPORT_MuxAsGpio
#define DIRRPORT	PORTB
#define DIRRGPIO	GPIOB
#define DIRRPIN		3u
/* Freno */
#define BRAKETPM	TPM0
#define BRAKEPORT	PORTC
#define BRAKECLK	kCLOCK_PortC
#define BRAKEMUX	kPORT_MuxAlt4
#define BRAKECNHL	1
#define BRAKEPIN	2u
/* Reversa */
#define REVCLK		kCLOCK_PortC
#define REVMUX		kPORT_MuxAsGpio
#define REVPORT		PORTC
#define REVGPIO		GPIOC
#define REVPIN		1u

/* Entradas */

/* Boton Niebla */
#define FOGBUTCLK		kCLOCK_PortB
#define FOGBUTMUX		kPORT_MuxAsGpio
#define FOGBUTPORT		PORTB
#define FOGBUTGPIO		GPIOB
#define FOGBUTPIN		8u
/* Boton Principal */
#define MAINBUTCLK		kCLOCK_PortB
#define MAINBUTMUX		kPORT_MuxAsGpio
#define MAINBUTPORT		PORTB
#define MAINBUTGPIO		GPIOB
#define MAINBUTPIN		9u
/* Dir Izq */
#define DIRLBUTCLK		kCLOCK_PortB
#define DIRLBUTMUX		kPORT_MuxAsGpio
#define DIRLBUTPORT		PORTB
#define DIRLBUTGPIO		GPIOB
#define DIRLBUTPIN		10u
/* Dir Der */
#define DIRRBUTCLK		kCLOCK_PortB
#define DIRRBUTMUX		kPORT_MuxAsGpio
#define DIRRBUTPORT		PORTB
#define DIRRBUTGPIO		GPIOB
#define DIRRBUTPIN		11u
/* Boton Freno */
#define BRAKEBUTCLK		kCLOCK_PortE
#define BRAKEBUTMUX		kPORT_MuxAsGpio
#define BRAKEBUTPORT	PORTE
#define BRAKEBUTGPIO	GPIOE
#define BRAKEBUTPIN		2u
/* Boton Reversa */
#define REVBUTCLK		kCLOCK_PortE
#define REVBUTMUX		kPORT_MuxAsGpio
#define REVBUTPORT		PORTE
#define REVBUTGPIO		GPIOE
#define REVBUTPIN		3u
/* Boton Preventivas */
#define PREVBUTCLK		kCLOCK_PortE
#define PREVBUTMUX		kPORT_MuxAsGpio
#define PREVBUTPORT		PORTE
#define PREVBUTGPIO		GPIOE
#define PREVBUTPIN		4u
/* Boton Modo Posicion */
#define POSBUTCLK		kCLOCK_PortE
#define POSBUTMUX		kPORT_MuxAsGpio
#define POSBUTPORT		PORTE
#define POSBUTGPIO		GPIOE
#define POSBUTPIN		20u
/* Boton Modo Cruce */
#define CRUBUTCLK		kCLOCK_PortE
#define CRUBUTMUX		kPORT_MuxAsGpio
#define CRUBUTPORT		PORTE
#define CRUBUTGPIO		GPIOE
#define CRUBUTPIN		21u

void P3_Init(P3* p3) {

	/* Salidas*/

	/* Luces de Niebla*/
	PIN_New(&p3->lightFog, FOGCLK, FOGMUX, FOGPORT, FOGGPIO, pin_configOutput,
	FOGPIN);
	PIN_Init(&p3->lightFog);

	/* Principales */
	PWM_Init(&p3->lightMain, MAINTPM, MAINPORT, MAINCLK, MAINMUX, MAINCNHL,
	MAINPIN);

	/* Direccionales */
	PIN_New(&p3->lightDirL, DIRLCLK, DIRLMUX, DIRLPORT, DIRLGPIO,
			pin_configOutput,
			DIRLPIN);
	PIN_Init(&p3->lightDirL);

	PIN_New(&p3->lightDirR, DIRRCLK, DIRRMUX, DIRRPORT, DIRRGPIO,
			pin_configOutput,
			DIRRPIN);
	PIN_Init(&p3->lightDirR);

	/* Frenos */
	PWM_Init(&p3->lightBrake, BRAKETPM, BRAKEPORT, BRAKECLK, BRAKEMUX,
	BRAKECNHL, BRAKEPIN);

	/* Reversa */
	PIN_New(&p3->lightReverse, REVCLK, REVMUX, REVPORT, REVGPIO,
			pin_configOutput,
			REVPIN);
	PIN_Init(&p3->lightReverse);

	/* Entradas */

	/* Luces de Niebla */
	PIN_New(&p3->buttonFog, FOGBUTCLK, FOGBUTMUX, FOGBUTPORT, FOGBUTGPIO,
			pin_configInput, FOGBUTPIN);
	PIN_Init(&p3->buttonFog);

	/* Luces principales */
	PIN_New(&p3->buttonMain, MAINBUTCLK, MAINBUTMUX, MAINBUTPORT, MAINBUTGPIO,
			pin_configInput, MAINBUTPIN);
	PIN_Init(&p3->buttonMain);

	/* Dir Izq */
	PIN_New(&p3->switchDirL, DIRLBUTCLK, DIRLBUTMUX, DIRLBUTPORT, DIRLBUTGPIO,
			pin_configInput, DIRLBUTPIN);
	PIN_Init(&p3->switchDirL);

	/* Dir Der */
	PIN_New(&p3->switchDirR, DIRRBUTCLK, DIRRBUTMUX, DIRRBUTPORT, DIRRBUTGPIO,
			pin_configInput, DIRRBUTPIN);
	PIN_Init(&p3->switchDirR);

	/* Freno */
	PIN_New(&p3->buttonBrake, BRAKEBUTCLK, BRAKEBUTMUX, BRAKEBUTPORT,
	BRAKEBUTGPIO, pin_configInput, BRAKEBUTPIN);
	PIN_Init(&p3->buttonBrake);
	/* Reversa */
	PIN_New(&p3->buttonReverse, REVBUTCLK, REVBUTMUX, REVBUTPORT, REVBUTGPIO,
			pin_configInput, REVBUTPIN);
	PIN_Init(&p3->buttonReverse);

	/* Preventivas */
	PIN_New(&p3->buttonPreventive, PREVBUTCLK, PREVBUTMUX, PREVBUTPORT,
	PREVBUTGPIO, pin_configInput, PREVBUTPIN);
	PIN_Init(&p3->buttonPreventive);

	/* Posicion */
	PIN_New(&p3->switchModePosicion, POSBUTCLK, POSBUTMUX, POSBUTPORT,
	POSBUTGPIO, pin_configInput, POSBUTPIN);
	PIN_Init(&p3->switchModePosicion);

	/* Cruce */
	PIN_New(&p3->switchModeCruce, CRUBUTCLK, CRUBUTMUX, CRUBUTPORT, CRUBUTGPIO,
			pin_configInput, CRUBUTPIN);
	PIN_Init(&p3->switchModeCruce);

}

void P3_Light_On(PIN* light) {
	PIN_SetHigh(light);
}

void P3_Light_Off(PIN* light) {
	PIN_SetLow(light);
}

void P3_Light_PWM_On(PWM* main) {
	PWM_Start(main);
}

void P3_Light_PWM_Off(PWM* main) {
	PWM_Stop(main);
}

void P3_Light_Main_ChangeMode(PWM* main, char mode) {
	P3_Light_PWM_Off(main);
	switch (mode) {
	case 'C':
		PWM_Update(main, 100);
		break;

	case 'P':
		PWM_Update(main, 20);
		break;

	case 'X':
		PWM_Update(main, 60);
		break;
	}
	P3_Light_PWM_On(main);
}

void P3_Light_Brake_ChangeMode(PWM* main, char mode) {
	P3_Light_PWM_Off(main);
	switch (mode) {
	case 'N':
		PWM_Update(main, 100);
		break;

	case 'P':
		PWM_Update(main, 40);
		break;
	}
	P3_Light_PWM_On(main);
}

void P3_Light_Dir_On(PIN* dir, uint32_t count) {

	if ((count < 400)) {
		P3_Light_On(dir);
	} else if ((count >= 400) && (count < 800)) {
		P3_Light_Off(dir);
	} else if ((count >= 800) && (count < 1200)) {
		P3_Light_On(dir);
	} else if ((count >= 1200) && (count < 1400)) {
		P3_Light_Off(dir);
	}

}

void P3_Light_Dir_Preventive(PIN* left, PIN* right, uint32_t count) {
	if (count < 800) {
		P3_Light_On(left);
		P3_Light_On(right);

	} else if (count >= 800) {
		P3_Light_Off(left);
		P3_Light_Off(right);

	}
}

int P3_ReadSignal(PIN* read) {
	return PIN_Read(read);
}

