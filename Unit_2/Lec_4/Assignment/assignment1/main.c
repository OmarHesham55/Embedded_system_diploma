/*
 * main.c
 *
 *  Created on: Jul 12, 2022
 *      Author: omart
 */


#include"stdio.h"

 int main(){

	 float matrix1[2][2];
	 float matrix2[2][2];
	 float sumMatrix[2][2];
	 int i,j;


	 printf("Enter the values of the matrix1\n");
	 for(i=0; i<2; i++){
		 for(j=0; j<2; j++){
			printf("M%d%d: ", i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&matrix1[i][j]);
		 }
	 }


	 // matrix2 inputs
	 printf("\nEnter the values of the matrix2\n");
	 for(i=0; i<2; i++){
		 for(j=0; j<2; j++){
			printf("M%d%d: ", i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&matrix2[i][j]);
		 }
	 }


	 //for summation of matrices
	 for(i=0; i<2; i++){
		 for(j=0; j<2; j++){
			 sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		 }
	 }


	 //to print the summation matrix
	 	 for(i=0; i<2; i++){
	 		 for(j=0; j<2; j++){
	 			printf("%f  ",sumMatrix[i][j]);
	 			if(j == 2-1){
	 				printf("\n");
	 			}
	 		 }
	 	 }
 }
