#include "Cat.hpp"

Cat::Cat(): Animal(){
    std::cout << "Default Cat Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if(this != &other){
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}

const std::string Cat::getType() const{
    return this->type;
}

void Cat::setType(std::string type){
    this->type = type;
}

void Cat::makeSound()const{
    std::cout << "Cat has made a Cat sound" << std::endl;
}