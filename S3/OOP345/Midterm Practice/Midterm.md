# Midterm Practice

## Midterm Details

## Midterm Part1 Practice (Concepts)
- 3 4 sentence is good enough

### Question 1
Q: Describe what an enumeration (enum) is and the difference between plain enums and scoped enums.


### Question 2
Q: Describe the idea of a compile time evaluation and provide an example of one.


### Question 3
Q: What is an anonymous class? How does it differ from a named class?



## Midterm Practice Part2 (Programming)

### Question 1

Inspect the following type definition below which is used to store an on/off switch.

```cpp
enum class StateType
{
    boolean,
    character,
    number
};
 
typedef struct
{
    char name[20];
    StateType sType;    
    union
    {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch;  
```
A switch is considered ON if the value satisfies one of the conditions below.

State Type: sState (“on” value)

boolean --> true
character --> ‘O’
number --> 1







Use the Switch definition above to build a class that models a home stereo system. Such a system will have output channels such as TV, DVD, Bluetooth device, Computer, etc. Each Switch object represents the current state of an output channel.



Basic Details
Your HomeStereo class has the following data members

- an array of dynamically allocated Switch-typed values
- a non-negative integer that stores the number of values in the array


A HomeStereo object can be created using a 2-argument Constructor.



Public Member Functions
displayOutputState(): receives an ostream reference (defaults to standard output) and returns an ostream reference. This function inserts the state of all switches into the given output stream. The output should be in the following form.
```
Channel Name: xxxxxx - State [on/off]< endl >
Channel Name: xxxxxx - State [on/off]< endl >
...  
```


Other Features
Include in your design all special member functions required to manage your objects.



Misc
You are allowed to add as many private members as your design requires!

Put in the answer box the content of your header file and implementation file. Both files must be properly created according to C++ standard and best practices.


### Question 2

Define a family of functions (a templated function) named insertAtEnd that inserts in a dynamically-allocated array of elements of any type another element at the end (resize the array). The function should receive as parameters:


    - the dynamically-allocated array
    - the size of the array
    - the element to insert


The function should return the resulted array.



Specialize the function for the type char. In this specialization the array must be null-terminated; the size parameter doesn’t count the null-byte.



The client code listed below uses your templated function, and should not contain memory leaks. The comments next to each statement shows the content the array should have after the statement is executed.



Write your solution in the textbox below.
```cpp
// assume all necessary headers have been included
 
int main()
{
    {
        int* arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1); // 1
        arrI = insertAtEnd(arrI, 1, 5); // 1, 5
        arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
        delete[] arrI;
    }
    {
        double* arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
        arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
        delete[] arrD;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');// a\0
        arrC = insertAtEnd(arrC, 1, 'b');// ab\0
        arrC = insertAtEnd(arrC, 2, 'c');// abc\0
        cout << arrC;
        delete[] arrC;
    }
}  
```


## Midterm Practice Part3 (Walkthrough)

### Question 1

Provide the output of the following program:
```cpp
#include <iostream>
using namespace std;
 
enum Vals { AV = 1, BV = 2, CV = 3 };
 
struct Foo{
  Vals val{};
 
  Foo& goo() {
    if (val == AV)
      val = BV;
    if (val == BV)
      val = CV;
    if (val == CV)
      val = AV;
    return *this;
  }
  Foo& boo(){
    if (val == AV)
      val = CV;
    if (val == BV)
      val = AV;
    if (val == CV)
      val = BV;
    return *this;
  }
};
 
ostream& operator<<(ostream& os, const Foo& f){
  os << f.val << endl;
  return os;
}
 
int main(){
 
  Foo f{AV};
  cout << f.goo();
  cout << f.boo();
  cout << (f.goo()).boo();
  cout << (f.boo()).goo();
}
```


 
### Question 2

Provide the output of the following program:


```cpp
#include <iostream>
using namespace std;
 
struct Foo{
  void goo(){
    cout << "Hi!" << endl;
  }
  auto moo(unsigned& v) -> decltype(v / 0.0){
    return v / 2.0;
  }
  auto boo(unsigned&& v) -> decltype(v * 0.0){
    return v * 2.0;
  }
};
 
int main()
{
  unsigned a[3] = { 1, 3, 5 };
 
  cout << (a[0] + a[1]) << endl;
  cout << (a[2]) << endl;
  cout << sizeof(a) / sizeof(a[0]) << endl;
 
  Foo f;
  f.goo();
  cout << f.moo(a[1]) << endl;
  cout << f.boo(8) << endl;
}
```


### Question 3
Provide the output of the following program:

```cpp
#include <iostream>
using namespace std;
 
struct thing{
  std::string name;
  std::string operator*(unsigned v){
    return name += to_string(v);
  }
  operator string() const{ return name; }
};
 
template<typename T, typename S>
auto foo(T& v1, S v2) -> decltype(v1 * v2){
  return v1 * v2;
}
 
template<>
auto foo(thing& v1, unsigned v2) -> decltype(v1 * v2){
  for (auto i = 0u; i < v2; ++i)
    v1.name += "E";
  return v1 * v2;  
}
 
int main(){
  unsigned x{1}, y{5};
  double a{1.1}, b{2.2};
  thing c{"NA"}, d{"CL"};
  cout << foo(x, y) << endl;
  cout << foo(x, a) << endl;
  cout << foo(a, b) << endl;
  cout << foo(c, x) << endl;
  cout << foo(d, y) << endl;
}
```

## Midterm Practice Part4 (Debugging)

### Question 1
The code below contains five (5) syntactic errors under C++17 standard (errors that are caught by a compiler or generate crashes/undefined behaviour at runtime).

```cpp
// A.h
#ifndef A_H 
#define A_H
struct A
{
public:
    double m_val;
public:
    A operator+=(const A &other)
    {
        this->m_val += other.m_val;
        return *this;
    } 
    double getValue() const { return m_val; }
}
;
decltype(A().getValue()) operator+=(double &val, const A &other);

// "data" is an array of "N" elements of type "T"
template <typename T, double N>
T process(const T *data)
{
    T sum;
    for (const auto &elem : data)
        sum += elem;
    return sum;
}
#endif
```

```cpp
// A. cpp
#include "A.h"

decltype(A().getValue()) operator+=(double &val, const A &other)
{
    return val += other.getValue();
}
```

```cpp
// main.cpp
#include <iostream>
#include "A.h"
using namespace std;

int main()
{
    int arrI[5]{0, 1, 2, 3, 4, 5};
    cout << process(arrI) << endl;

    A arrA[5]{{1.2}, {2.3}, {3.4}, {4.5}};
    cout << process(arrA) << endl;
}
```