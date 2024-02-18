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

byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {A0, A1, A2,A3};

 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );




void setup(){
  Serial.begin(9600); // Initialize serial communication
  lcd.begin(16,2);
  lcd.print("Press a key:"); // Initial message on the LCD
  
}
  
void loop() {
  char key = keypad.getKey(); // Read the pressed key

  if (key != NO_KEY) { // If a key is pressed
    int row, col;
    getCoordinates(key, row, col); // Get the coordinates of the pressed key
    lcd.clear(); // Clear the LCD display
    lcd.setCursor(0, 0); // Set cursor to the first line
    lcd.print("Key: ");
    lcd.print(key);
    lcd.setCursor(0, 1); // Set cursor to the second line
    lcd.print("Row: ");
    lcd.print(row);
    lcd.print(", Col: ");
    lcd.print(col);
    Serial.print("Pressed key: ");
    Serial.print(key);
    Serial.print(" Row: ");
    Serial.print(row);
    Serial.print(" Column: ");
    Serial.println(col);
  }
}

// Function to get the coordinates of the pressed key
void getCoordinates(char key, int &row, int &col) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (keys[i][j] == key) {
        row = i + 1; // Rows and columns are indexed from 1
        col = j + 1;
        return;
      }
    }
  }
  // If key not found, return -1 for both row and column
  row = -1;
  col = -1;
}
  
