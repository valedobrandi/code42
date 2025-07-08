#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

std::string trim(const std::string &str);

class Contact {

    public:

        Contact( void );
        ~Contact( void );

        void setContact( void );
        void displayContact( int index ) const;

    private:

        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;

        std::string truncate(const std::string &str);
        int phone_validate(const std::string &str);
};

#endif