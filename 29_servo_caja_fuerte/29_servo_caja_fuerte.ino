#include <ESP32Servo.h> 

#define pinServo 15

Servo miServo;

String entrada = "";
String secreto = "1234";
bool primeraVez = true;

void setup() {
  
  Serial.begin(115200);
  Serial.end();
  Serial.begin(115200);
  miServo.setPeriodHertz(50);
  miServo.attach(pinServo,500,2500);
  miServo.write(0);


}

void loop() {
  if(primeraVez){
    Serial.println("Introduzca la clave.");
    primeraVez = false;
  }
  
  if(Serial.available() > 0){
    entrada = Serial.readStringUntil('\n');
    entrada.trim();
    if(entrada == secreto){
      Serial.println("Clave correcta");
      miServo.write(90);
      delay(5000);
      Serial.println("Puerta cerrada");
      miServo.write(0);
    }
    else{
      Serial.println("Clave incorrecta. Pruebe otra vez.");
    }
    Serial.println("Introduzca la clave.");
  }
        
}



void limpiar(){
  Serial.write(27);  // Comando ESC
  Serial.print("[2J"); // Comando para borrar la pantalla
  Serial.write(27);
  Serial.print("[H");  // Mover el cursor a la posición inicial   
}






