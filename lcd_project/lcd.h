#ifndef LCD_H
#define LCD_H

#include <avr/io.h>

static void LCD_pulseEnable(uint8_t data);
static void LCD_send(uint8_t value, uint8_t mode);
void LCD_cmd(unsigned int cmd);
void LCD_init(void);
void LCD_char(unsigned int data);
void LCD_string(char * str);

#endif
