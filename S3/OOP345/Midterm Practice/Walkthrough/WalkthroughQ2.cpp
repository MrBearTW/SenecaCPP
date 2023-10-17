#include <iostream>
using namespace std;

struct Foo
{
    void goo()
    {
        cout << "Hi!" << endl;
    }
    auto moo(unsigned &v) -> decltype(v / 0.0)
    {
        return v / 2.0;
    }
    auto boo(unsigned &&v) -> decltype(v * 0.0)
    {
        return v * 2.0;
    }
};

int main()
{
    unsigned a[3] = {1, 3, 5};

    cout << (a[0] + a[1]) << endl;
    cout << (a[2]) << endl;
    cout << sizeof(a) / sizeof(a[0]) << endl;

    Foo f;
    f.goo();
    cout << f.moo(a[1]) << endl;
    cout << f.boo(8) << endl;
}
