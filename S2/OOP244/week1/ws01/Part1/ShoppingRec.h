/*/////////////////////////////////////////////////////////////////////////
                                Workshop 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/18

/////////////////////////////////////////////////////////////////////////*/

#ifndef SHOPPING_REC_LIST_H // replace with relevant names
#define SHOPPING_REC_LIST_H

namespace sdds
{
    const int MAX_TITLE_LENGTH = 50;
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    // Your header file content goes here
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec *shp);
    void toggleBoughtFlag(ShoppingRec *rec);
    bool isShoppingRecEmpty(const ShoppingRec *shp);
}
#endif