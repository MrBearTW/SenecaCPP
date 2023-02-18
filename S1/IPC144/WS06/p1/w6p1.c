/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define INCOME_AT_LEAST 500
#define INCOME_NO_MORE_THAN 400000
#define MAX_ITEMS 10
#define costLeast 100

#include <stdio.h>

int main(void)
{
    double income;
    int items = 0, i = 0;
    double cost[MAX_ITEMS] = {0};
    int priority[MAX_ITEMS] = {0};
    char finOption[MAX_ITEMS] = {0};
    double costSum;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income > INCOME_NO_MORE_THAN)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        else if (income < INCOME_AT_LEAST)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        printf("\n");

    } while (income > INCOME_NO_MORE_THAN || income < INCOME_AT_LEAST);

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items > MAX_ITEMS || items < 1)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        printf("\n");
    } while (items > MAX_ITEMS || items < 1);

    for (i = 0; i < items; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            (cost[i] <= 100) ? printf("      ERROR: Cost must be at least $100.00\n") : cost[i];
        } while (cost[i] <= 100);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] != 1 && priority[i] != 2 && priority[i] != 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] != 1 && priority[i] != 2 && priority[i] != 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finOption[i]);
            if (finOption[i] != 'y' && finOption[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (finOption[i] != 'y' && finOption[i] != 'n');
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finOption[i], cost[i]);
        costSum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", costSum);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
