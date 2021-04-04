
_main:

;Modulación PW.c,4 :: 		void main()
;Modulación PW.c,6 :: 		TRISA=0x03;
	MOVLW      3
	MOVWF      TRISA+0
;Modulación PW.c,7 :: 		ANSEL=0;
	CLRF       ANSEL+0
;Modulación PW.c,9 :: 		PORTA=0x03;
	MOVLW      3
	MOVWF      PORTA+0
;Modulación PW.c,11 :: 		PWM1_Init(2000);
	BSF        T2CON+0, 0
	BCF        T2CON+0, 1
	MOVLW      124
	MOVWF      PR2+0
	CALL       _PWM1_Init+0
;Modulación PW.c,12 :: 		PWM1_Start();
	CALL       _PWM1_Start+0
;Modulación PW.c,14 :: 		while (8)
L_main0:
;Modulación PW.c,16 :: 		if (!PORTA.RA0)
	BTFSC      PORTA+0, 0
	GOTO       L_main2
;Modulación PW.c,18 :: 		if (x!=6)
	MOVF       _x+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_main3
;Modulación PW.c,20 :: 		x++;
	INCF       _x+0, 1
;Modulación PW.c,21 :: 		}
L_main3:
;Modulación PW.c,22 :: 		while (!PORTA.RA0);
L_main4:
	BTFSC      PORTA+0, 0
	GOTO       L_main5
	GOTO       L_main4
L_main5:
;Modulación PW.c,23 :: 		}
L_main2:
;Modulación PW.c,25 :: 		if (!PORTA.RA1)
	BTFSC      PORTA+0, 1
	GOTO       L_main6
;Modulación PW.c,27 :: 		if (x!=1)
	MOVF       _x+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_main7
;Modulación PW.c,29 :: 		x--;
	DECF       _x+0, 1
;Modulación PW.c,30 :: 		}
L_main7:
;Modulación PW.c,31 :: 		while (!PORTA.RA1);
L_main8:
	BTFSC      PORTA+0, 1
	GOTO       L_main9
	GOTO       L_main8
L_main9:
;Modulación PW.c,32 :: 		}
L_main6:
;Modulación PW.c,34 :: 		switch (x)
	GOTO       L_main10
;Modulación PW.c,36 :: 		case 1:
L_main12:
;Modulación PW.c,38 :: 		PWM1_Set_Duty(0);
	CLRF       FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,39 :: 		break;
	GOTO       L_main11
;Modulación PW.c,42 :: 		case 2:
L_main13:
;Modulación PW.c,44 :: 		DutyActual=25;
	MOVLW      25
	MOVWF      _DutyActual+0
;Modulación PW.c,45 :: 		PWM1_Set_Duty(DutyActual);
	MOVLW      25
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,46 :: 		break;
	GOTO       L_main11
;Modulación PW.c,49 :: 		case 3:
L_main14:
;Modulación PW.c,51 :: 		DutyActual=50;
	MOVLW      50
	MOVWF      _DutyActual+0
;Modulación PW.c,52 :: 		PWM1_Set_Duty(DutyActual);
	MOVLW      50
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,53 :: 		break;
	GOTO       L_main11
;Modulación PW.c,56 :: 		case 4:
L_main15:
;Modulación PW.c,58 :: 		DutyActual=75;
	MOVLW      75
	MOVWF      _DutyActual+0
;Modulación PW.c,59 :: 		PWM1_Set_Duty(DutyActual);
	MOVLW      75
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,60 :: 		break;
	GOTO       L_main11
;Modulación PW.c,63 :: 		case 5:
L_main16:
;Modulación PW.c,65 :: 		DutyActual=100;
	MOVLW      100
	MOVWF      _DutyActual+0
;Modulación PW.c,66 :: 		PWM1_Set_Duty(DutyActual);
	MOVLW      100
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,67 :: 		break;
	GOTO       L_main11
;Modulación PW.c,70 :: 		case 6:
L_main17:
;Modulación PW.c,72 :: 		DutyActual=150;
	MOVLW      150
	MOVWF      _DutyActual+0
;Modulación PW.c,73 :: 		PWM1_Set_Duty(DutyActual);
	MOVLW      150
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;Modulación PW.c,74 :: 		break;
	GOTO       L_main11
;Modulación PW.c,76 :: 		delay_ms(3);
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	NOP
;Modulación PW.c,77 :: 		}
	GOTO       L_main11
L_main10:
	MOVF       _x+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_main12
	MOVF       _x+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_main13
	MOVF       _x+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_main14
	MOVF       _x+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_main15
	MOVF       _x+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_main16
	MOVF       _x+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_main17
L_main11:
;Modulación PW.c,78 :: 		}
	GOTO       L_main0
;Modulación PW.c,79 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
