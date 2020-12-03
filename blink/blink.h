#ifndef BLINK
#define BLINK

#include <avr/io.h>

// Test the functionality of passing a port to a function
void toggle(volatile uint8_t *PORT, uint8_t pin);

#endif