/*/////////////////////////////////////////////////////////////////////////
                            Workshop 7 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/13

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Truck.h"
using namespace std;

namespace sdds
{
    // a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address.
    Truck::Truck(const char *license, int year, double capacity, const char *address) : MotorVehicle(license, year)

    {
        // Call the constructor from the base class and pass the license number and year to it.
        if (capacity > 0)
        {
            // Set the current cargo to 0 and move the truck to the address specified in the last parameter.
            t_capacity = capacity;
            t_cargo = 0;
            if (address != nullptr)
            {
                moveTo(address);
            }
        }
        else
        {
            t_capacity = 0;
            t_cargo = 0;
        }
    }

    // bool addCargo(double cargo): a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. Do not exceed the capacity! If the current load has been changed, return true, otherwise return false.
    bool Truck::addCargo(double cargo)
    {
        if (cargo > 0 && t_cargo < t_capacity)
        {
            t_cargo += cargo;
            if (t_cargo > t_capacity)
            {
                t_cargo = t_capacity;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    // bool unloadCargo(): a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
    bool Truck::unloadCargo()
    {
        if (t_cargo > 0)
        {
            t_cargo = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    // ostream& write(ostream& os): a query that inserts into os the content of the object in the format
    // | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
    ostream &Truck::write(ostream &os) const
    {
        MotorVehicle::write(os);
        os << " | " << t_cargo << "/" << t_capacity;
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
    istream &Truck::read(istream &in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> t_capacity;
        cout << "Cargo: ";
        in >> t_cargo;
        return in;
    }

    // overload the insertion and extraction operators to insert a Truck into a stream and extract a Truck from a stream. These operators should call the write/read member functions in the class Truck.
    ostream &operator<<(ostream &os, const Truck &truck)
    {
        return truck.write(os);
    }

    istream &operator>>(istream &in, Truck &truck)
    {
        return truck.read(in);
    }
}
