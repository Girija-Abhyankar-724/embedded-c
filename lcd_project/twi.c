#include "twi.h"

void TWI_init(void) 
{
    TWSR = 0x00;   
    TWBR = 72; 
    TWCR = (1<<TWEN); 
}


void TWI_start(void)
{
    TWCR =
        (1<<TWINT) |
        (1<<TWSTA) |
        (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
}

void TWI_stop(void) 
{
    TWCR =
        (1<<TWINT) |
        (1<<TWEN) |
        (1<<TWSTO);
        
}

void TWI_write(unsigned char data) 
{
    TWDR = data;

    TWCR =
        (1<<TWINT) |
        (1<<TWEN);

    while(!(TWCR & (1<<TWINT)));
    
}
