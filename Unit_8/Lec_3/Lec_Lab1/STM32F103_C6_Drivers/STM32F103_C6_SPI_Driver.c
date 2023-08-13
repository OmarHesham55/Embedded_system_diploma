/*
 * STM32F103_C6_SPI_Driver.c
 *
 *  Created on: Aug 10, 2023
 *      Author: omart
 */


#include"STM32F103_C6_SPI_Driver.h"
#include"STM32F103_C6_GPIO_Driver.h"



/*====================================================================================================================================================
 *																	Generic Variables
 *====================================================================================================================================================
 */

SPI_Config_t* Global_Temp_Config[2] = {NULL,NULL};

GPIO_Pin_init_t pinCnfg;



/*====================================================================================================================================================
 *																	Generic Macros
 *====================================================================================================================================================
 */

#define SPI1_Index			0
#define SPI2_Index			1


#define SPI_SR_TXE			((uint8_t)0x2)
#define SPI_SR_RXE			((uint8_t)0x1)

/*====================================================================================================================================================
 *																			APIs
 *====================================================================================================================================================
 */



void MCAL_SPI_Init(SPI_Config_t* SPI_Cnfg,SPI_REG_t* SPIx)
{
	uint16_t tempCr1Reg = 0;
	uint16_t tempCr2Reg = 0;

	if(SPIx == SPI1)
	{
		Global_Temp_Config[SPI1_Index] = SPI_Cnfg;
		ENB_SPI1();
	}
	else if(SPIx == SPI2)
	{
		Global_Temp_Config[SPI2_Index] = SPI_Cnfg;
		ENB_SPI2();
	}

	//Enable SPI CR1:Bit 6
	tempCr1Reg |= (1<<6);

	//Master Or Slave
	tempCr1Reg |= SPI_Cnfg->SPI_Device_Mode;

	//SPI FrameFormat
	tempCr1Reg |= SPI_Cnfg->SPI_FrameFormat;

	//SPI DataSize
	tempCr1Reg |= SPI_Cnfg->SPI_DataSize;

	//Communication Mode FullDuplex/HalfDuplex/Simplex
	tempCr1Reg |= SPI_Cnfg->SPI_Communication_Mode;

	//SPI Clock polarity
	tempCr1Reg |= SPI_Cnfg->SPI_ClkPolarity;

	//SPI Clock Phase
	tempCr1Reg |= SPI_Cnfg->SPI_ClkPhase;


	//=======================NS====================

	if(SPI_Cnfg->SPI_NSS == SPI_NSS_HW_Master_SS_Output_Enable)
	{
		tempCr2Reg |= SPI_Cnfg->SPI_NSS;
	}
	else if(SPI_Cnfg->SPI_NSS == SPI_NSS_HW_Master_SS_Output_Disable)
	{
		tempCr2Reg &= SPI_Cnfg->SPI_NSS;
	}
	else
	{
		tempCr1Reg |= SPI_Cnfg->SPI_NSS;
	}

	// SPI BaudRate
	tempCr1Reg |= SPI_Cnfg->SPI_BaudRate;

	if(SPI_Cnfg->SPI_IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_EN();
		}
		else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_EN();
		}
	}


	SPIx->SPI_CR1 = tempCr1Reg;
	SPIx->SPI_CR2 = tempCr2Reg;

}
void MCAL_SPI_DeInit(SPI_REG_t* SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_DIS();
		RES_SPI1();
	}
	else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_DIS();
		RES_SPI2();
	}
}
void MCAL_SPI_GPIO_Init(SPI_REG_t* SPIx)
{

	if(SPIx == SPI1)
	{
		//PinA4 NSS
		//PinA5 SCLK
		//PinA6 MISO
		//PinA7 MOSI

		if(Global_Temp_Config[SPI1_Index]->SPI_Device_Mode == SPI_Master_Mode)
		{
			//Set SCK Pin
			pinCnfg.PIN_NUM = PIN_NUM__5;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);

			//Set MOSI pin
			pinCnfg.PIN_NUM = PIN_NUM__7;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);

			//Set MISO pin
			pinCnfg.PIN_NUM = PIN_NUM__6;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);

			switch (Global_Temp_Config[SPI1_Index]->SPI_NSS)
			{
				case SPI_NSS_HW_Master_SS_Output_Enable:
					pinCnfg.PIN_NUM = PIN_NUM__4;
					pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
					pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
					MCAL_GPIO_INIT(GPIOA, &pinCnfg);
					break;
				case SPI_NSS_HW_Master_SS_Output_Disable:
					pinCnfg.PIN_NUM = PIN_NUM__4;
					pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
					MCAL_GPIO_INIT(GPIOA, &pinCnfg);
					break;
			}
		}
		else{

			//Set NSS Pin
			if(Global_Temp_Config[SPI1_Index]->SPI_NSS == SPI_NSS_HW_Slave)
			{
				pinCnfg.PIN_NUM = PIN_NUM__4;
				pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
				MCAL_GPIO_INIT(GPIOA, &pinCnfg);
			}
			//Set SCK Pin
			pinCnfg.PIN_NUM = PIN_NUM__5;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);

			//Set MOSI pin
			pinCnfg.PIN_NUM = PIN_NUM__7;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);

			//Set MISO pin
			pinCnfg.PIN_NUM = PIN_NUM__6;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pinCnfg);
		}

	}
	else if(SPIx == SPI2)
	{
		//PinB12 NSS
		//PinB13 SCLK
		//PinB14 MISO
		//PinB15 MOSI

		if(Global_Temp_Config[SPI2_Index]->SPI_Device_Mode == SPI_Master_Mode)
		{
			//Set SCK Pin
			pinCnfg.PIN_NUM = PIN_NUM__13;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);

			//Set MOSI pin
			pinCnfg.PIN_NUM = PIN_NUM__15;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);

			//Set MISO pin
			pinCnfg.PIN_NUM = PIN_NUM__14;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);

			switch (Global_Temp_Config[SPI2_Index]->SPI_NSS)
			{
				case SPI_NSS_HW_Master_SS_Output_Enable:
					pinCnfg.PIN_NUM = PIN_NUM__12;
					pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
					pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
					MCAL_GPIO_INIT(GPIOB, &pinCnfg);
					break;

				case SPI_NSS_HW_Master_SS_Output_Disable:
					pinCnfg.PIN_NUM = PIN_NUM__12;
					pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
					MCAL_GPIO_INIT(GPIOB, &pinCnfg);
					break;
			}
		}
		else{

			//Set NSS Pin
			if(Global_Temp_Config[SPI2_Index]->SPI_NSS == SPI_NSS_HW_Slave)
			{
				pinCnfg.PIN_NUM = PIN_NUM__12;
				pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
				MCAL_GPIO_INIT(GPIOB, &pinCnfg);
			}
			//Set SCK Pin
			pinCnfg.PIN_NUM = PIN_NUM__13;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);

			//Set MOSI pin
			pinCnfg.PIN_NUM = PIN_NUM__15;
			pinCnfg.PIN_MODE = GPIO_MODE_FLOATING_IP;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);

			//Set MISO pin
			pinCnfg.PIN_NUM = PIN_NUM__14;
			pinCnfg.PIN_MODE = GPIO_MODE_AF_PUSH_PULL_OP;
			pinCnfg.PIN_SPEED = GPIO_MODE_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB, &pinCnfg);
		}


	}
}
void MCAL_SPI_TX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism)
{
	if(pollMechanism == Enable)
	{
		while(!((SPIx->SPI_SR)& SPI_SR_TXE));
	}
	SPIx->SPI_DR = *Data;

}
void MCAL_SPI_RX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism)
{
	if(pollMechanism == Enable)
	{
		while(!((SPIx->SPI_SR)& SPI_SR_RXE));
	}
	*Data = SPIx->SPI_DR;
}
void MCAL_SPI_TX_RX(SPI_REG_t* SPIx,uint16_t* Data,enum PollingMechanism pollMechanism)
{
	if(pollMechanism == Enable){
		while(!((SPIx->SPI_SR)&SPI_SR_TXE));
	}
	SPIx->SPI_DR = *Data;

	if(pollMechanism == Enable)
		while(!((SPIx->SPI_SR)&SPI_SR_RXE));
	*Data = SPIx->SPI_DR;
}






/*====================================================================================================================================================
 *																			IRQ
 *====================================================================================================================================================
 */

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE = ((SPI1->SPI_SR & (1<<1) )>> 1);
	irq_src.RXNE = ((SPI1->SPI_SR & (1<<0) )>> 0);
	irq_src.ERRI = ((SPI1->SPI_SR & (1<<4) )>> 4);

	Global_Temp_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}


void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE = ((SPI1->SPI_SR & (1<<1) )>> 1);
	irq_src.RXNE = ((SPI1->SPI_SR & (1<<0) )>> 0);
	irq_src.ERRI = ((SPI1->SPI_SR & (1<<4) )>> 4);

	Global_Temp_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);

}
