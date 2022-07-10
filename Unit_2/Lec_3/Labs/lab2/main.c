/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */

#include "stdio.h"

int main(){

	int x,y,z;
	printf("Enter three values you need to compare\n");
	fflush(stdin); fflush(stdout);
	scanf("%d\n %d\n %d",&x,&y,&z);

		if(x>y){
			if(x>z){
				printf("%d is the largest value",x);
			}else{
				printf("%d is the largest value",z);
			}
		}else{
			if(y>z){
				printf("%d is the largest value",y);
			}else{
				printf("%d is the largest value",z);
			}
		}



}
