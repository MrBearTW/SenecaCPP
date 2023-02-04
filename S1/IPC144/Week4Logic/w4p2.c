/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
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
    int apples, oranges, pears, tomatoes, cabbages, pick, picked, end;

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        // get APPLES need
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
        printf("\n");
        // get ORANGES need
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");
        // get PEARS need
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");
        // get TOMATOES need
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");
        // get CABBAGES need
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");
        // pick apples
        if (apples > 0)
        {
            pick = 0;
            picked = 0;
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked + pick < apples)
                {
                    printf("Looks like we still need some APPLES...\n");
                    picked += pick;
                }
                else if (picked + pick > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - picked);
                }
                else if (picked + pick == apples)
                {
                    printf("Great, that's the apples done!\n");
                    picked += pick;
                }
            } while (picked != apples);
            printf("\n");
        }
        // pick oranges
        if (oranges > 0)
        {
            pick = 0;
            picked = 0;
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked + pick < oranges)
                {
                    printf("Looks like we still need some ORANGES...\n");
                    picked += pick;
                }
                else if (picked + pick > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - picked);
                }
                else if (picked + pick == oranges)
                {
                    printf("Great, that's the oranges done!\n");
                    picked += pick;
                }
            } while (picked != oranges);
            printf("\n");
        }
        // pick pears
        if (pears > 0)
        {
            pick = 0;
            picked = 0;
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked + pick < pears)
                {
                    printf("Looks like we still need some PEARS...\n");
                    picked += pick;
                }
                else if (picked + pick > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - picked);
                }
                else if (picked + pick == pears)
                {
                    printf("Great, that's the pears done!\n");
                    picked += pick;
                }
            } while (picked != pears);
            printf("\n");
        }
        // pick tomatoes
        if (tomatoes > 0)
        {
            pick = 0;
            picked = 0;
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked + pick < tomatoes)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    picked += pick;
                }
                else if (picked + pick > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes - picked);
                }
                else if (picked + pick == tomatoes)
                {
                    printf("Great, that's the tomatoes done!\n");
                    picked += pick;
                }
            } while (picked != tomatoes);
            printf("\n");
        }
        // pick cabbages
        if (cabbages > 0)
        {
            pick = 0;
            picked = 0;
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (picked + pick < cabbages)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    picked += pick;
                }
                else if (picked + pick > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages - picked);
                }
                else if (picked + pick == cabbages)
                {
                    printf("Great, that's the cabbages done!\n");
                    picked += pick;
                }
            } while (picked != cabbages);
            printf("\n");
        }

        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &end);
        printf("\n");
    } while (end != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}