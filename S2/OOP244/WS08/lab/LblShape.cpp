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
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
  // Protected members
  
  // Add a query called label that returns the unmodifiable value of m_label member variable.
  const char *LblShape::label() const
  {
    return m_label;
  }

  // public members

  // Default (no argument) constructor
  // Sets the label pointer to null. (You don't need to do this if the m_label is already initialized to null)
  LblShape::LblShape()
  {
    m_label = nullptr;
  }

  // One argument constructor
  // Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable. Then copies the Cstring argument to the newly allocated memory.
  LblShape::LblShape(const char *label)
  {
    if (label != nullptr && label[0] != '\0')
    {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
    }
  }

  // Destructor
  // Deletes the memory pointed by m_label member variable.
  LblShape::~LblShape()
  {
    delete[] m_label;
    m_label = nullptr;
  }

  // getSpecs
  // Reads a comma-delimited Cstring form istream:
  // Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character (and then extract and ignore the comma). Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory.
  void LblShape::getSpecs(std::istream &is)
  {
    string temp;
    getline(is, temp, ','); // read until ',' and store in temp string object and ignore ',' character
    delete[] m_label;
    m_label = new char[temp.length() + 1];
    strcpy(m_label, temp.c_str());
  }
}