unsigned long tiempo = 0;
unsigned long t = 0;
const short pinLED = 4;
const short pinFR = A0;
char modal = "+";
const byte trigger = 7; // const = solo lectura ("constante")
const byte echo = 5;
float litros;
float altura;
float distancia;
int tiempo; 
const float pi = 3.1416;  
const float radio = 75;
const float h = 150;
void setup(){
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinFR, INPUT);
  pinMode(trigger, OUTPUT); // sensor
  pinMode(echo, INPUT); 
}
void loop(){
  if(Serial.available() > 0){ modal = Serial.read();}
  switch(modal){
    case 'E':{
      digitalWrite(pinLED, true);
      break;
    } 
    case 'A':{
      digitalWrite(pinLED, false);
      break;
    }
  }
  tiempo = millis();
  if((tiempo-t)>=200){
    t = tiempo;    
    if(analogRead(pinFR) < 300){ Serial.print("n");}
  }
}