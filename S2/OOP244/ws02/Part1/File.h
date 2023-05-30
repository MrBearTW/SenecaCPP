/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/25

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char *employeeName);
   bool read(int &employeeNumber);
   bool read(double &employeeSalary);
}
#endif // !SDDS_FILE_H_
