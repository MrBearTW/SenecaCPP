/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  :CHI-WEI PERNG
Student ID#:121967228
Email      :cperng@myseneca.ca
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef CORE_H
#define CORE_H

#define _CRT_SECURE_NO_WARNINGS

// Clear the standard input buffer void clearInputBuffer(void);
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lowerBound, int upperBound);

char inputCharOption(const char optionCstring[]);

void inputCString(char *aCstring, int minimumNumberofCharacters, int maximumNumberofCharacters);

void displayFormattedPhone(const char *phoneString);

#endif