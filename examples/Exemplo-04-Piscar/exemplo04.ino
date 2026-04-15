/**
 * *Exemplo 04 - LED Piscar
 * 
 ** Esse programa vai fazer com que o LED pisque um tempo determinado de 1 Hz.
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);

void setup() 
{
  ledExample.piscar();
}

void loop()
{   
    ledExample.update();
}