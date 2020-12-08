#define F_CPU 16000000UL    // Define CPU frequency

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

int main() {

    init_UART(9600, F_CPU);

    while(1) {
        transmit_string("hello world\n\0");
        _delay_ms(500);
    }
}