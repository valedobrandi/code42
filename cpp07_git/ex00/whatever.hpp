#ifndef WHATEVER_H
#define WHATEVER_H

template <typename Swap>
void swap(Swap& a, Swap& b)
{
    Swap t = a;
    a = b;
    b = t;
}
template <typename Min>
Min min(Min& a, Min& b)
{
    return (a < b ? a : b);
}

template <typename Max>
Max max(Max& a, Max& b)
{
    return (a > b ? a : b);
}
#endif


