#include "Streamable.h"

namespace sdds
{
    // destructor
    // Add an empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak.
    Streamable::~Streamable(){

    };

    // Insertion operator overload
    std::ostream &operator<<(std::ostream &os, const Streamable &obj)
    {
        // Overload the insertion operator so a constant object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state. Otherwise, the function will quietly ignore the insertion action.
        if (obj)
        {
            obj.write(os);
        }
        return os;
    }

    // Extraction operator overload
    std::istream &operator>>(std::istream &is, Streamable &obj)
    {
        // Overload the extraction operator so an object of type Streamable can be read from an istream object.
        return obj.read(is);
    }
}