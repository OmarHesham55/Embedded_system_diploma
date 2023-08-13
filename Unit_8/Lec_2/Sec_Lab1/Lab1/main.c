/*
 * Lab1.c
 *
 * Created: 8/12/2023 11:24:17 PM
 * Author : omart
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD/LCD.h"
#include "UART/UART.h"

int main(void)
{
	uint8_t ch[50];
	LCD_init();
	UART_INIT();
	
	LCD_Write_String("UART MODE:");
	_delay_ms(500);
	LCD_Cmnd(LCD_CLEAR_SCREEN);
	LCD_Write_String("UART_Tx_Num: ");
	UART_Tx_Num(1911);
	LCD_Cmnd(LCD_BEGIN_SECOND_ROW);
	LCD_Write_String("UART_Tx_str: ");
	UART_Tx_String("HI");
	_delay_ms(1000);
	LCD_Cmnd(LCD_CLEAR_SCREEN);
	LCD_Cmnd(LCD_BEGIN_FIRST_ROW);
	LCD_Write_String("UART_Rx_Str: ");
	LCD_Cmnd(LCD_BEGIN_SECOND_ROW);
	while (1) {
		uart_receive_string_until_enter(ch, sizeof(ch));
		LCD_Write_String(ch);
		memset(ch,0,sizeof(ch));
		_delay_ms(100);
	}

}

