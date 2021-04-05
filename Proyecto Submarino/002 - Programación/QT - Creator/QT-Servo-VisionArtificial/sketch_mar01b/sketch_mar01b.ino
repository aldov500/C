/*
 * 
 * hetpro-store.com/TUTORIALES/
 * Autor: Dr. Rubén Estrada Marmolejo
 * Fecha revisión: 29 de Enero de 2018
 * 
 */

#include <Servo.h>

Servo motor1;
Servo motor2;
 
String cadenaCharEntrada = "";  
char vectorChar[20];
bool finCadena = false;
char comando = 0;
void setup() {
  motor1.attach(9);
  motor2.attach(8);
  Serial.begin(115200);
  cadenaCharEntrada.reserve(20);
  pinMode(13,OUTPUT);

}

void loop() { 
  if(finCadena){                               //Se termino de recibir una cadena completa
    finCadena = false;                                  //Permitimos volver a recibir otra cadena
    cadenaCharEntrada.toCharArray(vectorChar,20);   //Convertimos el string a un vectorChar
    int numeroEntero = atoi(vectorChar);            //Convertimos un vectorChar a un entero
    
    //Serial.print("Se recibio ");
    //Serial.println(numeroEntero);
   
    if(comando == '@'){  //Deteccion del servo1
      if((numeroEntero >= 0) && (numeroEntero<=180)){
              motor1.write(numeroEntero);
      }
    }
    else if(comando == '$'){ //Deteccion del servo2
        if((numeroEntero >= 0) && (numeroEntero<=180)){
              motor2.write(numeroEntero);
      }    
    }
    else{
      //Error
    }
    cadenaCharEntrada = "";
    
    
  }
}

void serialEvent(){
  //Recepción de datos Seriales
  
  while (Serial.available()) {              //Si existen datos seriales, leer a todos
    char CaracterEntrada = Serial.read();   //Leer 1 byte serial recibido
    if(CaracterEntrada == '@' || CaracterEntrada == '$'){
      comando = CaracterEntrada;
    }
    else{
      cadenaCharEntrada += CaracterEntrada;   //Agregar el nuevo char a una cadena String 
    }
    if (CaracterEntrada == '\n') {          //Si el char o byte recibido es un fin de linea, activa la bandera
      finCadena = true;                        //Si la bandera finCadena = 1, entonces la transmision esta completa
    }
    
  }
  
}
