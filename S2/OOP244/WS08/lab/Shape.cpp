/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Shape.h"

namespace sdds
{
  // destructor
  // Create a virtual empty destructor for the shape interface.
  // this guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer will be removed properly from memory when deleted.
  Shape::~Shape()
  {
    
  }

  // Shape helper functions
  // Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.
  std::ostream &operator<<(std::ostream &os, const Shape &shape)
  {
    shape.draw(os);
    return os;
  }

  std::istream &operator>>(std::istream &is, Shape &shape)
  {
    shape.getSpecs(is);
    return is;
  }
}