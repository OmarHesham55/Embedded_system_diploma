/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	int ele,arr[50],i,Snum,exist=0;

	printf("Enter the number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&ele);

	for(i=0; i<ele; i++){
		printf("element %d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}



	printf("\nEnter the number to search in elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&Snum);



	for(i=0; i<ele; i++){
		if(arr[i] == Snum){
			exist = 1;
			break;
		}
	}

	if(exist==1){
		printf("number is founded in location: %d",i+1);
	}else{
		printf("number doesn't exist");
	}

}
