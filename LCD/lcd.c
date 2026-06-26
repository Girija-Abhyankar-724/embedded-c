#include <reg51.h>
sbit RS=P0^0;	// Register select
sbit RW=P0^1;	// Read from or write to register
sbit EN=P0^2;	// Enable pin of lcd

void msdelay(unsigned int time)
{
	int i,j;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 382; j++);
	}
}

void lcd_cmd(unsigned int i)
{
	RS=0; // 0 is command 1 is dataa
	RW=0; //0 is read 1 is write
	EN=1;
	P2=i;
	msdelay(10);
	EN=0;
}

void lcd_init(void)
{
	P2=0x00;
	EN=0;
	RS=0;
	RW=0;
	
	lcd_cmd(0x38);	// Function set: 2 Line, 8-bbit, 5x7 dots
	msdelay(4);
	lcd_cmd(0x06);	// Entry mode, aauto increment with no shift
	msdelay(4);
	lcd_cmd(0x0C);	// Display on, Curson off
	msdelay(4);
	lcd_cmd(0x01);	// LCD clear
	msdelay(4);
	lcd_cmd(0x80);	// Move cursor to Row 1 column 0
}

void lcd_write_char(unsigned char ch)
{
	RS=1;
	RW=0;
	EN=1;
	P2=ch;
	msdelay(10);
	EN=0;
}

void lcd_write_string(unsigned char *s)
{
	while(*s!='\0')
	{
		lcd_write_char(*s++);
	}
}

void main(){
lcd_init(); //initialise
lcd_cmd(0x80);
lcd_write_string("      ^_^       ");
lcd_cmd(0xC0);
lcd_write_string("                ");
msdelay(5000);
}