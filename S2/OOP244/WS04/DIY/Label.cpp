/*/////////////////////////////////////////////////////////////////////////
                            Workshop 4 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/13

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Label.h"
#include "cstring.h"
using namespace std;

namespace sdds
{

    Label::Label()
    {
        strCpy(frameSymbol, "+-+|+-+|"); // default frame
        oneLineText = nullptr;
    }

    Label::Label(const char *frameArg)
    {
        strCpy(frameSymbol, frameArg);
        oneLineText = nullptr;
    }

    Label::Label(const char *frameArg, const char *content)
    {
        if (strLen(content) < 71)
        {
            strCpy(frameSymbol, frameArg);
            this->oneLineText = new char[strLen(content) + 1];
            strCpy(this->oneLineText, content);
        }
    }

    Label::~Label()
    {
        if (oneLineText != nullptr)
        {
            delete[] oneLineText;
            oneLineText = nullptr;
            frameSymbol[0] = '\0';
        }
    }

    void Label::readLabel()
    {
        char temp[71];

        cout << "> ";
        cin.get(temp, 71, '\n');

        // clear buffer
        cin.ignore(1000, '\n');

        this->oneLineText = new char[strLen(temp) + 1];
        strCpy(this->oneLineText, temp);
    }

    std::ostream &Label::printLabel() const
    {

        if (oneLineText != nullptr)
        {
            int lineLong = strLen(oneLineText);

            cout << frameSymbol[0];
            cout.fill(frameSymbol[1]);
            cout.width(lineLong + 3);
            cout << frameSymbol[2] << endl; 

            cout << frameSymbol[7];
            cout.fill(' ');
            cout.width(lineLong + 3);
            cout << frameSymbol[3] << endl;

            cout << frameSymbol[7] << " " << oneLineText << " " << frameSymbol[3] << endl;

            cout << frameSymbol[7];
            cout.fill(' ');
            cout.width(lineLong + 3);
            cout << frameSymbol[3] << endl;

            cout << frameSymbol[6];
            cout.fill(frameSymbol[5]);
            cout.width(lineLong + 3);
            cout << frameSymbol[4];
        }
        return cout;
    }
}