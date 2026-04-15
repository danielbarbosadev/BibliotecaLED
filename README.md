# BibliotecaLED

Esta biblioteca foi desenvolvida para otimizar o controle de LEDs em sistemas embarcados. Ela abstrai a manipulação direta de portas digitais e oferece uma interface de alto nível para gerenciamento de estados e temporização. O principal diferencial é sua arquitetura **não-bloqueante**, que utiliza o contador interno do hardware para executar múltiplas tarefas sem interromper o fluxo principal do programa.

## 🚀 Funcionalidades

**Interface de Estado:** Métodos diretos para ligar, desligar e alternar o estado lógico do pino.

**Temporização Nativa:** Permite acionar o LED por um período determinado, com desligamento automático gerenciado pela biblioteca.

**Controle por Frequência:** Suporte para definição de ciclos de piscada em Hz.

**Modo de Repetição:** Executa uma quantidade específica de ciclos de piscada e encerra a operação automaticamente.

**Operação Assíncrona:** Substitui o uso de `delay()` por lógica baseada em `millis()`, permitindo o controle de múltiplos LEDs em paralelo.

## 📝 Implementação e Lógica

1.  **Instanciação:** Cada LED é tratado como um objeto, vinculando o pino de saída diretamente na criação.
2.  **Ciclo de Atualização:** A função `update()` deve ser inserida no `loop()` principal. Ela processa a pilha de tempo e atualiza o estado físico do pino apenas quando necessário.
3.  **Eficiência:** A biblioteca monitora internamente se há processos ativos (como timers ou piscadas) para evitar processamento desnecessário na CPU.

## 🛠️ Especificações Técnicas

**Linguagem de Programção:** Desenvolvida em C++.

**Gerenciamento de Tempo:** Utiliza aritmética de tempo para controle de eventos.

**Compatibilidade:**
* **Placas:** Compatível com toda a linha Arduino, ESP32, ESP8266 e microcontroladores suportados pelo framework.
* **Simuladores:** Testado e validado em ambientes como Wokwi.

---

## Estrutura da biblioteca

```text
LED/
├── library.json
├── README.md
├── LICENSE
├── src/
│   ├── LED.h
│   └── LED.cpp
└── examples/