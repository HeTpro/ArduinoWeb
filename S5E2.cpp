#include<LiquidCrystal.h>

char dato=0;
int boton=0;
int tono = 30;
int estadoB1 = 0;
int estadoB2 = 0;
int i = 0;

//LiquidCrystal lcd(RS, ENABLE, DB4, DB5, DB6, DB7);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(void){
   lcd.begin(16,2);
   lcd.print("Hola, Mundo");
   Serial.begin(9600);
   pinMode(11,OUTPUT);
    pinMode(12,INPUT_PULLUP);
   pinMode(13, INPUT_PULLUP); 
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
      estadoB1 = digitalRead(12);
      estadoB2 = digitalRead(13);
      if( estadoB1 == 0 && estadoB2 == 0)  tono = 30;
      else if (estadoB1 == 0 && estadoB2 == 1) tono = 50;
      else if (estadoB1 == 1 && estadoB2 == 0) tono = 100;
      else tono = 150;
      for(i = 0 ; i<100; i++){
        digitalWrite(11, HIGH);
        delayMicroseconds(tono);
        digitalWrite(11,LOW);
        delayMicroseconds(tono);
        
      }
      //delay(250);
      
    }
}

