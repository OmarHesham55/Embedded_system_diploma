/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: omart
 */

#include "stdio.h"


// calculate the average students degrees

int main(){
	 int students;
	 float summation = 0;
	 float degree;
	 printf("Enter numbers of students:");
	 fflush(stdin); fflush(stdout);
	 scanf("%d",&students);

	 for(int i=0;i<=students;i++){
		 printf("degree of student(%d) is:",i);
		 fflush(stdin); fflush(stdout);
		 scanf("%f",&degree);
		 summation += degree;
	 }

	 printf("average summation is:%f",summation/students);
}
