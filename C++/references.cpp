#include <iostream>
#include <string>



int main( void ) {
    
    int balls = 42;

    int* ballsPtr = &balls;
    int& ballsRef = balls;

    std::cout << balls << " " << *ballsPtr << " " << ballsRef << std::endl;
    *ballsPtr = 21;
    std::cout << balls << std::endl;
    ballsRef = 84;
    std::cout << balls << std::endl;
    return 0;
}