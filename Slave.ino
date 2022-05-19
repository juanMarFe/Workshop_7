#include "Wire.h"

const byte I2C_SLAVE_ADDR = 0x20;

void setup()
{
   Serial.begin(115200);
   pinMode(A0,INPUT);
   Wire.begin(I2C_SLAVE_ADDR);
   Wire.onReceive(receiveEvent);
   Wire.onRequest(requestEvent);
}

long data = 0;
//long response = 200;


void receiveEvent(int bytes)
{
   data = 0;
   uint8_t index = 0;
   while (Wire.available())
   {
      byte* pointer = (byte*)&data;
      *(pointer + index) = (byte)Wire.read();
      index++;
   }
}

void requestEvent()
{
  float i = (float)analogRead(A0);
  float y = (i*5000/1023)/10;
  Serial.println((int)y);
  long p=(long)y;
  Wire.write((byte*)&p, sizeof(p));
}


void loop() {
}
