#line 1 "C:/Users/Manuel/Desktop/CUCEI/Programación de sistemas embebidos/Laboratorios/03 LED Parpadeante/Código/LED Parpadeante.c"
void main() {

TRISC.RC0= 0;

 while (8)
 {
 PORTC.RC0^=1;
 delay_ms(250);
 }
}
