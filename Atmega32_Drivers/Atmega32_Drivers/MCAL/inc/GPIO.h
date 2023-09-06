/*
 * GPIO.h
 *
 * Created: 9/4/2023 4:29:19 PM
 *  Author: omart
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "ATMEGA32_MemMap.h"

enum PORTx{
	PORTA_e,
	PORTB_e,
	PORTC_e,
	PORTD_e
};

enum Pin_Direction{
	input_e,
	output_e
};

typedef struct{
	enum PORTx GPIOx;
	uint8_t pinNumber;
	enum Pin_Direction pinDirection;
}Pin_Init_t;






void MCAL_GPIO_Init(Pin_Init_t* pinInit);
void MCAL_GPIO_DeInit(enum PORTx GPIOx);
void MCAL_GPIO_SetPIN(enum PORTx GPIOx, uint8_t pinNumber,uint8_t pinMode);
void MCAL_GPIO_SetPORT(enum PORTx GPIOx, uint8_t portDirection);
void MCAL_GPIO_TogglePin(enum PORTx GPIOx, uint8_t pinNumber);
void MCAL_GPIO_TogglePort(enum PORTx GPIOx);
uint8_t MCAL_GPIO_ReadPin(enum PORTx GPIOx, uint8_t pinNumber);


#endif /* GPIO_H_ */