#define F_CPU 16000000UL    // Define CPU frequency

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "includes/uart.h"
#include "includes/eeprom.h"

#define ADDR 0x1

int main() {

    UART_init(9600, F_CPU);
    
    char message;

    while(1) {
        
        if(UART_available()) {
            message = UART_recieve();

            EEPROM_write(ADDR, message);
        }

        char read = EEPROM_read(ADDR);

        UART_transmit(&read, 1);
        UART_transmit_char('\n');      

        _delay_ms(500);
    }    
}
