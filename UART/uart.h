#ifndef UART
#define UART

#define BUFFER_LENGTH 100

#include <avr/io.h>

// Buffers to hold outgoing and incomming messages
extern char TX_buffer[BUFFER_LENGTH];
// extern static char RX_buffer[BUFFER_LENGTH];

// Variable holding the current position within the RX or TX buffers
extern uint8_t TX_send_position;
// extern static uint8_t RX_recieve_position = 0;

// Variable holding the read/write position within the RX or TX buffers
extern uint8_t TX_write_position;
// extern static uint8_t RX_read_position = 0;


// Setup UART baudrate and regesters
void UART_init(uint32_t baud, uint32_t f_cpu);

void UART_transmit(char* data, uint8_t len);

// static inline void transmit_char(char data);
// void transmit_string(char* data);

#endif // UART