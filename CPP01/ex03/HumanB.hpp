#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{

    private:
        std::string name;
        // Weapon &weapon;
        Weapon *weapon; // pointer cant be reference because it is not initialized in initializer list because B can  start without a weapon and reference cant be null so it must be pointer
    
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        // ~HumanB();
        void attack();
};

#endif