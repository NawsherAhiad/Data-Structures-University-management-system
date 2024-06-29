#include <stdio.h>
#include "User.h"
#include "Student.h"
#include "Student.c"
#include "Faculty.h"
#include "Faculty.c"
#include "Department.h"
#include "Department.c"
#include "Course.h"
#include "Course.c"
#include "EnrolledCourses.h"
#include "FinancialAid.h"
#include "Section.h"
#include "HealthStatus.h"
#include "EarnedCredit.h"
#include "Notice.h"
#include "FacultyEvaluation.h"
#include "Alumni.h"
#include "Convocation.h"
#include "AdvisingRules.h"



void Std(Student* head)
{
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




    int opt;

    do
    {
        printf("1. Add a student details\n");
        printf("2. Delete a student details\n");
        printf("3. Search a student using ID \n");
        printf("4. View all students\n");
        printf("5. Update a student info\n");
        printf("10.exit Student gateway\n\n\n");

        printf("Enter you choice: ");
        scanf("%d", &opt);

        if(opt ==1)
        {


            // Take input from the keyboard using gets for strings and scanf for other types
            getchar();
            printf("\t\t\tEnter name: ");
            gets(name);

            printf("\t\t\tEnter ID: ");
            scanf("%d", &ID);

            printf("\t\t\tEnter Unique ID: ");
            scanf("%d", &Unique_ID);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Email: ");
            gets(Email);

            printf("\t\t\tEnter Department: ");
            gets(Department);

            printf("\t\t\tEnter Phone: ");
            gets(Phone);

            printf("\t\t\tEnter Address: ");
            gets(Address);

            printf("\t\t\tEnter Advisor Name: ");
            gets(Advisor_Name);

            printf("\t\t\tEnter Earned Credit: ");
            scanf("%f", &Earned_Credit);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Gender: ");
            gets(Gender);

            printf("\t\t\tEnter Year: ");
            scanf("%d", &year);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Date of Birth (DD/MM/YYYY): ");
            gets(Date_of_Birth);







            Student* student1 = create_student(ID, Unique_ID, name, Email, Department,
                                               Phone, Address, Advisor_Name, Earned_Credit,
                                               Gender, year, Date_of_Birth);
            insert_student(&head, student1);
            printf("\n\n\n");





        }
        else if (opt == 2)
        {
            getchar();
            printf("\t\t\tEnter the ID to delete a student details: ");

            scanf("%d", &ID);
            delete_student(&head, ID);

        }
        else if (opt == 3)
        {
            getchar();
            printf("\t\t\tEnter the ID to search a student details: ");
            scanf("%d", &ID);
            read_student(head, ID);
        }

        else if (opt == 4)
        {
            printf("\t\t\tAll students:\n");
            Student* current = head;
            while (current != NULL)
            {
                print_student(current);
                current = current->next;
            }


        }
        else if (opt == 5)
        {
            printf("\t\t\tEnter all details to update\n");

            printf("\t\t\tEnter ID to update any students info\n");
            getchar();
            scanf("%d", &ID);
            read_student(head, ID);


            getchar();
            printf("\t\t\tEnter name: ");
            gets(name);


            printf("\t\t\tEnter Unique ID: ");
            scanf("%d", &Unique_ID);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Email: ");
            gets(Email);

            printf("\t\t\tEnter Department: ");
            gets(Department);

            printf("\t\t\tEnter Phone: ");
            gets(Phone);

            printf("\t\t\tEnter Address: ");
            gets(Address);

            printf("\t\t\tEnter Advisor Name: ");
            gets(Advisor_Name);

            printf("\t\t\tEnter Earned Credit: ");
            scanf("%f", &Earned_Credit);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Gender: ");
            gets(Gender);

            printf("\t\t\tEnter Year: ");
            scanf("%d", &year);
            getchar(); // consume the newline character left by scanf

            printf("\t\t\tEnter Date of Birth (DD/MM/YYYY): ");
            gets(Date_of_Birth);





            Student* updated_student1 = create_student(ID, Unique_ID, name, Email, Department,
                                        Phone, Address, Advisor_Name, Earned_Credit,
                                        Gender, year, Date_of_Birth);

            update_student(head, ID, updated_student1);
            printf("\t\t\tAfter updating........\n");
            read_student(head, ID);

        }



    }
    while(opt !=10);

}

