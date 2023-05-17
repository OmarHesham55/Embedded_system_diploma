/*
 * STM32F103_C6_GPIO_Driver.h
 *
 *  Created on: May 15, 2023
 *      Author: omart
 */

#ifndef INC_STM32F103_C6_GPIO_DRIVER_H_
#define INC_STM32F103_C6_GPIO_DRIVER_H_


//------------------------------
//Includes
//------------------------------
#include"STM_C6_Driver.h"


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


//------------------------------
//Macros Configuration Reference::
//------------------------------

typedef struct{
	volatile uint16_t PIN_NUM;
	volatile uint8_t PIN_MODE;			// This Pin Must Choose from @ref GPIO_MODE_x
	volatile uint8_t	PIN_SPEED;		// choose this Pin with referencing to @ref GPIO_MODE_SPEED_x
}GPIO_Pin_init_t;

//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//@ref GPIO_MODE_x
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*

/*
*1: Analog mode
*2: Floating input (reset state)
*3: Input with pull-up
*4: Input pull-down
*5: General purpose output push-pull
*6: General purpose output Open-drain
*7: Alternate function output Push-pull
*8: Alternate function output Open-drain
 * */

#define GPIO_MODE_ANALOG									0x00000000u
#define GPIO_MODE_FLOATING_IP								0x00000001u
#define GPIO_MODE_PULL_UP_IP								0x00000002u
#define GPIO_MODE_PULL_DOWN_IP								0x00000003u
#define GPIO_MODE_PUSH_PULL_OP								0x00000004u
#define GPIO_MODE_OPEN_DRAIN_OP								0x00000005u
#define GPIO_MODE_AF_PUSH_PULL_OP							0x00000006u
#define GPIO_MODE_AF_OPEN_DRAIN_OP							0x00000007u
#define GPIO_MODE_AF_IP										0x00000008u


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//@ref GPIO_MODE_SPEED_x
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*

/*
**00: Input mode (reset state) ~RS~
**01: Output mode, max speed 10 MHz.
**10: Output mode, max speed 2 MHz.
**11: Output mode, max speed 50 MHz.
 * */

#define GPIO_MODE_SPEED_RS									0x00000000u
#define GPIO_MODE_SPEED_10M									0x00000001u
#define GPIO_MODE_SPEED_2M									0x00000002u
#define GPIO_MODE_SPEED_50M									0x00000003u

//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*



//------------------------------
//APIS::
//------------------------------

void MCAL_GPIO_INIT(GPIO_REG_t* GPIOx,GPIO_Pin_init_t* PinCnfg);
void MCAL_GPIO_DeINIT(GPIO_REG_t* GPIOx);
uint8_t MCAL_GPIO_READ_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber);
uint16_t MCAL_GPIO_READ_PORT(GPIO_REG_t* GPIOx);
void MCAL_GPIO_WRITE_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber,uint8_t value);
void MCAL_GPIO_WRITE_PORT(GPIO_REG_t* GPIOx,uint32_t value);
void MCAL_GPIO_TOGGLE_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber);
//void MCAL_GPIO_RESET_PORT(GPIO_REG_t* GPIOx);
//void MCAL_GPIO_LCK_PORT(GPIO_REG_t* GPIOx);
#endif /* INC_STM32F103_C6_GPIO_DRIVER_H_ */
