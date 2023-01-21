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
    float sPrice, mPrice, lPrice, subTotal, total;
    int numberPatty;

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
    printf("Patty's shirt size is \'S\'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberPatty);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberPatty);

    subTotal = sPrice * numberPatty;
    printf("Sub-total: $%.4f\n", subTotal);

    int taxesRound = (subTotal * TAX * 100) + 0.5;
    printf("Taxes    : $ %.4lf\n", taxesRound/100.0);

    printf("Total    : $%.4lf\n", total = subTotal + taxesRound / 100.0);

    return 0;
}