#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    weapon = NULL;
    std::cout << "HumanB constructor has been called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

HumanB::~HumanB(){
    std::cout << "HumanB destructor has been called" << std::endl;
}

void HumanB::attack(){
    if(weapon)
        std::cout << name << " attack with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with." << std::endl;
}