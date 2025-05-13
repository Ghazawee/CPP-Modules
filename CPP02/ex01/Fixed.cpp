#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout <<"Copy assignment operator called" << std::endl;
    if(this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int val) : value(val << this->fractional_bits){
    std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(const float val) : value(roundf(val * (1 << this->fractional_bits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const{
    std::cout << "getRawBits member function called" << std::endl; // to match subject example
    return this->value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat() const{
    return static_cast<float>(this->value)/ (1 << fractional_bits);
}

int Fixed::toInt() const{
    return this->value >> fractional_bits;
}

//operator overload for << to print Fixed object, ex say we have Fixed a, with this we would be able to do std::cout << a; and print the a.value in float
std::ostream &operator<<(std::ostream &out, const Fixed &Fixed){
    out << Fixed.toFloat();
    return out; // return the stream to allow chaining // e.g std::cout << a << b;
}