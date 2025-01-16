#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definição dos pinos dos LEDs RGB
#define LED1_RED_PIN 2
#define LED1_GREEN_PIN 3
#define LED1_BLUE_PIN 4
#define LED2_RED_PIN 5
#define LED2_GREEN_PIN 6
#define LED2_BLUE_PIN 7
#define LED3_RED_PIN 8
#define LED3_GREEN_PIN 9
#define LED3_BLUE_PIN 10

// Pinos do teclado matricial (exemplo)
#define ROW1 12
#define ROW2 13
#define ROW3 14
#define ROW4 15
#define COL1 16
#define COL2 17
#define COL3 18
#define COL4 19

void init_hardware() {
    // Inicializa os pinos dos LEDs RGB
    gpio_init(LED1_RED_PIN); gpio_set_dir(LED1_RED_PIN, GPIO_OUT);
    gpio_init(LED1_GREEN_PIN); gpio_set_dir(LED1_GREEN_PIN, GPIO_OUT);
    gpio_init(LED1_BLUE_PIN); gpio_set_dir(LED1_BLUE_PIN, GPIO_OUT);

    gpio_init(LED2_RED_PIN); gpio_set_dir(LED2_RED_PIN, GPIO_OUT);
    gpio_init(LED2_GREEN_PIN); gpio_set_dir(LED2_GREEN_PIN, GPIO_OUT);
    gpio_init(LED2_BLUE_PIN); gpio_set_dir(LED2_BLUE_PIN, GPIO_OUT);

    gpio_init(LED3_RED_PIN); gpio_set_dir(LED3_RED_PIN, GPIO_OUT);
    gpio_init(LED3_GREEN_PIN); gpio_set_dir(LED3_GREEN_PIN, GPIO_OUT);
    gpio_init(LED3_BLUE_PIN); gpio_set_dir(LED3_BLUE_PIN, GPIO_OUT);

    // Inicializa os pinos do teclado matricial
    gpio_init(ROW1); gpio_set_dir(ROW1, GPIO_OUT);
    gpio_init(ROW2); gpio_set_dir(ROW2, GPIO_OUT);
    gpio_init(ROW3); gpio_set_dir(ROW3, GPIO_OUT);
    gpio_init(ROW4); gpio_set_dir(ROW4, GPIO_OUT);
    gpio_init(COL1); gpio_set_dir(COL1, GPIO_IN); gpio_pull_down(COL1);
    gpio_init(COL2); gpio_set_dir(COL2, GPIO_IN); gpio_pull_down(COL2);
    gpio_init(COL3); gpio_set_dir(COL3, GPIO_IN); gpio_pull_down(COL3);
    gpio_init(COL4); gpio_set_dir(COL4, GPIO_IN); gpio_pull_down(COL4);
}

void set_led_color(int led_number, bool red, bool green, bool blue) {
    switch (led_number) {
        case 1:
            gpio_put(LED1_RED_PIN, red);
            gpio_put(LED1_GREEN_PIN, green);
            gpio_put(LED1_BLUE_PIN, blue);
            break;
        case 2:
            gpio_put(LED2_RED_PIN, red);
            gpio_put(LED2_GREEN_PIN, green);
            gpio_put(LED2_BLUE_PIN, blue);
            break;
        case 3:
            gpio_put(LED3_RED_PIN, red);
            gpio_put(LED3_GREEN_PIN, green);
            gpio_put(LED3_BLUE_PIN, blue);
            break;
    }
}

char read_keypad() {
    const int rows[4] = {ROW1, ROW2, ROW3, ROW4};
    const int cols[4] = {COL1, COL2, COL3, COL4};
    char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    for (int i = 0; i < 4; i++) {
        gpio_put(rows[i], 1);  // Ativa a linha
        for (int j = 0; j < 4; j++) {
            if (gpio_get(cols[j])) {  // Verifica qual coluna está ativa
                gpio_put(rows[i], 0);  // Desativa a linha antes de retornar
                return keys[i][j];
            }
        }
        gpio_put(rows[i], 0);  // Desativa a linha
    }

    return '\0';  // Nenhuma tecla pressionada
}

int main() {
    stdio_init_all();
    init_hardware();

    while (true) {
        char key = read_keypad();

        if (key != '\0') {
            // Controle dos LEDs baseado na tecla pressionada
            switch (key) {
                case '1': set_led_color(1, true, false, false); break;  // Vermelho LED 1
                case '2': set_led_color(2, false, true, false); break;  // Verde LED 2
                case '3': set_led_color(3, false, false, true); break;  // Azul LED 3
                case 'A':  // Apaga todos os LEDs
                    set_led_color(1, false, false, false);
                    set_led_color(2, false, false, false);
                    set_led_color(3, false, false, false);
                    break;
                default:
                    break;
            }
        }

        sleep_ms(100);  // Debounce simples
    }

    return 0;
}
