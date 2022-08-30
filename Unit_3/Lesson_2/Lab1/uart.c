#include "uart.h"
#include <stdio.h>

#define UARTDR0 *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void uart_send_string(unsigned char* P_tx_string){
	while(*P_tx_string!='\0'){
		UARTDR0 = (unsigned char)(*P_tx_string);
		P_tx_string++;
	}
}