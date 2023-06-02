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
#include "Item.h"
using namespace std;
namespace sdds
{
    void Item::setName(const char *name)
    {
        strnCpy(m_itemName, name, 20);
    }

    // Public
    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char *name, double price, bool taxed)
    {
        if (price > 0 && name != '\0')
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
        else
        {
            setEmpty();
        }
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        double tax = 0;
        if (m_taxed)
        {
            tax = price();
            return tax * TAXRATE;
        }
        else
        {
            return tax;
        }
    }
    bool Item::isValid() const
    {
        return (m_price > 0 && *m_itemName != '\0') ? true : false;
    }
    void Item::display() const
    {
        if (isValid())
        {
            // name
            char pad = cout.fill('.');        
            cout << "| ";
            cout.setf(ios::left);
            cout.width(20);
            cout << m_itemName;
            cout.fill(pad);
            cout.unsetf(ios::left);

            // price
            cout << " | ";
            cout.width(7);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::fixed);
            
            // tax
            if (m_taxed)
            {
                cout << " | Yes |" << endl;
            }
            else
            {
                cout << " | No  |" << endl;
            }
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
}