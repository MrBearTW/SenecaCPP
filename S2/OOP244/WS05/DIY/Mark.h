/*/////////////////////////////////////////////////////////////////////////
                            Workshop 5 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/20

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>
namespace sdds
{
    class Mark
    {
        int m_mark;

    public:
        Mark();
        Mark(int mark);

                                    // Mark m
        operator int() const;       // int(m)      -->     0
        Mark &operator+=(int mark); // m += 20     -->     20
        Mark &operator=(int mark);  // m = 80      -->     80
        operator double() const;    // double(m)   -->     1
        operator char() const;      // char(m)     -->     'A'
    };
                                                        // Mark n(80)
    int operator+=(int &val, const Mark &rightOper);    // val += n    --> 140
}
#endif // !SDDS_MARK_H


/*
Create a Module for a Mark to encapsulate a mark between 0 and 100.

Mark	Grade	Scale 4 mark
0 < = Mark < 50	F	0.0
50 < = Mark < 60	D	1.0
60 < = Mark < 70	C	2.0
70 < = Mark < 80	B	3.0
80 < = Mark < = 100	A	4.0
The class name must be Mark.

⚠️Important: No values are allowed to be kept in mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This condition will not be repeated in during the workshop and applies to all the functions and operators of class Mark
*/