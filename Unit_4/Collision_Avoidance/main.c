/*
 * main.c
 *
 *  Created on: Oct 20, 2022
 *      Author: omart
 */
#include<stdio.h>
#include<stdlib.h>
#include"CA.h"

void setup(){
	CA_state_ptr = state(CA_Waiting);
}

int main(){

	setup();

	while(1){
		CA_state_ptr();
	}

}
