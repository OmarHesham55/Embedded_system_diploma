/*
 * STM32F103_C6_GPIO_Driver.c
 *
 *  Created on: May 15, 2023
 *      Author: omart
 */


#include"STM32F103_C6_GPIO_Driver.h"


uint8_t GET_CRLH_POS(uint16_t Pin)
{
	switch (Pin)
	{
		case PIN_NUM__0:
			return 0;
			break;

		case PIN_NUM__1:
			return 4;
			break;

		case PIN_NUM__2:
			return 8;
			break;

		case PIN_NUM__3:
			return 12;
			break;

		case PIN_NUM__4:
			return 16;
			break;

		case PIN_NUM__5:
			return 20;
			break;

		case PIN_NUM__6:
			return 24;
			break;

		case PIN_NUM__7:
			return 28;
			break;

		case PIN_NUM__8:
			return 0;
			break;

		case PIN_NUM__9:
			return 4;
			break;

		case PIN_NUM__10:
			return 8;
			break;

		case PIN_NUM__11:
			return 12;
			break;

		case PIN_NUM__12:
			return 16;
			break;

		case PIN_NUM__13:
			return 20;
			break;

		case PIN_NUM__14:
			return 24;
			break;

		case PIN_NUM__15:
			return 28;
			break;
	}
	return 0;
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_INIT(GPIO_REG_t* GPIOx,GPIO_Pin_init_t* PinCnfg)
{

	volatile uint32_t* regstr = NULL;
	uint8_t check = 0 ;
	//choosing which register will modify it
	regstr	= (PinCnfg->PIN_NUM < PIN_NUM__8) ? &GPIOx->CRL : &GPIOx->CRH;

	//Reset every pin's bit before using it
	(*regstr) &= ~(0xF << GET_CRLH_POS(PinCnfg->PIN_NUM));

	// If pin is output
	if( (PinCnfg->PIN_MODE == GPIO_MODE_OPEN_DRAIN_OP) ||( PinCnfg->PIN_MODE == GPIO_MODE_PUSH_PULL_OP )||( PinCnfg->PIN_MODE == GPIO_MODE_AF_OPEN_DRAIN_OP )||( PinCnfg->PIN_MODE == GPIO_MODE_AF_PUSH_PULL_OP) )
	{
		check = ( (( (PinCnfg->PIN_MODE - 4) << 2 ) | (PinCnfg->PIN_SPEED )) & 0x0F);
	}
	// If pin is Input
	else
	{
		if( (PinCnfg->PIN_MODE == GPIO_MODE_ANALOG) || (PinCnfg->PIN_MODE == GPIO_MODE_FLOATING_IP) )
		{
			check = ((((PinCnfg->PIN_MODE ) << 2) | 0x00 ) & 0x0F );
		}
		else if(PinCnfg->PIN_MODE == GPIO_MODE_AF_IP)
		{
			check = ((((GPIO_MODE_FLOATING_IP) << 2) | 0x00 ) & 0x0F );
		}
		else
		{
			check = ((((GPIO_MODE_PULL_UP_IP) << 2) | 0x00 ) & 0x0F );

			if(PinCnfg->PIN_MODE == GPIO_MODE_PULL_UP_IP){
//				SET_PIN(GPIOx->ODR,PinCnfg->PIN_NUM);
				GPIOx->ODR |= PinCnfg->PIN_NUM;

			}
			else
			{
//				RESET_PIN(GPIOx->ODR,PinCnfg->PIN_NUM);
				GPIOx->ODR &= ~(PinCnfg->PIN_NUM);

			}
		}
	}

	(*regstr) |= (check << GET_CRLH_POS(PinCnfg->PIN_NUM));
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_DeINIT(GPIO_REG_t* GPIOx)
{
	//First Way
/*
 * 	GPIOx->CRL 	= 0x44444444 ;
	GPIOx->CRH 	= 0x44444444;
//	GPIOx->IDR 	= Read Only;
	GPIOx->ODR 	= 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->BRR 	= 0x00000000;
	GPIOx->LCKR = 0x00000000;
 *
 *
 * */


	//Second Way
	if(GPIOx == GPIOA)
	{
		RCC->APB1RSTR |=  (1<<PIN_NUM__2);
		RCC->APB1RSTR &= ~(1<<PIN_NUM__2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=  (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=  (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD){
		RCC->APB2RSTR |=  (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


uint8_t MCAL_GPIO_READ_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber)
{
	uint8_t value;

	if( ((GPIOx->IDR) & pinNumber) != 0 )
	{
		value = 1;
	}
	else
	{
		value = 0;
	}
	return value;
}

 //*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
 //*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


uint16_t MCAL_GPIO_READ_PORT(GPIO_REG_t* GPIOx)
{

	return (uint16_t)(GPIOx->IDR);

}

//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_WRITE_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber,uint8_t value)
{

	if(value != 0)
	{
		GPIOx->BSRR = (uint32_t)pinNumber;

	}
	else
	{
		GPIOx->BRR = (uint32_t)pinNumber;

	}
}

//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_WRITE_PORT(GPIO_REG_t* GPIOx,uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_TOGGLE_PIN(GPIO_REG_t* GPIOx,uint16_t pinNumber)
{
	GPIOx->ODR ^= pinNumber;
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_RESET_PORT(GPIO_REG_t* GPIOx)
{
	GPIOx->BRR = 0xFFFF;
}


//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*


void MCAL_GPIO_SET_PORT(GPIO_REG_t* GPIOx)
{
	GPIOx->ODR = 0xFFFF;

}
