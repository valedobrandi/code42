#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) : index( 0 ), writed( 0 ), empty( 1 ) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::run(void)
{
    std::string input;
    int running = 1;
    while (running)
    {
        std::cout << "commands: 'ADD' 'SEARCH' 'EXIT'" << std::endl;
        std::getline(std::cin, input);
        if (trim(input) == "ADD")
            this->addContact();
        if (trim(input) == "SEARCH")
            this->searchContact();
        if (trim(input) == "EXIT")
            running = 0;
    }
    std::cout << "Exit" << std::endl;
    return;
}

void PhoneBook::addContact(void)
{

	if (this->index >= CONTACT)
		this->index = 0;
    this->contacts[this->index].setContact();
	this->index++;
    if (this->writed != CONTACT)
        writed++;
    this->empty = 0;
    return;
}

void PhoneBook::searchContact(void)
{
    if (this->empty) {
        std::cout << "Empty" << std::endl;
        return;
    }
    for (int i = 0; i < this->writed; i++) {
		this->contacts[i].displayContact(i);
    }
    while (1) {
		std::string input;
        std::cout << "index: ";
        std::getline(std::cin, input);
        std::string trimmed = trim(input);
        if (trimmed.length() != 1 || trimmed[0] < '0') {
            std::cout << "Invalid index" << std::endl;
			continue;
        }
        int index = trimmed[0] - '0';
        if (index >= this->writed) {
            std::cout << "No contact" << std::endl;
        }
        else {
            this->contacts[index].displayContact(index);
            return;
        }
    }
    return;
}
