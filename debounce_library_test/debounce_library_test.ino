#include <Servo.h>
#include <HashMap.h>
#include <Bounce2.h>
#define BUTTON1 2
#define BUTTON2 9
String guess = "";
const byte HASH_SIZE = 5; 
HashType<int,char*> hashRawArray[HASH_SIZE]; 
HashMap<int,char*> hashMap = HashMap<int,char*>( hashRawArray , HASH_SIZE );

Servo myfirstservo;  // create servo object to control a servo
Servo mysecondservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 

// Instantiate another Bounce object
Bounce debouncer2 = Bounce(); 

void setup() {
  Serial.begin(9600);
  myfirstservo.attach(8);  // attaches the servo on pin 9 to the servo object
  mysecondservo.attach(7);
  debouncer1.attach(BUTTON1);
  debouncer1.interval(5); // interval in ms
  debouncer2.attach(BUTTON2);
  debouncer2.interval(5); // interval in ms
  hashMap[0](0,"AB");
  hashMap[1](1,"BA");
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() {

  int status1;
  int status2;
  int i = 0;
  
  // Update the Bounce instances :
  debouncer1.update();
  debouncer2.update();

  // Get the updated value :
  status1 = debouncer1.read();
  status2 = debouncer2.read();

if( debouncer1.rose() )
  {
    guess = String(guess + "A");
    Serial.println(guess);
  }
  if( debouncer2.rose() )
  {
    guess = String(guess + "B");
    Serial.println(guess);
  }
  if (guess.length() >= 2)
  {
    for (i = 0; i <= 1; i += 1) {
      if (guess == hashMap.getValueOf(i)) {
        Serial.println(guess);
        Serial.println(i);
        Serial.println("Value of I:");
        Serial.println(hashMap.getValueOf(i));
        for (pos = 0; pos <= 45; pos += 45) { 
          myfirstservo.write(pos);
          mysecondservo.write(180-pos);
          delay(350);                       // waits 15ms for the servo to reach the position
          hashMap[i](-2,"smoked");
        }
        for (pos = 90; pos <= 45; pos += 45) { // goes from 90 degrees to 45 degrees
          myfirstservo.write(pos);              // tell servo to go to position in variable 'pos'
          mysecondservo.write(180-pos);
          guess = "";
        }
        break;
      }
    }
    guess = "";
  }
}
