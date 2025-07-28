// https://descubrearduino.com/l293d/

#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

//Estados posibles
#define PARO 0
#define DERECHA 1
#define IZQUIERDA 2

// Diodos LED
#define ROJO 0
#define VERDE 15
#define AZUL 4


void setup() {
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(ROJO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  pinMode(AZUL,OUTPUT);

}

void loop() {
  cambioEstado(DERECHA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);

  cambioEstado(IZQUIERDA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);
}

void cambioEstado(int estadoNuevo){
  switch(estadoNuevo){
    case PARO:
      Serial.println("Motor parado.");
      analogWrite(VELOCIDAD, 0); // Aapagamos el motor
      digitalWrite(ROJO,HIGH);
      digitalWrite(AZUL,LOW);
      digitalWrite(VERDE,LOW);
      break;
    case IZQUIERDA:
      //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
      Serial.println("Girando en la dirección IZQUIERDA.");
      analogWrite(VELOCIDAD, 70);
      digitalWrite(DIRPIN_1, 0);
      digitalWrite(DIRPIN_2, 1);

      digitalWrite(ROJO,LOW);
      digitalWrite(AZUL,HIGH);
      digitalWrite(VERDE,LOW);      
      break;
    case DERECHA:
      //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
      Serial.println("Girando en la dirección DERECHA.");
      analogWrite(VELOCIDAD, 250);
      digitalWrite(DIRPIN_1, 1);
      digitalWrite(DIRPIN_2, 0); 

      digitalWrite(ROJO,LOW);
      digitalWrite(AZUL,LOW);
      digitalWrite(VERDE,HIGH);   
      break;      
  }


}











