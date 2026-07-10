#ifndef PCF8574_H
#define PCF8574_H

#include <avr/io.h>

#define PCF8574_ADDR 0x27

void PCF8574_write(unsigned char data);

#endif
