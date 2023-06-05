#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 25
struct FactorialResults
{
    unsigned long long results[MAX_FACTORIALS];
    int numResults;
};
unsigned long long factorial(const int n)
{
    //printf("In factorial = %d\n",n);  // Print
    return (n > 1) ? n * factorial(n - 1) : 1;
}
int reduceFactorial(const int n)
{
    return n / n;
}
void computeFactorials(struct FactorialResults* results, int numFactorials)
{
    int i;
    for (i = 0; i < numFactorials; i++)
    {
        results->results[i] = factorial(i);
        // printf("In computeFactorials = %d\n",results.results[i]);  // Print
    }
    results->numResults = numFactorials;
    // printf("results.numResults = %d\n",results.numResults);  // Print
}
int main(void)
{
    struct FactorialResults results = {{0}, 0};
    int i;
    computeFactorials(&results, NUM_FACTS);
    
    for (i = 0; i < NUM_FACTS; i++)
    {
        //results.results[i] = reduceFactorial(results.results[i]);
        printf("%5d %25llu\n", i, results.results[i]);
    }
    return 0;
}

// int 2147483647
// unsigned long long 18446744073709551615