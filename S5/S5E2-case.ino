#include<LiquidCrystal.h>

char dato=0; //Usa para guardar el dato de la comunicaciòn serial
int boton=0; //En des-uso
int tono = 30; //Guarda, la frecuencia, del tono que se escuchara
int estadoB1 = 0; //Guarda el estado logico del b1
int estadoB2 = 0; //Guarda el estado logico del b2
int i = 0; //Se usa dentro de los ciclos for del programa
int temporal=0;
//LiquidCrystal lcd(RS, ENABLE, DB4, DB5, DB6, DB7);
LiquidCrystal lcd(11,10, 9, 4, 5, 6, 7);
//B1 - 8
//B2 - 2
//Buzzer - 3

void setup(void){
   lcd.begin(16,2);
   lcd.print("Hola, Mundo");
   Serial.begin(9600);
   pinMode(3,OUTPUT); //BUZZER
   pinMode(8,INPUT_PULLUP); //b1
   pinMode(2, INPUT_PULLUP); //b2
}

void loop(void){
    lcd.setCursor(14,0);
    lcd.print("h");
    Serial.println("Inicio Etapa 1");
    for(;;){
      lcd.setCursor(0,1);
      lcd.print(analogRead(A0)); 
      lcd.setCursor(4,1);
      lcd.print(" a0");
      if(Serial.available() == 1);
      {
       dato = Serial.read();
       if(dato == 'A') {
           break;
       }
      }
      //delay(500);
    }
     Serial.println("fIN Etapa 1");
      Serial.println("Inicio Etapa 2");
    for(;;){
      estadoB1 = digitalRead(8);
      estadoB2 = digitalRead(2);
      //if( estadoB1 == 0 && estadoB2 == 0)  tono = 30;
      //else if (estadoB1 == 0 && estadoB2 == 1) tono = 50;
      //else if (estadoB1 == 1 && estadoB2 == 0) tono = 100;
      //else tono = 1915;
      
      temporal = estadoB2*2+estadoB1*1;
      //temporal = EBN*2^n+EBN-1+2^(n-1)...EB3*4+EB2*2+EB1*1;
      // EB1 = 0, EB2 = 0, temporal = 0
      // EB1 = 0, EB2 = 1, temporal = 1
      // EB1 = 1, EB2 = 0, temporal = 2
      // EB1 = 1, EB1 = 1, temporal = 3
      switch(temporal){
        case 0: tono = 30;
        case 1: tono = 80;
        case 2: tono = 100;
        case 3: tono = 1915;
        default: tono=30;
        }
      for(i = 0 ; i<100; i++){
        
        ///Inicio
        digitalWrite(3, HIGH);
        delayMicroseconds(tono);
        digitalWrite(3,LOW);
        delayMicroseconds(tono);
        //PWM digital
        //fin
        
      }
      delay(250);
      
    }
}
