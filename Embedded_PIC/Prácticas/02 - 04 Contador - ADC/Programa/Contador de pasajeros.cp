#line 1 "C:/Users/Manuel/Desktop/Práctica #2/Programa/Contador de pasajeros.c"
unsigned char centenas=0, decenas=0, unidades=0, reg, sensor1, sensor2, x=0;
unsigned char TABLA[]={0x77,0x41,0x3B,0x6B,0x4D,0x6E,0x7E,0x43,0x7F,0x6F};

void multiplexado (unsigned char veces);
void conteo ();
void LecturaSens ();
void CompSens ();

void main()
{
 TRISA=0x13;
 ANSEL=0x03;
 TRISB=0x00;
 TRISC&=0x00;
 TRISD=0x00;
 OPTION_REG=0xF8;
 ADCON0=0xC1;
 ADCON1=0x00;
 PORTC=0x00;
 TMR0=0x00;

 while (8)
 {
 if (x==0)
 {
 PORTA.RA2=0;
 CompSens();
 }

 if (TMR0)
 {
 conteo();
 }
 multiplexado (10);

 if (x!=0)
 {
 x-=1;
 }
 TMR0=0;
 }
}

void conteo()
{
 unidades=unidades+TMR0;
 if (unidades==10)
 {
 unidades=0;

 decenas++;
 if (decenas==10)
 {
 decenas=0;

 centenas++;
 if (centenas==10)
 {
 centenas=0;

 }
 }
 }
}

void multiplexado(unsigned char veces)
 {
 PORTD&=0x00;
 while(veces)
 {
 PORTC=TABLA[centenas];
 PORTD=0x02;

 delay_us(3333);
 PORTD=0x00;

 PORTC=TABLA[decenas];
 PORTD=0x04;

 delay_us(3333);
 PORTD=0x00;

 PORTC=TABLA[unidades];
 PORTD=0x08;

 delay_us(3333);
 PORTD=0x00;

 veces--;
 }
 }

void LecturaSens()
{
 delay_us(2500);
 ADCON0=0xC3;
 while (ADCON0.GO_DONE)
 {}
 reg=ADRESH;

 if (reg>=0xAF)
 sensor1=1;
 else
 sensor1=0;

 ADCON0=0xC5;

 delay_us(2500);
 ADCON0=0xC7;

 while (ADCON0.GO_DONE)
 {}
 reg=ADRESH;

 if (reg>=0xAF)
 sensor2=1;
 else
 sensor2=0;
}

void CompSens ()
{
 LecturaSens ();
 if (sensor1==1&&sensor2==0)
 {
 PORTA.RA3=1;
 }

 else if (sensor1==0&&sensor2==1)
 {
 TRISA=0x1B;
 PORTA.RA3=0;
 x=8;

 }

 else
 {
 TRISA=0x13;
 PORTA.RA3=0;
 conteo ();
 }
}
