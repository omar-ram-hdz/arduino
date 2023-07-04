const byte pinRed = 12;
const byte pinBlue = 13;
char Read;
void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  while(Serial.available() > 0){
    Read = Serial.read();
  }
  if(Read == 'E') digitalWrite(pinRed,true);
  if(Read=='A') digitalWrite(pinRed,false);
  if(Read == 'I') digitalWrite(pinBlue,true);
  if(Read == 'O')digitalWrite(pinBlue,false);
}