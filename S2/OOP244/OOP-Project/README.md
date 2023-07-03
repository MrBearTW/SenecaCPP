# Project: Seneca Library Application

### Milestones

|Milestone| Revision |  Overview<br />session |Comments |
|------|:---:|:---:|:----|
| [MS1](#milestone-1) | V1.0 | | |
| [MS2](#milestone-2) | V1.0 |  |  |
| [MS3](#milestone-3) | V1.0  |  | |
| [MS4](#milestone-4) | V1.0  | |  |
| [MS5](#milestone-5) | V1.0 |  | |

When Books and other publications arrive in the Seneca library, they should be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them. 
Your task is to design an application that receives the publications and stores them into the system with the information needed for their retrieval. 

Later, each publication can be lent out to members of the library with a due date for return.

## Milestones due dates
This project will be done in 5 milestones and each milestone will have its due date. The due date of each milestone is stated below, and it is based on the amount of work to be done for that milestone. 

## Final project mark and due dates

|Milestone| Mark | Due date | Submission Policy|
|:------:|:---:|:---:|-------|
| MS1 | 10% | Jul 8 | gets full mark even if 1 week late. gets 0% afterwards|
| MS2 | 10% | Jul 14 | gets full mark even if 1 week late. gets 0% afterwards|
| MS3 | 10% | Jul 21 | gets full mark even if 1 week late. gets 0% afterwards|
| MS4 | 10% | Jul 26  | gets full mark even if 1 week late. gets 0% afterwards|
| MS5 | 60% | Aug 6  | See below|

> To make the final submission of the project easier and to make it possible to partially submit a project we have divided the submission of milestone 5 into six small ones. Each submission is worth 10% of the project mark. Your project will be marked only if you have all four milestones and at least have one of the 6 six submissions of milestone 5. 

|Milestone 5<br/> Divided into<br/>Six submission| Mark | Due date | Submission Policy|
|:------|:---:|:---:|-------|
| m51 (add) | 10% | Aug 6th| 10% penalty for each day being late up to 5 days|
| m52 (remove) | 10% |Aug 6th| 10% penalty for each day being late up to 5 days|
| m53 (checkout) | 10% | Aug 6th| 10% penalty for each day being late up to 5 days|
| m54 (return) | 10% | Aug 6th| 10% penalty for each day being late up to 5 days|
| m55 (Load Capacity) | 10% | Aug 6th| 10% penalty for each day being late up to 5 days|
| m56 (foolproofing) | 10% | Aug 6th| 10% penalty for each day being late up to 5 days|

> The first 4 milestones will not be marked based on the code, but their success and their timely submissions. You may modify or debug your previous code as you are going through the milestones. The only milestone that is going to scrutinized based your code will be milestone 5. If you require any feedback on your first four milestones you need to ask your professor to do so.

***NOTE:***<br/>
**Your project will receive a mark of zero if any of the first four milestones are not submitted by the rejection date (Aug 11th, 23:59 )<br />For your project to be marked, you must submit the first 4 milestones and at least one of the 6 submissions of Milestone 5**

You can check the due date of each milestone using the ```-due``` flag in the submission command:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number

## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```C++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation to any of the files containing your work will cause the rejection of your project submission**

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> All the code written in the project must be implemented in the **sdds** namespace.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*
- All the code written in this project should be within the namespace sdds.
- You are free and encouraged to add any attributes(member variables), functions and methods (member functions) you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  
- If any methods are being added and they are not called outside the scope of the class, make sure they are private.

- Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.

- When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

- A module called **Utils** is added to the project that can be used for your custom functions and classes in your implementation. Leave this module empty if you don't have any custom functionalities. <br />
You can add any custom code of your own to the **Utils** module to be used throughout the project. <br />  **Utils.h** will be included in all the unit tests of the milestones. 

- You may reuse and copy any code your professor provided for your workshops or functions you may have from previous work in this subject or other subjects and place it in the Utils module. 

# The Project

Before we start developing the application, we need to have a few classes developed to help us with the dates in the system and also the user interface of the application. 


# Milestone 1

## Overview of the Classes to Be Developed for Milestone 1


### Date Class	
A class the encapsulates year, and month and day values for Date stamp, comparison and Date IO purposes. 
### MenuItem Class	
A class that hold a text Item; (an option or title to be displayed) in a menu to be selected by the user. This is a fully private class that is only accessible by Menu (see next class)
### Menu Class	
A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program 


## The Date Class
The Date class was partially implemented by another program that left the company and it is your responsibility to complete the implementation:

The date class encapsulates the following values:
- **Year**; an integer between the year 1500 till today
- **Month**, an integer between 1 and 12
- **Day**, an integer between 1 and the number of days in the month.
- **Error code**; an integer that holds the code that corresponds to an error that recently happened or ZERO if the date object is valid and ready to be used.
- **Current year**; an integer that is automatically initialized to the current date of the system for validation purposes when a Date object is instantiated.

The Date module (implemented in files **Date.h** and **Date.cpp**) is well documented and is placed in the project directory.

## Already implemented methods of the Date class and helper functions of Date

### Private functions:
```C++
int daysSince0001_1_1()const; 
```

returns number of days passed since the date 0001/1/1

```C++
bool validate();             
```

Validates the date setting the error code and then returns true, if valid, and false if invalid.

```C++
void errCode(int theErrorCode); 
```

sets the error code value

```C++
int systemYear()const;         
```

returns the current system year (2021 for this semester)

```C++
bool bad()const;             
```

returns true if the Date is in an erroneous state.

```C++
int mdays()const; 
```

returns the number of days in current month (the month stored in m_mon attribute)

```C++
void setToToday();
```

sets the date to the current date (system date)


### Public functions and Constructors

```C++
Date();
```

creates a date with current date

```C++
Date(int year, int mon, int day); 
```

creates a date with assigned values then validates the date and sets the error code accordingly 


```C++
int errCode()const;
```

returns the error code or zero if date is valid

```C++
const char* dateStatus()const;
```

returns a string stating the current status of the date 


```C++
int currentYear()const;
```

returns the m_CUR_YEAR attribute value

```C++
 std::ostream& operator<<(std::ostream& os, const Date& RO);
 std::istream& operator>>(std::istream& is, Date& RO);
```

Overloads of insertion and extraction operators to call write and read methods of Date 

---------------------------------------------------


> Study the class and learn what each constant, variable and member function does and then using those functions and your knowledge of iostream, cin and cout, add the following member functions to the Date class:

## Your task is to develop the following 

### the read method
```C++
std::istream& read(std::istream& is = std::cin);
```
This function reads a date from the console in the following format YYYY/MM/DD as follows:

- Clears the error code by setting it NO_ERROR
- Reads the year, the month and the day member variables using istream and ignores a single character after the year and the month values to bypass the Slashes.
> Note that the separators do not have to be Slash characters **“/”** but any separator that is not an integer number.
- Checks if istream has failed. If it did fail, it will set the error code to CIN_FAILED and clears the istream. If not, it will validate the values entered.
- Flushes the keyboard
- Returns the istream object

------------------------

### The write method
```C++
std::ostream& write(std::ostream& os = std::cout)const;
```
If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”.
Otherwise, the function should write the date in the following format using the ostream object:
- Prints the year
- Prints a Slash “/”
- Prints the month in two spaces, padding the left digit with zero if the month is a single-digit number
- Prints a Slash “/”
- Prints the day in two spaces, padding the left digit with zero if the day is a single-digit number 
- Makes sure the padding is set back to spaces from zero 
- Returns the ostream object.

--------------------------

### Comparison operator overload methods
Overload the following comparison operators to compare two dates.

```C++
bool operator==
bool operator!=
bool operator>=
bool operator<=
bool operator<
bool operator>
```
Use the return value of the **daysSince0001_1_1()** method to compare the two dates:

--------------------------------

### Operator- method

Returns the difference between two Dates in days. 

#### Example
```C++
Date
      D1(2023, 12, 02),
      D2(2023, 11, 11);
int days = D1 - D2;

```
**days** in the above code snippet will hold the value 21.

-----------------------

### bool type conversion operator

It will return true if the date is valid and false if it is not.

------------------------


## Date Tester program

Write your own tester or use the following tester program to test and debug your Date class.

[dateTester.cpp](MS1/dateTester.cpp)

### output sample

> Note that the current date will change based on the day of execution

```Text
Current Date: 2023/06/26
0 days since ms1 was published
Please enter a date to be compared to 2023/06/26
(Also try some invalid values for testing):
YYYY/MM/DD > abc
cin Failed, Please try again > 2023/0/0
Bad Month Value, Please try again > 2023/10/30
Your Entry: 2023/10/30
Set by program to 2023/06/26: 2023/06/26
Days between the two dates: 126
All the following statements must be correct:
2023/10/30 > 2023/06/26
2023/10/30 >= 2023/06/26
2023/10/30 > 2023/06/26
2023/10/30 >= 2023/06/26
2023/10/30 != 2023/06/26
2023/10/30 != 2023/06/26
```


## The Menu Module

Create a module called Menu (in files Menu.cpp and Menu.h) this module will hold both MenuItem and Menu Classes’ implementation code. 

> Since the Menu class owns its MenuItem objects, it must have full control over the MenuItem creation. To implement this, have the declaration of the MenuItem and Menu class in the following sequence:
> - Forward declare the class Menu in the header file.
> - Implement the MenuItem class declaration (fully private) with Menu class as a friend. (see **MenuItem** class)
> - Implement the Menu class declaration.  (See **Menu** Class)

### The MenuItem Class
Create a class called MenuItem. This class holds only one Cstring of characters for the content of the menu item dynamically. The length of the content is unknown.
This class should be fully private (no public members; even constructor is private!):

Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
```C++
   friend class Menu;
```

### Constructor 
Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization). If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.

### Rule of Three 
A MenuItem object cannot be copied from or assigned to another MenuItem object.<br />
*(Copy constructor and Copy assignment are deleted)*

#### Destructor 
Deallocates the content


### `bool` type conversion
When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.

### `const char*` type conversion
When a MenuItem is casted to “const char*” it should return the address of the content Cstring.

### displaying the MenuItem
Create a method to display the content of the MenuItem on ostream. *(No newline is printed after)* <br />Nothing is printed if MenuItem is empty.

> Remember that the MenuItem class is fully private.

### The Menu Class
Create the Menu class as follows:

#### Rule of Three

A Menu Object can not be copied or assigned to another Menu Object. *(Copy constructor and Copy assignment are deleted)*

#### Attributes
This class has a minimum of three attributes.
1) A MenuItem to possibly hold the title of the Menu.
2) An array of MenuItem pointers. The size of this array is set by a constant unsigned integer defined in the Menu header file; called **MAX_MENU_ITEMS**. Have the **MAX_MENU_ITEMS** integer initialized to 20.
This array will keep potential MenuItems added to the Menu. Each individual element of this array will hold the address of a dynamically allocated MenuItem as they are added to the Menu. *(See insertion operator overload for Menu)* <br />Initialize this array of pointers to **nullptr**s.  
3) An integer to keep track of how many MenuItem pointers are pointing to dynamic MenuItem objects. *(obviously, the value of this variable is always between 0 and MAX_MENU_ITEMS)*.

#### Constructors
A Menu is always created empty; with no MenuItems, with or without a title.<br /> Example:
```C++
Menu A;
Menu B("Lunch Menu");
```

#### Destructor
Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.

#### Methods
- Suggestion: create a function to display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.
- Create a function to display the entire Menu on ostream: <br />
This function first displays the title (if it is not empty) followed by a **":"** and a new-line, then it will display all the MenuItems one by one; adding a row number in front of each. The row numbers are printed in two spaces, right justified followed by a **"dash"** and a **"space"**. 
After printing all the MenuItems it should print `" 0- Exit"` and new-line and `"> "`. <br />
For example if the title is "Lunch Menu" and the menu items are "Omelet", "Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:<b />
```Text
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```

- Create a member function called **`run`**. This function displays the Menu and gets the user selection.<br />
    *(this function should be completely foolproof)*
    The function receives nothing and returns an unsigned integer (That is the user’s selection). 
    After displaying the menu, ask for an integer and make sure the value of the integer is between 0 and the number of the menu items. If the user enters anything incorrect, print:<br />
    `"Invalid Selection, try again: "`<br />
    and get the integer again until a valid selection is made.

    > Nice to do:<br />  The action of a foolproof integer entry within limits, with a prompt and an error message is a good candidate for a separate function implementation in the Utils module

- Overload **`operator~`** to do exactly what the run function does (two different ways to run the menu)

- Overload a **member** insertion operator (operator<<) to add a MenuItem to the Menu.
    ```C++ 
    Menu& Menu::operator<<(const char* menuitemConent);
    ```
 
    This operator receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).

    To accomplish this, check if the next spot for a MenuItem is available in the array of MenuItem pointers. If it is, dynamically create a MenuItem out of the content received through the operator argument and then store the address in the available spot and finally increase the number of allocated MenuItem pointers by one.

    If no spot is available, ( that is; if number of allocated MenuItem pointers is equal to  MAX_MENU_ITEMS) this function silently ignores the action.

    At the end, return the reference of the Menu object. 
    
    Usage example:
    
    ```C++
    int a;
    Menu M;
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    a = M.run()
    cout << "Your selection " << a << endl;
    ```
    
    output:
    ```Text
     1- Omelet
     2- Tuna Sandwich
     3- California Rolls
     0- Exit
     > 3 <ENTER>
    Your selection 3
    ```

