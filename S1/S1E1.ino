void setup() {
  /* Es un comentario */
  // Configurar a las 4 salidas digitales.
  //(1)  - Conf. los pin 8-11 como salida
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
    
 //(2) - Conf. los 12 y 13 como entrada
  pinMode(12, INPUT);
  pinMode(13, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  
  delay(500);
   digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  
    delay(500);
   digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
    delay(500);
   digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(500);
  
  
}
