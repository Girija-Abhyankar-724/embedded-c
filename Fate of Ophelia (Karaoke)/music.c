#include <reg51.h>
#include <lcd.h>

void main()
{
    lcd_init();

    while(1)
    {
			
        lcd_cmd(0x80);
        lcd_write_string(" I swore my ");
        msdelay(1000);
				lcd_cmd(0x01);
			
				lcd_cmd(0x80);
        lcd_write_string(" loyalty to ");
        msdelay(1000);
				
				lcd_cmd(0x01);
			lcd_cmd(0x80);
        lcd_write_string(" me, ");
        msdelay(800);
				
			lcd_cmd(0x80);
        lcd_write_string(" me, myself ");
				msdelay(1000);
			
        lcd_cmd(0xC0);
        lcd_write_string(" and ");
        msdelay(200);
				
				lcd_cmd(0xC0);
        lcd_write_string(" and I ");
				
				msdelay(2000);
				lcd_cmd(0x01);
				msdelay(1000);
    }
}

