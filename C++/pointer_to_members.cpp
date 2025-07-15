
#include <iostream>

class Sample {

public:
    int foo;

    Sample( void );
    ~Sample( void );

    void bar( void ) const;

};

Sample::Sample( void ): foo( 0 ) {};
Sample::~Sample( void ) {};

void Sample::bar( void ) const {std::cout << "bar called" << std::endl;};

int main( void ) {

    Sample instance;
    Sample* instancep = &instance;

    // para um atributo;
    int Sample::*p = NULL;
    // para uma função;
    void (Sample::*f)(void) const;


    p = &Sample::foo;
    std::cout << "foo: " << instance.foo << std::endl;
    //any foo from a declared class (Sample instance);
    instance.*p = 21; 
    std::cout << "foo: " << instance.foo << std::endl;
    //any foo declare as pointer from a class (Sample* instancep = &instance);
    instancep->*p = 42; 
    std::cout << "foo: " << instance.foo << std::endl;

    f = &Sample::bar;

    (instance.*f)();
    (instancep->*f)();

    return 0;
}