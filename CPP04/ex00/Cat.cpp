#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout << "Default Cat Constructor called" << std::endl;
}

// Cat::Cat(std::string type) : type(type){
//     std::cout << "Cat Constructor called" << std::endl;
// }

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    // this->type = other.type;
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if(this != &other){
        // this->type = other.type;
        Animal::operator=(other);
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