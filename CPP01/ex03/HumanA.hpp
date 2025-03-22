#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{

    private:
        std::string name;
        Weapon &weapon;
    
    public:
        HumanA(std::string name, Weapon &weapon);
        // ~HumanA();
        void attack();
};


//&weapon reference to the weapon, since A always start with a weapon, it can be Weapon weapon but then you need to copy and use new
#endif