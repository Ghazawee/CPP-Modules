#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else{
        // for(int i = 1; i < ac; i++){
        //     for(int j = 0; av[i][j]; j++){
        //         std::cout << static_cast<char>(std::toupper(av[i][j]));
        //     }
        // }
        int i = 1;
        while(i < ac){
            int j = 0;
            while(av[i][j]){
                std::cout << static_cast<char>(std::toupper(av[i][j]));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}