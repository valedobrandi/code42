#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <climits>

std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        ++start;
    }
    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return str.substr(start, end - start);
}

bool BitcoinExchange::load_file(std::string filePath, std::vector<std::string>& dataBase)
{
    std::ifstream file(filePath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    std::string line;
    bool header = true;
    while (std::getline(file, line)) {
        if (header) { header = false; continue; }
        dataBase.push_back(line);
    }
    file.close();
    return true;
}

void ERROR_BAD_IMPUT(std::string error) {
    std::cerr << "Error: bad input => " << error << std::endl;
}

void ERROR_NUMBER_TO_LARGE( void ) {
    std::cerr << "Error: too large a number." << std::endl;
}

void ERROR_NOT_POSITIVE_NUMBER( void ) {
    std::cerr << "Error: not a positive number." << std::endl;
}

bool is_leap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool is_valid_date(int year, int month, int day) {
    if (year < 0) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if (month == 2) return is_leap(year) ? day <= 29 : day <= 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
    return true;
}

std::vector<std::string> exchange_date(std::string str_date) {
    std::istringstream oss(str_date);
    std::vector<std::string> date;
    std::string token;
    while (std::getline(oss, token, '-')) {
        date.push_back(token);
    }
    return date;
} 

bool is_date_format_valid(std::string date) {
    std::istringstream oss(date);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(oss, token, '-')) {
        for (size_t i = 0; i < token.size(); ++i) {
            if (!isalnum(token[i])) return false;
        }
        tokens.push_back(token);
    }
    if (tokens.size() != 3 || 
        !is_valid_date(atoi(tokens[0].c_str()), atoi(tokens[1].c_str()), atoi(tokens[2].c_str()))) {
        return false;
    }
    return true;
    
}

bool is_valid_number(const std::string& token) {
    std::istringstream iss(token);
    double value;
    char leftover;

    if (!(iss >> value) || (iss >> leftover)) {
        ERROR_BAD_IMPUT(iss.str());
        return false;
    }
    if (value > 1000.0) {
        ERROR_NUMBER_TO_LARGE();
        return false;
    }
    if (value < 0.0) {
        ERROR_NOT_POSITIVE_NUMBER();
        return false;
    }

    return true;
}


bool is_number_positive(std::string token) {
    long value = atol(token.c_str());
    return value >= 0;
}

bool validate_tokens(std::vector<std::string> &tokens, std::string token) {
    if (tokens.size() != 2 || 
        !is_date_format_valid(tokens[0])) {
        ERROR_BAD_IMPUT(token);
        return false;
    }
    if (!is_valid_number(tokens[1])) return false;
    
    return true;
}

std::string BitcoinExchange::get_exchange_rate(std::string date) {
    std::string find_date;
    for (vectorStringIt it = _data_exchange.begin(); it != _data_exchange.end(); ++it) {
        std::string line = *it;
        size_t pos = line.find(',');
        if (pos == std::string::npos) continue;
        std::string exchange_date = line.substr(0, pos);
        if (exchange_date == date) {
            return line;
        }
        if (exchange_date < date) {
            find_date = line;
        } else {
            break;
        }
    }
    return find_date;
}

void BitcoinExchange::process_exchange(void)
{   
    vectorStringIt it;
    for (it = _entries_exchange.begin(); it != _entries_exchange.end(); ++it) {
        std::istringstream oss(*it);
        std::string token;
        std::vector<std::string> tokens;
        tokens.clear();
        while (std::getline(oss, token, '|')) {
            tokens.push_back(trim(token));
        }
        if (validate_tokens(tokens, *it) == false) continue;
        std::string match_date = get_exchange_rate(tokens[0]);
        size_t pos = match_date.find(',');
        std::string exchange_rate = match_date.substr(pos + 1);
        double exchange = atof(exchange_rate.c_str()) * atof(tokens[1].c_str());
        std::cout << tokens[0] << " => " << tokens[1] << " = " << exchange << std::endl;
    }
}

bool BitcoinExchange::run_exchange(char *filePath) {
    std::string path(filePath);
    if (!load_file(path, _entries_exchange)) {
            return false;
        }
    return true;
}

BitcoinExchange::BitcoinExchange(std::string dataBase): data_base(data_base)
{
    
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): data_base(other.data_base)
{
    this->_data_exchange.clear();
    for (size_t it = 0; it < other._data_exchange.size(); ++it)
        _data_exchange[it] = other._data_exchange[it];
    this->_entries_exchange.clear();
    for (size_t it = 0; it < other._entries_exchange.size(); ++it)
        _entries_exchange[it] = other._entries_exchange[it];
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other) {
        data_base = other.data_base;
        this->_data_exchange.clear();
    for (size_t it = 0; it < other._data_exchange.size(); ++it)
        _data_exchange[it] = other._data_exchange[it];
    this->_entries_exchange.clear();
    for (size_t it = 0; it < other._entries_exchange.size(); ++it)
        _entries_exchange[it] = other._entries_exchange[it];
    }
   return *this;
}
