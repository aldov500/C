#line 1 "C:/Users/Manuel/Desktop/CUCEI/Programaci�n de sistemas embebidos/Laboratorios/03 LED Parpadeante/C�digo/LED Parpadeante.c"
void main() {

TRISC.RC0= 0;

 while (8)
 {
 PORTC.RC0^=1;
 delay_ms(250);
 }
}
