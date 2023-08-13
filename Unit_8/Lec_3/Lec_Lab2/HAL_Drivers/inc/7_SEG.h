/*
 * 7_SEG.h
 *
 *  Created on: Jul 22, 2023
 *      Author: omart
 */

#ifndef INC_7_SEG_H_
#define INC_7_SEG_H_

#include "STM_C6_Driver.h"
#include "STM32F103_C6_GPIO_Driver.h"

#define SGMNTS_PORT		GPIOB




void SEG_GPIO_INIT(void);
void SEG_NUMS(void);
#endif /* INC_7_SEG_H_ */
