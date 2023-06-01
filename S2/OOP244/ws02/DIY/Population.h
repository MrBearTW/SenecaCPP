/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/30

/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
    struct PCpopulations
    {
        char *postcode;
        int population;
    };

    void sort();

    // Load one row from the file
    bool load(PCpopulations &pcpRow);

    // Loads data from a file, and returns true if data was successfully loaded, false otherwise. This function receives as a parameter the name of the file
    bool load(const char filename[]);

    void display(const PCpopulations &pcp);

    //  function with no parameters that return nothing and prints the report as shown in DIY Execution example.
    void display();

    // a function with no parameters that return nothing and deallocate all dynamic memory used by the program.
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_