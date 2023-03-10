#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(const int a, const int b)
{
    return a + b;
}

double round(double d, int digits)
{
    int i, multiplier = 1;
    double result = 0;
    for (i = 0; i < digits; i++)
    {
        multiplier *= 10;
    }
    d *= multiplier;
    d += 0.5;
    result = (int)d;
    result /= multiplier;
    return result;
}

// print a title centered in filler chars of the indicate width
void printHeader(char title[], int width, char filler)
{
    int len, eachSide = 0, i;
    for (len = 0; title[len] != '\0'; len++)
    {
        eachSide = (width - len) / 2;
    }
    for (i = 0; i < eachSide; i++)
    {
        printf("%c", filler);
    }
    printf("\n");
}

int main(void)
{
    printHeader(" Functions ", 50, '*');
    
    printf("Ths sum of 7 + 4 = %d\n", add(7, 4));

    printf("3.76 rounded to 0 digits = %.2lf\n", round(3.76, 0));
    printf("3.26 rounded to 0 digits = %.2lf\n", round(3.26, 0));
    printf("3.76 rounded to 1 digits = %.2lf\n", round(3.76, 1));
    printf("3.7628 rounded to 3 digits = %.6lf\n", round(3.7628, 3));
}

