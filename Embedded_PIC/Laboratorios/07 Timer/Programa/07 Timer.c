void main() 
{
     OPTION_REG=0xF8;
     TRISC=0x00;
     PORTC=0x00;
     TMR0=0x00;
     
     while (8)
     {
      PORTC=TMR0;
     }
}