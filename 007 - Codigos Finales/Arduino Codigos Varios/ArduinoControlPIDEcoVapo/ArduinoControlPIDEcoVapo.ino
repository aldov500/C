#define SERVO_IZQ 10
#define SERVO_CEN 9
#define SERVO_DER 8

#include "Wire.h"
#include "Servo.h"
#include "I2Cdev.h"
#include "MPU6050.h"

Servo Servo_AletaIzq;
Servo Servo_AletaDer;
Servo Servo_Brushless;

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

void MoverMotores(int izq, int der, int centro);

void ObtenerReferenciaCero();

void setup() {
  Accel_Gyro.initialize();
  Tiempo_Actual = millis();
  Serial.begin(115200);
  Wire.begin();

  Servo_AletaIzq.attach(SERVO_IZQ);
  Servo_AletaDer.attach(SERVO_DER);
  Servo_Brushless.attach(SERVO_CEN);

  if (Accel_Gyro.testConnection()) {
    Serial.println("Sensor iniciado correctamente");

    ObtenerReferenciaCero();
  }
  else {

    Serial.println("Error al iniciar el sensor");
  }

  MoverMotores(90, 90, 90);
  delay(8000);

}


void loop() {

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
  Servo_AletaIzq.write(izq);
  Servo_AletaDer.write(der);
  Servo_Brushless.write(centro);

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

