#ifndef UART
#define UART

#include <avr/io.h>

void init_UART(uint32_t baud, uint32_t f_cpu);
static inline void transmit_char(char data);
void transmit_string(char* data);

#endif // UART