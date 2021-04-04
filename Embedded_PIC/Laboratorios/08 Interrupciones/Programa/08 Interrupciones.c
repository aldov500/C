unsigned char cuenta;

void main() 
{
 OPTION_REG=0xD7;
 INTCON=0xA0;
 TMR0=0x00;

 TRISC=0xFE;
 PORTC=0x00;

 while(8)
 {}
}

void interrupt()
{
 if (INTCON.TMR0IF)
 {
    cuenta++;
           
           if(cuenta==7)
           {
           cuenta=0;
           PORTC.RC0=~PORTC.RC0;
           INTCON.TMR0IF=0;
           }
    INTCON.TMR0IF=0;
 }
}