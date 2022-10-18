/*
 * main.c
 *
 *  Created on: Sep 18, 2022
 *      Author: omart
 */


#include"fifo.h"
#include<stdio.h>
#include<stdint.h>

#define length 5
TYPE buffer[length];

void main(){
	uint32_t i,temp=0;

	FIFO_BUFFER_t uart_buffer;
	if(	FIFO_INIT(&uart_buffer,buffer,length) == FIFO_NO_ERROR ){
		printf("----------------FIFO INIT IS DONE--------\n");
	}

	for(i=0;i<7;i++){
		if( FIFO_ENQU(&uart_buffer,&i) == FIFO_NO_ERROR ){
			printf("ENQE IS PUSHED %d\n",i);
		}
	}

	FIFO_PRINT(&uart_buffer);
	if(	FIFO_DEQU(&uart_buffer,&temp) == FIFO_NO_ERROR){
		printf("DEQU IS POPED WELL\n");
	}else
		printf("DEQUE IS FAILED\n");

	if(	FIFO_DEQU(&uart_buffer,&temp) == FIFO_NO_ERROR){
		printf("DEQU IS POPED WELL\n");
	}else
		printf("DEQUE IS FAILED\n");

	FIFO_PRINT(&uart_buffer);
}
