#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"

namespace sdds
{
    class Publication : public Streamable
    {
    private:
        // m_title
        char *m_title;

        // m_shelfId
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];

        // m_membership
        // In this class, if the membership number is '0', it means the publication is available and is not checked out by any members.
        // If the membership number is a five-digit number, it means the publication is checked out by the member holding that membership number.
        int m_membership;

        // m_libRef
        int m_libRef;

        // m_date
        // A Date object.
        // In periodical publications, this date is used for the publish date of the item.
        // In Books, this date is used to keep the date on which the book was borrowed by the member.
        Date m_date;

    public:
        // Constructor (default)
        Publication();

        // -------------------- Modifiers --------------------

        // Sets the membership attribute to either zero or a five-digit integer.
        virtual void set(int member_id);

        // Sets the **libRef** attribute value
        void setRef(int value);

        // Sets the date to the current date of the system.
        void resetDate();

        // -------------------- Queries --------------------

        // Returns the character 'P' to identify this object as a "Publication object"
        virtual char type() const;

        // Returns true is the publication is checkout (membership is non-zero)
        bool onLoan() const;

        // Returns the date attribute
        Date checkoutDate() const;

        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        bool operator==(const char *title) const;

        // Returns the title attribute
        operator const char *() const;

        // Returns the libRef attirbute.
        int getRef() const;

        // ---------- Streamable pure virtual function implementations ----------

        // bool conIO(ios& io)const
        bool conIO(std::ios &io) const;

        // ostream& write(ostream& os) const
        std::ostream &write(std::ostream &os) const;

        // istream& read(istream& istr)
        std::istream &read(std::istream &is);

        // operator bool() const
        operator bool() const;

        // -------------------- The Rule of three --------------------
        Publication(const Publication &src);
        Publication &operator=(const Publication &src);
        ~Publication();
    };
}

#endif // !SDDS_PUBLICATION_H