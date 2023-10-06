#define LED   2
void setup() {
  // put your setup code here, to run once:
  // to set this pin as output 
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // to turn the led on
  digitalWrite(LED, HIGH);

// delay the led
  delay(1000);
// to turn off the led
  digitalWrite(LED,LOW);
// delay the led
  delay(1000);
}
