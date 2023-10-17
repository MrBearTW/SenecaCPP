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
};
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