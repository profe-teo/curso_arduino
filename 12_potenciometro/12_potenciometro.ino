#define LED 13
#define POT 4

#define ZUM 14
#define POT2 12

int valorPot = 0;
int valorLed = 0;

int valorPotZ = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(POT,INPUT);

  pinMode(ZUM,OUTPUT);
  pinMode(POT2,INPUT);

}

void loop() {
  // 0 - 4096
  valorPot = analogRead(POT);
  valorPotZ = analogRead(POT2);

  valorLed = map(valorPot,0,4096,0,255);

  analogWrite(LED, valorLed);

  digitalWrite(ZUM, HIGH);
  delay(valorPotZ);
  digitalWrite(ZUM, LOW);
  delay(valorPotZ);  

  Serial.println("Pot: " + String(valorLed));

  //delay(100);

}
