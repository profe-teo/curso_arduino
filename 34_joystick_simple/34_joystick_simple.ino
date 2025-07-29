#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14




int cero_x = 1922;
int cero_y = 1813;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);

}

void loop() {
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_sw = digitalRead(PIN_SW);
/*
  Serial.print("X, Y, Z: ");
  Serial.print(String(valor_x) + ", ");
  Serial.print(String(valor_y) + ", ");
  Serial.println(String(valor_sw));
*/
  if ( valor_x - cero_x > 10 ){ // DERECHA
    Serial.println("Derecha: " + String(valor_x - cero_x));
  }

  if(valor_x - cero_x < -10){ //IZQUIERDA
    Serial.println("Izquierda: " + String(valor_x - cero_x));
  }
  if ( valor_y - cero_y > 10 ){ // ABAJO
    Serial.println("Abajo: " + String(valor_y - cero_y));
  }

  if(valor_y - cero_y < -10){ //ARRIBA
    Serial.println("Arriba: " + String(valor_y - cero_y));
  }
  delay(500);

}
