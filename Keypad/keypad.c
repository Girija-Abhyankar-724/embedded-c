#include <at89c5131.h>
#include <stdio.h>
#include <lcd.h>



//P3 Lower nibbles are connected to columns of the keyboard
sbit col_1 = P3^0;
sbit col_2 = P3^1;
sbit col_3 = P3^2;
sbit col_4 = P3^3;

//P3 Higher nibbles are connected to rows of the keyboard
sbit row_1 = P3^4;
sbit row_2 = P3^5;
sbit row_3 = P3^6;
sbit row_4 = P3^7;

char col_1_state,col_2_state,col_3_state,col_4_state;
unsigned char iterator;
//void msdelay(unsigned int time); //use this function for delay in milliseconds
//void lcd_init(); //use it to initialize lcd
//void write_data(unsigned char _data); //writing character or data to lcd the data will get displayed on the lcd
//void write_command(unsigned char comm);//sending commands to lcd

void main()
{
	RS = RW = EN = 0;
	/****************************************/
	//set all columns high
	col_1_state = 1;
	col_2_state = 1;
	col_3_state = 1;
	col_4_state = 1;
	/****************************************/
	
	/****************************************/
	//implement the function to initialize lcd here
	lcd_init();
	
	/****************************************/
	
	P3 = 0x0F;
	while (1)
	{
	
		if (P3 < 0x0F) //checking whether some key is pressed or not
			{
				//Add an delay of 200 ms for debouncing the keys
				msdelay(200);
				
				
				if ( P3 < 0x0F) //checking whether still some key is pressed or not after debounce
				{
					P3 =  0xE0| 0x0F; //fill in an hex number such that row 1 becomes zero and rest of the rows are still high
					
					
					 if (col_1==0) //check whether col_1 is zero or not
					 {
						 //call a function to write character 1 to the lcd display
						 lcd_write_char('1');
						 continue;
					 }
					 else if (col_2 == 0)
					 {
						 //call a function to write character 2 to the lcd display
						 lcd_write_char('2');
						 continue;
					 }
					 else if (col_3==0)  //check whether col_3 is zero or not
					 {
						 //call a function to write character 3 to the lcd display
						 lcd_write_char('3');
						 continue;
					 }
					 else if (col_4==0)  //check whether col_4 is zero or not
					 {
						 //call a function to write character A to the lcd display
						 lcd_write_char('A');
						 continue;
					 }
					 
					 P3 =  (0xD0)| 0x0F; //fill in an hex number such that row 2 becomes zero and rest of the rows are still high
					 
					 if (col_1 == 0)
					 {
						 //call a function to write character 4 to the lcd display
						lcd_write_char('4');
						 continue;
					 }
					 else if (col_2==0)  //check whether col_2 is zero or not
					 {
						 //call a function to write character 5 to the lcd display
						 lcd_write_char('5');
						 continue;
					 }
					 else if (col_3==0)  //check whether col_3 is zero or not
					 {
						 //call a function to write character 6 to the lcd display
						 lcd_write_char('6');
						 continue;
					 }
					 else if ( col_4 == 0)
					 {
						 //call a function to write character B to the lcd display
						 lcd_write_char('B');
						 continue;
					 }
					 
					 P3 =  0xB0| 0x0F; //fill in an hex number such that row 3 becomes zero and rest of the rows are still high

					 if (col_1==0)  //check whether col_1 is zero or not
					 {
						 //call a function to write character 7 to the lcd display
						 lcd_write_char('7');
						 continue;
					 }
					 else if (col_2 == 0)
					 {
						 //call a function to write character 8 to the lcd display
						 lcd_write_char('8');
						 continue;
					 }
					 else if (col_3 == 0)
					 {
						 //call a function to write character 9 to the lcd display
						 lcd_write_char('9');
						 continue;
					 }
					 else if (col_4==0)  //check whether col_4 is zero or not
					 {
						 //call a function to write character C to the lcd display
						 lcd_write_char('C');
						 continue;
					 }
					
					 P3 =  0x70| 0x0F; //fill in an hex number such that row 4 becomes zero and rest of the rows are still high
					 
					 if (col_1 == 0)
					 {
						 //call a function to write character 0 to the lcd display
						 lcd_write_char('0');
						 continue;
					 }
					 else if (col_2 == 0)
					 {
						 //call a function to write character + to the lcd display
						 lcd_write_char('+');
						 continue;
					 }
					 else if (col_3 == 0)
					 {
						 //call a function to write character - to the lcd display
						 lcd_write_char('-');
						 continue;
					 }
					 else if ( col_4 == 0)
					 {
						 //call a function to write character D to the lcd display
						 lcd_write_char('D');
						 continue;
					 }
					
					
				}
				else
				{
					P3 = 0x0F;
				}
			}
			else P3 = 0x0F;
  }
	return;
}


