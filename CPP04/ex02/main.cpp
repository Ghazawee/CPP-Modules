#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main(){

    // Animal a;
    Animal* a = new Cat();
    Animal* b = new Dog();
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "AAnimal a type: " << a->getType() << std::endl;
    std::cout << "AAnimal b type: " << b->getType() << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    a->makeSound();
    b->makeSound();
    std::cout << "------------------------------------------------" << std::endl;
    delete b;
    delete a;
    return (0);
}