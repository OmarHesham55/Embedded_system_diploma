/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){

	int a ,b;

	printf("Enter value of A.\t");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);

	printf("Enter value of B.\t");
	fflush(stdin); fflush(stdout);
	scanf("%d",&b);


	printf("After swapping\n A=\'%d\',B=\'%d\'", b , a);
}
