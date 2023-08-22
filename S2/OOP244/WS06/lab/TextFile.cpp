/*/////////////////////////////////////////////////////////////////////////
                            Workshop 6 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/06

/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
   // ---------------------- Line class ----------------------

   // Returns the address held in the m_value attribute.
   Line::operator const char *() const
   {
      return m_value;
   }

   // Dynamically allocates memory in m_value and copies the Cstring pointed by lineContent into it.
   Line &Line::operator=(const char *lineValue)
   {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   // default constructor: Initializes the m_value attribute to nullptr.
   // Line::Line()
   // {
   //    m_value = nullptr;
   // }
   //  error: redefinition

   // Makes sure all the allocated memory is freed.      // Make sure Line can not be copied or assigned to another Line.
   Line::~Line()
   {
      delete[] m_value;
      m_value = nullptr;
   }


   // ---------------------- TextFile class ----------------------

   // deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring and sets is to nullptr sets m_noOfLines attribute to zero.
   void TextFile::setEmpty()
   {
      delete[] m_textLines;
      m_textLines = nullptr;
      delete[] m_filename;
      m_filename = nullptr;
      m_noOfLines = 0;
   }

   // If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it. If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
   // Example:
   // setFilename("abc.txt"); // sets the m_filename to "abc.txt"
   // setFilename("abc.txt", true); // sets the m_filename to "C_abc.txt"
   void TextFile::setFilename(const char *fname, bool isCopy)
   {
      if (m_filename != nullptr)
      {
         delete[] m_filename;
         m_filename = nullptr;
      }

      if (isCopy)
      {
         m_filename = new char[strLen(fname) + 3];
         strCpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
      else
      {
         m_filename = new char[strLen(fname) + 1];
         strCpy(m_filename, fname);
      }
   }

   // Counts the number of lines in the file:
   // Creates a local ifstream object to open the file with the name held in m_filename. Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
   // In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
   // If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)
   void TextFile::setNoOfLines()
   {
      ifstream fin(m_filename);
      char ch;
      m_noOfLines = 0;
      if (fin.is_open())
      {
         while (fin.get(ch))
         {
            if (ch == '\n')
            {
               m_noOfLines++;
            }
         }
         m_noOfLines++;
      }
      if (m_noOfLines == 0)
      {
         setEmpty();
      }
   }

   // Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
   // If the m_filename is null, this function does nothing.
   // If the m_filename is not null (TextFile is not in a safe empty state ), loadText() will dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
   // Make sure m_textLine is deleted before this to prevent memory leak.
   // Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
   // Since the length of each line is unknown, read the line using a local C++ string object and the getline helper function. (note: this is the HELPER getline function and not a method of istream).
   // In a loop reads each line into the string object and then sets the m_textLines array elements to the values returned by the c_str() method of the string object until the reading fails (end of file reached).
   // After all the lines are read, make sure to update the value of m_noOfline to the actual number of lines read (This covers the possibility of one extra empty line at the end of the file)
   void TextFile::loadText()
   {
      if (m_filename != nullptr)
      {
         if (m_textLines != nullptr)
         {
            delete[] m_textLines;
            m_textLines = nullptr;
         }

         m_textLines = new Line[m_noOfLines];

         ifstream fin(m_filename);
         std::string line;
         unsigned i = 0;
         if (fin.is_open())
         {
            while (getline(fin, line) && i < m_noOfLines)
            {
               // deep copy
               m_textLines[i].m_value = new char[strLen(line.c_str()) + 1];
               strCpy(m_textLines[i].m_value, line.c_str());
               i++;
            }
         }
         m_noOfLines = i;
      }
   }

   // Saves the content of the TextFile under a new name.
   // Use a local ofstream object to open a new file using the name kept in the argument filename. Then loop through the elements of the m_textLines array and write them in the opened file adding a new line to the end of each line.
   void TextFile::saveAs(const char *fileName) const
   {
      ofstream ofs(fileName);
      if (ofs.is_open())
      {
         for (unsigned i = 0; i < m_noOfLines; i++)
         {
            ofs << m_textLines[i] << endl;
         }
      }
   }

   // Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
   TextFile::TextFile(unsigned pageSize)
   {
      setEmpty();
      m_pageSize = pageSize;
   }

   // Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
   TextFile::TextFile(const char *filename, unsigned pageSize)
   {
      setEmpty();
      m_pageSize = pageSize;

      if (filename != nullptr)
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   // Rule of three implementations for classes with resource
   // Implement The Copy Constructor, Copy assignment and destructor.

   // 1. Copy Constructor
   // Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero. If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely:
   // Sets the file-name to the name of the incoming TextFile object (isCopy set to true) See setFilename()
   // Saves the content of the incoming TextFile under the file name of the current TextFile
   // set the number of lines
   // loads the Text
   TextFile::TextFile(const TextFile &tf)
   {
      setEmpty();

      // Shallow copy non dynamic resources
      m_pageSize = tf.m_pageSize;
      this->m_noOfLines = tf.m_noOfLines;

      setFilename(tf.m_filename, true);

      // allocate new memory for the dynamic resources and deep copy
      m_textLines = new Line[m_noOfLines];
      unsigned i = 0;
      while (i < m_noOfLines)
      {
         m_textLines[i].m_value = new char[strLen(tf.m_textLines[i].m_value) + 1];
         strCpy(m_textLines[i].m_value, tf.m_textLines[i].m_value);
         i++;
      }
      saveAs(m_filename);
   }

   // 2. Copy Assignment
   // If the current and the incoming TextFiles are valid it will first delete the current text and then overwrites the current file and data by the content of the incoming TextFile.
   // deallocate the dynamic array of Text and sets the pointer to null
   // Saves the content of the incoming TextFile under the current filename
   // Sets the number of lines
   // loads the Text
   TextFile &TextFile::operator=(const TextFile &tf)
   {
      if (this != &tf)
      {
         if (m_textLines != nullptr)
         {
            delete[] m_textLines;
            m_textLines = nullptr;
         }

         if (tf.m_textLines && tf.m_noOfLines > 0)
         {
            // shallow copy non dynamic variables
            this->m_pageSize = tf.m_pageSize;
            this->m_noOfLines = tf.m_noOfLines;

            // allocate new memory and deep copy
            m_textLines = new Line[m_noOfLines];
            unsigned i = 0;
            while (i < m_noOfLines)
            {
               m_textLines[i].m_value = new char[strLen(tf.m_textLines[i].m_value) + 1];
               strCpy(m_textLines[i].m_value, tf.m_textLines[i].m_value);
               i++;
            }
            saveAs(m_filename);
         }
      }
      return *this;
   }

   // 3. Destructor
   // Deletes all the dynamic data.
   TextFile::~TextFile()
   {
      delete[] m_textLines;
      m_textLines = nullptr;
      delete[] m_filename;
      m_filename = nullptr;
   }


   // ------ public Methods ------

   // returns m_noOfLines;
   unsigned TextFile::lines() const
   {
      return m_noOfLines;
   }

   // Prints the filename and then the content of the file "m_pageSize" lines at a time.
   // print the file name
   // underline the file name with '=' character
   // loops through the lines and print them one by line
   // pauses after printing "m_pageSize" lines and prompts the user Hit ENTER to continue... and waits for the user to press enter and repeats until all lines are printed.
   // The function performs no action if the TextFile is in an empty state.
   // This function receives and returns an instance of istream and uses the instance for printouts.
   std::ostream &TextFile::view(std::ostream &ostr) const
   {
      if (m_filename != nullptr && m_textLines != nullptr && m_noOfLines > 0 && m_pageSize > 0)
      {
         ostr << m_filename << endl;
         ostr.fill('=');
         ostr.width(strLen(m_filename));
         ostr << '=' << endl;

         unsigned i = 0;
         while (i < m_noOfLines)
         {
            ostr << m_textLines[i] << endl;
            i++;
            if (i % m_pageSize == 0)
            {
               ostr << "Hit ENTER to continue...";
               cin.get();
            }
         }
      }
      return ostr;
   }

   // getFile()
   // Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. When done it will return the istr;
   std::istream &TextFile::getFile(std::istream &istr)
   {
      std::string filename;
      getline(istr, filename, '\n');
      delete[] m_filename;
      m_filename = new char[filename.length() + 1];
      setFilename(filename.c_str()); // std::string --> char*

      setNoOfLines();
      loadText();
      return istr;
   }

   // index Operator Overload
   // Returns the element in the m_textLine array corresponding to the index argument.
   // If the TextFile is in an empty state, it will return null. If the index exceeds the size of the array it should loop back to the beginning.
   // For example, if the number of lines is 10, the last index should be 9 and index 10 should return the first element and index 11 should return the second element.
   const char *TextFile::operator[](unsigned index) const
   {
      if (m_filename != nullptr && m_filename[0] != '\0')
      {
         if (index >= m_noOfLines)
            index -= m_noOfLines;
      }

      return m_textLines[index].m_value;
   }

   // ------ Type conversion overloads:------

   // boolean cast
   // Returns true if the TextFile is not in an empty state and returns false if it is.
   TextFile::operator bool() const
   {
      return m_textLines != nullptr;
   }

   // constant character pointer cast
   // Returns the filename.
   const char *TextFile::name() const
   {
      return m_filename;
   }

   // ------ Insertion and extraction helper operator overloads ------
   // To print and read on and from istream and ostream overload operator<< and operator>>:

   // operator<<
   // uses the view() method to print the TextFile
   std::ostream &operator<<(std::ostream &ostr, const TextFile &tf)
   {
      return tf.view(ostr);
   }

   // operator>>
   // uses the getFile() method to get the file name from console and load the content from the file
   std::istream &operator>>(std::istream &istr, TextFile &tf)
   {
      return tf.getFile(istr);
   }
}
