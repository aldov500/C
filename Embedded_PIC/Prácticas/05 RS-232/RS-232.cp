#line 1 "C:/Users/Manuel/Desktop/05 RS-232/RS-232.c"
unsigned char pos=1, clk, clk2;
unsigned char Tabla[]={0x3C, 0x66, 0xC3, 0x81, 0xC3, 0x42, 0xA5, 0xE7};

void Omega ();
void Pulso ();

void main()
{
 TXSTA.SYNC=0;
 TXSTA.BRGH=0;
 BAUDCTL.BRG16=0;

 SPBRG=25;

 RCSTA.SPEN=1;
 RCSTA.CREN=1;
 TXSTA.TXEN=1;

 PIE1.RCIE=1;
 INTCON.PEIE=1;
 INTCON.GIE=1;

 TRISB=0;
 TRISC=0x80;

 PortB=0;
 PortC=0;

 TRISA.RA4=1;
 ANSEL=0;
 ANSELH=0;

 while(8)
 {
 if (!PortA.RA0)
 {
 TXREG='M';
 delay_ms(5);
 TXREG='A';
 delay_ms(5);
 TXREG='N';
 delay_ms(5);
 TXREG='U';
 delay_ms(5);
 TXREG='E';
 delay_ms(5);
 TXREG='L';
 delay_ms(5);
 TXREG=' ';
 delay_ms(5);
 TXREG='L';
 delay_ms(5);
 TXREG='A';
 delay_ms(5);
 TXREG='R';
 delay_ms(5);
 TXREG='A';
 delay_ms(5);
 TXREG=' ';
 delay_ms(5);
 TXREG='2';
 delay_ms(5);
 TXREG='1';
 delay_ms(5);
 TXREG='0';
 delay_ms(5);
 TXREG='4';
 delay_ms(5);
 TXREG='5';
 delay_ms(5);
 TXREG='9';
 delay_ms(5);
 TXREG='9';
 delay_ms(5);
 TXREG='7';
 delay_ms(5);
 TXREG='4';
 delay_ms(5);
 TXREG=' ';

 while(!PORTA.RA4);
 }
 }
}

void interrupt()
{
 if (PIR1.RCIF)
 {
 Omega();
 }
}

void Omega()
{
 while (8)
 {
 PortC.RC2=1;

 clk=8;

 while (clk)
 {
 PORTB=Tabla[pos];
 Pulso();

 pos++;
 if (pos==8)
 {
 pos=0;
 }

 clk--;
 }

 PortC.RC2=0;
 Pulso();
 }
}

void Pulso ()
{
 PortC.RC3=1;
 delay_ms(1);
 PortC.RC3=0;
 delay_ms(1);
}
