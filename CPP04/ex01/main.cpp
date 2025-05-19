#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main(){

    const int n = 10;
    Animal* animals[n];
    std::cout << "Creating an array of animals" << std::endl;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            animals[i] = new Dog();
        }
        else{
            animals[i] = new Cat();
        }
    }
    std::cout << "Deleting the array of animals" << std::endl;
    for (int i = 0; i < n; i++){
        delete animals[i];
    }
// need some testing to make sure deep copies and print ideas

// Dog dog1;
// dog1.getBrain()->setIdea(0, "I want to eat");
// dog1.getBrain()->setIdea(1, "I want to play");
// std::cout << "--------------------------------Dog1 ideas------------------------------"<< std::endl;
// std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Dog2 copy constructor------------------------------"<< std::endl;
// Dog dog2(dog1);
// std::cout << "--------------------------------Dog2 ideas------------------------------"<< std::endl;
// std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Dog2 own ideas------------------------------"<< std::endl;
// dog2.getBrain()->setIdea(0, "I want to sleep");
// dog2.getBrain()->setIdea(1, "I want to bark");
// std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(1) << std::endl;
// std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Destructor------------------------------"<< std::endl;

// Dog base;
// base.getBrain()->setIdea(0, "I want to eat");
// std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
// {
//     Dog clone = base;
//     // clone = base;
//     std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
//     clone.getBrain()->setIdea(0, "I want to play");
//     std::cout << "base idea: " << base.getBrain()->getIdea(0) << std::endl;
//     std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
//     std::cout << "clone's Brain address: " << clone.getBrain() << std::endl;
//     std::cout << "base's Brain address: " << base.getBrain() << std::endl;
// }
// std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
    return (0);
}