/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

// The Rectangle class inherits the LblShape class to create a frame with a label inside.

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
  class Rectangle : public LblShape
  {
    // Create two member variables called m_width and m_height to hold the width and the height of a rectangular frame (number of characters).
    int m_width;
    int m_height;

  public:
    // Default (no argument) constructor
    Rectangle();

    // Three argument constructor
    Rectangle(const char *label, int width, int height);

    // Destructor
    // This class has no destructor implemented.

    // getSpecs
    // Reads comma-separated specs of the Rectangle from istream.
    // This function overrides the getSpecs function of the base class as follows.
    void getSpecs(std::istream &is);

    // draw
    // This function overrides the draw function of the base class.
    void draw(std::ostream &os) const;
  };
}
#endif