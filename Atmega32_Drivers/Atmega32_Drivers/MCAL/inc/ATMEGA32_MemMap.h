/*
 * ATMEGA32.h
 *
 * Created: 9/4/2023 4:29:07 PM
 *  Author: omart
 */ 


#ifndef ATMEGA32_MEMMAP_H_
#define ATMEGA32_MEMMAP_H_

#include<stdint.h>
#include<stdio.h>
#include "Utility.h"

/*
 ***GPIOA
 */
#define DDRA			*((volatile uint8_t*)0x3A)
#define PORTA			*((volatile uint8_t*)0x3B)
#define PINA			*((volatile uint8_t*)0x19)

/*
 ***GPIOB
 */
#define DDRB			*((volatile uint8_t*)0x37)
#define PORTB			*((volatile uint8_t*)0x38)
#define PINB			*((volatile uint8_t*)0x16)

/*
 ***GPIOC
 */
#define DDRC			*((volatile uint8_t*)0x34)
#define PORTC			*((volatile uint8_t*)0x35)
#define PINC			*((volatile uint8_t*)0x13)

/*
 ***GPIOD
 */
#define DDRD			*((volatile uint8_t*)0x31)
#define PORTD			*((volatile uint8_t*)0x32)
#define PIND			*((volatile uint8_t*)0x10)

//*********************************************************************
//*********************************************************************


/*
***EXTI
*/

#define GICR			*((volatile uint8_t*)0x5B)
#define MCUCR			*((volatile uint8_t*)0x55)
#define MCUCSR			*((volatile uint8_t*)0x54)
#define GIFR			*((volatile uint8_t*)0x5A)

#define INT0_Enable			GICR |= (1<<6)	
#define INT1_Enable			GICR |= (1<<7)
#define INT2_Enable			GICR |= (1<<5)

#define INTF0				6
#define INTF1				7
#define INTF2				5
#endif /* ATMEGA32_H_ */