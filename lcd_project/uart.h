#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 16UL))) - 1)

void UART_init(void);
unsigned char UART_recv(void);
void UART_tran(char ch);
void UART_sendstr(char *str);
void msdelay(int t);

#endif
