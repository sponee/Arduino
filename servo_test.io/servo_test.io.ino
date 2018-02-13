#include <Servo.h>
#define BUTTON1 2
#define BUTTON2 9
String kyle = "AB";
String guess = "";

Servo myfirstservo;  // create servo object to control a servo
Servo mysecondservo;
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
int AB = 2; // the number of blunts kyle can smoke

void setup() {
  myfirstservo.attach(8);  // attaches the servo on pin 9 to the servo object
  mysecondservo.attach(7);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  myfirstservo.write(pos);
  mysecondservo.write(pos);
}

void loop() {
  int status1;
  int status2;
  status1 = digitalRead(BUTTON1);
  status2 = digitalRead(BUTTON2);
  if(status1 == HIGH)
  {
    guess = String(guess + "A");
  }
  if(status2 == HIGH)
  {
    guess = String(guess + "B");
  }
  if (guess.length() == 2 && guess == "AB" && AB >= 1)
    {
      for (pos = 0; pos <= 45; pos += 45) { // goes from 0 degrees to 90 degrees
      // in steps of 1 degree
      myfirstservo.write(pos);              // tell servo to go to position in variable 'pos'
      mysecondservo.write(pos);
      delay(350);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 90; pos <= 45; pos += 45) { // goes from 90 degrees to 0 degrees
      myfirstservo.write(pos);              // tell servo to go to position in variable 'pos'
      mysecondservo.write(pos);
    }
    guess = "";
    AB --;
  }
  if (guess.length() == 2 && guess != "AB")
  {
    guess = "";
  }
}

