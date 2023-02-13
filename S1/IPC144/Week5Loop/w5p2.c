/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  :CHI-WEI PERNG
Student ID#:121967228
Email      :cperng@myseneca.ca
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month, i;
    double morningInput, morningTotal = 0, eveningInput, eveningTotal = 0;

    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);
        if (year > MAX_YEAR || year < MIN_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while ((year > MAX_YEAR || year < MIN_YEAR) || (month < JAN || month > DEC));

    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");

    // part 2:
    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("%d-", year);
        switch (month)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        default:
            break;
        }
        printf("-0%d\n", i + 1);
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningInput);
            if (morningInput < 0 || morningInput > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                morningTotal += morningInput;
            }
        } while (morningInput < 0 || morningInput > 5.0);
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningInput);
            if (eveningInput < 0 || eveningInput > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                eveningTotal += eveningInput;
            }
        } while (eveningInput < 0 || eveningInput > 5.0);
        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningTotal);
    printf("Evening total rating:%7.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n", morningTotal + eveningTotal);
    printf("\n");
    printf("Average morning rating: %4.1lf\n", morningTotal / 3);
    printf("Average evening rating: %4.1lf\n", eveningTotal / 3);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningTotal + eveningTotal) / 6);

    return 0;
}