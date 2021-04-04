
_main:

;Matrix.c,24 :: 		void main()
;Matrix.c,26 :: 		TRISC=0;                                        //Puerto C como salida
	CLRF       TRISC+0
;Matrix.c,27 :: 		PORTC=0;                                        //Limpiar Puerto C
	CLRF       PORTC+0
;Matrix.c,29 :: 		TRISA=0x01;                                     //Bit 0 de PORTA como entrada
	MOVLW      1
	MOVWF      TRISA+0
;Matrix.c,30 :: 		PORTA=0;                                        //Limpiar puerto A
	CLRF       PORTA+0
;Matrix.c,32 :: 		ANSEL=0;                                 // Entradas en PORTA y
	CLRF       ANSEL+0
;Matrix.c,33 :: 		ANSELH=0;                                // PORTB como digitales.
	CLRF       ANSELH+0
;Matrix.c,35 :: 		Lcd_init();                              // Inicia la LCD
	CALL       _Lcd_Init+0
;Matrix.c,36 :: 		Keypad_init();                            // Inicia el teclado matricial
	CALL       _Keypad_Init+0
;Matrix.c,37 :: 		Lcd_Cmd(_LCD_CLEAR);                     // Limpia el display.
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,38 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                // Apaga el cursor.
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,40 :: 		led[1]=1;
	MOVLW      1
	MOVWF      _led+1
;Matrix.c,41 :: 		alm[1]=1;
	MOVLW      1
	MOVWF      _alm+1
;Matrix.c,43 :: 		while(8)                                       //Ciclo Infinito
L_main0:
;Matrix.c,45 :: 		while (Ronda)                            //Mientras no se haya  perdido
L_main2:
	MOVF       _Ronda+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main3
;Matrix.c,47 :: 		if (Ronda==1)                          //Mensaje por defecto al iniciar el juego
	MOVF       _Ronda+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main4
;Matrix.c,49 :: 		LCD_Out(1, 1, "TecladoMatricial");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,50 :: 		LCD_Out(2, 1, " Practica 8 y 9");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,51 :: 		}
	GOTO       L_main5
L_main4:
;Matrix.c,53 :: 		else if(Ronda>1)                              //Mensaje en rondas posteriores
	MOVF       _Ronda+0, 0
	SUBLW      1
	BTFSC      STATUS+0, 0
	GOTO       L_main6
;Matrix.c,55 :: 		LCD_Out(1, 1, " Siguiente Ronda");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,56 :: 		}
L_main6:
L_main5:
;Matrix.c,58 :: 		if (PORTA.RA0)                                 //Al presionar RA0 se inicia el programa
	BTFSS      PORTA+0, 0
	GOTO       L_main7
;Matrix.c,60 :: 		x=1;
	MOVLW      1
	MOVWF      _x+0
;Matrix.c,61 :: 		Inicio();
	CALL       _Inicio+0
;Matrix.c,62 :: 		Mostrar();
	CALL       _Mostrar+0
;Matrix.c,63 :: 		Adquirir();
	CALL       _Adquirir+0
;Matrix.c,64 :: 		Comparacion();
	CALL       _Comparacion+0
;Matrix.c,65 :: 		}
L_main7:
;Matrix.c,66 :: 		}
	GOTO       L_main2
L_main3:
;Matrix.c,67 :: 		}
	GOTO       L_main0
;Matrix.c,68 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Inicio:

;Matrix.c,70 :: 		void Inicio()
;Matrix.c,72 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,73 :: 		Lcd_Out(1, 1, "   Atencion... ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr4_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,74 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_Inicio8:
	DECFSZ     R13+0, 1
	GOTO       L_Inicio8
	DECFSZ     R12+0, 1
	GOTO       L_Inicio8
	DECFSZ     R11+0, 1
	GOTO       L_Inicio8
	NOP
	NOP
;Matrix.c,75 :: 		}
L_end_Inicio:
	RETURN
; end of _Inicio

_Mostrar:

