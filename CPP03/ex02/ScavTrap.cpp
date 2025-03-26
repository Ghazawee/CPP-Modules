#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default"){
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