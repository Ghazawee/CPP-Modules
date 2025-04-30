#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    std::cout << "Weapon constructor has been called" << std::endl;
} 

Weapon::~Weapon(){
    std::cout << "Weapon destructor has been called" << std::endl;
}

const std::string &Weapon::getType()const{
    return type;
}

void Weapon::setType(std::string type){
    this->type = type;
}