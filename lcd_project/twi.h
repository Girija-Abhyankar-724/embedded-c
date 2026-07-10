#ifndef TWI_H
#define TWI_H

#include <avr/io.h>

void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(unsigned char data);

#endif
