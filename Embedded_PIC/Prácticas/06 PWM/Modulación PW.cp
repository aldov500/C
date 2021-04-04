#line 1 "C:/Users/Manuel/Desktop/06 PWM/Modulación PW.c"
unsigned char DutyActual;
unsigned short x=1;

void main()
{
 TRISA=0x03;
 ANSEL=0;

 PORTA=0x03;

 PWM1_Init(2000);
 PWM1_Start();

 while (8)
 {
 if (!PORTA.RA0)
 {
 if (x!=6)
 {
 x++;
 }
 while (!PORTA.RA0);
 }

 if (!PORTA.RA1)
 {
 if (x!=1)
 {
 x--;
 }
 while (!PORTA.RA1);
 }

 switch (x)
 {
 case 1:
 {
 PWM1_Set_Duty(0);
 break;
 }

 case 2:
 {
 DutyActual=25;
 PWM1_Set_Duty(DutyActual);
 break;
 }

 case 3:
 {
 DutyActual=50;
 PWM1_Set_Duty(DutyActual);
 break;
 }

 case 4:
 {
 DutyActual=75;
 PWM1_Set_Duty(DutyActual);
 break;
 }

 case 5:
 {
 DutyActual=100;
 PWM1_Set_Duty(DutyActual);
 break;
 }

 case 6:
 {
 DutyActual=150;
 PWM1_Set_Duty(DutyActual);
 break;
 }
 delay_ms(3);
 }
 }
}
