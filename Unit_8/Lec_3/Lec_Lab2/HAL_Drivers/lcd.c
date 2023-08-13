/*
 * lcd.c
 *
 *  Created on: May 25, 2023
 *      Author: omart
 */

#include"lcd.h"
#include"STM32F103_C6_GPIO_Driver.h"



GPIO_Pin_init_t pincnfg;


void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void LCD_Kick(void)
{
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, ENB, 1);
	delay_ms(50);
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, ENB, 0);
}


void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCMND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCMND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
	if (line == 3)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCMND(LCD_BEGIN_AT_THIRD_ROW + position);
		}
	}
	if (line == 4)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCMND(LCD_BEGIN_AT_FORTH_ROW + position);
		}
	}
}


void LCD_isBusy(void){


	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__0;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__1;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__2;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__3;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__4;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__5;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__6;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	pincnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pincnfg.PIN_NUM	 = PIN_NUM__7;
	MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RW, 1);
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RS, 0);
	LCD_Kick();

	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RW, 0);
}






void LCD_GPIO_Init(void){

		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = RS;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_CNTRL, &pincnfg);

		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = RW;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_CNTRL, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = ENB;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_CNTRL, &pincnfg);

//===========================================================


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__0;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__1;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__2;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__3;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__4;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__5;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__6;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);


		pincnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
		pincnfg.PIN_NUM	 = PIN_NUM__7;
		pincnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
		MCAL_GPIO_INIT(LCD_PORT, &pincnfg);

//===========================================================

		MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RS, 0);
		MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RW, 0);
		MCAL_GPIO_WRITE_PIN(LCD_CNTRL, ENB, 0);
}




void LCD_Init(void)
{

	delay_ms(20);
	LCD_GPIO_Init();
	delay_ms(15);

	LCD_SendCMND(LCD_CLEAR_SCREEN);
	LCD_SendCMND(LCD_FUNCTION_8BIT_2LINES);
	LCD_SendCMND(LCD_ENTRY_MODE);
	LCD_SendCMND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_SendCMND(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_SendCMND(unsigned char cmnd)
{
	MCAL_GPIO_WRITE_PORT(LCD_PORT, cmnd);
//	LCD_PORT->ODR = (uint8_t) cmnd;
//	LCD_PORT->ODR |= (cmnd << 0 );
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RW, 0);
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RS, 0);
	delay_ms(1);
	LCD_Kick();
}

void LCD_WriteChar(unsigned char data)
{
	MCAL_GPIO_WRITE_PORT(LCD_PORT, data);
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RW, 0);
	MCAL_GPIO_WRITE_PIN(LCD_CNTRL, RS, 1);
	delay_ms(1);
	LCD_Kick();
}



void LCD_WriteString(char* string)
{
	int count = 0;
	while (*string != '\0'){
		count++;
		LCD_WriteChar(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_GOTO_XY(3,0);
		}else if(count == 48)
		{
			LCD_GOTO_XY(4,0);
		}else if(count == 64)
		{
			LCD_SendCMND(LCD_CLEAR_SCREEN);
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}

