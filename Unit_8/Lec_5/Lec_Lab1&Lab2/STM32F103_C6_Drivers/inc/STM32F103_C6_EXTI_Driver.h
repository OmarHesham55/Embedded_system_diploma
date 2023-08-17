/*
 * STM32F103_C6_EXTI_Driver.h
 *
 *  Created on: May 24, 2023
 *      Author: omart
 */

#ifndef INC_STM32F103_C6_EXTI_DRIVER_H_
#define INC_STM32F103_C6_EXTI_DRIVER_H_



/*==========================================================*/
//includes
/*==========================================================*/


#include"STM_C6_Driver.h"
#include"STM32F103_C6_GPIO_Driver.h"



/***********************************************************************************************************************/




typedef struct{
	uint16_t		EXTI_INP_LINENum;
	GPIO_REG_t* 	GPIOx;
	uint16_t 		PIN_NUM;
	uint8_t			IVT_IRQ_NUM;
}EXTI_GPIO_Mapping_t;



typedef struct{
	EXTI_GPIO_Mapping_t 	EXTI_PIN;
	uint8_t					EXTI_Trigger_case;
	uint8_t					IRQ_EN;
	void(*P_IRQ_CallBack)(void);
}EXTI_PinConfig_t;




//=============================================================
//Macros Configuration References
//=============================================================

#define	EXTI0			0
#define	EXTI1			1
#define	EXTI2			2
#define	EXTI3			3
#define	EXTI4			4
#define	EXTI5			5
#define	EXTI6			6
#define	EXTI7			7
#define	EXTI8			8
#define	EXTI9			9
#define	EXTI10			10
#define	EXTI11			11
#define	EXTI12			12
#define	EXTI13			13
#define	EXTI14			14
#define	EXTI15			15




//==============================================================
// Reference Macros
//==============================================================

//@ ref EXTI_define
//EXTI0
#define EXTI0PA0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOA, PIN_NUM__0, EXTI0_IRQ}
#define EXTI0PB0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOB, PIN_NUM__0, EXTI0_IRQ}
#define EXTI0PC0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOC, PIN_NUM__0, EXTI0_IRQ}
#define EXTI0PD0        (EXTI_GPIO_Mapping_t){EXTI0, GPIOD, PIN_NUM__0, EXTI0_IRQ}


//EXTI1
#define EXTI1PA1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOA, PIN_NUM__1, EXTI1_IRQ}
#define EXTI1PB1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOB, PIN_NUM__1, EXTI1_IRQ}
#define EXTI1PC1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOC, PIN_NUM__1, EXTI1_IRQ}
#define EXTI1PD1        (EXTI_GPIO_Mapping_t){EXTI1, GPIOD, PIN_NUM__1, EXTI1_IRQ}


//EXTI2
#define EXTI2PA2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOA, PIN_NUM__2, EXTI2_IRQ}
#define EXTI2PB2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOB, PIN_NUM__2, EXTI2_IRQ}
#define EXTI2PC2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOC, PIN_NUM__2, EXTI2_IRQ}
#define EXTI2PD2        (EXTI_GPIO_Mapping_t){EXTI2, GPIOD, PIN_NUM__2, EXTI2_IRQ}


//EXTI3
#define EXTI3PA3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOA, PIN_NUM__3, EXTI3_IRQ}
#define EXTI3PB3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOB, PIN_NUM__3, EXTI3_IRQ}
#define EXTI3PC3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOC, PIN_NUM__3, EXTI3_IRQ}
#define EXTI3PD3        (EXTI_GPIO_Mapping_t){EXTI3, GPIOD, PIN_NUM__3, EXTI3_IRQ}


//EXTI4
#define EXTI4PA4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOA, PIN_NUM__4, EXTI4_IRQ}
#define EXTI4PB4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOB, PIN_NUM__4, EXTI4_IRQ}
#define EXTI4PC4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOC, PIN_NUM__4, EXTI4_IRQ}
#define EXTI4PD4        (EXTI_GPIO_Mapping_t){EXTI4, GPIOD, PIN_NUM__4, EXTI4_IRQ}


//EXTI5
#define EXTI5PA5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOA, PIN_NUM__5, EXTI5_IRQ}
#define EXTI5PB5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOB, PIN_NUM__5, EXTI5_IRQ}
#define EXTI5PC5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOC, PIN_NUM__5, EXTI5_IRQ}
#define EXTI5PD5        (EXTI_GPIO_Mapping_t){EXTI5, GPIOD, PIN_NUM__5, EXTI5_IRQ}


//EXTI6
#define EXTI6PA6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOA, PIN_NUM__6, EXTI6_IRQ}
#define EXTI6PB6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOB, PIN_NUM__6, EXTI6_IRQ}
#define EXTI6PC6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOC, PIN_NUM__6, EXTI6_IRQ}
#define EXTI6PD6        (EXTI_GPIO_Mapping_t){EXTI6, GPIOD, PIN_NUM__6, EXTI6_IRQ}


