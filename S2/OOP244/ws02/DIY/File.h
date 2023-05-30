#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
}
#endif // !SDDS_FILE_H_
