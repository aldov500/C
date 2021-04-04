
_main:

;Contador de pasajeros.c,9 :: 		void main()
;Contador de pasajeros.c,11 :: 		TRISA=0x13;   //Configurar RA0, RA1 y RA4 como entradas     0001 0011
	MOVLW      19
	MOVWF      TRISA+0
;Contador de pasajeros.c,12 :: 		ANSEL=0x03;   //"    "     RA0 y RA1 como entradas  análogas
	MOVLW      3
	MOVWF      ANSEL+0
;Contador de pasajeros.c,13 :: 		TRISB=0x00;  //Evitar ruido
	CLRF       TRISB+0
;Contador de pasajeros.c,14 :: 		TRISC&=0x00;  //Configurar el puerto C como salida, Display
	MOVLW      0
	ANDWF      TRISC+0, 1
;Contador de pasajeros.c,15 :: 		TRISD=0x00;   //Configurar RD0, RD1, RD2 y RD3 como salidas, Habilitadores
	CLRF       TRISD+0
;Contador de pasajeros.c,16 :: 		OPTION_REG=0xF8; //Configuración del timer
	MOVLW      248
	MOVWF      OPTION_REG+0
;Contador de pasajeros.c,17 :: 		ADCON0=0xC1; //Configura "Conversion Clock" e inicia el ADC
	MOVLW      193
	MOVWF      ADCON0+0
;Contador de pasajeros.c,18 :: 		ADCON1=0x00; //Justificación a la izquiera
	CLRF       ADCON1+0
;Contador de pasajeros.c,19 :: 		PORTC=0x00; //Limpiar el puerto C
	CLRF       PORTC+0
;Contador de pasajeros.c,20 :: 		TMR0=0x00;  //Limpia el Timer
	CLRF       TMR0+0
;Contador de pasajeros.c,22 :: 		while (8)
L_main0:
;Contador de pasajeros.c,24 :: 		if (x==0)
	MOVF       _x+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main2
;Contador de pasajeros.c,26 :: 		PORTA.RA2=0;
	BCF        PORTA+0, 2
;Contador de pasajeros.c,27 :: 		CompSens();
	CALL       _CompSens+0
;Contador de pasajeros.c,28 :: 		}
L_main2:
;Contador de pasajeros.c,30 :: 		if (TMR0)
	MOVF       TMR0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main3
;Contador de pasajeros.c,32 :: 		conteo();
	CALL       _conteo+0
;Contador de pasajeros.c,33 :: 		}
L_main3:
;Contador de pasajeros.c,34 :: 		multiplexado (10);
	MOVLW      10
	MOVWF      FARG_multiplexado_veces+0
	CALL       _multiplexado+0
;Contador de pasajeros.c,36 :: 		if (x!=0)
	MOVF       _x+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_main4
;Contador de pasajeros.c,38 :: 		x-=1;
	DECF       _x+0, 1
;Contador de pasajeros.c,39 :: 		}
L_main4:
;Contador de pasajeros.c,40 :: 		TMR0=0;
	CLRF       TMR0+0
;Contador de pasajeros.c,41 :: 		}
	GOTO       L_main0
;Contador de pasajeros.c,42 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_conteo:

;Contador de pasajeros.c,44 :: 		void conteo()
;Contador de pasajeros.c,46 :: 		unidades=unidades+TMR0;
	MOVF       TMR0+0, 0
	ADDWF      _unidades+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      _unidades+0
;Contador de pasajeros.c,47 :: 		if (unidades==10)
	MOVF       R1+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_conteo5
;Contador de pasajeros.c,49 :: 		unidades=0;
	CLRF       _unidades+0
;Contador de pasajeros.c,51 :: 		decenas++;
	INCF       _decenas+0, 1
;Contador de pasajeros.c,52 :: 		if (decenas==10)
	MOVF       _decenas+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_conteo6
;Contador de pasajeros.c,54 :: 		decenas=0;
	CLRF       _decenas+0
;Contador de pasajeros.c,56 :: 		centenas++;
	INCF       _centenas+0, 1
;Contador de pasajeros.c,57 :: 		if (centenas==10)
	MOVF       _centenas+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_conteo7
;Contador de pasajeros.c,59 :: 		centenas=0;
	CLRF       _centenas+0
