#include <Wire.h>
#include "rgb_lcd.h"

#define BUTTON1 3

int previous;
int read;
char Str4[ ] = "arduino";

char* myStrings[]={"This is string 1", "This is string 2", "This is string 3",
"This is string 4", "This is string 5","This is string 6"};

rgb_lcd lcd;

void setup(){
    Serial.begin(9600);
    pinMode(BUTTON1, INPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // initialize the serial communications:
    Serial.begin(9600);
}

void loop()
{
  lcd.print(myStrings[0]);
  delay(500);
  //lcd.print(Str4);
  int status;
  status = digitalRead(BUTTON1);
  if(status == HIGH)
  {
    read = ~read;
    //digitalWrite(LED1, read);
    Serial.println(read);
    previous = read;
    Serial.print("Previous:");
    Serial.println(previous);
    delay(10);
  }
  if(status == LOW)
  {
    //digitalWrite(LED1, previous);
    Serial.print("Previous:");
    Serial.println(previous);
  }
}
