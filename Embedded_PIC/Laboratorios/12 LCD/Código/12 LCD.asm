
_main:

;12 LCD.c,32 :: 		void main()
;12 LCD.c,34 :: 		ANSEL=0;
	CLRF       ANSEL+0
;12 LCD.c,35 :: 		PORTE&=(0<<RS|0<<RW|0<<E);
	MOVLW      0
	ANDWF      PORTE+0, 1
;12 LCD.c,36 :: 		PORTD=0x30;
	MOVLW      48
	MOVWF      PORTD+0
;12 LCD.c,37 :: 		TRISE&=(0<<RS|0<<RW|0<<E);
	MOVLW      0
	ANDWF      TRISE+0, 1
;12 LCD.c,38 :: 		TRISD=0;
	CLRF       TRISD+0
;12 LCD.c,40 :: 		delay_ms(50);
	MOVLW      65
	MOVWF      R12+0
	MOVLW      238
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	NOP
;12 LCD.c,42 :: 		DB=0x03C;  //00 0011 1100 Configuración
	MOVLW      60
	MOVWF      _DB+0
;12 LCD.c,43 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,44 :: 		DB=0x00F; //00000001111 Activar Display
	MOVLW      15
	MOVWF      _DB+0
;12 LCD.c,45 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,46 :: 		DB=0x01; //Clear Display
	MOVLW      1
	MOVWF      _DB+0
;12 LCD.c,47 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,48 :: 		DB=0x006; //Mover el cursor
	MOVLW      6
	MOVWF      _DB+0
;12 LCD.c,49 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,50 :: 		Cadena1();
	CALL       _Cadena1+0
;12 LCD.c,51 :: 		DB=0x0C0; //Set DDRAM
	MOVLW      192
	MOVWF      _DB+0
;12 LCD.c,52 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,53 :: 		Cadena2();
	CALL       _Cadena2+0
;12 LCD.c,56 :: 		while (8);
L_main1:
	GOTO       L_main1
;12 LCD.c,57 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Enable:

;12 LCD.c,59 :: 		void Enable()
;12 LCD.c,61 :: 		PORTD=DB;
	MOVF       _DB+0, 0
	MOVWF      PORTD+0
;12 LCD.c,62 :: 		PORTE|=(1<<E);
	BSF        PORTE+0, 2
;12 LCD.c,63 :: 		delay_ms(2);
	MOVLW      3
	MOVWF      R12+0
	MOVLW      151
	MOVWF      R13+0
L_Enable3:
	DECFSZ     R13+0, 1
	GOTO       L_Enable3
	DECFSZ     R12+0, 1
	GOTO       L_Enable3
	NOP
	NOP
;12 LCD.c,64 :: 		PORTE&=~((1<<E));
	BCF        PORTE+0, 2
;12 LCD.c,65 :: 		}
L_end_Enable:
	RETURN
; end of _Enable

_Cadena1:

;12 LCD.c,67 :: 		void Cadena1()
;12 LCD.c,69 :: 		unsigned char i=0;
	CLRF       Cadena1_i_L0+0
;12 LCD.c,71 :: 		PORTE|=(1<<RS);
	BSF        PORTE+0, 0
;12 LCD.c,73 :: 		while ((TEXTO1[i]!='\n'))
L_Cadena14:
	MOVF       Cadena1_i_L0+0, 0
	ADDLW      _TEXTO1+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_Cadena15
;12 LCD.c,75 :: 		DB=TEXTO1[i];
	MOVF       Cadena1_i_L0+0, 0
	ADDLW      _TEXTO1+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DB+0
;12 LCD.c,76 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,77 :: 		i++;
	INCF       Cadena1_i_L0+0, 1
;12 LCD.c,78 :: 		delay_ms(10);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_Cadena16:
	DECFSZ     R13+0, 1
	GOTO       L_Cadena16
	DECFSZ     R12+0, 1
	GOTO       L_Cadena16
	NOP
	NOP
;12 LCD.c,79 :: 		}
	GOTO       L_Cadena14
L_Cadena15:
;12 LCD.c,81 :: 		PORTE&=~((1<<RS));
	BCF        PORTE+0, 0
;12 LCD.c,82 :: 		}
L_end_Cadena1:
	RETURN
; end of _Cadena1

_CADENA2:

;12 LCD.c,84 :: 		void CADENA2(void)
;12 LCD.c,86 :: 		unsigned char i=0;
	CLRF       CADENA2_i_L0+0
;12 LCD.c,88 :: 		PORTE|=(1<<RS);
	BSF        PORTE+0, 0
;12 LCD.c,90 :: 		while ((TEXTO2[i]!='\n'))
L_CADENA27:
	MOVF       CADENA2_i_L0+0, 0
	ADDLW      _TEXTO2+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_CADENA28
;12 LCD.c,92 :: 		DB=TEXTO2[i];
	MOVF       CADENA2_i_L0+0, 0
	ADDLW      _TEXTO2+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DB+0
;12 LCD.c,93 :: 		Enable();
	CALL       _Enable+0
;12 LCD.c,94 :: 		i++;
	INCF       CADENA2_i_L0+0, 1
;12 LCD.c,95 :: 		delay_ms(100);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_CADENA29:
	DECFSZ     R13+0, 1
	GOTO       L_CADENA29
	DECFSZ     R12+0, 1
	GOTO       L_CADENA29
	NOP
	NOP
;12 LCD.c,96 :: 		}
	GOTO       L_CADENA27
L_CADENA28:
;12 LCD.c,98 :: 		PORTE&=((1<<RS));
	MOVLW      1
	ANDWF      PORTE+0, 1
;12 LCD.c,99 :: 		}
L_end_CADENA2:
	RETURN
; end of _CADENA2
