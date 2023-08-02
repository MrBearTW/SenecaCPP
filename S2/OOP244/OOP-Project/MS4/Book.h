// The Book class implementation
// The Book class is derived from the Publication class. A book is a publication with an "Author name".

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds
{

    class Book : public Publication
    {
        // The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically.
        char *m_authorName{nullptr};

    public:
        // Construction
        // A book is created empty by default, in a safe empty state.
        Book();

        // The rule of three
        // Implement what is needed to comply with the rule of three so a book can safely be copied or assigned to another book.
        Book(const Book &src);
        Book &operator=(const Book &src);
        virtual ~Book();

        // ---------- Methods ----------
        // The book class overrides the following virtual methods and type conversion operator.

        // type
        char type() const;

        // write
        std::ostream &write(std::ostream &os) const;

        // read
        std::istream &read(std::istream &is);

        // set
        void set(int member_id);

        // operator bool()
        operator bool() const;
    };
}
#endif