/*
 * CA.c
 *
 *  Created on: Oct 20, 2022
 *      Author: omart
 */



#include"CA.h"
#include<stdlib.h>
#include<stdio.h>

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;
int check_distance(int l , int r,int count);


//state pointer to function

void (*CA_state_ptr)();


state_define(CA_Waiting){


	CA_speed = 0;

	CA_distance =  check_distance(45 , 55, 1);

	(CA_distance <= CA_threshold) ? (CA_state_ptr = state(CA_Waiting)):(CA_state_ptr = state(CA_Driving));
	printf("CA_State: Waiting state CA_Distance: %d  CA_Speed:%d\n",CA_distance, CA_speed);

}

state_define(CA_Driving){

	CA_speed = 30;

	CA_distance =  check_distance(45 , 55, 1);

	(CA_distance > CA_threshold) ? (CA_state_ptr = state(CA_Driving)):(CA_state_ptr = state(CA_Waiting));

	printf("CA_State: Driving state CA_Distance: %d  CA_Speed:%d\n",CA_distance, CA_speed);

}


int check_distance(int l , int r,int count){
	int rand_num;
	for(int i =0; i <count; i++){
		 rand_num = (rand() % (r-l+1)) + l;
	}
	return rand_num;
}
