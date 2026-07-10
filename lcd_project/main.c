#include "twi.h"
#include "pcf8574.h"
#include "lcd.h"
#include "uart.h"
#include "songs.h"
#define CLR 0x01
int main (){

    TWI_init();
    UART_init();
    LCD_init();

    LCD_cmd(0x80);
    msdelay(2);
    LCD_string(" KARAOKE PARTY !! ");
    msdelay(2000);
		char c;
		
		
		UART_sendstr("************************\r\n");
		UART_sendstr("************************\r\n");
		UART_sendstr("***!! KARAOKE PARTY !!**\r\n");
		UART_sendstr("************************\r\n");
		UART_sendstr("************************\r\n");
		UART_sendstr("                        \r\n");
        UART_sendstr("1. Fate of Ophelia\r\n");
        UART_sendstr("2. You Belong With Me\r\n");
        UART_sendstr("                        \r\n");

        while(1){

            
            UART_sendstr("Type in the song number to select the song:\r\n");
            UART_sendstr("                        \r\n");
            LCD_cmd(CLR);
            msdelay(2);
            LCD_string("Select a song");

            c = UART_recv();

            switch(c){

                case '1' : UART_sendstr("NOW PLAYING: Fate of Ophelia\r\n");
                Fate_of_Ophelia();

                break;

                case '2' : UART_sendstr("NOW PLAYING: You Belong With Me\r\n");
                You_Belong_With_Me();
                break;

                default : UART_sendstr("Enter a valid song number\r\n");
                LCD_cmd(CLR);
                msdelay(2);
                LCD_string("Invalid Number");   
                msdelay(3000);
                break;
            }
		
        }
		
	}
        
        
           
