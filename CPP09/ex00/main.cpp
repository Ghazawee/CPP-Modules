#include "BitcoinExchange.hpp"


int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Usage: ./btc input.csv" << std::endl;
        return 1;
    }
    try{
        BitcoinExchange btc;
        btc.loadData("data.csv");
        btc.processInputFile(av[1]);
        return 0;
        
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

}