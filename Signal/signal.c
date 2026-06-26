#include <reg51.h>

void sdelay(unsigned int time) {
    int i, j, k;
    for (k = 0; k < time; k++) {
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 382; j++);
        }
    }
}

void msdelay(unsigned int time) {
    int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 382; j++);
    }
}

sbit RED    = P1^4;
sbit YELLOW = P1^5;
sbit GREEN  = P1^6;
sbit PED    = P1^7;

void main() {
    int k;              
    while (1) {
       
        RED    = 1;
        GREEN  = 0;
        YELLOW = 0;
        PED    = 1;
        sdelay(10);

        
        RED    = 0;
        GREEN  = 1;
        YELLOW = 0;
        PED    = 0;
        sdelay(5);

        
        RED    = 0;
        GREEN  = 0;
        YELLOW = 1;
        for (k = 0; k < 2; k++) {
            PED = 1;
            msdelay(500);
            PED = 0;
            msdelay(500);
        }
        PED = 0;    
    }
}