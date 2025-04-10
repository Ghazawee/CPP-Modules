#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main(){

    // const int n = 10;
    // Animal* animals[n];
    // std::cout << "Creating an array of animals" << std::endl;
    // for (int i = 0; i < n; i++){
    //     if (i % 2 == 0){
    //         animals[i] = new Dog();
    //     }
    //     else{
    //         animals[i] = new Cat();
    //     }
    // }
    // std::cout << "Deleting the array of animals" << std::endl;
    // for (int i = 0; i < n; i++){
    //     delete animals[i];
    // }
// need some testing to make sure deep copies and print ideas

Dog dog1;
dog1.getBrain()->setIdea(0, "I want to eat");
dog1.getBrain()->setIdea(1, "I want to play");
std::cout << "--------------------------------Dog1 ideas------------------------------"<< std::endl;
std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(0) << std::endl;
std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(1) << std::endl;
std::cout << "--------------------------------Dog2 copy constructor------------------------------"<< std::endl;
Dog dog2(dog1);
std::cout << "--------------------------------Dog2 ideas------------------------------"<< std::endl;
std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(0) << std::endl;
std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(1) << std::endl;
std::cout << "--------------------------------Dog2 own ideas------------------------------"<< std::endl;
dog2.getBrain()->setIdea(0, "I want to sleep");
dog2.getBrain()->setIdea(1, "I want to bark");
std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(0) << std::endl;
std::cout << "Dog1 idea " << dog1.getBrain()->getIdea(1) << std::endl;
std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(0) << std::endl;
std::cout << "Dog2 idea " << dog2.getBrain()->getIdea(1) << std::endl;
std::cout << "--------------------------------Destructor------------------------------"<< std::endl;
//if i want to use an animal pointer 
// Animal* dog1 = new Dog();
// dog1->getBrain()->setIdea(0, "I want to eat");
// dog1->getBrain()->setIdea(1, "I want to play");
// dog1->makeSound();
// std::cout << "--------------------------------Dog1 ideas------------------------------"<< std::endl;
// std::cout << "Dog1 idea " << dog1->getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog1 idea " << dog1->getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Dog2 copy constructor------------------------------"<< std::endl;
// Animal* dog2 = new Dog(*(dynamic_cast<Dog*>(dog1)));
// std::cout << "Second ";
// dog2->makeSound();
// std::cout << "--------------------------------Dog2 ideas------------------------------"<< std::endl;
// std::cout << "Dog2 idea " << dog2->getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog2 idea " << dog2->getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Dog2 own ideas------------------------------"<< std::endl;
// dog2->getBrain()->setIdea(0, "I want to sleep");
// dog2->getBrain()->setIdea(1, "I want to bark, oh wait i already barked, nvm that lets annoy the masses");
// std::cout << "Dog1 idea " << dog1->getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog1 idea " << dog1->getBrain()->getIdea(1) << std::endl;
// std::cout << "Dog2 idea " << dog2->getBrain()->getIdea(0) << std::endl;
// std::cout << "Dog2 idea " << dog2->getBrain()->getIdea(1) << std::endl;
// std::cout << "--------------------------------Destructor------------------------------"<< std::endl;
// delete dog2;
// delete dog1;

    return (0);
}