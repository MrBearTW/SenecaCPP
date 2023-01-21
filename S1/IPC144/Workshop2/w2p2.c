/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float sPrice, mPrice, lPrice, subTotal, total;
    int numberPatty, numberTommy, numberSally;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &sPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &lPrice);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", sPrice);
    printf("MEDIUM : $%.2f\n", mPrice);
    printf("LARGE  : $%.2f\n", lPrice);
    printf("\n");
    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberPatty);
    printf("\n");
    printf("Tommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numberTommy);
    printf("\n")
    printf("Sally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numberSally);
    printf("\n");;



    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberPatty);


    subTotal = sPrice * numberPatty;
    printf("Sub-total: $%.4f\n", subTotal);

    int taxesRound = (subTotal * TAX * 100) + 0.5;
    printf("Taxes    : $ %.4lf\n", taxesRound / 100.0);
    printf("Total    : $%.4lf\n", total = subTotal + taxesRound / 100.0);

    return 0;
}

//printf("Patty %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", ...
//printf("%33.4lf %9.4lf %9.4lf\n\n", ...