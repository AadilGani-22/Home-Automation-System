
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup(void) {
  // put your setup code here, to run once:
  // initiaze the led
  lcd.init();
  // turn the led
  lcd.backlight();
  // clear the clcd
  lcd.clear();
  // cursor to the home
  lcd.home();

  //to display string
  lcd.setCursor(0,0);
  lcd.print("ADC");


}

void loop(void) {
  // put your main code here, to run repeatedly:
  String temperature;

  temperature = String(((analogRead(A0) *(float)5/1024))/(float)0.01);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print(" deg cel");

  delay(1000);
}