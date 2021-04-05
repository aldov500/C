#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3,2 ); 

void setup()
{

 Serial.begin (9600); //inicia comunicacion serial
 pinMode(7, OUTPUT);
 lcd.begin(12, 11);
}

void loop ()
{
 float piro =analogRead (A0);
 float ldr =analogRead (A1);
 piro=piro*0.004887585533;
 ldr=ldr*0.004887585533;
 
 
 Serial.println ("Piro");
 Serial.println (piro); //escribe la luminosidad en el serial
 Serial.println ();
 Serial.println ("LDR");
 Serial.println (ldr); //escribe la presencia en el serial
 Serial.println ();
 delay (700);

if (ldr>=3.50 && piro>=3.0)
{

  digitalWrite (7, HIGH);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ldr);
  lcd.setCursor(5,0);
  lcd.print("LDR");
  lcd.setCursor(0,1);
  lcd.print("Mov Detected");
  delay (2000);
}
else 
{ 
  digitalWrite (7, LOW); 
      
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ldr);
  lcd.setCursor(5,0);
  lcd.print("LDR");
  lcd.setCursor(0,1);
  lcd.print("Detecting mov");
}
}

