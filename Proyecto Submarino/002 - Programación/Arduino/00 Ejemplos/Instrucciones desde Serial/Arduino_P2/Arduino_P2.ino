//Definicion de pines a utilizar 

int contador = 0; //Variable para el control de pulsaciones
String cadenaCharEntrada = "";  
char vectorChar[20];
bool finCadena = false;

void setup() {
  Serial.begin(9600);
  cadenaCharEntrada.reserve(20);
  //Configuracion de entradas y salidas
  pinMode(l_rojo,OUTPUT);
  pinMode(l_azul,OUTPUT);
  pinMode(l_verde,OUTPUT);
  pinMode(l_blanco,OUTPUT);
  pinMode(boton,INPUT_PULLUP);
  //Activando interrupcion de boton
  attachInterrupt(2, boton_interrupt, FALLING);
}

void loop() { 
  if(finCadena){                               //Se termino de recibir una cadena completa
    finCadena = false;                                  //Permitimos volver a recibir otra cadena
    cadenaCharEntrada.toCharArray(vectorChar,20);   //Convertimos el string a un vectorChar
    int numeroEntero = atoi(vectorChar);            //Convertimos un vectorChar a un entero
    
    //Comparamos el valor recibido y aplicamos la instruccion correspondiente
    if(numeroEntero == 1){
      digitalWrite(l_rojo,HIGH);
    }
    else if(numeroEntero == 2){
      digitalWrite(l_rojo,LOW);
    }
    else if(numeroEntero == 3){
      digitalWrite(l_azul,HIGH);
    }
    else if(numeroEntero == 4){
      digitalWrite(l_azul,LOW);
    }
    else if(numeroEntero == 5){
      digitalWrite(l_verde,HIGH);
    }
    else if(numeroEntero == 6){
      digitalWrite(l_verde,LOW);
    }
    else if(numeroEntero == 7){
      digitalWrite(l_blanco,HIGH);
    }
    else if(numeroEntero == 8){
      digitalWrite(l_blanco,LOW);
    }
    else if(numeroEntero == 9){
      int valor_sensor = analogRead(A0);
      // Convierto la lectura analogica (la cual va desde 0 - 1023) hacia un voltaje (0 - 5V):
      float voltaje = valor_sensor * (5.0 / 1023.0);
      Serial.print("@");
      Serial.println(voltaje);

    }
    cadenaCharEntrada = ""; 
  }
}

void serialEvent(){
  //Recepción de datos Seriales
  while (Serial.available()) {              //Si existen datos seriales, leer a todos
    char CaracterEntrada = Serial.read();   //Leer 1 byte serial recibido
    cadenaCharEntrada += CaracterEntrada;   //Agregar el nuevo char a una cadena String 
    if (CaracterEntrada == '\n') {          //Si el char o byte recibido es un fin de linea, activa la bandera
      finCadena = true;                        //Si la bandera finCadena = 1, entonces la transmision esta completa
    }
  }
}

