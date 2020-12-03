#define F_CPU 16000000UL
#define LED_PIN 1           // Blink port B pin 0

#include "blink.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRB |= (1 << LED_PIN);
    while(1)
    {
        toggle(&PORTB, LED_PIN);
        _delay_ms(1000);
    }
}