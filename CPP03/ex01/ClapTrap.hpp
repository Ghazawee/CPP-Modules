#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        int hitpoints;
        int energypoints;
        int attackdamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amout);
        void beRepaired(unsigned int amount);
        void setName(std::string name);
        void setHitpoints(int hitpoints);
        void setEnergypoints(int energypoints);
        void setAttackdamage(int attackdamage);
        std::string getName() const;
        int getHitpoints() const;
        int getEnergypoints() const;
        int getAttackdamage() const;
};

#endif