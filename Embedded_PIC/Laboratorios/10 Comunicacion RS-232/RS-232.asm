
_main:

;RS-232.c,1 :: 		void main()
;RS-232.c,3 :: 		TXSTA.SYNC=0;
	BCF        TXSTA+0, 4
;RS-232.c,4 :: 		TXSTA.BRGH=0;
	BCF        TXSTA+0, 2
;RS-232.c,5 :: 		BAUDCTL.BRG16=0;
	BCF        BAUDCTL+0, 3
;RS-232.c,7 :: 		SPBRG=25;
	MOVLW      25
	MOVWF      SPBRG+0
;RS-232.c,9 :: 		RCSTA.SPEN=1;
	BSF        RCSTA+0, 7
;RS-232.c,10 :: 		RCSTA.CREN=1;
	BSF        RCSTA+0, 4
;RS-232.c,11 :: 		TXSTA.TXEN=1;
	BSF        TXSTA+0, 5
;RS-232.c,13 :: 		PIE1.RCIE=1;
	BSF        PIE1+0, 5
;RS-232.c,14 :: 		INTCON.PEIE=1;
	BSF        INTCON+0, 6
;RS-232.c,15 :: 		INTCON.GIE=1;
	BSF        INTCON+0, 7
;RS-232.c,17 :: 		TRISD=0;
	CLRF       TRISD+0
;RS-232.c,18 :: 		PORTD=0xFF;
	MOVLW      255
	MOVWF      PORTD+0
;RS-232.c,19 :: 		TRISA.RA4=1;
	BSF        TRISA+0, 4
;RS-232.c,21 :: 		while(8)
L_main0:
;RS-232.c,23 :: 		if (!PORTA.RA4)
	BTFSC      PORTA+0, 4
	GOTO       L_main2
;RS-232.c,25 :: 		TXREG='1';
	MOVLW      49
	MOVWF      TXREG+0
;RS-232.c,26 :: 		while(!PORTA.RA4);
L_main3:
	BTFSC      PORTA+0, 4
	GOTO       L_main4
	GOTO       L_main3
L_main4:
;RS-232.c,27 :: 		}
L_main2:
;RS-232.c,28 :: 		}
	GOTO       L_main0
;RS-232.c,29 :: 		}
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

;RS-232.c,31 :: 		void interrupt()
;RS-232.c,33 :: 		if (PIR1.RCIF)
	BTFSS      PIR1+0, 5
	GOTO       L_interrupt5
;RS-232.c,35 :: 		PORTD=RCREG;
	MOVF       RCREG+0, 0
	MOVWF      PORTD+0
;RS-232.c,36 :: 		}
L_interrupt5:
;RS-232.c,37 :: 		}
L_end_interrupt:
L__interrupt8:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt
