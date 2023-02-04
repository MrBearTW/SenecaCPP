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
	int money = 7245;
	printf("1. $%.2lf\n", money / 100.0);
	printf("2. $%.2lf\n", money / (double)100);
	printf("3. $%.2lf\n", (double)money / 100);
	/*
	1. $72.45
	2. $72.45
	3. $72.45
	*/

	return 0;

}


