#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Department {
    char Dept_name[100];
    char Dept_chairman[100];
    char Total_faculty_list[100]; // Assuming a comma-separated string of faculty names or IDs
    int Num_of_faculties;
    char Major_courses[200]; // Assuming a comma-separated string of major courses
    char Minor_courses[200]; // Assuming a comma-separated string of minor courses
    struct Department* next; // Pointer to the next department in the linked list
} Department;

// Function prototypes
Department* create_department(char *dept_name, char *dept_chairman, char *total_faculty_list, 
                              int num_of_faculties, char *major_courses, char *minor_courses);

void insert_department(Department** head, Department* new_department);
void read_department(Department* head, char *dept_name);
void update_department(Department* head, char *dept_name, Department* updated_department);
void delete_department(Department** head, char *dept_name);
void print_department(Department* department);

#endif // DEPARTMENT_H
