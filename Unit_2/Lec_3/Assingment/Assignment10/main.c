/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	int x;
	printf("Enter an integer\t");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	if(x > 0 ){
		printf(" \'%d\' is positive",x);
	}else if(x < 0){
		printf(" \'%d\' is negative",x);
	}else{
		printf(" \'%d\' is zero",x);
	}
}

