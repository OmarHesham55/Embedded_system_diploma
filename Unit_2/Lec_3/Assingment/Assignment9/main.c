/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */


#include "stdio.h"

int main(){

	float a,s,d;
	printf("Enter three numbers");
	fflush(stdin); fflush(stdout);
	scanf("%f\t %f\t %f",&a,&s,&d);
	if(a>s){
		if(a>d){
			printf("\'%f\' is the largest number",a);
		}else{
			printf("\'%f\' is the largest number",d);
		}
	}else{
		if(s>d){
			printf("\'%f\' is the largest number",s);
		}else{
			printf("\'%f\' is the largest number",d);
		}
	}
}
