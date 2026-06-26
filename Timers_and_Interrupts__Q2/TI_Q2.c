#include <reg51.h>

sbit W1 = P3^6;
sbit W2 = P3^7;

/*oid timer0_ISR(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;

    W1 = !W1;
}

void timer1_ISR(void) interrupt 3
{
    TH1 = 0xFA;
    TL1 = 0x24;

    W2 = !W2;
}*/

void timer0_ISR(void) interrupt 1
{
    TH0 = 0xF8;
    TL0 = 0x30;

    W1 = !W1;
}

void timer1_ISR(void) interrupt 3
{
    TH1 = 0xF4;
    TL1 = 0x48;

    W2 = !W2;
}

void main()
{
    TMOD = 0x11;

    TH0 = 0xF8;
    TL0 = 0x30;
	
TH1 = 0xF4;
    TL1 = 0x48;
    
    EA  = 1;
    ET0 = 1;
    ET1 = 1;

    TR0 = 1;
    TR1 = 1;

    while(1);
}