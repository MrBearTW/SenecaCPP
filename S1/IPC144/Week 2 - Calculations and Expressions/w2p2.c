/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    printf("\n");
    printf("Sally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numberSally);
    printf("\n");
    printf("Customer Size Price Qty Sub-Total Tax Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    float subTotalPatty = sPrice * numberPatty;
    int taxesRoundPatty = (subTotalPatty * TAX * 100) + 0.5;
    float taxPatty = taxesRoundPatty / 100.0;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, sPrice, numberPatty, subTotalPatty, taxPatty, subTotalPatty + taxPatty);
    float subTotalSally = mPrice * numberSally;
    int taxesRoundSally = (subTotalSally * TAX * 100) + 0.5;
    float taxSally = taxesRoundSally / 100.0;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mPrice, numberSally, subTotalSally, taxSally, subTotalSally + taxSally);
    float subTotalTommy = lPrice * numberTommy;
    int taxesRoundTommy = (subTotalTommy * TAX * 100) + 0.5;
    float taxTommy = taxesRoundTommy / 100.0;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lPrice, numberTommy, subTotalTommy, taxTommy, subTotalTommy + taxTommy);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subTotal = subTotalPatty + subTotalTommy + subTotalSally;
    float taxTotal = taxPatty + taxTommy + taxSally;
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal, taxTotal, subTotal + taxTotal);
    printf("\n");
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    // Sales EXCLUDING tax
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty Balance\n");
    printf("-------- --- ---------\n");
    printf("             %22.4lf\n", subTotal);
    int TooniesEx = subTotal / 2;
    float TooniesExF = subTotal - TooniesEx * 2;
    printf("Toonies %3d %9.4lf\n", TooniesEx, TooniesExF);
    int LooniesEx = TooniesExF / 1;
    float LooniesExF = TooniesExF - LooniesEx * 1;
    printf("Toonies %3d %9.4lf\n", LooniesEx, LooniesExF);
    int QuartersEx = LooniesExF / 0.25;
    float QuartersExF = LooniesExF - QuartersEx * 0.25;
    printf("Toonies %3d %9.4lf\n", QuartersEx, QuartersExF);
    int DimesEx = QuartersExF / 0.10;
    float DimesExF = QuartersExF - DimesEx * 0.10;
    printf("Toonies %3d %9.4lf\n", DimesEx, DimesExF);
    int NickelsEx = DimesExF / 0.05;
    float NickelsExF = DimesExF - NickelsEx * 0.05;
    printf("Toonies %3d %9.4lf\n", NickelsEx, NickelsExF);
    int PenniesEx = NickelsExF / 0.01;
    float PenniesExF = NickelsExF - PenniesEx * 0.01;
    printf("Toonies %3d %9.4lf\n", PenniesEx, PenniesExF);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", subTotal/(numberPatty+ numberSally + numberTommy));
    printf("\n");
    // Sales INCLUDING tax
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty Balance\n");
    printf("-------- --- ---------\n");
    printf("             %22.4lf\n", subTotal + taxTotal);
    TooniesEx = (subTotal + taxTotal) / 2;
    TooniesExF = subTotal + taxTotal - TooniesEx * 2;
    printf("Toonies %3d %9.4lf\n", TooniesEx, TooniesExF);
    LooniesEx = TooniesExF / 1;
    LooniesExF = TooniesExF - LooniesEx * 1;
    printf("Toonies %3d %9.4lf\n", LooniesEx, LooniesExF);
    QuartersEx = LooniesExF / 0.25;
    QuartersExF = LooniesExF - QuartersEx * 0.25;
    printf("Toonies %3d %9.4lf\n", QuartersEx, QuartersExF);
    DimesEx = QuartersExF / 0.10;
    DimesExF = QuartersExF - DimesEx * 0.10;
    printf("Toonies %3d %9.4lf\n", DimesEx, DimesExF);
    NickelsEx = DimesExF / 0.05;
    NickelsExF = DimesExF - NickelsEx * 0.05;
    printf("Toonies %3d %9.4lf\n", NickelsEx, NickelsExF);
    PenniesEx = NickelsExF / 0.01;
    PenniesExF = NickelsExF - PenniesEx * 0.01;
    printf("Toonies %3d %9.4lf\n", PenniesEx, PenniesExF);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", (subTotal + taxTotal) / (numberPatty + numberSally + numberTommy));

    return 0;
}
