/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/06

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "CalorieList.h"
#include "Food.h"

using namespace std;

namespace sdds
{
    CalorieList::CalorieList()
    {
        cl_food = nullptr;
        cl_noOfFood = 0;
        cl_foodAdded = 0;
    }

    CalorieList::~CalorieList()
    {
        if (cl_food != nullptr)
        {
            delete[] cl_food;
            cl_food = nullptr;
        }
    };

    void CalorieList::init(int size)
    {
        cl_food = nullptr;
        cl_noOfFood = size;
        cl_foodAdded = 0;
        cl_food = new Food[size];
    }

    bool CalorieList::add(const char *item_name, int calories, int when)
    {
        if (cl_foodAdded < cl_noOfFood)
        {
            cl_food[cl_foodAdded].setFoodData(item_name, calories, when);
            cl_foodAdded++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool CalorieList::isValid() const
    {
        if (cl_food == nullptr)
        {
            return false;
        }
        for (int i = 0; i < cl_noOfFood; i++)
        {
            if (!cl_food[i].isValid())
            {
                return false;
            }
        }
        return true;
    }

    int CalorieList::totalCalories() const
    {
        int totalCal = 0;
        for (int i = 0; i < cl_noOfFood; i++)
        {
            totalCal += cl_food[i].getCalories();
        }
        return totalCal;
    }
    
    void CalorieList::display() const
    {
        // Title
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

        // Print food row
        int i = 0;
        for (i = 0; i < cl_noOfFood; i++)
        {
            cl_food[i].display();
        }

        // Footer
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << totalCalories() << " |            |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::deallocate()
    {
        delete[] cl_food;
        cl_food = nullptr;
    }
}