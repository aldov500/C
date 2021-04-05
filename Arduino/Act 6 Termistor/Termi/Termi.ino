float dato1, dato2, sig, termistor;
int temp1, temp2;

void setup (){
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
}

void loop(){
 dato1=analogRead (A0);
 dato2=analogRead (A1);
 temp1=(dato1*500)/1023;
 sig= dato2*0.005;
 termistor= (sig-1.6)*20;
 temp2=25+termistor;
 Serial.print("Lm35:...........");
 Serial.print(temp1);
 Serial.println("C");
 Serial.print("Termistor:.........");
 Serial.print(temp2);
 Serial.println("C");
 delay (1000);
 
}
