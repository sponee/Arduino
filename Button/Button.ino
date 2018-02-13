// Handling input
#define BUTTON1 8
#define LED1 3

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  int calibrationVal = 17;
}

void loop() {
  int status;
  status = digitalRead(BUTTON1);
  if(status == HIGH)
  {
    digitalWrite(LED1, status);

    Serial.print("Button is pressed.");
  }
  if(status == LOW)
  {
    digitalWrite(LED1, status);
  }
}
