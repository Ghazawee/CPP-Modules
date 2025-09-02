#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE


#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <sstream>


class BitcoinExchange{
    private:
        std::map<std::string, float> data;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadData(const std::string& filename);
        float getExchangeRate(const std::string& date)const;
        void processInputFile(const std::string& filename)const;
        bool isValidDate(const std::string& date)const;
        bool isValidValue(const float& value)const;
        std::string trim(const std::string& str, const std::string& to_remove)const;

};


#endif