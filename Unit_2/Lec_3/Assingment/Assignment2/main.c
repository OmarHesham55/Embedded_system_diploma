/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	int x;

	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("You Entered \"%d\"",x);
}
