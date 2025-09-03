#include "PmergeMe.hpp"

int main(int ac, char **av){
    try{
        PmergeMe pmerge;
        pmerge.processInput(ac, av);
        pmerge.sortAndDisplay();
        return 0;
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}