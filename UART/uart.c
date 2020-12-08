#include "uart.h"

void init_UART(uint32_t baud, uint32_t f_cpu) {

    // Calculate UBRR value form the desired baud and F_CPU
    uint16_t ubbr = ((f_cpu/16/baud)-1);

    // Set baud rate
    UBRR0H = (uint8_t)(ubbr >> 8);
    UBRR0L = (uint8_t)ubbr;

    // Enable RX and TX
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Set number of data bits
    // This sets UART to 8 bit data
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void transmit_char(char data) {
    // Wait till the transmit shift regester is empty
    while(!(UCSR0A & (1 << UDRE0)));

    // Place data in transmit regester
    UDR0 = data;
}

void transmit_string(char* data) {
    for(int i = 0; *(data + i) != '\0'; i++) {
        transmit_char(*(data+i));
    }
}