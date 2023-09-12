int dato[3] = {0};
int hamrx[7] = {0,1,0,0,1,0,1};
int p[3] = {0};

void setup() {
  Serial.begin(9600);
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
}

void loop() {
  
  invhamming();
  
  for (int i = 0; i < 4; i++) {
    Serial.print(dato[i]);
    delay(50);
  }
  Serial.println();
  
  digitalWrite(23,dato[0]);
  digitalWrite(25,dato[1]);
  digitalWrite(27,dato[2]);
  digitalWrite(29,dato[3]);
}


void invhamming() {
  p[0] = hamrx[2]^hamrx[4]^hamrx[6];
  p[1] = hamrx[2]^hamrx[5]^hamrx[6];
  p[2] = hamrx[4]^hamrx[5]^hamrx[6];
  dato[0] = hamrx[2];    
  dato[1] = hamrx[4];
  dato[2] = hamrx[5];    
  dato[3] = hamrx[6];
  
  if((p[0]!=hamrx[0])&&(p[1]!=hamrx[1])&&(p[2]==hamrx[3])){
    dato[0] = !hamrx[2];
  } 
  if((p[0]!=hamrx[0])&&(p[1]==hamrx[1])&&(p[2]!=hamrx[3])){
    dato[1] = !hamrx[4];
  }
  if((p[0]==hamrx[0])&&(p[1]!=hamrx[1])&&(p[2]!=hamrx[3])){
    dato[2] = !hamrx[5];
  }
  if((p[0]!=hamrx[0])&&(p[1]!=hamrx[1])&&(p[2]!=hamrx[3])){
    dato[3] = !hamrx[6];
  }
}
