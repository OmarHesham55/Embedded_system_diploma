/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: omart
 */

#include <stdio.h>

int main(){
	float r;
    float sol;
	char choice;

	printf("Enter the radius of the circle..");
	fflush(stdin); fflush(stdout);
	scanf("%f",&r);
	printf("Enter \"A\" to calculate Area or \"C\" to Calculate Circumference. \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&choice);

	if(choice == 'A' || choice == 'a'){
		sol = 3.14*r*r;
		printf("Solution is = %f", sol);
	}else if(choice == 'C' || choice == 'c'){
		sol = 2*3.14*r;
		printf("Solution is = %f", sol);
	}else{
		printf("Enter a correct choice");
	}

}
