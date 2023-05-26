/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/25

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE *fptr;

   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }

   /* TODO: read functions go here */

   bool read(char *employeeName)
   {
      bool readEmployeeName = (fscanf(fptr, "%[^\n]\n", employeeName) == 1) ? 1 : 0;
      return readEmployeeName;
   }

   bool read(int &employeeNumber)
   {
      bool readEmployeeNumber = (fscanf(fptr, "%d,", &employeeNumber) == 1) ? 1 : 0;
      return readEmployeeNumber;
   }

   bool read(double &employeeSalary)
   {
      bool readEmployeeSalary = (fscanf(fptr, "%lf,", &employeeSalary) == 1)? 1:0;
      return readEmployeeSalary;
   }
}