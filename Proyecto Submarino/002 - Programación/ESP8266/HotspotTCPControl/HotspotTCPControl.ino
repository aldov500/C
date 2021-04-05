
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#define tcpServerSerial Serial

/* Declaraciones Globales */
const char* ssid       = "ECOVAPO";
const char* pass       = "ecovapo2018";

/* Declaracion Servidor TCP */
const int tcpPort       = 23;
WiFiServer tcpServer(tcpPort);
IPAddress IP(192, 168, 1, 1);

/* Dclaracion Cliente TCP */
const int tcpNumClients = 1;
WiFiClient tcpClient[tcpNumClients];


void setup() {
  /* Inicio del Sistema */
  tcpServerSerial.begin(115200);
  tcpServerSerial.println("\n"); delay(1000);
  tcpServerSerial.print("Iniciando servidor TCP");
  for (int i = 0; i < 5; i++) {
    tcpServerSerial.print(".");
    delay(50);
  }
  pinMode(LED_BUILTIN, OUTPUT);

  /* Configuracion Punto de Acceso */
  tcpServerSerial.println("Iniciando Punto de Acceso");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IP, IP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid, pass);

  /* Configuracion Servidor TCP */
  tcpServer.begin();
  tcpServer.setNoDelay(true);

  /* Finalizacion de Configuracion */
  tcpServerSerial.print("Servidor TCP iniciado! Conexión telnet por medio de ");
  tcpServerSerial.print(WiFi.localIP());
  tcpServerSerial.print(' ');
  tcpServerSerial.print(tcpPort);
  tcpServerSerial.println(" para conexión.");

}

void loop() {

  uint8_t aux;
  String tcpReadString;
  char tcpReadChar[15];

  /* Conexion a nuevo cliente */
  if (tcpServer.hasClient()) {
    for (aux = 0; aux < tcpNumClients; aux++) {
      /* Busca clientes para desconectar */
      if ( !(tcpClient[aux]) || !(tcpClient[aux].connected()) ) {
        tcpClient[aux] = tcpServer.available();
        tcpServerSerial.print("Nueva conexión: ");
        tcpServerSerial.println(aux + 1);
        continue;
      }
    }
  }

  /* Recepcion de datos */
  for (aux = 0; aux < tcpNumClients; aux++) {
    if (tcpClient[aux] && tcpClient[aux].connected()) {

      /* Enviar datos de Telnet a Serial */
      if (tcpClient[aux].available()) {
        while (tcpClient[aux].available()) {
          tcpReadChar[aux] = tcpClient[aux].read();
          tcpServerSerial.write(tcpReadChar[aux]);
          tcpReadString += tcpReadChar[aux];
        }

      }

    } else {
      tcpServerSerial.println("Usuario desconectado.");
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  if (tcpReadString == "OK\r\n") {
    tcpServerSerial.println("String");
  }


  if (tcpServerSerial.available()) {
    size_t len = tcpServerSerial.available();
    uint8_t sbuf[len];
    tcpServerSerial.readBytes(sbuf, len);

    /* Respuesta para telnet */
    for (aux = 0; aux < tcpNumClients; aux++) {
      if (tcpClient[aux] && tcpClient[aux].connected()) {
        tcpClient[aux].write(sbuf, len);
          
      }
    }

  }



  aux = 0;
  tcpReadString = "";

}
