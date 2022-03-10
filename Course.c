#include "course.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Course* create_course(char *code, char *title, float credit) {
    Course* new_course = (Course*)malloc(sizeof(Course));
    if (new_course == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strncpy(new_course->courseCode, code, sizeof(new_course->courseCode) - 1);
    new_course->courseCode[sizeof(new_course->courseCode) - 1] = '\0';
    strncpy(new_course->courseTitle, title, sizeof(new_course->courseTitle) - 1);
    new_course->courseTitle[sizeof(new_course->courseTitle) - 1] = '\0';
    new_course->courseCredit = credit;
    new_course->next = NULL;

    return new_course;
}

void insert_course(Course **head, Course *new_course) {
    new_course->next = *head;
    *head = new_course;
    printf("Course inserted successfully.\n");
}

void read_course(Course *head, char *code) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseCode, code) == 0) {
            print_course(current);
            return;
        }
        current = current->next;
    }
    printf("Course with code %s not found.\n", code);
}

void update_course(Course *head, char *code, Course *updated_course) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseCode, code) == 0) {
            strncpy(current->courseCode, updated_course->courseCode, sizeof(current->courseCode) - 1);
            current->courseCode[sizeof(current->courseCode) - 1] = '\0';
            strncpy(current->courseTitle, updated_course->courseTitle, sizeof(current->courseTitle) - 1);
            current->courseTitle[sizeof(current->courseTitle) - 1] = '\0';
            current->courseCredit = updated_course->courseCredit;
            printf("Course with code %s updated successfully.\n", code);
            return;
        }
        current = current->next;
    }
    printf("Course with code %s not found.\n", code);
}

void delete_course(Course **head, char *code) {
    Course* current = *head;
    Course* prev = NULL;
    while (current != NULL && strcmp(current->courseCode, code) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Course with code %s not found.\n", code);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Course with code %s deleted successfully.\n", code);
}

void print_course(Course *course) {
    printf("\t\t\tCourse Code: %s\n", course->courseCode);
    printf("\t\t\tCourse Title: %s\n", course->courseTitle);
    printf("\t\t\tCourse Credit: %.2f\n", course->courseCredit);
    printf("\n");
}
