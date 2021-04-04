#line 1 "C:/Users/Manuel/Desktop/08, 09 y 10 Teclado matricial/Matrix.c"
unsigned short TeclaPar=0, TeclaPres=0, x=0,Ronda=1, Turno, kp;
unsigned char alm[10], led[10];
char keypadPort at PORTD;

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

void Inicio();
void Mostrar();
void Adquirir();
void Comparacion();

void main()
{
 TRISC=0;
 PORTC=0;

 TRISA=0x01;
 PORTA=0;

 ANSEL=0;
 ANSELH=0;

 Lcd_init();
 Keypad_init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 led[1]=1;
 alm[1]=1;

 while(8)
 {
 while (Ronda)
 {
 if (Ronda==1)
 {
 LCD_Out(1, 1, "TecladoMatricial");
 LCD_Out(2, 1, " Practica 8 y 9");
 }

 else if(Ronda>1)
 {
 LCD_Out(1, 1, " Siguiente Ronda");
 }

 if (PORTA.RA0)
 {
 x=1;
 Inicio();
 Mostrar();
 Adquirir();
 Comparacion();
 }
 }
 }
}

void Inicio()
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "   Atencion... ");
 delay_ms(1000);
}

void Mostrar()
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "     .  .  .");
 Turno=Ronda;

 while (Turno)
 {
 x+=3;

 if (x==1)
 x=2;

 if (x==11)
 x=1;
 if (x==13|x==14)
 x=5;
 if (x==15)
 x=3;
 if (x==16)
 x=1;
 if (x>=17)
 x=11;

 switch (x)
 {
 case 1: PORTC.RC0 = 1; break;
 case 2: PORTC.RC1 = 1; break;
 case 3: PORTC.RC2 = 1; break;
 case 4: PORTC.RC3 = 1; break;
 case 5: PORTC.RC4 = 1; break;
 case 6: PORTC.RC5 = 1; break;
 case 7: PORTC.RC6 = 1; break;
 case 8: PORTC.RC7 = 1; break;
 case 9: PORTA.RA4 = 1; break;
 case 10: PORTA.RA5 = 1; break;
 case 11: PORTA.RA6 = 1; break;
 case 12: PORTA.RA7 = 1; break;
 }
 led[Turno]=x;

 if (Ronda==1)
 {
 delay_ms(1000);
 }

 else if (Ronda==2)
 {
 delay_ms(850);
 }

 else if (Ronda==3)
 {
 delay_ms(700);
 }

 else if (Ronda==4)
 {
 delay_ms(550);
 }

 else if (Ronda==5)
 {
 delay_ms(450);
 }

 else if (Ronda==6)
 {
 delay_ms(350);
 }

 else delay_ms(200);

 Turno--;

 PORTA=1;
 PORTC=0;
 delay_ms(50);
 }
}

void Adquirir()
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, " Introduzca la");
 Lcd_Out(2, 1, "     secuencia");
 Turno=Ronda;

 while (Turno)
 {
 do
 {
 kp = Keypad_Key_Click();
 delay_ms(100);
 }
 while (!kp);

 switch (kp)
 {
 case 1: alm[Turno] = 1; break;
 case 2: alm[Turno] = 2; break;
 case 3: alm[Turno] = 3; break;
 case 4: alm[Turno] = 4; break;
 case 5: alm[Turno] = 5; break;
 case 6: alm[Turno] = 6; break;
 case 7: alm[Turno] = 7; break;
 case 8: alm[Turno] = 8; break;
 case 9: alm[Turno] = 9; break;
 case 10: alm[Turno] = 10; break;
 case 11: alm[Turno] = 11; break;
 case 12: alm[Turno] = 12; break;
 }
 Turno--;
 }
}

void Comparacion()
{
 Turno=Ronda;
 Lcd_cmd(_LCD_CLEAR);

 if (alm[Turno]==led[Turno])
 {
 Ronda++;
 Lcd_Out (1, 1, "    CORRECTO!");
 delay_ms(750);
 }

 else if (led[Turno]!=alm[Turno])
 {
 Ronda=0;
 Lcd_Out(1, 1, "   Incorrecto!");
 Lcd_Out(2, 1, "  FIN DEL JUEGO");
 delay_ms(10000);
 }

 LCD_cmd(_LCD_CLEAR);
}
