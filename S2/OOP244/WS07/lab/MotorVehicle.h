/*/////////////////////////////////////////////////////////////////////////
                            Workshop 7 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/13

/////////////////////////////////////////////////////////////////////////*/

/*
MotorVehicle Private Members
The class should be able to store the following data:

a license plate number as a statically allocated array of characters of size 9.
the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
the year when the vehicle was built.
You can add any other private members in the class, as required by your design.
*/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>
using namespace std;

namespace sdds
{
    class MotorVehicle
    {
        char m_license[9];
        char m_address[64];
        int m_year;

    public:
        // MotorVehicle Public Members
        // a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. Set the location of the vehicle at Factory. Assume all data is valid.
        MotorVehicle(const char *license, int year, const char *address = "Factory");

        // void moveTo(const char* address): moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
        void moveTo(const char *address);

        // ostream& write(ostream& os): a query that inserts into os the content of the object in the format
        std::ostream &write(std::ostream &os) const;

        // istream& read(istream& in): a mutator that reads from the stream in the data for the current object
        std::istream &read(std::istream &in);
    };
        
    // Helper Functions
    // overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream. These operators should call the write/read member functions in the class MotorVehicle.
    std::ostream &operator<<(std::ostream &os, const MotorVehicle &vehicle);
    std::istream &operator>>(std::istream &in, MotorVehicle &vehicle);
}
#endif
