#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <sstream>

class Zombie{

    private:
        std::string name;
    
    public:
        Zombie();
        ~Zombie();
        void set_name(std::string new_name);
        void announce();
};

Zombie* zombieHorde(int N, std::string name );
#endif