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
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels < 1)
        {
            cout << "The number of labels must be positive" << endl;
        }
        else
        {
            labelsList = new Label[noOfLabels];
            labelsRequested = noOfLabels;
        }
    }

    LabelMaker::~LabelMaker()
    {
        if (labelsList != nullptr)
        {
            delete[] labelsList;
            labelsList = nullptr;
        }
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << labelsRequested << " labels:" << endl;

        for (int i = 0; i < labelsRequested; i++)
        {
            cout << "Enter label number " << i + 1 << endl;
            labelsList[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < labelsRequested; i++)
        {
            labelsList[i].printLabel();
            cout << endl;
        }
    }
}
