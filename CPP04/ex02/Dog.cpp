#include "Dog.hpp"

Dog::Dog(): Animal(), brain(new Brain()){
    std::cout << "Default Dog Constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other){
    brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other){
    if(this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        this->type = other.type;
    }
    std::cout << "Dog copy assignment constructor called" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
    delete brain; // should i print the message first then call delete ??
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

Brain* Dog::getBrain()const{
    return this->brain;
}