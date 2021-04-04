
_main:

;RS-232.c,7 :: 		void main()
;RS-232.c,9 :: 		TXSTA.SYNC=0;
	BCF        TXSTA+0, 4
;RS-232.c,10 :: 		TXSTA.BRGH=0;
	BCF        TXSTA+0, 2
;RS-232.c,11 :: 		BAUDCTL.BRG16=0;
	BCF        BAUDCTL+0, 3
;RS-232.c,13 :: 		SPBRG=25;
	MOVLW      25
	MOVWF      SPBRG+0
;RS-232.c,15 :: 		RCSTA.SPEN=1;
	BSF        RCSTA+0, 7
;RS-232.c,16 :: 		RCSTA.CREN=1;
	BSF        RCSTA+0, 4
;RS-232.c,17 :: 		TXSTA.TXEN=1;
	BSF        TXSTA+0, 5
;RS-232.c,19 :: 		PIE1.RCIE=1;
	BSF        PIE1+0, 5
;RS-232.c,20 :: 		INTCON.PEIE=1;
	BSF        INTCON+0, 6
;RS-232.c,21 :: 		INTCON.GIE=1;
	BSF        INTCON+0, 7
;RS-232.c,23 :: 		TRISB=0;         //Se usará el PuertoB para mandar los valores a las filas
	CLRF       TRISB+0
;RS-232.c,24 :: 		TRISC=0x80;      //Y dos bits del puerto C para el multiplexado
	MOVLW      128
	MOVWF      TRISC+0
;RS-232.c,26 :: 		PortB=0;         //Se limpian los puertos
	CLRF       PORTB+0
;RS-232.c,27 :: 		PortC=0;
	CLRF       PORTC+0
;RS-232.c,29 :: 		TRISA.RA4=1;
	BSF        TRISA+0, 4
;RS-232.c,30 :: 		ANSEL=0;
	CLRF       ANSEL+0
;RS-232.c,31 :: 		ANSELH=0;
	CLRF       ANSELH+0
;RS-232.c,33 :: 		while(8)
L_main0:
;RS-232.c,35 :: 		if (!PortA.RA0)
	BTFSC      PORTA+0, 0
	GOTO       L_main2
;RS-232.c,37 :: 		TXREG='M';
	MOVLW      77
	MOVWF      TXREG+0
;RS-232.c,38 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
;RS-232.c,39 :: 		TXREG='A';
	MOVLW      65
	MOVWF      TXREG+0
;RS-232.c,40 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
;RS-232.c,41 :: 		TXREG='N';
	MOVLW      78
	MOVWF      TXREG+0
;RS-232.c,42 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
;RS-232.c,43 :: 		TXREG='U';
	MOVLW      85
	MOVWF      TXREG+0
;RS-232.c,44 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
;RS-232.c,45 :: 		TXREG='E';
	MOVLW      69
	MOVWF      TXREG+0
;RS-232.c,46 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
;RS-232.c,47 :: 		TXREG='L';
	MOVLW      76
	MOVWF      TXREG+0
;RS-232.c,48 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
;RS-232.c,49 :: 		TXREG=' ';
	MOVLW      32
	MOVWF      TXREG+0
;RS-232.c,50 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
;RS-232.c,51 :: 		TXREG='L';
	MOVLW      76
	MOVWF      TXREG+0
;RS-232.c,52 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
;RS-232.c,53 :: 		TXREG='A';
	MOVLW      65
	MOVWF      TXREG+0
;RS-232.c,54 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
;RS-232.c,55 :: 		TXREG='R';
	MOVLW      82
	MOVWF      TXREG+0
;RS-232.c,56 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main12:
	DECFSZ     R13+0, 1
	GOTO       L_main12
	DECFSZ     R12+0, 1
	GOTO       L_main12
;RS-232.c,57 :: 		TXREG='A';
	MOVLW      65
	MOVWF      TXREG+0
;RS-232.c,58 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main13:
	DECFSZ     R13+0, 1
	GOTO       L_main13
	DECFSZ     R12+0, 1
	GOTO       L_main13
;RS-232.c,59 :: 		TXREG=' ';
	MOVLW      32
	MOVWF      TXREG+0
;RS-232.c,60 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main14:
	DECFSZ     R13+0, 1
	GOTO       L_main14
	DECFSZ     R12+0, 1
	GOTO       L_main14
;RS-232.c,61 :: 		TXREG='2';
	MOVLW      50
	MOVWF      TXREG+0
;RS-232.c,62 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main15:
	DECFSZ     R13+0, 1
	GOTO       L_main15
	DECFSZ     R12+0, 1
	GOTO       L_main15
;RS-232.c,63 :: 		TXREG='1';
	MOVLW      49
	MOVWF      TXREG+0
;RS-232.c,64 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main16:
	DECFSZ     R13+0, 1
	GOTO       L_main16
	DECFSZ     R12+0, 1
	GOTO       L_main16
;RS-232.c,65 :: 		TXREG='0';
	MOVLW      48
	MOVWF      TXREG+0
;RS-232.c,66 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main17:
	DECFSZ     R13+0, 1
	GOTO       L_main17
	DECFSZ     R12+0, 1
	GOTO       L_main17
