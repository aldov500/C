
#include <ESP8266WiFi.h>

#define MAX_SRV_CLIENTS 1
#define TCP_PORT 23   
        
WiFiServer tcpServer(TCP_PORT);
WiFiClient tcpServerClients[MAX_SRV_CLIENTS];

IPAddress apIP(192, 168, 1, 1);

const char SSID[]     = "ECOVAPO";      // Choose any SSID
const char PASSWORD[] = "ecovapo2018";  // minimum 8 characters

#define SerialDebug     Serial   // Debug goes out on GPIO02
#define SerialEcoVapo   Serial1    // GPS or other device connected to the ESP UART

#ifndef min
#define min(x,y)  ((x)<(y)?(x):(y))
#endif

void setup() {
  // !!! Debug output goes to GPIO02 !!!
  SerialDebug.begin(115200);
  SerialDebug.println("TCP <-> UART bridge");

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(SSID, PASSWORD);

  //start UART. Be sure to set the speed to match the speed of whatever is
  //connected  to the UART.
  SerialEcoVapo.begin(115200);

  // Start TCP listener on port TCP_PORT
  tcpServer.begin();
  tcpServer.setNoDelay(true);
  SerialDebug.print("Ready! Use 'telnet or nc ");
  SerialDebug.print(WiFi.localIP());
  SerialDebug.print(' ');
  SerialDebug.print(TCP_PORT);
  SerialDebug.println("' to connect");
}

void loop() {
  uint8_t i;
  uint8_t buf[1024];
  int bytesAvail, bytesIn;

  //check if there are any new clients
  if (tcpServer.hasClient()) {
    for (i = 0; i < MAX_SRV_CLIENTS; i++) {
      //find free/disconnected spot
      if (!tcpServerClients[i] || !tcpServerClients[i].connected()) {
        if (tcpServerClients[i]) tcpServerClients[i].stop();
        tcpServerClients[i] = tcpServer.available();
        SerialDebug.print("New client: "); SerialDebug.print(i);
        continue;
      }
    }
    //no free/disconnected spot so reject
    WiFiClient tcpServerClient = tcpServer.available();
    tcpServerClient.stop();
  }

  //check clients for data
  for (i = 0; i < MAX_SRV_CLIENTS; i++) {
    if (tcpServerClients[i] && tcpServerClients[i].connected()) {
      //get data from the telnet client and push it to the UART
      while ((bytesAvail = tcpServerClients[i].available()) > 0) {
        bytesIn = tcpServerClients[i].readBytes(buf, min(sizeof(buf), bytesAvail));
        if (bytesIn > 0) {
          SerialEcoVapo.write(buf, bytesIn);
          delay(0);
        }
      }
    }
  }

  //check UART for data
  while ((bytesAvail = SerialEcoVapo.available()) > 0) {
    bytesIn = SerialEcoVapo.readBytes(buf, min(sizeof(buf), bytesAvail));
    if (bytesIn > 0) {
      //push UART data to all connected telnet clients
      for (i = 0; i < MAX_SRV_CLIENTS; i++) {
        if (tcpServerClients[i] && tcpServerClients[i].connected()) {
          tcpServerClients[i].write((uint8_t*)buf, bytesIn);
          delay(0);
        }
      }
    }
  }
}
