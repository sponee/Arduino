#define LED1 3

char value=128;
// What is pulse-width modulation (PWM)?

// ----|_____|-----|_____

void setup() {
  pinMode(LED1, OUTPUT);

}

void loop() {
  analogWrite(LED1, value);
  value --;
  delay(10);
}
