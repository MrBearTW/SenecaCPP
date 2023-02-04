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
	int result, money = 7245;
	result = money / 100;
	printf("1. $%.2lf\n", money / 100);
	printf("2. $%d\n", money / 100);
	printf("3. $%.2lf\n", result);
	printf("4. $%d\n", result);
	/*
	1. $0.00
	2. $72
	3. $0.00
	4. $72
	*/
	
	return 0;
}


