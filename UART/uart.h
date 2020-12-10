#ifndef UART
#define UART

#define BUFFER_LENGTH 50

#include <avr/io.h>

// Buffers to hold outgoing and incomming messages
extern char TX_buffer[BUFFER_LENGTH];
extern char RX_buffer[BUFFER_LENGTH];

// Variable holding the current position within the RX or TX buffers
extern uint8_t TX_send_position;
extern uint8_t RX_write_position;

// Variable holding the read/write position within the RX or TX buffers
extern uint8_t TX_write_position;
extern uint8_t RX_read_position;


// Setup UART baudrate and regesters
void UART_init(uint32_t baud, uint32_t f_cpu);

// Transmit an array of characters
void UART_transmit(char* data, uint8_t len);

// Read a character from the recieve buffer
char UART_recieve(void);

// Return true if there is unread bytes in the buffer
int UART_available(void);

#endif // UART