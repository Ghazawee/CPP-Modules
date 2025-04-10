#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog: public Animal{
    
    public:
        Dog();
        //Dog(std::string type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog(); // destructor should also be virtual or else it wont compile, but why exactly idk actually // ithink only needed in base class
        const std::string getType()const;
        void setType(std::string type);
        virtual void makeSound()const; //this should be virtual // same here i only need it in the base class
};

#endif