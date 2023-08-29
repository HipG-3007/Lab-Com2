bool estadoDato=true;
bool estadoClk=false;
const int clk =  2;  
const int dato =  3;  

void setup() {
  attachInterrupt(digitalPinToInterrupt(2),sincronizacion,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),receptor,CHANGE);
  Serial.begin(9600);
  pinMode(clk, INPUT); 
  pinMode(dato, INPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
}

void loop() {
  Serial.println((String) "Estado " + estadoDato + "  Duty " + estadoClk);
  digitalWrite(12,estadoClk);
  digitalWrite(13,estadoDato);
}


void receptor(){
  estadoDato=!estadoDato;
}

void sincronizacion(){
  estadoClk=!estadoClk;
}
