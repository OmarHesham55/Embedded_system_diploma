/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	float x,y;
	printf("Enter two numbers.\n");
	fflush(stdin); fflush(stdout);
	scanf("%f\n %f",&x ,&y);
	printf("product is:%f",x*y);
}
