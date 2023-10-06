#define BLYNK_TEMPLATE_ID "TMPLYbKtsTxW"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "8Hsi6SDtbUKhVHKxf5_0F7knS6ucDd0N"

#define BLYNK_PRINT Serial


#include<SPI.h>
#include<Ethernet.h>
#include<BlynkSimpleEthernet>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

#include"main.h"
#include"tempertature_system.h"
#include"ldr.h"
#include"serial_tank.h"

char auth[] = BLYNK_AUTH_TOKEN;
bool heater_sw,inlet_sw,outlet_sw;
unsigned int tank_volume;


void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
