#include "led.h"
#include "pico/stdlib.h"

#include <stdio.h>

void init_led(void) {
	gpio_init(LED_RED_PIN);
	gpio_init(LED_GREEN_PIN);
	gpio_init(LED_BLUE_PIN);

	gpio_set_dir(LED_RED_PIN, GPIO_OUT);
	gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
	gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
}

void set_led_color(bool red, bool green, bool blue) {
	gpio_put(LED_RED_PIN, red);
	gpio_put(LED_GREEN_PIN, green);
	gpio_put(LED_BLUE_PIN, blue);

	/* printf("LED_RED_PIN=%d\n", red); */
	/* printf("LED_GREEN_PIN=%d\n", green); */
	/* printf("LED_BLUE_PIN_PIN=%d\n", blue); */
}
