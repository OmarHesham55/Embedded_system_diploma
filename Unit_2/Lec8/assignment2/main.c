/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	char alpha[27];
	char *ptr = alpha;
	int i;

	for(i=0;i<27;i++){
		*ptr = i+'A';
		 ptr++;
	}

	ptr = alpha;
	printf("Alphabet is:\n");
	for(i=0;i<26;i++){
		printf(" %c ",*ptr);
		ptr++;
	}

}
