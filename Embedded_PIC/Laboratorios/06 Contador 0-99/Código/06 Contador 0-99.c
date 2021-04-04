unsigned char decenas, unidades;
unsigned char TABLA[]={0x77,0x41,0x3B,0x6B,0x4D,0x6E,0x7E,0x43,0x7F,0x6F};

void conteo ();
void multiplexado (unsigned char veces);

void main(){
     TRISC&=0x00;
     TRISD&=0xFC;
     OPTION_REG&=0x7F;
     ANSELH&=0x00;
     PORTB+=0x01;
     
     while (8){
           if(PORTB.RB0=1)
                          {
                          conteo();
                          }
           multiplexado (25);
              }
           }

void conteo(){
     unidades++;
     if (unidades==10)
        {
        unidades=0;
        decenas++;
              
        if (decenas==10)
           {
           decenas=0;
           }
        }
              }
              
void multiplexado(unsigned char veces)
     {
     PORTD&=0x00;
     
     while(veces)
                 {
                 PORTC=TABLA[unidades];
                 PORTD+=0x02;
                 delay_ms(5);

                 PORTD-=0x01;
                 
                 PORTC=TABLA[decenas];
                 delay_ms(5);
                 PORTD-=0x01;
                 
                 veces--;
                 }
      }