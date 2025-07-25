#include <ESP32Servo.h> 

#define pinServo 15

Servo miServo;

void setup() {
  miServo.setPeriodHertz(50);
  miServo.attach(pinServo,500,2500);

}

void loop() {
  /*
  for(int i = 0; i < 180; i++){
    miServo.write(i);
    delay(20);
  }
  delay(200);

  for(int i = 180; i > 0; i--){
    miServo.write(i);
    delay(20);
  }
  delay(200);
  
*/
miServo.write(0);
delay(2000);
  for(int i = 0; i <= 180; i+=45){
    miServo.write(i);
    delay(500);
  }
  delay(2000);

  for(int i = 180; i >= 0; i-=45){
    miServo.write(i);
    delay(500);
  }
  delay(2000);
  
        
}
