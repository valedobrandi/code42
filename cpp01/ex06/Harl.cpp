#include "Harl.hpp"

Harl::Harl( void ) {}

void Harl::complain( std::string level ) {
    std::string const lv[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int switch_lv = -1;
    for (int i = 1; i < 4; i++) {
        if (level == lv[i]) {
            switch_lv = i;
            break;
        }
    }
    switch (switch_lv)
    {
        case 0:
            this->_debug();
            __attribute__ ((fallthrough));
        case 1:
            this->_info();
           __attribute__ ((fallthrough));
        case 2:
            this->_warning();
            __attribute__ ((fallthrough));
        case 3:
            this->_error();     
            break;   
        default:
             std::cout << "[ Probably complaining about insignificant problems ]"
                        << std::endl;
            break;
    }
}

void Harl::_debug( void ) {
    std::cout << "[ DEBUG ]"
                << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-" 
                << "ketchup burger. I really do!" << std::endl;
    return ;
}

void Harl::_info( void ) {
    std::cout << "[ INFO ]"
                << "I cannot believe adding extra bacon costs more money. You didn’t put"
                << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
                << std::endl;
    return ;
}

void Harl::_warning( void ) {
    std::cout << "[ WARNING ]" 
                << "I think I deserve to have some extra bacon for free. I’ve been coming for"
                << "years, whereas you started working here just last month." 
                << std::endl;
    return ;
}

void Harl::_error( void ) {
    std::cout << "[ ERROR ]" 
                << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
}