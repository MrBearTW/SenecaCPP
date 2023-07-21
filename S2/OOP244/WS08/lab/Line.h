/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

// Line inherits the LblShape class to create a horizontal line with a label.

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
  class Line : public LblShape
  {
    // Private Member variable
    // Create a member variable called m_length to hold the length of the Line in characters.
    int m_length{0};

  public:
    // Default (no argument) constructor
    Line();

    // Two argument constructor
    Line(const char *label, int length);

    // Destructor
    // This class has no destructor implemented.

    // getSpecs
    // Reads comma-separated specs of the Line from istream.
    // This function overrides the getSpecs function of the base class as follows.
    void getSpecs(std::istream &is);

    // draw
    // This function overrides the draw function of the base class.
    void draw(std::ostream &os) const;
  };
}
#endif