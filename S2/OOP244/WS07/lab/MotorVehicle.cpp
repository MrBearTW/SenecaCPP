/*/////////////////////////////////////////////////////////////////////////
                            Workshop 7 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/13

/////////////////////////////////////////////////////////////////////////*/

/*
Design and code a class named MotorVehicle that holds information about a vehicle with an engine. Place your class definition in a header file named MotorVehicle.h and your function definitions in an implementation file named MotorVehicle.cpp.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the sdds namespace.
*/

#include "MotorVehicle.h"
#include "cstring.h"
#include <iostream>
using namespace std;

namespace sdds
{
    // MotorVehicle Public Members
    // a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. Set the location of the vehicle at Factory. Assume all data is valid.
    MotorVehicle::MotorVehicle(const char *license, int year, const char *address)
    {
        if (license != nullptr && license[0] != '\0' && year > 0 && address != nullptr && address[0] != '\0')
        {
            strCpy(m_license, license);
            strCpy(m_address, address);
            m_year = year;
        }
        else
        {
            m_license[0] = '\0';
            m_address[0] = '\0';
            m_year = 0;
        }
    }

    // void moveTo(const char* address): moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message

    void MotorVehicle::moveTo(const char *address)
    {
        if (address != nullptr && address[0] != '\0' && strCmp(m_address, address) != 0)
        {
            // [LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
            // where
            // the license plate is a field of 8 characters aligned to the right
            // current address is a field of 20 characters aligned to the right
            // new address is a field of 20 characters aligned to left
            cout << "|";
            cout.width(8);
            cout << right << m_license << "| |";
            cout.width(20);
            cout << right << m_address << " ---> ";
            cout.width(20);
            cout << left << address << "|" << endl;

            strCpy(m_address, address);
        }
    }

    // ostream& write(ostream& os): a query that inserts into os the content of the object in the format
    // | [YEAR] | [PLATE] | [ADDRESS]
    std::ostream &MotorVehicle::write(std::ostream &os) const
    {
        os << "| ";
        os.width(4);
        os << left << m_year << " | ";
        os << right << m_license << " | ";
        os << left << m_address;
        return os;
    }

    // istream& read(istream& in): a mutator that reads from the stream in the data for the current object
    /*
    Built year: [USER TYPES HERE]
    License plate: [USER TYPES HERE]
    Current location: [USER TYPES HERE]
    Capacity: [USER TYPES HERE]
    Cargo: [USER TYPES HERE]
    */
    std::istream &MotorVehicle::read(std::istream &in)
    {
        cout << "Built year: ";
        in >> m_year;
        cout << "License plate: ";
        in >> m_license;
        cout << "Current location: ";
        in >> m_address;
        return in;
    }

    // Helper Functions
    // overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream. These operators should call the write/read member functions in the class MotorVehicle.
    std::ostream &operator<<(std::ostream &os, const MotorVehicle &vehicle)
    {
        return vehicle.write(os);
    }
    
    std::istream &operator>>(std::istream &in, MotorVehicle &vehicle)
    {
        return vehicle.read(in);
    }
}