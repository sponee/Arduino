/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define BUTTON1 2
#define BUTTON2 9
String kyle = "AB";
String guess = "";

Servo myfirstservo;  // create servo object to control a servo
Servo mysecondservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position
int AB = 2; // the number of blunts kyle can smoke

void setup() {
  myfirstservo.attach(8);  // attaches the servo on pin 9 to the servo object
  mysecondservo.attach(9);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() {
  int status1;
  int status2;
  status1 = digitalRead(BUTTON1);
  status2 = digitalRead(BUTTON2);
  if(status1 == HIGH)
  {
    guess =  String(guess + "A");
  }
  if(status2 == HIGH)
  {
    guess =  String(guess + "B");
  }
  if (guess.length() == 2 && guess.equals("AB"))
  {
    for (pos1 = 0; pos1 <= 90; pos1 += 1) { // goes from 0 degrees to 90 degrees
      // in steps of 1 degree
      for (pos2 = 0; pos2 <= 90; pos2 += 1) { // goes from 0 degrees to 90 degrees
      myfirstservo.write(pos1);              // tell servo to go to position in variable 'pos'
      mysecondservo.write(pos2);              // tell servo to go to position in variable 'pos'
      delay(350);                       // waits 15ms for the servo to reach the position
    }
    for (pos1 = 90; pos1 <= 90; pos1 += 1) { // goes from 90 degrees to 0 degrees
       for (pos2 = 90; pos2 <= 90; pos2 += 1) { // goes from 90 degrees to 0 degrees
    }
      myfirstservo.write(pos1);              // tell servo to go to position in variable 'pos'
      mysecondservo.write(pos2);              // tell servo to go to position in variable 'pos'
    }
    guess = "";
  }
  if (guess.length() == 2 && guess != "AB")
  {
    guess = "";
  }
  }
}
