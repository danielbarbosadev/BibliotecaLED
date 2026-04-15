/**
 * *Exemplo 06 - LED Piscar por Tempo e Repetições
 * 
 ** Esse programa vai fazer com que o LED pisque em uma determinado frequência em Hz em uma determinada quantidade de vezes.
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);

void setup() 
{
  ledExample.piscar(2,10);
}

void loop()
{   
    ledExample.update();
}