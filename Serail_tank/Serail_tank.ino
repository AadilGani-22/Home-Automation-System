#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

  #define INLET_VALVE 0X00
  #define OUTLET_VALVE 0X01

 #define HIGH_FLOAT 0X10
 #define LOW_FLOAT 0X11


 #define VOLUME 0X30

   #define ENABLE 0X01
  #define DISABLE 0X00

  unsigned int value, valueL;
  unsigned char valueh=0,value1=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  lcd.setCursor(0,1);
  lcd.print("Connect Srtank");


  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);



}
char buff[6];

void volume(void)
{
  Serial.write(VOLUME);
  while(!Serial.available());
  valueh=Serial.read();
  while(!Serial.available());
  value1=Serial.read();
  value= (valueh<< 8)| value1;
  lcd.setCursor(0,1);
  lcd.print("v= ");
  lcd.print(value);
  lcd.print("1 ");
}
void filling_start(void)
{
   Serial.write(INLET_VALVE);

  
   Serial.write(ENABLE);
   Serial.write(OUTLET_VALVE);
   Serial.write(DISABLE);

   lcd.setCursor(0,0);
   lcd.print("Filling");

   do{
      Serial.write(HIGH_FLOAT);
      while(!Serial.available());
      valueL= Serial.read();
      volume();

   }while(valueL ==0);
}
void start_emptying(void)
{
  Serial.write(INLET_VALVE);

  
  Serial.write(ENABLE);
  Serial.write(OUTLET_VALVE);
  Serial.write(DISABLE);

  lcd.setCursor(0,0);
  lcd.print("Emptying");

  do{
      Serial.write(LOW_FLOAT);
      while(!Serial.available());
      valueL= Serial.read();
      volume();

  }while(valueL == 1);
}
void loop() {
  // put your main code here, to run repeatedly:
 filling_start();
 start_emptying();
}
