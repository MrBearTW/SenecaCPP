#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validPostalCode(const char pc[])
{
    int result = pc != NULL;
    if (result)
    {
        int len = strlen(pc);
        result = len == 6 || len == 7;
        if (result)
        {
            int i, alpha = 1;
            for (i = 0; i < len && result; i++)
            {
                switch (alpha)
                {
                case 0:
                    result = isdigit(pc[i]) || (i == 3 && isspace(pc[i]));
                    if (!(i == 3 && isspace(pc[i])))
                    {
                        alpha = !alpha;
                    }
                    break;

                case 1:
                    result = isalpha(pc[i]);
                    alpha = !alpha;
                    break;
                }
            }
        }
    }
    return result;
}

void formatPostalCode(const char pc[], char formatted[])
{
    int i, len = strlen(pc), fmtPtr = 0, start = 0;
    for (i = 0; i < 3; i++)
    {
        formatted[fmtPtr++] = toupper(pc[i]);
    }
    if (pc[3] == ' ')
    {
        formatted[fmtPtr++] = ' ';
        start = 4;
    }
    else
    {
        formatted[fmtPtr++] = ' ';
        start = 3;
    }

    for (i = 0; i < 3; i++)
    {
        formatted[fmtPtr++] = toupper(pc[i + start]);
    }
    formatted[fmtPtr++] = '\0';
}

void strip(char s[])
{
    if (s != NULL)
    {
        int len = strlen(s);
        int i, j;
        for (i = (len - 1); i >= 0 && isspace(s[i]); i--)
        {
            len--;
        }
        if (len <= 0)
        {
            s[0] = '\0';
        }
        else
        {
            s[len] = '\0';
            i = 0;
            while (isspace(s[i]))
                i++;
            for (j = 0; s[j + i] != '\0'; j++)
            {
                s[j] = s[j + i];
            }
            s[j] = '\0';
        }
    }
}

int getNumbers(const char s[], int numbers[])
{
    char buf[16] = {0};
    int bufPt = 0,inNumber = 0, result = 0;

    if (s != NULL)
    {
        int len = strlen(s);
        int i;
        for (i = 0; i < len; i++)
        {
            if (isdigit(s[i]))
            {
                buf[bufPt++] = s[i];
                inNumber = 1;
            }
            else
            {
                if (inNumber)
                {
                    buf[bufPt] = '\0';
                    inNumber = !inNumber;
                    bufPt = 0;
                    numbers[result++] = atoi(buf);
                }
            }
        }
    }
    return result;
}

void formatMessage(char fmtStr[], const char insert[])
{
    // "I ate $ for dinner"
    if (fmtStr != NULL && insert != NULL)
    {
        int i, len = strlen(fmtStr);
        for (i = 0; i < len && fmtStr[i] != '$'; i++)
            ;
        if (i < len)
        {
            char tmp[100] = {0};
            strcpy(tmp, fmtStr + i + 1);
            fmtStr[i] = '\0';
            strcat(fmtStr, insert);
            strcat(fmtStr, tmp);
        }
    }
}

int main(void)
{
    char goodpc1[] = "e2m 2K7";
    char goodpc2[] = "e2m2K7";
    char badpc1[] = "ejm 2k7";
    char badpc2[] = "ejm2k7";
    char badpc3[] = "e2m k7";
    char prettyPC[16] = {0};
    char leadTrail1[] = {"    ABC    DEF   "};
    char strWithNums[] = {" 23 dogs ate 7 apple   "};
    int numbers[10] = {0};
    int i, n = 0;

    printf("%s is %s\n", goodpc1, validPostalCode(goodpc1) ? "good" : "bad");
    printf("%s is %s\n", goodpc2, validPostalCode(goodpc2) ? "good" : "bad");
    printf("%s is %s\n", badpc1, validPostalCode(badpc1) ? "good" : "bad");
    printf("%s is %s\n", badpc2, validPostalCode(badpc2) ? "good" : "bad");
    printf("%s is %s\n", badpc3, validPostalCode(badpc3) ? "good" : "bad");

    formatPostalCode(goodpc1, prettyPC);
    printf("The pretty version of %s is %s \n", goodpc1, prettyPC);

    formatPostalCode(goodpc2, prettyPC);
    printf("The pretty version of %s is %s \n", goodpc2, prettyPC);

    strip(leadTrail1);
    printf("Stripped = \'%s\'\n", leadTrail1);

    n = getNumbers(strWithNums, numbers);
    printf("The numbers are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    char fmtStr[100] = {"I ate $ for dinner"};
    formatMessage(fmtStr, "fish");
    printf("The formatted string is %s\n", fmtStr);

    return 0;
}