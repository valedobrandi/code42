#include "MyClass.hpp"

MyClass::MyClass(int value) : _value(value)
{
}

MyClass::MyClass(void)
{
}

MyClass::~MyClass(void)
{
}

MyClass::MyClass(const MyClass &other) : _value(other._value)
{
}

MyClass &MyClass::operator=(const MyClass &other)
{
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

int MyClass::getValue() const
{
	return (_value);
}

bool MyClass::operator<(const MyClass &other) const
{
	return (_value < other._value);
}

bool MyClass::operator>(const MyClass &other) const
{
	return (_value > other._value);
}
