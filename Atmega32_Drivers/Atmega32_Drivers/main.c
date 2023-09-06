/*
 * Atmega32_Drivers.c
 *
 * Created: 9/4/2023 4:27:26 PM
 * Author : omart
 */ 

#include "MCAL/inc/GPIO.h"

int main(void)
{
/***** For Testing *******
	
	Pin_Init_t pinInit;
	pinInit.GPIOx = PORTA_e;
	pinInit.pinDirection = output_e;
	pinInit.pinNumber = PIN_NUMBER_ALL;
	MCAL_GPIO_Init(&pinInit);
	
	while(1){
		
	MCAL_GPIO_TogglePort(PORTA_e);
	
		for (int i=0; i<2; i++){
			for(int j=0; j<500; j++);
		}
	 }
*/

	Pin_Init_t pinInit;
	pinInit.GPIOx = PORTA_e;
	pinInit.pinDirection = output_e;
	pinInit.pinNumber = PIN_NUMBER_5;
	MCAL_GPIO_Init(&pinInit);
	
	pinInit.GPIOx = PORTA_e;
	pinInit.pinDirection = input_e;
	pinInit.pinNumber = PIN_NUMBER_0;
	MCAL_GPIO_Init(&pinInit);
	
	while (1);
	{
		uint8_t val;
		val = MCAL_GPIO_ReadPin(PORTA_e,PIN_NUMBER_0);
		if ()
		{
		}
	}
}


