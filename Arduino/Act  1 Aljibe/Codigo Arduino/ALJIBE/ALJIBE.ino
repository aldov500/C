int fondoa=53;
int medioa=52;
int llenoa=51;

int fondoc=50;
int medioc=49;
int llenoc=48;


int led_afo=47;
int led_ame=46;
int led_all=45;

int led_cfo=44;
int led_cme=43;
int led_cll=42;

int bombaa=41;
int bombac=40;



void setup() {
//Aljibe  
pinMode(fondoa,INPUT); //fondo
pinMode(medioa,INPUT); //medio
pinMode(llenoa,INPUT); //lleno
//Cisterna
pinMode(fondoc,INPUT); //fondo
pinMode(medioc,INPUT); //medio
pinMode(llenoc,INPUT); //fondo
//leds
pinMode(led_afo,OUTPUT); //aljibe fondo
pinMode(led_ame,OUTPUT); //aljibe medio
pinMode(led_all,OUTPUT); //aljibe lleno

pinMode(led_cfo,OUTPUT); //cisterna fondo
pinMode(led_cme,OUTPUT); //cisterna medio
pinMode(led_cll,OUTPUT); //cisterna llena
//Bombas
pinMode(bombaa,OUTPUT);
pinMode(bombac,OUTPUT);
}

void loop() {
//Lectura de datos  
fondoa=digitalRead(53);
medioa=digitalRead(52);
llenoa=digitalRead(51);
fondoc=digitalRead(50);
medioc=digitalRead(49);
llenoc=digitalRead(48);
//Impresión del nivel
if(fondoa==HIGH){
  digitalWrite(led_afo,HIGH);
} 
else { digitalWrite(led_afo,LOW);
}
if(medioa==HIGH){
  digitalWrite(led_ame,HIGH);
} 
else { digitalWrite(led_ame,LOW);
}
if(llenoa==HIGH){
  digitalWrite(led_all,HIGH);
} 
else { digitalWrite(led_all,LOW);
}

if(fondoc==HIGH){
  digitalWrite(led_cfo,HIGH);
} 
else { digitalWrite(led_cfo,LOW);
}
if(medioc==HIGH){
  digitalWrite(led_cme,HIGH);
} 
else { digitalWrite(led_cme,LOW);
}
if(llenoc==HIGH){
  digitalWrite(led_cll,HIGH);
} 
else { digitalWrite(led_cll,LOW);
}
delay(20);

//Condicional bomba Aljibe-Cisterna
if(fondoa == HIGH && medioa == HIGH && llenoa == HIGH){
 digitalWrite(bombaa,HIGH);
}
else{
  digitalWrite(bombaa,LOW);
}
if(fondoc == HIGH && medioc == HIGH && llenoc == HIGH){
 digitalWrite(bombaa, LOW);
 delay(200);
 digitalWrite(bombac, HIGH);
}
else{
  digitalWrite(bombac, LOW);
}

if(fondoc == HIGH && medioc == HIGH && llenoc == HIGH && fondoa == HIGH && medioa == HIGH && llenoa == HIGH){
 digitalWrite(bombaa, HIGH);
 delay(200);
 digitalWrite(bombac, HIGH);
 delay(1000);
 digitalWrite(bombac, LOW);
 digitalWrite(bombac, LOW);
 
 
}

}
