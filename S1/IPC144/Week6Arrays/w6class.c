#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_PAYS 10
#define MAX_PRODUCTS 5

int main(void)
{
    double pay1, pay2, pay3, sum = 0;
    double pay[MAX_PAYS] = {0};
    int i, numPays = 0;

    for (i = 0; i < MAX_PAYS; i++)
    {
        printf("Enter pay %d (0 to stop): ", i + 1);
        scanf("%lf", &pay[i]);
        sum += pay[i];
        if (pay[i] == 0)
            i = MAX_PAYS; // exit loop on zero
        else
            numPays++; //
    }

    double avg = sum / numPays;
    printf("avg = %lf\n", avg);

    printf("Above average pays: \n");
    // loop only over the number of pays entered
    for (i = 0; i < numPays; i++)
    {
        if (pay[i] > avg)
        {
            printf("%lf\n", pay[i]);
        }
    }

    // part 2
    double price[MAX_PRODUCTS] = {99.22, 22.33, 33.44, 44.55, 55.66};
    int sku[MAX_PRODUCTS] = {1, 2, 3, 4, 5};
    int productID = 0, posn = -1;

    printf("Seneca grocery price check\n");
    do
    {
        printf("Enter the SKU to check: ");
        scanf("%d", &productID);
        if (productID != 0)
        {
            // linear search
            posn = -1;
            for (i = 0; i < MAX_PRODUCTS; i++)
            {
                if (sku[i] == productID)
                {
                    posn = i;
                }
            }
            if (posn >= 0)
                printf("price=%.2lf\n", price[posn]);
            else
                printf("cannot find %d\n", productID);
        }

    } while (productID != 0);

    // part3
    double highestPrice = -99.9;
    int mostExpensivedID = -1;

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        if (price[i] > highestPrice)
        {
            highestPrice = price[i];
            mostExpensivedID = sku[i];
        }
    }

    printf("The most expensive product is %.3lf\n", highestPrice);
    printf("The most expensive product ID is %d\n", mostExpensivedID);

    // part4
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, day, dayOfYear = 0;

    printf("Enter a month and a day: ");
    scanf("%d%d", &month, &day);

    if (month < 1 || month > 12 || day < 1)
    {
        printf("Bad date\n");
    }
    else if (day < 1 || day > monthDays[month - 1])
    {
        printf("Bad date\n");
    }
    else
    {
        for (i = 0; i < month - 1; i++)
        {
            dayOfYear += monthDays[i];
        }
        dayOfYear += day;

        printf("That is the %d day of the year\n", dayOfYear);
    }
    return 0;
}
