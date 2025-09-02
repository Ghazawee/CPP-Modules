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
    if (ss.fail() || !ss.eof()){
        
        return false;
    }
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
    if (line != "date,exchange_rate"){
        throw std::runtime_error("Invalid header in " + filename);
    }
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
        if (isValidDate(date) && !ss.fail() && ss.eof()){
            data[date] = rate;
        }
    }
    infile.close();

}
float BitcoinExchange::getExchangeRate(const std::string& date)const{
    std::map<std::string, float>::const_iterator it = data.find(date);
    if (it != data.end()){
        return it->second;
    }
    it = data.lower_bound(date);
    if (it == data.begin()){
        throw std::runtime_error("No earlier date available");
    }
    --it;
    return it->second;

}

std::string BitcoinExchange::trim(const std::string& str, const std::string& to_remove)const{
    size_t first = str.find_first_not_of(to_remove);
    size_t last = str.find_last_not_of(to_remove);
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

void BitcoinExchange::processInputFile(const std::string& filename)const{
    std::ifstream infile(filename.c_str());
    if (!infile){
        throw std::runtime_error("Couldnt open " + filename);
    }
    std::string line;
    std::getline(infile, line);
    if (line != "date | value"){
        throw std::runtime_error("Invalid header in " + filename);
    }
    while(std::getline(infile, line)){
        size_t pipePos = line.find('|');
        if(pipePos == std::string::npos){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos); // if the format should always be "date | value" with spaces around '|' i need to do pipePos - 1 else just pipePos// or maybe use find then trim spaces
        date = trim(date, " \t\r");
        std::string valueStr = line.substr(pipePos + 1);
        valueStr = trim(valueStr, " \t\r");

        std::stringstream ss(valueStr);
        float value;
        ss >> value;
        if (!isValidDate(date)){
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (ss.fail() || !ss.eof()){
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        if (!isValidValue(value)){
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        try{
            float rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    infile.close();
}