- Overload two type conversions for **`int`** and **`unsigned int`** to return the number of MenuItems on the Menu.

- Overload the type conversion for **`bool`** to return true if the Menu has one or more MenuItems otherwise, false;

- Overload the insertion operator to print the title of the Menu using **cout**.

    Example for the last three overloads:

    ```C++
    Menu M ("Lunch Menu");
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    if (M) { // bool conversion
      cout << "The " << M << " is not empty and has "      //  insertion operator overload
            << unsigned int(M) << " menu items." << endl;  //  const int conversion (int conversion not tested)
    }
    ```

    Output:

    ```Text
    The Lunch Menu is not empty and has 3 menu items.
    ```

- Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
    If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)  
    Example:
    ```C++
    Menu M;
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    cout << M[0] << endl;
    cout << M[1] << endl;
    cout << M[3] << endl; // << note that the last valid index is "2"
    ```
    The above code snippet will print the following:
    ```Text
    Omelet
    Tuna Sandwich
    Omelet
    ```
## Menu tester program
Write your own tester or use the following tester program to test and debug your Menu class.

[menuTester.cpp](MS1/menuTester.cpp)

### Sample Execution

```Text
The >< menu is empty
The Lunch Menu is not empty and has 3 menu items.
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> abc
Invalid Selection, try again: 5
Invalid Selection, try again: -1
Invalid Selection, try again: 0
 1- Order more
 0- Exit
> 0
Your orders:
2 Omelets
3 Tuna Sandwichs

```

