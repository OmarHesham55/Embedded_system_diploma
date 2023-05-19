/*
 * lab1_led.c
 *
 * Created: 5/18/2023 9:42:16 PM
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

	//PORTD as Input Port
	DDRD = 0;
	PORTD = 0xFF;	// Making PORTD Pull-Up

while (1)
	{
		if (READ_BIT(PIND,2)==0)
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
				CLEAR_BIT(PORTA,4);
				_delay_ms(100);
				CLEAR_BIT(PORTA,3);
				_delay_ms(100);
				CLEAR_BIT(PORTA,2);
				_delay_ms(100);
				CLEAR_BIT(PORTA,1);
				_delay_ms(100);
				CLEAR_BIT(PORTA,0);
				_delay_ms(100);
		}
		else{
			PORTA = 0x00;
		}
		
	}
}