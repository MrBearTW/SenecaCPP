#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

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

      // Simple private fuctions:
      void load();      // prints: "Loading Data"<NEWLINE>
      void save();      // prints: "Saving Data"<NEWLINE>
      void search();    // prints: "Searching for publication"<NEWLINE>
      void returnPub(); // calls the search() method.

      // Methods with confirmation
      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      // Constructor
      LibApp();

      // The run method
      void run();
   };
}
#endif // !SDDS_LIBAPP_H
