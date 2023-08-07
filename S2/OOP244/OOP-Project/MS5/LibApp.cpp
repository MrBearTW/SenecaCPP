#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "LibApp.h"
#include "PublicationSelector.h"

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

    // The load method
    // See the pubSel_Tester.cpp that uses a similar logic to load the publications for example...
    void LibApp::load()
    {
        // First print "Loading Data" and then open the data file for reading and read all the publications in dynamic instances pointed by the PPA Array.
        cout << "Loading Data" << endl;

        char single_character_type{};
        std::ifstream infile(m_filename); // Need #include <fstream>

        // Do this by first reading a single character for the type of publication and then dynamically instantiating the corresponding object into the next available PPA element. Then extract the object from the file stream and add one to the NOLP. Since the extraction operator calls the proper read function virtually, the object will be properly read from the file.
        // Continue this until the ifstream reading fails.
        for (int i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++)
        {
            infile >> single_character_type;
            infile.ignore();
            if (infile)
            {
                if (single_character_type == 'P')
                {
                    m_ppa[i] = new Publication;
                }
                else if (single_character_type == 'B')
                {
                    m_ppa[i] = new Book;
                }

                if (m_ppa[i])
                {
                    infile >> *m_ppa[i];
                    m_nolp++;
                    // At the end set the LLRN to the reference number of the last publication read.
                    m_llrn = m_ppa[m_nolp - 1]->getRef();
                }
            }
        }
    }

    // The save method
    void LibApp::save()
    {
        // First print "Saving Data"
        cout << "Saving Data" << endl;
        // and then open the data file stream for overwriting. (ofstream) Go through the elements of PPA up to the N0LP. Insert all elements into the ofstream object except those with 0 (zero) as Library Reference Number. (return value of getRef() method)
        std::ofstream outfile(m_filename);
        for (int i = 0; i < m_nolp; i++)
        {
            // Publications that have the reference number of 0 (zero) are deleted by the user (removed from the library) and therefore should not be saved back into the data file. We refer to these publications as deleted ones.
            if (m_ppa[i]->getRef() != 0)
            {
                outfile << *m_ppa[i] << std::endl;
            }
        }
        // At the end, close the file stream.
        outfile.close();
    }

    // SearchMode
    // 1. Search all
    // 2. Search Checkout Items Search only those publications which are on loan by library members
    // 3. Search Available Items Search only those publications which are not on loan
    int LibApp::search(int searchMode)
    {
        // Search will use an instance of PublicationSelector class to collect the search matches and user selection. The prompt of the PublicSelector should be: "Select one of the following found matches:" The page size for the selector menu should be 15 (the default value)
        PublicationSelector selector("Select one of the following found matches:");

        // First, get the type of publication to search for from the user. (user the type selection Menu of the class)
        int pubTypeInt = m_pubTypeMenu.run();
        cin.ignore(1000, '\n');
        char title[256]{};
        char pubTypeIntToChar;

        if (pubTypeInt == 1)
        {
            pubTypeIntToChar = 'B';
        }
        else if (pubTypeInt == 2)
        {
            pubTypeIntToChar = 'P';
        }
        // Then print "Publication Title: " and get the title to search the PPA for. (up to 256 characters)
        std::cout << "Publication Title: ";
        std::cin.getline(title, 256, '\n');

        // Go through all the publications in the PPA and base on the method of search (all the items, on loan items or available ones) check each element and if the publication (pointed by the PPA element) is not deleted and type matches the selection of the user and the title contains the title the user entered, insert it into the PublicationSelector object.
        if (searchMode == 1)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                // if (m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == pubTypeIntToChar && ((char *)(m_ppa[i])) == (title))
                if (m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == pubTypeIntToChar && m_ppa[i]->operator==(title))
                {
                    selector << m_ppa[i];
                }
            }
        }
        else if (searchMode == 2)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                if (m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == pubTypeIntToChar && m_ppa[i]->operator==(title) && m_ppa[i]->onLoan())
                {
                    selector << m_ppa[i];
                }
            }
        }
        else if (searchMode == 3)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                if (m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == pubTypeIntToChar && m_ppa[i]->operator==(title) && !m_ppa[i]->onLoan())
                {
                    selector << m_ppa[i];
                }
            }
        }

        // If matches are found, sort the result and get the user's selection and return the library reference number. If not print "No matches found!"
        // If the user aborts at any stage print "Aborted!"
        if (selector)
        {
            selector.sort();
            int removeLibRef = selector.run();
            if (removeLibRef > 0)
            {
                std::cout << *getPub(removeLibRef) << endl;
                return removeLibRef;
            }
            else
            {
                std::cout << "Aborted!" << endl;
                return -1;
            }
        }
        else
        {
            std::cout << "No matches found!" << endl;
            return -1;
        }
    }

    // The returnPub() Method
    void LibApp::returnPub()
    {
        // Print: "Return publication to the library"
        cout << "Return publication to the library" << endl;
        // Search for "on loan" publications only
        int returnLibRef = search(2);
        // If the user selects a publication and confirms the return using the prompt: "Return Publication?"
        if (returnLibRef != -1 && confirm("Return Publication?"))
        {
            // If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
            if (Date() - getPub(returnLibRef)->checkoutDate() > SDDS_MAX_LOAN_DAYS)
            {
                // Following message is printed: Please pay $9.99 penalty for being X days late!, 9.99 is replaced with the penalty value and X is replaced with the number of late days.
                cout << "Please pay $" << fixed << setprecision(2) << (Date() - getPub(returnLibRef)->checkoutDate() - SDDS_MAX_LOAN_DAYS) * 0.5 << " penalty for being " << Date() - getPub(returnLibRef)->checkoutDate() - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
            }
            // set the membership number of the publication to 0 (zero)
            getPub(returnLibRef)->set(0);
            // set the "changed" flag to true
            m_changed = true;
            // print: "Publication returned"
            cout << "Publication returned" << endl;
        }
        cout << endl;
    }

    // -------------------- Methods with confirmation --------------------

    // The newPublication() method
    void LibApp::newPublication()
    {
        // If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.
        if (m_nolp == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else // Otherwise,
        {
            // print: "Adding new publication to the library"
            cout << "Adding new publication to the library" << endl;
            // get the publication type from the user.
            int pubTypeInt = m_pubTypeMenu.run();
            cin.ignore(1000, '\n');

            // in a publication pointer, instantiate a dynamic (2)"Publication" or (1)"Book" based on the user's choice.
            Publication *pub = nullptr;

            if (pubTypeInt == 0)
            {
                cout << "Aborted!" << endl;
            }
            else
            {
                if (pubTypeInt == 1)
                {
                    pub = new Book;
                    cin >> *pub;
                }
                else if (pubTypeInt == 2)
                {
                    pub = new Publication;
                    cin >> *pub;
                }

                // Read the instantiated object from the cin object.
                // If the cin fails, flush the keyboard, print "Aborted!" and exit.
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Aborted!" << endl;
                }
                // If the cin is ok, then confirm that the user wants to add the publication to the library using this prompt: "Add this publication to the library?".
                else
                {
                    if (confirm("Add this publication to the library?"))
                    {
                        // After the user confirms, if the publication object is valid
                        if (pub)

                        { // Add one to the LLRN and set the library reference number to the value
                            m_llrn++;
                            pub->setRef(m_llrn);
                            // Add the publication object's address to the end of the PPA and add one to the NOLP.
                            m_ppa[m_nolp] = pub;
                            m_nolp++;
                            // set the "changed" flag to true
                            m_changed = true;
                            // print: "Publication added"
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            // If the publication object is not valid print: "Failed to add publication!" and delete the allocated memory.
                            cout << "Failed to add publication!" << endl;
                            delete pub;
                        }
                    }
                    // If the user did not confirm, print "Aborted!" and exit.
                    else
                    {
                        cout << "Aborted!" << endl;
                    }
                }
            }
        }
        cout << endl;
    }

    void LibApp::removePublication()
    {
        // print: "Removing publication from the library"
        cout << "Removing publication from the library" << endl;
        // Search all the publications
        int removeLibRef = search(1);

        // If the user selects a publication and confirms to remove the publication using the prompt: "Remove this publication from the library?"
        if (removeLibRef != -1)
        {
            if (confirm("Remove this publication from the library?"))
            {
                // Set the library reference of the selected publication to 0 (zero)
                getPub(removeLibRef)->setRef(0);
                // set the "changed" flag to true
                m_changed = true;
                // print: "Publication removed"
                cout << "Publication removed" << endl;
            }
        }
        cout << endl;
    }

    // The checkOutPub method

    void LibApp::checkOutPub()
    {
        // print: "Checkout publication from the library"
        cout << "Checkout publication from the library" << endl;
        // Search in available publications only
        int checkOutLibRef = search(3);
        if (checkOutLibRef != -1)
        {
            // If the user selects a publication and confirms to checkout using the prompt: "Check out publication?"
            if (confirm("Check out publication?"))
            {
                int inputMemNum;
                cout << "Enter Membership number: ";
                // read a 5 digit number from the console, if invalid print: "Invalid membership number, try again: " and read again
                cin >> inputMemNum;
                while (cin.fail() || inputMemNum < 10000 || inputMemNum > 99999)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid membership number, try again: ";
                    cin >> inputMemNum;
                }
                // set the membership number of the selected publication the integer value.
                getPub(checkOutLibRef)->set(inputMemNum);
                // set the changed flag to true
                m_changed = true;
                // print: "Publication checked out"
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
    }

    // -------------------- Constructor --------------------
    // Constructor should initialize and set the attributes and load the publication records from database
    // Initializes the attributes (see the attribute section)
    // populates the Menu attributes
    // This menu will be used as the main menu of the application and should be initialized with the following title:
    //    "Seneca Libray Application"
    // Add a Menu to the LibApp for selection of publication type. The title of this menu is: "Choose the type of publication:"

    LibApp::LibApp(const char *filename) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubTypeMenu("Choose the type of publication:")
    {
        m_changed = false;

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

        // File name
        if (filename)
        {
            strcpy(m_filename, filename);
        }
        else
        {
            cout << "Invalid file name!" << endl;
        }

        // Publication Pointers Array
        // Publication *m_ppa[SDDS_LIBRARY_CAPACITY];
        // Did not need to do this because the array is already declared in the header file.

        // Number Of Loaded Publications
        m_nolp = 0;

        // Last Library Reference Number
        m_llrn = 0;

        // Publication Type Menu
        // The publication type menu should also provide two selections: "Book" and "Publication".
        m_pubTypeMenu << "Book"
                      << "Publication";

        // calls the load() method
        load();
    }

    // Destructor
    LibApp::~LibApp()
    {
        // deletes all the dynamically allocated publications in the PPA.
        for (int i = 0; i < m_nolp; i++)
        {
            delete m_ppa[i];
        }
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

    // Publication* getPub(int libRef) method
    // Just return the "pointer" to the publication with the library reference number "libRef" from the PPA.
    // Create a method to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
    Publication *LibApp::getPub(int libRef)
    {
        // If no publication is found, this function returns nullptr.
        Publication *temp_pub = nullptr;
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i]->getRef() == libRef)
            {
                temp_pub = m_ppa[i];
            }
        }
        return temp_pub;
    }
}
