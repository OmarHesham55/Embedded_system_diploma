/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: omart
 */

#define max 100

#include<stdio.h>
#include<string.h>
int main(){
	char sentence[max];
	char *p;
	int i;
	printf("put here a sentence:");
	fflush(stdin); fflush(stdout);
	fgets(sentence,max,stdin);
	printf("\nYou entered: %s\n",sentence);
	 i = strlen(sentence);
	 p = &sentence[i-1];
	 printf("Reversed Sentence is:");
	 while(p!=&sentence[0]-1){
		printf("%c",*p);
		--p;
	}
}
