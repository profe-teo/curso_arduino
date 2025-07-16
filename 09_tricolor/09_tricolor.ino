#define ROJO 15
#define VERDE 13
#define AZUL 12

void setup() {
  pinMode(ROJO,OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL,OUTPUT);

}

void loop() {
  /*
  // Rojo
  digitalWrite(ROJO,LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, HIGH);

  delay(500);

// Verde
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);

  delay(500);
  

  //Azul
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);

  delay(500);

    //Magenta
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);

  delay(500);

    //Cian
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  delay(500);

    //Amarillo
  digitalWrite(ROJO,LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);

  delay(500);

    //Blanco
  digitalWrite(ROJO,LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  delay(500);
  */

  int r = 0;
  int g = 0;
  int b = 0;

  for(;;){
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);

    analogWrite(ROJO, r);
    analogWrite(VERDE, g);
    analogWrite(AZUL, b);

    delay(1000);
  }


}
