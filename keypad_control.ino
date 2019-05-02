// https://www.tinkercad.com/things/gCTcvtGkeN8
// s'utilitza un keypad per introduir un password d'un caràcter
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
int pinR = 3;
int pinG = 2;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3','A'},
  {'4', '5', '6','B'},
  {'7', '8', '9','C'},
  {'*', '0', '#','D'}
};

char reference = 'B';
byte rowPins[ROWS] = {12, 11, 10, 9}; 
byte colPins[COLS] = {8, 7, 6, 5}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  digitalWrite(pinR, HIGH);
  digitalWrite(pinG, HIGH);
  delay(500);
  
}
  
void loop(){
  char customKey = customKeypad.getKey();
  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  delay(100);
  if (customKey != NO_KEY)
  {
    if (customKey == reference)
    {
      Serial.print(customkey);
      Serial.print(" > ");
      Serial.println("OK!");
      digitalWrite(pinG, HIGH);
      delay(500);
    }
    else
    {
      Serial.print(customkey);
      Serial.print(" > ");
      Serial.println("Warning!!");
      digitalWrite(pinR, HIGH);
      delay(500);
    }
  }
  
}
