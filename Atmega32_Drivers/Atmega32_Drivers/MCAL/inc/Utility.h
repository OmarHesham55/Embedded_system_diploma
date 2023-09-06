/*
 * Utility.h
 *
 * Created: 9/4/2023 4:29:32 PM
 *  Author: omart
 */ 


#ifndef UTILITY_H_
#define UTILITY_H_

#define PIN_NUMBER_0				0
#define PIN_NUMBER_1				1
#define PIN_NUMBER_2				2
#define PIN_NUMBER_3				3
#define PIN_NUMBER_4				4
#define PIN_NUMBER_5				5
#define PIN_NUMBER_6				6
#define PIN_NUMBER_7				7
#define PIN_NUMBER_ALL				0xFF

#define Pin_HIGH						1
#define Pin_LOW							0

#define TOGGLE_PIN(reg,pin)				reg ^= (1<<pin)
#define SET_PIN(reg,pin)				reg |= (1<<pin)
#define RESET_PIN(reg,pin)				reg &= ~(1<<pin)
#define READ_PIN(reg,pin)				((reg>>pin) & 1)			


#endif /* UTILITY_H_ */