/*
 * Lab2.c
 *
 * Created: 5/10/2023 5:17:15 PM
 * Author : omart
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void GPIO_Init(void){
	// Pins 2 3 in PORTD as input
	DDRD &= ~(1<<2);
	DDRD &= ~(1<<3);
	
	//Pins 5,6,7 in PortD as output
	DDRD |= (1<<PIND5) | (1<<PIND6) | (1<<PIND7);	
	
	// Pin 2 in PORTB as input
	DDRB &=~(1<<PINB2);
}
	
void EXTI_INIT(void){
	
	// Configure INT0 as any logical change
	MCUCR |= (1<<ISC00);
	MCUCR &=~(1<<ISC01);
	
	// Configure INT1 as Raising edge
	MCUCR |= (1<<ISC10) | (1<<ISC11);
	MCUCR &=~(1<<ISC01);
	
	// Configure INT2 as falling edge
	MCUCSR &=~(1<<ISC2);
	
	GICR |= (1<< INT0) | (1<<INT1) | (1<<INT2); // Enable interrupt 1,2,3
	
	sei(); /*Enable the global interrupt*/

}	


ISR(INT0_vect){
	PORTD ^= (1<<PIND5);
	_delay_ms(1000);
	PORTD ^= (1<<PIND5);
}

ISR(INT1_vect){
		PORTD ^= (1<<PIND6);
		_delay_ms(1000);
		PORTD ^=(1<<PIND6);
}

ISR(INT2_vect){
	PORTD ^= (1<<PIND7);
	_delay_ms(1000);
	PORTD ^=(1<<PIND7);
}
int main(void)
{
	GPIO_Init();
	EXTI_INIT();
    /* Replace with your application code */
    while (1) 
    {
    }
}

