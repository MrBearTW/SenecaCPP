# Workshop #10: Function Templates
Version 1.0

In this workshop, you are to code two function templates:
- to search through a compound type array and insert the matches found in the array, into a Collection of the same compound type.
- to list elements of an array with a title

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

-	code function templates
-	implement calls to function templates
-	describe what you have learned in completing this workshop


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

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

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.


# PART 1 (100%)

Look at the code provided in the **Collection** template module, study it and understand it. The Collection class is a template that works like a dynamic array of objects and resizes itself as objects are added to it. The code snippet below demonstrates how Collection works:  
```C++
Collection<double> Cdbl;
Cdbl.add(1.23);
Cdbl.add(2.34);
Cdbl.add(3.45);
cout << "There are " << Cdbl.size() << " items in the Collection!" << endl;
for(int i=0; i< Cdbl.size();i++){
    cout << Cdbl[i] << endl;
}
```
Output:
```Text
There are 3 items in the Collection!
1.23
2.34
3.45
```
## Supplied Modules:
- Collection
- ReadWrite 
- Employee
- Student
- Car

**Do not modify these modules!**  Look at the code and make sure you understand them.

## searchNlist module
Implement this module in 'searchNlist.h' header file.
### `search` function template

Create a function template called **search** that accepts four arguments in any order you prefer:
- A reference to a Collection of templated objects (template type 1). The Collection is defined in **Collection.h** 
- An array of templated objects; the same type as the Collection type. (template type 1)
- Number of elements in the array of objects
- A  **key** templated value to search for, in the array of objects. (template type 2)


The search function template returns a bool that is true only if at least one match to the key is found in the array of objects and false otherwise. 

The search function goes through all the elements of the array of objects and adds all the matches found to the Collection. (use the "==" operator to check for  a match between the objects and the key) 

### listArrayElements
Lists all the elements of an array. 

Create a function template called **listArrayElements** that accepts three arguments in any order you prefer:
- A `const char*` for a Title to be printed as the Title of the list.
- A constant array of templated objects (template type)
- The number of the elements of the array.

This function first prints the **Title** and then goes to newline.

Then it will print the row number and then insert each element of the array into cout with a newline attached.

For example, if this function is called for the following array of integers.
```C++
int a[]{10,20,30,40};
```
using the Title value of "INTEGERS" and the number of elements as 4, the output would be like the following.
```text
INTEGERS
1: 10
2: 20
3: 30
4: 40
```

### Template type requirements
Have a comment section for both functions and explain what requirements each of types of your templates must have to be able to work with your logic.

Then also copy these comments to the part 2 reflection of the workshop.

## The main module
> In this workshop you are modifying the main module. Make sure to update the comments at the top to reflect your work on the module

Modify the main module and call the **search** function as the condition of the four **if** statements in the source code.
> See the comments in **main.cpp**

Also, call the **listArrayElement** function four times before the first three **if** statement and at the end of the main() function to list the elements of the integer array **a**.
> See the comments in **main.cpp**


```C++
/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
// tester program
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;

int main() {
   Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"), 
                Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"), 
                Car("GVDEFG", "Tesla Model X") };
   Student S[6] = { Student(23456, "Lisa Simpson",4.0),Student(45678, "Ralph Wiggum",2.1), Student(56789, "Milhouse Van Houten",4.0), 
                Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz",3.0),Student(12345, "Bart Simpson",1.5) };
   Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56,111), Employee(122345, "Mindy Simmons", 65432.44,222), 
                Employee(435678, "Lenny Leonard", 43213.22,111), Employee(546789, "Waylon Smithers", 654321.55,333), 
                Employee(657890, "Frank Grimes", 34567.88,333), Employee(364567, "Homer Simpson", 55432.11,111) };

   Collection<Car> Cres;
   Collection<Student> Sres;
   Collection<Employee>Eres;

   // Call the  listArrayElements to list all cars, Title: "All the cars:"
   listArrayElements(.........................);
   cout << "Searching for Tesla cars: " << endl;
   // Call the search function to search the array C 
   // and store the matches in Cres passing "Tesla" as the key argument
   if (search(...........................)) {
      cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Cres.size(); i++) {
         cout << (i + 1) << ": " << Cres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // Call the  listArrayElements to list all the students, Title: "All students:"
   listArrayElements(..................................);

   cout << "Searching for students with 4.0 Gpa:" << endl;
   // Call the search function to search the array S 
   // and store the matches in Sres passing 4.0 as the key argument
   if (search(..................................)) {
      cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Sres.size(); i++) {
         cout << (i + 1) << ": " << Sres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // Call the  listArrayElements to list all the employees, Title: "All employees:"
   listArrayElements(...................................);

   cout << "Searching for employees who share office number 111:" << endl;
   // Call the search function to search the array E 
   // and store the matches in Eres passing 111 as the key argument
   if (search(.................................)) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   cout << "Searching for employees who share office number 555:" << endl;
   // Call the search function to search the array E 
   // and store the matches in Eres passing 555 as the key argument
   if (search(...............................)) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   int a[]{ 10,20,30,40,50,60 };
   // Call the  listArrayElements to list all the integers in the array a
   // Title: "INTEGERS"

   listArrayElements(...........................);
   return 0;
}
```
## output

```Text
All the cars:
1: GVFGHI Tesla Model S
2: ABCDEF BMW 320
3: CDEFGH Ford Festiva
4: BCDEFG Ford Festiva
5: GVDGHI Tesla Model 3
6: EFGHIJ Nissan Maxima
7: GVDEFG Tesla Model X
Searching for Tesla cars:
3 matches found:
1: GVFGHI Tesla Model S
2: GVDGHI Tesla Model 3
3: GVDEFG Tesla Model X

All students:
1: 23456 Lisa Simpson GPA: 4.0
2: 45678 Ralph Wiggum GPA: 2.1
3: 56789 Milhouse Van Houten GPA: 4.0
4: 67890 Todd Flanders GPA: 3.5
5: 34567 Nelson Muntz GPA: 3.0
6: 12345 Bart Simpson GPA: 1.5
Searching for students with 4.0 Gpa:
2 matches found:
1: 23456 Lisa Simpson GPA: 4.0
2: 56789 Milhouse Van Houten GPA: 4.0

All employees:
1: 213456 Carl Carlson (Office# 111) Salary: $62344.56
2: 122345 Mindy Simmons (Office# 222) Salary: $65432.44
3: 435678 Lenny Leonard (Office# 111) Salary: $43213.22
4: 546789 Waylon Smithers (Office# 333) Salary: $654321.55
5: 657890 Frank Grimes (Office# 333) Salary: $34567.88
6: 364567 Homer Simpson (Office# 111) Salary: $55432.11
Searching for employees who share office number 111:
3 matches found:
1: 213456 Carl Carlson (Office# 111) Salary: $62344.56
2: 435678 Lenny Leonard (Office# 111) Salary: $43213.22
3: 364567 Homer Simpson (Office# 111) Salary: $55432.11

Searching for employees who share office number 555:
No matches found!

INTEGERS
1: 10
2: 20
3: 30
4: 40
5: 50
6: 60
```
## PART 1 Submission 


### Files to submit
```Text
Collection.h
Car.h
Car.cpp
Employee.h
Employee.cpp
Student.h
Student.cpp
ReadWrite.h
ReadWrite.cpp
main.cpp
serchNlist.h
```

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty
# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.



# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.
> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
