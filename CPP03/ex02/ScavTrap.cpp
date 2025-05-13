#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    std::cout << "ScavTrap constructor with param called" << std::endl;
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if(this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if(getHitpoints() < 1){
        std::cout << "ScavTrap " << getName() << " is already dead" << std::endl;
        return;
    }
    if(getEnergypoints() < 1){
        std::cout << "ScavTrap " << getName() << " has no energy points to attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << getName() << " attack " << target << ", causing " << getAttackdamage() << " points of damage!" << std::endl;
    this->energypoints -= 1;

}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << getName() << " have entered in Gate keeper mode" << std::endl;
}

void ScavTrap::setHitpoints(int hitpoints){
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

void ScavTrap::setEnergypoints(int energypoints){
    if (energypoints < 0){
        std::cout << "Energy points cannot be negative" << std::endl;
        return;
    }
    else if (energypoints > 50){
        std::cout << "Energy points cannot be greater than 50" << std::endl;
        return;
    }
    this->energypoints = energypoints;
}

void ScavTrap::setAttackdamage(int attackdamage){
    if (attackdamage < 0){
        std::cout << "Attack damage cannot be negative" << std::endl;
        return;
    }
    else if(attackdamage > 20){
        std::cout << "Attack damage cannot be above 20" << std::endl;
        return;
    }
    this->attackdamage = attackdamage;
}