#include "good.hpp"

int main(int ac, char **av){

    
    if (ac != 4){
        std::cout << "Usage: ./sed_is_for_loosers filename s1 s2" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()){
        std::cout << "s1 cannot be empty" << std::endl;
        return 1;
    }
    std::string content = readfile(filename);
    if(content.empty()){
        std::cout << "Error: file is empty" << std::endl;
        return 1;
    }
    replace(content, s1, s2);
    if (writefile(content, filename))
        return(1);
    return (0);
}