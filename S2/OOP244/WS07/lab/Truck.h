/*/////////////////////////////////////////////////////////////////////////
                            Workshop 7 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/13

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"


/*
The class should be able to store the following data (on top of data coming from the parent class):

a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.
*/

namespace sdds
{
    class Truck : public MotorVehicle
    {
        double t_capacity;
        double t_cargo;
    public:
        // a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address. Call the constructor from the base class and pass the license number and year to it. Set the current cargo to 0 and move the truck to the address specified in the last parameter.
        Truck(const char *plate, int year, double capacity, const char *address);

        // bool addCargo(double cargo): a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. Do not exceed the capacity! If the current load has been changed, return true, otherwise return false.
        bool addCargo(double cargo);

        // bool unloadCargo(): a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
        bool unloadCargo();

        // ostream& write(ostream& os): a query that inserts into os the content of the object in the format
        std::ostream &write(std::ostream &os) const;

        // istream& read(istream& in): a mutator that reads from the stream in the data for the current object
        std::istream &read(std::istream &in);
    };
    // overload the insertion and extraction operators to insert a Truck into a stream and extract a Truck from a stream. These operators should call the write/read member functions in the class Truck.
    std::ostream &operator<<(std::ostream &os, const Truck &truck);
    std::istream &operator>>(std::istream &in, Truck &truck);
}

#endif // !SDDS_TRUCK_H