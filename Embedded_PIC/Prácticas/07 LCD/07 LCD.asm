
_main:

;07 LCD.c,30 :: 		void main()
;07 LCD.c,32 :: 		TRISA=0x03;
	MOVLW      3
	MOVWF      TRISA+0
;07 LCD.c,33 :: 		TRISD=0x00;
	CLRF       TRISD+0
;07 LCD.c,34 :: 		TRISC=0x00;
	CLRF       TRISC+0
;07 LCD.c,35 :: 		ANSEL=0x00;
	CLRF       ANSEL+0
;07 LCD.c,37 :: 		PORTC=0;
	CLRF       PORTC+0
;07 LCD.c,38 :: 		PORTD=0;
	CLRF       PORTD+0
;07 LCD.c,39 :: 		PORTA=0 ;
	CLRF       PORTA+0
;07 LCD.c,41 :: 		Lcd_init();
	CALL       _Lcd_Init+0
;07 LCD.c,42 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,44 :: 		while(8)
L_main0:
;07 LCD.c,46 :: 		Lcd_Out(1, 1, "  Practica 07");      //Mensaje
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_07_32LCD+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;07 LCD.c,47 :: 		Lcd_Out(2, 1, "C para Embebidos");   //        en reposo
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_07_32LCD+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;07 LCD.c,50 :: 		if (PORTA.RA0)                       //Muestra mensaje1
	BTFSS      PORTA+0, 0
	GOTO       L_main2
;07 LCD.c,52 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,53 :: 		delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;07 LCD.c,54 :: 		Lcd_Out(1, 1, TEXTO1);            //Muestra nombre y
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _TEXTO1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;07 LCD.c,55 :: 		Delay_ms(250);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
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
;07 LCD.c,56 :: 		Lcd_Out(2, 1, TEXTO2);            //código en el display
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _TEXTO2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;07 LCD.c,57 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;07 LCD.c,59 :: 		for(i=0; i<17; i++)
	CLRF       _i+0
L_main6:
	MOVLW      17
	SUBWF      _i+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_main7
;07 LCD.c,61 :: 		Lcd_Cmd(_LCD_SHIFT_LEFT); //Mueve el texto a la izquiera
	MOVLW      24
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,62 :: 		delay_ms(150);
	MOVLW      195
	MOVWF      R12+0
	MOVLW      205
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
;07 LCD.c,59 :: 		for(i=0; i<17; i++)
	INCF       _i+0, 1
;07 LCD.c,63 :: 		}
	GOTO       L_main6
L_main7:
;07 LCD.c,64 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	DECFSZ     R11+0, 1
	GOTO       L_main10
	NOP
	NOP
;07 LCD.c,65 :: 		Lcd_cmd(_LCD_CLEAR);       //Limpia la pantalla
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,66 :: 		}
L_main2:
;07 LCD.c,68 :: 		if (PORTA.RA1)                      //Animación
	BTFSS      PORTA+0, 1
	GOTO       L_main11
;07 LCD.c,70 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,71 :: 		Lcd_Out(1, 5, "-PACMAN-");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_07_32LCD+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;07 LCD.c,72 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main12:
	DECFSZ     R13+0, 1
	GOTO       L_main12
	DECFSZ     R12+0, 1
	GOTO       L_main12
	DECFSZ     R11+0, 1
	GOTO       L_main12
	NOP
	NOP
;07 LCD.c,74 :: 		for (i=0; i!=17; i++)          //Ciclo For para el movimiento
	CLRF       _i+0
L_main13:
	MOVF       _i+0, 0
	XORLW      17
	BTFSC      STATUS+0, 2
	GOTO       L_main14
;07 LCD.c,76 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,77 :: 		Phantom(2,i);           //Función de caracter personal "Fantasma"
	MOVLW      2
	MOVWF      FARG_Phantom_pos_row+0
	MOVF       _i+0, 0
	MOVWF      FARG_Phantom_pos_char+0
	CALL       _Phantom+0
;07 LCD.c,78 :: 		Lcd_Cmd(_LCD_SHIFT_RIGHT);
	MOVLW      28
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,79 :: 		delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main16:
	DECFSZ     R13+0, 1
	GOTO       L_main16
	DECFSZ     R12+0, 1
	GOTO       L_main16
	DECFSZ     R11+0, 1
	GOTO       L_main16
	NOP
;07 LCD.c,81 :: 		PacMan1(2,i);           //Pac-Man boca abierta
	MOVLW      2
	MOVWF      FARG_PacMan1_pos_row+0
	MOVF       _i+0, 0
	MOVWF      FARG_PacMan1_pos_char+0
	CALL       _PacMan1+0
;07 LCD.c,82 :: 		delay_ms(200);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main17:
	DECFSZ     R13+0, 1
	GOTO       L_main17
	DECFSZ     R12+0, 1
	GOTO       L_main17
	DECFSZ     R11+0, 1
	GOTO       L_main17
	NOP
