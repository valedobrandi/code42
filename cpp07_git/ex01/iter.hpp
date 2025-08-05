#ifndef ITER_H
#define ITER_H

#include <cstddef>


template <typename T>
void iter(T *array, size_t i, void (*func)( T& ))
{
    for (size_t t = 0; t < i; t++)
        func(array[t]);
}

template <typename T>
void iter(const T *array, size_t i, void (*func)( const T& ))
{
    for (size_t t = 0; t < i; t++)
        func(array[t]);
}

#endif


