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
        // std::cout << "Error: file is empty OR MAYBE it doesnt EXISTS!!!!!!!!!! NOW GO BACK AND ENTER A MOTHERF*****G FILE THAT EXISTS AS A F*****G ARGUMENT!!!!!!!!! Thank you" << std::endl;
        std::cout << "Error: file is empty" << std::endl;
        return 1;
    }
    replace(content, s1, s2);
    writefile(content, filename);
    return (0);
}