#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <libopencm3/stm32/gpio.h>
#include "clock.h"
#include "console.h"
#include "sdram.h"
#include "lcd_spi.h"
#include "gfx.h"
//#include "gyr_spi.h"
#include "battery.h"
#include "led_usart.h"

int main(void) {
	int8_t x = 0, y = 0, z = 0, usart_switch = 0;
	uint16_t voltage;
	float battery;
	char X[8], Y[8], Z[8], Battery[8];
	clock_setup();
	console_setup(9600);
	sdram_init();
	//gyr_setup();
	adc_setup();
	lcd_spi_init();
	led_usart_setup();
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
		if (gpio_get(GPIOA, GPIO0)) {
			if (usart_switch) {
				usart_switch = 0;
				gpio_clear(GPIOG, GPIO13);
			} else {
				usart_switch = 1;
			}
		}
		sprintf(X, "% d", x);
		sprintf(Y, "% d", y);
		sprintf(Z, "% d", z);
		sprintf(Battery, "%.2f", battery);
		gfx_setCursor(50, 75);
		gfx_puts("X: ");
		gfx_puts(X);
		gfx_setCursor(50, 115);
		gfx_puts("Y: ");
		gfx_puts(Y);
		gfx_setCursor(50, 155);
		gfx_puts("Z: ");
		gfx_puts(Z);
		gfx_setCursor(8, 225);
		gfx_puts("Battery:");
		gfx_puts(Battery);
		gfx_puts(" V");
		gfx_setCursor(10, 275);
		gfx_puts("USART/USB: ");
		if (usart_switch) {
			gfx_puts("Yes");
		} else {
			gfx_puts("No");
		}
		lcd_show_frame();
		if (usart_switch) {
			console_puts(X);
			console_puts("\t");
			console_puts(Y);
			console_puts("\t");
			console_puts(Z);
			console_puts("\n");
			gpio_toggle(GPIOG, GPIO13);
		}
		x++, y--, z++;
	}
}