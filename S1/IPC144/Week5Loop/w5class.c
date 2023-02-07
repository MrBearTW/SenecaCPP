// Enter 3 pairs of number as long as the first is negative and thee second positive.
// If they do not meet this criteria, then stop

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int i, m, n, good = 1, j;
    for (i = 0; i < 3 && good; i++)
    {
        printf("enter a negative and a positive number: ");
        scanf("%d%d", &m, &n);
        good = m < 0 && n > 0;
        if (good)
            printf("m=%d, n=%d\n", m, n);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = i; j > 0; j--)
        {
            printf("i=%d, j=%d\n", i, j);
        }
    }
    // i=1, j=1
    // i=2, j=2
    // i=2, j=1

/*
    int keepGoing = 0, i, j;
    char type;
    do
    {
        printf("Enter loop type and number of times: ");
        scanf("%c%d%*c", &type, &i);
        switch (type)
        {
        case 'W':
            if (i >=3 && i <= 10)
                for (j = 0; j < i; j++)
                {
                    printf("", type);
                }
            break;
        case 'Q':
            if (i == 0)
                keepGoing = 0;
            break;
        }
    } while (keepGoing);
*/

    // find the largest of group of number entered
    int largest = -9999999;
    n = 1;
    while (n > 0)
    {
        printf("pick a positvive number (0 or neg to exit): ");
        scanf("%d", &n);
        if (n > 0)
        {
            if (n > largest)
            {
                largest = n;
            }
        }
    }
    printf("The largest value is %d\n",largest);

    // find the average of a series of numbers
    int sum =0, nvalues =0;
    n=1;
    while (n > 0)
    {
        printf("pick a positvive number (0 or neg to exit): ");
        scanf("%d", &n);
        if (n > 0)
        {
            if (n > largest)
            {
                sum += n;
                nvalues++;
            }
        }
    }
    printf("The average value is %.2lf\n",(double)sum/nvalues);


    return 0;
}
