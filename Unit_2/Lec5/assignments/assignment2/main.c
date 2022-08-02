/*
 * main.c
 *
 *  Created on: Jul 28, 2022
 *      Author: omart
 */


#include "stdio.h"

int func1(int num){
	int i,sum=1;
	for(i=num; i>1; --i){
		sum *= i;
	}
	printf("%d",sum);
	return sum;
}

int main(){
	int x;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	func1(x);
}
