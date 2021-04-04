#line 1 "C:/Users/Manuel/Desktop/CUCEI/Seminario de programación de sistemas embebidos/Laboratorios/12 LCD/Código/12 LCD.c"
volatile unsigned char TEXTO1[]={" C con el MICRO \n"};
volatile unsigned char TEXTO2[]={"   PIC16F887\n"};

unsigned char DB;
#line 27 "C:/Users/Manuel/Desktop/CUCEI/Seminario de programación de sistemas embebidos/Laboratorios/12 LCD/Código/12 LCD.c"
 void Configuracion();
 void Enable();
 void Cadena1();
 void Cadena2();

 void main()
{
 ANSEL=0;
 PORTE&=(0<< 0 |0<< 1 |0<< 2 );
 PORTD=0x30;
 TRISE&=(0<< 0 |0<< 1 |0<< 2 );
 TRISD=0;

 delay_ms(50);

 DB=0x03C;
 Enable();
 DB=0x00F;
 Enable();
 DB=0x01;
 Enable();
 DB=0x006;
 Enable();
 Cadena1();
 DB=0x0C0;
 Enable();
 Cadena2();


 while (8);
}

 void Enable()
 {
 PORTD=DB;
 PORTE|=(1<< 2 );
 delay_ms(2);
 PORTE&=~((1<< 2 ));
 }

 void Cadena1()
 {
 unsigned char i=0;

 PORTE|=(1<< 0 );

 while ((TEXTO1[i]!='\n'))
 {
 DB=TEXTO1[i];
 Enable();
 i++;
 delay_ms(10);
 }

 PORTE&=~((1<< 0 ));
 }

 void CADENA2(void)
 {
 unsigned char i=0;

 PORTE|=(1<< 0 );

 while ((TEXTO2[i]!='\n'))
 {
 DB=TEXTO2[i];
 Enable();
 i++;
 delay_ms(100);
 }

 PORTE&=((1<< 0 ));
 }
