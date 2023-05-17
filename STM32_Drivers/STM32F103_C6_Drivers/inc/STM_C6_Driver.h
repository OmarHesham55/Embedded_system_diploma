/*
 * STM_C6_Driver.h
 *
 *  Created on: May 16, 2023
 *      Author: omart
 */

#ifndef INC_STM_C6_DRIVER_H_
#define INC_STM_C6_DRIVER_H_

//------------------------------
//Includes
//------------------------------
#include<stdint.h>
#include<stdio.h>
#include"Utility.h"
//------------------------------
//Base Addresses for Memory
//------------------------------

#define Flash_Memory_Base 								0x08000000UL
#define System_Memory_Base								0x1FFFF000UL
#define SRAM_Base										0x20000000UL
#define Perihpheral_Base								0x40000000UL
#define Cortex_M3_Internal_Base							0xE0000000UL

//*********************************************************************
//*********************************************************************

//------------------------------
//Base Addresses for Peripherals
//------------------------------

#define GPIOA_BASE										0x40010800UL
#define GPIOB_BASE										0x40010C00UL
#define GPIOC_BASE										0x40011000UL
#define GPIOD_BASE										0x40011400UL
#define AFIO_BASE										0x40010000UL
#define	RCC_BASE										0x40021000UL
#define	EXTI_BASE										0x40010400UL

//*********************************************************************
//*********************************************************************

//------------------------------
//Peripheral Registers::GPIO
//------------------------------

typedef struct{
	volatile	uint32_t	CRL;
	volatile	uint32_t	CRH;
	volatile	uint32_t	IDR;
	volatile	uint32_t	ODR;
	volatile	uint32_t	BSRR;
	volatile	uint32_t	BRR;
	volatile	uint32_t	LCKR;
}GPIO_REG_t;

//*********************************************************************
//*********************************************************************

//------------------------------
//Peripheral Registers::RCC
//------------------------------
typedef struct{
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CIR;
	volatile	uint32_t	APB2RSTR;
	volatile	uint32_t	APB1RSTR;
	volatile	uint32_t	AHBENR;
	volatile	uint32_t	APB2ENR;
	volatile	uint32_t	APB1ENR;
	volatile	uint32_t	BDCR;
	volatile	uint32_t	CSR;
	volatile 	uint32_t 	AHBSTR;
	volatile	uint32_t 	CFGR2;
}RCC_REG_t;


//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Registers::AFIO
//------------------------------
typedef struct{
	volatile	uint32_t	EVCR;
	volatile	uint32_t	MAPR;
	volatile	uint32_t	EXTICR1;
	volatile	uint32_t	EXTICR2;
	volatile	uint32_t	EXTICR3;
	volatile	uint32_t	EXTICR4;
	volatile	uint32_t	Reserved;
	volatile	uint32_t	MAPR2;
}AFIO_REG_t;


//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Registers::EXTI
//------------------------------
typedef struct{
	volatile	uint32_t	IMR;
	volatile	uint32_t	EMR;
	volatile	uint32_t	RTSR;
	volatile	uint32_t	FTSR;
	volatile	uint32_t	SWIER;
	volatile	uint32_t	PR;
}EXTI_REG_t;


//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Instants::
//------------------------------

#define GPIOA		 	((GPIO_REG_t *)GPIOA_BASE)
#define GPIOB		 	((GPIO_REG_t *)GPIOB_BASE)
#define GPIOC		 	((GPIO_REG_t *)GPIOC_BASE)
#define GPIOD		 	((GPIO_REG_t *)GPIOD_BASE)
#define RCC				((RCC_REG_t  *)RCC_BASE)
#define AFIO			((AFIO_REG_t *)AFIO_BASE)
#define EXTI			((EXTI_REG_t *)EXTI_BASE)


//*********************************************************************
//*********************************************************************

//------------------------------
//Clock Macros::
//------------------------------

#define ENB_PORTA()							(RCC->APB2ENR = 1<<2);
#define ENB_PORTB()							(RCC->APB2ENR = 1<<3);
#define	ENB_PORTC()							(RCC->APB2ENR = 1<<4);
#define ENP_PORTD()							(RCC->APB2ENR = 1<<5);
#define ENB_AFIO()							(RCC->APB2ENR = 1<<0);


#endif /* INC_STM_C6_DRIVER_H_ */
