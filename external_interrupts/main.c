#define F_CPU 16000000UL    // Define CPU frequency

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN 1
#define INT_PIN 0

// Pin change interrupt
ISR(PCINT0_vect) {

    // If interupt pin is low toggel the LED
	if(!(PINB & (1 << INT_PIN))) {
        PORTB ^= (1 << LED_PIN);
    }
}

int main() {

    // Set interrupt regesters
    SREG   |= (1 << 7); // Global interrupt enable
    PCICR  |= (1 << 0); // Enable pin change interrupt 0
    PCMSK0 |= (1 << 0); // Enable pin change interrupt on port B pin 0

    // Set port data dirrection
    DDRB  |= (1 << LED_PIN);

    PORTB |= (1 << INT_PIN);

    while(1) {
        // Do nothing
    }
}
