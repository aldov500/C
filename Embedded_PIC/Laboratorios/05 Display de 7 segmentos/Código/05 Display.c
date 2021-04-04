unsigned char cuenta;
unsigned char TABLA[]={0x77, 0x41, 0x3B, 0x6B, 0x4D, 0x6E, 0x7E, 0x43, 0x7F, 0x6F};

void main() {
     TRISC=0;
     
     while (1)
           {
           for (cuenta=0;cuenta!=10;cuenta+=1)
            {
               PORTC=TABLA[cuenta];
               delay_ms(500);
            }
           }
            }