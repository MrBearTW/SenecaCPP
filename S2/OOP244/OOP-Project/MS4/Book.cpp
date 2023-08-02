#include <iostream>
#include <cstring>
#include <iomanip>

#include "Book.h"

namespace sdds
{
    // Construction
    Book::Book() : Publication()
    {
        m_authorName = nullptr;
    }

    // The rule of three
    Book::Book(const Book &src) : Publication(src)
    {
        if (src.m_authorName != nullptr)
        {
            m_authorName = new char[strlen(src.m_authorName) + 1];
            strcpy(m_authorName, src.m_authorName);
        }
        else
        {
            m_authorName = nullptr;
        }
    }

    Book &Book::operator=(const Book &src)
    {
        if (this != &src)
        {
            Publication::operator=(src);

            if (m_authorName)
            {
                delete[] m_authorName;
                m_authorName = nullptr;
            }

            if (src.m_authorName)
            {
                m_authorName = new char[strlen(src.m_authorName) + 1];
                strcpy(m_authorName, src.m_authorName);
            }
        }
        return *this;
    }

    Book::~Book()
    {
        delete[] m_authorName;
        m_authorName = nullptr;
    }

    // ---------- Methods ----------
    // type method
    // Returns the character "B".
    char Book::type() const
    {
        return 'B';
    }

    // write method
    std::ostream &Book::write(std::ostream &os) const
    {
        // First, it will invoke the write of its Base class.
        Publication::write(os);
        // If the incoming argument is a console IO object.
        if (conIO(os))
        {
            // writes a single space
            os << " ";
            // writes the author's name in SDDS_AUTHOR_WIDTH spaces. If the author's name is longer than the SDDS_AUTHOR_WIDTH value, it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters. Note that this should not modify the author's name.
            
            // If the author's name is longer then SDDS_AUTHOR_WIDTH, it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters.
            if (strlen(m_authorName) >= SDDS_AUTHOR_WIDTH)
            {
                os.write(m_authorName, SDDS_AUTHOR_WIDTH);
            }
            else
            {
                os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << m_authorName;
            }

            // writes " |"
            os << " |";
        }
        else
        {
            // If the incoming argument is not a console IO object
            // writes a tab character '\t'
            // writes the author's name
            os << "\t" << m_authorName;
        }
        // returns the incoming ostream.
        return os;
    }

    // Read
    std::istream &Book::read(std::istream &is)
    {
        // Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)
        char temp_authorName[256] = {0};
        // char temp_authorName[SDDS_AUTHOR_WIDTH + 1] = {0};

        // First, invoke the read of the Base class.
        Publication::read(is);
        // Free the memory held for the author's name
        if (m_authorName)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        // If the incoming argument is a console IO object
        if (conIO(is))
        {
            // ignore one character (skip the '\n')
            is.ignore();
            // prompt "Author: "
            std::cout << "Author: ";
            // read the author's name
        }
        else
        {
            // If the incoming argument is not a console IO object
            // ignore the tab character
            is.ignore(1000, '\t');
            // read the author's name
        }

        // is.getline(temp_authorName, 256);    // This will skip a line.
        is.get(temp_authorName, 256);

        // Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
        if (!is.fail())
        {
            m_authorName = new char[strlen(temp_authorName) + 1];
            strcpy(m_authorName, temp_authorName);
        }

        // At the end return the incoming istream object.
        return is;
    }

    // set
    void Book::set(int member_id)
    {
        // invoke the set of the base class to set the member id
        Publication::set(member_id);
        // reset the date to the current date.
        resetDate();
    }

    // perator bool()
    Book::operator bool() const
    {
        // return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
        return (m_authorName != nullptr && m_authorName[0] != '\0' && Publication::operator bool());
    }
}
