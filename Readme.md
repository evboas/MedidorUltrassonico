# Projeto Medidor Ultrassônico para Laboratório

Este projeto foi elaborado para ser utilizado em laboratório de hidráulica durante atividades realizadas para pesquisas desenvolvidas.

A demanda exigia que fossem tiradas 30 medidas do nível de água de um pequeno canal de água no laboratório para que se pudesse tirar algumas medidas estatísticas e então comparar com simulações de fluidodinâmica computacional.

## Hardware

O hardware foi projeto com auxílio da plataforma Arduino, utilizando um sensor ultrassônico HC-SR04 e alguns componentes como LED e Buzzer para sinalizar o funcionamento.

A lista de hardware é composta por:

- 1 Arduino Uno
- 1 Sensor Ultrassônico HC-SR04
- 1 LED Vermelho
- 1 LED Verde
- 2 Resistores de 220 Ohm
- 1 Buzzer
- 1 Botão (PushButton)

A montagem do hardware pode ser vista na figura:

![Montagem Hardware](/img/Hardware.png)

## Funcionamento

Inicialmente o LED Verde estará acesso, indicando que o equipamento se encontra pronto para ser acionado. Assim que o botão é pressionado o Buzzer emite um sinal indicando que o sensor foi acionado e o LED Vermelho começará piscar a cada leitura que o sensor realizar. Ao finalizar, o Buzzer emite outro sinal sonoro e o LED Verde volta a acender.

As medidas são mostradas no monitor serial.

## Quantidade de medidas

O número de medições configuradas está conforme a necessidade do projeto inicial (30 medições), mas pode ser facilmente alterada na linha 16, onde se encontrada a variável global ***nMedidas***.

```C++ 
int nMedidas = 30; // número de medições que devem ser realizadas
```

## Futuras modificações

Embora o projeto esteja, atualmente, parado, ainda há intenções de se realizar a troca do Arduino pela plataforma ESP NodeMCU e criar um interface que possibilite a visualização dos dados em um computador, assim como o processamento desses dados com a plotagem de gráficos.
