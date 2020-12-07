#define F_CPU 16000000UL
#define LED_PIN PORTB1           // Blink port B pin 0
#define LED_ENABLE PORTB0

#include "blink.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << LED_PIN); 	// Set port B pin 1 as output

    DDRB &= ~(1 << LED_ENABLE); // Set port B pin 0 as input
    PORTB |= (1 << LED_ENABLE); // Enable port B pin 0 internal 50k pullup
    
    while(1) {
	if(PINB & (1 << LED_ENABLE)) { // If port B pin 0 is high, toggle the LED pin
        toggle(&PORTB, LED_PIN);
        _delay_ms(100);
	}
	else PORTB &= ~(1 << LED_PIN); // Else set LED pin low
    }
}