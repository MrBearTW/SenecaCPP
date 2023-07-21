/*/////////////////////////////////////////////////////////////////////////
                            Workshop 8 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/20

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
  // Default (no argument) constructor
  // Sets the width and height member variables to zero. It will also invoke the default constructor of the base class.
  Rectangle::Rectangle() : LblShape()
  {
    m_width = 0;
    m_height = 0;
  }

  // Three argument constructor
  // Receives a Cstring for the label, and two values for the width and height of the Rectangle from the argument list.
  Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label)
  {
    // Passes the Cstring to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values received from the argument list.
    // However if the m_height is less than 3 or m_width is less the length of the label() + 2
    if (width >= (int)strlen(LblShape::label()) + 2 && height >= 3)
    {
      m_width = width;
      m_height = height;
    }
    else
    {
      // it will set the Rectangle to an empty state.
      m_width = 0;
      m_height = 0;
    }
  }

  // Destructor
  // This class has no destructor implemented.

  // getSpecs
  // Reads comma-separated specs of the Rectangle from istream.
  // This function overrides the getSpecs function of the base class as follows.
  // First, it will call the getSpecs function of the base class, then it will read two comma-separated values from istream for m_width and m_length and then ignores the rest of the characters up to and including the newline character ('\n').
  void Rectangle::getSpecs(std::istream &is)
  {
    LblShape::getSpecs(is);
    is >> m_width;
    is.ignore();  // ignore the comma
    is >> m_height;
    while (is.get() != '\n') // clear the buffer of old characters
    {
    }
  }

  // draw
  // This function overrides the draw function of the base class.
  // For example, if the Cstring returned by the label query is "Container", the width is 30 and the height is 5, this function should insert the following into ostream:
  // +----------------------------+
  // |Container                   |
  // |                            |
  // |                            |
  // +----------------------------+
  void Rectangle::draw(std::ostream &ostr) const
  {
    // If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:
    if (m_height > 0 && m_height > 0)
    {
      // First line:
      // prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.
      ostr << '+';
      for (int i = 0; i < m_width - 2; i++)
      {
        ostr << '-';
      }
      ostr << '+' << endl;

      // Second line:
      // prints '|', then in (m_width-2) spaces it prints the label() left justified and then prints '|' and goes to new line.
      ostr << '|';
      ostr.setf(ios::left);
      ostr.width(m_width - 2);
      ostr << label();
      ostr.unsetf(ios::left);
      ostr << '|' << endl;

      // In next (m_height - 3) lines:
      // prints '|', (m_width-2) spaces then prints '|' and goes to new line.
      for (int i = 0; i < m_height - 3; i++)
      {
        ostr << '|';
        ostr.width(m_width - 1);
        ostr << '|' << endl;
      }

      // Last line: exactly like first line.
      ostr << '+';
      for (int i = 0; i < m_width - 2; i++)
      {
        ostr << '-';
      }
      ostr << '+' ;
    }
  }
}