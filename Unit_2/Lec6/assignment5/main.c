/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: omart
 */


#include "stdio.h"
#include "string.h"

struct sStudents{
	int id;
	char name[50];
	float marks;
};

int main(){
	struct sStudents student[100];
	int i=0,j;
	char ans;

	printf("Add a student");

	do{
		printf("Your ID:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&student[i].id);

		printf("Your Name:");
		fflush(stdin); fflush(stdout);
		gets(student[i].name);

		printf("Your Mark:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&student[i].marks);
		i++;

		printf("Add another student?(y/n)");
		fflush(stdin); fflush(stdout);
		scanf("%c",&ans);
	}while(ans=='y');

	for(j=0;j<i;j++){
		printf("[%d]\tID:%d\n\tname:%s\n\tmark:%.1f\n",
				j+1,student[j].id,student[j].name,student[j].marks);
	}


}
