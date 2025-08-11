#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base* generate(){
    srand(time(0));
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else if (random == 2)
        return new C();
    return NULL;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "I identify as an A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "I identify as a B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "I identify as a C type" << std::endl;
    else
        std::cout << "I identify as an unknown type" << std::endl;
}

void identify(Base& p){
    try{
        dynamic_cast<A&>(p);
        std::cout << "I identify as an A type" << std::endl;
        return;
    }catch (std::exception&){}
    try{
        dynamic_cast<B&>(p);
        std::cout << "I identify as a B type" << std::endl;
        return;
    }catch (std::exception&){}
    try{
        dynamic_cast<C&>(p);
        std::cout << "I identify as a C type" << std::endl;
        return;
    }catch (std::exception&){}

    std::cout << "I identify as an unknown type" << std::endl;
    
}

int main() {
    Base* a = generate();
    //do i need to check if a is NULL?

    std::cout << "====================================================" << std::endl;
    std::cout << "Test with pointer:" << std::endl;
    identify(a);
    std::cout << "====================================================" << std::endl;
    std::cout << "Test with reference:" << std::endl;
    identify(*a);
    std::cout << "====================================================" << std::endl;
    std::cout << "End of tests" << std::endl;
    std::cout << "====================================================" << std::endl;

    delete a;

    return 0;
}