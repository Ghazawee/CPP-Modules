#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()){
    std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat& other){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if(this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat(){
    delete brain;
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

Brain* Cat::getBrain()const{
    return this->brain;
}