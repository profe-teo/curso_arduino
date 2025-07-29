#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14

#define NORTE 32
#define SUR 33
#define ESTE 15
#define OESTE 4

int brujula[] = {NORTE, SUR, ESTE, OESTE};


int cero_x = 1922;
int cero_y = 1813;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);
/*
  pinMode(NORTE, OUTPUT);
  pinMode(SUR, OUTPUT);
  pinMode(ESTE, OUTPUT);
  pinMode(OESTE, OUTPUT);
  */
  for(int i = 0; i < 4; i++){
    pinMode(brujula[i], OUTPUT);
  }
}

void loop() {
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_sw = digitalRead(PIN_SW);

  if(valor_sw){
    for (int i = 0; i < 4;i++)
    {
      analogWrite(brujula[i],0);
    }
  }
  else{
    for (int i = 0; i < 4;i++)
    {
      analogWrite(brujula[i],255);
    }    
  }

  if ( valor_x - cero_x > 10 ){ // DERECHA
    Serial.println("Derecha: " + String(valor_x - cero_x));
    //onOffLed(ESTE,HIGH);
    onOffLed(ESTE,valor_x - cero_x );
  }
  if(valor_x - cero_x < -10){ //IZQUIERDA
    Serial.println("Izquierda: " + String(valor_x - cero_x));
    //onOffLed(OESTE, HIGH);
    onOffLed(OESTE, valor_x - cero_x);
  }
  if ( valor_y - cero_y > 10 ){ // ABAJO
    Serial.println("Abajo: " + String(valor_y - cero_y));
    //onOffLed(SUR,HIGH);
    onOffLed(SUR,valor_y - cero_y);
  }
  if(valor_y - cero_y < -10){ //ARRIBA
    Serial.println("Arriba: " + String(valor_y - cero_y));
    //onOffLed(NORTE,HIGH);
    onOffLed(NORTE,valor_y - cero_y);
  }
  delay(200);
}

void onOffLed(int led, int valor){
  /*
  digitalWrite(NORTE, LOW);
  digitalWrite(SUR, LOW);
  digitalWrite(ESTE, LOW);
  digitalWrite(OESTE, LOW);
  */
  int brillo = 0;
  if(valor < 0){
    valor = -valor;
  }
  brillo = map(valor, 0,2048,0,255);
  for (int i = 0; i < 4;i++)
  {
    digitalWrite(brujula[i],0);
  }

    analogWrite(led, brillo);

}
