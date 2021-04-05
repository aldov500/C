String cadenaCharEntrada = "";  
char vectorChar[20];
bool finCadena = false;
volatile int tiempo = 1000;
void setup() {
  Serial.begin(115200);
  

}

void loop() {

  Serial.print("@");
  Serial.println(analogRead(A0));
  delay(tiempo);
}


void serialEvent(){
  //Recepción de datos Seriales
  
  while (Serial.available()) {              //Si existen datos seriales, leer a todos
    char CaracterEntrada = Serial.read();   //Leer 1 byte serial recibido
   
    cadenaCharEntrada += CaracterEntrada;   //Agregar el nuevo char a una cadena String 
    if (CaracterEntrada == '\n') {          //Si el char o byte recibido es un fin de linea, activa la bandera
      cadenaCharEntrada.toCharArray(vectorChar,20);   //Convertimos el string a un vectorChar
    tiempo = atoi(vectorChar);            //Convertimos un vectorChar a un entero
    
    //Serial.print("Se recibio ");
    //Serial.println(numeroEntero);
    cadenaCharEntrada = "";
    }
    
  }
  
}

