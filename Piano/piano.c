
#include <at89c5131.h>
#include <stdio.h>
#include <lcd.h>

unsigned int current_note;

sbit SOUND = P0^7;

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

char col_1_state, col_2_state, col_3_state, col_4_state;
unsigned char iterator;

//void msdelay(unsigned int time); //use this function for delay in milliseconds
//void lcd_init(); //use it to initialize lcd
//void write_data(unsigned char _data); //writing character or data to lcd the data will get displayed on the lcd
//void write_command(unsigned char comm);//sending commands to lcd

void music(void) interrupt 1
{
    TH0 = current_note >> 8;
    TL0 = current_note & 0xFF;

    SOUND = !SOUND;

    //TF0=0; this happens automatically in interrupts
}



void play_note(unsigned int note)
{
    current_note = note;

    TH0 = current_note >> 8;
    TL0 = current_note & 0xFF;

    TF0 = 0;
    TR0 = 1;
}

void stop_note(void)
{
    TR0 = 0;
    TF0 = 0;
    SOUND = 0;
}

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

    TMOD = 0x11;      // T0 Mode1, T1 Mode1
    EA   = 1;         // Global Interrupt Enable
    ET0  = 1;         // Enable Timer0 Interrupt
		//TR0=1;
    P3 = 0x0F;
	SOUND=0;
    while(1)
    {
			
        if(P3 < 0x0F) //checking whether some key is pressed or not
        {
            //Add an delay of 200 ms for debouncing the keys
            msdelay(200);

            if(P3 < 0x0F) //checking whether still some key is pressed or not after debounce
            {
                P3 = 0xEF; //row 1 low

                if(col_1 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("1 : Sa(low)");

                    play_note(0xEFB9);

                    while(col_1 == 0);

                    stop_note();
                    continue;
                }
                else if(col_2 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("2 : Re");

                    play_note(0xF188);

                    while(col_2 == 0);

                    stop_note();
                    continue;
                }
                else if(col_3 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("3 : Ga");

                    play_note(0xF2FA);

                    while(col_3 == 0);

                    stop_note();
                    continue;
                }
                else if(col_4 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("A");
                    continue;
                }

                P3 = 0xDF; //row 2 low

                if(col_1 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("4 : Ma");

                    play_note(0xF3CB);

                    while(col_1 == 0);

                    stop_note();
                    continue;
                }
                else if(col_2 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("5 : Pa");

                    play_note(0xF526);

                    while(col_2 == 0);

                    stop_note();
                    continue;
                }
                else if(col_3 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("6 : Dha");

                    play_note(0xF63C);

                    while(col_3 == 0);

                    stop_note();
                    continue;
                }
                else if(col_4 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("B");
                    continue;
                }

                P3 = 0xBF; //row 3 low

                if(col_1 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("7 : Ni");

                    play_note(0xF752);

                    while(col_1 == 0);

                    stop_note();
                    continue;
                }
                else if(col_2 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("8 : Sa(high)");

                    play_note(0xF7DD);

                    while(col_2 == 0);

                    stop_note();
                    continue;
                }
                else if(col_3 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("9");
                    continue;
                }
                else if(col_4 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("C");
                    continue;
                }

                P3 = 0x7F; //row 4 low

                if(col_1 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("0");
                    continue;
                }
                else if(col_2 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("+");
                    continue;
                }
                else if(col_3 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("-");
                    continue;
                }
                else if(col_4 == 0)
                {
                    lcd_cmd(0x01);
                    lcd_write_string("D");
                    continue;
                }
            }
            else
            {
                P3 = 0x0F;
            }
        }
        else
        {
            P3 = 0x0F;
        }
    }
}
