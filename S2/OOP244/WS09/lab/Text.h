/*/////////////////////////////////////////////////////////////////////////
                            Workshop 9 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/27

/////////////////////////////////////////////////////////////////////////*/

// Text: A class that can load the contents of a text file into memory and insert it into ostream.
// Text class is created using a file name. If the name is not null it will store it dynamically in the memory and read it from the disk into a dynamically allocated memory (using the member function read).

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>

namespace sdds
{
   class Text
   {
      char *m_filename{nullptr}; // Hold the name of the file dynamically
      char *m_content{nullptr};  // Holds the content of the text file dynamically.

      int getFileLength() const; // Code provided in Text.cpp

      // ---------- Mandatory functionalities ----------
      // if anything goes wrong in setting up the class or reading a file, it will be set to an empty state.

   protected:
      // This index operator provides read-only access to the content of the text for the derived classes of Text.
      const char &operator[](int index) const;

   public:
      Text(const char *filename = nullptr);
      // implement rule of three here
      Text(const Text &src);
      Text &operator=(const Text &src);
      virtual ~Text();

      void read();

      // This virtual function will insert the content of the Text class into the ostream if m_content is not null.
      virtual void write(std::ostream &os) const;
   };
   // prototype of insertion overload into ostream goes here

   // instertion overload into ostream
   // Overload the insertion operator for a Text object into ostream.
   std::ostream &operator<<(std::ostream &os, const Text &text);
}
#endif // !SDDS_PERSON_H__
