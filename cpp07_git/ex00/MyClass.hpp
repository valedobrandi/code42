#ifndef MYCLASS_HPP
# define MYCLASS_HPP

class MyClass
{
  private:
	int _value;

  public:
	MyClass(int value);
	MyClass(void);
	~MyClass(void);
	MyClass(const MyClass &other);
	MyClass &operator=(const MyClass &other);

	int getValue() const;

	bool operator<(const MyClass &other) const;
	bool operator>(const MyClass &other) const;
};

#endif