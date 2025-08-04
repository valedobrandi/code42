#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer & /* other */)
{
}

Serializer &Serializer::operator=(const Serializer & /* other */)
{
    return *this;
}

Serializer::~Serializer(void)
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t t = reinterpret_cast<uintptr_t>(ptr);
    return t;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *t = reinterpret_cast<Data *>(raw);
    return t;
}
