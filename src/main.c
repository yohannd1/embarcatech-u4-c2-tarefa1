#include <stdio.h>

#include "pico/stdlib.h"
#include "buzzer.h"

#define BUZZER_PIN 10

int main(void) {
	stdio_init_all();

	Buzzer bz;
	Buzzer_init(&bz, BUZZER_PIN);
	Buzzer_play(&bz, 2090, 500); // isso aqui toca o buzzer por 500ms. TODO:
								 // conectar isso ao teclado

	for (int i = 0;; i++) {
		printf("Hello %d\n", i);
		sleep_ms(1000);
	}

	return 0;
}
