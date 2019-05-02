// https://www.tinkercad.com/things/5Ttlgoy8axD
// From http://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/

#include <Keypad.h>
#include <Servo.h>

int portaPin = 11;
int pinR = 13;
int pinG = 12;


String inputCode = ""; 
String Master = "123A456"; 
int pswdLen = Master.length();
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);  
Servo porta;

void setup(){
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(portaPin, OUTPUT);
  porta.attach(portaPin);
  porta.write(0);
}

void loop(){

  customKey = customKeypad.getKey();
  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  
  if (customKey)
  {
    inputCode = inputCode + customKey; 
    data_count++; 
    Serial.print(customKey);
  }

  if(data_count == pswdLen){
    Serial.println(' ');
    if(inputCode == Master)
    {
 	  Serial.println("Password correcte");
      digitalWrite(pinG, HIGH);

	  porta.write(180);
      delay(1000);
      porta.write(0);
 
    }
    else
    {
      Serial.println("Password erroni");
      digitalWrite(pinR, HIGH);
      delay(1000);
     }    
    clearData(); 
  }
}

void clearData(){
  Data = "";
  data_count = 0;
  return;
}
