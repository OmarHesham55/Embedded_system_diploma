/*
 * mian.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){
	char character;
	printf("Enter the character\t");
	fflush(stdin); fflush(stdout);
	scanf("%c",&character);
	printf("The ASCII Code for the character \"%c\" is:%d",character,character);

}
