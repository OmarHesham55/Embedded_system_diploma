/*
 * Lab2.c
 *
 * Created: 8/8/2023 9:40:26 PM
 * Author : omart
 */ 

#define F_CPU	1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define SCK		7
#define addr	0x0B
void SPI_MasterInit(void)
{
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK);
	
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
}

void max7221Send(unsigned char cmnd, unsigned char data)
{
	PORTB &= ~(1<<SS);	/* configure SS as LOW so we can write on it */
	SPDR = cmnd;		/* Write on SPDR the cmnd*/
	while(!(SPSR & (1<<SPIF)));	/* waiting for receiving would be complete*/
	SPDR = data;				/* Write the data*/
	while(!(SPSR & (1<<SPIF)));	/* waiting for receiving would be complete*/
	PORTB |= (1<<SS);		/* return SS to be high again*/
} 

int main(void)
{

	SPI_MasterInit();
	/*Decode Mode*/		max7221Send(0x09, 0xFF);	/*~0xFF~ to show the all 7 digits in each 7-Segments */
	/*Intensity */		max7221Send(0x0A, 0x0F);	/*Max on Intensity*/
	/*Scan Limit*/		//max7221Send(0x0B, 0x07);	/*Number of 7-Segments to display from 1~8*/
	/*Shutdown*/		max7221Send(0x0C, 0x01);	/*0:Shutdown  1:Normal Operation*/
	unsigned char counter = 0;
	while(1)
	{
// 		max7221Send(0x0B,0x00);
// 		max7221Send(0x01,1);
// 		_delay_ms(1000);

		for (char i = 0x00; i<0x09;i++)
		{
			max7221Send(addr,i);
			for(char indx = 0x01; indx < 0xA; indx++){
				while (counter != 9)
				{
					max7221Send(indx,counter++);
				}
				counter = 0;
			}
		}
	
	
	}
	
	

}

