/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

// Create the following two Pure virtual functions:
// a pure virtual function is a virtual function that has no implementation. To indicate that the pure virtual function does not have implementation set its prototype to zero (= 0;) in the class declaration.

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
  class Shape
  {
  public:
    // draw
    // Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
    virtual void draw(std::ostream &os) const = 0;

    // getSpecs
    // Returns void and receives a reference to istream as an argument.
    virtual void getSpecs(std::istream &is) = 0;

    // destructor
    virtual ~Shape();
  };
  
  // Shape helper functions
  // Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.
  std::ostream &operator<<(std::ostream &os, const Shape &shape);
  std::istream &operator>>(std::istream &is, Shape &shape);
}

#endif