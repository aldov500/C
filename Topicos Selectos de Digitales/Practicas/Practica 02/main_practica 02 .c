/* Librerias y Cabeceras */


/* Definiciones */
#define 	HTZ 		






#define 	SERIAL_PIN	0
#define 	SLOT1_PIN	1
#define 	SLOT2_PIN	2
#define 	SLOT3_PIN	3
#define 	SLOT4_PIN	8

/* Etapas */
#define 	BREAK 		0
#define 	SYNC		1
#define 	NAME		2
#define 	LNAME		3
#define 	SLOT1		4
#define 	SLOT2		5
#define 	SLOT3		6
#define 	SLOT4		7
#define 	LEDS		8

/* Estructura de configuracion para Pin */
static const gpio_pin_config_t pin_ConfigInput = { kGPIO_DigitalInput, 0 };
static const gpio_pin_config_t pin_ConfigOutput = { kGPIO_DigitalOutput, 1 };

/* Prototipos */
void BOARD_InitPins(void);
void TimerConfiguration(void);
void PIT_IRQHandler(void);

/* Nombres */
void pinSecuenceMatch(int index, int secuence[], int* bit_state);
void nameSecuence();
/* Slots */
void slotsCalculate(int* s1, int* s2, int pin);
/* Leds */
void LED_Init(int ledVector[]);
void LED_Codificator(int s11, int s12, int* loop);
void LED_loop(int loop[]);
void RGB_Manager(char led, int state);

/* Secuencia de bits para Nombre */
int secuenceName[] = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 };
/* Secuencia de bits para Apellido */
int secuenceLName[] = { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 };

int state = BREAK;
uint32_t count = 0;

int main(void) {
	/* Configuración inicial */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	TimerConfiguration();

	/* Variables para Slots */
	int slots[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	while (1) {

		switch (state) {

		case BREAK:
			RGB_Manager('R', 1);
			RGB_Manager('G', 1);
			RGB_Manager('B', 1);

			count = 0;
			while (count < 1000) {
				/* El contador comienza en cero y se resetéa si hay una señal activa */
				if (GPIO_ReadPinInput(GPIOB, SERIAL_PIN)) {
					count = 0;

				} else {
					/* Si la señal ha sido negativa por 1 segundo, se cambia al estado de SYNC */
					if (count >= 1000) {

						state = SYNC;
					}
				}
			}

			break;

		case SYNC:
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);
			count = 0;
			while (count < 200) {
				/* Si la señal es baja el contador se reinicia */
				if (!GPIO_ReadPinInput(GPIOB, SERIAL_PIN)) {
					count = 0;
				} else {
					/* Si la señal se levanta por 200 ms cambia de estado */
					if (count >= 200) {
						state = NAME;
					}
				}
			}

			break;

		case NAME:
			RGB_Manager('R', 0);
			RGB_Manager('G', 1);
			RGB_Manager('B', 0);
			nameSecuence(secuenceName);
			break;

		case LNAME:
			RGB_Manager('R', 0);
			RGB_Manager('G', 0);
			RGB_Manager('B', 1);
			nameSecuence(secuenceLName);
			break;

		case SLOT1:
			RGB_Manager('R', 1);
			RGB_Manager('G', 1);
			RGB_Manager('B', 0);
			slotsCalculate(&slots[0], &slots[1], SLOT1_PIN);
			break;

		case SLOT2:
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 1);
			slotsCalculate(&slots[2], &slots[3], SLOT2_PIN);
			break;

		case SLOT3:
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);
			slotsCalculate(&slots[4], &slots[5], SLOT3_PIN);
			break;

		case SLOT4:
			RGB_Manager('R', 0);
			RGB_Manager('G', 0);
			RGB_Manager('B', 1);
			slotsCalculate(&slots[6], &slots[7], SLOT4_PIN);
			break;

		case LEDS:
			RGB_Manager('R', 0);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);
			LED_Init(&slots);
			break;

		default:
			break;

		}

	}

	for (;;) {
		__asm("NOP");
	}
}

/*
 * Funciones de datos para Nombres, desde aqui se hace el cambio en la FSM principal
 *
 * */

