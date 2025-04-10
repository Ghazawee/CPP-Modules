#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain()){
    std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog& other){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if(this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(){
    delete brain; // should i print the message first then call delete ??
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

Brain* Dog::getBrain()const{
    return this->brain;
}