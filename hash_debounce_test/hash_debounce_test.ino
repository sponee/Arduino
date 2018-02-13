#include <Servo.h>
#include <HashMap.h>
#define BUTTON1 2
#define BUTTON2 9
String kyle = "AB";
String guess = "";
const byte HASH_SIZE = 5; 
HashType<int,char*> hashRawArray[HASH_SIZE]; 
HashMap<int,char*> hashMap = HashMap<int,char*>( hashRawArray , HASH_SIZE );

Servo myfirstservo;  // create servo object to control a servo
Servo mysecondservo;

int buttonState1;
int buttonState2;      // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin
int lastButtonState2 = LOW;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime1 = 0;  // the last time the output pin was toggled
long lastDebounceTime2 = 0;
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myfirstservo.attach(8);  // attaches the servo on pin 9 to the servo object
  mysecondservo.attach(7);
  hashMap[0](0,"AA");
  hashMap[1](1,"BB");
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() {
//  int status2;
  int i = 0;
int reading1 = digitalRead(BUTTON1);
//  status2 = digitalRead(BUTTON2);

if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
    Serial.println("Reset button 1 timer");
  }

if (((millis() - lastDebounceTime1) > debounceDelay)) {

  if (reading1 != buttonState1) {
      buttonState1 = reading1;

      if (buttonState1 = HIGH)
      {
      guess = String(guess + "A");
      Serial.println(guess);

      lastButtonState1 = reading1;
      }

  /*if( status1 == HIGH )
    {
      guess = String(guess + "A");
      lastDebounceTime1 = millis();
      lastButtonState1 = status1;
      Serial.println(guess);
    }
    if( status2 == HIGH)
    {
      guess = String(guess + "B");
      lastDebounceTime2 = millis();
      lastButtonState2 = status2;
      Serial.println(guess);
    }
    */
    if (guess.length() >= 2)
    {
      for (i = -1; i <= 1; i += 1) {
        //Serial.println(guess);
        if (guess == hashMap.getValueOf(i)) {
          Serial.println("Value of I:");
          Serial.println(hashMap.getValueOf(i));
          for (pos = 0; pos <= 45; pos += 45) { 
            myfirstservo.write(pos);
            mysecondservo.write(180-pos);
            delay(350);                       // waits 15ms for the servo to reach the position
          }
          for (pos = 90; pos <= 45; pos += 45) { // goes from 90 degrees to 45 degrees
            myfirstservo.write(pos);              // tell servo to go to position in variable 'pos'
            mysecondservo.write(180-pos);
            guess = "";
          }
        }
      }
      guess = "";
    }
  }
}
}
