#define ROJO 13
#define VERDE 12
#define AZUL 14

#define POT_R 4
#define POT_V 15
#define POT_A 2

int pot_r, pot_v, pot_a;
int led_r, led_v, led_a;

void setup() {
  pinMode(ROJO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  pinMode(AZUL,OUTPUT);

  pinMode(POT_R, INPUT);
  pinMode(POT_V, INPUT);
  pinMode(POT_A, INPUT);

}

void loop() {
  pot_r = analogRead(POT_R);
  led_r = map(pot_r,0,4096,0,255);
  analogWrite(ROJO, 255 - led_r);
  
  pot_v = analogRead(POT_V);
  led_v = map(pot_v,0,4096,0,255);
  analogWrite(VERDE, 255 - led_v);

  pot_a = analogRead(POT_A);
  led_a = map(pot_a,0,4096,0,255);
  analogWrite(AZUL, 255 - led_a);

  delay(100);
}
