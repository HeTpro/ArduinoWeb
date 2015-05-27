
#define PinTrigger 12
#define PinEco 13

void setup() {
  Serial.begin (9600);
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinEco, INPUT);
}

void loop() {
  int duracion, distancia;
  for(;;){
    digitalWrite(PinTrigger, HIGH);          //Generamos el pulso de trigger
    delayMicroseconds(1000);
    digitalWrite(PinTrigger, LOW);
    duracion = pulseIn(PinEco, HIGH);    //Esperamos el pulso y medimos el tiempo que dura en uS
    distancia = (duracion/58);       //Dividimos entre 58 segun el fabricante 
  
    if (distancia >= 255 || distancia <= 0){
        Serial.println("error");
      }
    else {
        Serial.println(distancia);
      }
    delay(10);
  }
}
