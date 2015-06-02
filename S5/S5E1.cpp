#include<LiquidCrystal.h>

//LiquidCrystal lcd(RS, ENABLE, DB4, DB5, DB6, DB7);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(void){
   lcd.begin(16,2);
   lcd.print("Hola, Mundo");
 
}

void loop(void){
    lcd.setCursor(14,0);
    lcd.print("h");
    for(;;){
      lcd.setCursor(0,1);
      lcd.print(analogRead(A0)); 
      lcd.setCursor(4,1);
      lcd.print(" a0");
      
      delay(500);
    }
}
