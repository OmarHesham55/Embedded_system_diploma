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
#define GPIOA_BASE	0x40010800
#define AFIO_BASE	0x40010000
#define EXTI_BASE	0x40010400
#define GPIOB_BASE	0x40010C00
//RCC
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)

//GPIOA
#define GPIOA_CRL	*(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_CRH	*(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_IDR	*(volatile uint32_t*)(GPIOA_BASE + 0x08)
#define GPIOA_ODR	*(volatile uint32_t*)(GPIOA_BASE + 0x0C)
#define GPIOA_BSRR  *(volatile uint32_t*)(GPIOA_BASE + 0x10)

//GPIOB
#define GPIOB_CRL	*(volatile uint32_t*)(GPIOB_BASE + 0x00)
#define GPIOB_CRH	*(volatile uint32_t*)(GPIOB_BASE + 0x04)
#define GPIOB_IDR	*(volatile uint32_t*)(GPIOB_BASE + 0x08)
#define GPIOB_ODR	*(volatile uint32_t*)(GPIOB_BASE + 0x0C)
#define GPIOB_BSRR  *(volatile uint32_t*)(GPIOB_BASE + 0x10)


//EXTI
#define EXTI_IMR	 	*(volatile uint32_t*)(EXTI_BASE + 0x00)
#define EXTI_RTSR	 	*(volatile uint32_t*)(EXTI_BASE + 0x08)
#define EXTI_PR		 	*(volatile uint32_t*)(EXTI_BASE + 0x14)
#define NVIC_ISR0		*(volatile uint32_t*)(0xE000E100)

void clock_enable(void){
	//IOPA & IOPB are enabled
	RCC_APB2ENR |= (1<<3) | (1<<2);
}

void GPIO_ENB(void){
	// Configure PinA 1,13 as input
//PinA1
	GPIOA_CRL &=~(0b11<<4);
	GPIOA_CRL |= (1<<6);
	GPIOA_CRL &=~(1<<4);
//PinA13
	GPIOA_CRL &=~(0b11<<20);
	GPIOA_CRL |= (1<<22);
	GPIOA_CRL &=~(1<<23);

	// Configure PinB 1,13 as output
//PinB1
	GPIOB_CRL |= (1<<4);
	GPIOB_CRL &=~(0b111<<5);
//PinB13
	GPIOB_CRH |= (1<<20);
	GPIOB_CRH &=~(0b111<<21);

}

void wait(int x){
	for(int i=0; i<x;i++){
		for(int j=0; j<500;j++);
	}
}

int main(void)
{
	clock_enable();
	GPIO_ENB();
	while(1){
			if( ( (GPIOA_IDR>>1) && 1 ) == 0 ){
				GPIOB_ODR ^= (1<<1);
				while(( (GPIOA_IDR>>1) && 1 ) == 0);
			}
			if( ( (GPIOA_IDR>>13) && 1 ) == 1 ){
				GPIOB_ODR ^= (1<<13);
			}

			wait(1);
	}
}


