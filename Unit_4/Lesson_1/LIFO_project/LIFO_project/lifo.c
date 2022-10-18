/*
 * lifo.c
 *
 *  Created on: Sep 17, 2022
 *      Author: omart
 */



#include"lifo.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

LIFO_STATUS_t LIFO_PUSH_ITEM(LIFO_BUFFER_t* buffer_name,TYPE data){

		// check Buffer is valid
		if(!buffer_name->base || !buffer_name->head){
			printf("%d lifo is null push\n",LIFO_NULL);
			return LIFO_NULL;
		}

		// check buffer is full
		if(buffer_name->count >= buffer_name->length){
			printf("%d lifo is full   push\n",LIFO_full);
			return LIFO_full;

		}

		*(buffer_name->head) = data;
		  buffer_name->head ++;
		  buffer_name->count++;

		  printf("\n\n%d lifo added successfully ",LIFO_no_error);
		  return LIFO_no_error;
}

LIFO_STATUS_t LIFO_POP_ITEM(LIFO_BUFFER_t* buffer_name,TYPE* data){

	// check Buffer is valid
	if(!buffer_name->base || !buffer_name->head){
		printf("%d lifo is null  pop\n",LIFO_NULL);
		return LIFO_NULL;
	}

	//check buffer is empty
	if(buffer_name->count == 0){
		printf("%d lifo is empty   pop\n",LIFO_empty);
		return LIFO_empty;
	}
//	printf("\n%d---%x\n",*(buffer_name->head),buffer_name->head);
	buffer_name->head--;
//	printf("\n%d---%x\n",*(buffer_name->head),buffer_name->head);
	*data = *(buffer_name->head);
	buffer_name->count--;

	return 0;
}


LIFO_STATUS_t LIFO_INIT(LIFO_BUFFER_t* buffer_name,TYPE* buffer,TYPE LENGTH){

	if(buffer == NULL){
		printf("%d lifo is null init\n",LIFO_NULL);
		return LIFO_NULL;
	}

	buffer_name->base = buffer;
	buffer_name->head = buffer;
	buffer_name->length = LENGTH;
	buffer_name->count = 0;

	return LIFO_no_error;
}
