#line 1 "C:/Users/Manuel/Desktop/CUCEI/Programaci�n de sistemas embebidos/Laboratorios/#02 Manipulaci�n de puertos como entrada y salida/Archivos/Lab #02.c"
void main()
 {
 TRISC=0x00;
 OPTION_REG=0x7F;
 ANSELH=0x00;
 PORTB=0xFF;

while (8)
 {
 PORTC=PORTB;
 }
 }
