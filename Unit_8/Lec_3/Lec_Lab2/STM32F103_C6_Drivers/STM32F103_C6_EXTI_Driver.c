/*
 * STM32F103_C6_EXTI_Driver.c
 *
 *  Created on: May 24, 2023
 *      Author: omart
 */


/*==========================================================*/
//includes
/*==========================================================*/
#include"STM32F103_C6_EXTI_Driver.h"



/***********************************************************************************************************************/




/*==========================================================*/
/* GENARIC MACROS */
/*==========================================================*/



#define AFIO_GPIO_EXTI_Mapping(x)						((x == GPIOA)?0:\
														(x == GPIOB)?1:\
														(x == GPIOC)?2:\
														(x == GPIOD)?3:0)


/***********************************************************************************************************************/


/*==========================================================*/
/* GENARIC FUNCTIONS */
/*==========================================================*/


	void(*GP_IRQ_CallBack[15])(void);


	void NVIC_ENB(uint16_t x){
		switch (x) {
			case 0:
				NVIC_IRQ6_EXTI0_EN();
				break;
			case 1:
				NVIC_IRQ7_EXTI1_EN();
				break;
			case 2:
				NVIC_IRQ8_EXTI2_EN();
				break;
			case 3:
				NVIC_IRQ9_EXTI3_EN();
				break;
			case 4:
				NVIC_IRQ10_EXTI4_EN();
				break;
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				NVIC_IRQ23_EXTI5_9_EN();
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				NVIC_IRQ40_EXTI10_15_EN();
				break;
		}
	}


	void NVIC_DIS(uint16_t x){
		switch (x) {
			case 0:
				NVIC_IRQ6_EXTI0_DIS();
				break;
			case 1:
				NVIC_IRQ7_EXTI1_DIS();
				break;
			case 2:
				NVIC_IRQ8_EXTI2_DIS();
				break;
			case 3:
				NVIC_IRQ9_EXTI3_DIS();
				break;
			case 4:
				NVIC_IRQ10_EXTI4_DIS();
				break;
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				NVIC_IRQ23_EXTI5_9_DIS();
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				NVIC_IRQ40_EXTI10_15_DIS();
				break;
		}
	}

/***********************************************************************************************************************/





/*
 * ========================================================================================
 *                                      FUNCTIONS APIs Definitions
 * ========================================================================================
 *
 */


/**=================================================================
 * @Fn -                    -MCAL_EXTI_GPIO_INIT
 * @brief -                 -Initialize the EXTI For Specific GPIO Pin and specify Mask/Trigger Condition and IRQ CallBack
 * @param [in] -            -EXTI_PIN_CONFIG : where this set by this reference @Ref EXTI_IRQ_EN_define and @Ref EXTI_TRIGGRE_define
 * @retval -                -none
 * note -                   -stmf103c6 MCU has GPIO A,B,C,D,E Modules
 *                           but LQFP48 Package has only GPIO A,B, Part of C/D exported external pins
 */
/**================================================================= */



void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t * EXTI_PIN_CONFIG){

	MCAL_EXTI_GPIO_UPDATE(EXTI_PIN_CONFIG);
}


/**=================================================================
 * @Fn -                    -MCAL_EXTI_GPIO_DEINIT
 * @brief -                 -Initialize the EXTI For Specific GPIO Pin and specify Mask/Trigger Condition and IRQ CallBack
 * @param [in] -            -EXTI_PIN_CONFIG : where this set by this reference @Ref EXTI_IRQ_EN_define and @Ref EXTI_TRIGGRE_define
 * @retval -                -none
 * note -                   -stmf103c6 MCU has GPIO A,B,C,D,E Modules
 *                           but LQFP48 Package has only GPIO A,B, Part of C/D exported external pins
 */
/**================================================================= */

void MCAL_EXTI_GPIO_DEINIT(void){
	EXTI->EMR 		= 0x00000000;
	EXTI->FSTR 		= 0x00000000;
	EXTI->IMR 		= 0x00000000;
	EXTI->RSTR 		= 0x00000000;
	EXTI->SWIER 	= 0x00000000;
	EXTI->PR   		= 0xFFFFFFFF;

	//Disable NVIC
	NVIC_IRQ6_EXTI0_DIS();
	NVIC_IRQ7_EXTI1_DIS();
	NVIC_IRQ8_EXTI2_DIS();
	NVIC_IRQ9_EXTI3_DIS();
	NVIC_IRQ10_EXTI4_DIS();
	NVIC_IRQ23_EXTI5_9_DIS();
	NVIC_IRQ40_EXTI10_15_DIS();

}









