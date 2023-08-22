bool estado=false;

void setup() {
  attachInterrupt(digitalPinToInterrupt(2),receptor,CHANGE);
  Serial.begin(9600);
  pinMode(3,1);
}

void loop() {
  Serial.println((String) "Estado " + estado);
  digitalWrite(3,estado);
}


void receptor(){
  estado=!estado;
}
