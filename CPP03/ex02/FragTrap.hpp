#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//It is stated in the subject that "FragTrap class that inherits from ClapTrap. It is very similar to
//ScavTrap" so that means i should override the attack function ?? right?? it didnt mention that the attack
//should have a different message, only the constructor and destructor aaaaaaaaaaaah BS BS BS BS

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        // void attack(const std::string& target);
        void highFivesGuys();
        void setHitpoints(int hitpoints);
        void setEnergypoints(int energypoints);
        void setAttackdamage(int attackdamage);
};

#endif