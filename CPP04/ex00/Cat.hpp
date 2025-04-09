#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal{
    
    public:
        Cat();
        //Cat(std::string type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();
        const std::string getType()const;
        void setType(std::string type);
        virtual void makeSound()const; //this should be virtual
};

#endif