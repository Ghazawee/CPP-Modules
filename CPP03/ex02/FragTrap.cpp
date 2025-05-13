#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap Default constructor called" << std::endl;
    hitpoints = 100;
    energypoints = 100;
    attackdamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap constructor with param called" << std::endl;
    hitpoints = 100;
    energypoints = 100;
    attackdamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if(this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

// void FragTrap::attack(const std::string& target){
//     if(getHitpoints() < 1){
//         std::cout << "FragTrap " << getName() << " is already dead" << std::endl;
//         return;
//     }
//     if(getEnergypoints() < 1){
//         std::cout << "FragTrap " << getName() << " has no energy points to attack" << std::endl;
//         return;
//     }
//     std::cout << "FragTrap " << getName() << " attack " << target << ", causing " << getAttackdamage() << " points of damage!" << std::endl;
//     this->energypoints -= 1;

// }

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << getName() << " wanna high fives guys?! High Fives!!!" << std::endl;
}

void FragTrap::setHitpoints(int hitpoints){
    if (hitpoints < 0){
        std::cout << "Hitpoints cannot be negative" << std::endl;
        return;
    }
    else if (hitpoints > 100){
        std::cout << "Hitpoints cannot be greater than 100" << std::endl;
        return;
    }
    this->hitpoints = hitpoints;
}

void FragTrap::setEnergypoints(int energypoints){
    if (energypoints < 0){
        std::cout << "Energy points cannot be negative" << std::endl;
        return;
    }
    else if (energypoints > 100){
        std::cout << "Energy points cannot be greater than 100" << std::endl;
        return;
    }
    this->energypoints = energypoints;
}

void FragTrap::setAttackdamage(int attackdamage){
    if (attackdamage < 0){
        std::cout << "Attack damage cannot be negative" << std::endl;
        return;
    }
    else if(attackdamage > 30){
        std::cout << "Attack damage cannot be above 30" << std::endl;
        return;
    }
    this->attackdamage = attackdamage;
}