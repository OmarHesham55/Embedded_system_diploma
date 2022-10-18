/*
 * uart.c
 *
 *  Created on: Sep 27, 2022
 *      Author: omart
 */

#include "uart.h"
#define UART0DR *((volatile unsigned int*)((unsigned int*)0x101f1000))

void rx_string(unsigned char* word){

	while(*word != '\0'){
		UART0DR = (unsigned int)word;
		word++;
	}

}
