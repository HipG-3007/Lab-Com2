const int clk =  2;      
int estadoCLK = LOW;    
long tiempoPasadoClk = 0;  
long duty = 500;          


const int dato =  3;      
int estadoDato = LOW;            
long tiempoPasadoDato = 0;        
long intervaloDato = 1000;  


void setup() {
  pinMode(clk, OUTPUT); 
  pinMode(dato, OUTPUT);   
}

void loop(){
  Reloj();
  Data();
}


void Reloj(){
unsigned long tiempoActual = millis();
  if(tiempoActual - tiempoPasadoClk > duty) {
    tiempoPasadoClk = tiempoActual;   
    if (estadoCLK == LOW){
      estadoCLK = HIGH;
    }
    else{
      estadoCLK = LOW;
    }
    digitalWrite(clk, estadoCLK);
  }
}


void Data(){
unsigned long tiempoActual = millis();
  if(tiempoActual - tiempoPasadoDato > intervaloDato) {
    tiempoPasadoDato = tiempoActual;   
    if (estadoDato == LOW){
      estadoDato = HIGH;
      }
    else{
      estadoDato = LOW;
      }     
    digitalWrite(dato, estadoDato);
  }
}
