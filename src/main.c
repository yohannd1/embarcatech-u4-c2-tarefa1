#include <stdio.h>
#include "pico/stdlib.h"

#include "teclado.h"
#include "buzzer.h"
#include "led.h"

#define BUZZER_PIN 10

// Definindo os pinos das linhas e colunas do teclado matricial 4x4
uint pinos_colunas[4] = {8, 9, 16, 17};
uint pinos_linhas[4] = {1, 2, 3, 4};
int tamanho_array_colunas = sizeof(pinos_colunas) / sizeof(pinos_colunas[0]);
int tamanho_array_linhas = sizeof(pinos_linhas) / sizeof(pinos_linhas[0]);

// Mapa de teclas do teclado
char mapa_caracteres[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

int main(void) {
	stdio_init_all();

	Buzzer bz;
	Buzzer_init(&bz, BUZZER_PIN);

	inicializar_teclado(pinos_colunas,pinos_linhas,tamanho_array_colunas,tamanho_array_linhas);

	while (true) {
		char tecla = obter_tecla_pressionada(pinos_colunas,pinos_linhas,tamanho_array_colunas,tamanho_array_linhas,mapa_caracteres);
		
		if(tecla){
			printf("Tecla pressionada: %c\n",tecla);
		}

		switch (tecla) {
			case 'A':
				// Ligar o led vermelho
				set_led_color(true, false, false);
				break;

			case 'B':
				// Ligar o led verde
				set_led_color(false, true, false);
				break;

			case 'C':
				// Ligar o led azul
				set_led_color(false, false, true);
				break;

			case 'D':
				// Tocar o buzzer
				Buzzer_play(&bz, 2090, 500);
				break;
		
			default:
				break;
		}

		sleep_ms(500);
	}

	return 0;
}
