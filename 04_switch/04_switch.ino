int dia = 7;
String nombreDia = "";

void setup() {

  Serial.begin(115200);
  delay(500);
  switch (dia) {
  case 1:
    nombreDia = "Lunes";
    break;
  case 2:
    nombreDia = "Martes";
    break;  
  case 3:
    nombreDia = "Miércoles";
    break; 
  case 4:
    nombreDia = "Jueves";
    break; 
  case 5:
    nombreDia = "Viernes";
    break; 
  case 6:
    nombreDia = "Sábado";
    break; 
  case 7:
    nombreDia = "Domingo";
    break;     
  }
Serial.println("El día es " + nombreDia);

}

void loop() {
  // put your main code here, to run repeatedly:

}
