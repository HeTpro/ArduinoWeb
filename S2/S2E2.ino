void setup(void){
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 
 pinMode(13, INPUT_PULLUP);
 pinMode(12, INPUT_PULLUP);
 
 Serial.begin(9600);
  
}

void loop(void)
{
 Serial.println("Bienvenido");
 while(1){
  if(digitalRead(13) == HIGH && digitalRead(12) == HIGH){
    Serial.println("Mensaje1");
  }
  else{
    Serial.println("Mensaje2");
  }
  
 } 
 
}

