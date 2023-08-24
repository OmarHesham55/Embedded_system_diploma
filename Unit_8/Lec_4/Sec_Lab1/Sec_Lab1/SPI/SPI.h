/*
 * SPI.h
 *
 * Created: 8/15/2023 5:17:18 PM
 *  Author: omart
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU	1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS				4
#define MOSI			5
#define MISO			6
#define CLK				7

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
unsigned char SPI_MasterSend(unsigned char Data);
unsigned char SPI_SlaveReceiver(unsigned char Data);


#endif /* SPI_H_ */