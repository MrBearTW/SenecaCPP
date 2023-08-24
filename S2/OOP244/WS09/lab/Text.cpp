/*/////////////////////////////////////////////////////////////////////////
                            Workshop 9 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/27

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;

namespace sdds
{
   // Code provided (int Text.cpp) ; it returns the length (size) of the text file on the disk. It returns zero if either the file does not exist or the content is empty.
   int Text::getFileLength() const
   {
      int len = 0;
      ifstream fin(m_filename);
      while (fin)
      {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   // This index operator provides read-only access to the content of the text for the derived classes of Text.
   // The behaviour of the operator is not defined if the index goes out of bounds.
   const char &Text::operator[](int index) const
   {
      if (index >= 0 || index < getFileLength())
      {
         return m_content[index];
      }
      else
      {
         return m_content[getFileLength()];
      }
   }

   Text::Text(const char *filename)
   {
      if (m_filename)
      {
         delete[] m_filename;
         m_filename = nullptr;
      }
      if (m_content)
      {
         delete[] m_content;
         m_content = nullptr;
      }

      if (filename)
      {
         m_filename = new char[strLen(filename) + 1];
         strCpy(m_filename, filename);
         read();
      }
   }

   // The rule of three
   // Implement the rule of three so memory is managed properly in case of copying and assignment.
   Text::Text(const Text &src)
   {
      *this = src;
   }

   Text &Text::operator=(const Text &src)
   {
      if (this != &src)
      {
         delete[] m_filename;
         delete[] m_content;
         m_filename = nullptr;
         m_content = nullptr;
         if (src.m_filename && src.m_content)
         {
            m_filename = new char[strLen(src.m_filename) + 1];
            strCpy(m_filename, src.m_filename);
            m_content = new char[strLen(src.m_content) + 1];
            strCpy(m_content, src.m_content);
         }
      }
      return *this;
   }

   Text::~Text()
   {
      delete[] m_filename;
      delete[] m_content;
      m_filename = nullptr;
      m_content = nullptr;
   }

   // First, read will the current content of the file and then allocates memory to the size of the file on the disk + 1 (for the null byte).
   // Then it will read the contents of the file character by character into the newly allocated memory and terminates it with a null byte at the end.
   void Text::read()
   {
      int index = 0;
      char temp;
      ifstream fin(m_filename);

      if (m_content)
      {
         delete[] m_content;
         m_content = nullptr;
      }

      if (fin.is_open())
      {
         m_content = new char[getFileLength() + 1];
         while (fin.get(temp))
         {
            m_content[index] = temp;
            index++;
         }
         m_content[index] = '\0';
      }
      else
      {
         m_content = nullptr;
      }
   }

   // This virtual function will insert the content of the Text class into the ostream if m_content is not null.
   void Text::write(std::ostream &os) const
   {
      if (m_content)
      {
         os << m_content;
      }
   }

   // Overload the insertion operator for a Text object into ostream.
   std::ostream &operator<<(std::ostream &os, const Text &text)
   {
      text.write(os);
      return os;
   }
}