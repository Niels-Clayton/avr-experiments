#include "blink.h"

void toggle(volatile uint8_t *PORT, uint8_t pin){
    *PORT ^= (1 << pin);
}
