#include "Menu.h"
#include "Utils.h"
#include <cstring>

namespace sdds
{
    // -------------------- class MenuItem --------------------
    void MenuItem::setEmpty()
    {
        delete[] menuContent;
        menuContent = nullptr;
    }

    // Constructor

    // Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization). If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.
    MenuItem::MenuItem(const char *textContent)
    {
        if (textContent != nullptr && textContent[0] != '\0')
        {
            menuContent = new char[strlen(textContent) + 1];
            strcpy(menuContent, textContent);
        }
        else
        {
            setEmpty();
        }
    }

    // Rule of Three
    // A MenuItem object cannot be copied from or assigned to another MenuItem object.
    // (Copy constructor and Copy assignment are deleted)

    // Destructor
    // Deallocates the content
    MenuItem::~MenuItem()
    {
        delete[] menuContent;
        menuContent = nullptr;
    }

    // bool type conversion
    // When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.
    MenuItem::operator bool() const
    {
        return menuContent != nullptr && menuContent[0] != '\0';
    }

    // const char* type conversion
    // When a MenuItem is casted to “const char*” it should return the address of the content Cstring.
    MenuItem::operator const char *() const
    {
        return menuContent;
    }

    // displaying the MenuItem
    // Create a method to display the content of the MenuItem on ostream. (No newline is printed after)
    // Nothing is printed if MenuItem is empty.
    // Remember that the MenuItem class is fully private.
    std::ostream &MenuItem::display(std::ostream &os)
    {
        // if (menuContent != nullptr && menuContent[0] != '\0')
        if (*this)
        {
            os << menuContent;
        }
        return os;
    }

    // -------------------- class Menu --------------------

    // Constructor
    // A Menu is always created empty; with no MenuItems, with or without a title.
    // Example:
    // Menu A;
    // Menu B("Lunch Menu");
    Menu::Menu()
    {
        menuItems[0] = nullptr;
        pointerCount = 0;
    };

    // Constructor with title

    //  Menu::Menu(const char *title): menuTitle(title)
    Menu::Menu(const char *title)
    {
        menuTitle.menuContent = new char[strlen(title) + 1];
        menuTitle.menuContent = strcpy(menuTitle.menuContent, title);
        menuItems[0] = nullptr;
        pointerCount = 0;
    };

    // ref: https://github.com/AryanK1511/Seneca-college-OOP244-Workshops-and-Labs/blob/main/Final_Project/MS1/Menu.cpp
    // Menu::Menu(const char *title) : menuTitle(title)
    // {
    //     pointerCount = 0;
    // };

    // Rule of Three
    // A Menu Object can not be copied or assigned to another Menu Object. (Copy constructor and Copy assignment are deleted)

    // Destructor
    // Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.
    Menu::~Menu()
    {
        // menuTitle is not pointer
        // // delete[] menuTitle;
        // // menuTitle = nullptr;
        // When object is out of scope, menuTitle will be deleted automatically (no need to delete it manually)

        for (unsigned int i = 0; i < pointerCount; i++)
        {
            delete menuItems[i];
            menuItems[i] = nullptr;
        }
    }

    // Suggestion: create a function to display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.
    std::ostream &Menu::displayMenuTitle(std::ostream &os)
    {
        if (menuTitle)
        {
            menuTitle.display(os);
        }
        return os;
    }

