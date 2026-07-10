#include "pcf8574.h"
#include "twi.h"

void PCF8574_write(unsigned char data)
{
    TWI_start();

    TWI_write(PCF8574_ADDR << 1);

    TWI_write(data);           

    TWI_stop();
}
