// There are 6 errors in the following code (eg. Compile, Undefined Behavior, Memory Leak, Runtime Crash...). Identify them in the following format:

//                File, Line Number

//                Type Of Error

//                Description of Error

//                Fix for Error

// Make use of the following hints to locate each error:

// Error #1 located in sample.h/main.cpp related to the use of redefinitions
// Error #2 located in sample.h/main.cpp related to the use of objects
// Error #3 located in sample.cpp/main.cpp related to the use of types
// Error #4 located in main.cpp related to order of precedence
// Error #5 located in main.cpp related to threading
// Error #6 located in sample.cpp/main.cpp related to the use of shared states
// sample.h

#include <iostream>
#include <string>
#include <vector>
#include <future>

structGem
{
    std::string name{};
    unsigned weight{};
};

classTreasureBox
{
    std::vector<Gem> gems;
    unsigned weight{};

public:
    TreasureBox(const std::string *names, unsigned *weights, unsigned size);
    TreasureBox &operator+=(constGem &g);
    void update(const std::string &name);
    std::ostream &display() const;
};

void task(std::promise<unsigned> &p);


