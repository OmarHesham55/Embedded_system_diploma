/*
 * LCD.c
 *
 * Created: 8/12/2023 11:27:25 PM
 *  Author: omart
 */ 
#include "LCD.h"


void ENABLE(void){
	LCD_CTRL_PORT |=(1<<ENB);
	_delay_ms(50);
	LCD_CTRL_PORT &=~(1<<ENB);
}

void LCD_LINES(uint8_t line){
	
	if(line == 1)
	{
		LCD_Cmnd(LCD_BEGIN_FIRST_ROW);
		}
		else if( line == 2)
		{
		LCD_Cmnd(LCD_BEGIN_SECOND_ROW);
		}
}

void LCD_init(void){
	LCD_DATA_DIR	= 0xFF;
	LCD_CTRL_DIR	= 0xFF;
	_delay_ms(50);
	LCD_Cmnd(LCD_8BIT_MODE);
	LCD_Cmnd(LCD_DISP_ON_CURSOR_BLINKING);
	LCD_Cmnd(LCD_CLEAR_SCREEN);
	LCD_Cmnd(LCD_ENTRY_INC);
	LCD_Cmnd(LCD_BEGIN_FIRST_ROW);
}


void LCD_Cmnd(unsigned char cmnd){
	
	LCD_DATA_PORT = cmnd;
	LCD_CTRL_PORT &=~( (1<<RS) | (1<<RW) );
	ENABLE();
	//LCD_DATA_PORT = 0;
	_delay_ms(3);
}

void LCD_Write_Char(unsigned char data){
	LCD_DATA_PORT  = data;
	LCD_CTRL_PORT |= (1<<RS);
	LCD_CTRL_PORT &=~(1<<RW);
	ENABLE();
	_delay_ms(1);
}

void LCD_Write_String(unsigned char* data){
	int count = 0;
	
	while(*data > 0){

		count++;
		LCD_Write_Char(*data++);
		
		if(count == 16){
			LCD_LINES(2);
		}
		else if(count == 32){
			LCD_Cmnd(LCD_CLEAR_SCREEN);
			LCD_LINES(1);
			count = 0;
		}
	}
}


void LCD_Write_Num(int num){
	char str[20];
	
	sprintf(str,"%d",num);
	
	LCD_Write_String(str);
}