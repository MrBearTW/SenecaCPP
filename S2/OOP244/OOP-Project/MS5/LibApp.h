#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
#include "Book.h"
#include "Streamable.h"

namespace sdds
{
   class LibApp
   {
      // A flag to keep track of changes made to the application data. This flag is initially set to false. If any change is made to the data of the application, this flag is set to true.
      // Doing so, when exiting the program, we can warn the user and ask if they like the changes to be saved or discarded.
      bool m_changed;

      // This menu will be used as the main menu of the application
      Menu m_mainMenu;

      // This menu will be used when exiting the program if any changes are made to the data.
      Menu m_exitMenu;

      // Instantiate a Menu in this function and initialize it with the message argument.
      bool confirm(const char *message);

      // File name
      // Add an array of 256 characters to hold the publication data file name.
      char m_filename[256];

      // PPA
      // Publication Pointers Array
      // Create and add an array of Publication pointers to the size of SDDS_LIBRARY_CAPACITY. This array will be populated with all the records of the publication data file when the LibApp is instantiated.
      Publication *m_ppa[SDDS_LIBRARY_CAPACITY]{};

      // NOLP
      // Number Of Loaded Publications
      // Add an integer to hold the number of Publications loaded into the PPA.
      int m_nolp;

      // LLRN
      // Last Library Reference Number
      // Add an integer to hold the last library reference number read from the data file. This number will be used to assign new library reference numbers to new publications added to the library. When a new publication is added to the library, this number will be added by one and then assigned to the new publication. Doing this; each publication in the library will have a unique library reference number.
      int m_llrn;

      // Publication Type Menu
      Menu m_pubTypeMenu;

      void load();
      void save();

      // Add needed arguments so the search function can be called in three different modes:
      int search(int searchMode);
      void returnPub(); // calls the search() method.

      // Methods with confirmation
      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      // Constructor
      LibApp(const char *filename);
      // Destructor
      ~LibApp();

      // The run method
      void run();

      // Publication* getPub(int libRef) method
      Publication *getPub(int libRef);
   };
}
#endif // !SDDS_LIBAPP_H
