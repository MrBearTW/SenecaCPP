#include <iostream>
using namespace std;
#include "LibApp.h"

namespace sdds
{
    // Instantiate a Menu in this function and initialize it with the message argument.
    // Then add only a "yes" as a single menu item to the Menu.
    // Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
    bool LibApp::confirm(const char *message)
    {
        Menu menu(message);
        menu << "Yes";
        if (menu.run() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // -------------------- Simple private fuctions --------------------

    // prints: "Loading Data"<NEWLINE>
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
    }

    // prints: "Saving Data"<NEWLINE>
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    // prints: "Searching for publication"<NEWLINE>
    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    /*  Calls the search() method.
        prints "Returning publication"<NEWLINE>
        prints "Publication returned"<NEWLINE>
        sets m_changed to true;  */
    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        cout << endl;
        m_changed = true;
    }

    // -------------------- Methods with confirmation --------------------

    // prints "Adding new publication to library"+newline
    // calls the confirm method with "Add this publication to library?"
    // if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl;
    }

    // prints "Removing publication from library"+newline
    // calls the search method
    // calls the confirm method with "Remove this publication from the library?"
    // if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    // calls the search method
    // calls the confirm method with Check out publication?"
    // if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    // -------------------- Constructor --------------------
    // Constructor should initialize and set the attributes and load the publication records from database
    // Initializes the attributes (see the attribute section)
    // populates the Menu attributes
    LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_changed = false;

        // This menu will be used as the main menu of the application and should be initialized with the following title:
        //    "Seneca Libray Application"
        // and then populated with the following menu items:
        //    "Add New Publication"
        //    "Remove Publication"
        //    "Checkout publication from library"
        //    "Return publication to library"
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";

        // This menu will be used when exiting the program if any changes are made to the data. This menu should be initialized with the following title:
        //    "Changes have been made to the data, what would you like to do?"
        // and then populated with the following menu items:
        //    "Save changes and exit"
        //    "Cancel and go back to the main menu"
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";

        // calls the load() method
        load();
    }

    // The run method
    // The run method is the main application driver.

    /*
    suggested pseudo code:
    loop until done
        display menu
        if first option new publication otherwise
        if second option remove publication otherwise
        if third option checkout otherwise
        if fourth option return publication otherwise
            if changed
            Warning menu and choices
            if save selected save and its done otherwise
            if discard selected
                final confirmation for exit
                if exit selected
                    its done (no saving)
                end if
            end if
            otherwise (no change)
            it is done
            end if
        end if
    end loop
    goodbye message
    */
    void LibApp::run()
    {
        int menuSelection = -1, exitSelection = -1;

        // It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
        do
        {
            menuSelection = m_mainMenu.run();
            switch (menuSelection)
            {

            case 0:
                if (m_changed == true) // When the user selects exit, the value of m_changed is examined.
                {
                    // If the value is true, the m_exitMenu is used by calling its run method.
                    exitSelection = m_exitMenu.run();
                    // Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving.
                    switch (exitSelection)
                    {
                    //  If the exit is selected, then the confirm menu will be called using the message: "This will discard all the changes are you sure?".
                    // If the user selects Yes, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            m_changed = false;
                        }
                        break;
                    case 1: // If the first one is selected, the save() method is called and the program terminates.
                        save();
                        break;
                    case 2: // // If the second one is selected the program goes back to the main menu and execution continues.
                        menuSelection = 1;
                        break;
                    }
                }
                cout << endl;
                // If the value is false, then since the data of the application is not modified, the program terminates.
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            }
        } while (menuSelection != 0);

        // When the program is terminated, the following message is printed:
        // -------------------------------------------
        // Thanks for using Seneca Library Application
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
