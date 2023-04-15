/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <ctype.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
int inputInt(void)
{
    char newLine = 'x';
    int value = 0;
    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }

    return value;
}

int inputIntPositive(void)
{
    int intPositive = 0;
    while (intPositive <= 0)
    {
        intPositive = inputInt();
        if (intPositive <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    }
    return intPositive;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int input = 0;

    do
    {
        input = inputInt();
        if (input < lowerBound || input > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (input < lowerBound || input > upperBound);

    return input;
}

char inputCharOption(const char optionCstring[])
{
    char input;
    int i, inTheCstring = 0;

    while (inTheCstring == 0)
    {
        scanf("%c", &input);
        for (i = 0; optionCstring[i] != '\0'; i++)
        {
            if (input == optionCstring[i])
            {
                inTheCstring = 1;
            }
        }
        if (inTheCstring == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", optionCstring);
        }
        clearInputBuffer();
    }
    return input;
}

void inputCString(char *aCstring, int minimumNumberofCharacters, int maximumNumberofCharacters)
{
    char input[100] = {0};
    int inputNumber, inTheRange = 0;

    while (inTheRange == 0)
    {
        inputNumber = 0;
        scanf("%99[^\n]", input);

        // MS1
        // int i, j = 0;
        // for (i = 0; input[i] != '\0'; i++)
        // {
        //     inputNumber++;
        // }

        // MS2
        inputNumber = strlen(input);

        if (inputNumber <= maximumNumberofCharacters && inputNumber >= minimumNumberofCharacters)
        {
            inTheRange = 1;
            // MS1
            // while (input[j] != '\0')
            // {
            //     aCstring[j] = input[j];
            //     j++;
            // }
            // aCstring[j] = '\0';

            // MS2
            strcpy(aCstring, input);
        }
        else
        {
            if (maximumNumberofCharacters == minimumNumberofCharacters)
            {
                printf("Invalid %d-digit number! Number: ", maximumNumberofCharacters);
            }
            else if (inputNumber > maximumNumberofCharacters)
            {
                printf("ERROR: String length must be no more than %d chars: ", maximumNumberofCharacters);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minimumNumberofCharacters, maximumNumberofCharacters);
            }
        }
        clearInputBuffer();
    }
}

void displayFormattedPhone(const char *phoneString)
{
    int i, argumentCount = 0, isNotDigit = 0;

    // it is exactly 10 characters long
    if (phoneString != NULL)
    {
        // MS1
        // for (i = 0; phoneString[i] != '\0'; i++)
        // {
        //     argumentCount++;
        // }

        // MS2
        argumentCount = strlen(phoneString);

        // only contains digits (0-9)
        for (i = 0; phoneString[i] != '\0'; i++)
        {
            // if (phoneString[i] < '0' || phoneString[i] > '9')     // MS1
            if (!isdigit(phoneString[i])) // MS2
            {
                isNotDigit = 1;
            }
        }
    }

    // Print result
    if (argumentCount == 10 && isNotDigit == 0 && phoneString != NULL)
    {
        for (i = 0; phoneString[i] != '\0'; i++)
        {
            if (i == 0)
            {
                printf("(");
            }
            else if (i == 3)
            {
                printf(")");
            }
            else if (i == 6)
            {
                printf("-");
            }
            printf("%c", phoneString[i]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
