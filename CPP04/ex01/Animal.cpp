#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Default Animal Constructor called" << std::endl;
}


Animal::Animal(const Animal &other){
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal copy assignment constructor called" << std::endl;
    if(this != &other){
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

const std::string Animal::getType() const{
    return this->type;
}

void Animal::setType(std::string type){
    this->type = type;
}

void Animal::makeSound() const{
    std::cout << "Animal has made an animal sound" << std::endl;
}
