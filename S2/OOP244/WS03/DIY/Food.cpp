/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/06

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds
{
    Food::Food()
    {
        f_name[0] = '\0';
        f_calories = 0;
        f_consumptionTime = 0;
    }

    Food::~Food() {}

    void Food::setFoodEmpty()
    {
        f_name[0] = '\0';
        f_calories = 0;
        f_consumptionTime = 0;
    }

    void Food::setFoodData(const char *item_name, int calories, const int when)
    {
        if (item_name == nullptr || calories <= 0 || (when < 1 || when > 4))
        {
            setFoodEmpty();
        }
        else
        {
            strnCpy(f_name, item_name, FOODNAMEMAX);
            if (strLen(item_name) >= FOODNAMEMAX)
            {
                f_name[FOODNAMEMAX] = '\0';
            }
            else
            {
                f_name[strLen(item_name)] = '\0';
            }
            f_calories = calories;
            f_consumptionTime = when;
        }
    }

    bool Food::isValid() const
    {
        return (f_name[0] != '\0' || f_calories != 0 || (f_consumptionTime >= 1 && f_consumptionTime <= 4));
    }

    int Food::getCalories() const
    {
        return f_calories;
    }

    void Food::display() const
    {
        if (isValid())
        {
            // m_name
            char pad = cout.fill('.');
            cout << "| ";
            cout.setf(ios::left);
            cout.width(30);
            cout << f_name;
            cout.fill(pad);
            cout.unsetf(ios::left);

            // f_calories
            cout << " | ";
            cout.width(4);
            cout << f_calories;

            // f_consumptionTime
            cout << " | ";
            cout.setf(ios::left);
            cout.width(11);
            switch (f_consumptionTime)
            {
            case 1:
                cout << "Breakfast";
                break;
            case 2:
                cout << "Lunch";
                break;
            case 3:
                cout << "Dinner";
                break;
            case 4:
                cout << "Snack";
                break;
            }
            cout << "|" << endl;
            cout.unsetf(ios::left);
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }
}
