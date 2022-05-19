//Importe de la libreria de I2C
#include "Wire.h"

// Identificador de esclavo
const byte I2C_SLAVE_ADDR = 0x20;

void setup()
{
   Serial.begin(115200);
   // Inicialización del pin en el que se encuentra el sensor
   pinMode(A0,INPUT);
   // Inicialización del metodo identificador de esclavo
   Wire.begin(I2C_SLAVE_ADDR);
   // Indicador de metodo a utilizar en caso de que el maestro lo necesite
   Wire.onRequest(requestEvent);
}

//Metodo que lee el sensor en el momento que el maestro lo indica
void requestEvent()
{
   //Lectura del Sensor
  float i = (float)analogRead(A0);
   
////////////////////////////////////////////////////////////////////////////////
   
  //Cambio de los bytes dados por el sensor a la temperatura en celcius
  
  float y = (i*5000/1023)/10;
  Serial.println((int)y);
  long p=(long)y;
   
////////////////////////////////////////////////////////////////////////////////
   
  //Envio de información al Maestro
  Wire.write((byte*)&p, sizeof(p));
}


void loop() {
}
