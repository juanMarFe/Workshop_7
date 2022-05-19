//Importe de la libreria 2Wire

#include "Wire.h"
// Declaracion de la variable que identifica al esclavo con el id 0x20
const byte I2C_SLAVE_ADDR = 0x20;

// Declaracion de respuesta que se obtiene del esclavo
long response = 0;
// Declaración del pin para prender el led
int ledPin = 13;

void setup()
{
   Serial.begin(115200);
   Wire.begin();
   pinMode(ledPin,OUTPUT);
}

//Loop que realiza la verificación de la temperatura cada 2 segundos
void loop()
{
   requestToSlave();
   delay(2000);
    
}

// Metodo que pide la información del sensor al esclavo
void requestToSlave()
{
   //Variables de respuesta que obtienen el mensaje del sensor
   response = 0;
   Wire.requestFrom(I2C_SLAVE_ADDR, sizeof(response));
   uint8_t index = 0;
   byte* pointer = (byte*)&response;
   while (Wire.available())
   {
      //Con Wire.read se lee la temperatura del sensor luego de llamarlo con el método Wire.requestFrom
      *(pointer + index) = (byte)Wire.read();
      index++;
   }
   Serial.println(response);
   
   // Cambio de temperatura por medio del condicional if que verifica su temperatura para saber si el led debe estar prendido o apagado
  if(response >= 22){
    digitalWrite(ledPin, 1);
   }
   else{
    digitalWrite(ledPin, 0);
    }
  
}
