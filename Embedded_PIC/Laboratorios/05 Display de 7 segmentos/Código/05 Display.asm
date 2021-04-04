
_main:

;05 Display.c,4 :: 		void main() {
;05 Display.c,5 :: 		TRISC=0;
	CLRF       TRISC+0
;05 Display.c,7 :: 		while (1)
L_main0:
;05 Display.c,9 :: 		for (cuenta=0;cuenta!=10;cuenta+=1)
	CLRF       _cuenta+0
L_main2:
	MOVF       _cuenta+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_main3
;05 Display.c,11 :: 		PORTC=TABLA[cuenta];
	MOVF       _cuenta+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;05 Display.c,12 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;05 Display.c,9 :: 		for (cuenta=0;cuenta!=10;cuenta+=1)
	INCF       _cuenta+0, 1
;05 Display.c,13 :: 		}
	GOTO       L_main2
L_main3:
;05 Display.c,14 :: 		}
	GOTO       L_main0
;05 Display.c,15 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
