/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"
int main(){
	int x,y;

	printf("Enter two numbers:\n");
	fflush(stdin); fflush(stdout);

	scanf("%d\t %d",&x,&y);
	printf(" minimum number is:\"%d\" ",(x>y)?y:x );
}
