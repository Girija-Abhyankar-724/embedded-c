#include <reg51.h>
#include <lcd.h>


//OUTPUT PIN
sbit out = P0^7;

unsigned int notes[12]={
0xEFB9, 
0xEFB9, 
0xF188, 
0xEFB9, 
0xF3CA, 
0xF2FA, 
0xEFB9, 
0xEFB9, 
0xF188, 
0xEFB9, 
0xF526, 
0xF3CA  
};
	
unsigned int time[12]={
500,
500,
1000,
1000,
1000,
2000,
	500,
500,
1000,
1000,
1000,
2000
};

unsigned int current_note;

void music (void) interrupt 1{
	
	TH0=current_note>>8;
	TL0=current_note &0xFF;
	 
	out = !out;
	//TF0=0; this happens automatically in interrupts
}

void delay (unsigned int t){
	
unsigned int i;

for(i=0; i<t; i++){
TH1=0xFC;
	TL1=0x18;
	
	TF1=0;
	TR1=1;
	
	while(TF1==0);
	
	TR1=0;
	TF1=0;
}	
}


void main()
{
	unsigned int i;
    TMOD = 0x11;
		EA=1;
	ET0=1;
	
		
	
	while(1){
		lcd_init();

lcd_cmd(0x80);
lcd_write_string(" Happy Birthday ");
lcd_cmd(0xC0);
lcd_write_string(" Anirudh ^-^ !! ");
		
		for(i=0; i<12; i++){
			
			current_note = notes[i];
			
			TH0=current_note>>8;
			TL0= current_note&0xFF;
			
			//start the note
			TF0=0;
			TR0=1;
			
			delay(time[i]);
			
			//stop the note
			TR0=0;
			TF0=0;
			out=0;
			
			//add a tiny delay
			delay(50);
		
			
		}
	}
    
}
