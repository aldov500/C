
_main:

;Estacionometro.c,18 :: 		void main()
;Estacionometro.c,20 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;Estacionometro.c,21 :: 		Lcd_Cmd(_LCD_CLEAR);          // Limpia el display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,22 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);     // Apaga el cursos
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,24 :: 		TRISB=0x10;                   //Usaremos RB4 como entrada
	MOVLW      16
	MOVWF      TRISB+0
;Estacionometro.c,25 :: 		ANSELH=0;
	CLRF       ANSELH+0
;Estacionometro.c,26 :: 		TRISD=0;
	CLRF       TRISD+0
;Estacionometro.c,27 :: 		PORTD.RD0=0;                      //Salida para LEDs
	BCF        PORTD+0, 0
;Estacionometro.c,28 :: 		PORTD.RD1=0;
	BCF        PORTD+0, 1
;Estacionometro.c,30 :: 		Lcd_Out(1,1," Proyecto Final");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,31 :: 		Lcd_Out(2,1,"Progr. Embebidos");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,33 :: 		Delay_ms(2500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	DECFSZ     R11+0, 1
	GOTO       L_main0
	NOP
;Estacionometro.c,35 :: 		T1CON = 0x10;
	MOVLW      16
	MOVWF      T1CON+0
;Estacionometro.c,37 :: 		for (i=0; i!=2; i++)
	CLRF       _i+0
	CLRF       _i+1
L_main1:
	MOVLW      0
	XORWF      _i+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main37
	MOVLW      2
	XORWF      _i+0, 0
L__main37:
	BTFSC      STATUS+0, 2
	GOTO       L_main2
;Estacionometro.c,39 :: 		PortD.RD0=~PortD.RD0;
	MOVLW      1
	XORWF      PORTD+0, 1
;Estacionometro.c,40 :: 		PortD.RD1=~PortD.RD1;
	MOVLW      2
	XORWF      PORTD+0, 1
;Estacionometro.c,41 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;Estacionometro.c,37 :: 		for (i=0; i!=2; i++)
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;Estacionometro.c,42 :: 		}
	GOTO       L_main1
L_main2:
;Estacionometro.c,44 :: 		while(1)
L_main5:
;Estacionometro.c,46 :: 		LCD_cmd(_LCD_RETURN_HOME);
	MOVLW      2
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,47 :: 		TMR1H = 0;                  //Limpia el
	CLRF       TMR1H+0
;Estacionometro.c,48 :: 		TMR1L = 0;                  //       TIMER
	CLRF       TMR1L+0
;Estacionometro.c,50 :: 		PORTB.B0 = 1;               //Activa el TRIGGEr
	BSF        PORTB+0, 0
;Estacionometro.c,51 :: 		Delay_us(10);               //delay forzoso de 10 microsegundos
	MOVLW      3
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
;Estacionometro.c,52 :: 		PORTB.B0 = 0;               //Desactiva el TRIGGER
	BCF        PORTB+0, 0
;Estacionometro.c,54 :: 		while(!PORTB.B4);           //Mientras ECHO no esté activo
L_main8:
	BTFSC      PORTB+0, 4
	GOTO       L_main9
	GOTO       L_main8
L_main9:
;Estacionometro.c,55 :: 		T1CON.F0 = 1;               //Empieza el timer
	BSF        T1CON+0, 0
;Estacionometro.c,56 :: 		while(PORTB.B4);            //Espera a que el ECHO baje
L_main10:
	BTFSS      PORTB+0, 4
	GOTO       L_main11
	GOTO       L_main10
L_main11:
;Estacionometro.c,57 :: 		T1CON.F0 = 0;               //Detiene el timer
	BCF        T1CON+0, 0
;Estacionometro.c,59 :: 		dis=(TMR1L|(TMR1H<<8));     //Lee el timer
	MOVF       TMR1H+0, 0
	MOVWF      R0+1
	CLRF       R0+0
	MOVF       TMR1L+0, 0
	IORWF      R0+0, 1
	MOVLW      0
	IORWF      R0+1, 1
	MOVF       R0+0, 0
	MOVWF      _dis+0
	MOVF       R0+1, 0
	MOVWF      _dis+1
;Estacionometro.c,60 :: 		dis/=29.41*.5;              //Formula para convertir el tiempo en distancia
	CALL       _Int2Double+0
	MOVLW      174
	MOVWF      R4+0
	MOVLW      71
	MOVWF      R4+1
	MOVLW      107
	MOVWF      R4+2
	MOVLW      130
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _Double2Int+0
	MOVF       R0+0, 0
	MOVWF      _dis+0
	MOVF       R0+1, 0
	MOVWF      _dis+1
