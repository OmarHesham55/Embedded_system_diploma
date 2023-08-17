/*
 * Lab1.c
 *
 * Created: 8/8/2023 6:49:52 PM
 * Author : omart
 */ 

#define F_CPU	1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCLK	7

			

void SPI_MasterInit(void)
{
	/*Set MOSI and SCK as Output*/
	DDRB |= (1<<MOSI) | (1<<SCLK) | (1<<SS);
	
	/*Set MISO As Input*/
	DDRB &= ~(1<<MISO);
	
	/* Enable the SPI,MSTR and fck/16 in SPCR */
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
}

unsigned char SPI_MasterSend(unsigned char Data)
{
	/*Start Transmit Data*/
	SPDR = Data;
	
	/*Wait until the transmission is complete*/
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

int main(void)
{
	DDRA = 0xFF;
	unsigned char ch = 0;
	SPI_MasterInit();
	
	for(ch = 0; ch <= 255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterSend(ch);
	}
}

