#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "A zombie is born."<<std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " is no longer with us."<<std::endl;
}

void Zombie::set_name(std::string new_name){
    name = new_name;
}
void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}