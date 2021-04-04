unsigned char pos=1, veces, clk, clk2;
unsigned char TABLAa[]={0x3C, 0x66, 0xC3, 0x81, 0xC3, 0x42, 0xA5, 0xE7};

void Omega ();
void Pulso ();

void main() 
{
     TRISB=0;
     TRISC=0x80;
     
     PortB=0;
     PortC=0;
     
     TRISA.RA4=1;
     ANSEL=0;
     ANSELH=0;
     
     while(8)
     {
      if (PortA.RA0)
         {
          veces=100;
          Omega();
         }
     }
}

void Omega()
{
   while (veces)
        {
         PortC.RC2=1;
         clk=8;
         
         while (clk)
               {
                PORTB=TABLAa[pos];
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
               veces--;
          }
          
   PORTB=0;
}

void Pulso ()
{
   PortC.RC3=1;
   delay_ms(1);
   PortC.RC3=0;
   delay_ms(1);
}