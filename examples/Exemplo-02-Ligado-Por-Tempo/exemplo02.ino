/**
 * *Exemplo 02 - LED Ligar por Tempo
 * 
 ** Esse programa vai fazer com que o LED ascenda e permaneça ligado até um determinado tempo em milissegundos(ms).
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);
void setup() 
{
  ledExample.ligar(5000); // 5000 milissegundos = 5 segundos.
}

void loop()
{   
    ledExample.update();
}