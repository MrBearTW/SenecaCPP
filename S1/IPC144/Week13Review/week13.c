#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LEN 50
int readFile(FILE *fp, char lines[][MAX_LINE_LEN + 1], int maxLines)
{
    int line = 0;
    while (line < maxLines && !feof(fp) && fgets(lines[line], MAX_LINE_LEN, fp))
    {
        printf("I just read line %d\n", line);
        line++;
    }
    return line;
}

int readFileAsMess(FILE *fp, char buf[])
{
    int nchars = 0;
    int ch;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (!feof(fp))
            buf[nchars++] = ch;
    }
    return nchars;
}

int readMeALine(FILE *fp, char buf[])
{
    int success = !feof(fp);
    int bufPt = 0, ch;
    if (success)
    {
        while ((ch = fgetc(fp)) != EOF && ch != '\n')
        {
            buf[bufPt++] = ch;
        }
        buf[bufPt] = '\0';
        success = !feof(fp);
    }
    return success;
}

int readNumbers(FILE *fp, int ar[])
{
    int num = 0, nread = 0, keepGoing = 1;
    if (!feof(fp))
    {
        keepGoing = !feof(fp);
        if (keepGoing)
        {
            printf("not EOF Yet\n");
        }
        else
        {
            printf("At EOF\n");
        }
        keepGoing = fscanf(fp, "%d", &ar[num]) == 1;
        printf("I read %d\n", ar[num]);

        while (keepGoing)
        // while (!feof(fp) && fscanf("%d", &ar[num]) == 1)
        {
            num++;
            keepGoing = !feof(fp);
            if (keepGoing)
            {
                printf("not EOF yet\n");
            }
            else
            {
                printf("At EOF\n");
            }
            keepGoing = fscanf(fp, "%d", &ar[num]) == 1;
            if (keepGoing)
            {
                printf("I read %d\n", ar[num]);
            }
            else
            {
                printf("fscanf failed\n");
            }
        }
    }
    return num;
}

int main(void)
{
    char lineArray[20][MAX_LINE_LEN + 1] = {0};
    char bigBuffer[200] = {0};
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Open failed\n");
    }
    else
    {
        int nlines = readFile(fp, lineArray, 20);
        int i;
        for (i = 0; i < nlines; i++)
        {
            printf("%03d: %s", i + 1, lineArray[i]);
        }

        rewind(fp);
        int nchars = readFileAsMess(fp, bigBuffer);
        printf("\n===================\n");
        printf("Read %d chars from %s", nchars, bigBuffer);

        rewind(fp);
        printf("My own read line by line\n");
        while (readMeALine(fp, bigBuffer))
        {
            printf("%s\n", bigBuffer);
        }
        printf("%s\n", bigBuffer);
        fclose(fp);
    }

    fp = fopen("numbers.txt", "r");
    if (!fp)
    {
        printf("Cannot open numbers\n");
    }
    else
    {
        int ar[20] = {0}, num, i;
        num = readNumbers(fp, ar);
        for (i = 0; i < num; i++)
        {
            printf("%d\n", ar[i]);
        }
        fclose(fp);
    }

    return 0;
}