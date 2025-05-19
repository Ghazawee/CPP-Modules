#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    std::cout << "Default WrongCat Constructor called" << std::endl;
    this->type = "WrongCat";
}


WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat copy assignment constructor called" << std::endl;
    if(this != &other){
        WrongAnimal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor called" << std::endl;
}

const std::string WrongCat::getType() const{
    return this->type;
}

void WrongCat::setType(std::string type){
    this->type = type;
}

void WrongCat::makeSound()const{
    std::cout << "WrongCat has made a WrongCat sound" << std::endl;
}