;Matrix.c,77 :: 		void Mostrar()                                       //Mostrar en los LED la secuencia
;Matrix.c,79 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,80 :: 		Lcd_Out(1, 1, "     .  .  .");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr5_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,81 :: 		Turno=Ronda;
	MOVF       _Ronda+0, 0
	MOVWF      _Turno+0
;Matrix.c,83 :: 		while (Turno)                                       //Ciclo para crear la secuencia
L_Mostrar9:
	MOVF       _Turno+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar10
;Matrix.c,85 :: 		x+=3;                                        //Función para que sea seudoaleaotorio
	MOVLW      3
	ADDWF      _x+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      _x+0
;Matrix.c,87 :: 		if (x==1)
	MOVF       R1+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar11
;Matrix.c,88 :: 		x=2;
	MOVLW      2
	MOVWF      _x+0
L_Mostrar11:
;Matrix.c,90 :: 		if (x==11)                                    //Funciones
	MOVF       _x+0, 0
	XORLW      11
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar12
;Matrix.c,91 :: 		x=1;                                          //En
	MOVLW      1
	MOVWF      _x+0
L_Mostrar12:
;Matrix.c,92 :: 		if (x==13|x==14)                              //Caso
	MOVF       _x+0, 0
	XORLW      13
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      R1+0
	MOVF       _x+0, 0
	XORLW      14
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar13
;Matrix.c,93 :: 		x=5;                                          //Que
	MOVLW      5
	MOVWF      _x+0
L_Mostrar13:
;Matrix.c,94 :: 		if (x==15)                                    //Se
	MOVF       _x+0, 0
	XORLW      15
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar14
;Matrix.c,95 :: 		x=3;                                          //Rebase
	MOVLW      3
	MOVWF      _x+0
L_Mostrar14:
;Matrix.c,96 :: 		if (x==16)                                    //el
	MOVF       _x+0, 0
	XORLW      16
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar15
;Matrix.c,97 :: 		x=1;                                          //número de
	MOVLW      1
	MOVWF      _x+0
L_Mostrar15:
;Matrix.c,98 :: 		if (x>=17)                                    //LEDs
	MOVLW      17
	SUBWF      _x+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_Mostrar16
;Matrix.c,99 :: 		x=11;
	MOVLW      11
	MOVWF      _x+0
L_Mostrar16:
;Matrix.c,101 :: 		switch (x)
	GOTO       L_Mostrar17
;Matrix.c,103 :: 		case  1: PORTC.RC0 = 1; break;
L_Mostrar19:
	BSF        PORTC+0, 0
	GOTO       L_Mostrar18
;Matrix.c,104 :: 		case  2: PORTC.RC1 = 1; break;
L_Mostrar20:
	BSF        PORTC+0, 1
	GOTO       L_Mostrar18
;Matrix.c,105 :: 		case  3: PORTC.RC2 = 1; break;
L_Mostrar21:
	BSF        PORTC+0, 2
	GOTO       L_Mostrar18
;Matrix.c,106 :: 		case  4: PORTC.RC3 = 1; break;
L_Mostrar22:
	BSF        PORTC+0, 3
	GOTO       L_Mostrar18
;Matrix.c,107 :: 		case  5: PORTC.RC4 = 1; break;
L_Mostrar23:
	BSF        PORTC+0, 4
	GOTO       L_Mostrar18
;Matrix.c,108 :: 		case  6: PORTC.RC5 = 1; break;
L_Mostrar24:
	BSF        PORTC+0, 5
	GOTO       L_Mostrar18
;Matrix.c,109 :: 		case  7: PORTC.RC6 = 1; break;
L_Mostrar25:
	BSF        PORTC+0, 6
	GOTO       L_Mostrar18
;Matrix.c,110 :: 		case  8: PORTC.RC7 = 1; break;
L_Mostrar26:
	BSF        PORTC+0, 7
	GOTO       L_Mostrar18
