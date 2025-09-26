#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <vector>

typedef std::vector<std::string>::iterator vectorStringIt;

class BitcoinExchange {
    public:
        std::string data_base;
        BitcoinExchange( );
        ~BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& other);
        BitcoinExchange& operator=( const BitcoinExchange& other);

        bool load(std::string filePath, std::vector<std::string> &container);
        std::string getExchangeRate(std::string date, std::vector<std::string> &dataBase);
        void processExchange(
			std::vector<std::string> &database,
			std::vector<std::string> &exchange);
		void runExchange(char *databaseFilePath, char *exchangeFileParh, std::vector<std::string> database, std::vector<std::string> exchange);
};

#endif