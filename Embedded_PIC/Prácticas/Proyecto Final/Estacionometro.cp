#line 1 "C:/Users/Manuel/Desktop/Proyecto Final/Estacionometro.c"
int dis, i, x=0, pasx=0;
char txt[7];

sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

void main()
{
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 TRISB=0x10;
 ANSELH=0;
 TRISD=0;
 PORTD.RD0=0;
 PORTD.RD1=0;

 Lcd_Out(1,1," Proyecto Final");
 Lcd_Out(2,1,"Progr. Embebidos");

 Delay_ms(2500);

 T1CON = 0x10;

 for (i=0; i!=2; i++)
 {
 PortD.RD0=~PortD.RD0;
 PortD.RD1=~PortD.RD1;
 delay_ms(500);
 }

 while(1)
 {
 LCD_cmd(_LCD_RETURN_HOME);
 TMR1H = 0;
 TMR1L = 0;

 PORTB.B0 = 1;
 Delay_us(10);
 PORTB.B0 = 0;

 while(!PORTB.B4);
 T1CON.F0 = 1;
 while(PORTB.B4);
 T1CON.F0 = 0;

 dis=(TMR1L|(TMR1H<<8));
 dis/=29.41*.5;

 IntToStr(dis,txt);
 Ltrim(txt);

 if (dis<9)
 {
 x=1;
 if (x!=pasx)
 {
 LCD_cmd(_LCD_CLEAR);
 }

 Lcd_Out(1, 1, "  DETENGASE");

 PortD.RD0=1;
 PortD.RD1=1;
 delay_ms(250);
 PortD.RD0=0;
 PortD.RD1=0;

 pasx=x;
 }

 else if (dis>=10&&dis<=19)
 {
 x=2;
 LCD_cmd(_LCD_CLEAR);

 Lcd_Out(1,1,"Distancia= ");
 Lcd_Out(1,12, txt);
 Lcd_Out(1,15,"cm");
 delay_ms(400);

 Lcd_Cmd(_LCD_CLEAR);

 Lcd_Out(1,1, " Objeto Cercano");
 Lcd_Out(2,1, "   Detectado");

 PortD.RD0=1;
 PortD.RD1=1;
 delay_ms(500);
 PortD.RD0=0;
 PortD.RD1=0;
 pasx=x;
 }

 else if (dis>=20&&dis<=149)
 {
 x=3;
 if (x!=pasx)
 {
 LCD_cmd(_LCD_CLEAR);
 }
 Lcd_Out(1,1,"Distancia= ");
 Lcd_Out(1,12, txt);
 Lcd_Out(1,15,"cm");
 pasx=x;
 }

 else if (dis>=150)
 {
 x=4;
 if (x!=pasx)
 {
 LCD_cmd(_LCD_CLEAR);
 }
 Lcd_Out(1,1," No se detecta algun objeto cercano");
 for (i=0; i!=18; i++)
 {
 delay_ms(180);
 Lcd_cmd(_LCD_SHIFT_LEFT);
 }
 pasx=x;
 }

 Delay_ms(200);
 }
}
