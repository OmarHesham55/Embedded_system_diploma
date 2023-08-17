/*
 * STM32F103_C6_UART_Driver.c
 *
 *  Created on: Jul 4, 2023
 *      Author: omart
 */

#include"STM32F103_C6_UART_Driver.h"
#include"STM32F103_C6_RCC_Driver.h"
#include"STM32F103_C6_GPIO_Driver.h"
#include"STM_C6_Driver.h"

//to enable USART TX::
/*
Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
  transmission
 */


/*====================================================================================================================================================
 *																	Generic Variables
 *====================================================================================================================================================
 */

USART_CONFG_t* Global_UART_CONFG[3] = {NULL,NULL,NULL};


#define UART1_Index				0
#define UART2_Index				1
#define UART3_Index				2
/*====================================================================================================================================================
 *																		APIs
 *====================================================================================================================================================
 */

void MCAL_UART_Init(USART_REG_t* USARTx,USART_CONFG_t* USARTCnfg)
{
	uint32_t pClk,Brr;


	if(USARTx == USART1)
	{
		ENB_USART1();
		Global_UART_CONFG[UART1_Index] = USARTCnfg;
	}

		else if(USARTx == USART2)
		{
			ENB_USART2();
			Global_UART_CONFG[UART2_Index] = USARTCnfg;
		}
		else if(USARTx == USART3)
		{
			ENB_USART3();
			Global_UART_CONFG[UART3_Index] = USARTCnfg;
		}

	/*Enable USART Module*/
	USARTx->USART_CR1 |= 1<<13;

	/*Enable USART TX/RX*/
	USARTx->USART_CR1 |= USARTCnfg->USART_MODE;

	/*M bits 8 | 9 */
	USARTx->USART_CR1 |= USARTCnfg->USART_BITs;

	/*Parity Bit*/
	USARTx->USART_CR1 |= USARTCnfg->USART_PARITYBIT;

	/*Stop bit*/
	USARTx->USART_CR2 |= USARTCnfg->USART_STOPBIT;

	/*USART FLW Control*/
	USARTx->USART_CR3 |= USARTCnfg->USART_HW_FLW_CTL;

	if(USARTx == USART1)
		pClk = MCAL_RCC_GET_PCLK2();
	else
		pClk = MCAL_RCC_GET_PCLK1();

	Brr = UART_BRR_Register(pClk,USARTCnfg->USART_BAUDRATE);
	USARTx->USART_BRR = Brr;

	if(USARTCnfg->USART_IRQ != USART_IRQ_Enable_None)
	{
		USARTx->USART_CR1 |= (USARTCnfg->USART_IRQ);

		if (USARTx == USART1)
		{
			NVIC_IRQ37_USART1_EN();
		}
		else if(USARTx == USART2)
		{
			NVIC_IRQ38_USART2_EN();
		}
		else if(USARTx == USART3)
		{
			NVIC_IRQ39_USART3_EN();
		}
	}
}

void MCAL_UART_DeInit(USART_REG_t* USARTx)
{
	if(USARTx == USART1)
		RES_USART1();
	else if(USARTx == USART2)
		RES_USART2();
	else if(USARTx == USART3)
		RES_USART3();
}

void MCAL_UART_TX(USART_REG_t* USARTx,uint16_t *data,enum polling PollingEN)
{
	if(PollingEN == Enable_UART)
		while(!(USARTx->USART_SR & 1<<7));


	if(USARTx == USART1)
	{
		if(Global_UART_CONFG[UART1_Index]->USART_BITs == USART_BITs_9)
		{
			USARTx->USART_DR = (*data) & (uint16_t)0x1FF;
		}
		else
		{
			USARTx->USART_DR = (*data) & (uint8_t)0xFF;
		}
	}
	else if(USARTx == USART2)
	{
		if(Global_UART_CONFG[UART2_Index]->USART_BITs == USART_BITs_9)
		{
			USARTx->USART_DR = (*data) & (uint16_t)0x1FF;
		}
		else
		{
			USARTx->USART_DR = (*data) & (uint8_t)0xFF;
		}
	}
	else if(USARTx == USART3)
	{
		if(Global_UART_CONFG[UART2_Index]->USART_BITs == USART_BITs_9)
		{
			USARTx->USART_DR = (*data) & (uint16_t)0x1FF;
		}
		else
		{
			USARTx->USART_DR = (*data) & (uint8_t)0xFF;
		}
	}
}

void MCAL_UART_WAIT(USART_REG_t* USARTx)
{
	while(!(USARTx->USART_SR & 1<<6));
}