;Contador de pasajeros.c,61 :: 		}
L_conteo7:
;Contador de pasajeros.c,62 :: 		}
L_conteo6:
;Contador de pasajeros.c,63 :: 		}
L_conteo5:
;Contador de pasajeros.c,64 :: 		}
L_end_conteo:
	RETURN
; end of _conteo

_multiplexado:

;Contador de pasajeros.c,66 :: 		void multiplexado(unsigned char veces)
;Contador de pasajeros.c,68 :: 		PORTD&=0x00;
	MOVLW      0
	ANDWF      PORTD+0, 1
;Contador de pasajeros.c,69 :: 		while(veces)
L_multiplexado8:
	MOVF       FARG_multiplexado_veces+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_multiplexado9
;Contador de pasajeros.c,71 :: 		PORTC=TABLA[centenas];
	MOVF       _centenas+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;Contador de pasajeros.c,72 :: 		PORTD=0x02;
	MOVLW      2
	MOVWF      PORTD+0
;Contador de pasajeros.c,74 :: 		delay_us(3333); //PIC
	MOVLW      5
	MOVWF      R12+0
	MOVLW      82
	MOVWF      R13+0
L_multiplexado10:
	DECFSZ     R13+0, 1
	GOTO       L_multiplexado10
	DECFSZ     R12+0, 1
	GOTO       L_multiplexado10
	NOP
	NOP
;Contador de pasajeros.c,75 :: 		PORTD=0x00;
	CLRF       PORTD+0
;Contador de pasajeros.c,77 :: 		PORTC=TABLA[decenas];
	MOVF       _decenas+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;Contador de pasajeros.c,78 :: 		PORTD=0x04;
	MOVLW      4
	MOVWF      PORTD+0
;Contador de pasajeros.c,80 :: 		delay_us(3333); //PIC
	MOVLW      5
	MOVWF      R12+0
	MOVLW      82
	MOVWF      R13+0
L_multiplexado11:
	DECFSZ     R13+0, 1
	GOTO       L_multiplexado11
	DECFSZ     R12+0, 1
	GOTO       L_multiplexado11
	NOP
	NOP
;Contador de pasajeros.c,81 :: 		PORTD=0x00;
	CLRF       PORTD+0
;Contador de pasajeros.c,83 :: 		PORTC=TABLA[unidades];
	MOVF       _unidades+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;Contador de pasajeros.c,84 :: 		PORTD=0x08;
	MOVLW      8
	MOVWF      PORTD+0
;Contador de pasajeros.c,86 :: 		delay_us(3333); //PIC
	MOVLW      5
	MOVWF      R12+0
	MOVLW      82
	MOVWF      R13+0
L_multiplexado12:
	DECFSZ     R13+0, 1
	GOTO       L_multiplexado12
	DECFSZ     R12+0, 1
	GOTO       L_multiplexado12
	NOP
	NOP
;Contador de pasajeros.c,87 :: 		PORTD=0x00;
	CLRF       PORTD+0
;Contador de pasajeros.c,89 :: 		veces--;
	DECF       FARG_multiplexado_veces+0, 1
;Contador de pasajeros.c,90 :: 		}
	GOTO       L_multiplexado8
L_multiplexado9:
;Contador de pasajeros.c,91 :: 		}
L_end_multiplexado:
	RETURN
; end of _multiplexado

_LecturaSens:

