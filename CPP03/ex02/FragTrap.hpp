#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"



class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        void highFivesGuys();
        void setHitpoints(int hitpoints);
        void setEnergypoints(int energypoints);
        void setAttackdamage(int attackdamage);
};

#endif