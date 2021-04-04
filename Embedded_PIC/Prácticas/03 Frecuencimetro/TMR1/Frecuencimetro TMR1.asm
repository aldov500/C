
_main:

;Frecuencimetro TMR1.c,25 :: 		void main() {
;Frecuencimetro TMR1.c,26 :: 		TMR1_CFG();
	CALL       _TMR1_CFG+0
;Frecuencimetro TMR1.c,27 :: 		ANSEL = 0;
	CLRF       ANSEL+0
;Frecuencimetro TMR1.c,28 :: 		TRISA = 0x00;
	CLRF       TRISA+0
;Frecuencimetro TMR1.c,29 :: 		PORTA = 0x00;
	CLRF       PORTA+0
;Frecuencimetro TMR1.c,30 :: 		TRISD=0x00;
	CLRF       TRISD+0
;Frecuencimetro TMR1.c,31 :: 		PORTD=0x00;
	CLRF       PORTD+0
;Frecuencimetro TMR1.c,32 :: 		ANSELH=0;
	CLRF       ANSELH+0
;Frecuencimetro TMR1.c,33 :: 		Lcd_Init();                        // Initialize LCD
	CALL       _Lcd_Init+0
;Frecuencimetro TMR1.c,34 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Frecuencimetro TMR1.c,35 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Frecuencimetro TMR1.c,36 :: 		Lcd_Out(1,1,txt1);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Frecuencimetro TMR1.c,37 :: 		Lcd_Out(2,14,txt3);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      14
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt3+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Frecuencimetro TMR1.c,39 :: 		while(1){
L_main0:
;Frecuencimetro TMR1.c,40 :: 		T1CON.TMR1ON = 1;
	BSF        T1CON+0, 0
;Frecuencimetro TMR1.c,41 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;Frecuencimetro TMR1.c,42 :: 		T1CON.TMR1ON = 0;
	BCF        T1CON+0, 0
;Frecuencimetro TMR1.c,43 :: 		PORTA = TMR1H;
	MOVF       TMR1H+0, 0
	MOVWF      PORTA+0
;Frecuencimetro TMR1.c,44 :: 		PORTD = TMR1L;
	MOVF       TMR1L+0, 0
	MOVWF      PORTD+0
;Frecuencimetro TMR1.c,45 :: 		timer = (TMR1H<<8) + TMR1L;
	CLRF       _timer+3
	MOVF       TMR1H+1, 0
	MOVWF      _timer+2
	MOVF       TMR1H+0, 0
	MOVWF      _timer+1
	CLRF       _timer+0
	MOVF       TMR1L+0, 0
	ADDWF      _timer+0, 1
	BTFSC      STATUS+0, 0
	INCF       _timer+1, 1
	MOVLW      0
	MOVWF      _timer+2
	MOVWF      _timer+3
;Frecuencimetro TMR1.c,46 :: 		cuenta = cuenta * 65536;
	MOVF       _cuenta+1, 0
	MOVWF      R0+3
	MOVF       _cuenta+0, 0
	MOVWF      R0+2
	CLRF       R0+0
	CLRF       R0+1
	MOVF       R0+0, 0
	MOVWF      _cuenta+0
	MOVF       R0+1, 0
	MOVWF      _cuenta+1
	MOVF       R0+2, 0
	MOVWF      _cuenta+2
	MOVF       R0+3, 0
	MOVWF      _cuenta+3
;Frecuencimetro TMR1.c,47 :: 		timer = timer+cuenta;
	MOVF       _timer+0, 0
	ADDWF      R0+0, 1
	MOVF       _timer+1, 0
	BTFSC      STATUS+0, 0
	INCFSZ     _timer+1, 0
	ADDWF      R0+1, 1
	MOVF       _timer+2, 0
	BTFSC      STATUS+0, 0
	INCFSZ     _timer+2, 0
	ADDWF      R0+2, 1
	MOVF       _timer+3, 0
	BTFSC      STATUS+0, 0
	INCFSZ     _timer+3, 0
	ADDWF      R0+3, 1
	MOVF       R0+0, 0
	MOVWF      _timer+0
	MOVF       R0+1, 0
	MOVWF      _timer+1
	MOVF       R0+2, 0
	MOVWF      _timer+2
	MOVF       R0+3, 0
	MOVWF      _timer+3
;Frecuencimetro TMR1.c,48 :: 		LongToStr(timer, txt2);
	MOVF       R0+0, 0
	MOVWF      FARG_LongToStr_input+0
	MOVF       R0+1, 0
	MOVWF      FARG_LongToStr_input+1
	MOVF       R0+2, 0
	MOVWF      FARG_LongToStr_input+2
	MOVF       R0+3, 0
	MOVWF      FARG_LongToStr_input+3
	MOVLW      _txt2+0
	MOVWF      FARG_LongToStr_output+0
	CALL       _LongToStr+0
;Frecuencimetro TMR1.c,49 :: 		Lcd_Out(2,1,txt2);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Frecuencimetro TMR1.c,50 :: 		TMR1H = 0x00;
	CLRF       TMR1H+0
;Frecuencimetro TMR1.c,51 :: 		TMR1L = 0x00;
	CLRF       TMR1L+0
;Frecuencimetro TMR1.c,52 :: 		cuenta = 0;
	CLRF       _cuenta+0
	CLRF       _cuenta+1
	CLRF       _cuenta+2
	CLRF       _cuenta+3
;Frecuencimetro TMR1.c,53 :: 		}
	GOTO       L_main0
;Frecuencimetro TMR1.c,54 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_TMR1_CFG:

;Frecuencimetro TMR1.c,56 :: 		void TMR1_CFG(){
;Frecuencimetro TMR1.c,57 :: 		T1CON.T1GINV = 1;             //Puerta activado en Alto
	BSF        T1CON+0, 7
;Frecuencimetro TMR1.c,58 :: 		T1CON.TMR1GE = 0;             //Puerta activada
	BCF        T1CON+0, 6
;Frecuencimetro TMR1.c,59 :: 		T1CON.T1CKPS0 = 0;            //Preescaler 1:1
	BCF        T1CON+0, 4
;Frecuencimetro TMR1.c,60 :: 		T1CON.T1CKPS1 = 0;
	BCF        T1CON+0, 5
;Frecuencimetro TMR1.c,61 :: 		T1CON.T1SYNC = 0;             //No sincronizado
	BCF        T1CON+0, 2
;Frecuencimetro TMR1.c,62 :: 		T1CON.TMR1CS=1;               //Clock externo
	BSF        T1CON+0, 1
;Frecuencimetro TMR1.c,64 :: 		INTCON.GIE = 1;
	BSF        INTCON+0, 7
;Frecuencimetro TMR1.c,65 :: 		INTCON.PEIE = 1;
	BSF        INTCON+0, 6
;Frecuencimetro TMR1.c,66 :: 		PIE1.TMR1IE = 1;              //Interrupcion por overflow del TMR1IE
	BSF        PIE1+0, 0
;Frecuencimetro TMR1.c,67 :: 		}
L_end_TMR1_CFG:
	RETURN
; end of _TMR1_CFG

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;Frecuencimetro TMR1.c,69 :: 		void interrupt(){
;Frecuencimetro TMR1.c,70 :: 		if (PIR1.TMR1IF){
	BTFSS      PIR1+0, 0
	GOTO       L_interrupt3
;Frecuencimetro TMR1.c,71 :: 		cuenta++;
	MOVF       _cuenta+0, 0
	MOVWF      R0+0
	MOVF       _cuenta+1, 0
	MOVWF      R0+1
	MOVF       _cuenta+2, 0
	MOVWF      R0+2
	MOVF       _cuenta+3, 0
	MOVWF      R0+3
	INCF       R0+0, 1
	BTFSC      STATUS+0, 2
	INCF       R0+1, 1
	BTFSC      STATUS+0, 2
	INCF       R0+2, 1
	BTFSC      STATUS+0, 2
	INCF       R0+3, 1
	MOVF       R0+0, 0
	MOVWF      _cuenta+0
	MOVF       R0+1, 0
	MOVWF      _cuenta+1
	MOVF       R0+2, 0
	MOVWF      _cuenta+2
	MOVF       R0+3, 0
	MOVWF      _cuenta+3
;Frecuencimetro TMR1.c,72 :: 		PIR1.TMR1IF = 0;
	BCF        PIR1+0, 0
;Frecuencimetro TMR1.c,73 :: 		}
L_interrupt3:
;Frecuencimetro TMR1.c,74 :: 		}
L_end_interrupt:
L__interrupt7:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt
