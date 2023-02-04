/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char c1Type, c2Type, c3Type, c1Cream, c2Cream, c3Cream, orderType, orderCream;
    int c1BageWeight, c2BageWeight, c3BageWeight, orderServings;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c1Type);
    printf("Bag weight (g): ");
    scanf("%d", &c1BageWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c1Cream);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c2Type);
    printf("Bag weight (g): ");
    scanf("%d", &c2BageWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c2Cream);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c3Type);
    printf("Bag weight (g): ");
    scanf("%d", &c3BageWeight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c3Cream);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c1Type == 'l' || c1Type == 'L', c1Type == 'm' || c1Type == 'M', c1Type == 'r' || c1Type == 'R', c1BageWeight, c1BageWeight / GRAMS_IN_LBS, c1Cream == 'y' || c1Cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c2Type == 'l' || c2Type == 'L', c2Type == 'm' || c2Type == 'M', c2Type == 'r' || c2Type == 'R', c2BageWeight, c2BageWeight / GRAMS_IN_LBS, c2Cream == 'y' || c2Cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c3Type == 'l' || c3Type == 'L', c3Type == 'm' || c3Type == 'M', c3Type == 'r' || c3Type == 'R', c3BageWeight, c3BageWeight / GRAMS_IN_LBS, c3Cream == 'y' || c3Cream == 'Y');
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &orderType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &orderCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &orderServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");

    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c1Type == 'l' || c1Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c1Type == 'm' || c1Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c1Type == 'r' || c1Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c1BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c1BageWeight == 500)||(orderServings >= 10 && (c1BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c1Cream == 'y' || c1Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c1Cream == 'n' || c1Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c2Type == 'l' || c2Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c2Type == 'm' || c2Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c2Type == 'r' || c2Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c2BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c2BageWeight == 500)||(orderServings >= 10 && (c2BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c2Cream == 'y' || c2Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c2Cream == 'n' || c2Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c3Type == 'l' || c3Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c3Type == 'm' || c3Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c3Type == 'r' || c3Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c3BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c3BageWeight == 500)||(orderServings >= 10 && (c3BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c3Cream == 'y' || c3Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c3Cream == 'n' || c3Cream == 'N')));
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &orderType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &orderCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &orderServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c1Type == 'l' || c1Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c1Type == 'm' || c1Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c1Type == 'r' || c1Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c1BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c1BageWeight == 500)||(orderServings >= 10 && (c1BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c1Cream == 'y' || c1Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c1Cream == 'n' || c1Cream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c2Type == 'l' || c2Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c2Type == 'm' || c2Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c2Type == 'r' || c2Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c2BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c2BageWeight == 500)||(orderServings >= 10 && (c2BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c2Cream == 'y' || c2Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c2Cream == 'n' || c2Cream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n", ((orderType == 'l' || orderType == 'L') && (c3Type == 'l' || c3Type == 'L')) || ((orderType == 'm' || orderType == 'M') && (c3Type == 'm' || c3Type == 'M')) || ((orderType == 'r' || orderType == 'R') && (c3Type == 'r' || c3Type == 'R')), (orderServings <= 4 && orderServings >= 1)&&(c3BageWeight == 250)||(orderServings <= 9 && orderServings >= 5)&&(c3BageWeight == 500)||(orderServings >= 10 && (c3BageWeight == 1000)), ((orderCream == 'y' || orderCream == 'Y')&&(c3Cream == 'y' || c3Cream == 'Y'))||((orderCream == 'n' || orderCream == 'N')&&(c3Cream == 'n' || c3Cream == 'N')));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
