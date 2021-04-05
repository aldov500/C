
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#define TELNET Serial

// "{\"Status\":\"Iniciando\"}"

/* :::Declaraciones Globales :::*/
const char* ssid       = "ECOVAPO";
const char* pass       = "ecovapo2018";

bool EstaConectado = false;

/* :::Declaracion Servidor Telnet::: */
const int TelnetPuerto       = 23;
WiFiServer TelnetWifiServer(TelnetPuerto);
IPAddress IP(192, 168, 1, 1);

/* :::Declaracion Cliente Telnet::: */
const int TelnetNumClientes = 1;
WiFiClient TelnetWifiCliente[TelnetNumClientes];

void ConectarTelnet();
void EscribirStringTelnet();
void ConfigurarTelnet();
void RecibirTelnet();
void EscribirTelnet();

void setup() {

  ConfigurarTelnet();

}

void loop() {

  ConectarTelnet();
  RecibirTelnet();
  EscribirTelnet();
}

void ConfigurarTelnet() {
  /* :::Inicio del Sistema::: */
  TELNET.begin(115200);
  TELNET.print("{\"Status\":\"Iniciando\"}");

  pinMode(LED_BUILTIN, OUTPUT);

  /* Configuracion Punto de Acceso */
  TELNET.println("{\"Status\":\"Iniciando Punto de Acceso\"}");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IP, IP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid, pass);

  /* Configuracion Servidor Telnet */
  TelnetWifiServer.begin();
  TelnetWifiServer.setNoDelay(true);

  /* Finalizacion de Configuracion */
  TELNET.print("{\"Status\":\"Iniciado\"}");
}

void EscribirTelnet() {
  uint8_t aux;
  if (TELNET.available()) {
    size_t len = TELNET.available();
    uint8_t sbuf[len];
    TELNET.readBytes(sbuf, len);

    /* Respuesta para telnet */
    for (aux = 0; aux < TelnetNumClientes; aux++) {
      if (TelnetWifiCliente[aux] && TelnetWifiCliente[aux].connected()) {
        TelnetWifiCliente[aux].write(sbuf, len);
        
      }
    }
    for(int i=0; i<len; i++){
      sbuf[i] = 0;
    }
  }
  else {
    return;
  }
}
void RecibirTelnet() {
  char TelnetReadChar[15];
  String TelnetReadString;
  uint8_t aux;
  /* Recepcion de datos */
  for (aux = 0; aux < TelnetNumClientes; aux++) {
    if (TelnetWifiCliente[aux] && TelnetWifiCliente[aux].connected()) {

      /* Enviar datos de Telnet a Serial */
      if (TelnetWifiCliente[aux].available()) {
        while (TelnetWifiCliente[aux].available()) {
          TelnetReadChar[aux] = TelnetWifiCliente[aux].read();
          TELNET.write(TelnetReadChar[aux]);
          TelnetReadString += TelnetReadChar[aux];
        }

      }

    } else {
      if (EstaConectado = false) {
        TELNET.println("{\"Status\":\"Desconectado\"}");
        digitalWrite(LED_BUILTIN, LOW);
        delay(10);
      }

    }
  }
  return;
}
void ConectarTelnet() {

  for (int i = 0; i < TelnetNumClientes; i++) {
    if (TelnetWifiServer.hasClient()) {
      String RespuestaConexion = "{\"Status\":\"Conectado\"}";

      if (!TelnetWifiCliente[i] || !TelnetWifiCliente[i].connected()) {
        if (TelnetWifiCliente[i]) {
          TelnetWifiCliente[i].stop();
        }

        TelnetWifiCliente[i] = TelnetWifiServer.available();
        EscribirStringTelnet(RespuestaConexion);
        EstaConectado = true;
      }

    }
  }
  return;

}


void EscribirStringTelnet(String Mensaje) {
  size_t t = Mensaje.length() + 1;
  uint8_t buff[t];

  Mensaje.getBytes(buff, t);

  for (int i = 0; i < TelnetNumClientes; i++) {
    if (TelnetWifiCliente[i] && TelnetWifiCliente[i].connected()) {
      TelnetWifiCliente[i].write(buff, t);
    }
    else {
      return;
    }
  }
}
