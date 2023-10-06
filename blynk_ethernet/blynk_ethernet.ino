#define BLYNK_TEMPLATE_ID "TMPLYbKtsTxW"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "8Hsi6SDtbUKhVHKxf5_0F7knS6ucDd0N"

#include<SPI.h>
#include<Ethernet.h>
#include<BlynkSimpleEthernet.h>

#define LED 2

char auth[] = BLYNK_AUTH_TOKEN;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
 if(value)
 {
   digitalWrite(LED,1);
 }
 else{
   digitalWrite(LED,0);
 }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);

  Blynk.begin(auth);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();

}
