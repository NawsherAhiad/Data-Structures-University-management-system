#include "Student.h"

Student* create_student(int id, int unique_id, char *name, char *email, char *department,
                        char *phone, char *address, char *advisor_name, float earned_credit,
                        char *gender, int year, char *date_of_birth) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_student->ID = id;
    new_student->Unique_ID = unique_id;
    strcpy(new_student->name, name);
    strcpy(new_student->Email, email);
    strcpy(new_student->Department, department);
    strcpy(new_student->Phone, phone);
    strcpy(new_student->Address, address);
    strcpy(new_student->Advisor_Name, advisor_name);
    new_student->Earned_Credit = earned_credit;
    strcpy(new_student->Gender, gender);
    new_student->year = year;
    strcpy(new_student->Date_of_Birth, date_of_birth);
    new_student->next = NULL;

    return new_student;
}

void insert_student(Student** head, Student* new_student) {
    new_student->next = *head;
    *head = new_student;
    printf("Student inserted successfully.\n");
}

void read_student(Student* head, int id) // for search based on ID
{

    Student* current = head;
    while (current != NULL) {
        if (current->ID == id) {
            print_student(current);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void update_student(Student* head, int id, Student* updated_student) {
    Student* current = head;
    while (current != NULL) {
        if (current->ID == id) {
            strcpy(current->name, updated_student->name);
            current->Unique_ID = updated_student->Unique_ID;
            strcpy(current->Email, updated_student->Email);
            strcpy(current->Department, updated_student->Department);
            strcpy(current->Phone, updated_student->Phone);
            strcpy(current->Address, updated_student->Address);
            strcpy(current->Advisor_Name, updated_student->Advisor_Name);
            current->Earned_Credit = updated_student->Earned_Credit;
            strcpy(current->Gender, updated_student->Gender);
            current->year = updated_student->year;
            strcpy(current->Date_of_Birth, updated_student->Date_of_Birth);
            printf("Student with ID %d updated successfully.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void delete_student(Student** head, int id) {
    Student* current = *head;
    Student* prev = NULL;
    while (current != NULL && current->ID != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Student with ID %d deleted successfully.\n", id);
}

void print_student(Student* student) {
    printf("\t\t\tStudent ID: %d\n", student->ID);
    printf("\t\t\tStudent Name: %s\n", student->name);
    printf("\t\t\tStudent Email: %s\n", student->Email);
    printf("\t\t\tStudent Department: %s\n", student->Department);
    printf("\t\t\tStudent Phone: %s\n", student->Phone);
    printf("\t\t\tStudent Address: %s\n", student->Address);
    printf("\t\t\tStudent Advisor Name: %s\n", student->Advisor_Name);
    printf("\t\t\tStudent Earned Credit: %.2f\n", student->Earned_Credit);
    printf("\t\t\tStudent Gender: %s\n", student->Gender);
    printf("\t\t\tStudent Year: %d\n", student->year);
    printf("\t\t\tStudent Date of Birth: %s\n", student->Date_of_Birth);
    printf("\n");
}
