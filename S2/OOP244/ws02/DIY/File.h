/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/30

/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // DIY
   bool read(char *postcode);
   bool read(int &population);
}
#endif // !SDDS_FILE_H_
