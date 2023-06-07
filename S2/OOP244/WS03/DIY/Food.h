/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/06

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#define FOODNAMEMAX 30
namespace sdds
{
    class Food
    {
        char f_name[FOODNAMEMAX + 1]; // Food name; up to 30 characters
        int f_calories;               // Calorie number; valid between 0 and 3000 calories (including 3000).
        int f_consumptionTime;        // Time of consumption; values 1, 2, 3 or 4 (see Meal time and their code)
        void setFoodEmpty();

    public:
        Food();               // CONSTRUCTORS
        ~Food();              // DESTRUCTORS

        void display() const; // Displaying a food item
        void setFoodData(const char *item_name, int calories, const int when);
        bool isValid() const;
        int getCalories() const; // Get calories value
    };
}

#endif