;Matrix.c,111 :: 		case  9: PORTA.RA4 = 1; break;
L_Mostrar27:
	BSF        PORTA+0, 4
	GOTO       L_Mostrar18
;Matrix.c,112 :: 		case 10: PORTA.RA5 = 1; break;
L_Mostrar28:
	BSF        PORTA+0, 5
	GOTO       L_Mostrar18
;Matrix.c,113 :: 		case 11: PORTA.RA6 = 1; break;
L_Mostrar29:
	BSF        PORTA+0, 6
	GOTO       L_Mostrar18
;Matrix.c,114 :: 		case 12: PORTA.RA7 = 1; break;
L_Mostrar30:
	BSF        PORTA+0, 7
	GOTO       L_Mostrar18
;Matrix.c,115 :: 		}
L_Mostrar17:
	MOVF       _x+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar19
	MOVF       _x+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar20
	MOVF       _x+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar21
	MOVF       _x+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar22
	MOVF       _x+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar23
	MOVF       _x+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar24
	MOVF       _x+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar25
	MOVF       _x+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar26
	MOVF       _x+0, 0
	XORLW      9
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar27
	MOVF       _x+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar28
	MOVF       _x+0, 0
	XORLW      11
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar29
	MOVF       _x+0, 0
	XORLW      12
	BTFSC      STATUS+0, 2
	GOTO       L_Mostrar30
L_Mostrar18:
;Matrix.c,116 :: 		led[Turno]=x;
	MOVF       _Turno+0, 0
	ADDLW      _led+0
	MOVWF      FSR
	MOVF       _x+0, 0
	MOVWF      INDF+0
;Matrix.c,118 :: 		if (Ronda==1)
	MOVF       _Ronda+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar31
;Matrix.c,120 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_Mostrar32:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar32
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar32
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar32
	NOP
	NOP
;Matrix.c,121 :: 		}
	GOTO       L_Mostrar33
L_Mostrar31:
;Matrix.c,123 :: 		else if (Ronda==2)
	MOVF       _Ronda+0, 0
	XORLW      2
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar34
;Matrix.c,125 :: 		delay_ms(850);
	MOVLW      5
	MOVWF      R11+0
	MOVLW      80
	MOVWF      R12+0
	MOVLW      224
	MOVWF      R13+0
L_Mostrar35:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar35
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar35
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar35
	NOP
;Matrix.c,126 :: 		}
	GOTO       L_Mostrar36
L_Mostrar34:
;Matrix.c,128 :: 		else if (Ronda==3)
	MOVF       _Ronda+0, 0
	XORLW      3
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar37
;Matrix.c,130 :: 		delay_ms(700);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      142
	MOVWF      R12+0
	MOVLW      18
	MOVWF      R13+0
L_Mostrar38:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar38
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar38
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar38
	NOP
;Matrix.c,131 :: 		}
	GOTO       L_Mostrar39
L_Mostrar37:
;Matrix.c,133 :: 		else if (Ronda==4)
	MOVF       _Ronda+0, 0
	XORLW      4
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar40
;Matrix.c,135 :: 		delay_ms(550);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      203
	MOVWF      R12+0
	MOVLW      69
	MOVWF      R13+0
L_Mostrar41:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar41
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar41
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar41
;Matrix.c,136 :: 		}
	GOTO       L_Mostrar42
L_Mostrar40:
;Matrix.c,138 :: 		else if (Ronda==5)
	MOVF       _Ronda+0, 0
	XORLW      5
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar43
;Matrix.c,140 :: 		delay_ms(450);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      73
	MOVWF      R12+0
	MOVLW      102
	MOVWF      R13+0
L_Mostrar44:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar44
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar44
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar44
	NOP
;Matrix.c,141 :: 		}
	GOTO       L_Mostrar45
L_Mostrar43:
;Matrix.c,143 :: 		else if (Ronda==6)
	MOVF       _Ronda+0, 0
	XORLW      6
	BTFSS      STATUS+0, 2
	GOTO       L_Mostrar46