/* @param secuence es la secuencia de datos binarios*/
void nameSecuence(int secuence[]) {
	int done = 0;
	int bit_state = 0;
	count = 0;

	/* Mientras la "bandera" no sea 1 */
	while (done == 0) {
		switch (bit_state) {
		case 0:
			/* Ejecuta la función que checa si el bit ingresado es igual al de la secuencia  */
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 1:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 2:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 3:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 4:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 5:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 6:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 7:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 8:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 9:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			break;

		case 10:
			pinSecuenceMatch(bit_state, secuence, &bit_state);
			done = 1;
			break;

		}

	}

	/* Si se termina la secuencia con los 10 bits done se levanta*/
	if (done == 1) {
		/* Para Nombre */
		if (state == NAME)
			state = LNAME;
		/* Para Apellido */
		else if (state == LNAME)
			state = SLOT1;
	}
}

/* @param index de la secuencia
 @param secuence de numeros binarios
 @param bit_state para los cambios de estado */

void pinSecuenceMatch(int index, int secuence[], int* bit_state) {
	/* Si el valor de la lectura es igual a el bit en la secuencia actual */
	if (GPIO_ReadPinInput(GPIOB, SERIAL_PIN) == secuence[index]) {
		/* El contador llega a 50 al menos*/
		if (count > 50) {
			/* Cambia de estado */
			count = 0;
			*bit_state = index + 1;
		}

	} else {
		count = 0;
	}
}

/*
 * Funciones de Slot, desde aqui cambia la FSM
 *
 * */

/* @param s1 para guardar slot 01
 @param s2 ..
 @param pin a leer */
void slotsCalculate(int* s1, int* s2, int pin) {
	int menu = 1;

	while (menu != 3) {
		switch (menu) {
		case 1: /* Funciones Slot 1*/
			/* Debido a que el Slot4 está conectado en GPIOC-Pin_02 hay una condicional especial para el SLOT4 y otra para los demas SLOTS*/
			if (state == SLOT4) {
				count = 0;
				while (GPIO_ReadPinInput(GPIOB, pin) == 1) {

					if (count >= 50) {
						s1 = 1;
						menu = 2;
					}

				}

				while (GPIO_ReadPinInput(GPIOB, pin) == 0) {

					if (count >= 50) {
						s1 = 0;
						menu = 2;
					}
				}
			} else {
				count = 0;
				while (GPIO_ReadPinInput(GPIOB, pin) == 1) {

					if (count >= 50) {
						s1 = 1;
						menu = 2;
					}

				}

				while (GPIO_ReadPinInput(GPIOB, pin) == 0) {

					if (count > 45) {
						s1 = 0;
						menu = 2;
					}
				}

			}

			break;

		case 2: /* Funciones Slot 2*/
			if (state == SLOT4) {
				count = 0;
				while (GPIO_ReadPinInput(GPIOB, pin) == 1) {

					if (count > 45) {
						s2 = 1;
						menu = 3;
					}

				}

				while (GPIO_ReadPinInput(GPIOB, pin) == 0) {

					if (count > 45) {
						s2 = 0;
						menu = 3;
					}
				}
			} else {
				count = 0;
				while (GPIO_ReadPinInput(GPIOB, pin) == 1) {

					if (count > 45) {
						s2 = 1;
						menu = 3;
					}

				}

				while (GPIO_ReadPinInput(GPIOB, pin) == 0) {

					if (count > 45) {
						s2 = 0;
						menu = 3;
					}
				}

			}

			break;

		}

	}
	switch (state) {
	case SLOT1:
		state = SLOT2;

		break;
	case SLOT2:
		state = SLOT3;

		break;
	case SLOT3:
		state = SLOT4;

		break;
	case SLOT4:
		state = LEDS;

		break;

	}

}

/*
 * Funciones de LEDS, desde aqui cambia la FSM
 *
 * */
void LED_Init(int ledVector[]) {
	/* Crea un vector para la secuencia */
	int loop[10];

	/* codifica para los colores, con los dos slots por color y el valor a guardar en loop*/
	LED_Codificator(ledVector[0], ledVector[1], &loop[0]);
	LED_Codificator(ledVector[2], ledVector[3], &loop[1]);
	LED_Codificator(ledVector[4], ledVector[5], &loop[2]);
	LED_Codificator(ledVector[6], ledVector[7], &loop[3]);

	/* Comienza el ciclo de colores de cada slot */
	LED_loop(loop);

}
/* @param s11 slot 1 del color
 @param s12 slot 2 del color
 @param loop es el valor a guardar para las secuencias
 */
