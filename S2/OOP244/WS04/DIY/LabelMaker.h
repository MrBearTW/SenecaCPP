/*/////////////////////////////////////////////////////////////////////////
                            Workshop 4 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/13

/////////////////////////////////////////////////////////////////////////*/

// The LabelMaker Module
// The LabelMaker class creates a dynamic array of Labels and gets their content from the user one by one and prints them all at once.

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds
{
    class LabelMaker
    {
    private:
        Label *labelsList;
        int labelsRequested;

    public:
        // creates a dynamic array of Labels to the size of noOfLabels
        LabelMaker(int noOfLabels);

        // Deallocates the memory when LabelMaker goes out of scope.
        ~LabelMaker();

        // Gets the contents of the Labels as demonstrated in the Execution sample
        void readLabels();

        // Prints the Labels as demonstrated in the Execution sample
        void printLabels();
    };
} // namespace sdds

#endif // !SDDS_LABELMAKER_H