/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: omart
 */


#include "stdio.h"
#include "string.h"

int main(){
	char str[100],letter;
	short counter=0, i;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	printf("the statement is: \'%s\',",str);

	printf("\nEnter the Letter to find the frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&letter);

	for(i=0; i<strlen(str); i++){
		if(str[i] == letter){
			counter++;
		}
	}

	printf("frequency of \'%c\' is: %hd", letter,counter);

}
