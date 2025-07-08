/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:13:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 12:27:45 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact() {}

Contact::~Contact( void ) {}

std::string Contact::truncate( const std::string &str ) {
    size_t length = str.length();
    if (length > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int Contact::phone_validate(const std::string &str) {
    for (int j = 0; str[j]; j++) {
        if ((str[j] < '0' || str[j] > '9') && str[j] != ' ') {
            std::cout << "only numbers" << std::endl;
            return 1;
        }
    }
    return 0;
}

void Contact::setContact( void ) {
    std::string field[5];
    std::string input;

    const char  *prompts[5] = {
        "First Name: ",
        "Last Name: ",
        "NickName: ",
        "Phone Number: ",
        "Darkest Secret: "
    };

    for (int i = 0; i < 5; ) {
        std::cout << prompts[i];
        std::getline(std::cin, input);
        std::string trimmed = trim(input);
        if (trimmed == "") {
            std::cout << "empty" << std::endl;
            continue;
        }
        if ( i == 3 && this->phone_validate(trimmed)) continue;
        field[i] = input;
        i++;
    }

    this->first_name = this->truncate(field[0]);
    this->last_name = this->truncate(field[1]);
    this->nick_name = this->truncate(field[2]);
    this->phone_number = this->truncate(field[3]);
    this->darkest_secret = this->truncate(field[4]);

    return;
}

void Contact::displayContact( int index ) const {
    std::cout << "|"
        << std::right << std::setw(10) << index << "|"
        << std::right << std::setw(10) << this->first_name << "|"
        << std::right << std::setw(10) << this->last_name << "|"
        << std::right << std::setw(10) << this->nick_name << "|"
        << std::right << std::setw(10) << this->phone_number << "|"
        << std::right << std::setw(10) << this->darkest_secret << "|"
		<< std::endl;
    return;
}
