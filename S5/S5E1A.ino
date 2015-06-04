#include<LiquidCrystal.h>

//LiquidCrystal lcd(RS, ENABLE, DB4, DB5, DB6, DB7);
//LiquidCrystal lcd(RS, R/W, ENABLE, DB4, DB5, DB6, DB7);

LiquidCrystal lcd(11, 10, 9, 4, 5, 6, 7);

//LiquidCrystal lcd(11, 9, 4, 5, 6, 7);
void setup(void){
   lcd.begin(16,2);
   lcd.print("Hola, Mundo");
 
}

void loop(void){
     lcd.home();
     lcd.clear();
     lcd.print("ABCDEFGHIJKLMNOP");
     lcd.setCursor(0,1);
     lcd.print("QRSTUVWYXZ012345");
     delay(5000);
     lcd.setCursor(6,0);
     lcd.write('%');
     for(;;){
       
     }    
      
   
}
