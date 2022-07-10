/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	int a;
	printf("Enter an integer");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	if(a%2==0){
		printf("\'%d\'2 is even number",a);
	}else{
		printf("%d is odd number",a);
	}
}
