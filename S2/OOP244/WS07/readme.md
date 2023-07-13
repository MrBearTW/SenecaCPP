# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that make up the hierarchical structure. The base or parent class will be a `MotorVehicle` that holds common attributes of a vehicle with an engine then the child class `Truck` will be derived from the parent class. In addition to this hierarchy, we will define custom input/output operators for these classes.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- inherit a derived class from a base class
- shadow a base class member function with a derived class member function
- access a shadowed member function that is defined in a base class
- utilize custom input/output operators with these classes
- describe to your instructor what you have learned in completing this workshop


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


# lab (part 1) (100%)


## `MotorVehicle` Module

Design and code a class named `MotorVehicle` that holds information about a vehicle with an engine. Place your class definition in a header file named `MotorVehicle.h` and your function definitions in an implementation file named `MotorVehicle.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `MotorVehicle` Class

Design and code a class named `MotorVehicle` that holds information about a vehicle with an engine.


#### `MotorVehicle` Private Members

The class should be able to store the following data:

- a license plate number as a statically allocated array of characters of size 9.
- the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
- the year when the vehicle was built.

You can add any other private members in the class, as required by your design.



#### `MotorVehicle` Public Members

- a custom constructor that receives as parameters the license plate number and the year when the vehicle was built.  Set the location of the vehicle at `Factory`. Assume all data is valid.
- `void moveTo(const char* address)`: moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
  ```txt
  |[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
  ```
  where
  - the license plate is a field of 8 characters aligned to the right
  - current address is a field of 20 characters aligned to the right
  - new address is a field of 20 characters aligned to left

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `MotorVehicle` into a stream and extract a `MotorVehicle` from a stream. These operators should call the `write`/`read` member functions in the class `MotorVehicle`.

## `Truck` Module

Design and code a class named `Truck` that holds information about a motor vehicle that can carry cargo. Place your class definition in a header file named `Truck.h` and your function definitions in an implementation file named `Truck.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Truck` Class

Design and code a class named `Truck` that holds information about a motor vehicle that can carry cargo.  **This class should inherit from `MotorVehicle` class.**


#### `Truck` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
- the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Truck` Public Members

- a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address.  Call the constructor from the base class and pass the license number and year to it.  Set the current cargo to 0 and move the truck to the address specified in the last parameter.
- `bool addCargo(double cargo)`: a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. **Do not exceed the capacity!**  If the current load has been changed, return `true`, otherwise return `false`.
- `bool unloadCargo()`: a mutator that unloads current cargo (sets the attribute to 0).  If the current load has been changed, return `true`, otherwise, return `false`.
- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  Capacity: [USER TYPES HERE]
  Cargo: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `Truck` into a stream and extract a `Truck` from a stream. These operators should call the `write`/`read` member functions in the class `Truck`.

## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

```Text
----------------------------------------
|> T1: Vehicle
----------------------------------------
| 2010 | VVV-111 | Factory

| VVV-111| |             Factory ---> Downtown Toronto    |
| VVV-111| |    Downtown Toronto ---> Mississauga         |
| VVV-111| |         Mississauga ---> North York          |

| 2010 | VVV-111 | North York

----------------------------------------
|> T2: Read/Write
----------------------------------------
Built year: 2020
License plate: abc-111
Current location: Toronto

| 2020 | abc-111 | Toronto

----------------------------------------
|> T3: Truck
----------------------------------------
|  T-1111| |             Factory ---> Toronto HQ          |

|  T-1111| |          Toronto HQ ---> Toronto Deposit     |
Cargo loaded!
| 2015 | T-1111 | Toronto Deposit | 2345/5432

|  T-1111| |     Toronto Deposit ---> Montreal            |
Cargo loaded!
| 2015 | T-1111 | Montreal | 5432/5432

|  T-1111| |            Montreal ---> New York            |
Adding cargo failed!
| 2015 | T-1111 | New York | 5432/5432

|  T-1111| |            New York ---> New Jersey          |
Cargo unloaded!
| 2015 | T-1111 | New Jersey | 0/5432

|  T-1111| |          New Jersey ---> Toronto             |
Unloading cargo failed!
| 2015 | T-1111 | Toronto | 0/5432

----------------------------------------
|> T4: Read/Write
----------------------------------------
Built year: 2019
License plate: def-222
Current location: Montreal
Capacity: 2345
Cargo: 1234

| 2019 | def-222 | Montreal
| 2019 | def-222 | Montreal | 1234/2345

```


## PART 1 Submission

### Data Entry:
```text
2020
abc-111
Toronto
2019
def-222
Montreal
2345
1234
```

### Files to Submit
```text
cstring.cpp  
cstring.h   
MotorVehicle.cpp 
MotorVehicle.h
Truck.cpp
Truck.h
main.cpp
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