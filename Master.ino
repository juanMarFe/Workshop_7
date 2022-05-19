#include "Wire.h"

const byte I2C_SLAVE_ADDR = 0x20;

long data = 100;
long response = 0;

int ledPin = 13;

void setup()
{
   Serial.begin(115200);
   Wire.begin();
   pinMode(ledPin,OUTPUT);
}

void loop()
{
   requestToSlave();
   delay(2000);
    
}


void requestToSlave()
{
   response = 0;
   Wire.requestFrom(I2C_SLAVE_ADDR, sizeof(response));
   uint8_t index = 0;
   byte* pointer = (byte*)&response;
   while (Wire.available())
   {
      *(pointer + index) = (byte)Wire.read();
      index++;
   }
   Serial.println(response);
   
  if(response >= 22){
    digitalWrite(ledPin, 1);
   }
   else{
    digitalWrite(ledPin, 0);
    }
  
   

   Serial.println(response);
}