void Fac(Faculty* head)
{
    char name[100];
    int ID;
    int Unique_ID;
    char Email[100];
    char Department[100];
    char Phone[15];
    char Gender[10];

    int opt;
    do
    {
        printf("1. Add a faculty details\n");
        printf("2. Delete a faculty details\n");
        printf("3. Search a faculty using ID \n");
        printf("4. View all faculty\n");
        printf("5. Update a faculty info\n");
        printf("10.exit faculty gateway\n\n\n");

        printf("Enter you choice: ");
        scanf("%d", &opt);

        if(opt==1)
        {
            getchar();
            printf("\t\t\tEnter name: ");
            gets(name);

            printf("\t\t\tEnter ID: ");
            scanf("%d", &ID);

            printf("\t\t\tEnter Unique_ID: ");
            scanf("%d", &Unique_ID);

            // To consume the leftover newline character from previous scanf
            getchar();

            printf("\t\t\tEnter Email: ");
            gets(Email);

            printf("\t\t\tEnter Department: ");
            gets(Department);

            printf("\t\t\tEnter Phone: ");
            gets(Phone);

            printf("\t\t\tEnter Gender: ");
            gets(Gender);

            Faculty* faculty1 = create_faculty(ID, Unique_ID, name, Email, Department,
                                               Phone, Gender);
            insert_faculty(&head, faculty1);


        }
        else if(opt==2)
        {
            getchar();
            printf("\t\t\tEnter the ID to delete a faculty details: ");

            scanf("%d", &ID);
            delete_faculty(&head, ID);

        }
        else if(opt==3)
        {
            getchar();
            printf("\t\t\tEnter the ID to search a faculty details: ");

            scanf("%d", &ID);
            read_faculty(head, ID);

        }
        else if(opt==4)
        {
            printf("\t\t\tAll faculty members:\n");
            Faculty* current = head;
            while (current != NULL)
            {
                print_faculty(current);
                current = current->next;
            }

        }
        else if(opt==5)
        {
            printf("\t\t\tEnter all details to update\n");

            printf("\t\t\tEnter ID to update any faculty info\n");
            getchar();
            scanf("%d", &ID);
            read_faculty(head, ID);


            getchar();
            printf("\t\t\tEnter name: ");
            gets(name);


            printf("\t\t\tEnter Unique_ID: ");
            scanf("%d", &Unique_ID);

            // To consume the leftover newline character from previous scanf
            getchar();

            printf("\t\t\tEnter Email: ");
            gets(Email);

            printf("\t\t\tEnter Department: ");
            gets(Department);

            printf("\t\t\tEnter Phone: ");
            gets(Phone);

            printf("\t\t\tEnter Gender: ");
            gets(Gender);

            Faculty* updated_faculty1 = create_faculty(ID, Unique_ID, name, Email, Department,
                                        Phone, Gender);
            update_faculty(head, ID, updated_faculty1);
            printf("\t\t\tAfter updating........\n");
            read_faculty(head, ID);



        }




    }
    while(opt!=10);

}