;Matrix.c,145 :: 		delay_ms(350);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      199
	MOVWF      R12+0
	MOVLW      136
	MOVWF      R13+0
L_Mostrar47:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar47
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar47
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar47
	NOP
;Matrix.c,146 :: 		}
	GOTO       L_Mostrar48
L_Mostrar46:
;Matrix.c,148 :: 		else delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_Mostrar49:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar49
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar49
	DECFSZ     R11+0, 1
	GOTO       L_Mostrar49
	NOP
L_Mostrar48:
L_Mostrar45:
L_Mostrar42:
L_Mostrar39:
L_Mostrar36:
L_Mostrar33:
;Matrix.c,150 :: 		Turno--;
	DECF       _Turno+0, 1
;Matrix.c,152 :: 		PORTA=1;
	MOVLW      1
	MOVWF      PORTA+0
;Matrix.c,153 :: 		PORTC=0;
	CLRF       PORTC+0
;Matrix.c,154 :: 		delay_ms(50);
	MOVLW      65
	MOVWF      R12+0
	MOVLW      238
	MOVWF      R13+0
L_Mostrar50:
	DECFSZ     R13+0, 1
	GOTO       L_Mostrar50
	DECFSZ     R12+0, 1
	GOTO       L_Mostrar50
	NOP
;Matrix.c,155 :: 		}
	GOTO       L_Mostrar9
L_Mostrar10:
;Matrix.c,156 :: 		}
L_end_Mostrar:
	RETURN
; end of _Mostrar

_Adquirir:

;Matrix.c,158 :: 		void Adquirir()                                           //Adquirir el valor tecleado
;Matrix.c,160 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,161 :: 		Lcd_Out(1, 1, " Introduzca la");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr6_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,162 :: 		Lcd_Out(2, 1, "     secuencia");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr7_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,163 :: 		Turno=Ronda;
	MOVF       _Ronda+0, 0
	MOVWF      _Turno+0
;Matrix.c,165 :: 		while (Turno)
L_Adquirir51:
	MOVF       _Turno+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir52
;Matrix.c,167 :: 		do
L_Adquirir53:
;Matrix.c,169 :: 		kp = Keypad_Key_Click();
	CALL       _Keypad_Key_Click+0
	MOVF       R0+0, 0
	MOVWF      _kp+0
;Matrix.c,170 :: 		delay_ms(100);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_Adquirir56:
	DECFSZ     R13+0, 1
	GOTO       L_Adquirir56
	DECFSZ     R12+0, 1
	GOTO       L_Adquirir56
	NOP
	NOP
;Matrix.c,172 :: 		while (!kp);
	MOVF       _kp+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir53
;Matrix.c,174 :: 		switch (kp)
	GOTO       L_Adquirir57
;Matrix.c,176 :: 		case  1: alm[Turno] = 1; break;
L_Adquirir59:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      1
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,177 :: 		case  2: alm[Turno] = 2; break;
L_Adquirir60:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      2
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,178 :: 		case  3: alm[Turno] = 3; break;
L_Adquirir61:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      3
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,179 :: 		case  4: alm[Turno] = 4; break;
L_Adquirir62:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      4
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,180 :: 		case  5: alm[Turno] = 5; break;
L_Adquirir63:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      5
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,181 :: 		case  6: alm[Turno] = 6; break;
L_Adquirir64:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      6
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,182 :: 		case  7: alm[Turno] = 7; break;
L_Adquirir65:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      7
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,183 :: 		case  8: alm[Turno] = 8; break;
L_Adquirir66:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      8
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,184 :: 		case  9: alm[Turno] = 9; break;
L_Adquirir67:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      9
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,185 :: 		case 10: alm[Turno] = 10; break;
L_Adquirir68:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      10
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,186 :: 		case 11: alm[Turno] = 11; break;
L_Adquirir69:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      11
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,187 :: 		case 12: alm[Turno] = 12; break;
L_Adquirir70:
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVLW      12
	MOVWF      INDF+0
	GOTO       L_Adquirir58
