/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: omart
 */

#include "lifo.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

TYPE buffer1[5];

void main(){
	TYPE i,temp=0;

	// create two buffers
	LIFO_BUFFER_t uart_buffer , I2C_buffer;

	//initialize the first buffer in static memory
	LIFO_INIT(&uart_buffer,buffer1,5);


	//initialize&create the second buffer in dynamic memory
	TYPE* buffer2 = (TYPE*) malloc(5 * sizeof(TYPE));

	LIFO_INIT(&I2C_buffer,buffer2,5);


	for(i=0;i<7;i++){
		if(LIFO_PUSH_ITEM(&uart_buffer,i) == LIFO_no_error){
			printf("UART_BUFFER PUSHED: %d \n",i);
		}
	}

	for(i=0;i<7;i++){
		if(LIFO_POP_ITEM(&uart_buffer,&temp)== LIFO_no_error){
			printf("UART_BUFFER POPED: %d \n",temp);
		}
	}

}