/**=================================================================
 * @Fn -                    -MCAL_EXTI_GPIO_UPDATE
 * @brief -                 -Initialize the EXTI For Specific GPIO Pin and specify Mask/Trigger Condition and IRQ CallBack
 * @param [in] -            -EXTI_PIN_CONFIG : where this set by this reference @Ref EXTI_IRQ_EN_define and @Ref EXTI_TRIGGRE_define
 * @retval -                -none
 * note -                   -stmf103c6 MCU has GPIO A,B,C,D,E Modules
 *                           but LQFP48 Package has only GPIO A,B, Part of C/D exported external pins
 */
/**================================================================= */


void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t * EXTI_PIN_CONFIG){

	// 1- Configer GPIO as AF Input -> Floating Input
	GPIO_Pin_init_t pin;
	pin.PIN_MODE = GPIO_MODE_FLOATING_IP;
	pin.PIN_NUM  = EXTI_PIN_CONFIG->EXTI_PIN.PIN_NUM;
	MCAL_GPIO_INIT(EXTI_PIN_CONFIG->EXTI_PIN.GPIOx, &pin);
	//--------------------------------------------------


	// 2- Update AFIO to route between EXTI Line with Port A,B,C,D

	uint8_t AFIO_EXTICRx	=  EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum / 4;
	uint16_t AFIO_EXTICRx_POS		= (EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum % 4) * 4;
	// Clear the 4-Bit then Write on Register
	AFIO->EXTICRx[AFIO_EXTICRx] &=~(0xF<<AFIO_EXTICRx_POS);
	AFIO->EXTICRx[AFIO_EXTICRx] |= ( ( AFIO_GPIO_EXTI_Mapping(EXTI_PIN_CONFIG->EXTI_PIN.GPIOx) & 0xF) << AFIO_EXTICRx_POS);
	//----------------------------------------------------------

	// 3- Update Falling&Raising Trigger

	EXTI->FSTR &=~(1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);
	EXTI->RSTR &=~(1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);

	if(EXTI_PIN_CONFIG->EXTI_Trigger_case == EXTI_Trigger_Case_Falling){

		EXTI->FSTR |= (1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);

	}else if(EXTI_PIN_CONFIG->EXTI_Trigger_case == EXTI_Trigger_Case_Raising){

		EXTI->RSTR |= (1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);

	}else if(EXTI_PIN_CONFIG->EXTI_Trigger_case == EXTI_Trigger_Case_RaisingandFalling){

		EXTI->RSTR |= (1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);
		EXTI->FSTR |= (1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);

	}
	//----------------------------------------------------------
	// 4- Handling IRQ CALLBACK
	GP_IRQ_CallBack[EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum] = EXTI_PIN_CONFIG->P_IRQ_CallBack;

	// 5- Enable/Disable IRQ
		if(EXTI_PIN_CONFIG->IRQ_EN == EXTI_IRQ_Enable){
			EXTI->IMR |= EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum;
			NVIC_ENB(EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);
		}else{
			EXTI->IMR &=~(1<<EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);
			NVIC_DIS(EXTI_PIN_CONFIG->EXTI_PIN.EXTI_INP_LINENum);
		}
}


/***********************************************************************************************************************/



/* ================================================ */
/* =============== ISR Functions ================== */
/* ================================================ */

// EXTI0
void EXTI0_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 0;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[0]();

}

// EXTI1
void EXTI1_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 1;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[1]();

}

// EXTI2
void EXTI2_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 2;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[2]();

}

// EXTI3
void EXTI3_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 3;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[3]();

}

// EXTI4
void EXTI4_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 4;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[4]();

}

// EXTI5 ---> EXTI9
void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR & 1<<5)	{EXTI->PR |= (1<<5); GP_IRQ_CallBack[5]();}
	if (EXTI->PR & 1<<6)	{EXTI->PR |= (1<<6); GP_IRQ_CallBack[6]();}
	if (EXTI->PR & 1<<7)	{EXTI->PR |= (1<<7); GP_IRQ_CallBack[7]();}
	if (EXTI->PR & 1<<8)	{EXTI->PR |= (1<<8); GP_IRQ_CallBack[8]();}
	if (EXTI->PR & 1<<9)	{EXTI->PR |= (1<<9); GP_IRQ_CallBack[9]();}
}

// EXTI10 ---> EXTI15
void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR & 1<<10)	{EXTI->PR |= (1<<10); GP_IRQ_CallBack[10]();}
	if (EXTI->PR & 1<<11)	{EXTI->PR |= (1<<11); GP_IRQ_CallBack[11]();}
	if (EXTI->PR & 1<<12)	{EXTI->PR |= (1<<12); GP_IRQ_CallBack[12]();}
	if (EXTI->PR & 1<<13)	{EXTI->PR |= (1<<13); GP_IRQ_CallBack[13]();}
	if (EXTI->PR & 1<<14)	{EXTI->PR |= (1<<14); GP_IRQ_CallBack[14]();}
	if (EXTI->PR & 1<<15)	{EXTI->PR |= (1<<15); GP_IRQ_CallBack[15]();}
}


