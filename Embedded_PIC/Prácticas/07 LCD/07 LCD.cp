#line 1 "D:/07 LCD@PIC/07 LCD.c"
volatile unsigned char TEXTO1[]={"Juan Manuel Lara"};
volatile unsigned char TEXTO2[]={"Esparza 210459974"};
const char character1[] = {0,14,31,30,28,31,14,0};
const char character2[] = {0,14,31,31,31,31,14,0};
const char character3[] = {0,14,31,21,31,31,21,0};
unsigned char i, x;

sbit LCD_RS at RC3_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_RW at RD0_bit;

sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RC4_bit;
sbit LCD_D7 at RC5_bit;

sbit LCD_RS_Direction at TRISC3_bit;
sbit LCD_RW_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;

sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISC4_bit;
sbit LCD_D7_Direction at TRISC5_bit;

void PacMan1(char pos_row, char pos_char);
void PacMan2(char pos_row, char pos_char);
void Phantom(char pos_row, char pos_char);

void main()
{
 TRISA=0x03;
 TRISD=0x00;
 TRISC=0x00;
 ANSEL=0x00;

 PORTC=0;
 PORTD=0;
 PORTA=0 ;

 Lcd_init();
 Lcd_Cmd(_LCD_CURSOR_OFF);

 while(8)
 {
 Lcd_Out(1, 1, "  Practica 07");
 Lcd_Out(2, 1, "C para Embebidos");


 if (PORTA.RA0)
 {
 Lcd_cmd(_LCD_CLEAR);
 delay_ms(250);
 Lcd_Out(1, 1, TEXTO1);
 Delay_ms(250);
 Lcd_Out(2, 1, TEXTO2);
 delay_ms(1000);

 for(i=0; i<17; i++)
 {
 Lcd_Cmd(_LCD_SHIFT_LEFT);
 delay_ms(150);
 }
 delay_ms(500);
 Lcd_cmd(_LCD_CLEAR);
 }

 if (PORTA.RA1)
 {
 Lcd_cmd(_LCD_CLEAR);
 Lcd_Out(1, 5, "-PACMAN-");
 delay_ms(1000);

 for (i=0; i!=17; i++)
 {
 Lcd_cmd(_LCD_CLEAR);
 Phantom(2,i);
 Lcd_Cmd(_LCD_SHIFT_RIGHT);
 delay_ms(200);

 PacMan1(2,i);
 delay_ms(200);
 PacMan2(2,i);
 delay_ms(100);
 Lcd_Cmd(_LCD_SHIFT_RIGHT);

 delay_ms(50);
 }

 Lcd_Cmd(_LCD_SHIFT_LEFT);
 }
 }
}

void PacMan1(char pos_row, char pos_char)
{
 char i;
 Lcd_Cmd(64);
 for (i = 0; i<=7; i++) Lcd_Chr_CP(character1[i]);
 Lcd_Cmd(_LCD_RETURN_HOME);
 Lcd_Chr(pos_row, pos_char, 0);
}

void PacMan2(char pos_row, char pos_char)
{
 char i;
 Lcd_Cmd(64);
 for (i = 0; i<=7; i++) Lcd_Chr_CP(character2[i]);
 Lcd_Cmd(_LCD_RETURN_HOME);
 Lcd_Chr(pos_row, pos_char, 0);
}

void Phantom(char pos_row, char pos_char)
{
 char i;
 Lcd_Cmd(64);
 for (i = 0; i<=7; i++) Lcd_Chr_CP(character3[i]);
 Lcd_Cmd(_LCD_RETURN_HOME);
 Lcd_Chr(pos_row, pos_char, 0);
}
