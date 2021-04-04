unsigned char centenas=0, decenas=0, unidades=0, reg, sensor1, sensor2, x=0;
unsigned char TABLA[]={0x77,0x41,0x3B,0x6B,0x4D,0x6E,0x7E,0x43,0x7F,0x6F};

void multiplexado (unsigned char veces);
void conteo ();
void LecturaSens ();
void CompSens ();

void main() 
{
     TRISA=0x13;   //Configurar RA0, RA1 y RA4 como entradas     0001 0011
     ANSEL=0x03;   //"    "     RA0 y RA1 como entradas  análogas
     TRISB=0x00;  //Evitar ruido
     TRISC&=0x00;  //Configurar el puerto C como salida, Display
     TRISD=0x00;   //Configurar RD0, RD1, RD2 y RD3 como salidas, Habilitadores
     OPTION_REG=0xF8; //Configuración del timer
     ADCON0=0xC1; //Configura "Conversion Clock" e inicia el ADC
     ADCON1=0x00; //Justificación a la izquiera
     PORTC=0x00; //Limpiar el puerto C
     TMR0=0x00;  //Limpia el Timer
     
     while (8)
     {
           if (x==0)
              {
               PORTA.RA2=0;
               CompSens();
              }
           
           if (TMR0)
              {
               conteo();
              }
             multiplexado (10);

           if (x!=0)
              {
               x-=1;
              }
              TMR0=0;
     }
}

void conteo()
{    
     unidades=unidades+TMR0;
     if (unidades==10)
        {
        unidades=0;

        decenas++;
        if (decenas==10)
           {
           decenas=0;

           centenas++;
           if (centenas==10)
              {
              centenas=0;

              }
           }
        }
}

void multiplexado(unsigned char veces)
     {
     PORTD&=0x00;
     while(veces)
                 {
                 PORTC=TABLA[centenas];
                 PORTD=0x02;
                 //delay_ms(15); //Simulación;
                 delay_us(3333); //PIC
                 PORTD=0x00;
                 
                 PORTC=TABLA[decenas];
                 PORTD=0x04;
                 //delay_ms(15); //Simulación;
                 delay_us(3333); //PIC
                 PORTD=0x00;

                 PORTC=TABLA[unidades];
                 PORTD=0x08;
                 //delay_ms(15); //Simulación;
                 delay_us(3333); //PIC
                 PORTD=0x00;

                 veces--;
                 }
      }
      
void LecturaSens()
{
     delay_us(2500);
     ADCON0=0xC3; //1100 0011 Activar conversión en canal 000
     while (ADCON0.GO_DONE)
           {}
     reg=ADRESH;
     
     if (reg>=0xAF)
        sensor1=1;
     else
         sensor1=0;
 
     ADCON0=0xC5;  //1100 0101 Cambiamos de canal
     
     delay_us(2500);
     ADCON0=0xC7;  //1100 0111 Activar conversión en canal 001

     while (ADCON0.GO_DONE)
           {}
     reg=ADRESH;
     
     if (reg>=0xAF) //700 = 1010 1111 00
        sensor2=1;
     else
         sensor2=0;
}

void CompSens ()
{
     LecturaSens ();
           if (sensor1==1&&sensor2==0)
           {
            PORTA.RA3=1;
           }

           else if (sensor1==0&&sensor2==1)
           {
            TRISA=0x1B; //0001 1011;
            PORTA.RA3=0;
            x=8; //PIC
            //x=4; //Simulación
           }

           else
           {
            TRISA=0x13; //0001 0011
            PORTA.RA3=0;
            conteo ();
           }
}