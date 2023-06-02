/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/01

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds
{
    // Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
    void Bill::setEmpty()
    {
        *m_title = '\0';
        m_items = nullptr;
    }

    // Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
    bool Bill::isValid() const
    {
        bool itemIsValid = true;
        for (int i = 0; i < m_noOfItems && itemIsValid; i++)
        {
            if (!m_items[i].isValid())
            {
                itemIsValid = false;
            }
        }
        return itemIsValid;
    }

    // Adds all the taxes of the items using a loop and returns the sum.
    double Bill::totalTax() const
    {
        double totalTax = 0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            totalTax += m_items[i].tax();
        }
        return totalTax;
    }

    // Adds all the prices of the items using a loop and returns the sum;
    double Bill::totalPrice() const
    {
        double totalPrice = 0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    // Prints the title in the following format:
    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title << " |" << endl;
            cout.unsetf(ios::left);
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    // Prints the footer in the following format:
    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax() << " |" << endl;
            cout.unsetf(ios::fixed);

            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::fixed);
            cout << totalPrice() << " |" << endl;
            cout.unsetf(ios::fixed);

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::fixed);
            cout << totalTax() + totalPrice() << " |" << endl;
            cout.unsetf(ios::fixed);
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    // If any of the arguments are invalid, it will set the Bill to an empty state (ie. title is null or noOfItems is zero or less)
    // Otherwise, if the incoming arguments are valid:
    void Bill::init(const char *title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 0)
        {
            setEmpty();
        }
        else
        {
            // init() function will first set the m_noOfItems member variable to the incoming corresponding argument and sets m_itemsAdded to zero.
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            // Next, it will copy the Cstring pointed by the title argument into m_title attribute up to 36 characters
            strnCpy(m_title, title, 36);

            // Then it will dynamically allocate an array of Items pointed by m_items member variable. The length of this array will be m_noOfItems.
            m_items = new Item[noOfItems];

            // Make sure all the dynamically allocated Items are set to empty
            for (int i = 0; i < noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }

    // If the number of added Items (m_itemsAdded) is less than the length of the m_items array, this function will set the next available subject to the incoming argument values. Then it will add one to the m_itemsAdded and return true;
    // Otherwise, this function will do nothing, returning false;
    bool Bill::add(const char *item_name, double price, bool taxed)
    {
        bool addResult = false;

        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            addResult = true;
        }

        return addResult;
    }

    // This function will first print the title(), then it will loop through the m_items elements, printing every one of them, and finally prints the footer(). This function can not modify the Bill.
    void Bill::display() const
    {
        Title();

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    // Deallocates the m_items arrays and sets the pointers to null.
    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}