;Estacionometro.c,62 :: 		IntToStr(dis,txt);
	MOVF       R0+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       R0+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _txt+0
	MOVWF      FARG_IntToStr_output+0
	CALL       _IntToStr+0
;Estacionometro.c,63 :: 		Ltrim(txt);
	MOVLW      _txt+0
	MOVWF      FARG_Ltrim_string+0
	CALL       _Ltrim+0
;Estacionometro.c,65 :: 		if (dis<9)
	MOVLW      128
	XORWF      _dis+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main38
	MOVLW      9
	SUBWF      _dis+0, 0
L__main38:
	BTFSC      STATUS+0, 0
	GOTO       L_main12
;Estacionometro.c,67 :: 		x=1;
	MOVLW      1
	MOVWF      _x+0
	MOVLW      0
	MOVWF      _x+1
;Estacionometro.c,68 :: 		if (x!=pasx)
	MOVLW      0
	XORWF      _pasx+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main39
	MOVF       _pasx+0, 0
	XORLW      1
L__main39:
	BTFSC      STATUS+0, 2
	GOTO       L_main13
;Estacionometro.c,70 :: 		LCD_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,71 :: 		}
L_main13:
;Estacionometro.c,73 :: 		Lcd_Out(1, 1, "  DETENGASE");           //Aviso de que la proximidad es muy cercana
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,75 :: 		PortD.RD0=1;
	BSF        PORTD+0, 0
;Estacionometro.c,76 :: 		PortD.RD1=1;
	BSF        PORTD+0, 1
;Estacionometro.c,77 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main14:
	DECFSZ     R13+0, 1
	GOTO       L_main14
	DECFSZ     R12+0, 1
	GOTO       L_main14
	DECFSZ     R11+0, 1
	GOTO       L_main14
	NOP
	NOP
;Estacionometro.c,78 :: 		PortD.RD0=0;
	BCF        PORTD+0, 0
;Estacionometro.c,79 :: 		PortD.RD1=0;
	BCF        PORTD+0, 1
;Estacionometro.c,81 :: 		pasx=x;
	MOVF       _x+0, 0
	MOVWF      _pasx+0
	MOVF       _x+1, 0
	MOVWF      _pasx+1
;Estacionometro.c,82 :: 		}
	GOTO       L_main15
L_main12:
;Estacionometro.c,84 :: 		else if (dis>=10&&dis<=19)
	MOVLW      128
	XORWF      _dis+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main40
	MOVLW      10
	SUBWF      _dis+0, 0
L__main40:
	BTFSS      STATUS+0, 0
	GOTO       L_main18
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _dis+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main41
	MOVF       _dis+0, 0
	SUBLW      19
L__main41:
	BTFSS      STATUS+0, 0
	GOTO       L_main18
L__main35:
;Estacionometro.c,86 :: 		x=2;
	MOVLW      2
	MOVWF      _x+0
	MOVLW      0
	MOVWF      _x+1
;Estacionometro.c,87 :: 		LCD_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,89 :: 		Lcd_Out(1,1,"Distancia= ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr4_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,90 :: 		Lcd_Out(1,12, txt);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      12
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,91 :: 		Lcd_Out(1,15,"cm");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr5_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,92 :: 		delay_ms(400);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	DECFSZ     R11+0, 1
	GOTO       L_main19
;Estacionometro.c,94 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,96 :: 		Lcd_Out(1,1, " Objeto Cercano");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr6_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,97 :: 		Lcd_Out(2,1, "   Detectado");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr7_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,99 :: 		PortD.RD0=1;
	BSF        PORTD+0, 0
;Estacionometro.c,100 :: 		PortD.RD1=1;
	BSF        PORTD+0, 1
;Estacionometro.c,101 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main20:
	DECFSZ     R13+0, 1
	GOTO       L_main20
	DECFSZ     R12+0, 1
	GOTO       L_main20
	DECFSZ     R11+0, 1
	GOTO       L_main20
	NOP
	NOP
;Estacionometro.c,102 :: 		PortD.RD0=0;
	BCF        PORTD+0, 0
;Estacionometro.c,103 :: 		PortD.RD1=0;
	BCF        PORTD+0, 1
;Estacionometro.c,104 :: 		pasx=x;
	MOVF       _x+0, 0
	MOVWF      _pasx+0
	MOVF       _x+1, 0
	MOVWF      _pasx+1
;Estacionometro.c,105 :: 		}
	GOTO       L_main21
