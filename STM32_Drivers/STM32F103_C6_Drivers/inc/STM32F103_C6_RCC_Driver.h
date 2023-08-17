/*
 * STM32F103_C6_RCC_Driver.h
 *
 *  Created on: Jul 29, 2023
 *      Author: omart
 */

#ifndef INC_STM32F103_C6_RCC_DRIVER_H_
#define INC_STM32F103_C6_RCC_DRIVER_H_

#include"STM_C6_Driver.h"

#define HSE_Clock	(uint32_t)16000000
#define HSI_Clock	(uint32_t)8000000

uint32_t MCAL_RCC_GET_SYSCLK(void);
uint32_t MCAL_RCC_GET_HCLK(void);
uint32_t MCAL_RCC_GET_PCLK1(void);
uint32_t MCAL_RCC_GET_PCLK2(void);


#endif /* INC_STM32F103_C6_RCC_DRIVER_H_ */
