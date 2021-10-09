#include <avr/io.h>
#include "system.h"
#include "LedHeader.h"

void header_init(void) // Initilises header for leds
{
	for(uint8_t i = 1; i<7; i++) {
		DDRD |= (1<<i);
	}
}

void header_set(uint8_t amount) //Sets number of leds on
{
	if(amount < 7) {
		for(uint8_t i = 1; i<7; i++) {
			if(i<=amount) {
				PORTD |= (1<<(7-i));
			} else {
				PORTD &= ~(1<<(7-i));
			}
		}
	}
}