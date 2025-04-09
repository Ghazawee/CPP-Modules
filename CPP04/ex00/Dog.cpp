#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
    std::cout << "Default Dog Constructor called" << std::endl;
}

// Dog::Dog(std::string type) : type(type){
//     std::cout << "Dog Constructor called" << std::endl;
// }

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy constructor called" << std::endl;
    // this->type = other.type;
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if(this != &other){
        // this->type = other.type;
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}

const std::string Dog::getType() const{
    return this->type;
}

void Dog::setType(std::string type){
    this->type = type;
}

void Dog::makeSound()const{
    std::cout << "Dog has made a Dog sound" << std::endl;
}