void MCAL_UART_RX(USART_REG_t* USARTx,uint16_t *data,enum polling PollingEN)
{
	if(PollingEN == Enable_UART)
		while(!(USARTx->USART_SR & 1<<5));

	if(USARTx == USART1)
	{
		if(Global_UART_CONFG[UART1_Index]->USART_BITs == USART_BITs_9)
		{
			if(Global_UART_CONFG[UART1_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				/*All 9 bits are data*/
				//				*((uint16_t*)data) = USARTx->USART_DR;
				*data = USARTx->USART_DR;
			}
			else
			{
				/*Only 8 bit are data and 1 bit is parity bit*/

				//				*((uint16_t*)data) = (USARTx->USART_DR & (uint8_t)0xFF);
				*data = USARTx->USART_DR & (uint8_t)0xFF;
			}
		}
		else //8 bit Data
		{
			if(Global_UART_CONFG[UART1_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				/*All 8 bits are data*/
				*(data) = USARTx->USART_DR & (uint8_t)0xFF;
			}
			else
			{
				/*Only 7 bit are data and 1 bit is parity bit*/
				*(data) = USARTx->USART_DR & (uint8_t)0x7F;
			}
		}
	}
	else if(USARTx == USART2)
	{
		if(Global_UART_CONFG[UART2_Index]->USART_BITs == USART_BITs_9)
		{
			if(Global_UART_CONFG[UART2_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				*(data) = USARTx->USART_DR;
			}
			else
			{
				*(data) = USARTx->USART_DR & (uint8_t)0xFF;
			}
		}
		else
		{
			if(Global_UART_CONFG[UART2_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				*(data) = USARTx->USART_DR & (uint8_t)0xFF;
			}
			else
			{
				*(data) = USARTx->USART_DR & (uint8_t)0x7F;
			}
		}
	}
	else if(USARTx == USART3)
	{
		if(Global_UART_CONFG[UART3_Index]->USART_BITs == USART_BITs_9)
		{
			if(Global_UART_CONFG[UART3_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				*(data) = USARTx->USART_DR;
			}
			else
			{
				*(data) = USARTx->USART_DR & (uint8_t)0xFF;
			}
		}
		else
		{
			if(Global_UART_CONFG[UART3_Index]->USART_PARITYBIT == USART_PARITY_NONE)
			{
				*(data) = USARTx->USART_DR & (uint8_t)0xFF;
			}
			else
			{
				*(data) = USARTx->USART_DR & (uint8_t)0x7F;
			}
		}
	}

}


void MCAL_UART_GPIO_Init(USART_REG_t* USARTx)
{
	GPIO_Pin_init_t pinCnfg;

	if(USARTx == USART1)
	{
		//TX
		pinCnfg.PIN_NUM = PIN_NUM__9;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
		pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

		MCAL_GPIO_INIT(GPIOA, &pinCnfg);

		//RX
		pinCnfg.PIN_NUM = PIN_NUM__10;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_IP;

		MCAL_GPIO_INIT(GPIOA, &pinCnfg);

		if(Global_UART_CONFG[UART1_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_CTS || Global_UART_CONFG[UART1_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__11;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
		if(Global_UART_CONFG[UART1_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS || Global_UART_CONFG[UART1_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__12;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
	}



	if(USARTx == USART2)
	{
		//TX
		pinCnfg.PIN_NUM = PIN_NUM__2;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
		pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

		MCAL_GPIO_INIT(GPIOA, &pinCnfg);

		//RX
		pinCnfg.PIN_NUM = PIN_NUM__3;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_IP;

		MCAL_GPIO_INIT(GPIOA, &pinCnfg);

		if(Global_UART_CONFG[UART2_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_CTS || Global_UART_CONFG[UART2_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__0;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
		if(Global_UART_CONFG[UART2_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS || Global_UART_CONFG[UART2_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__1;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
	}




	if(USARTx == USART3)
	{
		//TX
		pinCnfg.PIN_NUM = PIN_NUM__10;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
		pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

		MCAL_GPIO_INIT(GPIOB, &pinCnfg);

		//RX
		pinCnfg.PIN_NUM = PIN_NUM__11;
		pinCnfg.PIN_MODE = GPIO_MODE_AF_IP;

		MCAL_GPIO_INIT(GPIOB, &pinCnfg);

		if(Global_UART_CONFG[UART3_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_CTS || Global_UART_CONFG[UART3_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__13;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
		if(Global_UART_CONFG[UART3_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS || Global_UART_CONFG[UART3_Index]->USART_HW_FLW_CTL == USART_HwFlowCNTL_RTS_CTS )
		{
			pinCnfg.PIN_NUM = PIN_NUM__14;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;

			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}
	}
}



void USART1_IRQHandler(void)
{
	Global_UART_CONFG[UART1_Index]->P_IRQ_CallBack();
}
void USART2_IRQHandler(void)
{
	Global_UART_CONFG[UART2_Index]->P_IRQ_CallBack();
}
void USART3_IRQHandler(void)
{
	Global_UART_CONFG[UART3_Index]->P_IRQ_CallBack();
}
