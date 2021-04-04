
_main:

;06 Contador 0-99.c,7 :: 		void main(){
;06 Contador 0-99.c,8 :: 		TRISC&=0x00;
	MOVLW      0
	ANDWF      TRISC+0, 1
;06 Contador 0-99.c,9 :: 		TRISD&=0xFC;
	MOVLW      252
	ANDWF      TRISD+0, 1
;06 Contador 0-99.c,10 :: 		OPTION_REG&=0x7F;
	MOVLW      127
	ANDWF      OPTION_REG+0, 1
;06 Contador 0-99.c,11 :: 		ANSELH&=0x00;
	MOVLW      0
	ANDWF      ANSELH+0, 1
;06 Contador 0-99.c,12 :: 		PORTB+=0x01;
	INCF       PORTB+0, 1
;06 Contador 0-99.c,14 :: 		while (8){
L_main0:
;06 Contador 0-99.c,15 :: 		if(PORTB.RB0=1)
	BSF        PORTB+0, 0
	BTFSS      PORTB+0, 0
	GOTO       L_main2
;06 Contador 0-99.c,17 :: 		conteo();
	CALL       _conteo+0
;06 Contador 0-99.c,18 :: 		}
L_main2:
;06 Contador 0-99.c,19 :: 		multiplexado (25);
	MOVLW      25
	MOVWF      FARG_multiplexado_veces+0
	CALL       _multiplexado+0
;06 Contador 0-99.c,20 :: 		}
	GOTO       L_main0
;06 Contador 0-99.c,21 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_conteo:

;06 Contador 0-99.c,23 :: 		void conteo(){
;06 Contador 0-99.c,24 :: 		unidades++;
	INCF       _unidades+0, 1
;06 Contador 0-99.c,25 :: 		if (unidades==10)
	MOVF       _unidades+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_conteo3
;06 Contador 0-99.c,27 :: 		unidades=0;
	CLRF       _unidades+0
;06 Contador 0-99.c,28 :: 		decenas++;
	INCF       _decenas+0, 1
;06 Contador 0-99.c,30 :: 		if (decenas==10)
	MOVF       _decenas+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_conteo4
;06 Contador 0-99.c,32 :: 		decenas=0;
	CLRF       _decenas+0
;06 Contador 0-99.c,33 :: 		}
L_conteo4:
;06 Contador 0-99.c,34 :: 		}
L_conteo3:
;06 Contador 0-99.c,35 :: 		}
L_end_conteo:
	RETURN
; end of _conteo

_multiplexado:

;06 Contador 0-99.c,37 :: 		void multiplexado(unsigned char veces)
;06 Contador 0-99.c,39 :: 		PORTD&=0x00;
	MOVLW      0
	ANDWF      PORTD+0, 1
;06 Contador 0-99.c,41 :: 		while(veces)
L_multiplexado5:
	MOVF       FARG_multiplexado_veces+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_multiplexado6
;06 Contador 0-99.c,43 :: 		PORTC=TABLA[unidades];
	MOVF       _unidades+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;06 Contador 0-99.c,44 :: 		PORTD+=0x02;
	MOVLW      2
	ADDWF      PORTD+0, 1
;06 Contador 0-99.c,45 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_multiplexado7:
	DECFSZ     R13+0, 1
	GOTO       L_multiplexado7
	DECFSZ     R12+0, 1
	GOTO       L_multiplexado7
;06 Contador 0-99.c,47 :: 		PORTD-=0x01;
	DECF       PORTD+0, 1
;06 Contador 0-99.c,49 :: 		PORTC=TABLA[decenas];
	MOVF       _decenas+0, 0
	ADDLW      _TABLA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;06 Contador 0-99.c,50 :: 		delay_ms(5);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_multiplexado8:
	DECFSZ     R13+0, 1
	GOTO       L_multiplexado8
	DECFSZ     R12+0, 1
	GOTO       L_multiplexado8
;06 Contador 0-99.c,51 :: 		PORTD-=0x01;
	DECF       PORTD+0, 1
;06 Contador 0-99.c,53 :: 		veces--;
	DECF       FARG_multiplexado_veces+0, 1
;06 Contador 0-99.c,54 :: 		}
	GOTO       L_multiplexado5
L_multiplexado6:
;06 Contador 0-99.c,55 :: 		}
L_end_multiplexado:
	RETURN
; end of _multiplexado
