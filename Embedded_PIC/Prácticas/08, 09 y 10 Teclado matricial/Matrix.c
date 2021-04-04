unsigned short TeclaPar=0, TeclaPres=0, x=0,Ronda=1, Turno, kp;
unsigned char alm[10], led[10];
char keypadPort at PORTD;

sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

void Inicio();                                 //Funciones
void Mostrar();                                //del
void Adquirir();                               //Programa
void Comparacion();

void main()
{
 TRISC=0;                                        //Puerto C como salida
 PORTC=0;                                        //Limpiar Puerto C

 TRISA=0x01;                                     //Bit 0 de PORTA como entrada
 PORTA=0;                                        //Limpiar puerto A

 ANSEL=0;                                 // Entradas en PORTA y
 ANSELH=0;                                // PORTB como digitales.

 Lcd_init();                              // Inicia la LCD
 Keypad_init();                            // Inicia el teclado matricial
 Lcd_Cmd(_LCD_CLEAR);                     // Limpia el display.
 Lcd_Cmd(_LCD_CURSOR_OFF);                // Apaga el cursor.

 led[1]=1;
 alm[1]=1;

 while(8)                                       //Ciclo Infinito
      {
       while (Ronda)                            //Mientras no se haya  perdido
             {
               if (Ronda==1)                          //Mensaje por defecto al iniciar el juego
               {
                LCD_Out(1, 1, "TecladoMatricial");
                LCD_Out(2, 1, " Practica 8 y 9");
               }

               else if(Ronda>1)                              //Mensaje en rondas posteriores
               {
                LCD_Out(1, 1, " Siguiente Ronda");
               }

               if (PORTA.RA0)                                 //Al presionar RA0 se inicia el programa
                  {
                   x=1;
                   Inicio();
                   Mostrar();
                   Adquirir();
                   Comparacion();
                  }
             }
      }
}

void Inicio()
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "   Atencion... ");
 delay_ms(1000);
}

void Mostrar()                                       //Mostrar en los LED la secuencia
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "     .  .  .");
 Turno=Ronda;

 while (Turno)                                       //Ciclo para crear la secuencia
       {
        x+=3;                                        //Función para que sea seudoaleaotorio
        
        if (x==1)
        x=2;
        
        if (x==11)                                    //Funciones
        x=1;                                          //En
        if (x==13|x==14)                              //Caso
        x=5;                                          //Que
        if (x==15)                                    //Se
        x=3;                                          //Rebase
        if (x==16)                                    //el
        x=1;                                          //número de
        if (x>=17)                                    //LEDs
        x=11;

        switch (x)
               {
                case  1: PORTC.RC0 = 1; break;
                case  2: PORTC.RC1 = 1; break;
                case  3: PORTC.RC2 = 1; break;
                case  4: PORTC.RC3 = 1; break;
                case  5: PORTC.RC4 = 1; break;
                case  6: PORTC.RC5 = 1; break;
                case  7: PORTC.RC6 = 1; break;
                case  8: PORTC.RC7 = 1; break;
                case  9: PORTA.RA4 = 1; break;
                case 10: PORTA.RA5 = 1; break;
                case 11: PORTA.RA6 = 1; break;
                case 12: PORTA.RA7 = 1; break;
               }
        led[Turno]=x;
        
        if (Ronda==1)
        {                                               //Aumentar dificultad
         delay_ms(1000);
        }
        
         else if (Ronda==2)
         {
          delay_ms(850);
         }
         
          else if (Ronda==3)
         {
          delay_ms(700);
         }
         
          else if (Ronda==4)
          {
           delay_ms(550);
          }
          
           else if (Ronda==5)
           {
            delay_ms(450);
           }
           
            else if (Ronda==6)
            {
             delay_ms(350);
             }
           
        else delay_ms(200);
        
        Turno--;

        PORTA=1;
        PORTC=0;
        delay_ms(50);
       }
}

void Adquirir()                                           //Adquirir el valor tecleado
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, " Introduzca la");
 Lcd_Out(2, 1, "     secuencia");
 Turno=Ronda;

 while (Turno)
       {
        do
        {
         kp = Keypad_Key_Click();
         delay_ms(100);
        }
        while (!kp);

        switch (kp)
              {
               case  1: alm[Turno] = 1; break;
               case  2: alm[Turno] = 2; break;
               case  3: alm[Turno] = 3; break;
               case  4: alm[Turno] = 4; break;
               case  5: alm[Turno] = 5; break;
               case  6: alm[Turno] = 6; break;
               case  7: alm[Turno] = 7; break;
               case  8: alm[Turno] = 8; break;
               case  9: alm[Turno] = 9; break;
               case 10: alm[Turno] = 10; break;
               case 11: alm[Turno] = 11; break;
               case 12: alm[Turno] = 12; break;
                }
         Turno--;
    }
}

void Comparacion()                                                //Comparar el valor del LED con el tecleado
{
 Turno=Ronda;
 Lcd_cmd(_LCD_CLEAR);

 if (alm[Turno]==led[Turno])                                      //Si son iguales
    {
     Ronda++;                                                     //-Se avanza de ronda
     Lcd_Out (1, 1, "    CORRECTO!");                             //Y se muestra este mensaje
     delay_ms(750);
    }

    else if (led[Turno]!=alm[Turno])                              //Si no
            {
             Ronda=0;                                             // Ronda es 0 para salir del ciclo principal
             Lcd_Out(1, 1, "   Incorrecto!");                     // Y se despliega
             Lcd_Out(2, 1,  "  FIN DEL JUEGO");                   // este mensaje
             delay_ms(10000);
            }

  LCD_cmd(_LCD_CLEAR);
}