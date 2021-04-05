// :: Programa principal de Submarino Eco Vapo
// :: Funciones:
// ::     Por medio de un evento serial, se detecta una cadena JSON con valores empaquetados
// ::     los cuales corresponden a los disntintos actuadores del sistema.
// ::     Dependiendo de los valores, se validan los mismos y se ejecutan funciones.
// ::     
// ::     Al código le hace falta agregarle la funcionalidad para que el valor de cada servo y el motor se mantengan
// ::     y asi con cada cambio que haya en el mismo, no habrá un golpe brusco de velocidad, sino que se controlará de manera suave.

// ::::: Directivas :::::

#define SERIAL_BAUD   115200
#define STRING_LENGTH 200
#define BRUSH_STARTV  1000
#define SERVO_IZQ     4
#define SERVO_CEN     5
#define SERVO_DER     6
#define BRUSHLESS     2
#define LED_01        13
#define LED_02        12
#define LED_03        11

// ::::: Bibliotecas :::::

#include "Servo.h"
#include "ArduinoJson.h"


// ::::: Variables Globales :::::

Servo ServoIzq;
Servo ServoDer;
Servo ServoCen;
Servo Brush;

short int ServoIzq_Valor;
short int ServoDer_Valor;
short int ServoCen_Valor;
short int Brushless_Valor;

String jsonRecibido;

bool jsonCompletado;

// ::::: Funciones Globales Prototipos :::::

void EventoSerial();
void JsonParser();

// ::::: VOID SETUP :::::

void setup() {
  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);

  Serial.begin(SERIAL_BAUD);

  jsonRecibido.reserve(STRING_LENGTH);
  jsonRecibido = "";

  jsonCompletado = false;

  ServoIzq.attach(SERVO_IZQ);
  ServoDer.attach(SERVO_DER);
  ServoCen.attach(SERVO_CEN);

  Brush.attach(BRUSHLESS);
  Brush.writeMicroseconds(BRUSH_STARTV);


}


// ::::: VOID LOOP :::::

void loop() {

  EventoSerial();

  if (jsonCompletado) {
    Serial.println(jsonRecibido);
    jsonRecibido = "";
    jsonCompletado = false;
  }
}


// ::::: Funciones Globales Definicion :::::

void EventoSerial() {

  while (Serial.available()) {

    char inChar = (char)Serial.read();

    jsonRecibido += inChar;

    if (inChar == '\n') {
      JsonParser();
    }
  }
}


void JsonParser() {
  StaticJsonBuffer<200> jsonBuffer;

  short lengthJSON = jsonRecibido.length();

  char inputJSON[lengthJSON] = {0};

  jsonRecibido.toCharArray(inputJSON, lengthJSON);

  JsonObject& root = jsonBuffer.parseObject(inputJSON);

  if (root.success()) {
    
    String J_LED_01 = root["LED_01"];
    String J_LED_02 = root["LED_02"];
    String J_LED_03 = root["LED_03"];
    String J_Serv1 = root["SERVO_01"];
    String J_Serv2 = root["SERVO_02"];
    String J_Serv3 = root["SERVO_03"];
    String J_Brush = root["BRUSH"];

    // LEDS
    if (J_LED_01 == "HIGH") {
      digitalWrite(LED_01, HIGH);
    } else if (J_LED_01 == "DOWN") {
      digitalWrite(LED_01, LOW);
    }

    if (J_LED_02 == "HIGH") {
      digitalWrite(LED_02, HIGH);
    } else if (J_LED_02 == "DOWN") {
      digitalWrite(LED_02, LOW);
    }

    if (J_LED_03 == "HIGH") {
      digitalWrite(LED_03, HIGH);
    } else if (J_LED_03 == "DOWN") {
      digitalWrite(LED_03, LOW);
    }


    // ::: Servomotores
    if (J_Serv1 == "180") {
      ServoIzq.write(180);
    } else if (J_Serv1 == "100") {
      ServoIzq.write(100);
    } else if (J_Serv1 == "90") {
      ServoIzq.write(90);
    } else if (J_Serv1 == "0") {
      ServoIzq.write(0);
    }

    if (J_Serv2 == "180") {
      ServoDer.write(180);
    } else if (J_Serv2 == "100") {
      ServoDer.write(100);
    } else if (J_Serv2 == "90") {
      ServoDer.write(90);
    } else if (J_Serv2 == "0") {
      ServoDer.write(0);
    }

    if (J_Serv3 == "180") {
      ServoCen.write(180);
    } else if (J_Serv3 == "90") {
      ServoCen.write(90);
    } else if (J_Serv3 == "0") {
      ServoCen.write(0);
    }

    if (J_Brush == "START") {
      Brush.writeMicroseconds(1700);
    } else if (J_Brush == "STOP") {
      Brush.writeMicroseconds(1000);
    }

  } else {

    Serial.println("parseObject() failed");
    return;
  }

  jsonCompletado = true;
}