void Dept( Department* head)
{
    char Dept_name[100];
    char Dept_chairman[100];
    char Total_faculty_list[100];
    int Num_of_faculties;
    char Major_courses[200];
    char Minor_courses[200];



    int opt;
    do
    {

        printf("\t\t\t1. Add a Department details\n");
        printf("\t\t\t2. Delete a Department details\n");
        printf("\t\t\t3. Search a faculty using ID \n");
        printf("\t\t\t4. View all Department\n");
        printf("\t\t\t5. Update a Department info\n");
        printf("\t\t\t10.exit Department gateway\n\n\n");

        printf("Enter you choice: ");
        scanf("%d", &opt);


        if(opt==1)
        {
            getchar();
            printf("\t\t\tEnter the department name: ");
            gets(Dept_name);


            printf("\t\t\tEnter the department chairman: ");
            gets(Dept_chairman);


            printf("\t\t\tEnter the total faculty list (comma-separated): ");
            gets(Total_faculty_list);


            printf("\t\t\tEnter the number of faculties: ");
            scanf("%d", &Num_of_faculties);


            while (getchar() != '\n');

            printf("\t\t\tEnter the major courses (comma-separated): ");
            gets(Major_courses);


            printf("\t\t\tEnter the minor courses (comma-separated): ");
            gets(Minor_courses);



            Department* dept1 = create_department(Dept_name, Dept_chairman, Total_faculty_list,
                                                  Num_of_faculties, Major_courses, Minor_courses);
            insert_department(&head, dept1);

        }
        else if (opt==2)
        {

            printf("\t\t\tEnter dept name to delete: ");
            getchar();
            gets(Dept_name);
            delete_department(&head, Dept_name);


        }
        else if  (opt == 3)
        {
            printf("\t\t\tEnter dept name to search: ");
            getchar();
            gets(Dept_name);
            read_department(head, Dept_name);



        }
        else if (opt == 4)
        {
            printf("\t\t\tAll departments:\n");
            Department* current = head;
            while (current != NULL)
            {
                print_department(current);
                current = current->next;
            }


        }
        else if(opt == 5)
        {
            printf("\t\t\tEnter dept name to update: ");
            getchar();
            gets(Dept_name);

            read_department(head, Dept_name);



            printf("\t\t\tPlease modify accordingly\n");

            printf("\t\t\tEnter the department chairman: ");
            gets(Dept_chairman);


            printf("\t\t\tEnter the total faculty list (comma-separated): ");
            gets(Total_faculty_list);


            printf("\t\t\tEnter the number of faculties: ");
            scanf("%d", &Num_of_faculties);


            while (getchar() != '\n');

            printf("\t\t\tEnter the major courses (comma-separated): ");
            gets(Major_courses);


            printf("\t\t\tEnter the minor courses (comma-separated): ");
            gets(Minor_courses);



             Department* updated_dept1 = create_department(Dept_name, Dept_chairman, Total_faculty_list,
                                                  Num_of_faculties, Major_courses, Minor_courses);
             update_department(head, Dept_name, updated_dept1);




        }
    }
    while(opt!=10);





}
void Crs(Course *courseList)
{
    char courseCode[20];
    char courseTitle[50];
    float courseCredit;

    int opt;
    do
    {
        printf("1. Add a course details\n");
        printf("2. Delete a course details\n");
        printf("3. Search a course using ID \n");
        printf("4. View all courses\n");
        printf("5. Update a course info\n");
        printf("10.exit courses gateway\n\n\n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        if(opt==1)
        {
            getchar();
            printf("\t\t\tEnter the course code: ");
            gets(courseCode);

            // Read courseTitle using gets
            printf("\t\t\tEnter the course title: ");
            gets(courseTitle);

            // Read courseCredit using scanf
            printf("\t\t\tEnter the course credit: ");
            scanf("%f", &courseCredit);



            Course *course1 = create_course(courseCode, courseTitle, courseCredit);
            insert_course(&courseList, course1);


        }
        else if (opt == 2)
        {
            getchar();
            printf("\t\t\tEnter course code to delete a course details: ");
            scanf("%s", courseCode);
            delete_course(&courseList, courseCode);

        }
        else if (opt == 3)
        {
            getchar();
            printf("\t\t\tEnter course code to search a course details: ");
            scanf("%s", courseCode);
            read_course(courseList, courseCode);


        }
        else if (opt ==4)
        {
            printf("\t\t\tAll courses\n");
            Course* current = courseList;
            while (current != NULL)
            {
                print_course(current);
                current = current->next;
            }
        }
        else if (opt ==5)
        {
            Course updatedCourse;
            printf("\t\t\tEnter all details to update.\n");
            printf("\t\t\tEnter course code to update any course info: ");
            getchar();
            scanf("%s", courseCode);
            read_course(courseList, courseCode);

            getchar();
            printf("\t\t\tEnter the course title: ");
            gets(courseTitle);


            printf("\t\t\tEnter the course credit: ");
            scanf("%f", &courseCredit);

            strcpy(updatedCourse.courseCode, courseCode);
            strcpy(updatedCourse.courseTitle, courseTitle);
            updatedCourse.courseCredit = courseCredit;
            update_course(courseList, courseCode, &updatedCourse);


        }

    }
    while(opt!=10);

}
int main()
{
    // Example usage
    /*Student student1;
    student1.ID = 1;
    sprintf(student1.name, "kawser chowdhury");
    // Continue to initialize other fields and other structures as needed

    printf("Student ID: %d\n", student1.ID);
    printf("Student Name: %s\n", student1.name);

    return 0;
    */

    // Initialize the head of the list
    // Initialize the head of the list
    Student* St_head = NULL;
    Faculty* fac_head = NULL;
    Course *courseList = NULL;
    Department* dept_head = NULL;



    int opt;
    do
    {
        printf("1.Student information\n");
        printf("2.Faculty information\n");
        printf("3.Department information\n");
        printf("4.Course information\n");
        printf("5.Alumni information\n");
        printf("10.exit\n\n\n ");

        printf("Enter choice: ");
        scanf("%d", &opt);

        if(opt ==1)
        {

            Std(St_head);
        }
        else if (opt == 2)
        {
            Fac(fac_head);
        }
        else if (opt == 3)
        {
            Dept(dept_head);
        }
        else  if (opt == 4)
        {
            Crs(courseList);
        }
        else if (opt == 10)
        {
            printf("Thanks sir for guiding us to complete this project");
        }

    }
    while(opt!=10);

}
