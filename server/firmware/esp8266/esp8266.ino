/***
Teste de Websockets com ESP8266 - Servidor
José Cintra em Outubro de 2019 - www.josecintra.com/blog/comunicacao-websockets-nodemcu-esp8266">
***/

#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <neotimer.h>

//Correção nivel lógico invertido
#define ON LOW
#define OFF HIGH

WebSocketsServer webSocket = WebSocketsServer(81); // Recebe dados do cliente
Neotimer mytimer = Neotimer(10000); // Intervalo de 10 segundos para envio dos dados do sensor

// Autenticação wi-fi - Coloque aqui a sua configuração
const char* ssid     = "brisa-679421";
const char* password = "84bmey4i";

const int pinLED = D4;
String tempString; // Temperatura convertida para String

// Tratamento de eventos dos dados que vêm do cliente 
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {

  switch (type) {
    case WStype_DISCONNECTED:
      break;

    case WStype_CONNECTED:
      { IPAddress ip = webSocket.remoteIP(num);
        Serial.println(ip);
      }
      break;

    case WStype_TEXT:
      { String text = String((char *) &payload[0]);
        Serial.println(text);
        Serial.println(num);
        Serial.println(type);

        if (text == "ON") {
          digitalWrite(pinLED, ON);
        } else {
          digitalWrite(pinLED, OFF);
        }
      }
      break;

  }

}

void setup() {
  
  // Inicialização do LED
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, OFF);

  // Conexões wi-fi e websocket
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(". ");
    delay(100);
  }
  
  Serial.println(WiFi.localIP());
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

}

void loop() {
  webSocket.loop();

  // Envio periódico dos dados do sensor de temperatura para o cliente
  if (mytimer.repeat()) {;
    webSocket.sendTXT(0, "32");
  }
}

