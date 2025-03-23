#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl{

    private:
        void debug();
        void info();
        void warning();
        void error();
        void (Harl::*functions[4])(); //::* pointer to a member function of Harl class
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif