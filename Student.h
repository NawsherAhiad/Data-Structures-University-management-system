
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int ID;
    int Unique_ID;
    char Email[100];
    char Department[100];
    char Phone[15];
    char Address[200];
    char Advisor_Name[100];
    float Earned_Credit;
    char Gender[10];
    int year;
    char Date_of_Birth[20];
    struct Student* next;
} Student;

// Function prototypes
Student* create_student(int id, int unique_id, char *name, char *email, char *department, 
                        char *phone, char *address, char *advisor_name, float earned_credit,
                        char *gender, int year, char *date_of_birth);

void insert_student(Student** head, Student* new_student);
void read_student(Student* head, int id);
void update_student(Student* head, int id, Student* updated_student);
void delete_student(Student** head, int id);
void print_student(Student* student);

#endif // STUDENT_H

