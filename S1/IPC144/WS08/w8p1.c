/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *testInt)
{
	int input = -1;
	do
	{
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	// only if it is NOT NULL
	if (testInt != NULL)
	{
		*testInt = input;
	}
	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *testDouble)
{
	double input = -1;
	do
	{
		scanf("%lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	// only if it is NOT NULL
	if (testDouble != NULL)
	{
		*testDouble = input;
	}
	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberNeedEntering)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n", SERVING_GRAMS);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int catFoodNum)
{
	struct CatFoodInfo input = {0};
	printf("Cat Food Product #%d\n", catFoodNum+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&input.sku);
	printf("PRICE         : $");
	getDoublePositive(&input.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&input.productWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&input.caloriesPerServing);
	printf("\n");
	return input;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const double *productWeight, const int caloriesPerServing)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *productWeight, caloriesPerServing);
}

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo catFoodInfo[MAX_NUM_PRODUCT] = {{0}};

	openingMessage(MAX_NUM_PRODUCT);

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].productWeight, catFoodInfo[i].caloriesPerServing);
	}
}
