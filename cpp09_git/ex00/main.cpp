#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    
    if (argc != 3) {
        std::cerr << "usage: ./btc data.csv input.txt" << std::endl;
        return 1;
    }
    BitcoinExchange broker(argv[1]);

    if (broker.run_exchange(argv[1]) == false) return 1;
    if (broker.run_exchange(argv[2]) == false) return 1;
    broker.process_exchange();

    return 0;
}