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
	short i;

	printf("Enter a statement: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	printf("\nyou wrote: \'%s\'\n",str);

	printf("\nreversed statement is: ");

	for(i=strlen(str)-1; i>=0; i--){
		printf("%c",str[i]);
	}

}
