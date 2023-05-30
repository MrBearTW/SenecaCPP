/*/////////////////////////////////////////////////////////////////////////
                                Workshop 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/18

/////////////////////////////////////////////////////////////////////////*/

#ifndef UTILS_LIST_H // replace with relevant names
#define UTILS_LIST_H

// Your header file content goes here
namespace sdds
{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif