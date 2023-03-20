#define _CRT_SECURE_NOWARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int function(int n)
{
    int j = n++;
    return n;
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

void printWords(char s[])
{
    int i, bufPt = 0;
    char buf[100] = {0};

    for (i = 0; s[i] != '\0'; i++)
    {
        while (isspace(s[i]))
        {
            i++;
        }
        if (s[i] != '\0')
        {
            bufPt = 0;
            while (!isspace(s[i]) && s[i] != '\0')
            {
                buf[bufPt++] = s[i];
                i++;
            }
            buf[bufPt] = '\0';
            printf("%s\n", buf);
        }
    }
}

int main(void)
{
    int n = 42;
    int j = function(n);

    printf("in main j = %d and n = %d\n", j, n);

    {
        // this is an inner scope or nested scope
        int n = 99;
        printf("in nested scope j = %d and n = %d\n", j, n);
    }
    printf("in main after nested scope j = %d and n = %d\n", j, n);

    // String
    char name[100] = {"Fred Flintstone"};
    printf("There are %ld characters in %s\n", strlen(name), name);

    char str2[100] = {0};
    strcpy(str2, "Barnet Rubble");
    printf("str2=%s\n", str2);

    strcat(str2, " is friends with ");
    strcat(str2, name);
    printf("str2=%s\n", str2);

    strcpy(str2, "yes");
    // does strcpy equal yes?
    printf("str2 does%s equal yes\n", (strcmp(str2, "yes") == 0) ? "" : " not");

    strcpy(str2, "no");
    // does strcpy equal yes?
    printf("str2 does%s equal yes\n", (strcmp(str2, "yes") == 0) ? "" : " not");

    printf("Enter you name: ");
    scanf("%[^\n]", name);
    printf("Hello %s\n", name);
    // clearBuffer();
    printf("The next char = %d\n", getchar());

    printf("Enter 2 numbers sparated by | :");
    scanf("%d|%d", &j, &n);

    int age = 0, height = 0, good = 0;
    printf("Enter your name, a colon, your age, a dash and your height:");
    // scanf("%[^:]%*c%d-%d", &name, &age, &height);
    scanf("%[^:]:%d-%d", &name, &age, &height);

    printf("Hi %s, I see you are %d years old and %d tall\n", name, age, height);

    do
    {
        printf("Enter a number: ");
        int nread = scanf("%d", &n);
        clearBuffer();
        good = nread == 1;
    } while (!good);
    printf("You entered =%d", n);
    printf("You entered =%8d", n);
    printf("You entered =%08d", n);
    printf("You entered =%-8dx", n);

    srand(time(NULL));
    int guess = rand() % 10 + 1;
    printf("What number from 1-10 did I guess? ");
    scanf("%d", &n);
    if (guess == n)
        printf("Con you win!!\n");
    else
        printf("I guessed %d - you loss\n", guess);

    printWords("This is a sentence");
    return 0;
}