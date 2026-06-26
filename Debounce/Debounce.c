#include <at89c5131.h>
#include <lcd.h>

// Button declaration
sbit button = P0^7;
// Add LCD pin definitions and function declarations here


void main()
{
// Initialize LCD
	unsigned int count=0;
	button =1;
	lcd_init();
	
lcd_cmd(0x80);
lcd_write_string("Debounce Counter");
 lcd_cmd(0xC0);
    lcd_write_char((count/10)+'0');
lcd_write_char((count%10)+'0');

	while(1){



if(button ==0){
msdelay(20);
if(button==0){
count++;
	lcd_cmd(0xC0);
                lcd_write_char((count/10)+'0');
lcd_write_char((count%10)+'0');
while(button==0);
} 
}

}
// Increment counter on valid press
// Display counter value on LCD
}


