/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"STM_C6_Driver.h"
#include"STM32F103_C6_GPIO_Driver.h"

void waiting(int x){
	unsigned int i , j;

	for(i =0;i<x;i++){
		for(j=0;j<500;j++);
	}
}

void enable_clock(){
	ENB_PORTA();
	ENB_PORTB();
}

void GPIO_init(){

	GPIO_Pin_init_t PinCnfg;

	PinCnfg.PIN_NUM = PIN_NUM__1;
	PinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	MCAL_GPIO_INIT(GPIOA, &PinCnfg);

	PinCnfg.PIN_NUM = PIN_NUM__13;
	PinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
	MCAL_GPIO_INIT(GPIOA, &PinCnfg);

	PinCnfg.PIN_NUM = PIN_NUM__1;
	PinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &PinCnfg);


	PinCnfg.PIN_NUM = PIN_NUM__13;
	PinCnfg.PIN_MODE = GPIO_MODE_PUSH_PULL_OP;
	PinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &PinCnfg);
}

int main(void)
{
	enable_clock();
	GPIO_init();

	while(1){

		if( MCAL_GPIO_READ_PIN(GPIOA, PIN_NUM__1) == 0 ){
			MCAL_GPIO_TOGGLE_PIN(GPIOB, PIN_NUM__1);
			while( MCAL_GPIO_READ_PIN(GPIOA, PIN_NUM__1) == 0);
		}

		if( MCAL_GPIO_READ_PIN(GPIOA, PIN_NUM__13) == 1 ){
			MCAL_GPIO_TOGGLE_PIN(GPIOB, PIN_NUM__13);
		}

		waiting(1);
	}


}

