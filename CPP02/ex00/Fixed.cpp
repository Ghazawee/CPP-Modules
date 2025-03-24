#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value){
    std::cout << "Copy constructor called" << std::endl;
    // *this = other; // by including this line, the copy constructor will call the copy assignment operator, it doesnt look like the subject example now :)
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout <<"Copy assignment operator called" << std::endl;
    if (this != &other) // to avoid assigning to itself
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}