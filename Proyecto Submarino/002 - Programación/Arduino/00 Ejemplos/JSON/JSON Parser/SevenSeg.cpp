
#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 6
#define PIN_F 7
#define PIN_G 8

#include "SevenSeg.h"


void SevenSeg_Init(SevenSeg* newDisplay) {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  
  newDisplay->a = false;
  newDisplay->b = false;
  newDisplay->c = false;
  newDisplay->d = false;
  newDisplay->e = false;
  newDisplay->f = false;
  newDisplay->g = false;
}

void SevenSeg_Segments(SevenSeg* newDisplay, bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  newDisplay->a = a;
  newDisplay->b = b;
  newDisplay->c = c;
  newDisplay->d = d;
  newDisplay->e = e;
  newDisplay->f = f;
  newDisplay->g = g;
}

void SevenSeg_SetNumber(SevenSeg *newDisplay, int num) {
  switch (num) {
    case 0:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 1, 1, 1, 0);
      break;
    case 1:
      SevenSeg_Segments(newDisplay, 0, 1, 1, 0, 0, 0, 0);
      break;
    case 2:
      SevenSeg_Segments(newDisplay, 1, 1, 0, 1, 1, 0, 1);
      break;
    case 3:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 1, 0, 0, 1);
      break;
    case 4:
      SevenSeg_Segments(newDisplay, 0, 1, 1, 0, 0, 1, 1);
      break;
    case 5:
      SevenSeg_Segments(newDisplay, 1, 0, 1, 1, 0, 1, 1);
      break;
    case 6:
      SevenSeg_Segments(newDisplay, 1, 0, 1, 1, 1, 1, 1);
      break;
    case 7:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 0, 0, 0, 0);
      break;
    case 8:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 1, 1, 1, 1);
      break;
    case 9:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 1, 0, 1, 1);
      break;
    case 10:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 0, 1, 1, 1);
      break;
    case 11:
      SevenSeg_Segments(newDisplay, 0, 0, 1, 1, 1, 1, 1);
      break;
    case 12:
      SevenSeg_Segments(newDisplay, 1, 0, 0, 1, 1, 1, 0);
      break;
    case 13:
      SevenSeg_Segments(newDisplay, 1, 1, 1, 1, 1, 1, 0);
      break;
    case 14:
      SevenSeg_Segments(newDisplay, 1, 0, 0, 1, 1, 1, 1);
      break;
    case 15:
      SevenSeg_Segments(newDisplay, 1, 0, 0, 0, 1, 1, 1);
      break;

    default:
      num = 0;
  }

}

void SevenSeg_Display(SevenSeg newDisplay) {
  if(newDisplay.a)  digitalWrite(PIN_A, HIGH);
  else  digitalWrite(PIN_A, LOW);
 
  if (newDisplay.b) digitalWrite(PIN_B, HIGH);
  else  digitalWrite(PIN_B, LOW);

  
  if (newDisplay.c){
    digitalWrite(PIN_C, HIGH);
  }
  else{
    digitalWrite(PIN_C, LOW);
  }
  
  if (newDisplay.d){
    digitalWrite(PIN_D, HIGH);
  }
  else{
    digitalWrite(PIN_D, LOW);
  }

  
  if (newDisplay.e){
    digitalWrite(PIN_E, HIGH);
  }
  else{
    digitalWrite(PIN_E, LOW);
  }

  
  if (newDisplay.f){
    digitalWrite(PIN_F, HIGH);
  }
  else{
    digitalWrite(PIN_F, LOW);
  }

  
  if (newDisplay.g){
    digitalWrite(PIN_G, HIGH);
  }
  else{
    digitalWrite(PIN_G, LOW);
  }
  
}

void SevenSeg_Clean(SevenSeg* newDisplay) {
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, LOW);

  newDisplay->a = false;
  newDisplay->b = false;
  newDisplay->c = false;
  newDisplay->d = false;
  newDisplay->e = false;
  newDisplay->f = false;
  newDisplay->g = false;
  
}



