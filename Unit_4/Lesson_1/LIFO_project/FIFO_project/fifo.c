/*
 * fifo.c
 *
 *  Created on: Sep 18, 2022
 *      Author: omart
 */

#include "fifo.h"
#include<stdio.h>
#include<stdint.h>

FIFO_STATUS_t FIFO_INIT(FIFO_BUFFER_t* FIFO_INIT, TYPE* FIFO_BUFFER, uint32_t LENGTH ){

	if(	FIFO_INIT && FIFO_BUFFER){
		FIFO_INIT->base   = FIFO_BUFFER;
		FIFO_INIT->head   = FIFO_BUFFER;
		FIFO_INIT->tail   = FIFO_BUFFER;
		FIFO_INIT->legnth = LENGTH;
		FIFO_INIT->count  = 0;
		return FIFO_NO_ERROR;
	}else{
		printf("something went wrong\n");
		return FIFO_NULL;
	}
}


FIFO_STATUS_t FIFO_CHECK(FIFO_BUFFER_t* FIFO_INIT){

	if(!FIFO_INIT->base || !FIFO_INIT->head || !FIFO_INIT->tail){
		printf("Something went wrong\n");
		return FIFO_NULL;
	}
	if(FIFO_INIT->count >= FIFO_INIT->legnth){
		return FIFO_FULL;
	}

	return FIFO_NO_ERROR;
}


FIFO_STATUS_t FIFO_ENQU(FIFO_BUFFER_t* FIFO_INIT, TYPE* DATA ){


	if(FIFO_CHECK(FIFO_INIT) == FIFO_NO_ERROR){
		*(FIFO_INIT->head) = *DATA;
		  FIFO_INIT->count++;

		  if(FIFO_INIT->head == (FIFO_INIT->base + (FIFO_INIT->legnth * sizeof(TYPE))))
			  FIFO_INIT->head = FIFO_INIT->base;
		  else
			  FIFO_INIT->head++;

		  return FIFO_NO_ERROR;
	}else{
		printf("FIFO ENQU (%d) is FAILED-----\n",*DATA);
		return FIFO_FULL;
	}

}


FIFO_STATUS_t FIFO_DEQU(FIFO_BUFFER_t* FIFO_INIT, TYPE* DATA ){

	if( FIFO_CHECK(FIFO_INIT) == FIFO_NO_ERROR || !FIFO_INIT->count == 0){

		*DATA = *(FIFO_INIT->tail);
		FIFO_INIT->count--;

		if(FIFO_INIT->tail == (FIFO_INIT->tail + (FIFO_INIT->legnth * sizeof(TYPE))))
			FIFO_INIT->tail = FIFO_INIT->base;
		else
			FIFO_INIT->tail++;
		return FIFO_NO_ERROR;
	}
	else{
		return FIFO_NULL;
	}
}



void FIFO_PRINT(FIFO_BUFFER_t* FIFO_INIT){
	TYPE* temp;
	int i;
	if(FIFO_INIT->count == 0){
		printf("Buffer is empty\n");
	}else{
		temp = FIFO_INIT->tail;
		printf("\n -------FIFO_PRINT-------\n");
		for(i=0;i<FIFO_INIT->count; i++){
			printf("\t %d \n",*temp);
			temp++;
		}
		printf("--------------------\n");
	}

}
