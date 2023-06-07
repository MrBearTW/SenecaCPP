/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/06

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds
{
    // The CalorieList class should dynamically hold series of Food items and display them in a report.
    class CalorieList
    {
        Food *cl_food;
        int cl_noOfFood;
        int cl_foodAdded;

        bool isValid() const;
        int totalCalories() const;

    public:
        CalorieList();  // CONSTRUCTORS
        ~CalorieList(); // DESTRUCTORS

        // sets the CalorieList to accept the "size" number of Food Items.
        // This function is called to prepare the CalorieList for accepting food items
        void init(int size);

        // Adds Food Items using their Name, Calorie count and time of consumption up to
        // the number set in the init() function, returns true if successful.
        bool add(const char *item_name, int calories, int when);

        // Displays the report with food information and the total calorie consumed in the day
        // as shown in the report sample
        void display() const;

        // Releases all the memory used. After this function init() can be called for another
        // report;
        void deallocate();
    };
}
#endif
