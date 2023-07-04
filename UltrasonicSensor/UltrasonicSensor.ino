const byte Trigger = 2;
const byte Echo = A0;
short p = 0;
unsigned long time = 0;
unsigned long absoluteTime = 0;
char task =  "+";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}
void loop() {
  if(Serial.available()>0){
    task = Serial.read();
  }
  absoluteTime = millis();
  digitalWrite(Trigger, false);
  if((absoluteTime - time)>=1000){
    time = absoluteTime;
    digitalWrite(Trigger, true);
    delayMicroseconds(10);
    digitalWrite(Trigger, false);
    p = int(((pulseIn(Echo, HIGH)/59)/0.1)-10);
    p = map(p,0,100,100,0);
    if(p<0){
      p=0;
    }
  }
  if(task == 'Y'){
      Serial.print(p);
      task = "+";
  }
}