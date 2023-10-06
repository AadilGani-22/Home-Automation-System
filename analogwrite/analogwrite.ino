const int analog_LDR=A0;
const int LED = 3;
unsigned int inputVal=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  inputVal= analogRead(analog_LDR);
  inputVal=(1023-inputVal)/4;
  analogWrite(LED,inputVal);

  delay(100);
}
