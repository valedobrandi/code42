#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( char p1, int p2, float p3, float const f ) 
    : a1( p1 ), a2( p2 ), a3( p3 ), pi( f ), qd( 42 ) {
    std::cout << "Constructor called" << std::endl;

    std::cout << "this->a1 = " << this->a1 << std::endl;
    std::cout << "this->a2 = " << this->a2 << std::endl;
    std::cout << "this->a3 = " << this->a3 << std::endl;

    this->foo = 42;
    std::cout << "this.foo " << this->foo << std::endl;

    this->_privateBar();
    
    return;
}

Sample::~Sample( void ) {
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::publicBar( void ) const {
    
    std::cout << "Member function bar called" << std::endl;
    std::cout << "this->pi " << this->pi << std::endl;
    std::cout << "this->qd " << this->qd << std::endl;

    return;
}

void    Sample::_privateBar( void ) const {
    
    std::cout << "Member private function bar called" << std::endl;


    return;
}