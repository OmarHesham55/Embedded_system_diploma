/*
 * STM32F103_C6_SPI_Driver.h
 *
 *  Created on: Aug 10, 2023
 *      Author: omart
 */

#ifndef INC_STM32F103_C6_SPI_DRIVER_H_
#define INC_STM32F103_C6_SPI_DRIVER_H_

#include"STM32F103_C6_RCC_Driver.h"
#include"STM_C6_Driver.h"

/*====================================================================================================================================================
 *																	Generic Variables
 *====================================================================================================================================================
 */

struct S_IRQ_SRC{
	uint8_t TXE:1;			// TX buffer empty interrupt
	uint8_t RXNE:1;			// RX buffer Not Empty Interrupt
	uint8_t ERRI:1;			// Error Interrupt
	uint8_t Reserved:5;
};


typedef struct{
	 uint16_t	SPI_Device_Mode;
	 uint16_t 	SPI_Communication_Mode;
	 uint16_t	SPI_FrameFormat;
	 uint16_t 	SPI_DataSize;
	 uint16_t	SPI_ClkPolarity;
	 uint16_t	SPI_ClkPhase;
	 uint16_t	SPI_NSS;
	 uint16_t	SPI_BaudRate;
	 uint8_t	SPI_IRQ_Enable;
	 void(*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);

}SPI_Config_t;



enum PollingMechanism{
	Enable,
	Disable
};

/*====================================================================================================================================================
 *																	Generic Macros
 *====================================================================================================================================================
 */


#define SPI_DataSize_8bit							(uint32_t)(0)
#define SPI_DataSize_16bit							(uint32_t)(1<<11)

#define SPI_Master_Mode								(uint32_t)(1<<2 | 1<<6)
#define SPI_Slave_Mode								(uint32_t)(0)

#define SPI_FullDuplex_2Line_Mode					(uint32_t)(0)
#define SPI_FullDuplex_2Line_RXONLY_Mode			(uint32_t)(1<<10)
#define SPI_HalfDuplex_1Line_RX_MODE				(uint32_t)(1<<15)
#define SPI_HalfDuplex_1Line_TX_MODE				(uint32_t)(1<<15 | 1<<14)

#define SPI_FrameFormat_MSB							(uint32_t)(0)
#define SPI_FrameFormat_LSB							(uint32_t)(1<<7)


#define SPI_ClkPolarity_High						(uint32_t)(1<<1)  	//High means Raising edge
#define SPI_ClkPolarity_Low							(uint32_t)(0)		//Low means falling edge

#define SPI_ClkPhase_1EDGE							(uint32_t)(0)
#define SPI_ClkPhase_2EDGE							(uint32_t)(1<<0)


#define SPI_NSS_HW_Slave									(uint32_t)(0)
#define SPI_NSS_HW_Master_SS_Output_Enable					(uint32_t)(1<<2)
#define SPI_NSS_HW_Master_SS_Output_Disable					~((uint32_t)(1<<2))

#define SPI_NSS_SW_Slave_Reset								(uint32_t)(1<<9)
#define SPI_NSS_SW_Slave_Set								(uint32_t)(1<<9 | 1<<8)



#define SPI_BaudRate_PRESCAL_2							(uint32_t)(0)
#define SPI_BaudRate_PRESCAL_4							(uint32_t)(0b001<<3)
#define SPI_BaudRate_PRESCAL_8							(uint32_t)(0b010<<3)
#define SPI_BaudRate_PRESCAL_16							(uint32_t)(0b011<<3)
#define SPI_BaudRate_PRESCAL_32							(uint32_t)(0b100<<3)
#define SPI_BaudRate_PRESCAL_64							(uint32_t)(0b101<<3)
#define SPI_BaudRate_PRESCAL_128						(uint32_t)(0b110<<3)
#define SPI_BaudRate_PRESCAL_256						(uint32_t)(0b111<<3)


#define SPI_IRQ_Enable_NONE								(uint32_t)(0)
#define SPI_IRQ_Enable_TXEIE							(uint32_t)(1<<7)
#define SPI_IRQ_Enable_RXNEIE							(uint32_t)(1<<6)
#define SPI_IRQ_Enable_ERRIE							(uint32_t)(1<<5)


/*====================================================================================================================================================
 *																			APIs
 *====================================================================================================================================================
 */




void MCAL_SPI_Init(SPI_Config_t* SPI_Cnfg,SPI_REG_t* SPIx);
void MCAL_SPI_DeInit(SPI_REG_t* SPIx);
void MCAL_SPI_GPIO_Init(SPI_REG_t* SPIx);
void MCAL_SPI_TX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism);
void MCAL_SPI_RX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism);
void MCAL_SPI_TX_RX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism);



#endif /* INC_STM32F103_C6_SPI_DRIVER_H_ */
