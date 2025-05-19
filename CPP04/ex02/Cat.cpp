#include "Cat.hpp"

Cat::Cat(): Animal(), brain(new Brain()){
    std::cout << "Default Cat Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other){
    brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other){
    if(this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        this->type = other.type;
    }
    std::cout << "Cat copy assignment constructor called" << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
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