/**
 * *Exemplo 01 - LED Ligar
 * 
 ** Esse programa vai fazer com que o LED ascenda e permaneça ligado continuamente. 
 */

#include <Arduino.h>
#include <LED.h>

Led ledExample(20);

void setup() 
{
  ledExample.ligar();
}

void loop()
{   
    ledExample.update();
}