L_main18:
;Estacionometro.c,107 :: 		else if (dis>=20&&dis<=149)
	MOVLW      128
	XORWF      _dis+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main42
	MOVLW      20
	SUBWF      _dis+0, 0
L__main42:
	BTFSS      STATUS+0, 0
	GOTO       L_main24
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _dis+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main43
	MOVF       _dis+0, 0
	SUBLW      149
L__main43:
	BTFSS      STATUS+0, 0
	GOTO       L_main24
L__main34:
;Estacionometro.c,109 :: 		x=3;                                //Las variables "x" y "pasx" evitan que la pantalla parpadee
	MOVLW      3
	MOVWF      _x+0
	MOVLW      0
	MOVWF      _x+1
;Estacionometro.c,110 :: 		if (x!=pasx)                        //Si no ha habido un cambio en el rango del sensor
	MOVLW      0
	XORWF      _pasx+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main44
	MOVF       _pasx+0, 0
	XORLW      3
L__main44:
	BTFSC      STATUS+0, 2
	GOTO       L_main25
;Estacionometro.c,112 :: 		LCD_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,113 :: 		}
L_main25:
;Estacionometro.c,114 :: 		Lcd_Out(1,1,"Distancia= ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr8_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,115 :: 		Lcd_Out(1,12, txt);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      12
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,116 :: 		Lcd_Out(1,15,"cm");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr9_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,117 :: 		pasx=x;
	MOVF       _x+0, 0
	MOVWF      _pasx+0
	MOVF       _x+1, 0
	MOVWF      _pasx+1
;Estacionometro.c,118 :: 		}
	GOTO       L_main26
L_main24:
;Estacionometro.c,120 :: 		else if (dis>=150)
	MOVLW      128
	XORWF      _dis+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main45
	MOVLW      150
	SUBWF      _dis+0, 0
L__main45:
	BTFSS      STATUS+0, 0
	GOTO       L_main27
;Estacionometro.c,122 :: 		x=4;                                //Las variables "x" y "pasx" evitan que la pantalla parpadee
	MOVLW      4
	MOVWF      _x+0
	MOVLW      0
	MOVWF      _x+1
;Estacionometro.c,123 :: 		if (x!=pasx)                        //Si no ha habido un cambio en el rango del sensor
	MOVLW      0
	XORWF      _pasx+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main46
	MOVF       _pasx+0, 0
	XORLW      4
L__main46:
	BTFSC      STATUS+0, 2
	GOTO       L_main28
;Estacionometro.c,125 :: 		LCD_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,126 :: 		}
L_main28:
;Estacionometro.c,127 :: 		Lcd_Out(1,1," No se detecta algun objeto cercano");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr10_Estacionometro+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Estacionometro.c,128 :: 		for (i=0; i!=18; i++)
	CLRF       _i+0
	CLRF       _i+1
L_main29:
	MOVLW      0
	XORWF      _i+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main47
	MOVLW      18
	XORWF      _i+0, 0
L__main47:
	BTFSC      STATUS+0, 2
	GOTO       L_main30
;Estacionometro.c,130 :: 		delay_ms(180);
	MOVLW      234
	MOVWF      R12+0
	MOVLW      195
	MOVWF      R13+0
L_main32:
	DECFSZ     R13+0, 1
	GOTO       L_main32
	DECFSZ     R12+0, 1
	GOTO       L_main32
;Estacionometro.c,131 :: 		Lcd_cmd(_LCD_SHIFT_LEFT);
	MOVLW      24
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Estacionometro.c,128 :: 		for (i=0; i!=18; i++)
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;Estacionometro.c,132 :: 		}
	GOTO       L_main29
L_main30:
;Estacionometro.c,133 :: 		pasx=x;
	MOVF       _x+0, 0
	MOVWF      _pasx+0
	MOVF       _x+1, 0
	MOVWF      _pasx+1
;Estacionometro.c,134 :: 		}
L_main27:
L_main26:
L_main21:
L_main15:
;Estacionometro.c,136 :: 		Delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main33:
	DECFSZ     R13+0, 1
	GOTO       L_main33
	DECFSZ     R12+0, 1
	GOTO       L_main33
	DECFSZ     R11+0, 1
	GOTO       L_main33
	NOP
;Estacionometro.c,137 :: 		}
	GOTO       L_main5
;Estacionometro.c,138 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
