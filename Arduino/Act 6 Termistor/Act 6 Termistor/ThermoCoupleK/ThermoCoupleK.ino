#include <max6675.h>


// ThermoCouple
int thermo_gnd_pin = 45;
int thermo_vcc_pin = 47;
int thermo_so_pin  = 53;
int thermo_cs_pin  = 51;
int thermo_sck_pin = 49;
  
MAX6675 thermocouple(thermo_sck_pin, thermo_cs_pin, thermo_so_pin);
float dato1, temp1;
  
void setup() {
  Serial.begin(9600);
  pinMode(A15, INPUT);

  pinMode(thermo_vcc_pin, OUTPUT); 
  pinMode(thermo_gnd_pin, OUTPUT); 
  digitalWrite(thermo_vcc_pin, HIGH);
  digitalWrite(thermo_gnd_pin, LOW);
}

void loop() {
  dato1=analogRead (A15);
  temp1=(dato1*500)/1023;
  
  Serial.print("Termopar: ");
  Serial.println(thermocouple.readCelsius());
  Serial.print("LM35: ");
  Serial.println(temp1);
  
  delay(500);
}
