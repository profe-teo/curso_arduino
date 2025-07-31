#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Pin del DHT22
#define DHTPIN 4
#define DHTTYPE DHT22

// Objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// -----------------------------------

char* ssid = "Aula 1";
char* pwd = "Horus.2025";

// MQTT

char* mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

char*  mqtt_topic_sub = "curso_arduino/teo/#";

char*  mqtt_topic_pub = "curso_arduino/teo";
char*  mqtt_client_id = "ESP_Teo";

static unsigned long lastMsg = 0;
unsigned long now;

// ----------------------
float temp = 0.0;
float hum = 0.0;

char tempStr[8];
char humStr[8];
// ----------------------

void setup() {
  Serial.begin(115200);
  
  // Conexión Wifi
  WiFi.begin(ssid,pwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());

  //MQTT
  client.setServer(mqtt_server,mqtt_port);
  client.setCallback(callback);
  
  // -----------------------------
  dht.begin();
}


void loop() {
  if(!client.connected()){
    reconnect();
  }
  client.loop();

/*
 if (Serial.available() > 0) {
    String mensaje = Serial.readStringUntil('\n');
    mensaje.trim();  // Elimina espacios o saltos de línea
    if (mensaje.length() > 0) {
      client.publish(mqtt_topic_pub, mensaje.c_str());
      Serial.print("Publicado: ");
      Serial.println(mensaje);
    }
  }
 */
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  dtostrf(temp, 1, 2, tempStr);
  dtostrf(hum, 1, 2, humStr);

  client.publish("curso_arduino/teo/temperatura", tempStr);
  client.publish("curso_arduino/teo/humedad", humStr);

  Serial.println("Temp: " + String(tempStr));
  Serial.println("Hum: " + String(humStr));

  delay(5000);

}

// Funciones
// Mensaje recibido en [curso_arduino/teo]: Hola Mundo
void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Mensaje recibido en [");
  Serial.print(topic);
  Serial.print("]:");
  for(int i = 0; i < length; i++){
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect(){
  while(!client.connected()){
    Serial.println("Reconectando ...");
    if(client.connect(mqtt_client_id)){
      Serial.println("Conectado a MQTT");
      client.subscribe(mqtt_topic_sub);
    }
    else{
      Serial.println("Fallo en la conexión");
      Serial.println("Error: " + client.state());
      delay(5000);
    }
  }
}













