/*
 * 7_SEG.c
 *
 *  Created on: Jul 22, 2023
 *      Author: omart
 */

#include "7_SEG.h"

void delay_m(int time){
	for(int i=0;i<time;i++){
		for(int j=0; j<255;j++);
	}
}
char SEG_NUM_arr[]={0x01,0x79,0x24,0x30,0x4C,0x12,0x02,0x19,0x00,0x10};

void SEG_GPIO_INIT(void)
{
	GPIO_Pin_init_t pinCnfg;
//	pinCnfg.PIN_NUM = PIN_NUM__ALL;
//	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
//	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
//
//	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__9;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__10;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__11 ;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__12 ;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__13 ;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__14 ;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);


	pinCnfg.PIN_NUM = PIN_NUM__15 ;
	pinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

	MCAL_GPIO_INIT(SGMNTS_PORT, &pinCnfg);

}

void SEG_NUMS(void){
	int i;
	for(i=0; i<10; i++){
		SGMNTS_PORT->ODR = SEG_NUM_arr[i]<<9;
//		MCAL_GPIO_WRITE_PORT(SGMNTS_PORT, SEG_NUM_arr[i] << 9);
		delay_m(100);
	}
}