    // Create a function to display the entire Menu on ostream:
    // This function first displays the title (if it is not empty) followed by a ":" and a new-line, then it will display all the MenuItems one by one; adding a row number in front of each. The row numbers are printed in two spaces, right justified followed by a "dash" and a "space". After printing all the MenuItems it should print " 0- Exit" and new-line and "> ".
    // For example if the title is "Lunch Menu" and the menu items are "Omelet", "Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:
    // Lunch Menu:
    //  1- Omelet
    //  2- Tuna Sandwich
    //  3- California Rolls
    //  0- Exit
    //  >
    std::ostream &Menu::displayMenu(std::ostream &os)
    {
        if (menuTitle)
        {
            menuTitle.display(os);
            os << "" << std::endl;
        }
        for (unsigned int i = 0; i < pointerCount; i++)
        {
            os << " " << i + 1 << "- ";
            menuItems[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";
        return os;
    }

    // Create a member function called run. This function displays the Menu and gets the user selection.
    // (this function should be completely foolproof) The function receives nothing and returns an unsigned integer (That is the user’s selection). After displaying the menu, ask for an integer and make sure the value of the integer is between 0 and the number of the menu items. If the user enters anything incorrect, print:
    // "Invalid Selection, try again: "
    // and get the integer again until a valid selection is made.
    // Nice to do:
    // The action of a foolproof integer entry within limits, with a prompt and an error message is a good candidate for a separate function implementation in the Utils module
    int Menu::run()
    {
        unsigned int user_input;
        displayMenu();

        bool validInt = false;

        // Check if the input is valid (integer between 0 and the number of the menu items)
        while (validInt == false)
        {
            cin >> user_input;
            if (!cin || user_input < 0 || user_input > pointerCount)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear();
                while (cin.get() != '\n') // clear the buffer of old characters
                {
                }
                validInt = false;
            }
            else
            {
                validInt = true;
            }
        }

        return user_input;
    }

    // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
    int Menu::operator~()
    {
        return run();
    }

    // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
    // This operator receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).
    // To accomplish this, check if the next spot for a MenuItem is available in the array of MenuItem pointers. If it is, dynamically create a MenuItem out of the content received through the operator argument and then store the address in the available spot and finally increase the number of allocated MenuItem pointers by one.
    // If no spot is available, ( that is; if number of allocated MenuItem pointers is equal to MAX_MENU_ITEMS) this function silently ignores the action.
    // At the end, return the reference of the Menu object.
    // Usage example:
    // int a;
    // Menu M;
    // M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    // a = M.run()
    // cout << "Your selection " << a << endl;
    // output:
    //  1- Omelet
    //  2- Tuna Sandwich
    //  3- California Rolls
    //  0- Exit
    //  > 3 <ENTER>
    // Your selection 3
    Menu &Menu::operator<<(const char *menuitemContent)
    {
        if (pointerCount < MAX_MENU_ITEMS)
        {
            MenuItem *newMenuItem = new MenuItem(menuitemContent);
            menuItems[pointerCount] = newMenuItem;
            pointerCount++;
        }

        return *this;
    }

    // Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
    Menu::operator int()
    {
        return pointerCount;
    }

    Menu::operator unsigned int()
    {
        return pointerCount;
    }

    // Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
    Menu::operator bool()
    {
        return pointerCount > 0;
    }

    // Overload the insertion operator to print the title of the Menu using cout.
    // Example for the last three overloads:
    // Menu M ("Lunch Menu");
    // M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    // if (M) { // bool conversion
    //   cout << "The " << M << " is not empty and has "      //  insertion operator overload
    //         << unsigned int(M) << " menu items." << endl;  //  const int conversion (int conversion not tested)
    // }
    // Output:
    // The Lunch Menu is not empty and has 3 menu items.
    std::ostream &operator<<(std::ostream &os, Menu &menu)
    {
        return (menu.displayMenuTitle(os));
    }

    // Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers. If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)
    // Example:
    // Menu M;
    // M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    // cout << M[0] << endl;
    // cout << M[1] << endl;
    // cout << M[3] << endl; // << note that the last valid index is "2"
    // The above code snippet will print the following:
    // Omelet
    // Tuna Sandwich
    // Omelet
    const char *Menu::operator[](unsigned int index) const
    {
        if (index > pointerCount)
        {
            return menuItems[index %= pointerCount]->menuContent;
        }
        else
        {
            return menuItems[index]->menuContent;
        }
    }

    // ref: https://github.com/AryanK1511/Seneca-college-OOP244-Workshops-and-Labs/blob/main/Final_Project/MS1/Menu.cpp
    // int getIntegerInput(int minRange, int maxRange)
    // {
    //     int input;
    //     bool validInt = false;
    //     while (validInt == false)
    //     {
    //         cin >> input;
    //         if (!cin || input < minRange || input > maxRange)
    //         {
    //             std::cout << "Invalid Selection, try again: ";
    //             cin.clear();
    //             while (cin.get() != '\n') // clear the buffer of old characters
    //             {
    //             }
    //             validInt = false;
    //         }
    //         else
    //         {
    //             validInt = true;
    //         }
    //     }
    //     return input;
    // }
}