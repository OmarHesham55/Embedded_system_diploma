/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: omart
 */


#include "stdio.h"

struct studentInfo{
	char name[50];
	int roll;
	float mark;
};

int main(){
	struct studentInfo student;

	printf("Enter your data\n");
	printf("Your Name:");
	fflush(stdin); fflush(stdout);
	gets(student.name);
	printf("Enter roll number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student.roll);
	printf("Enter your mark:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&student.mark);

	printf("\ndisplaying info.\n");
	printf("Your name is: %s\n",student.name);
	printf("your roll num is: %d\n",student.roll);
	printf("your mark is: %f",student.mark);

}
