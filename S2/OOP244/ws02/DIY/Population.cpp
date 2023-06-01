/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/30

/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"
using namespace std;

namespace sdds
{
    int noOfPostcode;
    int TotalPopulation;
    PCpopulations *pcp = nullptr;

    void sort()
    {
        PCpopulations temp = {0};
        for (int i = noOfPostcode - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (pcp[j].population > pcp[j + 1].population)
                {
                    temp = pcp[j];
                    pcp[j] = pcp[j + 1];
                    pcp[j + 1] = temp;
                }
            }
        }
    }

    // Load one row from the file
    bool load(PCpopulations &pcpRow)
    {
        bool check = false;
        char postcode[7] = {0};

        if (read(postcode) && read(pcpRow.population)) // read(char *postcode); // read(int &population);
        {
            pcpRow.postcode = new char[strLen(postcode) + 1];
            strCpy(pcpRow.postcode, postcode);
            check = true;
        }

        return check;
    }

    // Loads data from a file, and returns true if data was successfully loaded, false otherwise. This function receives as a parameter the name of the file
    bool load(const char filename[])
    {
        bool check = false;
        int loadSuccessNo = 0;
        if (openFile(filename))
        {
            noOfPostcode = noOfRecords(); // number of record

            pcp = new PCpopulations[noOfPostcode];

            for (int i = 0; i < noOfPostcode; i++)
            {
                load(pcp[i]) == 1 ? loadSuccessNo++ : loadSuccessNo = loadSuccessNo + 0;
            }

            // Check "loadSuccessNo" is match "noOfPostcode"
            if (loadSuccessNo != noOfPostcode)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else
            {
                check = true;
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
        }

        return check;
    }

    void display(const PCpopulations &pcp)
    {
        cout << pcp.postcode << ":  " << pcp.population << endl;
    }

    // a function with no parameters that return nothing and prints the report as shown in DIY Execution example.
    void display()
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < noOfPostcode; i++)
        {
            cout << i + 1 << "- ";
            display(pcp[i]);
            TotalPopulation += pcp[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << TotalPopulation << endl;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfPostcode; i++)
        {
            delete[] pcp[i].postcode;
            pcp[i].postcode = nullptr;
        }

        delete[] pcp;
        pcp = nullptr;
    }
}