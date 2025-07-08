#ifndef PHONE_BOOK_CLASS_H
# define PHONE_BOOK_CLASS_H

#include "Contact.class.hpp"
#define CONTACT 8

std::string trim(const std::string &str);

class PhoneBook {

    public:

        int index;
        int writed;

        PhoneBook( void );
        ~PhoneBook( void );

        void run( void );

    private:

        Contact contacts[CONTACT];
        int empty;

        void    addContact( void );
        void    searchContact( void );

};

#endif
