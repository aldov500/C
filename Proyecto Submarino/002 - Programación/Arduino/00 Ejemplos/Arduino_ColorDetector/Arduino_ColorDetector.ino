char dato;

void setup(){
    Serial.begin(115200);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    
}

void loop(){
	if(Serial.available()){
		dato = Serial.read();
                Serial.print(dato);		
		switch(dato){
                
		case '0': digitalWrite(13,HIGH); break;
		case '1': digitalWrite(13,LOW); break;	
		case '2': digitalWrite(12,HIGH); break;
		case '3': digitalWrite(12,LOW); break;
		case '4': digitalWrite(11,HIGH); break;
		case '5': digitalWrite(11,LOW); break;
	
		}
                 
      
        }
}
