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

#ifndef MAX_NUM_PRODUCT SERVING_GRAMS

#define MAX_NUM_PRODUCT 3
#define SERVING_GRAMS 64

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

// ----------------------------------------------------------------------------
// function prototypes

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

// 7. Logic entry point
void start(void);
