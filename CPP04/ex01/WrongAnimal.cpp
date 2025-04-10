#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "Default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal copy assignment constructor called" << std::endl;
    if(this != &other){
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

const std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::setType(std::string type){
    this->type = type;
}

void WrongAnimal::makeSound()const{
    std::cout << "WrongAnimal has made a WrongAnimal sound" << std::endl;
}
