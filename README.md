# Controle de LEDs com Raspberry Pi Pico

Este programa controla três LEDs conectados ao Raspberry Pi Pico, ativando-os em sequência quando um botão é pressionado. Após a ativação, os LEDs são desligados um a um, a cada 3 segundos.

## Requisitos
- Raspberry Pi Pico
- 3 LEDs
- 3 resistores (330Ω recomendados)
- 1 botão
- Cabos para conexão

## Conexões
- LED 1: Pino GPIO 10
- LED 2: Pino GPIO 11
- LED 3: Pino GPIO 12
- Botão: Pino GPIO 6 (com pull-up interno ativado)

## Compilação e Execução

1. Instale o SDK do Raspberry Pi Pico e configure o ambiente de desenvolvimento.
2. Compile o código com um compilador compatível.
3. Converta o binário gerado em um arquivo `.uf2` e transfira para o Pico.

## Funcionamento
1. Pressione o botão para acender todos os LEDs simultaneamente.
2. Os LEDs serão desligados um a um, com um intervalo de 3 segundos.
3. Após desligar todos os LEDs, o sistema aguarda uma nova ativação.