;Contador de pasajeros.c,93 :: 		void LecturaSens()
;Contador de pasajeros.c,95 :: 		delay_us(2500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_LecturaSens13:
	DECFSZ     R13+0, 1
	GOTO       L_LecturaSens13
	DECFSZ     R12+0, 1
	GOTO       L_LecturaSens13
	NOP
	NOP
;Contador de pasajeros.c,96 :: 		ADCON0=0xC3; //1100 0011 Activar conversión en canal 000
	MOVLW      195
	MOVWF      ADCON0+0
;Contador de pasajeros.c,97 :: 		while (ADCON0.GO_DONE)
L_LecturaSens14:
	BTFSS      ADCON0+0, 1
	GOTO       L_LecturaSens15
;Contador de pasajeros.c,98 :: 		{}
	GOTO       L_LecturaSens14
L_LecturaSens15:
;Contador de pasajeros.c,99 :: 		reg=ADRESH;
	MOVF       ADRESH+0, 0
	MOVWF      _reg+0
;Contador de pasajeros.c,101 :: 		if (reg>=0xAF)
	MOVLW      175
	SUBWF      _reg+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_LecturaSens16
;Contador de pasajeros.c,102 :: 		sensor1=1;
	MOVLW      1
	MOVWF      _sensor1+0
	GOTO       L_LecturaSens17
L_LecturaSens16:
;Contador de pasajeros.c,104 :: 		sensor1=0;
	CLRF       _sensor1+0
L_LecturaSens17:
;Contador de pasajeros.c,106 :: 		ADCON0=0xC5;  //1100 0101 Cambiamos de canal
	MOVLW      197
	MOVWF      ADCON0+0
;Contador de pasajeros.c,108 :: 		delay_us(2500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_LecturaSens18:
	DECFSZ     R13+0, 1
	GOTO       L_LecturaSens18
	DECFSZ     R12+0, 1
	GOTO       L_LecturaSens18
	NOP
	NOP
;Contador de pasajeros.c,109 :: 		ADCON0=0xC7;  //1100 0111 Activar conversión en canal 001
	MOVLW      199
	MOVWF      ADCON0+0
;Contador de pasajeros.c,111 :: 		while (ADCON0.GO_DONE)
L_LecturaSens19:
	BTFSS      ADCON0+0, 1
	GOTO       L_LecturaSens20
;Contador de pasajeros.c,112 :: 		{}
	GOTO       L_LecturaSens19
L_LecturaSens20:
;Contador de pasajeros.c,113 :: 		reg=ADRESH;
	MOVF       ADRESH+0, 0
	MOVWF      _reg+0
;Contador de pasajeros.c,115 :: 		if (reg>=0xAF) //700 = 1010 1111 00
	MOVLW      175
	SUBWF      _reg+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_LecturaSens21
;Contador de pasajeros.c,116 :: 		sensor2=1;
	MOVLW      1
	MOVWF      _sensor2+0
	GOTO       L_LecturaSens22
L_LecturaSens21:
;Contador de pasajeros.c,118 :: 		sensor2=0;
	CLRF       _sensor2+0
L_LecturaSens22:
;Contador de pasajeros.c,119 :: 		}
L_end_LecturaSens:
	RETURN
; end of _LecturaSens

_CompSens:

;Contador de pasajeros.c,121 :: 		void CompSens ()
;Contador de pasajeros.c,123 :: 		LecturaSens ();
	CALL       _LecturaSens+0
;Contador de pasajeros.c,124 :: 		if (sensor1==1&&sensor2==0)
	MOVF       _sensor1+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_CompSens25
	MOVF       _sensor2+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_CompSens25
L__CompSens32:
;Contador de pasajeros.c,126 :: 		PORTA.RA3=1;
	BSF        PORTA+0, 3
;Contador de pasajeros.c,127 :: 		}
	GOTO       L_CompSens26
L_CompSens25:
;Contador de pasajeros.c,129 :: 		else if (sensor1==0&&sensor2==1)
	MOVF       _sensor1+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_CompSens29
	MOVF       _sensor2+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_CompSens29
L__CompSens31:
;Contador de pasajeros.c,131 :: 		TRISA=0x1B; //0001 1011;
	MOVLW      27
	MOVWF      TRISA+0
;Contador de pasajeros.c,132 :: 		PORTA.RA3=0;
	BCF        PORTA+0, 3
;Contador de pasajeros.c,133 :: 		x=8; //PIC
	MOVLW      8
	MOVWF      _x+0
;Contador de pasajeros.c,135 :: 		}
	GOTO       L_CompSens30
L_CompSens29:
;Contador de pasajeros.c,139 :: 		TRISA=0x13; //0001 0011
	MOVLW      19
	MOVWF      TRISA+0
;Contador de pasajeros.c,140 :: 		PORTA.RA3=0;
	BCF        PORTA+0, 3
;Contador de pasajeros.c,141 :: 		conteo ();
	CALL       _conteo+0
;Contador de pasajeros.c,142 :: 		}
L_CompSens30:
L_CompSens26:
;Contador de pasajeros.c,143 :: 		}
L_end_CompSens:
	RETURN
; end of _CompSens
