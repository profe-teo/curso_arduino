#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11

#define LED 2

char* ssid = "Aula 1";
char* pwd = "Horus.2025";

WebServer servidor(80);

// Páginas

String home = "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Primera página</title></head><body><h1>Hola Mundo</h1><h2>Esta es mi primera página</h2><a href=\"/segunda\">Ir a la segunda página</a></body></html>";
String segunda = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda página</title></head><body><h1>Esta es la segunda página</h1></body></html>";
String temperatura = "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Primera página</title></head><body><h1>Temperatura y humedad</h1><h2>Temperatura: ##temp##</h2><h2>Humedad: ##hum##</h2></body></html>";

DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
float hum = 0.0;


void setup() {
  pinMode(LED, OUTPUT);
  dht.begin();
  // ------------------

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());

 // Solicitudes web
  servidor.on("/",handle_OnConnect);
  servidor.on("/segunda",handle_Segunda);
  servidor.on("/led_on", handle_Encender);
  servidor.on("/led_off", handle_Apagar);
  servidor.on("/temp",handle_Temp);


  servidor.begin();
  Serial.println("Servidor web iniciado");

}

void loop() {
  servidor.handleClient();
}


// Funciones de respuesta a las páginas web

void handle_OnConnect(){
  servidor.send(200,"text/html",home);
}

void handle_Segunda(){
  servidor.send(200,"text/html",segunda);
}

void handle_Encender(){
  digitalWrite(LED, HIGH);
  servidor.send(200,"text/html","");
}

void handle_Apagar(){
  digitalWrite(LED, LOW);
  servidor.send(200,"text/html","");
}

void handle_Temp(){
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  /*
  temperatura.replace("##temp##", String(temp));
  temperatura.replace("##hum##", String(hum));
  servidor.send(200,"text/html",temperatura);
  */
  // {"nombre":"ESP32","temperatura":24.5,"activo":true,"sensores":["DHT22","MQ-2","BMP180"]}
  String json = "{\"temp\":" + String(temp) + ",\"hum\":" + String(hum) + "}";
  servidor.send(200,"text/json",json);
}





