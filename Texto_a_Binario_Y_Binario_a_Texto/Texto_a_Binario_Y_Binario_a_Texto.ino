String texto;
char dato[1000];

void setup() {
  Serial.begin(9600);
}

void loop() {
  TextoABinario();
  
  BinarioATexto(dato); 
}



void TextoABinario() {
  while (Serial.available() == 0) {

  }

  while (Serial.available() > 0) {
    texto = Serial.readStringUntil('\n');
  }

  Serial.print("Texto ingresado: ");
  Serial.println(texto);

  Serial.println("Código binario:");

  int index = 0; 

  for (int i = 0; i < texto.length(); i++) {
    char c = texto.charAt(i);
    for (int j = 7; j >= 0; j--) {
      //Serial.print((c & (1 << j)) ? '1' : '0');
      dato[index++] = (c & (1 << j)) ? '1' : '0';
    }
    //Serial.print(' ');
  }
  dato[index] = '\0'; 
  Serial.println(dato);
  Serial.println(" ");
}




void BinarioATexto(char* binario) {
  int longitud = strlen(binario);
  char* texto = new char[longitud / 8 + 1]; 

  for (int i = 0; i < longitud; i += 8) {
    char byte = 0;
    for (int j = 0; j < 8; j++) {
      byte = (byte << 1) + (binario[i + j] - '0');
    }
    texto[i / 8] = byte;
  }
  texto[longitud / 8] = '\0';

  Serial.println("Texto convertido:");
  Serial.println(texto);
  Serial.println("\n");
  delete[] texto;
  
}
