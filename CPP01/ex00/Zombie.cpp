#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    this->name = name;
    std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " is dead."<< std::endl;
}

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}