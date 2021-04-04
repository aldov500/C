
_main:

;Lab #01.c,1 :: 		void main() {
;Lab #01.c,2 :: 		TRISC=0;
	CLRF       TRISC+0
;Lab #01.c,3 :: 		PORTC=0x055;
	MOVLW      85
	MOVWF      PORTC+0
;Lab #01.c,4 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
