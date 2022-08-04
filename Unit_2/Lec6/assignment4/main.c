/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: omart
 */

#include "stdio.h"
struct sComplex{
	double real;
	double imginary;
};

struct sComplex complexNum(char number[50]){

	struct sComplex num;
	printf("Enter the %s number example (r,iJ)",number);
	fflush(stdin); fflush(stdout);
	scanf("(%lf,%lf)",&num.real,&num.imginary);

	return num;
}

struct sComplex numSum(struct sComplex a,struct sComplex b){

	struct sComplex num;
	num.real = a.real + b.real;
	num.imginary = a.imginary + b.imginary;

	return num;

}

void printSum(struct sComplex z){

	printf("sum is equal to: %.1lf + j%.1lf",z.real,z.imginary);
}

int main(){

struct sComplex x,y,z;

x = complexNum("first");
y = complexNum("second");
z = numSum(x,y);
printSum(z);


}
