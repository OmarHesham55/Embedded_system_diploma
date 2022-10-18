/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */


#include"fifo.h"
#include<stdio.h>
#include<stdint.h>

#define length 5
type buffer[length];

int main(){
	uint32_t i,j=0;

	//initialize fifo

	FIFO_INIT_BUFF uart;
	uint32_t init_status = FIFO_initialize(&uart,length,buffer);

	//push item

	if(init_status == FIFO_noerror){
		for(i=0;i<6;i++){
			switch (FIFO_Push(&uart,i)) {
				case FIFO_noerror:
						printf("%d is pushed done\n\n",i);
					break;
				case FIFO_isFull:
						printf("%d failed to push\t----buffer is full----\n\n",i);
					break;
				default:
					printf("something went wrong\n\n");
					break;
			}
		}
	}else
		return FIFO_NULL;

	//check buffer --1
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}

	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}


	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}



	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}



	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}



	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}

	//check buffer --2
	if(FIFO_POP(&uart,&j) == FIFO_noerror){
			printf("%d is popped successfully\n\n",j);
	}else{
		switch (FIFO_POP(&uart,&j)) {
			case FIFO_empty:
					printf("nothing to pop\n\n");
				break;
			case FIFO_NULL:
					printf("buffer doesn't exist\n\n");
				break;
			default:
				break;
		}
	}




}
