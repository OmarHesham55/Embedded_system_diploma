/*
 * Lab3.c
 *
 * Created: 5/19/2023 6:34:49 PM
 * Author : omart
 */ 

//7-Segments

// Common anode requires a LOW signal whereas common cathode requires a HIGH signal to light up a segment.


#define F_CPU		8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Utilities.h"

int main(void)
{
	// char arr[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		
	DDRC = 0xFF; // DIR of PORTC as Output;
	/*PORTC*/
	
   DDRC = 0xFF;
   unsigned char i,j;
   while(1)
   {
	   for(i=0;i<10;i++)
	   {
		   for(j=0;j<10;j++)
		   {
			   PORTC = (0b1011)| (i<<4);
			   _delay_ms(200);
			   PORTC = (0b0111)| (j<<4);
			   _delay_ms(200);
		   }
		   
	   }
   }
}

