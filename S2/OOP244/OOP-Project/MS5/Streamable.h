#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

// Create an Interface called Streamable to enforce implementation of the following methods. Any class inherited from Streamable will have the capability to be inserted into or extracted from a stream.

namespace sdds
{

    class Streamable
    {
    public:
        // -------------------- pure virtual function --------------------
        // write pure virtual function
        // This method is not capable of modifying the Streamable object. write receives and returns a reference of an ostream object.
        // Functions overriding this function will write into an ostream object.
        virtual std::ostream &write(std::ostream &os) const = 0;

        // read pure virtual function
        // read receives and returns a reference of an istream object.
        // Functions overriding this function will read from an istream object.
        virtual std::istream &read(std::istream &is) = 0;

        // conIO
        // This method is not capable of modifying the Streamable object. conIo receives a reference of an ios object and returns a Boolean.
        // Functions overriding this function will determine if the incoming ios object is a console IO object or not.
        virtual bool conIO(std::ios &io) const = 0;

        // Boolean conversion operator overload (pure virtual)
        // Boolean conversion overloads of this method will return if the Streamable object is in a valid state or not.
        virtual operator bool() const = 0;

        // destructor

        virtual ~Streamable();
    };

    // Insertion operator overload
    std::ostream &operator<<(std::ostream &os, const Streamable &obj);

    // Extraction operator overload
    std::istream &operator>>(std::istream &is, Streamable &obj);

}
#endif // !SDDS_STREAMABLE_H