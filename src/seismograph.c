#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "clock.h"
#include "console.h"
#include "sdram.h"
#include "lcd_spi.h"
#include "gfx.h"
//#include "gyr_spi.h"
#include "battery.h"

int main(void) {
	int8_t x = 0, y = 0, z = 0;
	uint16_t voltage;
	float battery;
	char X[8], Y[8], Z[8], Battery[8];
	clock_setup();
	console_setup(9600);
	sdram_init();
	//gyr_setup();
	adc_setup();
	lcd_spi_init();
	console_puts("LCD Initialized\n");
	gfx_init(lcd_draw_pixel, 240, 320);
	while (1) {
		gfx_fillScreen(LCD_WHITE);
		gfx_setTextSize(2);
		gfx_setCursor(25, 25);
		gfx_puts("Seismograph");
		//x = gyr_readX();
		//y = gyr_readY();
		//z = gyr_readZ();
		voltage = read_adc_naiive(1);
		battery = (voltage * 5.5/1023);
		sprintf(X, "% d", x);
		sprintf(Y, "% d", y);
		sprintf(Z, "% d", z);
		sprintf(Battery, "%.2f", battery);
		gfx_setCursor(25, 75);
		gfx_puts("X: ");
		gfx_puts(X);
		gfx_setCursor(25, 125);
		gfx_puts("Y: ");
		gfx_puts(Y);
		gfx_setCursor(25, 175);
		gfx_puts("Z: ");
		gfx_puts(Z);
		gfx_setCursor(8, 250);
		gfx_puts("Battery:");
		gfx_puts(Battery);
		gfx_puts(" V");
		lcd_show_frame();
		x++, y--, z++;
	}
}