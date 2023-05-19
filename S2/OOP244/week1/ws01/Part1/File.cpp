/*/////////////////////////////////////////////////////////////////////////
                                Workshop 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/18

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "File.h"
#include "ShoppingRec.h"
using namespace std;

FILE *sfptr = nullptr;

namespace sdds
{
    const char *const SHOPPING_DATA_FILE = "shoppinglist.csv";
    

    bool openFileForRead()
    {
        sfptr = fopen(SHOPPING_DATA_FILE, "r");
        return sfptr != NULL;
    }

    bool openFileForOverwrite()
    {
        sfptr = fopen(SHOPPING_DATA_FILE, "w");
        return sfptr != NULL;
    }

    void closeFile()
    {
        if (sfptr)
            fclose(sfptr);
    }

    bool freadShoppingRec(ShoppingRec *rec)
    {
        int flag = 0;
        bool success = fscanf(sfptr, "%[^,],%d,%d\n",
                              rec->m_title, &rec->m_quantity, &flag) == 3;
        rec->m_bought = !!flag;
        return success;
    }

    void fwriteShoppintRec(const ShoppingRec *rec)
    {
        fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
    }

}