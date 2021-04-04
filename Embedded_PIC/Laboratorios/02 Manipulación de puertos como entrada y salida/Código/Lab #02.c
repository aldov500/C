void main() 
     {
         TRISC=0x00;
         OPTION_REG=0x7F;
         ANSELH=0x00;
         PORTB=0xFF;

while (8)
      {
      PORTC=PORTB;
      }
     }