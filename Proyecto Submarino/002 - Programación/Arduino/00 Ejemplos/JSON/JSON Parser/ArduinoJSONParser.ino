
/* Librerías */
#include <ArduinoJson.h>
#include "SevenSeg.h"
#include <Stepper.h>

/* Constantes */
static const int sciMotorSpeed  = 15;
static const int sciMotorSteps  = 2048;
static const int iLedArduino    = 13;
static const int sciJsonLength  = 100;


/* Recepción JSON */
double dCoordX = 0.0;
double dCoordY = 0.0;
int iHead   = 0;
int iStack  = 0;
bool bStringEnded = false;
String sJson = "";

/* Motores */
Stepper stprMotorX(sciMotorSteps, 50, 52, 53, 51);
Stepper stprMotorY(sciMotorSteps, 46, 48, 49, 47);

/* Display 7 segmentos */
SevenSeg Display;

/*  Void Setup
    Led de Arduino como salida
    Configuración Serial
    Reserva de memoria para JSON
    Inicialización de Display de 7 segmentos
*/
void setup() {
  pinMode(iLedArduino, OUTPUT);
  Serial.begin(115200);
  sJson.reserve(sciJsonLength);
  SevenSeg_Init(&Display);
  stprMotorX.setSpeed(sciMotorSpeed);
  stprMotorY.setSpeed(sciMotorSpeed);

}

/* Void loop
   Lee JSON
   Limpia la variable
   Cambia bandera
*/
void loop() {

  if (bStringEnded == true) {
    VreadJson();
    sJson = "";
    bStringEnded = false;
  }
}

/* Void serialEvent
   Lee serial
   Concatena la variable
   Monitorea el final del JSON
*/
void serialEvent() {
  char cInput;

  while (Serial.available()) {
    cInput = Serial.read();
    sJson += cInput;
    if (cInput == '}') {
      bStringEnded = true;
    }
  }
}

void VreadJson() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& jsonParsed = jsonBuffer.parseObject(sJson);

  if (jsonParsed.success()) {

    String sSerialPreText = "{\"Status\":\"";
    String sSerialPosText = "\"}";
    String sSerialInsText = "";

    dCoordX = jsonParsed["X"];
    dCoordY = jsonParsed["Y"];
    iHead   = jsonParsed["Head"];
    iStack  = jsonParsed["Stack"];

    /* Cabezales */
    if (iHead == 1 ) {
      sSerialInsText += " CABEZAL 1 ";
    }
    else {
      sSerialInsText += " CABEZAL 0 ";
    }

    /* Carretes */
    SevenSeg_SetNumber(&Display, iStack);
    SevenSeg_Display(Display);
    sSerialInsText += " CARRETE " + String(iStack);

    /* Motores */
    int iMapedCoordX, iMapedCoordY;
    iMapedCoordX = map(dCoordX, 0, 22, 0, sciMotorSteps);
    iMapedCoordY = map(dCoordY, 0, 25, 0, sciMotorSteps);

    stprMotorX.step(iMapedCoordX);
    stprMotorY.step(iMapedCoordY);

    stprMotorX.step(-iMapedCoordX);
    stprMotorY.step(-iMapedCoordY);

    sSerialInsText += " MotorX: " + String(iMapedCoordX);
    sSerialInsText += " MotorY: " + String(iMapedCoordY);

    /* Respuesta Json */
    Serial.println(sSerialPreText + sSerialInsText + sSerialPosText);

  } else {
    Serial.println("Fallo el parsing");
    return;
  }

}


