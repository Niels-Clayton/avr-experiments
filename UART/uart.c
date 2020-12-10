#include "uart.h"
#include <avr/interrupt.h>


char TX_buffer[BUFFER_LENGTH];
char RX_buffer[BUFFER_LENGTH];

uint8_t TX_send_position = 0;
uint8_t RX_write_position = 0;

uint8_t TX_write_position = 0;
uint8_t RX_read_position = 0;


void UART_init(uint32_t baud, uint32_t f_cpu) {

    // Calculate UBRR value form the desired baud and F_CPU
    uint16_t ubbr = ((f_cpu/16/baud)-1);

    // Set baud rate
    UBRR0H = ubbr >> 8;
    UBRR0L = ubbr;

    // Enable RX and TX and enable RX and TX interrupts
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << TXCIE0) | (1 << RXCIE0);

    // Set number of data bits
    // This sets UART to 8 bit data
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

    // Enable global interrupts
    sei();
}

void UART_transmit(char* data, uint8_t len) {

    for(uint8_t i = 0; i < len; i++) {

        // If the buffer is already full of data, wait for an empty space
        while((TX_write_position == TX_send_position) && !(UCSR0A & (1 << UDRE0)));

        // Write the data to the transmit buffer
        *(TX_buffer + TX_write_position++) = *(data + i);

        // If a the end of the buffer, reset position
        if(TX_write_position == BUFFER_LENGTH) {
            TX_write_position = 0;
        }

        // Check for ongoing transmission
        if(UCSR0A & (1 << UDRE0)) {
            // Place data in transmit regester to begin the transmission
            UDR0 = *(TX_buffer + TX_send_position++);
        }

        // Check if send position must be reset
        if(TX_send_position == BUFFER_LENGTH) {
            TX_send_position = 0;
        }
    }  
}

char UART_recieve(void) {
    
    char data = '\0';

    // If a byte is available place it in the data variable 
    if(RX_write_position != RX_read_position) {
        data = *(RX_buffer + RX_read_position++);
    }

    // Check if send position must be reset
    if(RX_read_position == BUFFER_LENGTH) {
        RX_read_position = 0;
    }

    return data;
}


int UART_available(void) {

    // If there is unread data in the buffer return true
    return !(RX_write_position == RX_read_position);
}

// Transmit (TX) interupt rutine 
ISR(USART_TX_vect) {

    // If there is unsent data in the tansmit buffer
    if(TX_write_position != TX_send_position) {
        // Place data in transmit regester
        UDR0 = *(TX_buffer + TX_send_position++);
    }
    
    // Check if send position must be reset
    if(TX_send_position == BUFFER_LENGTH) {
            TX_send_position = 0;
    }
}

// Recieve (TX) interupt rutine 
ISR(USART_RX_vect) {

    // Store they byte of data in the recieve buffer
    *(RX_buffer + RX_write_position++) = UDR0;

    // Check if send position must be reset
    if(RX_write_position == BUFFER_LENGTH) {
        RX_write_position = 0;
    }
}