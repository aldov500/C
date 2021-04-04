// LCD module connections
sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;
// End LCD module connections

void TMR1_CFG();

long int cuenta = 0;
long int timer = 0;

char txt1[]="Frecuencimetro";
char txt2[20];
char txt3[]="Hz";

void main() {
  TMR1_CFG();
  ANSEL = 0;
  TRISA = 0x00;
  PORTA = 0x00;
  TRISD=0x00;
  PORTD=0x00;
  ANSELH=0;
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,1,txt1);
  Lcd_Out(2,14,txt3);'
  
  while(1){
    T1CON.TMR1ON = 1;
    delay_ms(1000);
    T1CON.TMR1ON = 0;
    PORTA = TMR1H;
    PORTD = TMR1L;
    timer = (TMR1H<<8) + TMR1L;
    cuenta = cuenta * 65536;
    timer = timer+cuenta;
    LongToStr(timer, txt2);
    Lcd_Out(2,1,txt2);
    TMR1H = 0x00;
    TMR1L = 0x00;
    cuenta = 0;
  }
}

void TMR1_CFG(){
  T1CON.T1GINV = 1;             //Puerta activado en Alto
  T1CON.TMR1GE = 0;             //Puerta activada
  T1CON.T1CKPS0 = 0;            //Preescaler 1:1
  T1CON.T1CKPS1 = 0;
  T1CON.T1SYNC = 0;             //No sincronizado
  T1CON.TMR1CS=1;               //Clock externo
  //T1CON.TMR1ON = 0;
  INTCON.GIE = 1;
  INTCON.PEIE = 1;
  PIE1.TMR1IE = 1;              //Interrupcion por overflow del TMR1IE
}

void interrupt(){
   if (PIR1.TMR1IF){
     cuenta++;
     PIR1.TMR1IF = 0;
   }
}