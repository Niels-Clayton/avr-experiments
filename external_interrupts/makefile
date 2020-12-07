# Target name for final intel hex file
TARGET = interrupts

# Directory Structure
SOURCEDIR = .
BUILDDIR  = build

# Compiler definitions
DEVICE = atmega328p

# Programmer definitions
DEVICE_ID = m328p
PORT = /dev/ttyACM0
PROGRAMMER = avrisp
BAUDRATE = 19200

# Source and intermediary file paths
SOURCES := $(shell find -name '*.c')
OBJECTS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))
ELF = $(BUILDDIR)/$(TARGET).elf
HEX = $(BUILDDIR)/$(TARGET).hex


# Compile all sources to an intel hex file
compile:$(OBJECTS)
	avr-gcc -Wall -Os -mmcu=$(DEVICE) $(OBJECTS) -o $(ELF)
	avr-objcopy -j .text -j .data -O ihex $(ELF) $(HEX)
	avr-size --format=avr --mcu=$(DEVICE) $(ELF)


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	avr-gcc -Wall -Os -mmcu=$(DEVICE) -c $< -o $@	


$(BUILDDIR):
	mkdir -p $@


# Flash the intel hex file to the specified avr microcontroller
flash: $(HEX)
	avrdude -c $(PROGRAMMER) -P $(PORT) -b $(BAUDRATE) -p $(DEVICE_ID) -U flash:w:$(HEX)


# Remove build outputs
clean:
	rm -f $(OBJECTS) $(ELF) $(HEX)


# Compile sources, flash to device, clean outputs
all: compile flash clean

.PHONY: all compile flash clean help


help:
	@echo "Targets:"
	@echo "all	- Run all targets"
	@echo "compile	- Build and compile sources to intel hex"
	@echo "flash	- Flash intel hex to AVR microcontroller"
	@echo "clean	- Remove all build outputs"
