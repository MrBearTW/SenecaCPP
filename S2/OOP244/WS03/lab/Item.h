/*/////////////////////////////////////////////////////////////////////////
                            Workshop 3 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/01

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#define TAXRATE 0.13
namespace sdds
{
   class Item
   {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char *name);

   public:
      void setEmpty();
      void set(const char *name, double price, bool taxed);
      void display() const;
      bool isValid() const;
      double price() const;
      double tax() const;
   };
}

#endif // !SDDS_SUBJECT_H
