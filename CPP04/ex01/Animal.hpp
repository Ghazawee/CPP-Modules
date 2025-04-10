#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal(); // destructor should also be virtual or else it wont compile, but why exactly idk actually
        const std::string getType()const;
        void setType(std::string type);
        virtual void makeSound() const; //this should be virtual
};

#endif