#ifndef EEPROM
#define EEPROM

#include <avr/io.h>
#include <avr/interrupt.h>

void EEPROM_write(uint16_t address, uint8_t data);
uint8_t EEPROM_read(uint16_t address);

#endif // EEPROM
