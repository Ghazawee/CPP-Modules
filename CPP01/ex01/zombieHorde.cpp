#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    Zombie* zombies = new Zombie[N];
    int i = 0;
    while(i < N){
        std::stringstream ss;
        ss << i + 1;
        zombies[i].set_name(name + "." + ss.str());
        // zombies[i] = Zombie(name + '.' + std::to_string(i)); //
        i++;
    }
    return zombies;
}