/*
 * lifo.c
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */

#include "lifo.h"
#include <stdio.h>
#include <stdint.h>

LIFO_BUFF_STATUS	LIFO_create_buff(LIFO_BUFF* buffer_init,uint32_t length,uint32_t* buff){
	if(buff != NULL ){
		buffer_init->base = buff;
		buffer_init->head = buff;
		buffer_init->length = length;
		buffer_init->count = 0;
		return no_error; //0
	}else{
		return buff_null; //4
	}
}

LIFO_BUFF_STATUS	LIFO_push_item(LIFO_BUFF* buffer , uint32_t pushed_item){

	//check if the buffer valid or not

	if(!buffer->base || !buffer->head){
			return buff_null;
	}

	// check if the buffer is full or not

	if(buffer->count >= buffer->length)
		return buff_full;

	// push the item

	*(buffer->head) = pushed_item;
//	printf("\t\t=====%d====\n\n",*buffer->base);
//	printf("\t\t=====%d====\n\n",*buffer->head);
	  buffer->head++;
 	  buffer->count++;
 	  return no_error;
}

LIFO_BUFF_STATUS    LIFO_pop_item(LIFO_BUFF* buffer , uint32_t* poped_item){
	if(!buffer->base || !buffer->head)
		return buff_null;

	if(buffer->count == 0)
		return buff_empty;

//	printf("\t\t=====%d====\n\n",*buffer->head);
	buffer->head--;
//	printf("\t\t=====%d====\n\n",*buffer->head);
   *poped_item = *buffer->head;
	buffer->count--;
	return no_error;
}
