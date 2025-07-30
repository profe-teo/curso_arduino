#define SENSOR 4

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);

}

void loop() {
  int lectura = touchRead(SENSOR);
  Serial.println("Sensor: " + String(lectura));

  delay(200);

}
