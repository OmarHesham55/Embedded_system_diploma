/*
 * lifo.h
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>

// define the stack
typedef struct{
	uint32_t count;
	uint32_t* base;
	uint32_t* head;
	uint32_t length;
}LIFO_BUFF;

// status of buffer
typedef enum{
	no_error,     //0
	buff_full,    //1
	buff_empty,   //2
	buff_null     //3
}LIFO_BUFF_STATUS;



//APIs

LIFO_BUFF_STATUS	LIFO_push_item(LIFO_BUFF* buffer , uint32_t pushed_item);
LIFO_BUFF_STATUS    LIFO_pop_item(LIFO_BUFF* buffer , uint32_t* poped_item);
LIFO_BUFF_STATUS	LIFO_create_buff(LIFO_BUFF* buffer_init,uint32_t length,uint32_t* buff);

#endif /* LIFO_H_ */
