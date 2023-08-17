/*
 * Lab1_Slave.c
 *
 * Created: 8/8/2023 8:39:15 PM
 * Author : omart
 */ 

#define F_CPU	1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS			4
#define MOSI		5
#define MISO		6
#define CLK			7

void SPI_SlaveInit(void)
{
		/*SS,MOSI and clk as input*/
		DDRB &= ~(1<<SS) & ~(1<<MOSI) & ~(1<<CLK);
		
		/*MISO as output*/
		DDRB |= (1<<MISO);
		
		/*Set SPE , SPR0*/
		SPCR = (1<<SPE) ;
	}
	
unsigned char SPI_SlaveReceiver(unsigned char Data)
{
		SPDR = Data;
		
		/*Wait until Receiving is complete*/
		while(!(SPSR & (1<<SPIF)));
		
		return SPDR;
	}
int main(void)
{
	DDRA = 0xFF;
	unsigned char ch = 255;
	SPI_SlaveInit();
	for (ch = 255; ch >= 0; ch--)
	{
		PORTA = SPI_SlaveReceiver(ch);
	}
}

