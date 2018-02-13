#define LED1 3

int status = 0; // 0 = on, -1 = off

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);
}


void loop() {
  status = ~status;
// status = status ^ 1;
  Serial.println(status);
  digitalWrite(LED1, status);
  delay(200);
}

