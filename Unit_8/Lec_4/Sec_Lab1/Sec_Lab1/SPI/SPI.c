/*
 * SPI.c
 *
 * Created: 8/15/2023 5:17:03 PM
 *  Author: omart
 */ 

#include "SPI.h"



void SPI_MasterInit(void)
{
	/*Set MOSI and SCK as Output*/
	DDRB |= (1<<MOSI) | (1<<CLK) | (1<<SS);
	
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

