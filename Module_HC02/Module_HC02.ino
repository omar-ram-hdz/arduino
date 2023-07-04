int pinRed = 12;
int pinBlue = 13;
byte pinPiezo = 8;
char Read;
int valueGas;
unsigned long Tiempo1 = 0;
unsigned long T1 = 0;
const byte pinGas = A0;
void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(pinGas,INPUT);
  pinMode(pinPiezo,OUTPUT);
}
void loop() {
  valueGas = analogRead(pinGas);
  Tiempo1 = millis();
  if(Serial.available() > 0){
    Read = Serial.read();
  }
  if(Read == 'E') digitalWrite(pinRed,true);
  if(Read=='A') digitalWrite(pinRed,false);
  if(Read == 'I') digitalWrite(pinBlue,true);
  if(Read == 'O')digitalWrite(pinBlue,false);
  if((Tiempo1-T1)>=350){
    Serial.println(valueGas);
    T1 = Tiempo1;
    if(valueGas>625) digitalWrite(pinPiezo,true);
    //Si al enviar los datos del sensor, el sensor tiene valores mayores a 620 entonces se enciende el piezo
    else digitalWrite(pinPiezo,false);
  }
}
