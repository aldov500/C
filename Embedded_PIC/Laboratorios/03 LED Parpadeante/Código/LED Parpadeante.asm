
_main:

;LED Parpadeante.c,1 :: 		void main() {
;LED Parpadeante.c,3 :: 		TRISC.RC0= 0; //Configura el puerto C como Salida, RC=Solo el bit 0.
	BCF        TRISC+0, 0
;LED Parpadeante.c,5 :: 		while (8) // Ciclo infinito
L_main0:
;LED Parpadeante.c,7 :: 		PORTC.RC0^=1;
	MOVLW      1
	XORWF      PORTC+0, 1
;LED Parpadeante.c,8 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;LED Parpadeante.c,9 :: 		}
	GOTO       L_main0
;LED Parpadeante.c,10 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
