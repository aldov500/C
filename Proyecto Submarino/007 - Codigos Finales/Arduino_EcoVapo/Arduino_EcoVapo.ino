// :: Programa principal de Submarino Eco Vapo
// :: Funciones:
// ::     Por medio de un evento serial, se detecta una cadena JSON con valores empaquetados
// ::     los cuales corresponden a los disntintos actuadores del sistema.
// ::     Dependiendo de los valores, se validan los mismos y se ejecutan funciones.

// ::::: Directivas :::::

#define SERIAL_BAUD   115200
#define STRING_LENGTH 200
#define BRUSH_STARTV  1000
#define SERVO_IZQ     6
#define SERVO_CEN     7
#define SERVO_DER     8
#define BRUSHLESS     5
#define LED_01        13
#define LED_02        12
#define LED_03        11

// ::::: Bibliotecas :::::

#include "Servo.h"
#include "ArduinoJson.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

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
bool bSerialCompletado;
bool bPID;

// ::::: Variables Globales MPU6050 :::::

MPU6050 Accel_Gyro;

int Aceleracion_X,    Aceleracion_Y,    Aceleracion_Z;
int Aceleracion_XMin, Aceleracion_YMin, Aceleracion_ZMin;
int Aceleracion_XMax, Aceleracion_YMax, Aceleracion_ZMax;

int Rotacion_X, Rotacion_Y, Rotacion_Z;
int rotMinX,    rotMinY,    rotMinZ;
int rotMaxX,    rotMaxY,    rotMaxZ;

float Angulo_X, Angulo_Y;

int mapAceleracion_X, mapAceleracion_Y, mapAceleracion_Z;
int mapRotacion_X,    mapRotacion_Y,    mapRotacion_Z;
int mapXmin, mapXmax;
int mapYmin, mapYmax;
int mapZmin, mapZmax;

long Referencia_X = 0;
long Referencia_Y = 0;
long Referencia_Z = 0;

long Error = 0;
long Error_Anterior = 0;

float pid_P = 0;
float pid_I = 0;
float pid_D = 0;

double kP = 2.5;
double kI = 0.005;
double kD = 3.2;

float Tiempo_Actual;
float Tiempo_Transcurrido;
float Tiempo_Anterior;

float PID;

int numeroMuestras = 1000;

// ::::: Funciones Globales Prototipos :::::

void EventoSerial();
void JsonParser();
void ControlPID();
void MoverMotores(int izq, int der, int centro);
void ObtenerReferenciaCero();

// ::::: VOID SETUP :::::

void setup() {
  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);

  Serial.begin(SERIAL_BAUD);

  jsonRecibido.reserve(STRING_LENGTH);
  jsonRecibido = "";

  jsonCompletado = false;
  bSerialCompletado = true;

  ServoIzq.attach(SERVO_IZQ);
  ServoDer.attach(SERVO_DER);
  ServoCen.attach(SERVO_CEN);

  Brush.attach(BRUSHLESS);
  Brush.writeMicroseconds(BRUSH_STARTV);

  // ::::: MPU6050 :::::

  Accel_Gyro.initialize();
  Tiempo_Actual = millis();
  Wire.begin();

  if (Accel_Gyro.testConnection()) {
    Serial.println("Sensor iniciado correctamente");

    ObtenerReferenciaCero();
  }
  else {

    Serial.println("Error al iniciar el sensor");
  }

  MoverMotores(90, 90, 90);
  delay(5000);


}

// ::::: VOID LOOP :::::

void loop() {

  EventoSerial();

  if (bPID == true) {
    ControlPID();
  } else {

  }

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

  int iBrush_Value;

  String sBrush_Value;

  StaticJsonBuffer<200> jsonBuffer;

  short lengthJSON = jsonRecibido.length();

  char inputJSON[lengthJSON] = {0};

  jsonRecibido.toCharArray(inputJSON, lengthJSON);

  JsonObject& root = jsonBuffer.parseObject(inputJSON);

  if (root.success()) {

    String J_LED_01     = root["LED_01"];
    String J_LED_02     = root["LED_02"];
    String J_LED_03     = root["LED_03"];
    String J_Serv1      = root["SERVO_01"];
    String J_Serv2      = root["SERVO_02"];
    String J_Serv3      = root["SERVO_03"];
    String J_Brush      = root["BRUSH"];
    String J_BrushValue = root["BRUSH_VALUE"];
    String J_PID        = root["PID"];


    if (J_PID == "ENCENDIDO") {
      bPID = true;
    } else {
      bPID = false;
    }

    if (bPID == true) {
      ControlPID();

    } else {
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
        sBrush_Value = J_BrushValue;

        iBrush_Value = sBrush_Value.toInt();

        iBrush_Value = map(iBrush_Value, 0, 100, 1000, 1700);

        Brush.writeMicroseconds(iBrush_Value);


      } else if (J_Brush == "STOP") {
        Brush.writeMicroseconds(1000);
      }
    }

  } else {
    Serial.println("parseObject() failed");
  }

  jsonCompletado = true;
  bSerialCompletado = true;
}

