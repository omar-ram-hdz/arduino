const byte pinFR = A1;
unsigned short valueFR = 0;
char task = "1";
String stringFR = String("");
void setup() {
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  pinMode(pinFR, INPUT);
}

void loop() {
  valueFR = analogRead(pinFR);
  if(valueFR < 70 ){
    stringFR = "Noche";
  }
  if(valueFR>100 && valueFR<400){
    stringFR = "Dia";
  }
  if(Serial.available()>0){
    task = Serial.read();
  }
  if(task == '~'){
    Serial.print(stringFR);
    task = "1";
  }
}
