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
    std::cout << "getRawBits member function called" << std::endl;
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

//operator overload for << to print Fixed object, ex say we have Fixed a, with this we would be able to do std::cout <<  a; and print the a.value in float
std::ostream &operator<<(std::ostream &out, const Fixed &Fixed){
    out << Fixed.toFloat();
    return out;
}
//Comparison operators
bool Fixed::operator>(const Fixed &other) const{
    return this->value > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const{
    return this->value < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const{
    return this->value >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const{
    return this->value <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const{
    return this->value == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const{
    return this->value != other.getRawBits();
}
//Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const{
    Fixed result;

    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const{
    Fixed result;

    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const{
    Fixed result;

    result.value = (static_cast<long long>(this->value) * other.value) >> this->fractional_bits; 
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const{
    if(other.toFloat() == 0)
    {
        std::cerr << "Division by 0" << std::endl;
        return Fixed(0);
    }    
    Fixed result;
    result.value = (static_cast<long long>(this->value) << this->fractional_bits) / other.value; 
    return result;
}

//Pre and post increment and decrement operators
Fixed &Fixed::operator++(){
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed tmp = *this;
    this->value++;
    return tmp;
}

Fixed &Fixed::operator--(){
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    this->value--;
    return tmp;
}

//Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}