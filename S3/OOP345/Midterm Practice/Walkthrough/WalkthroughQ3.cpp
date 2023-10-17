#include <iostream>
using namespace std;

struct thing
{
    std::string name;
    std::string operator*(unsigned v)
    {
        return name += to_string(v);
    }
    operator string() const { return name; }
};

template <typename T, typename S>
auto foo(T &v1, S v2) -> decltype(v1 * v2)
{
    return v1 * v2;
}

template <>
auto foo(thing &v1, unsigned v2) -> decltype(v1 * v2)
{
    for (auto i = 0u; i < v2; ++i)
        v1.name += "E";
    return v1 * v2;
}

int main()
{
    unsigned x{1}, y{5};
    double a{1.1}, b{2.2};
    thing c{"NA"}, d{"CL"};
    cout << foo(x, y) << endl;
    cout << foo(x, a) << endl;
    cout << foo(a, b) << endl;
    cout << foo(c, x) << endl;
    cout << foo(d, y) << endl;
}