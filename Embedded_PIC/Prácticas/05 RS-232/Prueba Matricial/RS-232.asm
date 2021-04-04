
_main:

;RS-232.c,7 :: 		void main()
;RS-232.c,9 :: 		TRISB=0;
	CLRF       TRISB+0
;RS-232.c,10 :: 		TRISC=0x80;
	MOVLW      128
	MOVWF      TRISC+0
;RS-232.c,12 :: 		PortB=0;
	CLRF       PORTB+0
;RS-232.c,13 :: 		PortC=0;
	CLRF       PORTC+0
;RS-232.c,15 :: 		TRISA.RA4=1;
	BSF        TRISA+0, 4
;RS-232.c,16 :: 		ANSEL=0;
	CLRF       ANSEL+0
;RS-232.c,17 :: 		ANSELH=0;
	CLRF       ANSELH+0
;RS-232.c,19 :: 		while(8)
L_main0:
;RS-232.c,21 :: 		if (PortA.RA0)
	BTFSS      PORTA+0, 0
	GOTO       L_main2
;RS-232.c,23 :: 		veces=100;
	MOVLW      100
	MOVWF      _veces+0
;RS-232.c,24 :: 		Omega();
	CALL       _Omega+0
;RS-232.c,25 :: 		}
L_main2:
;RS-232.c,26 :: 		}
	GOTO       L_main0
;RS-232.c,27 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Omega:

;RS-232.c,29 :: 		void Omega()
;RS-232.c,31 :: 		while (veces)
L_Omega3:
	MOVF       _veces+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Omega4
;RS-232.c,33 :: 		PortC.RC2=1;
	BSF        PORTC+0, 2
;RS-232.c,34 :: 		clk=8;
	MOVLW      8
	MOVWF      _clk+0
;RS-232.c,36 :: 		while (clk)
L_Omega5:
	MOVF       _clk+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Omega6
;RS-232.c,38 :: 		PORTB=TABLAa[pos];
	MOVF       _pos+0, 0
	ADDLW      _TABLAa+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;RS-232.c,39 :: 		Pulso();
	CALL       _Pulso+0
;RS-232.c,41 :: 		pos++;
	INCF       _pos+0, 1
;RS-232.c,42 :: 		if (pos==8)
	MOVF       _pos+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_Omega7
;RS-232.c,44 :: 		pos=0;
	CLRF       _pos+0
;RS-232.c,45 :: 		}
L_Omega7:
;RS-232.c,47 :: 		clk--;
	DECF       _clk+0, 1
;RS-232.c,48 :: 		}
	GOTO       L_Omega5
L_Omega6:
;RS-232.c,50 :: 		PortC.RC2=0;
	BCF        PORTC+0, 2
;RS-232.c,51 :: 		Pulso();
	CALL       _Pulso+0
;RS-232.c,52 :: 		veces--;
	DECF       _veces+0, 1
;RS-232.c,53 :: 		}
	GOTO       L_Omega3
L_Omega4:
;RS-232.c,55 :: 		PORTB=0;
	CLRF       PORTB+0
;RS-232.c,56 :: 		}
L_end_Omega:
	RETURN
; end of _Omega

_Pulso:

;RS-232.c,58 :: 		void Pulso ()
;RS-232.c,60 :: 		PortC.RC3=1;
	BSF        PORTC+0, 3
;RS-232.c,61 :: 		delay_ms(1);
	MOVLW      2
	MOVWF      R12+0
	MOVLW      75
	MOVWF      R13+0
L_Pulso8:
	DECFSZ     R13+0, 1
	GOTO       L_Pulso8
	DECFSZ     R12+0, 1
	GOTO       L_Pulso8
;RS-232.c,62 :: 		PortC.RC3=0;
	BCF        PORTC+0, 3
;RS-232.c,63 :: 		delay_ms(1);
	MOVLW      2
	MOVWF      R12+0
	MOVLW      75
	MOVWF      R13+0
L_Pulso9:
	DECFSZ     R13+0, 1
	GOTO       L_Pulso9
	DECFSZ     R12+0, 1
	GOTO       L_Pulso9
;RS-232.c,64 :: 		}
L_end_Pulso:
	RETURN
; end of _Pulso
