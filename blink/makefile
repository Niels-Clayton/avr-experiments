# Target name for final intel hex file
TARGET = blink

# Directory Structure
SOURCEDIR = .
BUILDDIR  = build

# Programmer definition
DEVICE = atmega328p
PORT = /dev/ttyACM0
PROGRAMMER = avrisp
BAUDRATE = 19200

# Source and intermediary file paths
SOURCES := $(shell find -name '*.c')
OBJECTS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))
ELF = $(BUILDDIR)/$(TARGET).elf
HEX = $(BUILDDIR)/$(TARGET).hex

.PHONY: all flash clean

compile:$(OBJECTS)
	avr-gcc -Wall -Os -mmcu=$(DEVICE) $(OBJECTS) -o $(ELF)
	avr-objcopy -j .text -j .data -O ihex $(ELF) $(HEX)
	avr-size --format=avr --mcu=$(DEVICE) $(ELF)


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	avr-gcc -Wall -Os -mmcu=$(DEVICE) -c $< -o $@	


$(BUILDDIR):
	mkdir -p $@


flash: $(HEX)
	avrdude -c $(PROGRAMMER) -P $(PORT) -b $(BAUDRATE) -p m328p -U flash:w:$(HEX)


clean:
	rm -f $(OBJECTS) $(ELF) $(HEX)


help:
	@echo "Targets:"
	@echo "compile	- Build and compile sources to intel hex"
	@echo "flash	- Flash intel hex to AVR microcontroller"
	@echo "clean	- Remove all build outputs"
