/*
 * main.c
 *
 *  Created on: Jul 12, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){

	float arr[50];
	int ele,i;
	float sum;
	printf("Enter the number of elements ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&ele);

	for(i=0; i<ele; i++){
		printf("Element no.%d ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&arr[i]);
	}

	for(i=0; i<ele; i++){
		sum += arr[i];
	}

	printf("Average number is: %f",sum/ele);
}
