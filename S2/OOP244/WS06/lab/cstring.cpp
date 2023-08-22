/*/////////////////////////////////////////////////////////////////////////
                            Workshop 6 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/06

/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h"
using namespace std;

namespace sdds
{
    // Copies the srouce character string into the destination
    void strCpy(char *des, const char *src)
    {
        for (; *src != '\0'; ++src, ++des)
        {
            *des = *src;
        }
        *des = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char *des, const char *src, int len)
    {
        if (len != 0)
        {
            for (; len != 0; len--)
            {
                *des++ = *src++;
            }
        }
    }

    // Compares two C-strings
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char *s1, const char *s2)
    {
        do
        {
            if (*s1 == '\0' || *s2 == '\0')
                return *s1 - *s2;
            s1++;
            s2++;
        } while (*s1 == *s2);
        return *s1 - *s2;
    }

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char *s1, const char *s2, int len)
    {
        if (len == 0)
            return 0;
        for (; len != 0; len--, s1++, s2++)
        {
            if (*s1 != *s2)
            {
                return (*s1 - *s2);
            }
        }
        return 0;
    }

    // returns the lenght of the C-string in characters
    int strLen(const char *s)
    {
        int i;
        for (i = 0; s[i] != '\0'; i++)
            ;
        return i;
    }

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char *strStr(const char *str1, const char *str2)
    {
        const char *result = nullptr;
        bool flag = false;

        while (*str1 && strLen(str1) >= strLen(str2) && !flag)
        {
            if (strnCmp(str1, str2, strLen(str2)) == 0)
            {
                result = str1;
                flag = true;
            }
            str1++;
        }
        return result;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char *des, const char *src)
    {
        strCpy(des + strLen(des), src);
    }
}
