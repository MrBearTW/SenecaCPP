/*/////////////////////////////////////////////////////////////////////////
                                Workshop 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/18

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "ShoppingRec.h"
#include "Utils.h"
using namespace std;

const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;

namespace sdds
{

    ShoppingRec getShoppingRec()
    {
        ShoppingRec R = {};
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH);
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
        return R;
    }

    void displayShoppingRec(const ShoppingRec *shp)
    {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title << " qty:(" << shp->m_quantity << ")" << endl;
    }

    void toggleBoughtFlag(ShoppingRec *rec)
    {
        rec->m_bought = !rec->m_bought;
    }

    bool isShoppingRecEmpty(const ShoppingRec *shp)
    {
        return shp->m_title[0] == 0;
    }

}