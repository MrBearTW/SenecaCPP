#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FILENAME "data.txt"
#define MARKFILE "marks.txt"
#define MAX_MARKS 100
#define NAME_SIZE 31
#define BUF_SIZE 127

struct Student
{
    char name[NAME_SIZE + 1];
    double mark;
};

int getStudent(FILE *fp, struct Student *student)
{
    int result = 1;
    int nread = fscanf(fp, "%[^|]|%lf%*c", student->name, &student->mark);
    result = (nread == 2 && !feof(fp));
    return result;
}

void wordCount(FILE *fp, int *nlines, int *nwords, int *nchars)
{
    char ch;
    int inWord = 0;
    *nlines = 0;
    *nwords = 0;
    *nchars = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        (*nchars)++;
        switch (ch)
        {
        case '\n':
            (*nlines)++;
            if (inWord)
                (*nwords)++;
            inWord = 0;
            break;
        case ' ':
        case '\t':
            if (inWord)
                (*nwords)++;
            inWord = 0;
            break;
        default:
            inWord = 1;
        }
    }
}

int main(void)
{
    char buf[BUF_SIZE + 1] = {0};
    struct Student students[MAX_MARKS] = {0};
    int numStudents = 0;
    FILE *fp = NULL;
    fp = fopen(FILENAME, "w");
    if (fp == NULL)
    {
        printf("cannot write to %s\n", FILENAME);
    }
    else
    {
        printf("Type something (empty line to stop): ");
        do
        {
            fgets(buf, BUF_SIZE, stdin);
            // scanf("%[^\n]",buf);    // Not detect the empty line
            if (strlen(buf) > 1) // 1 for '\n'
            {
                fputs(buf, fp);
            }
        } while (strlen(buf) > 1);
        fclose(fp);

        // read file to stdout
        fp = fopen(FILENAME, "r");
        if (fp == NULL)
        {
            printf("cannot open %s\n", FILENAME);
        }
        else
        {
            char ch;
            int nwords, nchars, nlines;
            wordCount(fp, &nlines, &nwords, &nchars);
            printf("Your typed %d chars, %d words and %d lines\n", nchars, nwords, nlines);

            rewind(fp); // reopen
            printf("You typed:\n");
            while ((ch = fgetc(fp)) != EOF)
                fputc(ch, stdout);
            fclose(fp);
        }
    }

    fp = fopen(MARKFILE, "r");
    if (fp == NULL)
    {
        printf("cannot open %s\n", MARKFILE);
    }
    else
    {
        int success = 1, i;
        do
        {
            printf("Success: %d\n", success);
            printf("numStudents: %d\n", numStudents);
            success = getStudent(fp, &students[numStudents]);
            if (success)
            {
                numStudents++;
                printf("inIf numStudents: %d\n", numStudents);
            }
        } while (success);
        fclose(fp);

        for (i = 0; i < numStudents + 1; i++)
        {
            printf("%s - %.2lf\n", students[i].name, students[i].mark);
        }
    }

    return 0;
}