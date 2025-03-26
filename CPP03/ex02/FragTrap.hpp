#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//It is stated in the subject that "FragTrap class that inherits from ClapTrap. It is very similar to
//ScavTrap" so that means i should override the attack function ?? right??

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys();
};

#endif