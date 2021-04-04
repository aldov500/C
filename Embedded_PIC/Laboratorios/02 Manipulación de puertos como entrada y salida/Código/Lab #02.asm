
_main:

;Lab #02.c,1 :: 		void main()
;Lab #02.c,3 :: 		TRISC=0x00;
	CLRF       TRISC+0
;Lab #02.c,4 :: 		OPTION_REG=0x7F;
	MOVLW      127
	MOVWF      OPTION_REG+0
;Lab #02.c,5 :: 		ANSELH=0x00;
	CLRF       ANSELH+0
;Lab #02.c,6 :: 		PORTB=0xFF;
	MOVLW      255
	MOVWF      PORTB+0
;Lab #02.c,8 :: 		while (8)
L_main0:
;Lab #02.c,10 :: 		PORTC=PORTB;
	MOVF       PORTB+0, 0
	MOVWF      PORTC+0
;Lab #02.c,11 :: 		}
	GOTO       L_main0
;Lab #02.c,12 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
