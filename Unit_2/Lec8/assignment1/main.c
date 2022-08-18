/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: omart
 */
#include "stdio.h"

//Q_1


int main(){
		int m;
		int *pAB = &m;

	printf("Enter a number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&m);

	printf("\nAddress of m:%p\n",&m);
	printf("value of m:%d\n",m);
	printf("ab is assigned with the address of m.\n");
	printf("address of pointer ab:%p\n",pAB);
	printf("value of pointer ab:%d\n",*pAB);
	printf("change the number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&m);
	printf("\nsame Address of m:%p\n",&m);
	printf("now value of m:%d\n",m);
	printf("same address of pointer ab:%p\n",pAB);
	printf("value of pointer ab:%d\n",*pAB);





}


