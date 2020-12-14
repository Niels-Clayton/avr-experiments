#include "includes/eeprom.h"

void EEPROM_write(uint16_t address, uint8_t data) {

    // Wait for any ongoing write to complete
    while(EECR & (1 << EEPE));
    
    // Set the eeprom write address
    EEARL = (uint8_t)address;
    
    // Set the eeprom write data
    EEDR = data;

    // Disable interrupts
    cli();

    // Set the master write enable
    EECR |= (1 << EEMPE);

    // Begin the eeprom write
    EECR |= (1 << EEPE);

    // Enable interupts
    sei();

}


uint8_t EEPROM_read(uint16_t address) {


    // Wait for any ongoing write to complete
    while(EECR & (1 << EEPE));

    // Set the eeprom read address
    EEARL = (uint8_t)address;

    // Disable interrupts
    cli();

    // Begin the eeprom read
    EECR |= (1 << EERE);

    // Enable interupts
    sei();

    // Return the data
    return EEDR; 
}
