/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: omart
 */


#include"stdio.h"

struct sDate{
	int day;
	int month;
	int year;
};

struct sEmployee{
	char name[50];
	char gender[50];
	struct sDate birthday;
	struct sDate graduation;
	float salary;
};

struct sDate readDate(char dateName[]){
	struct sDate date;
	printf("Enter your %s example(23/3/2023) ",dateName);
	fflush(stdin); fflush(stdout);
	scanf("%d/%d/%d",&date.day,&date.month,&date.year);
	return date;
}

struct sEmployee readEmployee(){
	struct sEmployee employee;
	printf("Name:");
	fflush(stdin); fflush(stdout);
	gets(employee.name);

	printf("gender:");
	fflush(stdin); fflush(stdout);
	gets(employee.gender);

	employee.birthday = readDate("birthday");
	employee.graduation = readDate("graduation");

	printf("salary:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&employee.salary);

	return employee;
}

void writeEmployee(struct sEmployee employee){
	printf("your name is:%s\n",employee.name);
	printf("gender:%s\n",employee.gender);
	printf("birthdate:%d/%d/%d\n",employee.birthday.day,employee.birthday.month,employee.birthday.year);
	printf("graduation year is:%d/%d/%d\n",employee.graduation.day,employee.graduation.month,employee.graduation.year);
	printf("your salary is:%.2f",employee.salary);
}


int main(){

	struct sEmployee emp = readEmployee();
	writeEmployee(emp);
}