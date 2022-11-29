/*
 * student_database.h
 *
 *  Created on: Oct 27, 2022
 *      Author: omart
 */

#ifndef STUDENT_DATABASE_H_
#define STUDENT_DATABASE_H_
#define ff  fflush(stdin);\
			fflush(stdout);
#define Student_Num  5
#define Courses_Num  3
#include <stdio.h>

struct student_info{
	char firstName[40];
	char lastName [40];
	int  rollNum;
	float GPA;
	int courses[Courses_Num];
};

typedef struct student_info Data;

typedef struct{
	unsigned int length;
	Data* start;
	Data* end;
	Data* point;
	unsigned int count;
}student_init;


typedef enum{
	successfully,
	failed,
	empty,
	full,
	null
}student_status;

extern Data student[Student_Num];

void push_data(Data* new_student,student_init* check,Data* students);
student_status check_data(student_init* check, Data* student);
student_status check_queue(student_init* check);

//  ================= ::Define APIS::  //

student_status add_student_manually(student_init* check,Data* student);
student_status find_ID(student_init* check,Data* student);
student_status find_byName(student_init* check,Data* students);
student_status find_byCourse(student_init* check,Data* students);
void total_students(student_init* check,Data* students);
void delete_student(student_init* check,Data* students);
void add_student_file(student_init* check,Data* student);
student_status update_student(student_init* check,Data* student);
student_status student_queue (student_init* check, Data item);

#endif /* STUDENT_DATABASE_H_ */
