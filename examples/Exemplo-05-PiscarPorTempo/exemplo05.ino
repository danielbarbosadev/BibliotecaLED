/**
 * *Exemplo 05 - LED Piscar Por Tempo
 * 
 ** Esse programa vai fazer com que o LED pisque um tempo determinado de 1 Hz.
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);

void setup() 
{
  ledExample.piscar(4);
}

void loop()
{   
    ledExample.update();
}
