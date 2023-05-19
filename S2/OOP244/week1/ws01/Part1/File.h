/*/////////////////////////////////////////////////////////////////////////
                                Workshop 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/18

/////////////////////////////////////////////////////////////////////////*/

#ifndef FILE_H // replace with relevant names
#define FILE_H
#include "ShoppingRec.h"

// Your header file content goes here
namespace sdds
{
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec *rec);
    void fwriteShoppintRec(const ShoppingRec *rec);
}
#endif