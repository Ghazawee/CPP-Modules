#include "RPN.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr << "Usage: ./RPN 'expression' " << std::endl;
        std::cerr << "expression example: \"3 4 + 2 * 7 /\" " << std::endl;
        return 1;
    }
    try{
        RPN rpn;
        rpn.evaluate(av[1]);
        if (rpn.size() != 1){
            std::cerr << "Error: The user input has too many values." << std::endl;
            return 1;
        }
        std::cout << rpn.top() << std::endl;
        return 0;   
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}