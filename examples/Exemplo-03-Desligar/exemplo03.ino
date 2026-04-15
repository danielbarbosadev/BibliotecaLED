/**
 * *Exemplo 03 - LED Desligar
 * 
 ** Esse programa vai fazer com que o LED ascenda e permanece ligado
 * *até que o usuário pressione o botão, fazendo assim com que ele seja desligado.
 * 
 */

#include <Arduino.h>
#include <LED.h>


Led ledExample(20);
const char pinBotaoExample = 0;

void funcaoBotaoApertado();

void setup() 
{
  ledExample.ligar();
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
        ledExample.desligar();
    }
    estadoAnteriorBotao = estadoAtualBotao;
}

