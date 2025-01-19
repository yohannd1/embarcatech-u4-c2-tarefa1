Unidade 4, Capítulo 2, Tarefa 1

# Microcontroladores - GPIO

Este projeto utiliza um teclado matricial 4x4 conectado a uma placa controladora (como a Raspberry Pi Pico) para realizar diferentes ações, como acender LEDs e tocar um buzzer, dependendo da tecla pressionada. 

## Funcionalidades Principais

1. **Detecção de Teclas do Teclado Matricial**:
   - O código é configurado para um teclado matricial 4x4, onde as teclas mapeadas são associadas a ações específicas.
   - As teclas pressionadas são capturadas e exibidas no console.

2. **Controle de LEDs RGB**:
   - O LED pode ser configurado para acender em diferentes cores dependendo da tecla pressionada:
     - `A`: LED vermelho.
     - `B`: LED verde.
     - `C`: LED azul.
     - `D`: Todas as cores do LED acesas ao mesmo tempo.

3. **Ativação do Buzzer**:
   - Ao pressionar a tecla `#`, o buzzer emite um som de frequência fixa por 500 ms.

4. **Mapeamento de Teclas**:
   - O teclado matricial é configurado com um mapa de caracteres:
     ```
     {'1', '2', '3', 'A'}
     {'4', '5', '6', 'B'}
     {'7', '8', '9', 'C'}
     {'*', '0', '#', 'D'}
     ```
   - Cada tecla tem uma funcionalidade específica ou não realiza ação (padrão).

## Arquivos Importados

O projeto utiliza bibliotecas específicas para abstração de funcionalidades:
- `teclado.h`: Lida com a inicialização e leitura de teclas do teclado matricial.
- `buzzer.h`: Controla o buzzer, permitindo tocar sons em frequências específicas.
- `led.h`: Gerencia o LED RGB, configurando as cores com base na entrada.

## Configuração de Hardware

1. **Pinos do Teclado**:
   - **Colunas**: GPIO 8, 9, 16, 17.
   - **Linhas**: GPIO 1, 2, 3, 4.
   
2. **Buzzer**:
   - Conectado ao GPIO 10.

3. **LED RGB**:
   - Configurado para responder a funções de controle (definido em `led.h`).

## Fluxo de Execução

1. Inicializa o sistema de entrada e saída padrão.
2. Configura o teclado matricial e o LED.
3. No loop principal:
   - Lê a tecla pressionada.
   - Realiza uma ação correspondente à tecla pressionada:
     - Acende o LED em cores diferentes.
     - Toca o buzzer.
     - Exibe no console a tecla detectada.
   - Aguarda 500 ms antes da próxima iteração.

## Como Compilar e Executar

1. Configure o ambiente de desenvolvimento para a Raspberry Pi Pico (SDK C/C++).
2. Inclua os arquivos `teclado.h`, `buzzer.h`, e `led.h` no projeto.
3. Compile o código e faça o upload para a placa.
4. Conecte o teclado matricial, o LED RGB e o buzzer aos pinos correspondentes.

## Requisitos

- Placa microcontroladora (como Raspberry Pi Pico).
- Teclado matricial 4x4.
- LED RGB.
- Buzzer piezoelétrico.
- Cabos e conexões apropriadas.

## Componentes 

Tarefa 1:
- Líder: Yohanan
- Diagrama do Wokwi: Vítor
- Teclado matricial: Vítor
- Buzzer: Yohanan
- LED: Allany e Yohanan
- Documentação: Caio
- Vídeo: Fernando
