#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){
    std::cout << "HumanA constructor has been called" << std::endl;
} 
//     this->name = name;
//     this->weapon = weapon; this doesnt work because weapon is a reference and references must be initialized in initializer list u cant reassign reference after it is created
// }

HumanA::~HumanA(){
    std::cout << "HumanA destructor has been called" << std::endl;
}

void HumanA::attack(){
    std::cout << name << " attack with " << weapon.getType() << std::endl;
}