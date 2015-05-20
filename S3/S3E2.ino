char dato_recibido = 0;
int i = 0;


void setup(void){
 pinMode(8, OUTPUT);
 pinMode(13, INPUT_PULLUP);
 
 Serial.begin(9600);
  
}

void loop(void){
  Serial.println("Voltimetro digital");
  Serial.println("S3E1.ino");
  for(;;){
    if(Serial.available() == 1)
    {
        dato_recibido = Serial.read();
        if(dato_recibido == 'A'){
        if(13 == LOW){
           analogWrite(8, 127);
        }
        else{
          for(i=0; i<255; i++){
           analogWrite(8,i); 
          }
          
        }
        }
        else{
          Serial.println("Error en dato enviado, favor de escribir una A");
        }
    }
     
  }
  
}
