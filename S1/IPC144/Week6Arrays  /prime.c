#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int i, j, prime = 0;

    for (i = 0; i < 100; i++)
    {
        prime = 1;
        for (j = i - 1; j > 1; j--)
        {
            if (i % j == 0)
                prime = 0;
        }
        if (prime)
        {
            printf("%d is prime\n", i);
        }      
    }

    return 0;
}
