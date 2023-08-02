#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Publication.h"

namespace sdds
{
    // Constructor  (default)
    Publication::Publication()
    {
        // m_title is a c-string to hold a dynamic title for the publication.
        //      To ease the implementation, let's assume this dynamic array can not be more than 255 characters long.
        // This attribute is null by default.
        m_title = nullptr;

        // Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long.
        // This attribute is an empty string by default.
        m_shelfId[0] = '\0';

        // This attribute is an integer to hold a 5 digit membership number of members of the library.

        // This attribute is zero by default.
        m_membership = 0;

        // This serial number is used internally to uniquely identify each publication in the system.
        // This attribute is -1 by default.
        m_libRef = -1;

        // The Date, by default, is set to the current date.
        // m_date = Date();
        resetDate();
    }

    // -------------------- Modifiers --------------------
    void Publication::set(int member_id)
    {
        // Sets the membership attribute to either zero or a five-digit integer.
        if (member_id >= 10000 && member_id <= 99999)
        {
            m_membership = member_id;
        }
        else
        {
            m_membership = 0;
        }
    }

    void Publication::setRef(int value)
    {
        // Sets the **libRef** attribute value
        if (value >= 0)
        {
            m_libRef = value;
        }
        else
        {
            m_libRef = -1;
        }
    }

    void Publication::resetDate()
    {
        // Sets the date to the current date of the system.
        m_date = Date();
    }

    // -------------------- Queries --------------------
    char Publication::type() const
    {
        // Returns the character 'P' to identify this object as a "Publication object"
        return 'P';
    }

