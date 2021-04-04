volatile unsigned char TEXTO1[]={" C con el MICRO \n"};
volatile unsigned char TEXTO2[]={"   PIC16F887\n"};

unsigned char DB;
#define DB0 0
#define DB1 1
#define DB2 2
#define DB3 3
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7
#define ID  1
#define SH  0
#define BLK 0
#define CUR 0
#define DSP 2
#define F   2
#define NL  3
#define Busy 7
#define RS  0
#define RW  1
#define E   2
#define SC  3
#define RL  2

 void Configuracion();
 void Enable();
 void Cadena1();
 void Cadena2();

 void main()
{
      ANSEL=0;
      PORTE&=(0<<RS|0<<RW|0<<E);
      PORTD=0x30;
      TRISE&=(0<<RS|0<<RW|0<<E);
      TRISD=0;
      
      delay_ms(50);
      
      DB=0x03C;  //00 0011 1100 Configuración
      Enable();
      DB=0x00F; //00000001111 Activar Display
      Enable();
      DB=0x01; //Clear Display
      Enable();
      DB=0x006; //Mover el cursor
      Enable();
      Cadena1();
      DB=0x0C0; //Set DDRAM
      Enable();
      Cadena2();


 while (8);
}

 void Enable()
 {
  PORTD=DB;
  PORTE|=(1<<E);
  delay_ms(2);
  PORTE&=~((1<<E));
 }

 void Cadena1()
 {
  unsigned char i=0;

          PORTE|=(1<<RS);

          while ((TEXTO1[i]!='\n'))
          {
           DB=TEXTO1[i];
           Enable();
           i++;
           delay_ms(10);
          }

          PORTE&=~((1<<RS));
 }

 void CADENA2(void)
 {
  unsigned char i=0;

           PORTE|=(1<<RS);

           while ((TEXTO2[i]!='\n'))
           {
            DB=TEXTO2[i];
            Enable();
            i++;
            delay_ms(100);
           }

           PORTE&=((1<<RS));
  }