/*
 * LCD.h
 *
 * Created: 8/12/2023 11:27:34 PM
 *  Author: omart
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LCD_CTRL_PORT           PORTB
#define LCD_CTRL_DIR            DDRB
#define LCD_DATA_PORT           PORTA
#define LCD_DATA_DIR            DDRA

#define RS                      1
#define RW                      2
#define ENB                     3

//          **Commands**
#define LCD_8BIT_MODE               0x38
#define LCD_4BIT_MODE               0x28
#define LCD_ENTRY_INC               0x06
#define LCD_DISP_OFF                0x08
#define LCD_DISP_ON                 0x0E
#define LCD_DISP_ON_CURSOR_OFF      0x0C
#define LCD_DISP_ON_CURSOR_BLINKING 0x0F
#define LCD_CLEAR_SCREEN            0x01
#define LCD_BEGIN_FIRST_ROW         0x80
#define LCD_BEGIN_SECOND_ROW        0xC0


//          **APIS**

void LCD_init(void);
void LCD_Cmnd(unsigned char);
void LCD_Write_Char(unsigned char);
void LCD_Write_String(unsigned char*);
void LCD_Write_Num(int num);
void LCD_LINES(uint8_t line);




#endif /* LCD_H_ */