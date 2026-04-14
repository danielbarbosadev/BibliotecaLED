#include "LED.h"

Led::Led(uint8_t pinLed) :
    pinLed(pinLed),
    estado(LOW),
    desligadoNoMomento(true),
    tempoDeterminadoParaDesligar(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)
{
    pinMode(pinLed, OUTPUT);
}

void Led::ligar()
{
    estado = HIGH;
    estadoPiscar = false;
}

void Led::ligar(uint32_t tempoLigado_ms)  
{
    estado = HIGH;                                             
    desligadoNoMomento = false;                                
    tempoDeterminadoParaDesligar = millis() + tempoLigado_ms; 
    estadoPiscar = false;
}

void Led::desligar()
{
    estado = LOW;
    estadoPiscar = false;
}

void Led::funcaoDesligamento()
{
    if (millis() >= tempoDeterminadoParaDesligar)     
        {
            estado = LOW;                             
            desligadoNoMomento = true;                
        }
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligadoNoMomento = true;
}

void Led::piscar(float frequencia)
{
    
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligadoNoMomento = true;
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    estadoPiscar = true;
    tempoEspera = (1.0f / (2.0f * frequencia)) * 1000.0f;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
    desligadoNoMomento = true;
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();

        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led::alternar()
{
    estado = !estado;
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pinLed;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    estadoPiscar = false;
    desligadoNoMomento = true;
}

void Led::update()
{
       
    if (!desligadoNoMomento) funcaoDesligamento();                         
        
    if (estadoPiscar) funcaoPiscar();

    digitalWrite(pinLed, estado);
}