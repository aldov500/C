#line 1 "C:/Users/Manuel/Desktop/CUCEI/Seminario de programación de sistemas embebidos/Laboratorios/11 PWM/Código/PWM.c"
int i;

void PW (int ancho);
void Periodo (int t);

void main()
{
 CCP1CON=0x0C;
 PIR1=0x02;
 T2CON=0x04;
 TRISC=0x00;

 Periodo (256);

 while (8)
 {
 for(i=0;i<=1000;i+=100)
 {
 PW(i);
 delay_ms(200);
 }

 for (i=1000;i>=0;i-=100)
 {
 PW(i);
 delay_ms(200);
 }
 }
}

void PW (int ancho)
{
 CCP1CON|=((ancho&0x0003)<<4);
 CCPR1L=ancho>>2;
}

void Periodo (int t)
{
 PR2=(t-1);
}
