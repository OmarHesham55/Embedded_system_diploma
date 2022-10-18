/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: omart
 */


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "lifo.h"

uint32_t buffer[5];

int main(){
	uint32_t temp=0,i;
//	LIFO_BUFF_STATUS status;

	//static memory location

	//initialize buffers
	LIFO_BUFF uart_buffer;


	// create the buffer
	uint32_t init_status = LIFO_create_buff(&uart_buffer,5,buffer);

	//dynamic memory location

	//uint32_t* buffer2 = (uint32_t*) malloc(5 * sizeof(uint32_t));

	if(init_status == no_error){
		for( i=0;i<7;i++){
			switch (LIFO_push_item(&uart_buffer,i)) {
				case no_error:
						printf("item %d pushed successfully\n\n",i);
					break;
				case buff_full:
						printf("item %d failed to push\t--buffer is full--\n\n",i);
					break;
				default:
					printf("ay haga ====switch case default====\n");
					break;
			}
		}
	}else{
		printf("mmmmmmm\n");
	}


	for(i=0; i<7; i++){
			switch ( LIFO_pop_item(&uart_buffer,&temp) ) {
				case no_error:
					printf("%d is popped successfully\n\n",temp);
					break;

				case buff_empty:
					printf("buffer is empty\n\n");
					break;

				default:
					printf("buffer is null\n");
					break;
			}
	}


}
