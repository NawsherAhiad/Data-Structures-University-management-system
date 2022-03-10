#include "Faculty.h"

Faculty* create_faculty(int id, int unique_id, char *name, char *email, char *department,
                        char *phone, char *gender) {
    Faculty* new_faculty = (Faculty*)malloc(sizeof(Faculty));
    if (new_faculty == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_faculty->ID = id;
    new_faculty->Unique_ID = unique_id;
    strcpy(new_faculty->name, name);
    strcpy(new_faculty->Email, email);
    strcpy(new_faculty->Department, department);
    strcpy(new_faculty->Phone, phone);
    strcpy(new_faculty->Gender, gender);
    new_faculty->next = NULL;

    return new_faculty;
}

void insert_faculty(Faculty** head, Faculty* new_faculty) {
    new_faculty->next = *head;
    *head = new_faculty;
    printf("Faculty inserted successfully.\n");
}

void read_faculty(Faculty* head, int id) {
    Faculty* current = head;
    while (current != NULL) {
        if (current->ID == id) {
            print_faculty(current);
            return;
        }
        current = current->next;
    }
    printf("Faculty with ID %d not found.\n", id);
}

void update_faculty(Faculty* head, int id, Faculty* updated_faculty) {
    Faculty* current = head;
    while (current != NULL) {
        if (current->ID == id) {
            strcpy(current->name, updated_faculty->name);
            current->Unique_ID = updated_faculty->Unique_ID;
            strcpy(current->Email, updated_faculty->Email);
            strcpy(current->Department, updated_faculty->Department);
            strcpy(current->Phone, updated_faculty->Phone);
            strcpy(current->Gender, updated_faculty->Gender);
            printf("Faculty with ID %d updated successfully.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Faculty with ID %d not found.\n", id);
}

void delete_faculty(Faculty** head, int id) {
    Faculty* current = *head;
    Faculty* prev = NULL;
    while (current != NULL && current->ID != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Faculty with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Faculty with ID %d deleted successfully.\n", id);
}

void print_faculty(Faculty* faculty) {
    printf("\t\t\tFaculty ID: %d\n", faculty->ID);
    printf("\t\t\tFaculty Name: %s\n", faculty->name);
    printf("\t\t\tFaculty Email: %s\n", faculty->Email);
    printf("\t\t\tFaculty Department: %s\n", faculty->Department);
    printf("\t\t\tFaculty Phone: %s\n", faculty->Phone);
    printf("\t\t\tFaculty Gender: %s\n", faculty->Gender);
    printf("\n");
}
