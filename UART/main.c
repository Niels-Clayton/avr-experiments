#define F_CPU 16000000UL    // Define CPU frequency

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

int main() {

    UART_init(9600, F_CPU);

    while(1) {
        UART_transmit("hello world\n", 12);
        // _delay_ms(10);
    }
}