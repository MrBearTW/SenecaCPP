/*/////////////////////////////////////////////////////////////////////////
                            Workshop 2 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/05/30

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
   // DIY
   bool read(char *postcode)
   {
      bool readPostcode = false;
      if (fscanf(fptr, "%[^,],", postcode) == 1)
      {
         readPostcode = true;
      }
      return readPostcode;
   }
   bool read(int &population)
   {
      bool readPopulation = false;
      if (fscanf(fptr, "%d\n", &population) == 1)
      {
         readPopulation = true;
      }
      return readPopulation;
   }
}