#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
        data = other.data;
    }
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date)const{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    std::stringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || !ss.eof())
        return false;
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2){
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }
    return true;
}
bool BitcoinExchange::isValidValue(const float& value)const{
    return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadData(const std::string& filename){
    std::ifstream infile(filename.c_str());
    if (!infile){
       throw std::runtime_error(filename + " should be in the directory");
    }
    std::string line;
    std::getline(infile, line);
    // std::stringstream ss;
    while(std::getline(infile, line)){
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos){
            continue;
        }
        std::string date = line.substr(0, commaPos);
        std::string valueStr = line.substr(commaPos + 1);
        std::stringstream ss(valueStr);
        float rate;
        ss >> rate;
        //check if valid date and value then store it
        if (isValidDate(date) || isValidValue(valueStr)){
            data[date] = rate;
        }
        // std::string rate = line.substr(commaPos + 1);

    }
    infile.close();

}
float BitcoinExchange::getExchangeRate(const std::string& data)const;
void BitcoinExchange::processInputFile(const std::string& filename)const;