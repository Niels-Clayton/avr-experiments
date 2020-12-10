#define F_CPU 16000000UL    // Define CPU frequency

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

int main() {

    UART_init(9600, F_CPU);
    char message;

    while(1) {
        while(UART_available()) {
            message = UART_recieve();
            UART_transmit(&message, 1);
        }
    }
}