void LED_Codificator(int s11, int s12, int* loop) {
	if (s11) {
		if (s12) {
			loop = 1;
		} else {
			loop = 2;
		}
	} else {
		if (s12) {
			loop = 3;
		} else {
			loop = 4;
		}

	}
}

/* @param loop contiene la secuencia de colores 
 */
void LED_loop(int loop[]) {
	int i = 0;
	int var = 0;
	/* Mientras la lectura sea negativa */
	while (i < 10) {
		var = loop[i];
		i++;
		count = 0;
		switch (var) {

		case 1:
			/* Color */
			count = 0;
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);

			break;
		case 2:
			count = 0;
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);



			break;
		case 3:
			count = 0;
			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);

			break;
		case 4:

			RGB_Manager('R', 1);
			RGB_Manager('G', 0);
			RGB_Manager('B', 0);

			break;

		}

		RGB_Manager('R', 0);
		RGB_Manager('G', 0);
		RGB_Manager('B', 0);

		/* Si se manda señal de almenos 1 segundo*/
		if (GPIO_ReadPinInput(GPIOB, SERIAL_PIN)) {
			count = 0;
			if (count > 1000) {
				RGB_Manager('R', 0);
				RGB_Manager('G', 0);
				RGB_Manager('B', 0);
				state = BREAK;
			}

		}

	}
}
/*
 * Funciones de Configuracion básica
 *
 * */

/* Configuración de registros para los pines por medio de GPIO */
void BOARD_InitPins(void) {
	/* Reloj Activado */
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);

	/* Multiplexeo seleccionado */

	/* Puerto Serial */
	PORT_SetPinMux(PORTB, 0u, kPORT_MuxAsGpio);
	/* Slot 01 */
	PORT_SetPinMux(PORTB, 1u, kPORT_MuxAsGpio);
	/* Slot 02 */
	PORT_SetPinMux(PORTB, 2u, kPORT_MuxAsGpio);
	/* Slot 03 */
	PORT_SetPinMux(PORTB, 3u, kPORT_MuxAsGpio);
	/* Slot 04 */
	PORT_SetPinMux(PORTB, 8u, kPORT_MuxAsGpio);

	PORT_SetPinMux(PORTB, 18u, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 19u, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 1u, kPORT_MuxAsGpio);

	/* Configuracion de pines */
	GPIO_PinInit(GPIOB, 0u, &pin_ConfigInput);
	GPIO_PinInit(GPIOB, 1u, &pin_ConfigInput);
	GPIO_PinInit(GPIOB, 2u, &pin_ConfigInput);
	GPIO_PinInit(GPIOB, 3u, &pin_ConfigInput);
	GPIO_PinInit(GPIOB, 8u, &pin_ConfigInput);

	GPIO_PinInit(GPIOB, 18u, &pin_ConfigOutput);
	GPIO_PinInit(GPIOB, 19u, &pin_ConfigOutput);
	GPIO_PinInit(GPIOD, 1u, &pin_ConfigOutput);

}
/* Configuración de registros para Timmer */
void TimerConfiguration(void) {
	/* 1/48Mhz = 48000 ciclos */
	int LDV = HTZ;
	/* Activa el Reloj para PIT */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	/* Enciende el PIT */
	PIT->MCR = 0;
	/* Interrupcion cada  0.01s */
	PIT->CHANNEL[0].LDVAL = LDV;
	/* Activa las interrupciones */
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
	NVIC_EnableIRQ(PIT_IRQn);

}

/* Funcion periodica del timer por medio de Interrupción */
void PIT_IRQHandler(void) {
	count = count + 1;
	if (count > 1200)
		count = 0;

	/* Limpia bandera de interrupciones */
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
}

/* Función para controlar los LEDS de la tarjeta */
void RGB_Manager(char led, int statergb) {
	switch (led) {
	case 'R':
		if (statergb == 1)
			GPIO_ClearPinsOutput(GPIOB, 1 << 18u);
		else if (statergb == 0)
			GPIO_SetPinsOutput(GPIOB, 1 << 18u);
		break;

	case 'G':
		if (statergb == 1)
			GPIO_ClearPinsOutput(GPIOB, 1 << 19u);
		else if (statergb == 0)
			GPIO_SetPinsOutput(GPIOB, 1 << 19u);
		break;

	case 'B':
		if (statergb == 1)
			GPIO_ClearPinsOutput(GPIOD, 1 << 1u);
		else if (statergb == 0)
			GPIO_SetPinsOutput(GPIOD, 1 << 1u);
		break;

	}
}
