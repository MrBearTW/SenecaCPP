/*/////////////////////////////////////////////////////////////////////////
                            Workshop 9 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/07/27

/////////////////////////////////////////////////////////////////////////*/

// HtmlText: A Text Class that has a title and can insert the text contents of the class into ostream in simple HTML format.
// HtmlText class is inherited from the Text for an HTML conversion. Make sure, like the Text class, the rule of three is implemented here.

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds
{
   class HtmlText : public Text
   {
      char *m_title{nullptr}; // Holds the title of the HTML conversion dynamically.

   public:
      HtmlText(const char *filename = nullptr, const char *title = nullptr);
      // rule of three goes here
      HtmlText(const HtmlText &src);
      HtmlText &operator=(const HtmlText &src);
      ~HtmlText();

      // Text::write override
      void write(std::ostream &os) const;
   };
}
#endif // !SDDS_HTMLTEXT_H__

