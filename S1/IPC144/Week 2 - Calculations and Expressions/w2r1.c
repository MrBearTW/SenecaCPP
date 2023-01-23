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
    float price1 = 17.96f, price3 = 17.98f;
	double price2 = 17.96, price4 = 17.98;
	printf("1. 17.96 = %f (as cents:%d)\n", price1, (int)(price1 * 100));
	printf("2. 17.96 = %lf (as cents:%d)\n", price2, (int)(price2 * 100));
	printf("3. 17.98 = %f (as cents:%d)\n", price3, (int)(price3 * 100));
	printf("4. 17.98 = %lf (as cents:%d)\n", price4, (int)(price4 * 100));
	/*
	1. 17.96 = 17.959999 (as cents : 1795)
	2. 17.96 = 17.960000 (as cents : 1796)
	3. 17.98 = 17.980000 (as cents : 1798)
	4. 17.98 = 17.980000 (as cents : 1798)
	*/

	printf("5. 17.96 = %.12f (as cents:%d)\n", price1, (int)(price1 * 100));
	printf("6. 17.96 = %.12lf (as cents:%d)\n", price2, (int)(price2 * 100));
	printf("7. 17.98 = %.12f (as cents:%d)\n", price3, (int)(price3 * 100));
	printf("8. 17.98 = %.12lf (as cents:%d)\n", price4, (int)(price4 * 100));
	/*
	5. 17.96 = 17.959999084473 (as cents : 1795)
	6. 17.96 = 17.960000000000 (as cents : 1796)
	7. 17.98 = 17.979999542236 (as cents : 1798)
	8. 17.98 = 17.980000000000 (as cents : 1798)
	*/

	printf("9. 17.98 = %.12f (as cents:%d)\n", price3, (int)(price3 * 100.0));
	printf("10. 17.98 = %.12f (as cents:%f)\n", price3, price3 * 100.0);
	/*
	9. 17.98 = 17.979999542236 (as cents:1797)
	10. 17.98 = 17.979999542236 (as cents:1797.999954)
	*/

	return 0;
}


