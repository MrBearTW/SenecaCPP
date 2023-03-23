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

// ----------------------------------------------------------------------------
// defines/macros
#ifndef MAX_NUM_PRODUCT MAX_NUM_PRODUCT LBSKG LBSG LBS

#define MAX_NUM_PRODUCT 3
#define SERVING_GRAMS 64
#define LBSKG 2.20462
#define LBSG 2494
#define LBS 5.5

#endif

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int caloriesPerServing;
    double productWeight;
};

struct ReportData
{
    int productSku;
    double productPrice;
    int caloriesPerServing;
    double productWeightPounds;
    double productWeightKilograms;
    int productWeightGrams;
    double totalServings;
    double costPerServing;
    double costCaloriesPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *testInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *testDouble);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberNeedEntering);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int catFoodNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const double *productWeight, const int caloriesPerServing);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *poundsToBeConvertedKg, double *conversionResultKg);

// 9. convert lbs: g
int convertLbsG(const double *poundsToBeConvertedG, int *conversionResultG);

// 10. convert lbs: kg / g
void convertLbs(const double *poundsToBeConverted, double *conversionResultKg, int *conversionResultG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *productPrice, const double *totalNumberOfServings, double *costPerCalorie);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *productPrice, const double *totalNumberOfCalories, double *costPerCalorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestProduct);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo);
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
