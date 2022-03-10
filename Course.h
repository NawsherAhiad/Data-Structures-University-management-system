#ifndef COURSE_H
#define COURSE_H

typedef struct Course {
    char courseCode[20];
    char courseTitle[50];
    float courseCredit;
    struct Course *next;
} Course;

Course* create_course(char *code, char *title, float credit);
void insert_course(Course **head, Course *new_course);
void read_course(Course *head, char *code);
void update_course(Course *head, char *code, Course *updated_course);
void delete_course(Course **head, char *code);
void print_course(Course *course);

#endif // COURSE_H