;07 LCD.c,83 :: 		PacMan2(2,i);
	MOVLW      2
	MOVWF      FARG_PacMan2_pos_row+0
	MOVF       _i+0, 0
	MOVWF      FARG_PacMan2_pos_char+0
	CALL       _PacMan2+0
;07 LCD.c,84 :: 		delay_ms(100);           //Pac-Man boca cerrada
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	NOP
	NOP
;07 LCD.c,85 :: 		Lcd_Cmd(_LCD_SHIFT_RIGHT);
	MOVLW      28
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,87 :: 		delay_ms(50);
	MOVLW      65
	MOVWF      R12+0
	MOVLW      238
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	NOP
;07 LCD.c,74 :: 		for (i=0; i!=17; i++)          //Ciclo For para el movimiento
	INCF       _i+0, 1
;07 LCD.c,88 :: 		}
	GOTO       L_main13
L_main14:
;07 LCD.c,90 :: 		Lcd_Cmd(_LCD_SHIFT_LEFT);
	MOVLW      24
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,91 :: 		}
L_main11:
;07 LCD.c,92 :: 		}
	GOTO       L_main0
;07 LCD.c,93 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_PacMan1:

;07 LCD.c,95 :: 		void PacMan1(char pos_row, char pos_char)
;07 LCD.c,98 :: 		Lcd_Cmd(64);
	MOVLW      64
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,99 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character1[i]);
	CLRF       PacMan1_i_L0+0
L_PacMan120:
	MOVF       PacMan1_i_L0+0, 0
	SUBLW      7
	BTFSS      STATUS+0, 0
	GOTO       L_PacMan121
	MOVF       PacMan1_i_L0+0, 0
	ADDLW      _character1+0
	MOVWF      R0+0
	MOVLW      hi_addr(_character1+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
	INCF       PacMan1_i_L0+0, 1
	GOTO       L_PacMan120
L_PacMan121:
;07 LCD.c,100 :: 		Lcd_Cmd(_LCD_RETURN_HOME);
	MOVLW      2
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,101 :: 		Lcd_Chr(pos_row, pos_char, 0);
	MOVF       FARG_PacMan1_pos_row+0, 0
	MOVWF      FARG_Lcd_Chr_row+0
	MOVF       FARG_PacMan1_pos_char+0, 0
	MOVWF      FARG_Lcd_Chr_column+0
	CLRF       FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;07 LCD.c,102 :: 		}
L_end_PacMan1:
	RETURN
; end of _PacMan1

_PacMan2:

;07 LCD.c,104 :: 		void PacMan2(char pos_row, char pos_char)
;07 LCD.c,107 :: 		Lcd_Cmd(64);
	MOVLW      64
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,108 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character2[i]);
	CLRF       PacMan2_i_L0+0
L_PacMan223:
	MOVF       PacMan2_i_L0+0, 0
	SUBLW      7
	BTFSS      STATUS+0, 0
	GOTO       L_PacMan224
	MOVF       PacMan2_i_L0+0, 0
	ADDLW      _character2+0
	MOVWF      R0+0
	MOVLW      hi_addr(_character2+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
	INCF       PacMan2_i_L0+0, 1
	GOTO       L_PacMan223
L_PacMan224:
;07 LCD.c,109 :: 		Lcd_Cmd(_LCD_RETURN_HOME);
	MOVLW      2
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,110 :: 		Lcd_Chr(pos_row, pos_char, 0);
	MOVF       FARG_PacMan2_pos_row+0, 0
	MOVWF      FARG_Lcd_Chr_row+0
	MOVF       FARG_PacMan2_pos_char+0, 0
	MOVWF      FARG_Lcd_Chr_column+0
	CLRF       FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;07 LCD.c,111 :: 		}
L_end_PacMan2:
	RETURN
; end of _PacMan2

_Phantom:

;07 LCD.c,113 :: 		void Phantom(char pos_row, char pos_char)
;07 LCD.c,116 :: 		Lcd_Cmd(64);
	MOVLW      64
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,117 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character3[i]);
	CLRF       Phantom_i_L0+0
L_Phantom26:
	MOVF       Phantom_i_L0+0, 0
	SUBLW      7
	BTFSS      STATUS+0, 0
	GOTO       L_Phantom27
	MOVF       Phantom_i_L0+0, 0
	ADDLW      _character3+0
	MOVWF      R0+0
	MOVLW      hi_addr(_character3+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
	INCF       Phantom_i_L0+0, 1
	GOTO       L_Phantom26
L_Phantom27:
;07 LCD.c,118 :: 		Lcd_Cmd(_LCD_RETURN_HOME);
	MOVLW      2
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;07 LCD.c,119 :: 		Lcd_Chr(pos_row, pos_char, 0);
	MOVF       FARG_Phantom_pos_row+0, 0
	MOVWF      FARG_Lcd_Chr_row+0
	MOVF       FARG_Phantom_pos_char+0, 0
	MOVWF      FARG_Lcd_Chr_column+0
	CLRF       FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;07 LCD.c,120 :: 		}
L_end_Phantom:
	RETURN
; end of _Phantom
