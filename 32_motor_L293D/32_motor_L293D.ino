// https://descubrearduino.com/l293d/

#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

//Estados posibles
#define PARO 0
#define DERECHA 1
#define IZQUIERDA 2



void setup() {
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

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
      analogWrite(VELOCIDAD, 0); // Aapagamos el motor
      break;
    case IZQUIERDA:
      //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
      Serial.println("Girando en la dirección IZQUIERDA.");
      analogWrite(VELOCIDAD, 70);
      digitalWrite(DIRPIN_1, 0);
      digitalWrite(DIRPIN_2, 1);
      break;
    case DERECHA:
      //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
      Serial.println("Girando en la dirección DERECHA.");
      analogWrite(VELOCIDAD, 250);
      digitalWrite(DIRPIN_1, 1);
      digitalWrite(DIRPIN_2, 0);    
  }


}











