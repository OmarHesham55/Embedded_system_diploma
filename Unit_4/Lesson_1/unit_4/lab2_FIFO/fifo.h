/*
 * fifo.h
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */

#ifndef FIFO_H_
#define FIFO_H_


#include<stdint.h>
#include<stdio.h>
#define type uint8_t
//initialize buffer
typedef struct{
	uint32_t length;
	uint32_t count;
	type* start;
	type* end;
	type* point;
}FIFO_INIT_BUFF;


//return status
typedef enum{
		FIFO_noerror,
		FIFO_NULL,
		FIFO_isFull,
		FIFO_empty,
}FIFO_STATUS;




//APIs

FIFO_STATUS FIFO_initialize(FIFO_INIT_BUFF* fifo_init,uint32_t length,type* buffer);
FIFO_STATUS FIFO_Push(FIFO_INIT_BUFF* buffer,uint32_t item);
FIFO_STATUS FIFO_POP(FIFO_INIT_BUFF* buffer,uint32_t* item);

#endif /* FIFO_H_ */
