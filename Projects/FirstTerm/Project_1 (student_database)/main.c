/*
 * main.c
 *
 *  Created on: Oct 27, 2022
 *      Author: omart
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"student_database.h"

Data student[Student_Num];

int main(){
	student_init QUEUE;
	int num;

	if(check_data(&QUEUE,student) == successfully){

		while(1){
			printf("Choose an option::\n");
			printf("Option 1:: add student manually\n");
			printf("Option 2:: find student by roll number\n");
			printf("Option 3:: add student manually by file\n");
			printf("Option 4:: All of students\n");
			printf("Option 5:: find student by its First Name\n");
			printf("Option 6:: Update Student\n");
			printf("Option 7:: find by Course Number\n");
			printf("Option 8:: Delete Student\n");
			printf("Option 9:: Exit\n");
			printf("Option::");
			ff
			scanf("%d",&num);
			switch (num) {

			case 1:
				if(add_student_manually(&QUEUE,student) != successfully)
					printf("\n==========queue is full==========\n\n");
				break;

			case 2:
				if(find_ID(&QUEUE,student)==failed)
					printf("\n==========No students to Search==========\n\n");
				break;

			case 3:
				add_student_file(&QUEUE,student);
				break;

			case 4:
				total_students(&QUEUE,student);
				break;

			case 5:
				if(find_byName(&QUEUE,student)!=successfully)
					printf("\n==========No student found==========\n\n");
				break;

			case 6:
				if(update_student(&QUEUE,student) != successfully){
					if(update_student(&QUEUE,student)==null)
						printf("\n\n========== No queue exists ==========\n\n");
					if(update_student(&QUEUE,student)==empty)
						printf("\n\n========== queue is empty ==========\n\n");
				}
				break;

			case 7:
				if(find_byCourse(&QUEUE,student)!=successfully){
					if(find_byCourse(&QUEUE,student)== empty)
						printf("\n\n========== queue is empty ==========\n\n");
					else
						printf("\n\n========== Course Not Found ==========\n\n");
				}else
					printf("\n\n========== Done ==========\n\n");
				break;

			case 8:
				delete_student(&QUEUE,student);
				break;

			case 9:
				exit(1);
				break;

			default:
				printf("\n==========Please Choose a right option::==========\n\n");
				break;
			}
		}
	}
}
