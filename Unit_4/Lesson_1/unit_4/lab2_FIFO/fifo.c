/*
 * fifo.c
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */
#include"fifo.h"
#include <stdio.h>
#include<stdlib.h>
FIFO_STATUS FIFO_initialize(FIFO_INIT_BUFF* fifo_init,uint32_t length,type* buffer){
	if(fifo_init != NULL){
		fifo_init->start =buffer;
		fifo_init->end =buffer;
		fifo_init->point =buffer;
		fifo_init->count=0;
		fifo_init->length = length;
		return FIFO_noerror;
	}else
		return FIFO_NULL;
}


FIFO_STATUS FIFO_Push(FIFO_INIT_BUFF* buffer,uint32_t item){
	//check buffer exist or not
	if(!buffer->start||!buffer->end)
		return FIFO_noerror;

	//check buffer is full or not
	if(buffer->count >= buffer->length)
		return FIFO_isFull;

	// push the data
	*(buffer->end) = item;
	  buffer->count++;

	if(buffer->end == (buffer->start+(buffer->length*sizeof(type)))){
		buffer->end = buffer->start;
	}else
		buffer->end++;

	return FIFO_noerror;
}

FIFO_STATUS FIFO_POP(FIFO_INIT_BUFF* buffer,uint32_t* item){

	//check buffer exist or not
	if(!buffer->start||!buffer->end||!buffer->point)
		return FIFO_noerror;

	//check buffer is empty or not
	if(buffer->count == 0)
		return FIFO_empty;


	//pop the data
	*item = *buffer->point;
	buffer->count--;
//	printf("\t\t=========%d=========\n\n",*item); 		//for checking

	//check circularity
	if(buffer->point == (buffer->start + (buffer->length * sizeof(type)))){
		buffer->point = buffer->start;
	}else
		buffer->point++;

	return FIFO_noerror;
}
