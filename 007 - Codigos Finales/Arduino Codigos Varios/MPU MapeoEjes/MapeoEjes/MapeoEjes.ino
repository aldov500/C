#include <I2Cdev.h>
#include "MPU6050.h"
#include "Wire.h"

MPU6050 Accel_Gyro;

int Aceleracion_X, Aceleracion_Y, Aceleracion_Z;
int Rotacion_X, Rotacion_Y, Rotacion_Z;

float Angulo_X, Angulo_Y;

int Aceleracion_XMin, Aceleracion_YMin, Aceleracion_ZMin;
int rotMinX, rotMinY, rotMinZ;

int Aceleracion_XMax, Aceleracion_YMax, Aceleracion_ZMax;
int rotMaxX, rotMaxY, rotMaxZ;

int mapAceleracion_X, mapAceleracion_Y, mapAceleracion_Z;
int mapRotacion_X, mapRotacion_Y, mapRotacion_Z;

int mapXmin, mapXmax;
int mapYmin, mapYmax;
int mapZmin, mapZmax;

long Referencia_X = 0;
long Referencia_Y = 0;
long Referencia_Z = 0;

int numeroMuestras = 1000;

void ObtenerReferenciaCero();

void setup() {

  Serial.begin(115200);
  Wire.begin();
  Accel_Gyro.initialize();

  if (Accel_Gyro.testConnection()) {
    Serial.println("Sensor iniciado correctamente");

    ObtenerReferenciaCero();
  }
  else {

    Serial.println("Error al iniciar el sensor");
  }

}


void loop() {

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

  /* :::  Impresión de Datos :::*/
  Serial.print("X: "); Serial.println(mapXmax);
//  Serial.print("Y: "); Serial.println(mapYmax);
//  Serial.print("Z: "); Serial.println(mapZmax);

  delay(30);
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

