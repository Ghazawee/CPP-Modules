#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal{
    
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        const std::string getType()const;
        void setType(std::string type);
        void makeSound()const; 
};

#endif