void ControlPID() {
  Tiempo_Anterior = Tiempo_Actual;
  Tiempo_Actual = millis();
  Tiempo_Transcurrido = (Tiempo_Actual - Tiempo_Anterior);


  /* :::  Lectura de Datos del MPU :::*/
  Accel_Gyro.getAcceleration(&Aceleracion_X, &Aceleracion_Y, &Aceleracion_Z);
  Accel_Gyro.getRotation(&Rotacion_X, &Rotacion_Y, &Rotacion_Z);

  /* ::: Calculo de Rotación Angular  :::*/
  Angulo_X = atan(Aceleracion_X / sqrt(pow(Aceleracion_Y, 2) + pow(Aceleracion_Z, 2))) * (180.0 / 3.14);
  Angulo_Y = atan(Aceleracion_Y / sqrt(pow(Aceleracion_X, 2) + pow(Aceleracion_Z, 2))) * (180.0 / 3.14);

  /* :::  Calculo de Valores Maximos y Minimos de Lectura :::*/
  if (Aceleracion_X < Aceleracion_XMin) Aceleracion_XMin = Aceleracion_X;
  if (Aceleracion_X > Aceleracion_XMax) Aceleracion_XMax = Aceleracion_X;

  if (Aceleracion_Y < Aceleracion_YMin) Aceleracion_YMin = Aceleracion_Y;
  if (Aceleracion_Y > Aceleracion_YMax) Aceleracion_YMax = Aceleracion_Y;

  if (Aceleracion_Z < Aceleracion_ZMin) Aceleracion_ZMin = Aceleracion_Z;
  if (Aceleracion_Z > Aceleracion_ZMax) Aceleracion_ZMax = Aceleracion_Z;

  /* :::  Mapeo de Valores :::*/
  mapXmax = map(Aceleracion_X, Referencia_X, Aceleracion_XMax, 0, 180);
  mapYmax = map(Aceleracion_Y, Referencia_Y, Aceleracion_YMax, 0, 180);
  mapZmax = map(Aceleracion_Z, Referencia_Z, Aceleracion_ZMin, 0, -180);


  /* ::: Calculo del Error ::: */
  Error = mapXmax - 0;


  /* ::: Calculo del proporcional del PID ::: */
  pid_P = kP * Error;

  /* ::: Calculo del Integral del PID ::: */

  if (-15 < Error < 15) {
    pid_I = pid_I + (kI * Error);
  }

  /* ::: Calculo del Derivativo del PID ::: */
  pid_D = kD * ((Error - Error_Anterior) / Tiempo_Transcurrido);


  PID = pid_I + pid_P + pid_D;

  if (PID > 180) {
    PID = 180;
  } else if (PID < -180) {
    PID = -180;
  }

  int ExeMotorIzq;
  int ExeMotorDer;
  int ExeMotorCen;

  if (PID > 0) {
    Serial.println("Derecha");
    ExeMotorIzq = map(PID, 1, 180, 90, 180);
    ExeMotorDer = map(PID, 1, 180, 90, 0);
    ExeMotorCen = map(PID, 1, 180, 90, 180);

  } else {
    Serial.println("Izquierda");
    ExeMotorIzq = map(PID, 0, -180, 90, 180);
    ExeMotorDer = map(PID, 0, -180, 0, 90);
    ExeMotorCen = map(PID, 0, -180, 90, 180);
  }

  MoverMotores(ExeMotorIzq, ExeMotorDer, ExeMotorCen);

  Error_Anterior = Error;

  /* :::  Impresión de Datos :::*/
  //  Serial.print("X: "); Serial.println(mapXmax);
  //  Serial.print("Y: "); Serial.println(mapYmax);
  //  Serial.print("Z: "); Serial.println(mapZmax);

  Serial.print(PID);
  delay(50);
}

void MoverMotores(int izq, int der, int centro) {
  ServoIzq.write(izq);
  ServoDer.write(der);
  ServoCen.write(centro);
}

void ObtenerReferenciaCero() {
  int muestrasX[numeroMuestras] = {0};
  int muestrasY[numeroMuestras] = {0};
  int muestrasZ[numeroMuestras] = {0};

  for (int i = 0; i < numeroMuestras; i++) {
    Accel_Gyro.getAcceleration(&Aceleracion_X, &Aceleracion_Y, &Aceleracion_Z);
    muestrasX[i] = Aceleracion_X;
    muestrasY[i] = Aceleracion_Y;
    muestrasZ[i] = Aceleracion_Z;
  }

  for (int i = 0; i < numeroMuestras; i++) {
    Referencia_X += muestrasX[i];
    Referencia_Y += muestrasY[i];
    Referencia_Z += muestrasZ[i];
  }

  Referencia_X = Referencia_X / numeroMuestras;
  Referencia_Y = Referencia_Y / numeroMuestras;
  Referencia_Z = Referencia_Z / numeroMuestras;
}



