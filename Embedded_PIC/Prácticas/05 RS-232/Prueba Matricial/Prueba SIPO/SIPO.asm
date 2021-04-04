
_main:

;SIPO.c,4 :: 		void main()
;SIPO.c,6 :: 		TRISD=0;
	CLRF       TRISD+0
;SIPO.c,7 :: 		PORTB=0;
	CLRF       PORTB+0
;SIPO.c,9 :: 		while (8)
L_main0:
;SIPO.c,11 :: 		Portd.Rd1=1;
	BSF        PORTD+0, 1
;SIPO.c,12 :: 		Portd.Rd0=1;
	BSF        PORTD+0, 0
;SIPO.c,13 :: 		Portd.Rd0=0;
	BCF        PORTD+0, 0
;SIPO.c,14 :: 		delay_ms(400);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
;SIPO.c,16 :: 		clk=14;
	MOVLW      14
	MOVWF      _clk+0
;SIPO.c,17 :: 		while (clk)
L_main3:
	MOVF       _clk+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main4
;SIPO.c,19 :: 		Pulso();
	CALL       _Pulso+0
;SIPO.c,20 :: 		}
	GOTO       L_main3
L_main4:
;SIPO.c,22 :: 		Portd.Rd1=0;
	BCF        PORTD+0, 1
;SIPO.c,23 :: 		Portd.Rd0=0;
	BCF        PORTD+0, 0
;SIPO.c,24 :: 		Portd.Rd0=1;
	BSF        PORTD+0, 0
;SIPO.c,26 :: 		}
	GOTO       L_main0
;SIPO.c,27 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Pulso:

;SIPO.c,29 :: 		void Pulso()
;SIPO.c,31 :: 		PortD.Rd0=~PortD.Rd0;
	MOVLW      1
	XORWF      PORTD+0, 1
;SIPO.c,32 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_Pulso5:
	DECFSZ     R13+0, 1
	GOTO       L_Pulso5
	DECFSZ     R12+0, 1
	GOTO       L_Pulso5
	DECFSZ     R11+0, 1
	GOTO       L_Pulso5
	NOP
	NOP
;SIPO.c,33 :: 		clk--;
	DECF       _clk+0, 1
;SIPO.c,34 :: 		}
L_end_Pulso:
	RETURN
; end of _Pulso
