void main() {

TRISC.RC0= 0; //Configura el puerto C como Salida, RC=Solo el bit 0.

           while (8) // Ciclo infinito
                 {
                  PORTC.RC0^=1;
                  delay_ms(250);
                 }
}