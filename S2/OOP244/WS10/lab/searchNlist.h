/*/////////////////////////////////////////////////////////////////////////
                            Workshop 10 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/08/04

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace sdds
{
    // search function template
    // Create a function template called search that accepts four arguments in any order you prefer:
    // 1. A reference to a Collection of templated objects (template type 1). The Collection is defined in Collection.h
    // 2. An array of templated objects; the same type as the Collection type. (template type 1)
    // 3. Number of elements in the array of objects
    // 4. A key templated value to search for, in the array of objects. (template type 2)
    template <typename T, typename K>
    bool search(Collection<T> &collection, T *array, int size, K key)
    {
        // The search function template returns a bool that is true only if at least one match to the key is found in the array of objects and false otherwise.
        bool found = false;

        // The search function goes through all the elements of the array of objects and adds all the matches found to the Collection. (use the "==" operator to check for a match between the objects and the key)
        for (int i = 0; i < size; i++)
        {
            if (array[i] == key)
            {
                collection.add(array[i]);
                found = true;
            }
        }
        return found;
    }

    // listArrayElements
    // Lists all the elements of an array.
    // Create a function template called listArrayElements that accepts three arguments in any order you prefer:
    // 1. A const char* for a Title to be printed as the Title of the list.
    // 2. A constant array of templated objects (template type)
    // 3. The number of the elements of the array.
    template <typename T>
    void listArrayElements(const char *title, const T *array, int size)
    {
        // This function first prints the Title and then goes to newline.
        cout << title << endl;

        // Then it will print the row number and then insert each element of the array into cout with a newline attached.
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ": " << array[i] << endl;
        }
    }

    // Have a comment section for both functions and explain what requirements each of types of your templates must have to be able to work with your logic.
    // Then also copy these comments to the part 2 reflection of the workshop.

    // Ans:

    // For search function template:
    // 1. Firs I need to understand the Collection class template in Collection.h file.
    // 2. Then understand the Collection class relationship with the Car, Student, and Employee classes.
    // 3. Understand why need 2 template types for this function template. (template type 1 and template type 2)  Because search arguments(Key) may be different types.
    // 4. Then create the function arguments using the Collection class template.
    // 5. Then create the function body using the "==" operator to check for a match between the objects and the key.
    // 6. Then use the "add" function of the Collection class to add the matched objects to the Collection object (templated objects).

    // For listArrayElements function template:
    // 1. Observing how this function is used in main.cpp and observe the output.
    // 2. Following the instruction to create the function arguments
    // 3. Then create the function body to print the Title and then go to newline.
    // 4. Then print the row number and then insert each element of the array into cout with a newline attached.
}
#endif // !SDDS_SEARCHNLIST_H_