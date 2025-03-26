#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default"){
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

void FragTrap::attack(const std::string& target){
    if(getHitpoints() < 1){
        std::cout << "FragTrap " << getName() << " is already dead" << std::endl;
        return;
    }
    if(getEnergypoints() < 1){
        std::cout << "FragTrap " << getName() << " has no energy points to attack" << std::endl;
        return;
    }
    std::cout << "FragTrap " << getName() << " attack " << target << ", causing " << getAttackdamage() << " points of damage!" << std::endl;
    this->energypoints -= 1;

}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << getName() << " wanna high fives guys?! High Fives!!!" << std::endl;
}