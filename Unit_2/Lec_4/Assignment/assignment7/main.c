/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: omart
 */


#include "stdio.h"
#include "string.h"

int main(){

	char str[50];
	short counter=0,i;

	printf("Enter a statement: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	for(i=0; i<str[i] && str[i]!=0; i++){
		counter++;
	}

	printf("statement is: %hd",counter);
}
