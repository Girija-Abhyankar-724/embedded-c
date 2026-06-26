#include <reg51.h>

unsigned char sample[4];   
unsigned char encoded[4];   

void msdelay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 382; j++);
}

void take_inp() {
    unsigned char i;
    unsigned char high_nibble, low_nibble;
    unsigned char led_count = 1;

    P1 = 0x0F;

    for (i = 0; i < 4; i++) {
        
        P1 = (unsigned char)((led_count << 4) | 0x0F);
        msdelay(8000);
        high_nibble = (P1 & 0x0F) << 4;
        led_count++;  

        
        P1 = (unsigned char)((led_count << 4) | 0x0F);
        msdelay(8000);
        low_nibble = P1 & 0x0F;
        led_count++;

        sample[i] = high_nibble | low_nibble;
    }

    P1 = 0x0F;
}

void quant_enc() {
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (sample[i] < 64)
            encoded[i] = 0x01;
        else if (sample[i] < 128)
            encoded[i] = 0x02;
        else if (sample[i] < 192)
            encoded[i] = 0x04;
        else
            encoded[i] = 0x08;
    }
}

void led_disp() {
    unsigned char i;
    while (1) {
        for (i = 0; i < 4; i++) {
            P1 = (unsigned char)((encoded[i] << 4) | 0x0F);
            msdelay(4000);
        }
        P1 = 0x0F;
    }
}

void main() {
    take_inp();
    quant_enc();
    led_disp();
}