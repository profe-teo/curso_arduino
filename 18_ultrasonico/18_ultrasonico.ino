#define TRG 13
#define ECHO 14
#define LED 15
#define MAX_DIST 700 // cm

float distancia = 0.0;
float timeOut = MAX_DIST * 60;
int velSonido = 340; 

int valorLed = 0;


void setup() {
  Serial.begin(115200);
  pinMode(TRG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  distancia = getSonar();
  valorLed = 255 - map(distancia,0,300,0,255);

  analogWrite(LED, valorLed);

  Serial.println("Distancia: " + String(distancia));
  delay(500);
}

float getSonar(){
  unsigned long int pingTime = 0;
  float dist = 0.0;

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRG, LOW);

  pingTime = pulseIn(ECHO, HIGH, timeOut);
  Serial.println("Ping Time:" +  String(pingTime));

  dist = (float) pingTime * velSonido / 2 / 10000;
  return dist; // en cm

}






