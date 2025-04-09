#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    
    public:
        WrongCat();
        //WrongCat(std::string type);
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        virtual ~WrongCat();
        const std::string getType()const;
        void setType(std::string type);
        virtual void makeSound()const; //this should be virtual
};

#endif