/*
 * fifo.h
 *
 *  Created on: Sep 18, 2022
 *      Author: omart
 */

#ifndef FIFO_H_
#define FIFO_H_


#include<stdint.h>
#include<stdio.h>
#define TYPE uint8_t

typedef struct{
	TYPE* base;
	TYPE* head;
	TYPE* tail;
	unsigned int count;
	unsigned int legnth;
}FIFO_BUFFER_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_NULL,
	FIFO_FULL,
	FIFO_EMPTY
}FIFO_STATUS_t;

FIFO_STATUS_t FIFO_INIT(FIFO_BUFFER_t* FIFO_INIT, TYPE* FIFO_BUFFER, uint32_t LENGTH );
FIFO_STATUS_t FIFO_ENQU(FIFO_BUFFER_t* FIFO_INIT, TYPE* DATA );
FIFO_STATUS_t FIFO_DEQU(FIFO_BUFFER_t* FIFO_INIT, TYPE* DATA );
FIFO_STATUS_t FIFO_CHECK(FIFO_BUFFER_t* FIFO_BUFFER);
void FIFO_PRINT(FIFO_BUFFER_t* FIFO_INIT);

#endif /* FIFO_H_ */
