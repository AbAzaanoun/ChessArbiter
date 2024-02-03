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


int digits_counter = 0;
bool lcd_line = 0;

void setup(){

  lcd.begin(16,2);

}
  
void loop(){
  char key = keypad.getKey();

  if (key){
    digits_counter++;
    if (digits_counter > 15){
      lcd_line = !lcd_line;
      digits_counter = 0; 
    }
    lcd.print(key);
    lcd.setCursor(digits_counter,lcd_line);
    key = "";
  }

}

