#define dataPin 3
#define clockPin 2
byte hamrx[7]={0};
byte bitCount = 0;


void setup() {
  pinMode(dataPin, INPUT);
  pinMode(clockPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(clockPin), clock_reciver, CHANGE);
}


void loop() {

}


void clock_reciver() {
  if(digitalRead(clockPin)==HIGH){
    //Serial.print("hola");
    Serial.print(hamrx[bitCount] = digitalRead(dataPin));
    //Serial.print(bitCount);
    bitCount=bitCount+1;
    
  }

}
