#include "pico/stdlib.h"

void inicializar_teclado(uint pinos_colunas[],uint pinos_linhas[], int tamanho_array_colunas, int tamanho_array_linhas){
    // Inicializa as colunas como entrada em nível baixo
	for (int contador = 0; contador < tamanho_array_colunas; contador++){
		gpio_init(pinos_colunas[contador]);
		gpio_set_dir(pinos_colunas[contador],GPIO_IN);
        gpio_pull_down(pinos_colunas[contador]);
	}
	
	// Inicializa as linhas como saída em nível baixo
	for (int contador = 0; contador < tamanho_array_linhas; contador++){
		gpio_init(pinos_linhas[contador]);
		gpio_set_dir(pinos_linhas[contador],GPIO_OUT);
        gpio_put(pinos_linhas[contador],false);
	}
}