
_main:

;09 ADC.c,1 :: 		void main()
;09 ADC.c,3 :: 		TRISC=0x00;
	CLRF       TRISC+0
;09 ADC.c,4 :: 		TRISD=~0x03;
	MOVLW      252
	MOVWF      TRISD+0
;09 ADC.c,6 :: 		TRISA=0x01;
	MOVLW      1
	MOVWF      TRISA+0
;09 ADC.c,7 :: 		ANSEL=0x01;
	MOVLW      1
	MOVWF      ANSEL+0
;09 ADC.c,9 :: 		ADCON0=0xC1;
	MOVLW      193
	MOVWF      ADCON0+0
;09 ADC.c,10 :: 		ADCON1=0x80;
	MOVLW      128
	MOVWF      ADCON1+0
;09 ADC.c,12 :: 		while (8)
L_main0:
;09 ADC.c,14 :: 		delay_ms(100);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	NOP
	NOP
;09 ADC.c,16 :: 		ADCON0=0xC3;
	MOVLW      195
	MOVWF      ADCON0+0
;09 ADC.c,18 :: 		while (ADCON0.GO_DONE)
L_main3:
	BTFSS      ADCON0+0, 1
	GOTO       L_main4
;09 ADC.c,20 :: 		}
	GOTO       L_main3
L_main4:
;09 ADC.c,21 :: 		PORTC=ADRESL;
	MOVF       ADRESL+0, 0
	MOVWF      PORTC+0
;09 ADC.c,22 :: 		PORTD=ADRESH;
	MOVF       ADRESH+0, 0
	MOVWF      PORTD+0
;09 ADC.c,23 :: 		}
	GOTO       L_main0
;09 ADC.c,24 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
