/*
 * STM32F103_C6_RCC_Driver.c
 *
 *  Created on: Jul 29, 2023
 *      Author: omart
 */
#include "STM_C6_Driver.h"
#include "STM32F103_C6_RCC_Driver.h"

const uint8_t APBPrescTable[8U] = {0,0,0,0,1,2,3,4};
const uint16_t AHBPrescTable[16U] = {0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};

uint32_t MCAL_RCC_GET_SYSCLK(void)
{
	switch((RCC->CFGR>>2) & 0b11 )
	{
		case 0:
			return HSI_Clock;
			break;
		case 1:
			return HSE_Clock;
		case 2:
			return 16000000;
		default:
			break;
	}
}

uint32_t MCAL_RCC_GET_HCLK(void)
{
	return ( MCAL_RCC_GET_SYSCLK() >> AHBPrescTable[( (RCC->CFGR >> 4) )& 0xF] );
}
uint32_t MCAL_RCC_GET_PCLK1(void)
{
	return (MCAL_RCC_GET_HCLK() >> APBPrescTable[( (RCC->CFGR >> 8) ) & 0b111] );
}
uint32_t MCAL_RCC_GET_PCLK2(void)
{
	return (MCAL_RCC_GET_HCLK() >> APBPrescTable[( (RCC->CFGR >> 11) ) & 0b111] );
}
