/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){

	int val,sum=0,i=0 ;
	printf("Enter a positive integer..");
	fflush(stdin); fflush(stdout);
	scanf("%d",&val);

		if(val == 0){
			printf("You inserted Zero choose another integer instead");
		}else if(val<0){
			printf("Insert a positive integer");
		}else{
			while(i<=val){
				sum += i;
				i++;
			}
			printf("%d",sum);
		}

}
