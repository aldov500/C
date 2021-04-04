
_main:

;08 Interrupciones.c,3 :: 		void main()
;08 Interrupciones.c,5 :: 		OPTION_REG=0xD7;
	MOVLW      215
	MOVWF      OPTION_REG+0
;08 Interrupciones.c,6 :: 		INTCON=0xA0;
	MOVLW      160
	MOVWF      INTCON+0
;08 Interrupciones.c,7 :: 		TMR0=0x00;
	CLRF       TMR0+0
;08 Interrupciones.c,9 :: 		TRISC=0xFE;
	MOVLW      254
	MOVWF      TRISC+0
;08 Interrupciones.c,10 :: 		PORTC=0x00;
	CLRF       PORTC+0
;08 Interrupciones.c,12 :: 		while(8)
L_main0:
;08 Interrupciones.c,13 :: 		{}
	GOTO       L_main0
;08 Interrupciones.c,14 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;08 Interrupciones.c,16 :: 		void interrupt()
;08 Interrupciones.c,18 :: 		if (INTCON.TMR0IF)
	BTFSS      INTCON+0, 2
	GOTO       L_interrupt2
;08 Interrupciones.c,20 :: 		cuenta++;
	INCF       _cuenta+0, 1
;08 Interrupciones.c,22 :: 		if(cuenta==7)
	MOVF       _cuenta+0, 0
	XORLW      7
	BTFSS      STATUS+0, 2
	GOTO       L_interrupt3
;08 Interrupciones.c,24 :: 		cuenta=0;
	CLRF       _cuenta+0
;08 Interrupciones.c,25 :: 		PORTC.RC0=~PORTC.RC0;
	MOVLW      1
	XORWF      PORTC+0, 1
;08 Interrupciones.c,26 :: 		INTCON.TMR0IF=0;
	BCF        INTCON+0, 2
;08 Interrupciones.c,27 :: 		}
L_interrupt3:
;08 Interrupciones.c,28 :: 		INTCON.TMR0IF=0;
	BCF        INTCON+0, 2
;08 Interrupciones.c,29 :: 		}
L_interrupt2:
;08 Interrupciones.c,30 :: 		}
L_end_interrupt:
L__interrupt6:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt
