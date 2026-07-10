#include "lcd.h"
#include "songs.h"

#define CLR 0x01
#define F_ROW 0x80//first row
#define S_ROW 0xC0 //second row

void Fate_of_Ophelia(){

LCD_cmd(CLR);
msdelay(5);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string("Keep it");

LCD_cmd(S_ROW);
msdelay(2);
LCD_string("1 hundred on");

msdelay(1300);

LCD_cmd(CLR);
msdelay(2);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string(" the land, ");

msdelay(1000);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string(" the sea, ");

msdelay(1000);

LCD_cmd(S_ROW);
msdelay(2);
LCD_string(" the ");

msdelay(200);

LCD_cmd(S_ROW);
msdelay(2);
LCD_string(" the sky ");

msdelay(500);

LCD_cmd(CLR);
msdelay(2);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string("pledge");

LCD_cmd(S_ROW);
msdelay(2);
LCD_string("allegiance to");

msdelay(1300);

LCD_cmd(CLR);
msdelay(2);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string(" your hands, ");

msdelay(1000);

LCD_cmd(F_ROW);
msdelay(2);
LCD_string(" your team, ");

msdelay(1000);

LCD_cmd(S_ROW);
msdelay(2);
LCD_string(" your ");

msdelay(200);

LCD_cmd(S_ROW);
msdelay(2);
LCD_string(" your vibes ");

msdelay(2000);

LCD_cmd(CLR);
msdelay(1000);
}

void You_Belong_With_Me(){
    
    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("If you");
    LCD_cmd(S_ROW);
    LCD_string("could see");
    msdelay(900);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("that I'm");
    LCD_cmd(S_ROW);
    LCD_string("the one");
    msdelay(1300);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("who");
    LCD_cmd(S_ROW);
    LCD_string("understands you");
    msdelay(1400);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("been here");
    LCD_cmd(S_ROW);
    LCD_string("all along");
    msdelay(1800);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("so why");
    LCD_cmd(S_ROW);
    LCD_string("can't you");
    msdelay(1300);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("see");
    msdelay(800);
    LCD_string("-ee");
    msdelay(700);
    LCD_string("-eee");
    msdelay(700);

    LCD_cmd(CLR);
    LCD_cmd(F_ROW);
    msdelay(2);
    LCD_string("You belong");
    LCD_cmd(S_ROW);
    LCD_string("with ");
    msdelay(1290);
    LCD_string("me");
    msdelay(800);
    LCD_string("-ee");
    msdelay(700);
    LCD_string("-eee");
    msdelay(2000);
    

}
