
_main:

;07 Timer.c,1 :: 		void main()
;07 Timer.c,3 :: 		OPTION_REG=0xF8;
	MOVLW      248
	MOVWF      OPTION_REG+0
;07 Timer.c,4 :: 		TRISC=0x00;
	CLRF       TRISC+0
;07 Timer.c,5 :: 		PORTC=0x00;
	CLRF       PORTC+0
;07 Timer.c,6 :: 		TMR0=0x00;
	CLRF       TMR0+0
;07 Timer.c,8 :: 		while (8){
L_main0:
;07 Timer.c,9 :: 		PORTC=TMR0;
	MOVF       TMR0+0, 0
	MOVWF      PORTC+0
;07 Timer.c,10 :: 		}
	GOTO       L_main0
;07 Timer.c,11 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
