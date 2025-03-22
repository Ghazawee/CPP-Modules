#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    weapon = NULL; // without it conditional jump or move depends on uninitialised value(s) will occur
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

void HumanB::attack(){
    if(weapon)
        std::cout << name << " attack with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with." << std::endl; // without if else, segfault if i call attack without initializing the weapon with null
}