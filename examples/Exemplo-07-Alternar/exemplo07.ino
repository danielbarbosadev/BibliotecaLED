/**
 * *Exemplo 07 - LED ALternar
 * 
 ** Esse programa vai fazer com que cada vez que o usuário pressionar o botão o estado do LED vai ser alternado (0 ou 1), fazendo com que ele ligue ou desligue.
 * 
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);
const char pinBotaoExample = 0;

void funcaoBotaoApertado();

void setup() 
{
  Serial.begin(9600);
}

void loop()
{   
    ledExample.update();
    funcaoBotaoApertado();
}

void funcaoBotaoApertado()
{
    bool estadoAtualBotao = digitalRead(pinBotaoExample);
    static bool estadoAnteriorBotao = 1;

    if(!estadoAtualBotao && estadoAnteriorBotao)
    {
        ledExample.alternar();
    }
    estadoAnteriorBotao = estadoAtualBotao;
}