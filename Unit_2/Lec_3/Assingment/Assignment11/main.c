/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"
#include "ctype.h"

int main(){
	char x;
	printf("Enter an input\n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	if(isalpha(x)){
		printf("This Input \'%c\'is a alphabet",x);
	}else{
		printf("this input is not alphabet \'%c\'",x);
	}
}
