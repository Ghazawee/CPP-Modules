#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );
    Fixed c( Fixed(5.05f) / Fixed(0) );
    Fixed g(3.5f);
    Fixed s(2.5f);

    std::cout << "Testing arithmetic operators:" << std::endl;
    std::cout << g << " + " << s << " = " << (g + s) << std::endl;
    std::cout << g << " - " << s << " = " << (g - s) << std::endl;
    std::cout << g << " * " << s << " = " << (g * s) << std::endl;
    std::cout << g << " / " << s << " = " << (g / s) << std::endl;;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << c << std::endl;
    return 0;
}