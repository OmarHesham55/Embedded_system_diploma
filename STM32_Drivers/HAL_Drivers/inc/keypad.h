/*
 * keypad.h
 *
 *  Created on: May 25, 2023
 *      Author: omart
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include"Utility.h"

#define R0				PIN_NUM__0
#define R1				PIN_NUM__1
#define R2				PIN_NUM__3
#define R3				PIN_NUM__4
#define C0				PIN_NUM__5
#define C1				PIN_NUM__6
#define C2				PIN_NUM__7
#define C3				PIN_NUM__8

#define KEYPAD_PORT			GPIOB
void KEYPAD_GPIO_Init(void);
char KEYPAD_Send(void);

#endif /* INC_KEYPAD_H_ */
