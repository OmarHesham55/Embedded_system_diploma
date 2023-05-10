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

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//BASE_ADDRESS
#define RCC_BASE	0x40021000
#define GPIO_BASE	0x40010800
#define AFIO_BASE	0x40010000
#define EXTI_BASE	0x40010400

//RCC
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)

//GPIO
#define GPIOx_CRL	*(volatile uint32_t*)(GPIO_BASE + 0x00)
#define GPIOx_CRH	*(volatile uint32_t*)(GPIO_BASE + 0x04)
#define GIOx_ODR	*(volatile uint32_t*)(GPIO_BASE + 0x0C)
//AFIO
#define AFIO_EXTICR1 *(volatile uint32_t*)(AFIO_BASE + 0x08)

//EXTI
#define EXTI_IMR	 	*(volatile uint32_t*)(EXTI_BASE + 0x00)
#define EXTI_RTSR	 	*(volatile uint32_t*)(EXTI_BASE + 0x08)
#define EXTI_PR		 	*(volatile uint32_t*)(EXTI_BASE + 0x14)
#define NVIC_ISR0		*(volatile uint32_t*)(0xE000E100)
void clock_enable(void){
	RCC_APB2ENR |= (1<<0) | (1<<2);
}

void GPIO_ENB(void){
	//Enable GPIO PinA0 as input
	GPIOx_CRL |= (0x4<<0);

	//Enable GPIO PinA13 as output
	GPIOx_CRH &= 0xFF0FFFFF;
	GPIOx_CRH |= 0x00200000;
}



int main(void)
{
	clock_enable();
	GPIO_ENB();

	AFIO_EXTICR1 |= 0x0;  	//These bits are written by software to select the source input for EXTIx external interrupt.

	EXTI_IMR |= (1<<0);		//Interrupt Mask on line 0
	EXTI_RTSR |= (1<<0);	// Rising trigger event configuration bit of line 0

	NVIC_ISR0 |= (1<<6);

	while(1);
}

void EXTI0_IRQHandler(void){
	GIOx_ODR ^= (1<<13);
	EXTI_PR |= (1<<0);
}
