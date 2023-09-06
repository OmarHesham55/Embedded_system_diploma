/*
 * EXTI.h
 *
 * Created: 9/6/2023 2:41:25 AM
 *  Author: omart
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "ATMEGA32_MemMap.h"

typedef struct{
	uint8_t EXTI_NumberRequest;
	uint8_t EXTI_Sense_Mode;
	void(*P_IRQ_CallBack)(void);
}EXTI_Config_t;


#define EXTI_NumberRequest_INT0				6
#define EXTI_NumberRequest_INT1				7
#define EXTI_NumberRequest_INT2				5

#define EXTI_Sense_LowLevel					0
#define EXTI_Sense_Falling_Raising			1
#define EXTI_Sense_FallingEdge				2
#define EXTI_Sense_RaisingEdge				3




void MCAL_EXTI_Init(EXTI_Config_t* ExtiConfg);

#endif /* EXTI_H_ */