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
     
     TRISB=0;         //Se usará el PuertoB para mandar los valores a las filas
     TRISC=0x80;      //Y dos bits del puerto C para el multiplexado
     
     PortB=0;         //Se limpian los puertos
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
         PortC.RC2=1;                     //Se manda un uno al SIPO para deshabilitar todas las columnas en cada barrido
         
         clk=8;

         while (clk)                     //Se repetirá esta acción ocho veces
               {
                PORTB=Tabla[pos];       //Se imprime en el PuertoB lo que hay en la Tabla
                Pulso();                //Se da un flanco de subida para recorrer el display
                
                pos++;
                if (pos==8)             //Si el valor de la posición es mayor a 8 se regresa al valor inicial
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