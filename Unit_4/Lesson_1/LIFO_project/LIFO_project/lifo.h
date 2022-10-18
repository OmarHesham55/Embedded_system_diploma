/*
 * lifo.h
 *
 *  Created on: Sep 17, 2022
 *      Author: omart
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>

#define TYPE uint32_t

typedef struct {
	TYPE length;
	TYPE  count;
	TYPE*  base;
	TYPE*  head;
}LIFO_BUFFER_t;

typedef enum{
	LIFO_no_error, //0
	LIFO_full,     //1
	LIFO_empty,    //2
	LIFO_NULL      //3
}LIFO_STATUS_t;

//functions

LIFO_STATUS_t LIFO_PUSH_ITEM(LIFO_BUFFER_t* buffer_name,TYPE data);
LIFO_STATUS_t LIFO_POP_ITEM(LIFO_BUFFER_t* buffer_name,TYPE* data);
LIFO_STATUS_t LIFO_INIT(LIFO_BUFFER_t* buffer_name,TYPE* buffer,TYPE LENGTH);

#endif /* LIFO_H_ */
