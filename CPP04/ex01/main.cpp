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
    return (0);
}