# ms1_tester.cpp
This file contains both date and menu testers functions and runs them at once for submission:

[ms1_tester.cpp](MS1/ms1_tester.cpp)

[ms1_tester output](MS1/ms1_tester_output.md)


## MS1 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Date.cpp, Date.h, Menu.cpp, Menu.h and ms1_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

# Milestone 2
## The Seneca Library Application Module
Your task for milestone 2 is to build a mockup application for the Seneca Library Application in a module called LibApp. 

The **LibApp** class demos the execution of the Seneca Library Application with printing messages instead of actually doing the tasks.

Later these messages are replaced with actual working modules to make the application functional. 

Creating a mockup application before developing the main program helps to understand the entire system and also demonstrates the execution of the program to the client before the application is fully developed.

You are going to use the Menu Module in this milestone. 
### Modules (files) included in this milestone:
```Text
Utils.cpp
Utils.h
Menu.cpp
Menu.h
LibApp.cpp
LibApp.h
ms2_tester.cpp
```
Before starting the milestone you have to make a minor modification to the title of the Menu class: 

> *Remove the colon **(":")** character after displaying the title of the Menu*
#### MS1 MENU:
```Text
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```
#### MS2 Menu:
```Text
Lunch Menu
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```

> Note: these types of modifications to previously written code are very common to accommodate newly developed logic.

