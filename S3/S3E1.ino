void setup(void){
 Serial.begin(9600);
  
}

void loop(void){
  Serial.println("Voltimetro digital");
  Serial.println("S3E1.ino");
  for(;;){
     Serial.println(analogRead(A0));
     delay(100); 
  }
  
}

