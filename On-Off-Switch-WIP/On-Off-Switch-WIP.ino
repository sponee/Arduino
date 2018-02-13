// Handling input
#define BUTTON1 2
#define LED1 3
int previous;
int read;

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
    read = ~read;
    digitalWrite(LED1, read);
    Serial.println(read);
    previous = read;
    Serial.print("Previous:");
    Serial.println(previous);
    delay(10);
  }
  if(status == LOW)
  {
    digitalWrite(LED1, previous);
    Serial.print("Previous:");
    Serial.println(previous);
  }
}
