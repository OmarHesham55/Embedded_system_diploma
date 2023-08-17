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

//*********************************************************************
//*********************************************************************

//------------------------------
//Base Addresses for Memory
//------------------------------

#define Flash_Memory_Base 								0x08000000UL
#define System_Memory_Base								0x1FFFF000UL
#define SRAM_Base										0x20000000UL
#define Perihpheral_Base								0x40000000UL
#define Cortex_M3_Internal_Base							0xE0000000UL
#define NVIC_BASE										0xE000E100UL
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
#define USART1_BASE										0x40013800UL
#define USART2_BASE										0x40004400UL
#define USART3_BASE										0x40004800UL
#define USART4_BASE										0x40004C00UL
#define USART5_BASE										0x40005000UL
#define SPI1_BASE										0x40013000UL
#define SPI2_BASE										0x40003800UL
#define SPI3_BASE										0x40003C00UL


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
	volatile	uint32_t	EXTICRx[4];
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
	volatile	uint32_t	RSTR;
	volatile	uint32_t	FSTR;
	volatile	uint32_t	SWIER;
	volatile	uint32_t	PR;
}EXTI_REG_t;


//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Registers::UART
//------------------------------

typedef struct{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}USART_REG_t;

//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Registers::SPI
//------------------------------

typedef struct{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;

}SPI_REG_t;

//*********************************************************************
//*********************************************************************


//------------------------------
//Peripheral Instants::
//------------------------------

#define GPIOA		 		((GPIO_REG_t *)GPIOA_BASE)
#define GPIOB		 		((GPIO_REG_t *)GPIOB_BASE)
#define GPIOC		 		((GPIO_REG_t *)GPIOC_BASE)
#define GPIOD		 		((GPIO_REG_t *)GPIOD_BASE)
#define RCC					((RCC_REG_t  *)RCC_BASE)
#define AFIO				((AFIO_REG_t *)AFIO_BASE)
#define EXTI				((EXTI_REG_t *)EXTI_BASE)
#define NVIC_ISER0			*(volatile uint32_t *)(NVIC_BASE + 0x00)
#define NVIC_ISER1			*(volatile uint32_t *)(NVIC_BASE + 0x04)
#define NVIC_ISER2			*(volatile uint32_t *)(NVIC_BASE + 0x08)
#define NVIC_ICER0			*(volatile uint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1			*(volatile uint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2			*(volatile uint32_t *)(NVIC_BASE + 0x88)
#define USART1				((USART_REG_t *)USART1_BASE)
#define USART2				((USART_REG_t *)USART2_BASE)
#define USART3				((USART_REG_t *)USART3_BASE)
#define SPI1				((SPI_REG_t *)SPI1_BASE)
#define SPI2				((SPI_REG_t *)SPI2_BASE)
#define SPI3				((SPI_REG_t *)SPI3_BASE)

//*********************************************************************
//*********************************************************************


//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Vector Table:
//-*-*-*-*-*-*-*-*-*-*-*
/*
 * EXTI
 */

#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40

//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Vector Table:
//-*-*-*-*-*-*-*-*-*-*-*
/*
 * USART
 */
#define	USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39

//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Vector Table:
//-*-*-*-*-*-*-*-*-*-*-*
/*
 * SPI
 */

#define SPI1_IRQ			35
#define SPI2_IRQ			36
#define SPI3_IRQ			51

//------------------------------
//Clock Macros::
//------------------------------

/*
 * Enable Peripherals CLocks::GPIO
 * */
#define ENB_PORTA()							(RCC->APB2ENR |= 1<<2)
#define ENB_PORTB()							(RCC->APB2ENR |= 1<<3)
#define	ENB_PORTC()							(RCC->APB2ENR |= 1<<4)
#define ENP_PORTD()							(RCC->APB2ENR |= 1<<5)
#define ENB_AFIO()							(RCC->APB2ENR |= 1<<0)

/*
 * Enable Peripherals CLocks::USART
 * */
#define ENB_USART1()						(RCC->APB2ENR |= 1<<14)
#define ENB_USART2()						(RCC->APB1ENR |= 1<<17)
#define ENB_USART3()						(RCC->APB1ENR |= 1<<18)
#define ENB_USART4()						(RCC->APB1ENR |= 1<<19)
#define ENB_USART5()						(RCC->APB1ENR |= 1<<20)

/*
 * Enable Peripherals CLocks::SPI
 * */
#define ENB_SPI1()							(RCC->APB2ENR |= 1<<12)
#define ENB_SPI2()							(RCC->APB1ENR |= 1<<14)
#define ENB_SPI3()							(RCC->APB1ENR |= 1<<15)


/*
 * Reset Peripherals CLocks :: USART
 * */
#define RES_USART1()						(RCC->APB2RSTR |= 1<<14)
#define RES_USART2()						(RCC->APB1RSTR |= 1<<17)
#define RES_USART3()						(RCC->APB1RSTR |= 1<<18)

/*
 * Reset Peripherals CLocks :: SPI
 * */
#define RES_SPI1()							(RCC->APB2RSTR |= 1<<12)
#define RES_SPI2()							(RCC->APB1RSTR |= 1<<14)
#define RES_SPI3()							(RCC->APB1RSTR |= 1<<15)

//Enable NVIC_IRQ
#define NVIC_IRQ6_EXTI0_EN()			(NVIC_ISER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_EN()			(NVIC_ISER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_EN()			(NVIC_ISER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_EN()			(NVIC_ISER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_EN()			(NVIC_ISER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_EN()			(NVIC_ISER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC
#define NVIC_IRQ40_EXTI10_15_EN()		(NVIC_ISER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15

/*
 * USART
 **/
#define NVIC_IRQ37_USART1_EN()			(NVIC_ISER1 |= 1<<5)
#define NVIC_IRQ38_USART2_EN()			(NVIC_ISER1 |= 1<<6)
#define NVIC_IRQ39_USART3_EN()			(NVIC_ISER1 |= 1<<7)


/*
 * SPI
 **/
#define NVIC_IRQ35_SPI1_EN()			(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_EN()			(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))


/*Disable:
 *
 * NVIC_IRQ
 * */
//Disable NVIC_IRQ
#define NVIC_IRQ6_EXTI0_DIS()				(NVIC_ICER0 |= 1<<6)					// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_DIS()				(NVIC_ICER0 |= 1<<7)					// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_DIS()				(NVIC_ICER0 |= 1<<8)					// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_DIS()				(NVIC_ICER0 |= 1<<9)					// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_DIS()				(NVIC_ICER0 |= 1<<10)					// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_DIS()			(NVIC_ICER0 |= 1<<23)					// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC
#define NVIC_IRQ40_EXTI10_15_DIS()			(NVIC_ICER1 |= 1<<8)					// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																					//  ---> PIN40 in NVIC
#define NVIC_IRQ37_USART1_DIS()				(NVIC_ICER1 |= 1<<5)
#define NVIC_IRQ38_USART2_DIS()				(NVIC_ICER1 |= 1<<6)
#define NVIC_IRQ39_USART3_DIS()				(NVIC_ICER1 |= 1<<7)


#define NVIC_IRQ35_SPI1_DIS()			(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_DIS()			(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))



//------------------------------
//Generic Macros::
//------------------------------

#endif /* INC_STM_C6_DRIVER_H_ */
