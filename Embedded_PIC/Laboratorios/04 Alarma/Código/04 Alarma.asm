
_main:

;04 Alarma.c,1 :: 		void main() {
;04 Alarma.c,2 :: 		TRISC=0;
	CLRF       TRISC+0
;04 Alarma.c,3 :: 		OPTION_REG=0x7F;
	MOVLW      127
	MOVWF      OPTION_REG+0
;04 Alarma.c,4 :: 		ANSELH=0;
	CLRF       ANSELH+0
;04 Alarma.c,5 :: 		PORTB=0xFF;
	MOVLW      255
	MOVWF      PORTB+0
;04 Alarma.c,7 :: 		while (8)
L_main0:
;04 Alarma.c,9 :: 		if(PORTB.RB0)
	BTFSS      PORTB+0, 0
	GOTO       L_main2
;04 Alarma.c,11 :: 		PORTC=PORTB&0x77;
	MOVLW      119
	ANDWF      PORTB+0, 0
	MOVWF      PORTC+0
;04 Alarma.c,12 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;04 Alarma.c,13 :: 		PORTC=1;
	MOVLW      1
	MOVWF      PORTC+0
;04 Alarma.c,14 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;04 Alarma.c,15 :: 		}
	GOTO       L_main5
L_main2:
;04 Alarma.c,18 :: 		PORTC=0;
	CLRF       PORTC+0
;04 Alarma.c,19 :: 		}
L_main5:
;04 Alarma.c,20 :: 		}
	GOTO       L_main0
;04 Alarma.c,21 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
