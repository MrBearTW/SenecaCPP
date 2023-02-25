#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NAME 30
#define PHONE_LEN 10
#define POST_CODE_DEN 7
#define MAX_MARKS 10
#define MAX_CLASS 10

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
    double marks[MAX_MARKS];
    int numMarks;
};

int main(void)
{
    char name[MAX_NAME + 1] = {0};
    name[0] = 'c';
    name[1] = 'a';
    name[2] = 't';
    name[3] = '\0';
    printf("name=%s\n", name);

    printf("Who are you? ");
    // scanf("%s", name);      // Can not read space " "
    scanf("%[^\n]", name); // Regular expression
    printf("Hello %s\n", name);

    int i, j;

    struct Person p1 = {{"John Smith"},
                        {{"23 Main St."}, {"Toronto"}, {"Ontario"}, {"M3P 2X1"}},
                        {"4163457890"},
                        23};

    printf("(P1) %s is %d years old and has the phone %s and lives at %s, %s, %s, %s\n", p1.name, p1.age, p1.phone, p1.address.street, p1.address.city, p1.address.province, p1.address.postCode);

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

    printf("(S1) %s is %d years old and has the phone %s and lives at %s, %s, %s, %s\n", s1.personInfo.name, s1.personInfo.age, s1.personInfo.phone,
           s1.personInfo.address.street, s1.personInfo.address.city, s1.personInfo.address.province,
           s1.personInfo.address.postCode);
    printf("Marks: ");
    for (i = 0; i < s1.numMarks; i++)
    {
        printf("%.2lf", s1.marks[i]);
    }
    printf("\n");

    struct Student myClass[MAX_CLASS] =
        {
            {{{"Jane Jones"},
              {{"15 Elm St."}, {"Ottawa"}, {"Ont"}, {"M4N 3P7"}},
              {"9056342890"},
              31},
             {45.7, 28.6},
             2},
            {{{"Bill Bones"},
              {{"55 Oak St."}, {"Oshawa"}, {"Ont"}, {"M3N 1P9"}},
              {"903456890"},
              29},
             {48.7, 32.6, 18, 0},
             3}};
    int numStudents = 2;
    printf("-- Class List--\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("(myClass[i]) %s is %d years old and has the phone %s and lives at %s, %s, %s, %s\n", myClass[i].personInfo.name, myClass[i].personInfo.age, myClass[i].personInfo.phone, myClass[i].personInfo.address.street, myClass[i].personInfo.address.city, myClass[i].personInfo.address.province, myClass[i].personInfo.address.postCode);
        printf("Marks: ");
        for (j = 0; j < s1.numMarks; j++)
        {
            printf("%.2lf", s1.marks[j]);
        }
        printf("\n");
    }

    return 0;
}