#include "BitcoinExchange.hpp"

int check_data_file(void){
    std::ifstream infile("data.csv");
    if (!infile){
       throw std::runtime_error("data.csv should be in the directory");
    }
    std::map<std::string, float> data;
    
}


int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Usage: ./btc input.csv" << std::endl;
        return 1;
    }
    try{
        // std::ifstream infile("data.csv");
        // if (!infile){
        //     std::cerr << "data.csv should be in the directory" << std::endl;
        //     return 1;
        // }
        
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }


}