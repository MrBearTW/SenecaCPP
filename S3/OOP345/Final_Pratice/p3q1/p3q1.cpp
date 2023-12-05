// Given the following code snippet, complete the tasks listed below:

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts
{
    string partType;
    string model;
    double price;
    double powerConsumption;
    bool used;
};

int main()
{

    vector<ComputerParts> wishList;
}

// Task 1. Add to the wishLish some number of desired Computer Parts

// Eg. GPU, RTX 3080, 1000, 300, false

// Task 2. Sort the wishList by price in ascending order

// Task 3. Print to the screen the part in the wishList the part that has the most and least powerConsumption

// Task 4. Remove from the wishList all the parts that are 'used'

// Task 5. Find the average cost of all the parts in the wishList

// Task 6. Change all the items in the wishList to 'used' and reduce their price by 20% and save this result to a new vector

// Task 7. Figure out how many of a given part type is in the wishList eg. how many CPUs and print to the screen

// Task 8. Create new wishList of computer parts and add parts to it. Combine it with the original wishList