
#include <reg51.h>

sbit OUT = P3^6;

void delay4ms()
{
    TH1 = 0xF0;
    TL1 = 0x60;

    TF1 = 0; //timer overflow flag- we clear it here. it becomes 1 whn the count is complete
    TR1 = 1; //timer run bbit when it is 1 the timer starts running

    while(TF1==0); //wait for the overfloe aka polling

    TR1 = 0; //stop the timer
    TF1 = 0; //reset the flag
}

void delay12ms()
{
    TH1 = 0xD1;
    TL1 = 0x20;

    TF1 = 0;
    TR1 = 1;

    while(TF1==0);

    TR1 = 0;
    TF1 = 0;
}

void main()
{
    TMOD = 0x10;      // T1 Mode 1

    while(1)
    {
        OUT = 1;
        delay4ms();

        OUT = 0;
        delay12ms();
    }
}