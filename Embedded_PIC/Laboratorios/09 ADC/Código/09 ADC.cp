#line 1 "C:/Users/Manuel/Desktop/CUCEI/Seminario de programación de sistemas embebidos/Laboratorios/09 ADC/Código/09 ADC.c"
void main()
 {
 TRISC=0x00;
 TRISD=~0x03;

 TRISA=0x01;
 ANSEL=0x01;

 ADCON0=0xC1;
 ADCON1=0x80;

 while (8)
 {
 delay_ms(100);

 ADCON0=0xC3;

 while (ADCON0.GO_DONE)
 {
 }
 PORTC=ADRESL;
 PORTD=ADRESH;
 }
 }
