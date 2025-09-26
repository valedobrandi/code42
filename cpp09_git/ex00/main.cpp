#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {

    if (argc != 3) {
        std::cerr << "usage: ./btc data.csv input.txt" << std::endl;
        return 1;
    }
    std::vector<std::string> database;
	std::vector<std::string> exchange;
    BitcoinExchange broker;

	try
	{
		broker.runExchange(argv[1], argv[2], database, exchange);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}