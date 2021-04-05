#define SERVO_IZQ 4
#define SERVO_CEN 5
#define SERVO_DER 6

#define BRUSHLESS 2

#include <ArduinoJson.h>
#include <Servo.h>


Servo ServoIzq;
Servo ServoDer;
Servo ServoCen;

Servo Brush;

const short Led01 = 13;
const short Led02 = 12;
const short Led03 = 11;

String inputString = "";
bool stringComplete = false;

void setup() {
  pinMode(Led01, OUTPUT);
  pinMode(Led02, OUTPUT);
  pinMode(Led03, OUTPUT);

  Serial.begin(115200);

  inputString.reserve(200);

  ServoIzq.attach(SERVO_IZQ);
  ServoDer.attach(SERVO_DER);
  ServoCen.attach(SERVO_CEN);

  Brush.attach(BRUSHLESS);
  Brush.writeMicroseconds(1000);

}

void loop() {

  serialEvent();

  if (stringComplete) {
    Serial.println(inputString);
    inputString = "";
    stringComplete = false;
  }

}

void serialEvent() {

  while (Serial.available()) {

    char inChar = (char)Serial.read();

    inputString += inChar;

    if (inChar == '\n') {
      StaticJsonBuffer<200> jsonBuffer;

      short lengthJSON = inputString.length();

      char inputJSON[lengthJSON] = {0};

      inputString.toCharArray(inputJSON, lengthJSON);

      JsonObject& root = jsonBuffer.parseObject(inputJSON);

      if (!root.success()) {
        Serial.println("parseObject() failed");
        return;
      } else {

        //Serial.println("parseObject() success");
        String J_Led01 = root["LED_01"];
        String J_Led02 = root["LED_02"];
        String J_Led03 = root["LED_03"];
        String J_Serv1 = root["SERVO_01"];
        String J_Serv2 = root["SERVO_02"];
        String J_Serv3 = root["SERVO_03"];
        String J_Brush = root["BRUSH"];

        // LEDS
        if (J_Led01 == "HIGH") {
          digitalWrite(Led01, HIGH);
        } else if (J_Led01 == "DOWN") {
          digitalWrite(Led01, LOW);
        }

        if (J_Led02 == "HIGH") {
          digitalWrite(Led02, HIGH);
        } else if (J_Led02 == "DOWN") {
          digitalWrite(Led02, LOW);
        }

        if (J_Led03 == "HIGH") {
          digitalWrite(Led03, HIGH);
        } else if (J_Led03 == "DOWN") {
          digitalWrite(Led03, LOW);
        }


        // ::: Servomotores
        if (J_Serv1 == "180") {
          ServoIzq.write(180);
        } else if(J_Serv1 == "100") {
          ServoIzq.write(100);
        } else if (J_Serv1 == "90") {
          ServoIzq.write(90);
        } else if (J_Serv1 == "0") {
          ServoIzq.write(0);
        }

        if (J_Serv2 == "180") {
          ServoDer.write(180);
        } else if(J_Serv2 == "100"){
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

      }

      stringComplete = true;
    }
  }
}
