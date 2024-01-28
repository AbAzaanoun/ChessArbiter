#include <Keypad.h>

const byte ROWS = 4; // Nombre de lignes du clavier matriciel
const byte COLS = 4; // Nombre de colonnes du clavier matriciel

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Broches connectées aux lignes du clavier
byte colPins[COLS] = {5, 4, 3, 2}; // Broches connectées aux colonnes du clavier

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char startPosition = '\0'; // Position de départ initiale
char endPosition = '\0'; // Position d'arrivée initiale

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    Serial.println(key); // Afficher la touche appuyée sur le moniteur série
    
    if (startPosition == '\0') {
      // Si la position de départ n'a pas encore été définie, définissez-la
      startPosition = key;
      Serial.print("Position de départ : ");
      Serial.println(startPosition);
    } 
    else if (endPosition == '\0') {
      // Si la position de départ a été définie mais pas la position d'arrivée, définissez-la
      endPosition = key;
      Serial.print("Position d'arrivée : ");
      Serial.println(endPosition);
      
      // Réinitialiser les positions après avoir enregistré la position d'arrivée
      startPosition = '\0';
      endPosition = '\0';
    }
  }
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
