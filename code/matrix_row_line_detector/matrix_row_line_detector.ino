#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; // Number of rows in the keypad
const byte COLS = 4; // Number of columns in the keypad

// Define the keypad layout
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Define the row and column pins
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {A3, A2, A1, A0};

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* Display */
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  Serial.begin(9600); // Initialize serial communication
  lcd.begin(16, 2);    // Initialize the LCD with 16 columns and 2 rows
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
