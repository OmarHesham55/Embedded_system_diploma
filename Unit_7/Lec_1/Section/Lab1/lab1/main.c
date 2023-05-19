/*
 * lab1.c
 *
 * Created: 5/19/2023 6:29:50 PM
 * Author : omart
 */ 


#define F_CPU		8000000UL

#include "Utilities.h"
#include "util/delay.h"
#include <avr/io.h>


int main(void)
{
	//PORTA pins ====> Output
	DDRA = 0xFF;
	while (1)
	{
			SET_BIT(PORTA,0);
			_delay_ms(100);
			SET_BIT(PORTA,1);
			_delay_ms(100);
			SET_BIT(PORTA,2);
			_delay_ms(100);
			SET_BIT(PORTA,3);
			_delay_ms(100);
			SET_BIT(PORTA,4);
			_delay_ms(100);
			CLEAR_BIT(PORTA,0);
			CLEAR_BIT(PORTA,1);
			CLEAR_BIT(PORTA,2);
			CLEAR_BIT(PORTA,3);
			CLEAR_BIT(PORTA,4);
			_delay_ms(100);									

		
	}
}

