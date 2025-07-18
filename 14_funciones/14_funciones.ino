
void setup() {
  Serial.begin(115200);
  delay(500);

  //int numero = sumar(3,2);
  //Serial.println(numero);
  int acumulador = 0;
  int valores[] = {1,3,4,5,8,12,34};

  for(int i = 0; i < 7; i++){
    acumulador = sumar(acumulador, valores[i]);
  }

  Serial.print("Total: ");
  Serial.println(acumulador);

  // -----------------------

  char cadena[] = "Hola Mundo";
  int largo = longitudCadena(cadena);
  Serial.print("Longitud: ");
  Serial.println(largo);

// --------------------------------

char* resultado;
resultado = invertirCadena(cadena);
Serial.print("Original: ");
Serial.println(cadena);
Serial.print("Inversa: ");
Serial.println(resultado);
//------------------------

resultado = inversa(cadena);
Serial.print("Original: ");
Serial.println(cadena);
Serial.print("Inversa: ");
Serial.println(resultado);
}

void loop() {

}

// FUNCIONES

// Función que suma dos números

int sumar(int primero, int segundo){
  /*
    1. Validar las entradas
    2. Hacer el trabajo
    3. Validar los resultados
  */
  int temp = primero + segundo;
  return temp;

}

// Función que calcules la longitud de una cadena
// camelCase
// PascalCase
// snake_case
int longitudCadena(char cadena[]){
  int i = 0;
  while(cadena[i] != '\0'){
    i++;
  }
  return i;

}

char* invertirCadena(char *cadena){
  int longitud = longitudCadena(cadena);
  char* inversa = new char[longitud + 1];
  int j = 0;
  for(int i = longitud -1; i>=0; i--){
    inversa[j] = cadena[i];
    j++;
  }
  inversa[longitud] = '\0';
  return inversa;
}

// ------------------------------
char* inversa(char* cadena){
  int longitud = longitudCadena(cadena);
  char temp[longitud];
  for(int i = 0; i < longitud; i++){
    temp[longitud - i -1] = cadena[i];
  }
  return temp;
}













