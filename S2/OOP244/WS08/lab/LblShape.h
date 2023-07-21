/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

// nherit an abstract class from the interface Shape called LblShape. This class adds a label to a Shape.
// This class will implement the pure virtual function getSpecs but will not implement the draw function; therefore it remains abstract.

#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
  class LblShape : public Shape
  {
    // Private Member variable
    // Add a character pointer member variable called m_label and initialize it to null. This member variable will be used to hold the dynamically allocated label for the Shape.
    // char *m_label{nullptr};
    char *m_label;

  protected:
    // label()
    const char *label() const;

  public:
    // Default (no argument) constructor
    LblShape();

    // One argument constructor
    LblShape(const char *label);

    // Destructor
    virtual ~LblShape();

    // deleted actions
    // The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
    LblShape(const LblShape &src) = delete;
    LblShape &operator=(const LblShape &src) = delete;

    // getSpecs
    // Reads a comma-delimited Cstring form istream:
    void getSpecs(std::istream &is);
  };
}
#endif