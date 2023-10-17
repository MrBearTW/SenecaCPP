// main.cpp
#include <iostream>
#include "A.h"
using namespace std;

int main()
{
    int arrI[5]{0, 1, 2, 3, 4, 5};
    cout << process(arrI) << endl;

    A arrA[5]{{1.2}, {2.3}, {3.4}, {4.5}};
    cout << process(arrA) << endl;
}