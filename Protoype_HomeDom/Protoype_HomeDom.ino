// Constante String:
String constantString = String();
const char space= " ";

// String de la FR 
String stringFR = String("Day");

// Casos de tipo Char
char caseTask = "Z";

// Luces:
const byte ligthCuarto1 = 2;
const byte ligthCuarto2 = 3;
const byte ligthBanio = 4;
const byte ligthCocina = 5;
const byte ligthComedor = 6;
const byte ligthSala = 7;

// Cortinas:
const byte Cuarto_Pin1 = 8,Cuarto_Pin2 = 9,Sala_Pin1 = 10, Sala_Pin2 = 11;

// Sensores:
const byte cisternaOne = A0, cisternaTwo = A1, gas = A2;

// Fotoresistencia:
const byte FR = A3;

//Sensor ultrasonico:
const byte Trigger = 12;
const byte Echo = A4;

// Millis:
unsigned long time = 0, absoluteTime = 0;

// Valores:
unsigned short valueCisternaOne = 0, valueGas, valueFR;
bool statusCisternaTwo;

// Satus:
bool statusCuarto1 = false, statusCocina = false,statusSala = false,statusBanio = false,statusCuarto2 = false,statusComedor = false;

// Funciones secundarias:
void awaitToSerialComunication(){
  while(!Serial){
    ;// El bucle dejará de repetirce hasta que la comunicacion serial este disponible
  }
}
bool toggle(bool status){//Si es true lo vuelve false y apaga y si es false,lo vuelve true y lo enciende
  if(status){
    return false;
  }
  return true;
}

// Funciones principales
void setup() {
  // Comunicacion serial:
  Serial.begin(9600);
  awaitToSerialComunication();
  
  // Pines de luz
  pinMode(ligthCocina, OUTPUT);
  pinMode(ligthCuarto1, OUTPUT);
  pinMode(ligthSala, OUTPUT);
  pinMode(ligthCuarto2, OUTPUT);
  pinMode(ligthComedor, OUTPUT);
  pinMode(ligthBanio, OUTPUT);

  // Pines de cortinas:
  pinMode(Cuarto_Pin1, OUTPUT);
  pinMode(Sala_Pin1, OUTPUT); 
  pinMode(Cuarto_Pin2, OUTPUT);
  pinMode(Sala_Pin2, OUTPUT); 

  // Pines de sensores:
  pinMode(cisternaOne, INPUT);
  pinMode(cisternaTwo, INPUT);
  pinMode(gas, INPUT);

  // Fotoresistencia
  pinMode(FR, INPUT);

  //Sensor ultrasonico
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}
void loop() {
  // Lectura de los valores de los sensores:
  statusCisternaTwo = digitalRead(cisternaTwo);
  valueGas = analogRead(gas);
  if(analogRead(FR)<60){
    stringFR = "Nigth";
  }else if (analogRead(FR)>169 && analogRead(FR) < 190){
    stringFR = "Day";
  }else{
    stringFR = "Error"; 
  }

  // Concatenacion y envio de los valores de los sensores:
  constantString = valueCisternaOne + space + statusCisternaTwo + space + valueGas + space + stringFR;
  absoluteTime = millis();
  if ((absoluteTime - time) >= 500) {
    time = absoluteTime;
    awaitToSerialComunication();
    Serial.println(constantString);
  }
  if((absoluteTime - time)>=1000){
    digitalWrite(Trigger, true);
    delayMicroseconds(10);
    digitalWrite(Trigger, false);
    valueCisternaOne = (pulseIn(Echo, HIGH)/59)/0.13;
  }
  
  // Lectura de datos y respuesta:
  if(Serial.available()){
     caseTask = Serial.read();
  }
  switch(caseTask){
    case 'A':{
      statusCuarto1 = toggle(statusCuarto1);
      digitalWrite(ligthCuarto1,statusCuarto1);
      break;      
    }
    case 'B':{
      statusCuarto2 = toggle(statusCuarto2);
      digitalWrite(ligthCuarto2,statusCuarto2);
      break;      
    }
    case 'C':{
      statusBanio = toggle(statusBanio);
      digitalWrite(ligthBanio, statusBanio);
      break;      
    }
    case 'D':{
      statusCocina = toggle(statusCocina);
      digitalWrite(ligthCocina, statusCocina);
      break;      
    }
    case 'E':{
      statusComedor = toggle(statusComedor);
      digitalWrite(ligthComedor, statusComedor);
      break;      
    }
    case 'F':{
      statusSala = toggle(statusSala);
      digitalWrite(ligthSala, statusSala);
      break;      
    }
  }
}