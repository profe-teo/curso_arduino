#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11

#define LED 14

DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
float hum = 0.0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  digitalWrite(LED, HIGH);
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.println(temp);

  Serial.println("Humedad: " + String(hum));
  digitalWrite(LED,LOW);
  delay(1000);

}