;RS-232.c,67 :: 		TXREG='4';
	MOVLW      52
	MOVWF      TXREG+0
;RS-232.c,68 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
;RS-232.c,69 :: 		TXREG='5';
	MOVLW      53
	MOVWF      TXREG+0
;RS-232.c,70 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
;RS-232.c,71 :: 		TXREG='9';
	MOVLW      57
	MOVWF      TXREG+0
;RS-232.c,72 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main20:
	DECFSZ     R13+0, 1
	GOTO       L_main20
	DECFSZ     R12+0, 1
	GOTO       L_main20
;RS-232.c,73 :: 		TXREG='9';
	MOVLW      57
	MOVWF      TXREG+0
;RS-232.c,74 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main21:
	DECFSZ     R13+0, 1
	GOTO       L_main21
	DECFSZ     R12+0, 1
	GOTO       L_main21
;RS-232.c,75 :: 		TXREG='7';
	MOVLW      55
	MOVWF      TXREG+0
;RS-232.c,76 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main22:
	DECFSZ     R13+0, 1
	GOTO       L_main22
	DECFSZ     R12+0, 1
	GOTO       L_main22
;RS-232.c,77 :: 		TXREG='4';
	MOVLW      52
	MOVWF      TXREG+0
;RS-232.c,78 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main23:
	DECFSZ     R13+0, 1
	GOTO       L_main23
	DECFSZ     R12+0, 1
	GOTO       L_main23
;RS-232.c,79 :: 		TXREG=' ';
	MOVLW      32
	MOVWF      TXREG+0
;RS-232.c,81 :: 		while(!PORTA.RA4);
L_main24:
	BTFSC      PORTA+0, 4
	GOTO       L_main25
	GOTO       L_main24
L_main25:
;RS-232.c,82 :: 		}
L_main2:
;RS-232.c,83 :: 		}
	GOTO       L_main0
;RS-232.c,84 :: 		}
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

;RS-232.c,86 :: 		void interrupt()
;RS-232.c,88 :: 		if (PIR1.RCIF)
	BTFSS      PIR1+0, 5
	GOTO       L_interrupt26
;RS-232.c,90 :: 		Omega();
	CALL       _Omega+0
;RS-232.c,91 :: 		}
L_interrupt26:
;RS-232.c,92 :: 		}
L_end_interrupt:
L__interrupt36:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

_Omega:

;RS-232.c,94 :: 		void Omega()
;RS-232.c,96 :: 		while (8)
L_Omega27:
;RS-232.c,98 :: 		PortC.RC2=1;                     //Se manda un uno al SIPO para deshabilitar todas las columnas en cada barrido
	BSF        PORTC+0, 2
;RS-232.c,100 :: 		clk=8;
	MOVLW      8
	MOVWF      _clk+0
;RS-232.c,102 :: 		while (clk)                     //Se repetirá esta acción ocho veces
L_Omega29:
	MOVF       _clk+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Omega30
;RS-232.c,104 :: 		PORTB=Tabla[pos];       //Se imprime en el PuertoB lo que hay en la Tabla
	MOVF       _pos+0, 0
	ADDLW      _Tabla+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;RS-232.c,105 :: 		Pulso();                //Se da un flanco de subida para recorrer el display
	CALL       _Pulso+0
;RS-232.c,107 :: 		pos++;
	INCF       _pos+0, 1
;RS-232.c,108 :: 		if (pos==8)             //Si el valor de la posición es mayor a 8 se regresa al valor inicial
	MOVF       _pos+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_Omega31
;RS-232.c,110 :: 		pos=0;
	CLRF       _pos+0
;RS-232.c,111 :: 		}
L_Omega31:
;RS-232.c,113 :: 		clk--;
	DECF       _clk+0, 1
;RS-232.c,114 :: 		}
	GOTO       L_Omega29
L_Omega30:
;RS-232.c,116 :: 		PortC.RC2=0;
	BCF        PORTC+0, 2
;RS-232.c,117 :: 		Pulso();
	CALL       _Pulso+0
;RS-232.c,118 :: 		}
	GOTO       L_Omega27
;RS-232.c,119 :: 		}
L_end_Omega:
	RETURN
; end of _Omega

_Pulso:

;RS-232.c,121 :: 		void Pulso ()
;RS-232.c,123 :: 		PortC.RC3=1;
	BSF        PORTC+0, 3
;RS-232.c,124 :: 		delay_ms(1);
	MOVLW      2
	MOVWF      R12+0
	MOVLW      75
	MOVWF      R13+0
L_Pulso32:
	DECFSZ     R13+0, 1
	GOTO       L_Pulso32
	DECFSZ     R12+0, 1
	GOTO       L_Pulso32
;RS-232.c,125 :: 		PortC.RC3=0;
	BCF        PORTC+0, 3
;RS-232.c,126 :: 		delay_ms(1);
	MOVLW      2
	MOVWF      R12+0
	MOVLW      75
	MOVWF      R13+0
L_Pulso33:
	DECFSZ     R13+0, 1
	GOTO       L_Pulso33
	DECFSZ     R12+0, 1
	GOTO       L_Pulso33
;RS-232.c,127 :: 		}
L_end_Pulso:
	RETURN
; end of _Pulso
