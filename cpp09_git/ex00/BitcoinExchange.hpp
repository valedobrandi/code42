#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <vector>

typedef std::vector<std::string>::iterator vectorStringIt;

class BitcoinExchange {
    private:
        std::vector<std::string> _entries_exchange;
        std::vector<std::string> _data_exchange;


    public:
        std::string data_base;
        BitcoinExchange( std::string );
        ~BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& other);
        BitcoinExchange& operator=( const BitcoinExchange& other);

        bool load_file(std::string filePath, std::vector<std::string> &dataBase);
        std::string get_exchange_rate(std::string date);
        void process_exchange(void);
        bool run_exchange(char *filePath);
};

#endif