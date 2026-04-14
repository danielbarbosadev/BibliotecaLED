#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led
{
private:
    uint8_t pinLed;
    bool estado;

    uint32_t tempoDeterminadoParaDesligar;
    bool desligadoNoMomento = true;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    uint16_t repeticoes;
    bool estadoPiscar;

    void funcaoPiscar();
    void funcaoDesligamento();
    

public:
    Led(uint8_t pinLed); // Método Construtor, deverá ter o mesmo nome da Classe

    void ligar(); //! OK
    void ligar(uint32_t tempoLigado_ms); //! OK

    void desligar(); //! OK

    void piscar(); //! OK
    void piscar(float frequencia); //!OK
    void piscar(float frequencia, uint16_t repeticoes); //! OK

    bool getEstado();  //! OK
    uint8_t getPino(); //! OK

    void setEstado(bool estado);

    void alternar(); //! OK

    void update(); //! OK
};
#endif