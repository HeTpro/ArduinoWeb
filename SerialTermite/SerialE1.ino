unsigned int var1 = 43223;  //2 bytes
double var2 = 1231241.12111;  //cuantos bytes? 4 bytes - correcto!!!
int var3 = -12321;  //2 bytes
char var4 = 'x';  //1 byte
char dato_recibido = 0;  //Variable que guardara el byte recibido por serial
unsigned char temporal = 0;

void setup(void){
  Serial.begin(9600);
  Serial.println("HeTPro");
}

void loop(void){
  Serial.println("Test serial"); //cuantas veces se imprimira este texto???    R. 1 sola vez
   //Porque?: Despues de esta instrucción viene un ciclo for infinito....
  for(;;){
    if(Serial.available() == 1){
     dato_recibido = Serial.read(); 
      switch(dato_recibido){
       case 'A':   Serial.write(var1); Serial.write((unsigned char)var1>>8);    break;
       case 'B':  
                    temporal = var2;
                    Serial.write(temporal);
                    temporal = (unsigned int) var2 >> 8;   // A esto se le conoce como "casting", investigar "casting c++" for more information
                    Serial.write(temporal);
                    temporal = (unsigned int) var2 >> 16;
                    Serial.write(temporal); 
               break;
       case 'C':   Serial.write(var3); Serial.write((unsigned char) var3>>8);     break;
       case 'D':   Serial.write(var4);    break;
       case 'E':  Serial.println("Gracias por usar nuestor administrador serial"); break;
       default:  Serial.println("Error 5202"); 
      }
      if(dato_recibido == 'E') break;
      
    }
  }
  for(;;);  //Pausa infinita
  while(1); //Es lo mismo que la anterior


}


//pREGUNTA:
// Cuantos bytes se requieren para transmitir la siguiente información: Serial.println("125625.232234");   R: 13 BYTES, 1 por cada aracter
//Pero, lo mas eficiente es enviar la variable, no su conversion a caracter, ya que la variable, por ejemplo var2, ocupa 4 bytes y representa praticamente la misma informacion. Pero esa informacion no se puede interpretar directamente. 
