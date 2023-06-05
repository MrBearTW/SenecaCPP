#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mathfuncs.h"

/*
double square(double n)
{
	return n * n;
}

double cube(double n)
{
	return n * n * n;
}
*/

int main(void) {
	struct enter inPut = { 0 };
	getFirstName(inPut.firstName);
	getLastName(inPut.lastName);
	getStreetAddress(inPut.streetAddress);
	getCity(inPut.city);
	getProvince(inPut.province);
	getPostalCode(inPut.postalCode);
	puts(" ");
	puts("You entere");
	fputs(inPut.firstName, stdout);
	printf(" ");
	puts(inPut.lastName);
	puts(inPut.streetAddress);
	puts(inPut.city);
	puts(inPut.province);
	puts(inPut.postalCode);
	return 0;
}


int getFirstName(char* firstName) {
	char temp[10] = { 0 };
	printf("Enter your first name : ");
	scanf("%10[^\n]", &temp);
	strcpy(firstName, temp);
	clearInputBuffer();
	return 0;
}
int getLastName(char* lastName) {
	char temp[10] = { 0 };
	int empty = 0;
	do
	{
		printf("Enter your last name : ");
		scanf("%10[^\n]", &temp);
		empty = notEmpty(temp);
		if (empty == 0 ) {
			puts("Invalid Entry :  ");
		}
		clearInputBuffer();
	} while (empty == 0);
	strcpy(lastName, temp);
	return 0;
}

int notEmpty(char* temp) {
	if (strlen(temp) == 0)
	{
		return 0;
	}
	return 1;
}


int getStreetAddress(char* streetAddress) {
	char temp[20] = { 0 };
	printf("Enter your street address : ");
	scanf("%20[^\n]", &temp);
	strcpy(streetAddress, temp);
	clearInputBuffer();
	return 0;
}
int getCity(char* city) {
	char temp[10] = { 0 };
	printf("Enter your city : ");
	scanf("%10[^\n]", &temp);
	strcpy(city, temp);
	clearInputBuffer();
	return 0;
}
int getProvince(char* province) {
	char temp[10] = { 0 };
	printf("Enter your province : ");
	scanf("%10[^\n]", &temp);
	strcpy(province, temp);
	clearInputBuffer();
	return 0;
}
int getPostalCode(char* postalCode) {
	char temp[10] = { 0 };
	int i = 0;
	char ch;
	int space = 0;
	do
	{
		printf("Enter your postal code : ");
		scanf("%10[^\n]", &temp);
		clearInputBuffer();
		space = centerIsSpace(temp);
		if (space == 0)
		{
			printf("Invalid Entry :  ");
		}
	} while (space == 0);

	while (temp[i])
	{
		ch = temp[i];
		temp[i] = toupper(ch);
		i++;
	}

	strcpy(postalCode, temp);
	return 0;
}

int centerIsSpace(char * temp)
{
	if (temp[3] == 32)
	{
		return 0;
	}
	return 1;
}


void clearInputBuffer(void)
{
	while (getchar() != '\n')
	{
		;
	}
}

/*
Enter your first name : John
Enter your last name :
Invalid Entry :
Enter your last name : Smith
Enter your street address : 35 Elm St.
Enter your city : Toronto
Enter your province : ON
Enter your postal code : m2e44x
Invalid Entry : Enter your postal code : m2e 4x4

You entere
John Smith
35 Elm St.,
Toronto, ON,
M2E 4X4
*/