unsigned int var1 = 1231;  //2 bytes
int var3 = -12321;  //2 bytes
char var4 = 'x';  //1 byte
char dato_recibido = 0;  //Variable que guardara el byte recibido por serial
unsigned char temporal = 0;

void setup(void){
  Serial.begin(9600);
 // Serial.println("HeTPro");
}

void loop(void){
 // Serial.println("Test serial"); //cuantas veces se imprimira este texto???    R. 1 sola vez
   //Porque?: Despues de esta instrucción viene un ciclo for infinito....
  for(;;){
    if(Serial.available() == 1){
     dato_recibido = Serial.read(); 
      switch(dato_recibido){
       case 'A':  Serial.write(var1);   Serial.write((unsigned int)var1>>8);    break;
       case 'C':   Serial.write(var3); Serial.write((unsigned int) var3>>8);     break;
       case 'D':   Serial.write(var4);    break;
       case 'B':  Serial.println("Gracias por usar nuestor administrador serial"); break;
       default:  Serial.println("Error 5202"); 
      }
      if(dato_recibido == 'B') break;
      
    }
  }
  for(;;);  //Pausa infinita
  while(1); //Es lo mismo que la anterior


}


