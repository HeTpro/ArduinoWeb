double variable = 13.2;


void setup(void){
 pinMode(8, OUTPUT);
 pinMode(13, INPUT_PULLUP); 
  Serial.begin(9600);
  Serial.println("HETPRO");
  Serial.print("HOLA");
  Serial.print(" QUE TAL");
  Serial.write(64);
  
}

void loop(void){
  Serial.println(digitalRead(13));
  Serial.println(variable);
  delay(1000);
  
}
