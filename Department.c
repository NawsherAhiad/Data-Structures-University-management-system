#include "Department.h"

Department* create_department(char *dept_name, char *dept_chairman, char *total_faculty_list,
                              int num_of_faculties, char *major_courses, char *minor_courses) {
    Department* new_department = (Department*)malloc(sizeof(Department));
    if (new_department == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_department->Dept_name, dept_name);
    strcpy(new_department->Dept_chairman, dept_chairman);
    strcpy(new_department->Total_faculty_list, total_faculty_list);
    new_department->Num_of_faculties = num_of_faculties;
    strcpy(new_department->Major_courses, major_courses);
    strcpy(new_department->Minor_courses, minor_courses);
    new_department->next = NULL;

    return new_department;
}

void insert_department(Department** head, Department* new_department) {
    new_department->next = *head;
    *head = new_department;
    printf("Department inserted successfully.\n");
}

void read_department(Department* head, char *dept_name) {
    Department* current = head;
    while (current != NULL) {
        if (strcmp(current->Dept_name, dept_name) == 0) {
            print_department(current);
            return;
        }
        current = current->next;
    }
    printf("Department with name %s not found.\n", dept_name);
}

void update_department(Department* head, char *dept_name, Department* updated_department) {
    Department* current = head;
    while (current != NULL) {
        if (strcmp(current->Dept_name, dept_name) == 0) {
            strcpy(current->Dept_name, updated_department->Dept_name);
            strcpy(current->Dept_chairman, updated_department->Dept_chairman);
            strcpy(current->Total_faculty_list, updated_department->Total_faculty_list);
            current->Num_of_faculties = updated_department->Num_of_faculties;
            strcpy(current->Major_courses, updated_department->Major_courses);
            strcpy(current->Minor_courses, updated_department->Minor_courses);
            printf("Department with name %s updated successfully.\n", dept_name);
            return;
        }
        current = current->next;
    }
    printf("Department with name %s not found.\n", dept_name);
}

void delete_department(Department** head, char *dept_name) {
    Department* current = *head;
    Department* prev = NULL;
    while (current != NULL && strcmp(current->Dept_name, dept_name) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Department with name %s not found.\n", dept_name);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Department with name %s deleted successfully.\n", dept_name);
}

void print_department(Department* department) {
    printf("\t\t\tDepartment Name: %s\n", department->Dept_name);
    printf("\t\t\tDepartment Chairman: %s\n", department->Dept_chairman);
    printf("\t\t\tTotal Faculty List: %s\n", department->Total_faculty_list);
    printf("\t\t\tNumber of Faculties: %d\n", department->Num_of_faculties);
    printf("\t\t\tMajor Courses: %s\n", department->Major_courses);
    printf("\t\t\tMinor Courses: %s\n", department->Minor_courses);
    printf("\n");
}
