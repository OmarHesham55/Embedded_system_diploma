/*
 * STM32F103_C6_UART_Driver.h
 *
 *  Created on: Jul 4, 2023
 *      Author: omart
 */

#ifndef INC_STM32F103_C6_UART_DRIVER_H_
#define INC_STM32F103_C6_UART_DRIVER_H_

#include "STM32F103_C6_GPIO_Driver.h"
#include"STM_C6_Driver.h"
#include"Utility.h"


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



typedef struct
{
	uint8_t			USART_MODE;
	uint32_t		USART_BAUDRATE;
	uint16_t		USART_BITs;
	uint8_t			USART_PARITYBIT;
	uint8_t			USART_STOPBIT;
	uint8_t			USART_HW_FLW_CTL;
	uint8_t			USART_IRQ;

	void(* P_IRQ_CallBack)(void);
}USART_CONFG_t;






#define USARTDIV(_PCLK_,_BAUD_)									(uint32_t)(_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)							(uint32_t)((25*_PCLK_) / (4* _BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)							(uint32_t)(USARTDIV(_PCLK_,_BAUD_) * 100)
#define Mantissa(_PCLK_,_BAUD_)									(uint32_t)(USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_)								(uint32_t)(((USARTDIV_MUL100(_PCLK_,_BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_)) *16 ) /100 )
#define UART_BRR_Register(_PCLK_,_BAUD_)						(( Mantissa(_PCLK_,_BAUD_) ) << 4 )|( (DIV_Fraction(_PCLK_,_BAUD_) )& 0xF)




/*====================================================================================================================================================
 *																	Generic Macros
 *====================================================================================================================================================
 */

#define USART_MODE_TX								(uint32_t)(1<<3)
#define USART_MODE_RX								(uint32_t)(1<<2)
#define USART_MODE_TX_RX							(uint32_t)(1<<2 | 1<<3)



#define USART_BAUDRATE_2400							2400
#define USART_BAUDRATE_9600							9600
#define USART_BAUDRATE_19200						19200
#define USART_BAUDRATE_57600						57600
#define USART_BAUDRATE_115200						115200
#define USART_BAUDRATE_230400						230400
#define USART_BAUDRATE_460800						460800
#define USART_BAUDRATE_921600						921600
#define USART_BAUDRATE_2250000						2250000
#define USART_BAUDRATE_4500000						4500000


#define USART_BITs_8								(uint32_t)(0)
#define USART_BITs_9								(uint32_t)(1<<12)


#define USART_PARITY_NONE							(uint32_t)(0)
#define USART_PARITY_EVEN							(uint32_t)(1<<10)
#define USART_PARITY_ODD							(uint32_t)(1<<10 | 1<<9)


#define	USART_STOP_BITs_Half						(uint32_t)(1<<12)
#define USART_STOP_BITs_1							(uint32_t)(0)
#define	USART_STOP_BITs_1andHalf					(uint32_t)(2<<12)
#define	USART_STOP_BITs_2							(uint32_t)(3<<12)


#define USART_HwFlowCNTL_NONE						(uint32_t)(0)
#define USART_HwFlowCNTL_RTS						(uint32_t)(1<<8)
#define USART_HwFlowCNTL_CTS						(uint32_t)(1<<9)
#define USART_HwFlowCNTL_RTS_CTS					(uint32_t)(1<<8 | 1<<9)



#define USART_IRQ_Enable_None							(uint32_t)(0)
#define USART_IRQ_Enable_TXE							(uint32_t)(1<<7)
#define USART_IRQ_Enable_TC								(uint32_t)(1<<6)
#define USART_IRQ_Enable_RXNEIE							(uint32_t)(1<<5)
#define USART_IRQ_Enable_PE								(uint32_t)(1<<8)


enum polling
{
	enable,
	disable
};



/*====================================================================================================================================================
 *																	Generic Functions
 *====================================================================================================================================================
 */










/*====================================================================================================================================================
 *																			APIs
 *====================================================================================================================================================
 */
void MCAL_UART_Init(USART_REG_t* USARTx,USART_CONFG_t* USARTCnfg);
void MCAL_UART_DeInit(USART_REG_t* USARTx);
void MCAL_UART_GPIO_Init(USART_REG_t* USARTx);
void MCAL_UART_TX(USART_REG_t* USARTx,uint16_t *data,enum polling PollingEN);
void MCAL_UART_RX(USART_REG_t* USARTx,uint16_t *data,enum polling PollingEN);
void MCAL_UART_WAIT(USART_REG_t* USARTx);

#endif /* INC_STM32F103_C6_UART_DRIVER_H_ */
