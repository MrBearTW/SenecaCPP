/*
Create a module called Menu (in files Menu.cpp and Menu.h) this module will hold both MenuItem and Menu Classes’ implementation code.

Since the Menu class owns its MenuItem objects, it must have full control over the MenuItem creation. To implement this, have the declaration of the MenuItem and Menu class in the following sequence:
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
using namespace std;

#define MAX_MENU_ITEMS 20

namespace sdds
{
    // Forward declare the class Menu in the header file.
    class Menu;

    // Implement the MenuItem class declaration (fully private) with Menu class as a friend. (see MenuItem class)
    // Create a class called MenuItem. This class holds only one Cstring of characters for the content of the menu item dynamically. The length of the content is unknown. This class should be fully private (no public members; even constructor is private!):
    class MenuItem
    {
    private:
        char *menuContent{};

        // Constructor
        MenuItem(const char *textContent = nullptr);

        // Rule of Three
        MenuItem(const MenuItem &menuItem) = delete;
        void operator=(const MenuItem &MI) = delete;
        ~MenuItem();

        void setEmpty();

        // bool type conversion
        operator bool() const;

        // const char* type conversion
        operator const char *() const;

        // displaying the MenuItem
        std::ostream &display(std::ostream &os = std::cout);

        // Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
        friend class Menu;
    };

    // Implement the Menu class declaration. (See Menu Class)
    class Menu
    {
    private:
        // A MenuItem to possibly hold the title of the Menu.
        MenuItem menuTitle{};   

        // An array of MenuItem pointers. The size of this array is set by a constant unsigned integer defined in the Menu header file; called MAX_MENU_ITEMS. Have the MAX_MENU_ITEMS integer initialized to 20. This array will keep potential MenuItems added to the Menu. Each individual element of this array will hold the address of a dynamically allocated MenuItem as they are added to the Menu. (See insertion operator overload for Menu)Initialize this array of pointers to nullptrs.
        MenuItem *menuItems[MAX_MENU_ITEMS];  

        // An integer to keep track of how many MenuItem pointers are pointing to dynamic MenuItem objects. (obviously, the value of this variable is always between 0 and MAX_MENU_ITEMS).
        unsigned int pointerCount = 0;

    public:
        Menu();
        Menu(const char *title);

        // Rule of Three
        Menu(const Menu &M) = delete;
        void operator=(const Menu &M) = delete;
        ~Menu();

        std::ostream &displayMenuTitle(std::ostream &os);

        std::ostream &displayMenu(std::ostream &os = std::cout);

        int operator~();

        // // Create a member function called run. This function displays the Menu and gets the user selection.
        int run();

        // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
        Menu &operator<<(const char *menuitemContent);

        // Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
        operator int();
        operator unsigned int();

        // Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
        operator bool();

        // Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
        const char *operator[](unsigned int index) const;
    };
    std::ostream &operator<<(std::ostream &os, Menu &menu);
    // int getIntegerInput(int minRange, int maxRange);

}

#endif