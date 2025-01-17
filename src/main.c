#include <stdio.h>
#include "pico/stdlib.h"
#include "teclado.h"

// Definindo os pinos das linhas e colunas do teclado matricial 4x4
uint pinos_colunas[4] = {8,9,16,17};
uint pinos_linhas[4] = {1,2,3,4};
int tamanho_array_colunas = sizeof(pinos_colunas) / sizeof(pinos_colunas[0]);
int tamanho_array_linhas = sizeof(pinos_linhas) / sizeof(pinos_linhas[0]);

// Mapa de teclas do teclado
char mapa_caracteres[4][4] = {
    {'1', '2' , '3', 'A'},
    {'4', '5' , '6', 'B'},
    {'7', '8' , '9', 'C'},
    {'*', '0' , '#', 'D'}
};

int main(void) {
	stdio_init_all();

	for (int i = 0;; i++) {
		printf("Hello %d\n", i);
		sleep_ms(1000);
	}

	return 0;
}
