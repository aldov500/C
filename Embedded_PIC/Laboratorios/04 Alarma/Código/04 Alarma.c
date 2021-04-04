void main() {
     TRISC=0;
     OPTION_REG=0x7F;
     ANSELH=0;
     PORTB=0xFF;
     
     while (8)
           {
           if(PORTB.RB0)
                        {
                        PORTC=PORTB&0x77;
                        delay_ms(250);
                        PORTC=1;
                        delay_ms(250);
                        }
           else
               {
               PORTC=0;
               }
           }
}