## The LibApp Module

create a class called **LibApp** with following attributes:

### LibApp Attributes
```C++
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;
```

#### `m_changed`
A flag to keep track of changes made to the application data. This flag is initially set to false. 
If any change is made to the data of the application, this flag is set to true. 

Doing so, when exiting the program, we can warn the user and ask if they like the changes to be saved or discarded.

#### `m_mainMenu`
This menu will be used as the main menu of the application and should be initialized with the following title:
```text
"Seneca Libray Application"
```
and then populated with the following menu items:
```text
"Add New Publication"
"Remove Publication"
"Checkout publication from library"
"Return publication to library"
```

#### `m_exitMenu`
This menu will be used when exiting the program if any changes are made to the data. This menu should be initialized with the following title:
```text
"Changes have been made to the data, what would you like to do?"
```
and then populated with the following menu items:
```text
"Save changes and exit"
"Cancel and go back to the main menu"
```

### Private Methods
```C++
bool confirm(const char* message);
```
Instantiate a **Menu** in this function and initialize it with the **message** argument.

Then add only a `"yes"` as a single menu item to the Menu.  

Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
#### Simple private fuctions:
```C++
      void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      void search();  // prints: "Searching for publication"<NEWLINE>
      
      void returnPub();  /*  Calls the search() method.
                             prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
```
#### Methods with confirmation
```C++
void newPublication();
```
prints `"Adding new publication to library"`+newline<br />
calls the confirm method with `"Add this publication to library?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication added"` + newline<br />
```C++
void removePublication();
```
prints `"Removing publication from library"`+newline<br />
calls the search method<br />
calls the confirm method with `"Remove this publication from the library?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication removed"` + newline<br />
```C++
void checkOutPub();
```
calls the search method<br />
calls the confirm method with `Check out publication?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication checked out"` + newline<br />