;Matrix.c,188 :: 		}
L_Adquirir57:
	MOVF       _kp+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir59
	MOVF       _kp+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir60
	MOVF       _kp+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir61
	MOVF       _kp+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir62
	MOVF       _kp+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir63
	MOVF       _kp+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir64
	MOVF       _kp+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir65
	MOVF       _kp+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir66
	MOVF       _kp+0, 0
	XORLW      9
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir67
	MOVF       _kp+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir68
	MOVF       _kp+0, 0
	XORLW      11
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir69
	MOVF       _kp+0, 0
	XORLW      12
	BTFSC      STATUS+0, 2
	GOTO       L_Adquirir70
L_Adquirir58:
;Matrix.c,189 :: 		Turno--;
	DECF       _Turno+0, 1
;Matrix.c,190 :: 		}
	GOTO       L_Adquirir51
L_Adquirir52:
;Matrix.c,191 :: 		}
L_end_Adquirir:
	RETURN
; end of _Adquirir

_Comparacion:

;Matrix.c,193 :: 		void Comparacion()                                                //Comparar el valor del LED con el tecleado
;Matrix.c,195 :: 		Turno=Ronda;
	MOVF       _Ronda+0, 0
	MOVWF      _Turno+0
;Matrix.c,196 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,198 :: 		if (alm[Turno]==led[Turno])                                      //Si son iguales
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	MOVF       _Turno+0, 0
	ADDLW      _led+0
	MOVWF      FSR
	MOVF       R1+0, 0
	XORWF      INDF+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L_Comparacion71
;Matrix.c,200 :: 		Ronda++;                                                     //-Se avanza de ronda
	INCF       _Ronda+0, 1
;Matrix.c,201 :: 		Lcd_Out (1, 1, "    CORRECTO!");                             //Y se muestra este mensaje
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr8_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,202 :: 		delay_ms(750);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      207
	MOVWF      R12+0
	MOVLW      1
	MOVWF      R13+0
L_Comparacion72:
	DECFSZ     R13+0, 1
	GOTO       L_Comparacion72
	DECFSZ     R12+0, 1
	GOTO       L_Comparacion72
	DECFSZ     R11+0, 1
	GOTO       L_Comparacion72
	NOP
	NOP
;Matrix.c,203 :: 		}
	GOTO       L_Comparacion73
L_Comparacion71:
;Matrix.c,205 :: 		else if (led[Turno]!=alm[Turno])                              //Si no
	MOVF       _Turno+0, 0
	ADDLW      _led+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	MOVF       _Turno+0, 0
	ADDLW      _alm+0
	MOVWF      FSR
	MOVF       R1+0, 0
	XORWF      INDF+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_Comparacion74
;Matrix.c,207 :: 		Ronda=0;                                             // Ronda es 0 para salir del ciclo principal
	CLRF       _Ronda+0
;Matrix.c,208 :: 		Lcd_Out(1, 1, "   Incorrecto!");                     // Y se despliega
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr9_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,209 :: 		Lcd_Out(2, 1,  "  FIN DEL JUEGO");                   // este mensaje
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr10_Matrix+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Matrix.c,210 :: 		delay_ms(10000);
	MOVLW      51
	MOVWF      R11+0
	MOVLW      187
	MOVWF      R12+0
	MOVLW      223
	MOVWF      R13+0
L_Comparacion75:
	DECFSZ     R13+0, 1
	GOTO       L_Comparacion75
	DECFSZ     R12+0, 1
	GOTO       L_Comparacion75
	DECFSZ     R11+0, 1
	GOTO       L_Comparacion75
	NOP
	NOP
;Matrix.c,211 :: 		}
L_Comparacion74:
L_Comparacion73:
;Matrix.c,213 :: 		LCD_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Matrix.c,214 :: 		}
L_end_Comparacion:
	RETURN
; end of _Comparacion
