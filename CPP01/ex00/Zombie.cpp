#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    //since there is conflict between the name of the member variable and the parameter name, we use this->name to refer to the member variable
    //alternative is to use member initialization list ex: Zombie::Zombie(std::string name) : name(name){}
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name << " is dead."<< std::endl;
}

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}