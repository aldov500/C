float presionMmhg, presionKpa, presionPsi;

void setup1(){
  Serial.begin(9600);
}


void loop(){
  int sensorValue= analogRead(A0);
  float voltage= sensorValue * (5.0 /1023.0);

  presionMmhg= (voltage - 0.18)*850;
  presionKpa= presionMmhg/ 7.50064;
  presionPsi= presionKpa* 0.14504;

  if (presionMmhg > 0){
    Serial.print("Presion mm/Hg: ");
    Serial.println(presionMmhg);

    Serial.print("Presion Kpa: ");
    Serial.println(presionKpa);

    Serial.print("Presion PSI: ");
    Serial.println(presionPsi);
    Serial.print("\n");
    delay(1000);
    
  }
}

