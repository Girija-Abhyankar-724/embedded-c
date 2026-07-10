#include "lcd.h"
#include "pcf8574.h"
#include <util/delay.h>


#define RS 0x01
#define RW 0x02
#define EN 0x04
#define BL 0x08

static void LCD_pulseEnable(uint8_t data)
{
    PCF8574_write(data | EN | BL);
    _delay_us(1);
 
    PCF8574_write((data & ~EN) | BL);
    _delay_us(50);
}

static void LCD_send(uint8_t value, uint8_t mode)
{
    uint8_t upper = value & 0xF0;          
    uint8_t lower = (uint8_t)(value << 4) & 0xF0; 
 
    LCD_pulseEnable(upper | mode);
    LCD_pulseEnable(lower | mode);
}


void LCD_cmd(unsigned int cmd){
  LCD_send(cmd, 0);
  _delay_us(2); //safety ig

}


void LCD_char(unsigned int data){
    LCD_send(data, RS);
}

void LCD_string(char * str){
    while(*str){
        LCD_char(*str);
        str++;
    }
}

void LCD_init(void)
{
    _delay_ms(20);

    LCD_pulseEnable(0x30);
    _delay_ms(5);
 
    LCD_pulseEnable(0x30);
    _delay_us(150);
 
    LCD_pulseEnable(0x30);
    _delay_us(150);
 
    LCD_pulseEnable(0x20);
    _delay_us(150);
 
    LCD_cmd(0x28);   
    LCD_cmd(0x0C);   
    LCD_cmd(0x06);  
    LCD_cmd(0x01);  
    _delay_ms(2);
}
