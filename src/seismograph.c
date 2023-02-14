#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "clock.h"
#include "console.h"
#include "sdram.h"
#include "lcd_spi.h"
#include "gfx.h"

int main(void) {
	int x = 0;
	char X[64];
	clock_setup();
	console_setup(9600);
	sdram_init();
	lcd_spi_init();
	console_puts("LCD Initialized\n");
	gfx_init(lcd_draw_pixel, 240, 320);
	while (1) {
		gfx_fillScreen(LCD_WHITE);
		gfx_setTextSize(2);
		gfx_setCursor(25, 25);
		gfx_puts("Seismograph");
		gfx_setCursor(25, 50);
		gfx_puts("X: ");
		sprintf(X, "%d", x);
		gfx_puts(X);
		lcd_show_frame();
		x++;
	}
}