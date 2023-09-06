/*
 * GPIO.c
 *
 * Created: 9/4/2023 4:28:31 PM
 *  Author: omart
 */ 

#include "inc/GPIO.h"

void MCAL_GPIO_Init(Pin_Init_t* pinInit)
{
	if (pinInit->pinNumber != PIN_NUMBER_ALL)
	{
		switch (pinInit->pinDirection)
		{
			case input_e:
	
			switch (pinInit->GPIOx)
			{
				case PORTA_e:
				DDRA &= ~(1<<pinInit->pinNumber);
				break;
		
				case PORTB_e:
				DDRB &= ~(1<<pinInit->pinNumber);
				break;
		
				case PORTC_e:
				DDRC &= ~(1<<pinInit->pinNumber);
				break;
		
				case PORTD_e:
				DDRD &= ~(1<<pinInit->pinNumber);
				break;
			}
			break;
	
			case output_e:
			
			switch (pinInit->GPIOx)
			{
				case PORTA_e:
				DDRA |= (1<<pinInit->pinNumber);
				break;
		
				case PORTB_e:
				DDRB |= (1<<pinInit->pinNumber);
				break;
		
				case PORTC_e:
				DDRC |= (1<<pinInit->pinNumber);
				break;
		
				case PORTD_e:
				DDRD |= (1<<pinInit->pinNumber);
				break;
			}
	
			break;
		}		
	} 
	
	else if(pinInit->pinNumber == PIN_NUMBER_ALL)
	{
		switch (pinInit->pinDirection)
		{
		case input_e:
		
			switch (pinInit->GPIOx)
			{
			case PORTA_e:
				DDRA = 0x00;
				break;
				
			case PORTB_e:
				DDRB = 0x00;
				break;
				
			case PORTC_e:
				DDRC = 0x00;
				break;
				
			case PORTD_e:
				DDRD = 0x00;
				break;				
			}
			break;
			
		case output_e:
			switch (pinInit->GPIOx)
			{
				case PORTA_e:
					DDRA = 0xFF;	
					break;
					
				case  PORTB_e:
					DDRB = 0xFF;
					break;
				
				case PORTC_e:
					DDRC = 0xFF;
					break;
				
				case PORTD_e:
					DDRD = 0xFF;
					break;			
			}			
			break;	
		}
	}

}
void MCAL_GPIO_DeInit(enum PORTx GPIOx)
{
	if(GPIOx == PORTA_e)
	{
		PORTA	= 0x00;
		DDRA	= 0x00;
	}
	else if(GPIOx == PORTB_e)
	{
		PORTB	= 0x00;
		DDRB	= 0x00;			
	}
	else if(GPIOx == PORTC_e)
	{
		PORTC	= 0x00;
		DDRC	= 0x00;		
	}
	else if(GPIOx == PORTD_e)
	{
		PORTD	= 0x00;
		DDRD	= 0x00;
	}
}
void MCAL_GPIO_SetPIN(enum PORTx GPIOx, uint8_t pinNumber,uint8_t pinMode)
{
	switch (pinMode)
	{
	case Pin_LOW:

		if (GPIOx == PORTA_e)
		{
			PORTA &= ~(1<<pinNumber);
		}
		else if(GPIOx == PORTB_e)
		{
			PORTB &= ~(1<<pinNumber);
		}
		else if(GPIOx == PORTC_e)
		{
			PORTC &= ~(1<<pinNumber);
		}
		else if(GPIOx == PORTD_e)
		{
			PORTD &= ~(1<<pinNumber);
		}	
	break;
	
	case Pin_HIGH:
	
		if (GPIOx == PORTA_e)
		{
			PORTA |= (1<<pinNumber);
		}
		else if(GPIOx == PORTB_e)
		{
			PORTB |= (1<<pinNumber);
		}
		else if(GPIOx == PORTC_e)
		{
			PORTC |= (1<<pinNumber);
		}
		else if(GPIOx == PORTD_e)
		{
			PORTD |= (1<<pinNumber);
		}
	break;
	}
	
}
void MCAL_GPIO_SetPORT(enum PORTx GPIOx, uint8_t portDirection)
{
	
	switch (portDirection)
	{
		case Pin_LOW:
		
			if (GPIOx == PORTA_e)
			{
				PORTA = 0x00;
			}
			else if(GPIOx == PORTB_e)
			{
				PORTB = 0x00;
			}
			else if(GPIOx == PORTC_e)
			{
				PORTC = 0x00;
			}
			else if(GPIOx == PORTD_e)
			{
				PORTD = 0x00;
			}
		case Pin_HIGH:
		
			if (GPIOx == PORTA_e)
			{
				PORTA = 0xFF;
			}
			else if(GPIOx == PORTB_e)
			{
				PORTB = 0xFF;
			}
			else if(GPIOx == PORTC_e)
			{
				PORTC = 0xFF;
			}
			else if(GPIOx == PORTD_e)
			{
				PORTD = 0xFF;
			}
	}
	
}
void MCAL_GPIO_TogglePin(enum PORTx GPIOx, uint8_t pinNumber)
{
		if (GPIOx == PORTA_e)
		{
			PORTA ^= (1<<pinNumber);
		}
		else if(GPIOx == PORTB_e)
		{
			PORTB ^= (1<<pinNumber);
		}
		else if(GPIOx == PORTC_e)
		{
			PORTC ^= (1<<pinNumber);
		}
		else if(GPIOx == PORTD_e)
		{
			PORTD ^= (1<<pinNumber);
		}
	
}
void MCAL_GPIO_TogglePort(enum PORTx GPIOx)
{
	
		if (GPIOx == PORTA_e)
		{
			PORTA = ~PORTA;
		}
		else if(GPIOx == PORTB_e)
		{
			PORTB = ~PORTB;
		}
		else if(GPIOx == PORTC_e)
		{
			PORTC = ~PORTC;
		}
		else if(GPIOx == PORTD_e)
		{
			PORTD = ~PORTD;
		}
}
uint8_t MCAL_GPIO_ReadPin(enum PORTx GPIOx, uint8_t pinNumber)
{
	volatile uint8_t val;
	
		if (GPIOx == PORTA_e)
		{
			val = ((PINA>>pinNumber)&1);
		}
		else if(GPIOx == PORTB_e)
		{
			val = ((PINB>>pinNumber)&1);
		}
		else if(GPIOx == PORTC_e)
		{
			val = ((PINC>>pinNumber)&1);
		}
		else if(GPIOx == PORTD_e)
		{
			val = ((PIND>>pinNumber)&1);
		}

	return val;
}
