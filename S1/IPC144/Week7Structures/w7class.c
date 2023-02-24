#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NAME 30
#define PHONE_LEN 10
#define POST_CODE_DEN 7
#define MAX_MARKS 10

struct Address
{
    char street[MAX_NAME + 1];
    char city[MAX_NAME + 1];
    char province[MAX_NAME + 1];
    char postCode[POST_CODE_DEN + 1];
};

struct Person
{
    char name[MAX_NAME + 1];
    struct Address address;
    char phone[PHONE_LEN + 1];
    int age;
};

struct Student
{
    struct Person personInfo;
    double 
};

int main(void)
{
    int i, j;

    struct Student s1 = {
        {{"Jane Jones"},
         {{"15 Elm St."},
          {"Ottawa"},
          {"Ont"},
          {"M4N 3P7"}},
         {"9056342890"},
         31},
        {45.7, 28.6},
        23};

    printf("(S1) %s is &d years old and ha the phone %s and lives at %s %s %s");
    printf("Marks: ");
    for (i = 0; i < s1.numMarks; i++)
    {
        printf("%.2lf", s1.marks[i]);
    }
    printf("\n");

    struct Student myClass[MAX_CLASS] =
        {

        };
    int numStudents = 2;
    printf("-- Class List--\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("(myClass[i]) %s is %d years old and has the phone %s and live at %s");
        printf("Marks: ");
        for (j = 0; j < s1.numMarks; j++)
        {
            printf("%.2lf", s1.marks[j]);
        }
        printf("\n");
    }

    return 0;
}