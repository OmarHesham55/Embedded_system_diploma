/*
 * Sec_Lab1.c
 *
 * Created: 8/15/2023 5:16:14 PM
 * Author : omart
 */ 

#define F_CPU 1000000UL
#define SPI_Slave
#include <avr/io.h>
#include "SPI/SPI.h"


int main(void)
{
		DDRA = 0xFF;
		unsigned char ch;
		#ifdef SPI_Slave
			SPI_SlaveInit();
			ch = 255;
			for (ch = 255; ch >= 0; ch--)
			{
				PORTA = SPI_SlaveReceiver(ch);
			}
		#endif

	#ifdef SPI_Master
		SPI_MasterInit();
		ch = 0;
		for(ch = 0; ch <= 255; ch++)
		{
			_delay_ms(1000);
			PORTA = SPI_MasterSend(ch);
		}
	#endif

}

