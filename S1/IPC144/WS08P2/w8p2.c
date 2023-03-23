/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	printf("Cat Food Product #%d\n", catFoodNum + 1);
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *poundsToBeConvertedKg, double *conversionResultKg)
{
	double convertedKg = 0;

	convertedKg = (*poundsToBeConvertedKg) / LBSKG;
	if (conversionResultKg != NULL)
	{
		*conversionResultKg = convertedKg; 
	}

	return convertedKg;
	
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *poundsToBeConvertedG, int *conversionResultG)
{
	int convertedG = 0;
	double *conversionResultKg = NULL;

	convertedG = convertLbsKg(poundsToBeConvertedG, conversionResultKg) * 1000;
	if (conversionResultG != NULL)
	{
		*conversionResultG = convertedG;
	}

	return convertedG;
}

// 10. convert lbs: kg and g
void convertLbs(const double *poundsToBeConverted, double *conversionResultKg, int *conversionResultG)
{
	convertLbsKg(poundsToBeConverted, conversionResultKg);
	convertLbsG(poundsToBeConverted, conversionResultG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberServings)
{
	if (numberServings != NULL)
	{
		*numberServings = (double)totalGrams / servingSizeGrams;
	}
	return *numberServings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *productPrice, const double *totalNumberOfServings, double *costPerServing)
{
	if (costPerServing != NULL)
	{
		*costPerServing = (*productPrice) / (*totalNumberOfServings);
	}
	return *costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *productPrice, const double *totalNumberOfCalories, double *costPerCalorie)
{
	if (costPerCalorie != NULL)
	{
		*costPerCalorie = *productPrice / *totalNumberOfCalories;
	}

	return *costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo)
{
	struct ReportData data = {0};
	double totalNumberOfCalories = 0;

	// directly assigned
	data.productSku = catFoodInfo.sku;
	data.productPrice = catFoodInfo.price;
	data.caloriesPerServing = catFoodInfo.caloriesPerServing;
	data.productWeightPounds = catFoodInfo.productWeight;

	// Lb to Kg and G
	convertLbs(&data.productWeightPounds, &data.productWeightKilograms, &data.productWeightGrams);

	// Servings
	calculateServings(SERVING_GRAMS, data.productWeightGrams, &data.totalServings);

	// $/Serv
	calculateCostPerServing(&data.productPrice, &data.totalServings, &data.costPerServing);
	// $/Cal
	totalNumberOfCalories = (data.totalServings) * (data.caloriesPerServing);
	calculateCostPerCal(&data.productPrice, &totalNumberOfCalories, &data.costCaloriesPerServing);

	return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SERVING_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData.productSku, reportData.productPrice, reportData.productWeightPounds, reportData.productWeightKilograms, reportData.productWeightGrams, reportData.caloriesPerServing, reportData.totalServings, reportData.costPerServing, reportData.costCaloriesPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", catFoodInfo.sku, catFoodInfo.price);
	printf("\n");
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFoodInfo[MAX_NUM_PRODUCT] = {{0}};
	struct ReportData reportData[MAX_NUM_PRODUCT] = {{0}};
	int i = 0, cheapestIndex = 0;
	double cheapestPrice = 0;

	openingMessage(MAX_NUM_PRODUCT);

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i);
		reportData[i] = calculateReportData(catFoodInfo[i]); // Calculate report
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].productWeight, catFoodInfo[i].caloriesPerServing);
	}
	printf("\n");

	// ----------------------------------------------------------------------------
	// PART-2

	// Find cheapest
	cheapestPrice = reportData[0].costCaloriesPerServing;

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		if (reportData[i].costCaloriesPerServing <= cheapestPrice)
		{
			cheapestPrice = reportData[i].costCaloriesPerServing;
			cheapestIndex = i;
		}
	}

	// Displaying report
	displayReportHeader();

	for (i = 0; i < MAX_NUM_PRODUCT; i++)
	{
		displayReportData(reportData[i], cheapestIndex);

		i == cheapestIndex ? printf(" ***\n") : printf("\n");
	}
	printf("\n");

	// Displaying ending
	displayFinalAnalysis(catFoodInfo[cheapestIndex]);
}
