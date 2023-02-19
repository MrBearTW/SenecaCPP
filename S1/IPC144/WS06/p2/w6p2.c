/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
    double income, costSum;
    int items = 0, i = 0, forecastSelect = -1, y, m, finprinted = 0, priorityFilter = 0;
    double cost[MAX_ITEMS] = {0};
    int priority[MAX_ITEMS] = {0};
    char finOption[MAX_ITEMS] = {0};

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
            if (cost[i] <= 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
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

    while (forecastSelect != 0)
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastSelect);
        printf("\n");

        switch (forecastSelect)
        {
        case 1:
            printf("====================================================\n");
            printf("Filter:   All items\n");
            costSum = 0;
            for (i = 0; i < items; i++)
            {
                costSum += cost[i];
            }
            printf("Amount:   $%.2lf\n", costSum);
            y = (int)(costSum / income / 12);
            m = (int)(costSum / income) % 12 == 0 ? (int)(costSum / income) % 12 : ((int)(costSum / income) % 12) + 1;
            if (m == 12)
            {
                y++;
                m = 0;
            }
            printf("Forecast: %d years, %d months\n", y, m);
            for (i = 0, finprinted = 0; i < items && finprinted == 0; i++)
            {
                if (finOption[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    finprinted = 1;
                }
            }
            printf("====================================================\n");
            printf("\n");

            break;
        case 2:
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityFilter);
            costSum = 0;
            for (i = 0; i < items; i++)
            {
                if (priority[i] == priorityFilter)
                {
                    costSum += cost[i];
                }
            }
            printf("Amount:   $%.2lf\n", costSum);
            y = (int)(costSum / income / 12);
            m = (int)(costSum / income) % 12 == 0 ? (int)(costSum / income) % 12 : ((int)(costSum / income) % 12) + 1;
            if (m == 12)
            {
                y++;
                m = 0;
            }
            printf("Forecast: %d years, %d months\n", y, m);
            for (i = 0, finprinted = 0; i < items && finprinted == 0; i++)
            {
                if (priority[i] == priorityFilter && finOption[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    finprinted = 1;
                }
            }
            printf("====================================================\n");
            printf("\n");
            break;
        case 0:
            printf("Best of luck in all your future endeavours!\n");
            break;
        default:
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
            break;
        }
    }
    printf("\n");
    return 0;
}
