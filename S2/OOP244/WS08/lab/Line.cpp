/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
  // Default (no argument) constructor
  // Sets the m_length member variable to zero, and invokes the default constructor of the base class.
  Line::Line()
  {
    m_length = 0;
  }

  // Two argument constructor
  // Passes the Cstring to the constructor of the base class and sets the m_length member variable to the value of the second argument.
  Line::Line(const char *label, int length) : LblShape(label)
  {
    // Receives a Cstring and a value for the length of the line.
    if (label != nullptr && label[0] != '\0')
    {
      m_length = length;
    }
  }

  // Destructor
  // This class has no destructor implemented.

  // getSpecs
  // Reads comma-separated specs of the Line from istream.
  // This function overrides the getSpecs function of the base class as follows.
  void Line::getSpecs(std::istream &is)
  {
    // First, it will call the getSpecs function of the base class
    LblShape::getSpecs(is);
    // then it will read the value of the m_length attribute from the istream argument,
    is >> m_length;
    // and then it will ignore The rest of the characters up to and including the newline character '\n'.
    // is.ignore(1000, '\n');
    while (is.get() != '\n') // clear the buffer of old characters
    {
    }
  }

  // draw
  // This function overrides the draw function of the base class.
  // If the m_length member variable is greater than zero and the label() is not null, this function will first print the label() and then go to the new line. Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
  // Otherwise, it will take no action.
  // For example, if the Cstring returned by the label query is "Separator" and the length is 40, the draw function should insert the following into ostream:
  // Separator
  // ========================================
  void Line::draw(std::ostream &os) const
  {
    if (m_length > 0 && label() != nullptr)
    {
      os << label() << endl;
      for (int i = 0; i < m_length; i++)
      {
        os << "=";
      };
    }
  }
}
