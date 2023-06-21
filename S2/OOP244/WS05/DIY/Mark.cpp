/*/////////////////////////////////////////////////////////////////////////
                            Workshop 5 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/20

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Mark.h"
using namespace std;

namespace sdds
{
    /*
    Construction
    Mark can be created using an integer value (one argument constructor)that sets the value of the mark. If this value is not provided (no-argument constructor), the value of the mark will be zero.

       Mark m, n(25), k(200), p(-10);
       // value of m is 0
       // value of n is 25
       // k is invalid
       // p is invalid
    */
    Mark::Mark()
    {
        m_mark = 0;
    }
    
    Mark::Mark(int mark)
    {
        if (mark >= 0 && mark <= 100)
        {
            m_mark = mark;
        }
        else
        {
            m_mark = -1;
        }
    }

    // ------------------- Operator and conversion overloads -------------------

    /*
    Mark can be casted to an integer (int type). The result would be the value of the mark or zero if the mark is in an invalid state.
      Mark m, n(25), k(200), p(-10);
       cout << int(m) << endl;
       cout << int(n) << endl;
       cout << int(k) << endl;
       cout << int(p) << endl;
    Ouptut:

    0
    25
    0
    0
    */
    Mark::operator int() const
    {
        int mark = 0;
        if (this->m_mark >= 0 && this->m_mark <= 100)
        {
            mark = this->m_mark;
        }
        return mark;
    }

    /*
    An integer can be added to the value of the mark using += operator; if the mark is invalid, the action is omitted. Reference of the mark is returned after the operation.
      Mark m, n(25), k(200);
      cout << int(m += 20) << endl;
      cout << int(n += 20) << endl;
      cout << int(k += 20) << endl;
      cout << int(n += 60) << endl;
    Output:

    20
    45
    0
    0
    */
    Mark &Mark::operator+=(int value)
    {
        if (this->m_mark >= 0 && this->m_mark <= 100)
        {
            this->m_mark += value;
        }else{
            this->m_mark = 0;
        }
        return *this;
    }

    /*
    Mark can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment. Reference of the mark is returned after the operation.
      Mark m, n(25), k(200);
      cout << int(m = 80) << endl;
      cout << int(n = 120) << endl;
      cout << int(k = 70) << endl;
    Output:

    80
    0
    70
    */

    Mark &Mark::operator=(int value)
    {
        if (value >= 0 && value <= 100)
        {
            m_mark = value;
        }
        else
        {
            m_mark = -1;
        }
        return *this;
    }

    /*
    Mark can be casted to a double, the result would be the GPA equivalent of the integer value. See the table of mark values above. Casting an invalid mark will result in a zero value.
       Mark m(50), n(80), k(120);
       cout << double(m) << endl;
       cout << double(n) << endl;
       cout << double(k) << endl;
    Output:

    1
    4
    0
    */
    Mark::operator double() const
    {
        double gpa = 0.0;
        if (m_mark >= 0 && m_mark < 50)
        {
            gpa = 0.0;
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            gpa = 1.0;
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            gpa = 2.0;
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            gpa = 3.0;
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            gpa = 4.0;
        }
        return gpa;
    }

    /*
    Mark can be casted to a character (char type), the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result in an 'X' value.
       Mark m(50), n(80), k(120);
       cout << char(m) << endl;
       cout << char(n) << endl;
       cout << char(k) << endl;
    Output:

    D
    A
    X
    */
    Mark::operator char() const
    {
        char grade = 'X';
        if (m_mark >= 0 && m_mark < 50)
        {
            grade = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            grade = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            grade = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            grade = 'B';
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            grade = 'A';
        }
        return grade;
    }

    /*
    Mark can be added to an integer, returning the integer after the operation. Invalid marks will not add any value to the integer.
       Mark n(80), k(120);
       cout << (val += n) << endl;
       cout << (val += k) << endl;
    Output:

    140
    140
    */

    int operator+=(int &val, const Mark &rightOper)
    {
        int temp = int(rightOper);
        if (temp >= 0 && temp <= 100)
        {
            val += temp;
        }
        return val;
    }
}