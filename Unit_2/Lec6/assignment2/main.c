/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: omart
 */


#include "stdio.h"

	struct sumDistance{
		float dist_feet1;
		float dist_inch1;
		float dist_feet2;
		float dist_inch2;
	};

	void func(struct sumDistance dist){
		float sumFeet,sumInch;
		sumFeet = dist.dist_feet1+dist.dist_feet2;
		sumInch = dist.dist_inch1+dist.dist_inch2;
		printf("summation is:%f.%f",sumFeet,sumInch);
	}

	int main(){
		struct sumDistance distance;

		printf("Enter first distance:\n");

		printf("Enter feet:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance.dist_inch1);

		printf("Enter inch:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance.dist_feet1);

		printf("Enter second distance:\n");

		printf("Enter feet:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance.dist_feet2);

		printf("Enter Inch:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance.dist_inch2);

		func(distance);

	}