## Constructor
Constructor should initialize and set the attributes and load the publication records from database
- Initializes the attributes (see the attribute section)
- populates the Menu attributes
- calls the `load()`` method

## The run method

The run method is the main application driver.

It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.

When the user selects exit, the value of `m_changed` is examined. 
If the value is false, then since the data of the application is not modified, the program terminates.

If the value is true, the `m_exitMenu` is used by calling its run method. Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving. 

If the first one is selected, the `save()` method is called and the program terminates.

If the second one is selected the program goes back to the main menu and execution continues.

If the exit is selected, then the confirm menu will be called using the message: `"This will discard all the changes are you sure?"`.  If the user selects **Yes**, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.


When the program is terminated, the following message is printed:
```Text
-------------------------------------------
Thanks for using Seneca Library Application
```

### suggested pseudo code:
```text
loop until done
    display menu
    if first option  new publication otherwise
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
```

## Tester program

[ms2_tester.cpp](MS2/ms2_tester.cpp)

### Data Entry
```Text
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
```

### output

[MS2 Output](ms2_output.md)


## MS2 Submission


> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.cpp, Menu.h, LibApp.cpp, LibApp.h and ms2_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m2
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


# Milestone 3
## Streamable Interface module and Publication class module

TBA

## [Back to milestones](#milestones)


# Milestone 4

## The **Book** class

TBA

# Milestone 5
## The Seneca Library Application

TBA

## [Back to milestones](#milestones)