    bool Publication::onLoan() const
    {
        // Returns true is the publication is checkout (membership is non-zero)
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const
    {
        // Returns the date attribute
        return m_date;
    }

    bool Publication::operator==(const char *title) const
    {
        // Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const
    {
        // Returns the title attribute
        return m_title;
    }

    int Publication::getRef() const
    {
        // Returns the libRef attirbute.
        return m_libRef;
    }

    // ---------- Streamable pure virtual function implementations ----------

    // bool conIO(ios& io)const
    bool Publication::conIO(std::ios &io) const
    {
        // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
        return &io == &std::cout || &io == &std::cin;
    }

    // ostream& write(ostream& os) const
    std::ostream &Publication::write(std::ostream &os) const
    {
        // If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes as the following format (title is left-justified padded with dots)
        /*
            | P001 | The Toronto Star.............. | 34037 | 2023/11/17 |
            | P007 | Macleans Magazine............. |  N/A  | 2023/11/11 |
        */

        if (conIO(os))
        {
            os << "| " << m_shelfId << " | " << std::setw(SDDS_TITLE_WIDTH) << std::left << std::setfill('.');
            // If the m_title is longer than the SDDS_TITLE_WIDTH value, print the first SDDS_TITLE_WIDTH characters of the title.
            if (strlen(m_title) > SDDS_TITLE_WIDTH)
            {
                char title_30_chars[SDDS_TITLE_WIDTH + 1]{};
                strncpy(title_30_chars, m_title, SDDS_TITLE_WIDTH);
                title_30_chars[SDDS_TITLE_WIDTH] = '\0';
                os << title_30_chars;
            }
            else
            {
                os << m_title;
            }

            os << " | ";
            if (m_membership == 0)
            {
                os << " N/A ";
            }
            else
            {
                os << m_membership;
            }
            os << " | " << m_date << " |";
        }
        // Otherwise:
        // Print the type() and then libRef, shelfId, title, membership and date attributes in a tab-separated format.
        /*
            P	2001	P001	The Toronto Star	34037	2023/11/17
        */
        // No newline is printed afterwards either way.
        else
        {
            os << type() << '\t';
            os << '\t' << m_libRef << '\t' << m_shelfId << '\t';
            // If the m_title is longer than the SDDS_TITLE_WIDTH value, print the first SDDS_TITLE_WIDTH characters of the title.
            if (strlen(m_title) > SDDS_TITLE_WIDTH)
            {
                char title_30_chars[SDDS_TITLE_WIDTH + 1]{};
                strncpy(title_30_chars, m_title, SDDS_TITLE_WIDTH);
                title_30_chars[SDDS_TITLE_WIDTH] = '\0';
                os << title_30_chars << '\t';
            }
            else
            {
                os << m_title << '\t';
            }

            if (m_membership == 0)
            {
                os << "N/A";
            }
            else
            {
                os << m_membership;
            }
            os << '\t' << m_date;
        }
        return os;
    }

    // istream& read(istream& istr)
    // Read all the values in local variables before setting the attributes to any values.
    std::istream &Publication::read(std::istream &is)
    {
        // Store the whole title but just print the first 30 characters.
        char temp_title[256]{};
        int temp_membership = 0;
        int temp_libRef = -1;
        char temp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        Date temp_date;

        // First, clear all the attributes by freeing the memory and setting everything to their default values.
        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        // Then, if the istr argument is a console IO object (use conIO()) read the attributes as follows:
        if (conIO(is))
        {
            // prompt: "Shelf No: "
            std::cout << "Shelf No: ";

            // - read the shelf number up to its limit (see Lib.h).
            is.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1);

            // - if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
            if (strlen(temp_shelfId) != SDDS_SHELF_ID_LEN)
            {
                is.setstate(std::ios::failbit);
            }

            // - prompt: "Title: "
            std::cout << "Title: ";

            // - read the title
            is.getline(temp_title, 256);

            // - prompt: "Date: "
            std::cout << "Date: ";

            // - read the date
            is >> temp_date;
        }

        // in this case the libRef value is left with its default value.
        // Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.
        else
        {
            // - read the libRef number
            is >> temp_libRef;

            // - skip the tab
            is.ignore();

            // - read the shelf number
            // - skip the tab
            is.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');

            // - read the title
            // - skip the tab
            is.getline(temp_title, 256, '\t');

            // - read the membership
            is >> temp_membership;

            // - skip the tab
            is.ignore();

            // - read the date
            is >> temp_date;
        }

        // Either way if the date is in an invalid state set the istr to a fail state manually
        if (!temp_date)
        {
            is.setstate(std::ios::failbit);
        }

        // After the process of reading is done if istr is in a valid state:
        if (is)
        {
            // - Dynamically store the title into the title attribute
            m_title = new char[strlen(temp_title) + 1];

            // - copy the shelf id into the shelfId attribute
            strcpy(m_title, temp_title);

            // - copy the shelf id into the shelfId attribute
            strcpy(m_shelfId, temp_shelfId);

            // - set the membership
            m_membership = temp_membership;

            // - set the date
            m_date = temp_date;

            // - set the libRef attribute
            m_libRef = temp_libRef;
        }
        // At the end return the istr argument.
        return is;
    }

    // operator bool() const
    Publication::operator bool() const
    {
        // Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
        return m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0';
    }

    // -------------------- The Rule of three --------------------
    // Make sure this object complies with the guidelines of the Rule of three so the copying and assignment and destruction are done safely and without any memory leak.

    // copy constructor
    Publication::Publication(const Publication &src)
    {
        m_title = nullptr;
        if (src.m_title)
        {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
        strcpy(m_shelfId, src.m_shelfId);
        m_membership = src.m_membership;
        m_libRef = src.m_libRef;
        m_date = src.m_date;
    }

    // copy assignment operator
    Publication &Publication::operator=(const Publication &src)
    {
        if (this != &src)
        {
            delete[] m_title;
            m_title = nullptr;
            if (src.m_title)
            {
                m_title = new char[strlen(src.m_title) + 1];
                strcpy(m_title, src.m_title);
            }
            strcpy(m_shelfId, src.m_shelfId);
            m_membership = src.m_membership;
            m_libRef = src.m_libRef;
            m_date = src.m_date;
        }
        return *this;
    }

    // destructor
    Publication::~Publication()
    {
        delete[] m_title;
        m_title = nullptr;
    }
}