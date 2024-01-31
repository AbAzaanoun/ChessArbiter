#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {' ','0','=','+'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1,0}; 
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.begin(16,2);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    lcd.print(key);
  }
}