//EXTI7
#define EXTI7PA7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOA, PIN_NUM__7, EXTI7_IRQ}
#define EXTI7PB7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOB, PIN_NUM__7, EXTI7_IRQ}
#define EXTI7PC7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOC, PIN_NUM__7, EXTI7_IRQ}
#define EXTI7PD7        (EXTI_GPIO_Mapping_t){EXTI7, GPIOD, PIN_NUM__7, EXTI7_IRQ}


//EXTI8
#define EXTI8PA8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOA, PIN_NUM__8, EXTI8_IRQ}
#define EXTI8PB8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOB, PIN_NUM__8, EXTI8_IRQ}
#define EXTI8PC8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOC, PIN_NUM__8, EXTI8_IRQ}
#define EXTI8PD8        (EXTI_GPIO_Mapping_t){EXTI8, GPIOD, PIN_NUM__8, EXTI8_IRQ}


//EXTI9
#define EXTI9PA9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOA, PIN_NUM__9, EXTI9_IRQ}
#define EXTI9PB9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOB, PIN_NUM__9, EXTI9_IRQ}
#define EXTI9PC9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOC, PIN_NUM__9, EXTI9_IRQ}
#define EXTI9PD9        (EXTI_GPIO_Mapping_t){EXTI9, GPIOD, PIN_NUM__9, EXTI9_IRQ}


//EXTI10
#define EXTI10PA10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOA, PIN_NUM__10, EXTI10_IRQ}
#define EXTI10PB10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOB, PIN_NUM__10, EXTI10_IRQ}
#define EXTI10PC10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOC, PIN_NUM__10, EXTI10_IRQ}
#define EXTI10PD10      (EXTI_GPIO_Mapping_t){EXTI10, GPIOD, PIN_NUM__10, EXTI10_IRQ}


//EXTI11
#define EXTI11PA11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOA, PIN_NUM__11, EXTI11_IRQ}
#define EXTI11PB11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOB, PIN_NUM__11, EXTI11_IRQ}
#define EXTI11PC11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOC, PIN_NUM__11, EXTI11_IRQ}
#define EXTI11PD11      (EXTI_GPIO_Mapping_t){EXTI11, GPIOD, PIN_NUM__11, EXTI11_IRQ}


//EXTI12
#define EXTI12PA12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOA, PIN_NUM__12, EXTI12_IRQ}
#define EXTI12PB12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOB, PIN_NUM__12, EXTI12_IRQ}
#define EXTI12PC12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOC, PIN_NUM__12, EXTI12_IRQ}
#define EXTI12PD12      (EXTI_GPIO_Mapping_t){EXTI12, GPIOD, PIN_NUM__12, EXTI12_IRQ}


//EXTI13
#define EXTI13PA13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOA, PIN_NUM__13, EXTI13_IRQ}
#define EXTI13PB13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOB, PIN_NUM__13, EXTI13_IRQ}
#define EXTI13PC13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOC, PIN_NUM__13, EXTI13_IRQ}
#define EXTI13PD13      (EXTI_GPIO_Mapping_t){EXTI13, GPIOD, PIN_NUM__13, EXTI13_IRQ}


//EXTI14
#define EXTI14PA14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOA, PIN_NUM__14, EXTI14_IRQ}
#define EXTI14PB14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOB, PIN_NUM__14, EXTI14_IRQ}
#define EXTI14PC14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOC, PIN_NUM__14, EXTI14_IRQ}
#define EXTI14PD14      (EXTI_GPIO_Mapping_t){EXTI14, GPIOD, PIN_NUM__14, EXTI14_IRQ}


//EXTI15
#define EXTI15PA15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOA, PIN_NUM__15, EXTI15_IRQ}
#define EXTI15PB15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOB, PIN_NUM__15, EXTI15_IRQ}
#define EXTI15PC15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOC, PIN_NUM__15, EXTI15_IRQ}
#define EXTI15PD15      (EXTI_GPIO_Mapping_t){EXTI15, GPIOD, PIN_NUM__15, EXTI15_IRQ}

/***********************************************************************************************************************/


//@ ref EXTI_Trigger_Case_define
#define EXTI_Trigger_Case_Raising				0
#define EXTI_Trigger_Case_Falling				1
#define EXTI_Trigger_Case_RaisingandFalling		2

/***********************************************************************************************************************/
//@ ref IRQ_EN_define
#define	EXTI_IRQ_Enable			1
#define	EXTI_IRQ_Disable		0


/*
 * ========================================================================================
 *                         APIs Supported by "MCAL GPIO DRIVER"
 * ========================================================================================
 *
 */


void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t * EXTI_PIN_CONFIG);
void MCAL_EXTI_GPIO_DEINIT(void);
void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t * EXTI_PIN_CONFIG);

#endif /* INC_STM32F103_C6_EXTI_DRIVER_H_ */
