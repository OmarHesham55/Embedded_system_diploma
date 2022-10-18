/*
 * main.c
 *
 *  Created on: Sep 20, 2022
 *      Author: omart
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdint.h>

#define DPRINTF(...)     {fflush(stdout); \
						  fflush(stdin);\
						  printf(__VA_ARGS__);\
						  fflush(stdout);\
						  fflush(stdin);}
//effective data
struct Sdata{
	unsigned int id;
	char  name[40];
	float   height;
};

struct SStudent{
	struct Sdata student;
	struct SStudent* nextStudent;
};

struct SStudent* gpFirstStudent = NULL;

void addStudent(){
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;
	char temp_text[40];
	//check if the buffer empty or not
	if(gpFirstStudent == NULL){
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		gpFirstStudent = pNewStudent;
	}else{
		pLastStudent = gpFirstStudent;
		while(pLastStudent->nextStudent)
			pLastStudent = pLastStudent->nextStudent;
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		pLastStudent->nextStudent = pNewStudent;
	}
	//fill new record
	DPRINTF("\n Enter the ID: ");
	gets(temp_text);
	pNewStudent->student.id = atoi(temp_text);

	DPRINTF("\n Enter the Name: ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter the Height: ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);

	// set the next pointer (new_student) to the null
	pNewStudent->nextStudent = NULL;
}

int deleteStudent(){
	char temp_text[40];
	uint32_t selected_id;
	DPRINTF("Select the ID: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//check the list
	if(gpFirstStudent){
		struct SStudent* pSelectedStudent = gpFirstStudent;
		struct SStudent* pPrevStudent = NULL;

		while(pSelectedStudent){
			if(pSelectedStudent->student.id == selected_id){ //compare the two ids

				if(pPrevStudent){ // check if there is prev student?

					pPrevStudent->nextStudent = pSelectedStudent->nextStudent;

				}else{// if not then assign the firstStudent to the next of selected student
					gpFirstStudent = pSelectedStudent->nextStudent;
				}
			free(pSelectedStudent);
			return 1;
			}

			pPrevStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->nextStudent;
		}
	}
	DPRINTF("\n can't find the id");
	return 0;
}


void view_students(){
	struct SStudent* currentStudent = gpFirstStudent;
	int count=1;
	if(currentStudent == NULL){
		DPRINTF("\n Empty List");
	}
	else{
		while(currentStudent){
			DPRINTF("\n Record Number %d\n",count);
			DPRINTF("\t ID: %d",currentStudent->student.id);
			DPRINTF("\t Name: %s",currentStudent->student.name);
			DPRINTF("\t Name: %.1f",currentStudent->student.height);
			currentStudent = currentStudent->nextStudent;
			count++;
		}
	}

}




void deleteAll(){
	struct SStudent* currentStudent = gpFirstStudent;
	if(currentStudent == NULL){
		DPRINTF("\n Empty List");
	}
	else{
		while(currentStudent){
			struct SStudent* temp = currentStudent;
			currentStudent = currentStudent->nextStudent;
			free(temp);
		}
		gpFirstStudent = NULL;
	}
}


void main(){

	char temp_text[40];

	while(1){
		DPRINTF("\n=======================");
		DPRINTF("\n\t Choose one of the following options\n");
		DPRINTF("\n 1: Add student");
		DPRINTF("\n 2: Delete student");
		DPRINTF("\n 3: View All Students");
		DPRINTF("\n 4: Delete All Students");
		DPRINTF("\n Enter option Number: ");
		gets(temp_text);
		DPRINTF("\n=======================");

		switch (atoi(temp_text))
		{
		case 1:
			addStudent();
			break;

		case 2:
			deleteStudent();
			break;

		case 3:
			view_students();
			break ;
		case 4:
			deleteAll();
			break ;

		default:
			DPRINTF("\nwrong option ");
			break;
		}
	}





}





