#ifndef LED_h
#define LED_h

#include <Arduino.h>


/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, piscar continuamente e piscar por quantidade definida
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
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



    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();
    

public:
    /**
     * @brief Constroi um objeto Led.
     * @param pin Número do pino digitalWrite onde o LED está conectado.
     */
    Led(uint8_t pinLed); 

    /**
     * @brief Liga o LED continuamente.
     */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado_ms Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();

     /**
     * @brief Inicia a piscada contínua em 1 Hz.
     */
    void piscar(); 

     /**
     * @brief Inicia a piscada em um tempo determinado em Hz.
     * @param frequencia Frequênciada piscada do em Hz.
     */
    void piscar(float frequencia); 

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequênciada piscada do em Hz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes); 

    /**
     * @brief Retorna o valor do estado do LED.
     */
    bool getEstado();  

    /**
     * @brief Retorna o valor do pino do LED.
     */
    uint8_t getPino(); 

    /**
     * @brief Define o estado do LED.
     * @param estado true para ligado, false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief alterna o estado do LED.
     */
    void alternar(); 

     /**
     * @brief Atualiza o estado do LED, e deve ser chamado continuamente dentro do loop().
     */
    void update(); 
};
#endif