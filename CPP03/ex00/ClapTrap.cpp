#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitpoints(10), energypoints(10), attackdamage(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitpoints(10), energypoints(10), attackdamage(0){
    std::cout << "ClapTrap constructor with param called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energypoints = other.energypoints;
    this->attackdamage = other.attackdamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if(this != &other){
        this->name = other.name;
        this->hitpoints = other.hitpoints;
        this->energypoints = other.energypoints;
        this->attackdamage = other.attackdamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if(getHitpoints() < 1){
        std::cout << "ClapTrap " << getName() << " is already dead" << std::endl;
        return;
    }
    if(getEnergypoints() < 1){
        std::cout << "ClapTrap " << getName() << " has no energy points to attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << getName() << " attack " << target << ", causing " << getAttackdamage() << " points of damage!" << std::endl;
    this->energypoints -= 1;

}

void ClapTrap::takeDamage(unsigned int amount){
    if(getHitpoints() < 1){
        std::cout << "ClapTrap " << getName() << " is already dead" << std::endl;
        return;
    }
    else if (amount >= static_cast<unsigned int>(getHitpoints())){
        std::cout << "ClapTrap " << getName() << " took this amount of damage " << amount << " and died" << std::endl;
        this->hitpoints = 0;
        return;
    }
    else{
        std::cout << "ClapTrap " << getName() << " take " << amount << " points of damage!" << std::endl;
        this->hitpoints -= static_cast<int>(amount);
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if(getHitpoints() >= 10){
        std::cout << "ClapTrap " << getName() << " is already at full health" << std::endl;
        return;
    }
    if (getHitpoints() < 1){
        std::cout << "ClapTrap " << getName() << " cannot be repaired, because ClapTrap " << getName() << " is already dead" << std::endl;
        return;
    }
    if (getEnergypoints() < 1){
        std::cout << "ClapTrap " << getName() << " has no energy points to repair" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << getName() << " is repaired for " << amount << " point of health!" << std::endl;
    this->hitpoints += amount;
    this->energypoints -= 1;
}

void ClapTrap::setName(std::string name){
    this->name = name;
}

void ClapTrap::setHitpoints(int hitpoints){
    if (hitpoints < 0){
        std::cout << "Hitpoints cannot be negative" << std::endl;
        return;
    }
    else if (hitpoints > 10){
        std::cout << "Hitpoints cannot be greater than 10" << std::endl;
        return;
    }
    this->hitpoints = hitpoints;
}

void ClapTrap::setEnergypoints(int energypoints){
    if (energypoints < 0){
        std::cout << "Energy points cannot be negative" << std::endl;
        return;
    }
    else if (energypoints > 10){
        std::cout << "Energy points cannot be greater than 10" << std::endl;
        return;
    }
    this->energypoints = energypoints;
}

void ClapTrap::setAttackdamage(int attackdamage){
    if (attackdamage < 0){
        std::cout << "Attack damage cannot be negative" << std::endl;
        return;
    }
    this->attackdamage = attackdamage;
}

std::string ClapTrap::getName() const{
    return this->name;
}

int ClapTrap::getHitpoints() const{
    return this->hitpoints;
}

int ClapTrap::getEnergypoints() const{
    return this->energypoints;
}

int ClapTrap::getAttackdamage() const{
    return this->attackdamage;
}
