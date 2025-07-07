#ifndef PHONE_BOOK_CLASS_H
# define PHONE_BOOK_CLASS_H

#include "../contact_class/Contact.class.hpp"

class PhoneBook {

    public:

        int index;
        int writed;

        PhoneBook( void );
        ~PhoneBook( void );

        void run( void );

    private:

        Contact contacts[8];
        int empty;
        
        std::string trim(const std::string &str);
        void    addContact( void );
        void    searchContact( void );

};

#endif