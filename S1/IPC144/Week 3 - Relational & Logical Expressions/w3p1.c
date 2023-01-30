/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
 Full Name  :CHI-WEI PERNG
 Student ID#:121967228
 Email      :cperng@myseneca.ca
 Section    :NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const int p1Id = 111, p2Id = 222, p3Id = 111;
    const float  testValue = 330.99, p1Price = 111.49, p2Price = 222.99, p3Price = 334.49;
    const char p1Tax = 'Y', p2Tax = 'N', p3Tax = 'N';
    float avgPrice;
    
    avgPrice = ((int)(((p1Price + p2Price + p3Price)/3*100)+0.5))/100.00;
    
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", p1Id);
    printf("  Taxed: %c\n", p1Tax);
    printf("  Price: $%.4lf\n", p1Price);
    printf("\n");
    printf("Product-2 (ID:%d)\n", p2Id);
    printf("  Taxed: %c\n", p2Tax);
    printf("  Price: $%.4lf\n", p2Price);
    printf("\n");
    printf("Product-3 (ID:%d)\n", p3Id);
    printf("  Taxed: %c\n", p3Tax);
    printf("  Price: $%.4lf\n", p3Price);
    printf("\n");
    printf("The average of all prices is: $%.4lf\n", avgPrice);
    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", p1Tax == 'Y');
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", (p2Tax == 'N') && (p2Tax == 'N'));
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, p3Price < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n",(p3Price > p1Price) && (p2Price > p1Price));
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", p1Price >= (p3Price- p2Price), p3Price - p2Price);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", p2Price >= avgPrice);
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n", (p1Id != p2Id) && (p1Id != p3Id));
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n", (p2Id != p1Id) && (p2Id != p3Id));
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n", (p3Id != p1Id) && (p3Id != p2Id));
    
    return 0;
}