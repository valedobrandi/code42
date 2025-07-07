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
        if (this->trim(input) == "ADD")
            this->addContact();
        if (this->trim(input) == "SEARCH")
            this->searchContact();
        if (this->trim(input) == "EXIT")
            running = 0;
    }
    std::cout << "exit" << std::endl;
    return;
}

void PhoneBook::addContact(void)
{

    if (this->index > 8)
        this->index = 0;
    this->index++;
    this->contacts[this->index].setContact();
    if (this->writed < 9)
        writed++;
    this->empty = 0;
    return;
}

void PhoneBook::searchContact(void)
{
    if (this->empty) {
        std::cout << "empty" << std::endl;
        return;
    }
    std::string input;
    for (int i = 1; i < this->writed; i++) {
        this->contacts[i].displayContact(i);
    }
    while (1) {
        std::cout << "index: ";
        std::getline(std::cin, input);
        std::string trimmed = this->trim(input);
        if (trimmed.length() != 1 || trimmed[0] < '0' || trimmed[0] > '8') {
            std::cout << "Invalid index" << std::endl;
        }
        int index = trimmed[0] - '0';
        if (index > this->writed) {
            std::cout << "no contact" << std::endl;
        }
        else {
            this->contacts[index].displayContact(index);
            return;
        }
    }
    return;
}

std::string PhoneBook::trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}
