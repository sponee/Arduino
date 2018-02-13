int buttonPin = 2;
int ledPin = 3;
void setup()
{
 pinMode(buttonPin,INPUT);//set button as digital input
 pinMode(ledPin,OUTPUT);//as buzzer as digital output
}
void loop()
{
 if(digitalRead(buttonPin))//check button is pressed or not
 {
 digitalWrite(ledPin,HIGH);//pressed，then buzzer buzzes
 }
 else
 {
 digitalWrite(ledPin, LOW);//not pressed，then buzzer remains silent
 }
} 
