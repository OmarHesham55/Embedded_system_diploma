/*
 * keypad.c
 *
 *  Created on: May 25, 2023
 *      Author: omart
 */

#include"keypad.h"
#include"STM32F103_C6_GPIO_Driver.h"

int KEYPAD_R [] = {R0,R1,R2,R3};
int KEYPAD_C [] = {C0,C1,C2,C3};

void KEYPAD_GPIO_Init(void){

	GPIO_Pin_init_t	PinConfig;

	PinConfig.PIN_NUM = R0;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = R1;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = R2;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = R3;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = C0;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = C1;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	PinConfig.PIN_NUM = C2;
	PinConfig.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinConfig.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_PORT, &PinConfig);

	MCAL_GPIO_WRITE_PORT(KEYPAD_PORT,0xFF);
}


char KEYPAD_Send(void){
	int i,j;

	for(i=0; i<4; i++){

		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_C[0], PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_C[1], PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_C[2], PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_C[3], PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_C[i], PIN_RESET);

		for(j=0;j<4;j++)
		{
			if( MCAL_GPIO_READ_PIN(KEYPAD_PORT, KEYPAD_R[j]) == 0 ){														//!(KEYPAD_PIN & (1<<KEYPAD_R[j]))
				while( MCAL_GPIO_READ_PIN(KEYPAD_PORT, KEYPAD_R[j]) == 0);

				switch (i)
				{
				case (0):
						if(j == 0) return '7';
						else if(j == 1) return '8';
						else if(j == 2) return '9';
						else if(j == 3) return '/';
				break;

				case (1):
						if(j == 0) return '4';
						else if(j == 1) return '5';
						else if(j == 2) return '6';
						else if(j == 3) return '*';
				break;


				case (2):
						if(j == 0) return '1';
						else if(j == 1) return '2';
						else if(j == 2) return '3';
						else if(j == 3) return '-';
				break;


				case (3):
						if(j == 0) return '?';
						else if(j == 1) return '0';
						else if(j == 2) return '=';
						else if(j == 3) return '+';
				break;
				}
			}
		}
	}

	return 'N';
}
