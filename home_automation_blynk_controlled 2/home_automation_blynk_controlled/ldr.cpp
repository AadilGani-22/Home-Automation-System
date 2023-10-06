#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);  
}
unsigned int input_value=0;

void brightness_control(void)
{
  // read the LDR values
   input_value= analogRead(LDR_SENSOR);
   // reverse map from 0 to 1023 to 255 to 0
   input_value=(1023-input_value)/4;
   analogWrite(GARDEN_LIGHT,input_value);
   delay(100);
}
