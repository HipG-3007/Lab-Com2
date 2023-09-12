
const int clk =  2;      

const int dato =  3;  

void setup() {
  attachInterrupt(digitalPinToInterrupt(2),sincronizacion,HIGH);
 // attachInterrupt(digitalPinToInterrupt(3),receptor,CHANGE);
  Serial.begin(9600);
  pinMode(clk, INPUT); 
  pinMode(dato, INPUT); 

}

void loop() {
  
}


void receptor(){
  Serial.println((String) "dato= " + digitalRead(dato));
}

void sincronizacion(){
  if(digitalRead(clk)==HIGH){
    //Serial.println((String) "clk= " + digitalRead(clk));
    Serial.println((String) "dato= " + digitalRead(dato));
    //attachInterrupt(digitalPinToInterrupt(3),receptor,CHANGE);
  }
}
