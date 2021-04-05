int ldr;
int pir; 
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);   //LDR
  pinMode(22, OUTPUT);  //FOCO
  pinMode(23, INPUT);   //PIRO
}

void loop() {
ldr= analogRead(A0);
pir= digitalRead(23);
Serial.print("LDR ");
Serial.println(ldr);
Serial.print("PIRO ");
Serial.println(pir);


if(ldr<50&&pir>0){
    digitalWrite(22,HIGH);
}
else{
digitalWrite(22,LOW);
}

delay(100);
}
