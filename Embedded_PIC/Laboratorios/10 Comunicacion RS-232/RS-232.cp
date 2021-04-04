#line 1 "C:/Users/Manuel/Desktop/CUCEI/Seminario de programación de sistemas embebidos/Laboratorios/10 Comunicación RS-232/Código/RS-232.c"
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

 TRISD=0;
 PORTD=0xFF;
 TRISA.RA4=1;

 while(8)
 {
 if (!PORTA.RA4)
 {
 TXREG='1';
 while(!PORTA.RA4);
 }
 }
}

void interrupt()
{
 if (PIR1.RCIF)
 {
 PORTD=RCREG;
 }
}
