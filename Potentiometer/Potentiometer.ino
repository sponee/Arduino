#define POT1 A0
#define LED1 3

int aValue;
char LEDValue;

void setup() {
  pinMode(LED1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  aValue = analogRead(POT1);
  LEDValue = aValue/4;
  Serial.print("POT1: ");
  Serial.println(aValue);
  analogWrite(LED1, LEDValue);
}
