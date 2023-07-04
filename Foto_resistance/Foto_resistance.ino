const byte pinFR = A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  pinMode(pinFR, INPUT);
} 
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(pinFR));
}