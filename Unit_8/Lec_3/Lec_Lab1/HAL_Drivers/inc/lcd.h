/*
 * lcd.h
 *
 *  Created on: May 25, 2023
 *      Author: omart
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#define F_CPU 1000000UL
#include"STM32F103_C6_GPIO_Driver.h"
#include"Utility.h"

#define RS				PIN_NUM__8
#define RW				PIN_NUM__9
#define ENB				PIN_NUM__10

#define LCD_PORT		GPIOA
#define LCD_CNTRL		GPIOA




#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_BEGIN_AT_THIRD_ROW						(0x90)
#define LCD_BEGIN_AT_FORTH_ROW						(0xD0)



void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_SendCMND(unsigned char cmnd);
void LCD_WriteChar(unsigned char data);
void LCD_WriteString(char* string);
//void LCD_isBusy(void);
void LCD_Kick(void);
//void LCD_ClearScreen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);
//void LCD_INT_NUM(int value); // print integer value

#endif /* INC_LCD_H_ */
