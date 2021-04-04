
_main:

;PWM.c,6 :: 		void main()
;PWM.c,8 :: 		CCP1CON=0x0C; //0000 1100 PWM Single Outpu, P1A, Modo PWM.
	MOVLW      12
	MOVWF      CCP1CON+0
;PWM.c,9 :: 		PIR1=0x02;
	MOVLW      2
	MOVWF      PIR1+0
;PWM.c,10 :: 		T2CON=0x04; //Preescala, Activar Timer2
	MOVLW      4
	MOVWF      T2CON+0
;PWM.c,11 :: 		TRISC=0x00;
	CLRF       TRISC+0
;PWM.c,13 :: 		Periodo (256);
	MOVLW      0
	MOVWF      FARG_Periodo_t+0
	MOVLW      1
	MOVWF      FARG_Periodo_t+1
	CALL       _Periodo+0
;PWM.c,15 :: 		while (8)
L_main0:
;PWM.c,17 :: 		for(i=0;i<=1000;i+=100)
	CLRF       _i+0
	CLRF       _i+1
L_main2:
	MOVLW      128
	XORLW      3
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main11
	MOVF       _i+0, 0
	SUBLW      232
L__main11:
	BTFSS      STATUS+0, 0
	GOTO       L_main3
;PWM.c,19 :: 		PW(i);
	MOVF       _i+0, 0
	MOVWF      FARG_PW_ancho+0
	MOVF       _i+1, 0
	MOVWF      FARG_PW_ancho+1
	CALL       _PW+0
;PWM.c,20 :: 		delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
;PWM.c,17 :: 		for(i=0;i<=1000;i+=100)
	MOVLW      100
	ADDWF      _i+0, 1
	BTFSC      STATUS+0, 0
	INCF       _i+1, 1
;PWM.c,21 :: 		}
	GOTO       L_main2
L_main3:
;PWM.c,23 :: 		for (i=1000;i>=0;i-=100)
	MOVLW      232
	MOVWF      _i+0
	MOVLW      3
	MOVWF      _i+1
L_main6:
	MOVLW      128
	XORWF      _i+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main12
	MOVLW      0
	SUBWF      _i+0, 0
L__main12:
	BTFSS      STATUS+0, 0
	GOTO       L_main7
;PWM.c,25 :: 		PW(i);
	MOVF       _i+0, 0
	MOVWF      FARG_PW_ancho+0
	MOVF       _i+1, 0
	MOVWF      FARG_PW_ancho+1
	CALL       _PW+0
;PWM.c,26 :: 		delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
	DECFSZ     R11+0, 1
	GOTO       L_main9
	NOP
;PWM.c,23 :: 		for (i=1000;i>=0;i-=100)
	MOVLW      100
	SUBWF      _i+0, 1
	BTFSS      STATUS+0, 0
	DECF       _i+1, 1
;PWM.c,27 :: 		}
	GOTO       L_main6
L_main7:
;PWM.c,28 :: 		}
	GOTO       L_main0
;PWM.c,29 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_PW:

;PWM.c,31 :: 		void PW (int ancho)
;PWM.c,33 :: 		CCP1CON|=((ancho&0x0003)<<4);
	MOVLW      3
	ANDWF      FARG_PW_ancho+0, 0
	MOVWF      R2+0
	MOVF       R2+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	IORWF      CCP1CON+0, 1
;PWM.c,34 :: 		CCPR1L=ancho>>2;
	MOVF       FARG_PW_ancho+0, 0
	MOVWF      R0+0
	MOVF       FARG_PW_ancho+1, 0
	MOVWF      R0+1
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+1, 7
	BTFSC      R0+1, 6
	BSF        R0+1, 7
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+1, 7
	BTFSC      R0+1, 6
	BSF        R0+1, 7
	MOVF       R0+0, 0
	MOVWF      CCPR1L+0
;PWM.c,35 :: 		}
L_end_PW:
	RETURN
; end of _PW

_Periodo:

;PWM.c,37 :: 		void Periodo (int t)
;PWM.c,39 :: 		PR2=(t-1);
	DECF       FARG_Periodo_t+0, 0
	MOVWF      PR2+0
;PWM.c,40 :: 		}
L_end_Periodo:
	RETURN
; end of _Periodo
