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
        void set_name(std::string new_name); // setter function to set the name of the zombie// alternative i can have two constructors one with name and one without for when allocating the array
        void announce();
};

Zombie* zombieHorde(int N, std::string name );
#endif