const int clk =  2;      
int estadoCLK = LOW;    
long tiempoPasadoClk = 0;  
long duty = 0;          

const int tx =  3;      
int estadoTx = LOW;            
long tiempoPasadoTx = 0;        
long intervaloTx = 0;  

long tiempoPasadoHamming = 0;        
long intervaloHamming = 0;

long tiempoPasadoLectura = 0;        
long intervaloLectura = 0;

int estadoAnterior1 = LOW;

int estadoAnterior2 = LOW;

int estadoAnterior3 = LOW;

int estadoAnterior4 = LOW;

int dato[] = {0,0,0,0};
int hamtx[7] = {0};

int i = 0;
int l = 0;

String texto;

void setup() {
 Serial.begin(9600);
 pinMode(clk, OUTPUT); 
 pinMode(tx, OUTPUT);
}

void loop() {
  TextoABinario();
}


void TextoABinario() {
  while (Serial.available() == 0) {
  }

  while (Serial.available() > 0) {
    texto = Serial.readStringUntil('\n');
  }

  Serial.print("Texto ingresado: ");
  Serial.println(texto);

  Serial.println("Codigo binario:");
  
  for (int m = 0; m < texto.length(); m++) {
    int ascii_value = int(texto.charAt(m));
    Serial.println("_______________________________________________________");
    Serial.print((String)texto.charAt(m)+":\n");
    for (int k = 0; k <= 1; k++) {
      int tindx = 0;
      
      for (int j = 7; j >= 4; j--) {
        dato[tindx] = (ascii_value & (1 << j)) ? 1 : 0;
        Serial.print((String) "" + dato[tindx] + "   ");
        tindx++;
      }
      Serial.println("");
      hamming();
      transmisor(hamtx, sizeof(hamtx) / sizeof(int)); 
      ascii_value = ascii_value << 4;     
    }
    
    Serial.println("");
  }
  Serial.println("");
}

void hamming(){
unsigned long tiempoActual = millis();
  if(tiempoActual - tiempoPasadoHamming > intervaloHamming) {
    tiempoPasadoHamming = tiempoActual;  

    Serial.println((String) "datos ->" + dato[0] + dato[1] + dato[2] + dato[3]);

    hamtx[0]=(dato[0]^dato[1])^dato[3];
    hamtx[1]=(dato[0]^dato[2])^dato[3];  
    hamtx[2]=dato[0];
    hamtx[3]=(dato[1]^dato[2])^dato[3];  
    hamtx[4]=dato[1];  
    hamtx[5]=dato[2];  
    hamtx[6]=dato[3];

    Serial.println((String)"hamming(7,4)\n" + "Bit/P1  "+ "Bit/P2  " + "Bit3  " + "Bit/P4  " + "Bit5   " + "Bit6   " + "Bit7");
    for (int i = 0; i < 7; i++) {
      Serial.print((String) "   " + hamtx[i] + "   ");
    }
    Serial.println("");
    
    //
  }
  
}


void transmisor(int bits[], int longitud) {
unsigned long tiempoActual = millis();
  if(tiempoActual - tiempoPasadoTx > intervaloTx) {
    tiempoPasadoTx = tiempoActual;

    for (l=0; l < longitud; l++) {
      Reloj();
      if(estadoCLK==HIGH){
        digitalWrite(tx, bits[l]);
        Serial.print(bits[l]);
      }
      else{
        digitalWrite(tx, 0);
        l--;
      }
      
//      if(l==2){
//        bits[2]=0;
//      }

      if(l>=6){
        Serial.println(" -> Hamming Enviado \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _");
        //l=0;
      }
      //Serial.println((String) "El for llego hasta l="+l);
    }
  }
}


void Reloj(){
unsigned long tiempoActual = millis();
  if(tiempoActual - tiempoPasadoClk > duty) {
    tiempoPasadoClk = tiempoActual;   
    if (estadoCLK == LOW){
      estadoCLK = HIGH;
      //Serial.println("Alto");
    }
    else{
      estadoCLK = LOW;
      //Serial.println("Bajo");
    }
    digitalWrite(clk, estadoCLK);
  }
}



                
