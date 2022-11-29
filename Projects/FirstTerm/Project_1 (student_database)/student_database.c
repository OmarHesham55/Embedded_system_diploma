/*
 * student_database.c
 *
 *  Created on: Oct 27, 2022
 *      Author: omart
 */
#include "student_database.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

student_status check_data(student_init* check, Data* student){
	if(check != NULL){
		check->start = student;
		check->end = check->start;
		check->point = check->start;
		check->length = Student_Num;
		check->count = 0;
		return successfully;
	}
	else
		return null;
}

student_status add_student_manually(student_init* check, Data* student){
	Data new_student;

	//CHECHING
	if(!check->start || !check->end)
		return successfully;

	if(check->count >= check->length)
		return full;

	//Student INFO /////////////////
	push_data(&new_student,check,student);

	//push student information
	*(check->end) = new_student;
	  check->count++;

	if(check->end == (check->point + (check->length*sizeof(Data))))
		check->end = check->start;
	else
		check->end++;

	return successfully;
}


void delete_student(student_init* check,Data* students){

	if(check->count == 0)
	{
		printf("\n==========No student found==========\n\n");
	}
	else
	{
		int i, rollID,flag = 0;
		Data* student = check->start;
		Data tempStudent;
		printf("\nThe ID which you want to delete>> ");
		ff
		scanf("%d", &rollID);

		for(i = 0; i < check->count; i++)
		{
			if(student->rollNum == rollID)
			{
				flag = 1;
				break;
			}
			student++;
		}
		if(flag == 0)
		{
			printf("\n\n========== ID Not Found ==========\n\n");
		}
		else
		{
			while((i + 1) != check->count)
			{
				tempStudent = students[i];
				students[i] = students[i + 1];
				students[i + 1] = tempStudent;
				i++;
			}
			printf("\n\n========== ID is Deleted ==========\n\n");
			check->end--;
			check->count--;
		}
	}

}


student_status find_ID(student_init* check,Data* student){
	int id;

	if(check->count!=0){
		printf("\n::Enter the ID to Check: ");
		ff
		scanf("%d",&id);
		for(int i=0; i<check->count;i++){
			if(student->rollNum == id){
				printf("\n\n=============DATA==================\n\n");
				printf("First Name:: %s\n",student->firstName);
				printf("Last Name:: %s\n",student->lastName);
				printf("ID:: %d\n",student->rollNum);
				printf("GPA:: %.2f\n",student->GPA);
				for(int i=0; i<Courses_Num;i++){
					printf("Courses_%d:: %d\n",i+1,student->courses[i]);
					ff
				}
				printf("\n\n=============DATA==================\n\n");
				return successfully;
			}
			student++;
		}
	}else{
		printf("\n\n==========No students to Search==========\n\n");
		return empty;
	}


	return failed;
}



void total_students(student_init* check,Data* students){

	check->point = check->start;

	if(!check->point)
		printf("doesn't exist data\n");

	if(check->count == 0){
		printf("\n::There're not students exist\n\n");
	}
	else{
		for(int i=0; i<check->count;i++){
				printf("\n\n=============DATA==================\n\n");
				printf("First Name:: %s\n",check->point->firstName);
				printf("Last Name:: %s\n",check->point->lastName);
				printf("ID:: %d\n",check->point->rollNum);
				printf("GPA:: %.2f\n",check->point->GPA);
				for(int i=0; i<Courses_Num;i++){
					printf("Courses_%d:: %d\n",i+1,check->point->courses[i]);
					ff
				}
				printf("\n\n=============DATA=============\n\n");
				check->point++;
		}
	}
}

void add_student_file(student_init* check,Data* student){
	Data tempStudent;
	FILE* F_Ptr;

	F_Ptr = fopen("student.txt", "r");
	if(!F_Ptr)
	{
		printf("\n\n=============File Not Found=============");
	}
	else
	{
		while(1)
		{

			fscanf(F_Ptr, "%d", &tempStudent.rollNum);

			if (feof(F_Ptr))
			{
				break;
			}
			else{
				ff
				fscanf(F_Ptr, "%s %s %f", tempStudent.firstName, tempStudent.lastName, &tempStudent.GPA);

				for (int i = 0; i < Courses_Num; ++i){
					fscanf(F_Ptr, "%d", &tempStudent.courses[i]);
					ff
				}

				if(student_queue(check, tempStudent) == successfully)
					printf("\n\n================ Student Saved Successfully ================\n\n");
			}
		}
	}
	fclose(F_Ptr);

}


