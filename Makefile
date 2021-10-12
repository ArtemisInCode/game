# File:   Makefile
# Author: M. P. Hayes, UCECE
# Date:   12 Sep 2010
# Descr:  Makefile for game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: main.out


# Compile: create object files from C source files.
main.o: main.c ../../drivers/avr/system.h LedHeader.h maps.h movement.h levels.h ../../utils/pacer.h 
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

LedHeader.o: LedHeader.c LedHeader.h
	$(CC) -c $(CFLAGS) $< -o $@
	
timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@
	
pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@
	
ledmat.o: ../../drivers/ledmat.c ../../drivers/ledmat.h  ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@
	
maps.o: maps.c maps.h
	$(CC) -c $(CFLAGS) $< -o $@

levels.o: levels.c ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../utils/pacer.h movement.h ../../drivers/navswitch.h levels.h maps.h
	$(CC) -c $(CFLAGS) $< -o $@
	
movement.o: movement.c ../../drivers/avr/system.h ../../drivers/avr/pio.h movement.h ../../drivers/navswitch.h ../../drivers/ledmat.h levels.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/navswitch.h  ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/delay.h
	$(CC) -c $(CFLAGS) $< -o $@





# Link: create ELF output file from object files.
main.out: main.o system.o LedHeader.o pacer.o timer.o ledmat.o maps.o movement.o levels.o navswitch.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: main.out
	$(OBJCOPY) -O ihex main.out main.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash main.hex; dfu-programmer atmega32u2 start

