#ifndef FACULTY_H
#define FACULTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

typedef struct Faculty {
    char name[100];
    int ID;
    int Unique_ID;
    char Email[100];
    char Department[100];
    char Phone[15];
    char Gender[10];
    struct Faculty* next; // Pointer to the next faculty in the linked list
} Faculty;

// Function prototypes
Faculty* create_faculty(int id, int unique_id, char *name, char *email, char *department, 
                        char *phone, char *gender);

void insert_faculty(Faculty** head, Faculty* new_faculty);
void read_faculty(Faculty* head, int id);
void update_faculty(Faculty* head, int id, Faculty* updated_faculty);
void delete_faculty(Faculty** head, int id);
void print_faculty(Faculty* faculty);

#endif // FACULTY_H