student_status find_byName(student_init* check,Data* students){
	check->point = students;
	char name[40];


	//check if the queue status
	if(check_queue(check) == successfully ){

		printf("\n\nEnter the First Name:: ");
		ff
		gets(name);

		for(int i=0; i<check->count;i++){
			if(stricmp(name,check->point->firstName) == 0){
				printf("\n\n=============DATA==================\n\n");
				printf("First Name:: %s\n",check->point->firstName);
				printf("Last Name:: %s\n",check->point->lastName);
				printf("ID:: %d\n",check->point->rollNum);
				printf("GPA:: %.2f\n",check->point->GPA);
				for(int j=0; j<Courses_Num;j++){
					printf("Courses_%d:: %d\n",j+1,check->point->courses[j]);
					ff
				}
				printf("\n\n=============DATA==================\n\n");
				return successfully;
			}
				check->point++;
		}

	}else{
		if(check_queue(check) == empty ){
			printf("\n\n========= queue is empty =========\n\n");
		}
	}

	return failed;
}


student_status update_student(student_init* check,Data* student){
	int option;
	int id;
	//	Data* update = student;

	if(check_queue(check) == null){
		return null;
	}

	if(check_queue(check) == empty){
		return empty;
	}
	printf("\n\n::Which Student ID you want to Update>> ");
	ff
	scanf("%d",&id);


	while(student){

		if(student->rollNum == id){
			printf("\n\nWhich information you want to update::\n\n");
			printf("1: The First Name\n");
			printf("2: The Second Name\n");
			printf("3: The GPA Score\n");
			printf("4: The Courses ID\n");
			printf("Enter your option>> ");
			ff
			scanf("%d",&option);
			switch (option){
			case 1:
				printf("\nUpdate The First Name::");
				ff
				gets(student->firstName);
				printf("\n\n================= UPDATE IS DONE =================\n\n");
				break;
			case 2:
				printf("\nUpdate The Last Name::");
				ff
				gets(student->lastName);
				printf("\n\n================= UPDATE IS DONE =================\n\n");
				break;
			case 3:
				printf("\nUpdate The GPA>>");
				ff
				scanf("%f",&student->GPA);
				printf("\n\n================= UPDATE IS DONE =================\n\n");
				break;
			case 4:
				printf("\nUpdate The Courses CRN>>\n");
				for(int i=0;i<Courses_Num;i++){
					printf("Course_%d:: ",i+1);
					ff
					scanf("%d",&student->courses[i]);
				}
				printf("\n\n================= UPDATE IS DONE =================\n\n");
				break;
			default:
				printf("\n\n========= ID is Not Found =========\n\n");
				break;
			}
			break;
		}
		else
			student++;
	}

	return successfully;

}


student_status find_byCourse(student_init* check,Data* student){
	int course,i;
	check->point = student;
	if(check_queue(check) == null){
		return null;
	}

	if(check_queue(check) == empty){
		return empty;
	}

	printf("\n\n::Choose Which Course you want to search >> ");
	ff
	scanf("%d",&course);

	for(int j=0; j<check->count;j++){
		i=0;
		for(int n=0; n<Courses_Num;n++){
			if(check->point->courses[i] == course){
				printf("\n\n=============DATA==================\n\n");
				printf("First Name:: %s\n",check->point->firstName);
				printf("Last Name:: %s\n",check->point->lastName);
				printf("ID:: %d\n",check->point->rollNum);
				printf("GPA:: %.2f\n",check->point->GPA);
				for(int k=0; k<Courses_Num; k++){
					printf("Courses_%d:: %d\n",k+1,check->point->courses[k]);
					ff
				}
				printf("\n\n=============DATA==================\n\n");
			}
		i++;
		}
		check->point++;
	}

	return successfully;
}







void push_data(Data* new_student,student_init* check,Data* students){
	int id,flag=0;
	float gpa;
	check->point = students;
	printf("Enter Student Info::\n\n");
	printf("ID: ");
	ff
	scanf("%d",&id);

	label:
	check->point = students;
	for(int i=0; i<check->count; i++){
		if(check->point->rollNum == id){
			flag = 1;
		}
		check->point++;
	}
	if(flag > 0){
		flag=0;
		printf("\n::Thish ID is already exist choose another RollNumber:: ");
		ff
		scanf("%d",&id);
		goto label;
	}else{
		flag=0;
		new_student->rollNum = id;
	}

	printf("First Name: ");
	ff
	gets(new_student->firstName);

	printf("Last Name: ");
	ff
	gets(new_student->lastName);

	printf("GPA: ");
	ff
	scanf("%f",&gpa);
	new_student->GPA = gpa;

	printf("Your Courses: \n");
	for(int i=0;i<Courses_Num;i++){
		printf("\tCourse_%d:: ",i+1);
		ff
		scanf("%d",&new_student->courses[i]);
	}
	printf("\n\n");

}

student_status check_queue(student_init* check){

	if(!check->start || !check->point || !check->end)
		return null;

	if(check->count == 0)
		return empty;

	return successfully;
}


student_status student_queue (student_init* check, Data item){

	//check if queue is full or not
	if(check->count == Student_Num)
		return full;

	else{

		*(check->end) = item;
		check->count++;
		check->end++;

		return successfully;
	}
}

