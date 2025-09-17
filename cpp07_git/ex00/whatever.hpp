#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>
void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
template <typename T>
T min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template <typename T>
T max(const T& a, const T& b)
{
    return (a < b ? b : a);
}
#endif


