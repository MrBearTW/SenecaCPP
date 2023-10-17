#include <iostream>
using namespace std;

enum Vals
{
    AV = 1,
    BV = 2,
    CV = 3
};

struct Foo
{
    Vals val{};

    Foo &goo()
    {
        if (val == AV)
            val = BV;
        if (val == BV)
            val = CV;
        if (val == CV)
            val = AV;
        return *this;
    }
    Foo &boo()
    {
        if (val == AV)
            val = CV;
        if (val == BV)
            val = AV;
        if (val == CV)
            val = BV;
        return *this;
    }
};

ostream &operator<<(ostream &os, const Foo &f)
{
    os << f.val << endl;
    return os;
}

int main()
{

    Foo f{AV};
    cout << f.goo();
    cout << f.boo();
    cout << (f.goo()).boo();
    cout << (f.boo()).goo();
}