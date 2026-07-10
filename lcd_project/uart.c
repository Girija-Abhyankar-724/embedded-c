#include "uart.h"

void UART_init() {

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    UCSR0C |= (1<< UCSZ00) | (1 << UCSZ01);
    UBRR0L = BAUD_PRESCALE; 
    UBRR0H = (BAUD_PRESCALE >> 8);
}

unsigned char UART_recv (){
    while (!(UCSR0A & (1 << RXC0)));
    return (UDR0);
}

void UART_tran(char ch){
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = ch;
}

void UART_sendstr(char *str){
    unsigned char j=0;
    for(j=0; str[j]!= '\0'; j++){
        UART_tran(str[j]);
    }
}

void msdelay(int t){
    int i;
    for(i=0; i<t; i++){

        TCNT0 = 0x06;
        TIFR0 = 0x01;
        TCCR0B = (1<<CS01) | (1<<CS00);
        while((TIFR0 & 0x01) ==0); 
        TCCR0B=0;
        
    }

}

