/*/////////////////////////////////////////////////////////////////////////
                            Workshop 9 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/27

/////////////////////////////////////////////////////////////////////////*/

// HtmlText class is created using an additional argument for the title of the HTML conversion and overrides the virtual write function of the base class.

// When created HtmlText will pass the filename to its base class and if the title is not null, it will keep in dynamically as a property.

// if anything goes wrong in setting up the class or reading a file, it will be set to an empty state.

#include <iostream>
#include "HtmlText.h"
#include "cstring.h"
namespace sdds
{
    HtmlText::HtmlText(const char *filename, const char *title) : Text(filename)
    {
        if (title)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
        else
        {
            m_title = nullptr;
        }
    }

    // rule of three goes here
    HtmlText::HtmlText(const HtmlText &src)
    {
        *this = src;
    }

    HtmlText &HtmlText::operator=(const HtmlText &src)
    {
        if (this != &src)
        {
            Text::operator=(src);
            if (m_title)
            {
                delete[] m_title;
                m_title = nullptr;
            }

            if (src.m_title)
            {
                m_title = new char[strLen(src.m_title) + 1];
                strCpy(m_title, src.m_title);
            }
        }
        else
        {
            m_title = nullptr;
        }
        return *this;
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    // This override will convert the text file to a simple HTML file as follows:

    // First the open tags for html page, header and title are inserted into ostream proceeding with the open body tag. Then for all the conent of the file:

    // less than operator(<) is replaced by "&lt;" characters
    // greater than operator(>) is replaced by "&gt;" characters
    // newline ('\n') is replaced by "<br />\n" characters
    // space character(' ') if more than one, except from the first, the rest are replaced by "&nbsp;"
    // At the end, the close tags for body and html page are inserted.

    // o accomplish the above do the insertion into ostream as follows:

    // create a boolean variable and set it to false to keep track of the occurance of multiple spaces (let's call it MS for Multiple Spaces)
    // insert "<html><head><title>"
    // if m_title is not null, insert the title, otherwise insert "No Title"
    // insert "</title></head>\n<body>\n"
    // if "</title>\n\n" is not null insert "<h1>" << m_title << "</h1>\n"
    // loop through all the elements of the m_content (using the protected index operator) and convert the characters as follows:
    // at the end insert "</body>\n</html>" to end the html page.
    void HtmlText::write(std::ostream &os) const
    {
        bool MS = false;
        os << "<html><head><title>";
        if (m_title != nullptr)
        {
            os << m_title;
        }
        else
        {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

        if (m_title)
        {
            os << "<h1>" << m_title << "</h1>\n";
            int index = 0;

            // loop through all the elements of the m_content (using the protected index operator) and convert the characters as follows:
            while (Text::operator[](index) != '\0') 
            {
                char temp = Text::operator[](index);
                switch (temp)
                {
                case '<':
                    os << "&lt;";
                    MS = false;
                    break;
                case '>':
                    os << "&gt;";
                    MS = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    MS = false;
                    break;
                case ' ':
                    if (MS)
                    {
                        os << "&nbsp;";
                    }
                    else
                    {
                        os << temp;
                        MS = true;
                    }
                    break;
                default:
                    os << temp;
                    MS = false;
                    break;
                }
                index++;
            }
        }
        os << "</body>\n</html>";
    }
}