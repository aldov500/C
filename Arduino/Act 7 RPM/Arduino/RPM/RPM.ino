int ledPin = 11;                // IR LED connected to digital pin 13
volatile byte rpmcount;
unsigned int rpm;
unsigned long timeold;

void rpm_fun()
 {
      rpmcount++;
 }

void setup()
 {
   Serial.begin(9600); 

   //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
   //Triggers on FALLING (change from HIGH to LOW)
   attachInterrupt(0, rpm_fun, FALLING);

   //Turn on IR LED
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, HIGH);

   rpmcount = 0;
   rpm = 0;
   timeold = 0;
 }

 void loop()
 {
  
   //Update RPM every second
   delay(1000);
   //Don't process interrupts during calculations
   detachInterrupt(0);
   //Note that this would be 60*1000/(millis() - timeold)*rpmcount if the interrupt
   //happened once per revolution instead of twice. Other multiples could be used
   //for multi-bladed propellers or fans
   rpm = 8.57*1000/(millis() - timeold)*rpmcount;
   timeold = millis();
   rpmcount = 0;

   //Print out result to lcdm
   
   Serial.print("RPM= ");
   Serial.println(rpm);
 

   //Restart the interrupt processing
   attachInterrupt(0, rpm_fun, FALLING);
  }
