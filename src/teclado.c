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

char obter_tecla_pressionada(uint pinos_colunas[],uint pinos_linhas[], int tamanho_array_colunas, int tamanho_array_linhas, char mapa_caracteres[4][4]){
	bool tecla_pressionada = false;
	
	// Realiza a varredura das linhas
	for (int contador_linhas = 0; contador_linhas < tamanho_array_linhas; contador_linhas++){
		// Coloca atual no nível alto
		gpio_put(pinos_linhas[contador_linhas],true);

		// Realiza a varredura das colunas
		for (int contador_colunas = 0; contador_colunas < tamanho_array_colunas; contador_colunas++)
		{
			// Verifica se o botão foi pressionado
			if (gpio_get(pinos_colunas[contador_colunas])){
				// Desliga a linha atual para evitar conflitos caso mantenha a tecla pressionada
				gpio_put(pinos_linhas[contador_linhas],false);

				return mapa_caracteres[contador_linhas][contador_colunas];			
			}
		}

		// Coloca a linha atual no nível baixo
		gpio_put(pinos_linhas[contador_linhas],false);
	}

	return '\0';
}